#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <libTableauNoir.h>
#include "structure.h"
#include "mob.h"
#include "init.h"
#include "detection.h"
#include "entite.h"


/*-----------------------------------------------------------------*/
/*Contrôle des zombies*/
void zombie(mob_t * zombie, game_t * game){
  int detection = 0;
  if(zombie->AS <=0){
    for(int i = 0; i < game->map.nb_mob; i++){
      if(!game->map.mob[i].type){
	if((sqrt(pow(zombie->pos.x - game->map.mob[i].pos.x,2)+pow(zombie->pos.y - game->map.mob[i].pos.y,2)) < zombie->range_att)){
	  if(detect_entite(zombie->range_att,zombie->direct, zombie->pos,game->map.mob[i].pos , zombie->nb_hit, *game)){

	    zombie->nb_hit = 1;
	    zombie->vect.x = game->map.mob[i].pos.x - zombie->pos.x;
	    zombie->vect.y = game->map.mob[i].pos.y - zombie->pos.y;
	    detection = 1;
	  }
	}
	else{
	  if(zombie->nb_hit>0){
	    zombie->AS =0;
	    zombie->vect.x = pow(-1,1+rand())*zombie->pos.v;
	    zombie->vect.y = 0;
	    zombie->nb_hit = 0;
	  }
	}
      }
    }
    if(!detection){
      if((sqrt(pow(zombie->pos.x,2)+pow(zombie->pos.y,2)) < zombie->range_att)){
	if(detect_entite(zombie->range_att,zombie->direct, zombie->pos, game->perso.pos, zombie->nb_hit, *game)){
	  zombie->nb_hit =1;
	  zombie->vect.x = -zombie->pos.x;
	  zombie->vect.y = -zombie->pos.y;
	  detection = 1;
	}
      }
      else{
	  if(zombie->nb_hit>0){
	    zombie->AS =0;
	    zombie->vect.x = pow(-1,1+rand())*zombie->pos.v;
	    zombie->vect.y = 0;
	    zombie->nb_hit = 0;
	  }
	}
    }
    zombie->AS = .45;
  }
  else{
    zombie->AS = zombie->AS - game->syst.dt;
  }   
  if(zombie->nb_hit != 0){
    path_finder(zombie, game);
    for(int i =0; i < game->map.nb_mob; i++){
      if(!game->map.mob[i].type){
	if(sqrt(pow(zombie->pos.x - game->map.mob[i].pos.x,2)+pow(zombie->pos.y - game->map.mob[i].pos.y,2)) <= 25){
	  creer_projectile(&game->map, zombie->pos, zombie->direct, zombie->pos.v,zombie->dmg,35, game->visuel.visuel_pro[zombie->direct -1], zombie->type, 35,1);
	  zombie->vect.x = pow(-1,1+rand())*zombie->pos.v;
	  zombie->vect.y = 0;
	  zombie->nb_hit =0;
	}
      }
    }
    if(sqrt(pow(zombie->pos.x,2)+pow(zombie->pos.y,2)) <= 25){
      creer_projectile(&game->map, zombie->pos, zombie->direct, zombie->pos.v,zombie->dmg,35, game->visuel.visuel_pro[zombie->direct -1], zombie->type, 35,1);
      zombie->vect.x = pow(-1,1+rand())*zombie->pos.v;
      zombie->vect.y = 0;
      zombie->nb_hit =0;
    }
    int direct = zombie->direct;
    int frame = game->syst.frame;
    zombie->visuel_actif = game->visuel_mob.zombie[direct*3 - frame-2];
  }
  else{
    mvt_mob(zombie, *game);
    mob_visuel(zombie, game->visuel_mob.zombie,0,*game);
  }  
}


/*-----------------------------------------------------------------*/
/*déplacement mob*/
void mvt_mob(mob_t * mob, game_t game){;
  if(mob->tps_move <= 0){
    mob->tps_move  = 3*(double)rand()/RAND_MAX;
    mob->direct = 1 + rand()%4;
    if(mob->direct == 1){
      mob->vect.x = 0;
      mob->vect.y = mob->pos.v*7/8;
    }
    if(mob->direct == 2){
      mob->vect.x = 0;
      mob->vect.y = -mob->pos.v*7/8;
    }
    if(mob->direct == 3){
      mob->vect.x = -mob->pos.v;
      mob->vect.y = 0;
    }
    if(mob->direct == 4){
      mob->vect.x = mob->pos.v;
      mob->vect.y = 0;
    }
  }
  else{
    mob->tps_move = mob->tps_move - game.syst.dt;
    mob->pos_f.x = mob->pos.x + mob->vect.x*game.syst.dt;
    mob->pos_f.y = mob->pos.y + mob->vect.y*game.syst.dt;  
    /*collision*/
    int collision = collision_mob(&mob->pos_f, &mob->pos,game);
    if(collision){
      mob->tps_move = 0;
      mvt_mob(mob, game);
      return;
    }
    mob->pos.x = mob->pos_f.x;
    mob->pos.y = mob->pos_f.y;
   }
} 

/*-----------------------------------------------------------------*/
/*mob visuel*/
void mob_visuel(mob_t *mob, Image visuel_base[], int i, game_t game){
  if((atan2(mob->vect.y,mob->vect.x) >( M_PI/4)) && (atan2(mob->vect.y,mob->vect.x) <( 3*M_PI/4))){
    mob->visuel_actif = visuel_base[i+1+game.syst.frame];    
    mob->direct = 1;
    return;
  }
  if((atan2(mob->vect.y,mob->vect.x) <(-M_PI/4 )) && (atan2(mob->vect.y,mob->vect.x) > (-3*M_PI/4))){
    mob->visuel_actif = visuel_base[i+4+game.syst.frame];
    mob->direct = 2;
    return;
  }
  if((atan2(mob->vect.y,mob->vect.x) >(3*M_PI/4)) || (atan2(mob->vect.y,mob->vect.x) < (-3*M_PI/4))){
    mob->visuel_actif = visuel_base[i+7+game.syst.frame];   
    mob->direct = 3;
    return;
  }
  if((atan2(mob->vect.y,mob->vect.x) < ( M_PI/4)) && (atan2(mob->vect.y,mob->vect.x )> (-M_PI/4))){
    mob->visuel_actif = visuel_base[i+10+game.syst.frame];   
    mob->direct = 4;
    return;
  }
}



/*Contrôle des ghosts*/
void ghost(mob_t *ghost,game_t *game){
  for(int i =0; i< game->map.nb_mob; i++){
    if(!game->map.mob[i].type){
      if(sqrt(pow(ghost->pos.x - game->map.mob[i].pos.x,2) + pow(ghost->pos.y - game->map.mob[i].pos.y,2)) < 30){
	game->map.mob[i].hp --;
      }
    }
  }
  if(sqrt(pow(ghost->pos.x,2) + pow(ghost->pos.y,2)) < 30){
    if(game->perso.shield <=0 ){      
    game->perso.hp --;
    game->perso.shield = 1.2;
    }
  }
    /*visuel*/
  int i = 0;
  if(ghost->nb_hit !=0){
    i = 12;
  }
  mob_visuel(ghost,game->visuel_mob.ghost,i,*game);

  /*déplacement*/
  ghost->pos_f.x = ghost->pos.x + ghost->vect.x*game->syst.dt;
  ghost->pos_f.y = ghost->pos.y + ghost->vect.y*game->syst.dt;
   if(sqrt(pow(ghost->pos.x,2) + pow(ghost->pos.y,2)) < ghost->range_att){
    if(ghost->AS <= 0){
      if(ghost->nb_hit == 0){
	ghost->vect.x = -ghost->pos.x*3/2;
	ghost->vect.y = -ghost->pos.y*3/2;
	ghost->nb_hit = 3;
	ghost->AS = 4;
      }      
    }
    else{
      if(ghost->nb_hit == 0){
	ghost->AS = ghost->AS - game->syst.dt;
      }
    }
   }

  if(ghost->nb_hit !=0){
    double x,y,x2,y2;
    x = (ghost->pos_f.x - game->map.pos.x + tn_largeur(game->map.map_visuel)/2);    
    y = -(ghost->pos_f.y - game->map.pos.y - tn_hauteur(game->map.map_visuel)/2);
    x2 = (ghost->pos.x - game->map.pos.x + tn_largeur(game->map.map_visuel)/2);    
    y2 = -(ghost->pos.y - game->map.pos.y - tn_hauteur(game->map.map_visuel)/2);
    int collision = collision_mob(&ghost->pos_f,&ghost->pos, *game);
    double aux_x = ghost->vect.x + ghost->vect.x/5;
    double aux_y = ghost->vect.y + ghost->vect.y/5;
    
    /*collision*/
     if(collision == 1){
      int l = 0,c =0;	
      while(x >= 25){
	x= x-25;
	c++;
      }
      while(y >= 25){
	y = y-25;
	l++;
      }
      int c_bis=0,l_bis=0;
      while(x2 >= 25){
	x2= x2-25;
	c_bis++;
      }
      while(y2 >= 25){
	y2 = y2-25;
	l_bis++;
      }
      if((c_bis < c) || (c_bis > c)){
	ghost->vect.x = -aux_x;
      }
      if((l_bis < l) ||(l_bis > l)){
	  ghost->vect.y = -aux_y;  
	}
	ghost->nb_hit --;
	return; 
    }
    if(collision == 2){
      ghost->vect.x = aux_y ;
      ghost->vect.y = aux_x ;
      ghost->nb_hit --;
      return;
    }
    if(collision == 3){
      ghost->vect.x =  - aux_y;
      ghost->vect.y = - aux_x ;
      ghost->nb_hit --; 
      return;
    }
    if(collision == 4){
      ghost->vect.x =  - aux_y;
      ghost->vect.y = - aux_x;
      ghost->nb_hit --;
      return;
    }
    if(collision == 5){
      ghost->vect.x = aux_y;
      ghost->vect.y = aux_x;
      ghost->nb_hit --;
      return;
    }
    ghost->pos.x = ghost->pos_f.x;
    ghost->pos.y = ghost->pos_f.y;
  }
  else{
    mvt_mob(ghost,*game);
  }
}

/*-----------------------------------------------------------------*/
/*collision mob*/
int collision_mob(coord_t *pos_f, coord_t *pos, game_t game){
  int l = 0,c =0;
  double x,y;
  x = (pos_f->x - game.map.pos.x + tn_largeur(game.map.map_visuel)/2);    
  y = -(pos_f->y - game.map.pos.y - tn_hauteur(game.map.map_visuel)/2);
  while(x >= 25){
    x= x-25;
    c++;
  }
  while(y >= 25){
    y = y-25;
    l++;
  }
  int res = 0;
  if(game.map.interaction[l][c] == 1){
    res = 1;
  }
  else{
    if(game.map.interaction[l][c] == 2){
      if((-x+26) > y){
	res = 2;
      }
    }
    else{
      if(game.map.interaction[l][c] == 3){
	if(x>y){
	  res = 3;
	}
      }
      else{
	if(game.map.interaction[l][c] == 4){
	  if(x<y){
	    res = 4;
	  }
	}
	else{
	  if(game.map.interaction[l][c] == 5){
	    if((-x+26) < y){
	      res = 5;
	    }
	  }
	}
      }
    }
  }
  if(res !=0){
    pos_f->x = pos->x;
    pos_f->y = pos->y;
  }

  return res;  
}

/*-----------------------------------------------------------------*/
/*vérifier quels monstres sont morts*/
void maj_mort_mob(game_t *game){
  for(int i =0; i < game->map.nb_mob; i++){
    if(game->map.mob[i].hp <= 0){
      if(game->map.mob[i].type != 0){
	creer_item(&game->map, game->map.mob[i].pos,1, game->visuel.visuel_item[1], game->map.mob[i].type +rand()%2);
	game->map.mob[i] = game->map.mob[game->map.nb_mob-1];      
	game->map.nb_mob --;
      }
      else {
	game->map.mob[i] = game->map.mob[game->map.nb_mob-1];      
	game->map.nb_mob --;
      }
    }
  }  
}

void creer_mob(map_t * map, coord_t pos, double range_att, double speed, Image visuel, int hp, int dmg, int type){
  map->mob[map->nb_mob] = (mob_t){
    .pos = pos,
    .range_att = range_att,
    .visuel_actif = visuel,
    .hp = hp,
    .dmg =dmg,
    .type = type,
    .visible = 1
  };
  map->mob[map->nb_mob].pos.v = speed;
  map->nb_mob ++;
}


void maj_mob(game_t * game){
 for(int i = 0;i < game->map.nb_mob;i++){
   if(game->map.mob[i].visible){
     if(game->map.mob[i].type == 1){
       zombie(&game->map.mob[i],game);
     }
     else {
       if(game->map.mob[i].type == 2){
	 ghost(&game->map.mob[i],game);
       }
       else{
	 if(game->map.mob[i].type == 0){
	   mob(&game->map.mob[i], game);
	 }
       }
     }
   }
 }
}

void mob(mob_t *mob,game_t *game){
  int detection = 0;
  if(mob->AS <=0){
    coord_t pos;
    double distance = 160;
    for(int i = 0; i < game->map.nb_mob; i++){
      if(game->map.mob[i].type){
	if((sqrt(pow(mob->pos.x - game->map.mob[i].pos.x,2)+pow(mob->pos.y - game->map.mob[i].pos.y,2)) < mob->range_att)){
	  if(distance > sqrt(pow(mob->pos.x - game->map.mob[i].pos.x,2)+pow(mob->pos.y - game->map.mob[i].pos.y,2))){
	    distance = sqrt(pow(mob->pos.x - game->map.mob[i].pos.x,2)+pow(mob->pos.y - game->map.mob[i].pos.y,2));
	    pos = game->map.mob[i].pos;
	  }
	  mob->nb_hit = 1;
	  mob->vect.x = pos.x - mob->pos.x;
	  mob->vect.y = pos.y - mob->pos.y;
	  detection =1;
	}
	else{
	  if(mob->nb_hit > 0 && !detection){
	    mob->AS =0;
	    mob->vect.x = pow(-1,1+rand())*mob->pos.v;
	    mob->vect.y = 0;
	    mob->nb_hit = 0;
	  }
	}
      }
    }
    mob->AS = .45;
  }
  else{
    mob->AS = mob->AS - game->syst.dt;
  }   
  if(mob->nb_hit != 0){
    path_finder(mob, game);
    for(int i =0; i < game->map.nb_mob; i++){
      if(game->map.mob[i].type){
	if(sqrt(pow(mob->pos.x - game->map.mob[i].pos.x,2)+pow(mob->pos.y - game->map.mob[i].pos.y,2)) <= 35){
	  creer_projectile(&game->map, mob->pos, mob->direct, mob->pos.v,mob->dmg,30, game->visuel.visuel_pro[4], mob->type, 40,1);
	  mob->vect.x = pow(-1,1+rand())*mob->pos.v;
	  mob->vect.y = 0;
	  mob->nb_hit =0;
	  mob->AS = 2;
	}
      }
    }   
    int direct = mob->direct;
    int frame = game->syst.frame;
    mob->visuel_actif = game->visuel.visuel_mob[direct*3 - frame-2];
  }
  else{
    mvt_mob(mob, *game);
    mob_visuel(mob, game->visuel.visuel_mob,0,*game);
  } 
 }

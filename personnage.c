#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <libTableauNoir.h>
#include "structure.h"
#include "mob.h"
#include "detection.h"
#include "entite.h"
#include "personnage.h"

void image_base(game_t *game){
  if(game->perso.tps_spell > 0){
    if(game->perso.direct == 1){
      game->perso.visuel = game->visuel.visuel_mob[1];
    }
    if(game->perso.direct == 2){
      game->perso.visuel = game->visuel.visuel_mob[4];
    }
    if(game->perso.direct == 3){
      game->perso.visuel = game->visuel.visuel_mob[7];
    }
    if(game->perso.direct == 4){
      game->perso.visuel = game->visuel.visuel_mob[10];
    }
  }
  else{
    if(game->perso.direct == 1){
      game->perso.visuel = game->visuel.visuel_mvt[1];
    }
    if(game->perso.direct == 2){
      game->perso.visuel = game->visuel.visuel_mvt[4];
    }
    if(game->perso.direct == 3){
      game->perso.visuel = game->visuel.visuel_mvt[7];
    }
    if(game->perso.direct == 4){
      game->perso.visuel = game->visuel.visuel_mvt[10];
    }
  }

}

/*-----------------------------------------------------------------*/
/*attaque*/
void attaque(game_t *game){
  if(game->perso.AS >= game->perso.AS_ref){
    if(game->perso.basic){
      creer_projectile(&game->map, game->perso.pos, game->perso.direct, game->perso.pos.v*3, game->perso.dmg, game->perso.range,game->visuel.visuel_atk[game->perso.direct-1], game->perso.type, game->perso.rayon_atk,game->syst.personnage);    
      game->perso.AS = 0;
      game->perso.basic = 0;
    }

  }
  else{
    game->perso.AS = game->perso.AS + game->syst.dt;
  }
  
  if(game->perso.spell_cd >= game->perso.spell_cd_ref){
    if(game->perso.spell){
      if(game->syst.personnage){
	game->perso.tps_spell = 10;
	game->perso.dmg = game->perso.dmg+1;
	game->perso.hp = game->perso.hp +2;
	game->perso.pos.v = game->perso.pos.v + 25;
	game->perso.range = game->perso.range + 10;
	game->perso.AS_ref = game->perso.AS_ref*3/2;
	game->perso.spell = 0;
	game->perso.spell_cd =0;
      }
      else{
	creer_mob(&game->map, game->perso.pos, 160, game->perso.pos.v/2,game->visuel.visuel_mob[4], game->perso.hp*3, game->perso.dmg, game->perso.type);
	game->perso.spell = 0;
	game->perso.spell_cd =0;
      }
    }
  }
  else {
    game->perso.spell_cd = game->perso.spell_cd + game->syst.dt;
  }
  if(game->perso.tps_spell >= 0){
    game->perso.tps_spell = game->perso.tps_spell - game->syst.dt;
  }
  else{
    game->perso.pos.v = game->stat.speed;
    game->perso.dmg = game->stat.dmg;
    game->perso.AS_ref = game->stat.AS;
    game->perso.range = game->stat.range_atk;    
  }
}


void afficher(game_t game){
  afficherImage(game.map.map_visuel,game.map.pos.x - tn_largeur(game.map.map_visuel)/2, game.map.pos.y + tn_hauteur(game.map.map_visuel)/2);
  t_image image_ysup;
  t_image image_yinf;   
  int i1 = 0,i2 = 0;
   for(int i = 0; i < game.map.nb_mob; i++){
    if(game.map.mob[i].pos.y >= 0){
      image_ysup.image[i1] = game.map.mob[i].visuel_actif;
      image_ysup.pos[i1].y = game.map.mob[i].pos.y;
      image_ysup.pos[i1].x = game.map.mob[i].pos.x;	
      i1++;		
    }
    else {
      image_yinf.image[i2] = game.map.mob[i].visuel_actif;
      image_yinf.pos[i2].y = game.map.mob[i].pos.y;
      image_yinf.pos[i2].x = game.map.mob[i].pos.x;
      i2++;
    }
  }
   for(int i = 0; i < game.map.nb_item; i++){
    if(game.map.item[i].pos.y >= 0){
      image_ysup.image[i1] = game.map.item[i].visuel;
      image_ysup.pos[i1].y = game.map.item[i].pos.y;
      image_ysup.pos[i1].x = game.map.item[i].pos.x;	
      i1++;		
    }
    else {
      image_yinf.image[i2] = game.map.item[i].visuel;
      image_yinf.pos[i2].y = game.map.item[i].pos.y;
      image_yinf.pos[i2].x = game.map.item[i].pos.x;
      i2++;
    }
  }
  for(int i = 0; i < game.map.nb_projectile; i++){
    if(game.map.projectile[i].pos.y >= 0){
      image_ysup.image[i1] = game.map.projectile[i].visuel;
      image_ysup.pos[i1].y = game.map.projectile[i].pos.y;
      image_ysup.pos[i1].x = game.map.projectile[i].pos.x;	
      i1++;		
    }
    else {
      image_yinf.image[i2] = game.map.projectile[i].visuel;
      image_yinf.pos[i2].y = game.map.projectile[i].pos.y;
      image_yinf.pos[i2].x = game.map.projectile[i].pos.x;
      i2++;
    }
  }
  
  
  for(int i = 0; i < game.map.nb_struct; i++){
    if(game.map.struct_o[i].pos.y >= 0){
      image_ysup.image[i1] = game.map.struct_o[i].image;
      image_ysup.pos[i1].y = game.map.struct_o[i].pos.y;
      image_ysup.pos[i1].x = game.map.struct_o[i].pos.x;	
      i1++;
    }
    else{
      image_yinf.image[i2] = game.map.struct_o[i].image;
      image_yinf.pos[i2].y = game.map.struct_o[i].pos.y;
      image_yinf.pos[i2].x = game.map.struct_o[i].pos.x;	
      i2++;
    }
  }
  
  image_ysup.nb = i1;
  image_yinf.nb = i2;
  ordre_image(&image_ysup);
  ordre_image(&image_yinf);
  for(int l =0; l<i1;l++){
    afficherImage(image_ysup.image[l],image_ysup.pos[l].x - tn_largeur(image_ysup.image[l])/2, image_ysup.pos[l].y + tn_hauteur(image_ysup.image[l])/2);
  }

  afficherImage(game.perso.visuel, game.perso.pos.x - tn_largeur(game.perso.visuel)/2, game.perso.pos.y + tn_hauteur(game.perso.visuel)/2);
  if(game.perso.shield > 0){
    afficherImage(game.visuel.visuel_item[0], -tn_largeur(game.visuel.visuel_item[0])/2, tn_hauteur(game.visuel.visuel_item[0])/2);
  }
  for(int l = 0;l <i2; l++){
    afficherImage(image_yinf.image[l],image_yinf.pos[l].x - tn_largeur(image_yinf.image[l])/2, image_yinf.pos[l].y + tn_hauteur(image_yinf.image[l])/2);
  } 
  afficherImage(game.map.map_calque,game.perso.pos.x- tn_largeur(game.map.map_calque)/2, game.perso.pos.y + tn_hauteur(game.map.map_calque)/2);
 
}





/*Mouvement du perso*/
void  mvt(game_t * game){ 
  if(game->perso.direct == 1){
    game->map.pos_f.y = game->map.pos.y - game->perso.pos.v*game->syst.dt*7/4;
    if(!collision(game)){
      for(int i = 0; i < game->map.nb_mob;i++){
	game->map.mob[i].pos.y = game->map.mob[i].pos.y - game->perso.pos.v*game->syst.dt*7/4;
      }
      for(int i = 0; i < game->map.nb_item;i++){
	game->map.item[i].pos.y = game->map.item[i].pos.y - game->perso.pos.v*game->syst.dt*7/4;
      }
      for(int i = 0; i < game->map.nb_struct;i++){
	game->map.struct_o[i].pos.y = game->map.struct_o[i].pos.y - game->perso.pos.v*game->syst.dt*7/4;
      }     
      for(int i =0; i< game->map.nb_projectile;i++){
	game->map.projectile[i].pos.y = game->map.projectile[i].pos.y - game->perso.pos.v*game->syst.dt*7/4;
      }
    }
    return;
  }
  if(game->perso.direct == 2){
    game->map.pos_f.y = game->map.pos.y + game->perso.pos.v*game->syst.dt*7/4;
    if(!collision(game)){
      for(int i = 0; i < game->map.nb_mob;i++){
	game->map.mob[i].pos.y = game->map.mob[i].pos.y + game->perso.pos.v*game->syst.dt*7/4;
      }
      for(int i = 0; i < game->map.nb_item;i++){
	game->map.item[i].pos.y = game->map.item[i].pos.y + game->perso.pos.v*game->syst.dt*7/4;
      }
      for(int i = 0; i < game->map.nb_struct;i++){
	game->map.struct_o[i].pos.y = game->map.struct_o[i].pos.y + game->perso.pos.v*game->syst.dt*7/4;
      }
      for(int i =0; i< game->map.nb_projectile;i++){
	game->map.projectile[i].pos.y = game->map.projectile[i].pos.y + game->perso.pos.v*game->syst.dt*7/4;
      }
    }
    return;
  }
  if(game->perso.direct == 3){
    game->map.pos_f.x = game->map.pos.x + game->perso.pos.v*game->syst.dt*2;
    if(!collision(game)){
      for(int i = 0; i < game->map.nb_mob;i++){
	game->map.mob[i].pos.x = game->map.mob[i].pos.x + game->perso.pos.v*game->syst.dt*2;
      }
      for(int i = 0; i < game->map.nb_item;i++){
	game->map.item[i].pos.x = game->map.item[i].pos.x + game->perso.pos.v*game->syst.dt*2;
      }
      for(int i = 0; i < game->map.nb_struct;i++){
	game->map.struct_o[i].pos.x = game->map.struct_o[i].pos.x + game->perso.pos.v*game->syst.dt*2;
      }
      for(int i =0; i< game->map.nb_projectile;i++){
	game->map.projectile[i].pos.x = game->map.projectile[i].pos.x + game->perso.pos.v*game->syst.dt*2;
      }
    }
  }
  if(game->perso.direct == 4){
    game->map.pos_f.x = game->map.pos.x - game->perso.pos.v*game->syst.dt*2;
    if(!collision(game)){
      for(int i = 0; i < game->map.nb_mob;i++){
	game->map.mob[i].pos.x = game->map.mob[i].pos.x - game->perso.pos.v*game->syst.dt*2;
      }
      for(int i = 0; i < game->map.nb_item;i++){
	game->map.item[i].pos.x = game->map.item[i].pos.x - game->perso.pos.v*game->syst.dt*2;
      }
      for(int i = 0; i < game->map.nb_struct;i++){
	game->map.struct_o[i].pos.x = game->map.struct_o[i].pos.x - game->perso.pos.v*game->syst.dt*2;
      }
      for(int i =0; i< game->map.nb_projectile;i++){
	game->map.projectile[i].pos.x = game->map.projectile[i].pos.x - game->perso.pos.v*game->syst.dt*2;
      }
    }
  }
}


/*-----------------------------------------------------------------*/
/*Collision*/
int collision(game_t * game){
  int l = 0,c = 0;
  double x = -(game->map.pos_f.x - tn_largeur(game->map.map_visuel)/2); 
  double y = game->map.pos_f.y + tn_hauteur(game->map.map_visuel)/2;
  while(x >= 25){
    x = x - 25;
    c++;
  }
  while(y >= 25){
    y = y - 25;
    l++;
  }
  if(game->map.interaction[l][c] == 2){
    if((-x+26) > y){
       game->map.pos_f.x = game->map.pos.x;
       game->map.pos_f.y = game->map.pos.y;
       return 1;
    }
  }
   if(game->map.interaction[l][c] == 3){
    if(x > y){
       game->map.pos_f.x = game->map.pos.x;
       game->map.pos_f.y = game->map.pos.y;
       return 1;
    }
  }
    if(game->map.interaction[l][c] == 4){
    if(x < y){
       game->map.pos_f.x = game->map.pos.x;
       game->map.pos_f.y = game->map.pos.y;
       return 1;
    }
  }
    if(game->map.interaction[l][c] == 5){
    if((-x+24) < y){
       game->map.pos_f.x = game->map.pos.x;
       game->map.pos_f.y = game->map.pos.y;
       return 1;
    }
  }
  if(game->map.interaction[l][c] == 1){
    game->map.pos_f.x = game->map.pos.x;
    game->map.pos_f.y = game->map.pos.y;
    return 1; 
  } 
  game->map.pos.x = game->map.pos_f.x;
  game->map.pos.y = game->map.pos_f.y;

  return 0;
}
       

/*-----------------------------------------------------------------*/
/*Visuel du perso*/
void visuel(int direct, Image image[],Image * visuel, int frame ){

    if(direct == 1){
      *visuel = image[1+frame]; 
    }
    if(direct == 2){
      *visuel = image[4+frame];
    }
    if(direct == 3){
      *visuel = image[7+frame];
    }
    if(direct == 4){
      *visuel = image[10+frame];
    }
}


/*-----------------------------------------------------------------*/
/*Calcul de la fréquence des images*/
void frame_calc(game_t *game){
  game->syst.tick++;
  if(game->syst.tick > 10000)
    game->syst.tick = 0;
  double frame = cos(game->syst.tick*M_PI/64*2);
  if(frame ==1){
    game->syst.frame = 1;
      return;
  }
  if(frame >(-0.0001) && frame < 0.0001){
    game->syst.frame = 0;
    return;
  }
  if(frame == -1){
    game->syst.frame =-1;
  }
}


void ordre_image(t_image * t_image){
int i,t;
double y_aux,x_aux;
Image i_aux;
 for(t = 0;t < t_image->nb;t++){
   for(i = 0;i < t_image->nb-1;i++){	
     if(t_image->pos[i].y < t_image->pos[i+1].y){
       x_aux= t_image->pos[i].x;
       t_image->pos[i].x = t_image->pos[i+1].x ;
       t_image->pos[i+1].x = x_aux;	
       y_aux = t_image->pos[i].y;
       t_image->pos[i].y = t_image->pos[i+1].y ;
       t_image->pos[i+1].y = y_aux;
       i_aux = t_image->image[i];
       t_image->image[i] = t_image->image[i+1];
       t_image->image[i+1] = i_aux;
     }
   }
 }
}

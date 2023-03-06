#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <libTableauNoir.h>
#include "structure.h"
#include "mob.h"
#include "detection.h"

/*******************************************************************/
/*detection des touches attaques*/
void detect_att(game_t * game){
  EtatSourisClavier ESC = lireEtatSourisClavier();
  if(ESC.touchesClavier[13]){
    if(game->perso.AS >= game->perso.AS_ref){
      game->perso.basic = 1;
    }
  }
  if(ESC.touchesClavier[14]){
    if(game->perso.spell_cd >= game->perso.spell_cd_ref){
      game->perso.spell =1;
    }
  }

}/*-----------------------------------------------------------------*/
/*détection d'obstacle sur un chemin*/
int detect_traj(coord_t pos1, coord_t pos2, game_t game){
  double vectx = 5*(pos2.x -pos1.x)/sqrt(pow(pos1.x - pos2.x,2)+pow(pos1.y - pos2.y,2));
  double vecty = 5*(pos2.y -pos1.y)/sqrt(pow(pos1.x - pos2.x,2)+pow(pos1.y - pos2.y,2));
  mob_t lux ={.pos_f = {pos1.x, pos1.y}};
  int res = 0;
  while(sqrt(pow(pos2.x-pos1.x,2)+pow(pos2.y-pos1.y,2)) > 6){
    pos1.x = pos1.x + vectx;
    pos1.y = pos1.y + vecty;
    if(collision_mob(&lux.pos_f,&lux.pos,game)){
      res = 1;
    }
    lux.pos_f.x = pos1.x;
    lux.pos_f.y = pos1.y;
  }
  return res;
}

/*Vérifier si un joueur est dans le champ de vision du monstre*/
int detect_entite(double range_att, int direction, coord_t pos,coord_t pos1, int nb_hit, game_t game){
  if((sqrt(pow(pos.x - pos1.x,2)+pow(pos.y - pos1.y,2)) < range_att)){
    if(direction == 1){
      if(((atan2(pos1.y-pos.y,pos1.x-pos.x) > 7*M_PI/36) && (atan2(pos1.y-pos.y,pos1.x-pos.x) < 29*M_PI/36)) || nb_hit){
	if(!nb_hit){
	  if(!detect_traj(pos,pos1, game)){
	    return 1;
	  }	  
	}
	else{
	  return 1;
	}
      }
    }
    else{
      if(direction == 2){
	if(((atan2(pos1.y-pos.y,pos1.x-pos.x) < (-7*M_PI/36)) && (atan2(pos1.y-pos.y,pos1.x-pos.x) > (-29*M_PI/36)))|| nb_hit){
	  if(!nb_hit){
	    if(!detect_traj(pos,pos1, game)){
	      return 1;
	    }	  
	  }
	  else{
	    return 1;
	  }
	}	
      }
      else{
	if(direction == 3){
	  if((atan2(pos1.y-pos.y,pos1.x-pos.x) >(29*M_PI/36)) || (atan2(pos1.y-pos.y,pos1.x-pos.x) < (-29*M_PI/36))|| nb_hit){
	    if(!nb_hit){
	      if(!detect_traj(pos,pos1,game)){
		return 1;
	      }	  
	    }
	    else{
	      return 1;
	    }
	  }
	}
	else{
	  if(direction == 4){	
	    if(((atan2(pos1.y-pos.y,pos1.x-pos.x) < (7*M_PI/36)) && (atan2(pos1.y-pos.y,pos1.x-pos.x)> (-7*M_PI/36)))|| nb_hit){
	      if(!nb_hit){
		if(!detect_traj(pos,pos1, game)){
		  return 1;
		}	  
	      }
	      else{
		return 1;
	      }
	    }
	  }
	}
      }
    }
  }
  return 0;
}
/*-----------------------------------------------------------------*/
/*Détection des touches*/
int detect(EtatSourisClavier ESC, game_t *game){
  if(ESC.touchesClavier[26]){
    game->perso.direct = 1;
    return 1;
  }
  if(ESC.touchesClavier[22]){
    game->perso.direct =  2;
    return 1;
  }
  if(ESC.touchesClavier[4]){
    game->perso.direct =  3;
    return 1;
  }
  if(ESC.touchesClavier[7]){
    game->perso.direct =  4;
    return 1;
  }
  return 0;

}


void path_finder(mob_t * mob, game_t *game){
if(fabs(mob->vect.x) >= fabs(mob->vect.y)){
	mob->pos_f.x = mob->pos.x + mob->vect.x/fabs(mob->vect.x)*mob->pos.v*game->syst.dt*2;
	mob->pos_f.y = mob->pos.y;
	int collision = collision_mob(&mob->pos_f, &mob->pos,*game);
	if(!collision){	 
	  if((mob->pos_f.x - mob->pos.x) >0){
	    mob->direct = 4;
	  }
	  else{
	    mob->direct = 3;
	  }
	  mob->pos.x = mob->pos_f.x;
	}
	else{
	  if((mob->pos.y + mob->pos.v*game->syst.dt) > (mob->pos.y - mob->pos.v*game->syst.dt)){
	    mob->pos_f.y = mob->pos.y - mob->pos.v*game->syst.dt*2;
	    mob->pos_f.x = mob->pos.x;
	    if(!collision_mob(&mob->pos_f, &mob->pos, *game)){
		if((mob->pos_f.y - mob->pos.y) > 0){
		  mob->direct = 1;
		}
		else{
		  mob->direct = 2;
		}
		mob->pos.y = mob->pos_f.y;
	      }
	  }
	  else{
	    mob->pos_f.y = mob->pos.y + mob->pos.v*game->syst.dt*2;
	    if((mob->pos_f.y - mob->pos.y) > 0){
	      mob->direct = 1;
	    }
	    else{
	      mob->direct = 2;
	    }
	    mob->pos.y = mob->pos_f.y;
	  }
	  
	}
      }
      else{
	mob->pos_f.y = mob->pos.y + mob->vect.y/fabs(mob->vect.y)*mob->pos.v*game->syst.dt*2;
	mob->pos_f.x = mob->pos.x;
	int collision = collision_mob(&mob->pos_f, &mob->pos,*game);
	if(!collision){	 
	  if((mob->pos_f.y - mob->pos.y) >0 ){
	    mob->direct = 1;
	  }
	  else{
	    mob->direct = 2;
	  }
	  mob->pos.y = mob->pos_f.y;
	}
	else{
	  if((mob->pos.x + mob->pos.v*game->syst.dt) > (mob->pos.x - mob->pos.v*game->syst.dt)){
	    mob->pos_f.x = mob->pos.x - mob->pos.v*game->syst.dt*2;
	    mob->pos_f.y = mob->pos.y;
	    if(!collision_mob(&mob->pos_f, &mob->pos, *game)){
		if((mob->pos_f.x - mob->pos.x) > 0){
		  mob->direct = 4;
		}
		else{
		  mob->direct = 3;
		}
		mob->pos.x = mob->pos_f.x;
	      }
	  }
	  else{
	    mob->pos_f.x = mob->pos.x + mob->pos.v*game->syst.dt*2;
	    if((mob->pos_f.x - mob->pos.x) > 0){
	      mob->direct = 4;
	    }
	    else{
	      mob->direct = 3;
	    }
	    mob->pos.x = mob->pos_f.x;
	  }
	}
      }

}

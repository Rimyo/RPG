#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <libTableauNoir.h>
#include "structure.h"
#include "init.h"
#include "mob.h"
#include "detection.h"
#include "entite.h"
#include "menu.h"
#include "personnage.h"


void mettre_a_jour_game(game_t *game);
double game_end(game_t);




int main(){

  creerTableau();
  fixerModeBufferisation(1);
  fixerTaille(600,600);

  animation_deb();
  game_t game;
  game.syst.personnage = -1;
  game.syst.nb_map = -1;
  while(game.syst.personnage == -1 || game.syst.nb_map == -1 ){
    selection(&game);
  }
  game.stat.hp = game.perso.hp;
  game.stat.dmg = game.perso.dmg;
  game.stat.speed = game.perso.pos.v;
  game.stat.range_atk = game.perso.range;
  game.stat.AS = game.perso.AS_ref;
  while (!game_end(game) && !fermetureDemandee()){
    mettre_a_jour_game(&game);    
    afficher(game);
    tamponner();
    effacerTableau();
  }
  printf("temps de jeu : %f", game.syst.temps);
  fin(game);
}



/*-----------------------------------------------------------------*/
/*Mise à jour des données*/
void mettre_a_jour_game(game_t *game){
  if(game->syst.nb_map == 1){
    if((game->map.pos.y - tn_hauteur(game->map.map_visuel)/2) < -575){
      for(int i =0; i< game->map.nb_mob; i++){
	if(!game->map.mob[i].visible)
	  game->map.mob[i].visible = 1;
      }
      game->map.interaction[14][7] = 1;
      game->map.interaction[14][8] = 1;
    }
  }
  EtatSourisClavier ESC = lireEtatSourisClavier();
  game->syst.temps = game->syst.temps + game->syst.dt;
  game->syst.dt =  delta_temps();
  image_base(game);
  if(game->perso.shield >=0){
    game->perso.shield = game->perso.shield - game->syst.dt;
  }  
  if(ESC.sourisBoutonGauche || !game->perso.hp){
    game->syst.end = 1;
  }
  maj_item(game);
  maj_mob(game);
  detect_att(game);
  attaque(game);
  maj_projectile(&game->map, game);
  maj_mort_mob(game);
  frame_calc(game);
  for(int i =0; i< game->map.nb_mob; i++){
    if(game->map.mob[i].shield >= 0){
      game->map.mob[i].shield = game->map.mob[i].shield - game->syst.dt;
    }

  }
  if(detect(ESC, game)){    
    mvt(game);
    if(game->perso.tps_spell>=0){
      visuel(game->perso.direct, game->visuel.visuel_mob, &game->perso.visuel, game->syst.frame);
    }
    else{
      visuel(game->perso.direct, game->visuel.visuel_mvt, &game->perso.visuel, game->syst.frame);
    }
  }
}





double game_end(game_t game){
  return game.syst.end;
}




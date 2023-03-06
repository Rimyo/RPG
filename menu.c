#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <libTableauNoir.h>
#include "structure.h"
#include "init.h"
#include "menu.h"



void fin(game_t game){
  if(game.map.nb_mob == 0){
    Image win = chargerImage("win.png");
    afficherImage(win,-300,300);
    tamponner();
    attendreNms(1000);
    libererImage(win);
  }
  else {
    Image dead = chargerImage("died_page.png");
    afficherImage(dead,-300,300);
    tamponner();
    attendreNms(1000);
    libererImage(dead);
  }
  for(int i = 0; i < game.map.nb_struct; i++){    
    libererImage(game.map.struct_o[i].image);
  }
  libererImage(game.map.map_visuel);
  libererImage(game.map.map_calque);
  for(int i =0; i< 4; i++){
    libererImage(game.visuel.visuel_atk[i]);
  }
  for(int i = 0; i < 12; i++){
    libererImage(game.visuel.visuel_mvt[i]);
  }
  for(int i =0; i < 5; i++){   
    libererImage(game.visuel.visuel_pro[i]);
  }
  for(int i =0; i < 2; i++){   
    libererImage(game.visuel.visuel_item[i]);
  }
  for(int i =0; i < 24; i ++){
    libererImage(game.visuel_mob.ghost[i]);
  }
  for(int i =0; i < 12; i++){
    libererImage(game.visuel_mob.zombie[i]);
    }
}

void transition1(Image image[]){
  for(int i = 0; i< 7; i++){
    afficherImage(image[i], -300, 300);
    tamponner();
    effacerTableau();
    attendreNms(150);
  }
 
}

void store(game_t *game){
  Image store = chargerImage("store.png");
  afficherImage(store,-300,300);
  tamponner();
  attendreNms(1500);
  libererImage(store);
}

void selection_mode(game_t *game){
  attendreNms(200);
  Image cadre2 = chargerImage("parchemin.png");
  Image fond_page = chargerImage("fond_page.png");
  Image selection_mode_page = chargerImage("selection_page_mode.png");
  int j =0;
    EtatSourisClavier esc = lireEtatSourisClavier();
    while(!esc.touchesClavier[13]){
      esc = lireEtatSourisClavier();
      if(esc.touchesClavier[26]){
	j = 0;
      }
      if(esc.touchesClavier[22]){
	j = 110;
      }
      afficherImage(fond_page, -300, 300);
      afficherImage(cadre2, -140, 195 - j);
      afficherImage(selection_mode_page, -300, 300);
      tamponner();
      effacerTableau();
      attendreNms(100);
    }
    if(j == 0){
      game->syst.nb_map = 1;
      Image tips = chargerImage("tips_n1.png");
      afficherImage(tips,-300,300);
      tamponner();
      attendreNms(200);
      esc = lireEtatSourisClavier();
      while(!esc.touchesClavier[13]){
	esc = lireEtatSourisClavier();
      }
      libererImage(tips);
    }
    if(j== 110){
      game->syst.nb_map = 0;
      Image tips = chargerImage("tips_survival.png");
      afficherImage(tips,-300,300);
      tamponner();
      attendreNms(200);
      esc = lireEtatSourisClavier();
      while(!esc.touchesClavier[13]){
	esc = lireEtatSourisClavier();
      }
      libererImage(tips);
    }

    libererImage(cadre2);
    libererImage(selection_mode_page);
    libererImage(fond_page);
}


void selection_perso(game_t * game){
  attendreNms(200);
  int l = 0;
  Image cadre2 = chargerImage("parchemin.png");
  Image selection_perso_page = chargerImage("selection_page_perso.png");
  Image fond_page = chargerImage("fond_page.png");
  EtatSourisClavier esc = lireEtatSourisClavier();
  while(!esc.touchesClavier[13]){
    esc = lireEtatSourisClavier();
    if(esc.touchesClavier[26]){
      l = 0;
    }
    if(esc.touchesClavier[22]){
      l = 117;
    }      
    afficherImage(fond_page, -300, 300);
    afficherImage(cadre2, -130, 180 - l);
    afficherImage(selection_perso_page, -300, 300);
    tamponner();
    effacerTableau();
    attendreNms(100);      
  }
  if(l == 0){
    game->syst.personnage =0;
     Image tips = chargerImage("perso_rim.png");
      afficherImage(tips,-300,300);
      tamponner();
      attendreNms(200);
      esc = lireEtatSourisClavier();
      while(!esc.touchesClavier[13]){
	esc = lireEtatSourisClavier();
      }
      libererImage(tips);
  }
  if(l == 117){
    game->syst.personnage =1;
     Image tips = chargerImage("perso_riku.png");
      afficherImage(tips,-300,300);
      tamponner();
      attendreNms(200);
      esc = lireEtatSourisClavier();
      while(!esc.touchesClavier[13]){
	esc = lireEtatSourisClavier();
      }
      libererImage(tips);
  }
  libererImage(cadre2);
  libererImage(selection_perso_page);
  libererImage(fond_page);
}

void selection(game_t *game){
  game->syst.nb_map = -1;
  game->syst.personnage = -1;

  Image page = chargerImage("selection_page.png");
  Image cadre = chargerImage("selection_bordure.png");
  Image error_selection = chargerImage("error_selection.png");
  EtatSourisClavier esc = lireEtatSourisClavier();
  int i =0;
  /*1ere page de selection*/
  while(!esc.touchesClavier[13] || i != 330){
    esc = lireEtatSourisClavier(); 
    if(esc.touchesClavier[26]){
      if(i >= 110){
	i = i - 110;
      }
    }
    if(esc.touchesClavier[22]){
      if(i <=220 ){
	i =  i + 110;
      }
    }
    afficherImage(page, -300, 300);
    afficherImage(cadre, -180 , 180- i);    
    tamponner();
    effacerTableau();
    attendreNms(100);
    esc = lireEtatSourisClavier();
    if(esc.touchesClavier[13] && i == 0){
      selection_perso(game);
      attendreNms(200);
    }
    if(esc.touchesClavier[13] && i == 110){
      selection_mode(game);
      attendreNms(200);
    }
    if(esc.touchesClavier[13] && i == 220){
      store(game);
      attendreNms(200);
    }
    esc = lireEtatSourisClavier();
  }
  if(game->syst.personnage == -1 || game->syst.nb_map == -1){
    afficherImage(error_selection, -300,300);
    tamponner();
    attendreNms(1000);
  }
  else{
    int personnage = game->syst.personnage;
    if(game->syst.nb_map == 0){
      survival(game);
    }
    else{
      niveau1(game);
    }
    if(personnage == 1){
      perso_riku(game);
    }
    if(personnage == 0){
      perso_rim(game);    
    }
    game->syst.personnage = personnage;
  }
  libererImage(error_selection);
  libererImage(cadre);
  libererImage(page);
}


void animation_deb(){

  Image anim[7] =  {
    chargerImage("dark1.png"),
    chargerImage("dark2.png"),
    chargerImage("dark3.png"),
    chargerImage("dark4.png"),
    chargerImage("dark5.png"),
    chargerImage("dark6.png"),
    chargerImage("dark7.png"),
  };
  Image menu = chargerImage("menu.png");
  Image tools = chargerImage("intro_rpg.png");  
  EtatSourisClavier esc = lireEtatSourisClavier();
  afficherImage(tools,- tn_largeur(tools)/2, tn_hauteur(tools)/2);
  tamponner();
  while(!esc.touchesClavier[13]){
    esc = lireEtatSourisClavier();
    attendreNms(80);
  }
  transition1(anim);
  effacerTableau();
  afficherImage(menu, - 300, 300);
  attendreNms(1000);
  esc = lireEtatSourisClavier();
  tamponner();
   while(!esc.touchesClavier[13]){
    esc = lireEtatSourisClavier();
    attendreNms(100);
  }
  transition1(anim);
  effacerTableau();
  for(int i = 0; i < 7 ; i++){
    libererImage(anim[i]);
  }
  libererImage(menu);
  libererImage(tools);
}

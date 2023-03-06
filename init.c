#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <libTableauNoir.h>
#include "structure.h"
#include "init.h"

void niveau1(game_t *game){
  game_t game1 = {    
    .map = { .map_visuel = chargerPixelArt("map_n1.png"),
	   
	     .map_calque = chargerPixelArt("dark1.png"),

	     .struct_o = { {.pos={-124,289}, .image = chargerPixelArt("tree3.png")},
			   {.pos={-51,65}, .image = chargerPixelArt("tree3.png")},
			   {.pos={-92,145}, .image = chargerPixelArt("tree1.png")},
			   {.pos={132,220}, .image = chargerPixelArt("tree1.png")},
			   {.pos={130,343}, .image = chargerPixelArt("tree3.png")},
			   {.pos={79,95}, .image = chargerPixelArt("tree2.png")},
			   {.pos={0,-40}, .image = chargerPixelArt("wall.png")}},
	     
	     .pos={0,395},
	     
	     .pos_f = {0,395},
	     
	     .mob ={{.pos={100,750,90}, .pos_f={101,750}, .range_att = 160,.tps_move = 0, .hp = 4, .type = 2, .visible =0},
		    {.pos={0,750,90}, .pos_f={0,750}, .range_att = 160,.tps_move = 0,.hp = 4, .type = 2,.visible =0},
		    {.pos={-100,750,90}, .pos_f={-100,750}, .range_att = 160,.tps_move = 0,.hp = 4, .type = 2,.visible =0},
		    {.pos={169,201,60}, .pos_f={169,201}, .range_att = 160,.tps_move = 0,.hp =3,.type =1,.dmg = 1,.visible =1},
		    {.pos={-169,201,60}, .pos_f={-169,201}, .range_att = 160,.tps_move = 0,.hp = 3,.type =1,.dmg = 1,.visible =1},
		    {.pos={64,277,60}, .pos_f={64,277}, .range_att = 160,.tps_move = 0,.hp = 3,.type =1,.dmg = 1,.visible =1},
		    {.pos={-64,277,60}, .pos_f={-64,277}, .range_att = 160,.tps_move = 0,.hp = 3,.type =1,.dmg = 1,.visible =1},
		    {.pos={25,325,60}, .pos_f={25,325}, .range_att = 160,.tps_move = 0,.hp = 3,.type =1,.dmg = 1,.visible =1},
		    {.pos={-25,325,60}, .pos_f={-25,325}, .range_att = 160,.tps_move = 0,.hp = 3,.type =1,.dmg = 1,.visible =1}},
	     .nb_struct = 7,
	     .nb_projectile =0,
	     .nb_mob = 9,
	     .interaction =       {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//0
				   {1,1,1,1,2,0,0,0,0,0,0,3,1,1,1,1},
				   {1,1,1,2,0,0,0,0,0,0,0,0,3,1,1,1},
				   {1,1,2,0,0,0,0,0,0,0,0,0,0,3,1,1},
				   {1,2,0,0,0,0,0,0,0,0,0,0,0,0,3,1},
				   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//5
				   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				   {1,4,0,0,0,0,0,0,0,0,0,0,0,0,5,1},//10
				   {1,1,4,0,0,0,0,0,0,0,0,0,0,5,1,1},
				   {1,1,1,4,0,0,0,0,0,0,0,0,5,1,1,1},
				   {1,1,1,1,4,0,0,0,0,0,0,5,1,1,1,1},
				   {1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1},
				   {1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1},//15
				   {1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1},
				   {1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1},
				   {1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1},
				   {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1},
				   {1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1},//20
				   {1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1},
				   {1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1},
				   {1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1},
				   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				   {1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1},//25
				   {1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1},
				   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				   {1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1},
				   {1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1},
				   {1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1},//30
				   {1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,1},
				   {1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1},
				   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//35
				   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}}

    },
    .syst = { .tick=0, .end =0,.nb_map =1},
    
    .visuel={ .visuel_pro ={	chargerImage("claws effect3.png"),
				chargerImage("claws effect4.png"),
				chargerImage("claws effect3.png"),
				chargerImage("claws effect4.png"),
				chargerImage("orbre_energy.png")},
	      .visuel_item ={ chargerImage("shield.png"),
			      chargerImage("gold1.png")}, 
	     
    },
    
    .visuel_mob={.ghost={
	chargerPixelArt("ghost_dos1.png"),
	chargerPixelArt("ghost_dos2.png"),
	chargerPixelArt("ghost_dos3.png"),
	chargerPixelArt("ghost_face1.png"),
	chargerPixelArt("ghost_face2.png"),
	chargerPixelArt("ghost_face3.png"),
	chargerPixelArt("ghost_profilg1.png"),
	chargerPixelArt("ghost_profilg2.png"),
	chargerPixelArt("ghost_profilg3.png"),
	chargerPixelArt("ghost_profild1.png"),
	chargerPixelArt("ghost_profild2.png"),
	chargerPixelArt("ghost_profild3.png"),
	chargerPixelArt("ghost_dos1bis.png"),
	chargerPixelArt("ghost_dos2bis.png"),
	chargerPixelArt("ghost_dos3bis.png"),
	chargerPixelArt("ghost_face1bis.png"),
	chargerPixelArt("ghost_face2bis.png"),
	chargerPixelArt("ghost_face3bis.png"),
	chargerPixelArt("ghost_profilg1bis.png"),
	chargerPixelArt("ghost_profilg2bis.png"),
	chargerPixelArt("ghost_profilg3bis.png"),
	chargerPixelArt("ghost_profild1bis.png"),
	chargerPixelArt("ghost_profild2bis.png"),
	chargerPixelArt("ghost_profild3bis.png")},
		 .zombie ={
	chargerPixelArt("zombie_dos1.png"),
	chargerPixelArt("zombie_dos2.png"),
	chargerPixelArt("zombie_dos3.png"),
	chargerPixelArt("zombie_face1.png"),
	chargerPixelArt("zombie_face2.png"),
	chargerPixelArt("zombie_face3.png"),
	chargerPixelArt("zombie_profilg1.png"),
	chargerPixelArt("zombie_profilg2.png"),
	chargerPixelArt("zombie_profilg3.png"),
	chargerPixelArt("zombie_profild1.png"),
	chargerPixelArt("zombie_profild2.png"),
	chargerPixelArt("zombie_profild3.png")
      }
    }
    };
  for(int i =0; i < 9; i++){
    if(game1.map.mob[i].type == 2){
    game1.map.mob[i].visuel_actif = game1.visuel_mob.ghost[4];
    }
    else{
      game1.map.mob[i].visuel_actif = game1.visuel_mob.zombie[4];
    }
  }
  game1.perso.visuel = game1.visuel.visuel_mvt[4];
  *game = game1;
}

void survival(game_t *game){
  game_t game1 = {
    .map ={
      .struct_o ={{.pos={0,115},.image =chargerImage("mur2.png")},
		  {.pos={0,-75},.image =chargerImage("mur1.png")}},
      .mob={       {.pos={300,300,60}, .pos_f={169,201}, .range_att = 160,.tps_move = 0,.hp =4,.type =1,.dmg = 1, .visible =1},
		      {.pos={-300,300,60}, .pos_f={-169,201}, .range_att = 160,.tps_move = 0,.hp = 4,.type =1,.dmg = 1, .visible =1},
		      {.pos={-300,-300,60}, .pos_f={64,277}, .range_att = 160,.tps_move = 0,.hp = 4,.type =1,.dmg = 1, .visible =1},
		      {.pos={300,-300,60}, .pos_f={-64,277}, .range_att = 160,.tps_move = 0,.hp = 4,.type =1,.dmg = 1, .visible =1},
		      {.pos={-400,0,60}, .pos_f={25,325}, .range_att = 160,.tps_move = 0,.hp = 4,.type =1,.dmg = 1, .visible =1},
		      {.pos={400,0,60}, .pos_f={-25,325}, .range_att = 160,.tps_move = 0,.hp = 4,.type =1,.dmg = 1, .visible =1},
		      {.pos={-300,400,60}, .pos_f={-25,325}, .range_att = 160,.tps_move = 0,.hp = 4,.type =1,.dmg = 1, .visible =1},
		      {.pos={300,400,60}, .pos_f={-25,325}, .range_att = 160,.tps_move = 0,.hp = 4,.type =1,.dmg = 1, .visible =1},
		      {.pos={-300,-325,60}, .pos_f={-25,325}, .range_att = 160,.tps_move = 0,.hp = 4,.type =1,.dmg = 1, .visible =1},
		      {.pos={300,-325,60}, .pos_f={-25,325}, .range_att = 160,.tps_move = 0,.hp = 4,.type =1,.dmg = 1, .visible =1},
		      {.pos={400,-300,60}, .pos_f={-25,325}, .range_att = 160,.tps_move = 0,.hp = 4,.type =1,.dmg = 1, .visible =1},
		      {.pos={400,300,60}, .pos_f={-25,325}, .range_att = 160,.tps_move = 0,.hp = 4,.type =1,.dmg = 1, .visible =1},
		      {.pos={-400,300,60}, .pos_f={-25,325}, .range_att = 160,.tps_move = 0,.hp = 4,.type =1,.dmg = 1, .visible =1},
		      {.pos={-400,-300,60}, .pos_f={-25,325}, .range_att = 160,.tps_move = 0,.hp = 4,.type =1,.dmg = 1, .visible =1},
		      {.pos={100,-350,60}, .pos_f={-25,325}, .range_att = 160,.tps_move = 0,.hp = 4,.type =1,.dmg = 1, .visible =1},
		      {.pos={-100,-350,60}, .pos_f={-25,325}, .range_att = 160,.tps_move = 0,.hp = 4,.type =1,.dmg = 1, .visible =1},
		      {.pos={100,400,60}, .pos_f={-25,325}, .range_att = 160,.tps_move = 0,.hp = 4,.type =1,.dmg = 1, .visible =1},
		      {.pos={-100,400,60}, .pos_f={-25,325}, .range_att = 160,.tps_move = 0,.hp = 4,.type =1,.dmg = 1, .visible =1},
		      {.pos={300,0,60}, .pos_f={-25,325}, .range_att = 160,.tps_move = 0,.hp = 4,.type =1,.dmg = 1, .visible =1},
		      {.pos={-300,0,60}, .pos_f={-25,325}, .range_att = 160,.tps_move = 0,.hp = 4,.type =1,.dmg = 1, .visible =1},
		      {.pos={-275,0,60}, .pos_f={-25,325}, .range_att = 160,.tps_move = 0,.hp = 4,.type =1,.dmg = 1, .visible =1},
		   {.pos={275,0,60}, .pos_f={-25,325}, .range_att = 160,.tps_move = 0,.hp = 4,.type =1,.dmg = 1, .visible =1}},
      .nb_struct =2,
      .nb_mob = 22,
      .nb_projectile =0,
      .map_visuel = chargerImage("map_survival.png"),
      .map_calque = chargerPixelArt("calque.png"),
                     //0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
      .interaction = {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//0
		      {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		      {1,1,1,1,1,1,1,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,1,1,1,1,1,1,1,1,1},
		      {1,1,1,1,1,1,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,1,1,1,1,1,1,1,1},
		      {1,1,1,1,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,1,1,1,1,1,1},
		      {1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1},//5
		      {1,1,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,1,1,1,1},
		      {1,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,1,1,1},
		      {1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1},
		      {1,1,2,0,0,0,0,0,0,0,0,1,1,0,1,1,0,1,1,0,0,1,1,0,1,1,0,1,1,0,0,0,0,0,0,0,0,3,1,1},
		      {1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1},//10
		      {1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1},
		      {1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1},
		      {1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1},
		      {1,2,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,3,1},
		      {1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,1,1,0,0,1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1},//15
		      {1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1},
		      {1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1},
		      {1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1},
		      {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		      {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//20
		      {1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1},
		      {1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1},
		      {1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,1,1,0,0,1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1},
		      {1,4,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,5,1},
		      {1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1},//25
		      {1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1},
		      {1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1},
		      {1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1},
		      {1,1,4,0,0,0,0,0,0,0,0,1,1,0,1,1,0,1,1,0,0,1,1,0,1,1,0,1,1,0,0,0,0,0,0,0,0,5,1,1},
		      {1,1,1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,1,1,1},//30
		      {1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
		      {1,1,1,1,1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,1,1,1,1,1},
		      {1,1,1,1,1,1,1,1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,1,1,1,1,1,1,1,1},
		      {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1},
		      {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//35
		      {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		      {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		      {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		      {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
      }},
    
    .syst = { .tick=0, .end =0, .nb_map =0},
    
    .visuel={
             .visuel_pro ={ chargerImage("claws effect3.png"),
			    chargerImage("claws effect4.png"),
			    chargerImage("claws effect3.png"),
			    chargerImage("claws effect4.png"),
			    chargerImage("orbre_energy.png")},
	     .visuel_item = {chargerImage("shield.png"),
			     chargerImage("gold1.png")},
	     
	     
    },
    .visuel_mob = { 	 .zombie ={
	chargerPixelArt("zombie_dos1.png"),
	chargerPixelArt("zombie_dos2.png"),
	chargerPixelArt("zombie_dos3.png"),
	chargerPixelArt("zombie_face1.png"),
	chargerPixelArt("zombie_face2.png"),
	chargerPixelArt("zombie_face3.png"),
	chargerPixelArt("zombie_profilg1.png"),
	chargerPixelArt("zombie_profilg2.png"),
	chargerPixelArt("zombie_profilg3.png"),
	chargerPixelArt("zombie_profild1.png"),
	chargerPixelArt("zombie_profild2.png"),
	chargerPixelArt("zombie_profild3.png")
      }  }};
  for(int i =0; i < 22; i++){
    if(game1.map.mob[i].type == 1){
      game1.map.mob[i].visuel_actif = game1.visuel_mob.zombie[4];
    }
  }
  game1.perso.visuel = game1.visuel.visuel_mvt[4];
  *game = game1;

}

void perso_rim(game_t *game){
  game->perso = (perso_t){.pos={0,0,80}, .AS_ref = 1.5, .range = 160, .dmg = 1, .direct = 1, .basic =0, .hp = 2, .type =0, .rayon_atk = 12, .spell_cd = 15, .spell_cd_ref = 20, .rayon_atk = 13};
    game->visuel.visuel_mvt[0] =chargerPixelArt("rim_dos1.png");
    game->visuel.visuel_mvt[1] =chargerPixelArt("rim_dos2.png");
    game->visuel.visuel_mvt[2] =chargerPixelArt("rim_dos3.png");
    game->visuel.visuel_mvt[3] =chargerPixelArt("rim_face1.png");
    game->visuel.visuel_mvt[4] =chargerPixelArt("rim_face2.png");
    game->visuel.visuel_mvt[5] =chargerPixelArt("rim_face3.png");;
    game->visuel.visuel_mvt[6] = chargerPixelArt("rim_profilg1.png");
    game->visuel.visuel_mvt[7] = chargerPixelArt("rim_profilg2.png");
    game->visuel.visuel_mvt[8] = chargerPixelArt("rim_profilg3.png");
    game->visuel.visuel_mvt[9] = chargerPixelArt("rim_profild1.png");
    game->visuel.visuel_mvt[10] = chargerPixelArt("rim_profild2.png");
    game->visuel.visuel_mvt[11] = chargerPixelArt("rim_profild3.png");

    
    game->visuel.visuel_atk[0] = chargerImage("crystal.png");
    game->visuel.visuel_atk[1] =   chargerImage("crystal2.png");
    game->visuel.visuel_atk[2] =  chargerImage("crystal3.png");
    game->visuel.visuel_atk[3] = chargerImage("crystal4.png");
    
    game->visuel.visuel_mob[0] = chargerPixelArt("golem_dos1.png");
    game->visuel.visuel_mob[1] = chargerPixelArt("golem_dos2.png");
    game->visuel.visuel_mob[2] =chargerPixelArt("golem_dos3.png");  		   
    game->visuel.visuel_mob[3] =  chargerPixelArt("golem_face1.png");
    game->visuel.visuel_mob[4] =  chargerPixelArt("golem_face2.png");
    game->visuel.visuel_mob[5] =  chargerPixelArt("golem_face3.png");
    game->visuel.visuel_mob[6] =  chargerPixelArt("golem_profilg1.png");
    game->visuel.visuel_mob[7] =  chargerPixelArt("golem_profilg2.png");
    game->visuel.visuel_mob[8] =  chargerPixelArt("golem_profilg3.png");
    game->visuel.visuel_mob[9] =  chargerPixelArt("golem_profild1.png");
    game->visuel.visuel_mob[10] =  chargerPixelArt("golem_profild2.png");
    game->visuel.visuel_mob[11] =  chargerPixelArt("golem_profild3.png");

    game->perso.visuel = game->visuel.visuel_mvt[4];
}

void perso_riku(game_t * game){
  game->perso = (perso_t){.pos={0,0,80}, .AS_ref = 0.75, .range = 40, .dmg = 1, .direct = 1, .basic =0, .hp = 4, .type =0, .tps_spell = 0,.spell_cd = 25, .spell_cd_ref = 30, .rayon_atk = 30};
    game->visuel.visuel_mvt[0] =chargerPixelArt("riku_dos1.png");
    game->visuel.visuel_mvt[1] =chargerPixelArt("riku_dos2.png");
    game->visuel.visuel_mvt[2] =chargerPixelArt("riku_dos3.png");
    game->visuel.visuel_mvt[3] =chargerPixelArt("riku_face1.png");
    game->visuel.visuel_mvt[4] =chargerPixelArt("riku_face2.png");
    game->visuel.visuel_mvt[5] =chargerPixelArt("riku_face3.png");;
    game->visuel.visuel_mvt[6] = chargerPixelArt("riku_profilg1.png");
    game->visuel.visuel_mvt[7] = chargerPixelArt("riku_profilg2.png");
    game->visuel.visuel_mvt[8] = chargerPixelArt("riku_profilg3.png");
    game->visuel.visuel_mvt[9] = chargerPixelArt("riku_profild1.png");
    game->visuel.visuel_mvt[10] = chargerPixelArt("riku_profild2.png");
    game->visuel.visuel_mvt[11] = chargerPixelArt("riku_profild3.png");

    
    game->visuel.visuel_atk[0] = chargerImage("claws effect3_blue.png");
    game->visuel.visuel_atk[1] =   chargerImage("claws effect4_blue.png");
    game->visuel.visuel_atk[2] =  chargerImage("claws effect3_blue.png");
    game->visuel.visuel_atk[3] = chargerImage("claws effect4_blue.png");
    
    game->visuel.visuel_mob[0] = chargerPixelArt("lg_dos1.png");
    game->visuel.visuel_mob[1] = chargerPixelArt("lg_dos2.png");
    game->visuel.visuel_mob[2] =chargerPixelArt("lg_dos3.png");  		   
    game->visuel.visuel_mob[3] =  chargerPixelArt("lg_face1.png");
    game->visuel.visuel_mob[4] =  chargerPixelArt("lg_face2.png");
    game->visuel.visuel_mob[5] =  chargerPixelArt("lg_face3.png");
    game->visuel.visuel_mob[6] =  chargerPixelArt("lg_profilg1.png");
    game->visuel.visuel_mob[7] =  chargerPixelArt("lg_profilg2.png");
    game->visuel.visuel_mob[8] =  chargerPixelArt("lg_profilg3.png");
    game->visuel.visuel_mob[9] =  chargerPixelArt("lg_profild1.png");
    game->visuel.visuel_mob[10] =  chargerPixelArt("lg_profild2.png");
    game->visuel.visuel_mob[11] =  chargerPixelArt("lg_profild3.png");

    game->perso.visuel = game->visuel.visuel_mvt[4];
}

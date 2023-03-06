#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <libTableauNoir.h>
#include "structure.h"
#include "entite.h"
#include "mob.h"

void creer_projectile(map_t * map, coord_t pos_i, int direction,int speed,int dmg, double range, Image visuel, int type, int rayon, int durete){
  map->projectile[map->nb_projectile] = (projectile_t){
    .pos = pos_i,
    .direct = direction,
    .dmg = dmg,
    .range = range,
    .speed = speed,
    .visuel = visuel,
    .type = type,
    .rayon_atk = rayon,
    .durete = durete
  };
    map->nb_projectile ++;
}

/*-----------------------------------------------------------------*/
/*projectile*/
void maj_projectile(map_t * map, game_t *game){
  for(int i = 0; i < map->nb_projectile; i++){
   
    if(map->projectile[i].range >= 0){
      if(map->projectile[i].direct == 1){
	map->projectile[i].pos.y =  map->projectile[i].pos.y +  map->projectile[i].speed*game->syst.dt;
      }
      if(map->projectile[i].direct == 2){
	map->projectile[i].pos.y =  map->projectile[i].pos.y -  map->projectile[i].speed*game->syst.dt;
      }
      if(map->projectile[i].direct == 3){
	map->projectile[i].pos.x =  map->projectile[i].pos.x -  map->projectile[i].speed*game->syst.dt;
      }
      if(map->projectile[i].direct == 4){
	map->projectile[i].pos.x =  map->projectile[i].pos.x +  map->projectile[i].speed*game->syst.dt;
      }     
      if(collision_mob(&map->projectile[i].pos, &map->projectile[i].pos, *game)){
	map->projectile[i].dmg = 0;
      }
      map->projectile[i].range = map->projectile[i].range - map->projectile[i].speed*game->syst.dt;
    }
    else{
      map->projectile[i].dmg = 0;
    }
    
    for(int j =0; j < map->nb_mob; j++){
      if(sqrt(pow(map->projectile[i].pos.x - map->mob[j].pos.x,2)+pow(map->projectile[i].pos.y - map->mob[j].pos.y,2)) < map->projectile[i].rayon_atk){
	if(!map->projectile[i].type){
	  if(game->map.mob[j].type == 1){
	    map->mob[j].hp = map->mob[j].hp - map->projectile[i].dmg;
	    map->projectile[i].dmg = 0;
	    map->mob[j].nb_hit = 1;
	    if(map->projectile[i].dmg){
	      map->mob[j].pos.v = map->mob[j].pos.v + 12;
	    }
	  }
	  if(game->map.mob[j].type == 2){
	    map->mob[j].hp = map->mob[j].hp - map->projectile[i].dmg;
	    map->projectile[i].dmg = 0;
	  }
	}
	else {
	  if(game->map.mob[j].type == 0){
	    if(map->mob[j].shield <= 0){
	      map->mob[j].hp = map->mob[j].hp - map->projectile[i].dmg;
	      map->mob[j].shield = 0.5;
	    }
	      map->projectile[i].dmg = 0;
	  }
	}
      }
    }
    if(sqrt(pow(map->projectile[i].pos.x,2)+pow(map->projectile[i].pos.y,2)) < map->projectile[i].rayon_atk){
      if(map->projectile[i].type){
	if(game->perso.shield <=0){
	  game->perso.hp = game->perso.hp - map->projectile[i].dmg;
	  game->perso.shield = 1.2;
	}
	map->projectile[i].dmg = 0;
      }
    }
    if(map->projectile[i].durete){
      if(map->projectile[i].range <= 0){
	map->projectile[i] = map->projectile[map->nb_projectile-1];
	map->nb_projectile --;
      }
    }
    else if(map->projectile[i].dmg == 0){
      map->projectile[i] = map->projectile[map->nb_projectile-1];
      map->nb_projectile --;
    }
  }
}

void creer_item(map_t * map, coord_t pos, int type, Image image, int nb){
  map->item[map->nb_item] = (item_t){
    .pos = pos,
    .type = type,
    .visuel = image,
    .nb = nb
  };
    map->nb_item ++;
}

void maj_item(game_t * game){
  for(int i =0; i < game->map.nb_item; i++){
    if(game->map.item[i].type == 1){
      if(sqrt(pow(game->map.item[i].pos.x,2)+pow(game->map.item[i].pos.y,2))<20){
	game->stat.or = game->stat.or + game->map.item[i].nb;
	game->map.item[i] = game->map.item[game->map.nb_item-1];
	game->map.nb_item --;
      }
    }
  }

}

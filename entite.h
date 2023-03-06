#ifndef ENTITE_H
#define ENTITE_H

void creer_projectile(map_t *, coord_t, int,int, int, double, Image, int, int, int); /*crée un projectile avec les caractéristiques correspondant à celles passées en paramètre*/
void maj_projectile(map_t *, game_t *);/*Met à jour l'état de chaque projectile se trouvant sur la map*/
void creer_item(map_t *, coord_t, int, Image, int); /*Crée un item qui ne bouge pas sur la map*/
void maj_item(game_t *game); /*Met à jour l'item s'il y a eu des interactions entre temps avec des entités ou joueur*/
#endif

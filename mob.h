#ifndef MOB_H
#define MOB_H


void zombie(mob_t *, game_t*);/*Fonction qui gère un zombie de type mob_t, elle permet de réaliser 2 situations: le déplacement et le visuel du zombie quand il est en mode attaque et quand il ne l'est pas */
void ghost(mob_t * ,game_t *);/*Fonction presque identique au précédent, à un détail près, le déplacement et le visuel du ghost est différent quand il est en mode attaque*/
void mvt_mob(mob_t *, game_t);/*Contrôler le déplacement d'un mob aléatoirement*/
void mob_visuel(mob_t *, Image[], int, game_t);/*Gére le visuel du mob */
int collision_mob(coord_t *, coord_t *, game_t);/*Vérifie si la prochaine position calculée à partir de l'actuelle est dans un bloc de collision ou non, non = 0 sinn renvoit le numéro du type de block
de collision, nombre compris entre 1 et 5 inclus*/
void maj_mort_mob(game_t *);/*Vérifie quels mobs dont le hp <= 0, et gère le nombre de mob sur la map*/
void creer_mob(map_t *, coord_t, double, double, Image, int, int, int);/*crée un mob avec les caractèristiques correspondant à celles passées en paramètre*/
void maj_mob(game_t * );/*fait appel aux différents fonctions concernant les mobs*/
void mob(mob_t *,game_t *);/*Gère le déplacement et le visuel des mob quand ils sont en mode attaque ou non*/
#endif

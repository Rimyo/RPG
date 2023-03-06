#ifndef DETECTION_H
#define DETECTION_H



void detect_att(game_t *);  /*Vérifie si le joueur a appuyé sur une des touches permettant d'attaquer*/
int detect_traj(coord_t, coord_t, game_t); /*Vérifie si il y a présence ou non d'un block de collision entre 2 points, oui = 1  non = 0   */
int detect_entite(double, int, coord_t,coord_t, int, game_t); /*Vérifie si un point sur la map est dans le champ de vision du monstre, càd direction, angle et distance, oui = 0 non =1*/
int detect(EtatSourisClavier, game_t *); /*Vérifie quelle touche directionnelle a été appuyé*/
void path_finder(mob_t *, game_t *); /*Permet à un mob de trouver un chemin pour aller à un point*/
#endif

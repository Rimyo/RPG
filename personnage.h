#ifndef PERSONNAGE_H
#define PERSONNAGE_H


void image_base(game_t *game);/*rend l'animation du déplacement plus fluide*/
void attaque(game_t *game);/*fonction genère les attaques dépendant du personnage*/
void afficher(game_t game);/*fonction qui gère l'affichage de toutes les images qui se trouvent dans la fenêtre hormis ceux du menu*/
void  mvt(game_t * game);/*Gère le déplacement du personnage par rapport aux touches appuyées et les collisions*/
int collision(game_t * game);/*Vérifie si la prochaine position du personnage se trouve dans un block de collision, si non alors 0, sinon renvoit le numéro du type de block de collision*/
void visuel(int direct, Image image[],Image * visuel, int frame );/*Gère le visuel du personnage par rapport à la direction dans laquelle il se déplace*/
void frame_calc(game_t *game);/*gènère des nombres grâce à une fonction cosinus pour avoir un mouvement de déplacement des entités fluide*/
void ordre_image(t_image * t_image);/*trie les images par rapport à leur position y sur la map, par valeur décroissante */


#endif

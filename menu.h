#ifndef MENU_H
#define MENU_H

void transition1(Image[]);/*Petite animation de transition */
void animation_deb(); /*Affichage du jeu au début de sa lancement*/
void selection(game_t *);/*les fonctions selection permettent au joueur de choisir la map et son personnage*/
void selection_mode(game_t *);
void selection_perso(game_t *);
void store(game_t *);
void fin(game_t);/*image de fin de jeu + libération des images*/

#endif

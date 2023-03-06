# RPG

Ce projet est un jeu RPG (role player game), le joueur incarne un personnage dans le jeu et doit parvenir à tuer tous les monstres (Mode Histoire qui ne comporte qu'un niveau ^^") ou survivre le plus longtemps possible dans dans la map (Mode Survie).

Le joueur a le choix entre 2 personnages, chacun avec des attaques et compétences différentes, le personnage Rim permet d'attaquer de loin les monstres avec des projetiles et peut invoquer des golems de glace pour lui venir en secours! Le personnage Riku est un loup-garou, ses attaques sont à distance réduite mais inflige plus de dégât, sa compétence lui permet de se transformer en loup-garou pendant une période, ses dégâts, vitesse de déplacement et point de vie se voient augmenter!
Il existe pour l'instant 2 types de monstres : zombies et fantôme, la façon d'attaquer des 2 monstres différe 
ainsi que leur statistiques : point de vie, vitesse de déplacement... 

Le zombie a un mécanisme de détection de joueur, il n'attaque que le joueur dans 2 cas précis : le joueur est dans le champ de vision du zombie ( définit par une direction et une distance), c'est-à-dire, aucun obstacle entre le zombie et le joueur, le joueur se tient dans la direction où le zombie regarde et il est dans la range de vision, OU encore, le joueur attaque le zombie, dans ce cas peu importe si le joueur attaque le zombie de dos, le zombie se retournera et tentera de dévorer le joueur. Quand le zombie pourchassera le joueur, sa vitesse de déplacement est augmentée!

Le fantôme ne se trouve que dans la salle du mode Histoire, quand il remarque le joueur, il lui fonce dessus pour affliger des dégâts, et il rebondit sur les murs au maximum 3 fois, en augmentant sa vitesse de déplacement à chaque rebond!

Le jeu se joue uniquement sur le clavier, les touches de mouvement sont z,q,s et d, et les touches 
d'attaques sont : j = attaque de base, k = sort, le temps de rechargement des attaques dépend du type 
et du personnage.

Pour exécuter le programme, il faut entrer dans le terminal : "make"
ensuite pour lancer le jeu, il suffit juste d'entrer "./rpg.exe".
![image](https://user-images.githubusercontent.com/97539604/223269912-3501868e-f6f7-4049-aeda-c43b07eff674.png)
![image](https://user-images.githubusercontent.com/97539604/223275665-6b340033-c640-4f65-b8d0-769e383d6540.png)
![image](https://user-images.githubusercontent.com/97539604/223275801-2376f188-efa5-45fd-98d4-98f1be9defe2.png)
![image](https://user-images.githubusercontent.com/97539604/223276324-12d23f13-1d04-4184-b77d-20bb81ae1d59.png)
![image](https://user-images.githubusercontent.com/97539604/223277151-da57fe37-0acc-4345-a071-31c00d6b03ae.png)
![image](https://user-images.githubusercontent.com/97539604/223277311-92b640c6-2d97-4498-859b-6b4d11e40bfb.png)


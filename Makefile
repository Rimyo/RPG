
rpg.exe: rpg.o structure.o init.o mob.o detection.o entite.o menu.o personnage.o
	gcc -o rpg.exe structure.o init.o rpg.o mob.o detection.o entite.o menu.o personnage.o -lTableauNoir -lm -Wall

structure.o: structure.c
	gcc -o structure.o -c structure.c -lTableauNoir -lm -Wall

init.o: init.c structure.h
	gcc -o init.o -c init.c -lTableauNoir -lm -Wall

rpg.o: rpg.c structure.h init.h mob.h entite.h
	gcc -o rpg.o -c rpg.c -lTableauNoir -lm -Wall

mob.o : mob.c structure.h detection.h entite.h
	gcc -o mob.o -c mob.c  -lTableauNoir -lm -Wall

detection.o : detection.c structure.h mob.h 
	gcc -o detection.o -c detection.c -lTableauNoir -lm -Wall

entite.o : entite.c structure.h mob.h
	gcc -o entite.o -c entite.c -lTableauNoir -lm -Wall

menu.o : menu.c structure.h init.h
	gcc -o menu.o -c menu.c -lTableauNoir -lm -Wall

personnage.o : personnage.c structure.h entite.h mob.h detection.h
	gcc -o personnage.o -c personnage.c -lTableauNoir -lm -Wall

clean:
	rm -rf *.o

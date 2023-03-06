#ifndef STRUCTURE_H 
#define STRUCTURE_H
/*x,y position dans la fenêtre, v = vitesse */
typedef struct {
  double x;
  double y;
  double v;} coord_t;

/*image et position*/
typedef struct {
  Image image;
  coord_t pos;}struct_t;

typedef struct {
  Image visuel;
  coord_t pos;
  int type;
  int nb;} item_t;

typedef struct {
  Image image[100];
  coord_t pos[100];
  int nb;} t_image;

typedef struct {
  Image visuel;
  coord_t pos;
  int dmg;
  int speed;
  int direct;
  double range;
  int type;
  int rayon_atk;
  int durete;} projectile_t;

typedef struct {
  coord_t pos;
  coord_t pos_f;
  coord_t vect;
  double range_att;
  double AS;
  double AS_ref;
  int nb_hit;
  double tps_move;
  int direct;
  Image visuel_actif;
  int visible;
  int dmg;
  int hp;
  int type;
  double shield;}mob_t;

typedef struct {
  coord_t pos;
  Image visuel;
  int basic;
  int spell;
  double spell_cd;
  double spell_cd_ref;
  double AS;
  double AS_ref;
  int direct;
  int dmg;
  double range;
  int rayon_atk;
  int type;
  int hp;
  double tps_spell;
  double shield;} perso_t;

typedef struct {
  int hp;
  int dmg;
  double speed;
  double AS;
  double range_atk;
  int or;
} stat_t;

typedef struct {
  int interaction[100][100];
  Image map_visuel;
  coord_t pos;
  coord_t pos_f;
  struct_t struct_o[7];
  Image map_calque;
  projectile_t projectile[120];
  item_t item[100];
  mob_t mob[60];
  int nb_item;
  int nb_projectile;
  int nb_struct;
  int nb_mob;} map_t;

typedef struct {
  int tick;
  int end;
  double temps;
  double dt;
  int frame;
  int frame_p;
  double temps_p;
  int personnage;
  int nb_map;} syst_t;

typedef struct {
  Image visuel_mvt[12];
  Image visuel_atk[4];
  Image visuel_pro[5];
  Image visuel_item[2];
  Image visuel_mob[12];} visuel_t;

typedef struct {
  Image ghost[24];
  Image zombie[12];} visuel_mob;

typedef struct {
  perso_t perso;
  map_t map;
  syst_t syst;
  visuel_t visuel;
  visuel_mob visuel_mob;
  stat_t stat;} game_t;



#endif

#ifndef _Projet_H
#define _Projet_H

/*----------------------------------------DEFINE STRUCT----------------------------------------------*/

/* Structure pour représenter la map */
struct map {
 int width;
 int height;
 char **data;
 int nb_objets;
 int nb_monstres;
 int nb_rochers; 
};

/* Structure pour représenter Rahan */
struct rahan {
 int PV;
 int x;
 int y;
 int speed;
 int sante;
 int force;
 struct objet *equipement[3]; 
};


struct objet {
 char * description;
 char stat;
 int valeur;
 char * classe;

};

struct monstre {
 char * nom;
 int force;
 int vie;
};





/*---------------------------------------------------------------------------------------------------*/
/*----------------------------------------APPEL FONCTIONS--------------------------------------------*/
/*rahan.c*/
void move_rahan(struct rahan *rahan, struct map *map, char direction, struct objet *liste_objets[], struct monstre *liste_monstres[]); 
/*carte.c*/
void demiurge(struct map *map,int nb_objets,int nb_monstres, int nb_rochers);
struct map *init_map(int width, int height,int nb_objets,int nb_monstres,int nb_rochers);
void free_map(struct map *map);
void display_map(struct map *map, struct rahan *rahan);


/*---------------------------------------------------------------------------------------------------*/

#endif

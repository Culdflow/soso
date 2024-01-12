#include <stdlib.h>
#include <stdio.h>
#include "stdprof.h"
#include "projet.h"

/* Fonction principale */
int main() {
 char direction;
 int x, m;


/*----------------------------------------------------*/
 
  struct objet *liste_equipement[3];
 

 liste_equipement[0]= stdprof_malloc(sizeof(struct objet));
 liste_equipement[0]->description = "Rien";
 liste_equipement[0]->stat = 'F';
 liste_equipement[0]->valeur = 0;
 liste_equipement[0]->classe = "armes";
  
 liste_equipement[1]= stdprof_malloc(sizeof(struct objet));
 liste_equipement[1]->description = "Rien";
 liste_equipement[1]->stat = 'P';
 liste_equipement[1]->valeur = 0;
 liste_equipement[1]->classe = "protections";
  
 liste_equipement[2]= stdprof_malloc(sizeof(struct objet));
 liste_equipement[2]->description = "Rien";
 liste_equipement[2]->stat = 'V';
 liste_equipement[2]->valeur = 0;
 liste_equipement[2]->classe = "chaussures"; 


 /* ------------------------Initialise les objets --------------------------------------*/
  struct objet *liste_objets[3];
 

 liste_objets[0]= stdprof_malloc(sizeof(struct objet));
 liste_objets[0]->description = "Un couteau tranchant";
 liste_objets[0]->stat = 'F';
 liste_objets[0]->valeur = 250;
 liste_objets[0]->classe = "armes";
  
 liste_objets[1]= stdprof_malloc(sizeof(struct objet));
 liste_objets[1]->description = "Un poison pas très efficace";
 liste_objets[1]->stat = 'F';
 liste_objets[1]->valeur = 5;
 liste_objets[1]->classe = "armes";
  
 liste_objets[2]= stdprof_malloc(sizeof(struct objet));
 liste_objets[2]->description = "Une botte de vitesse améliorée";
 liste_objets[2]->stat = 'V';
 liste_objets[2]->valeur = 1;
 liste_objets[2]->classe = "chaussures"; 

/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
                   /* Initialise les monstres */

struct monstre *liste_monstres[3];

 liste_monstres[0]= stdprof_malloc(sizeof(struct monstre));
 liste_monstres[0]->nom = "Crapaud sacré";
 liste_monstres[0]->force = 30;
 liste_monstres[0]->vie = 200;

 liste_monstres[1]= stdprof_malloc(sizeof(struct monstre));
 liste_monstres[1]->nom = "Loup des bois";
 liste_monstres[1]->force = 30;
 liste_monstres[1]->vie = 200;

 liste_monstres[2]= stdprof_malloc(sizeof(struct monstre));
 liste_monstres[2]->nom = "Arbre humain";
 liste_monstres[2]->force = 30;
 liste_monstres[2]->vie = 200;




/*----------------------------------------------------------------------------*/

 /* Initialise la map */
 struct map *map = init_map(30, 20,5,3,5);

 /* Génère les entités */
 /*demiurge(map); */

 /* Initialise Rahan */
 struct rahan *rahan = malloc(sizeof(struct rahan));
 rahan->PV = 50;
 rahan->sante = 50;
 rahan->x = 6;
 rahan->y = 6;
 rahan->speed = 1;
 rahan->force = 100;
 int i;
 for(i=0;i<3;i++){
 rahan->equipement[i] = liste_equipement[i];} 


 /* Boucle de jeu */
 while (rahan->sante>0) {
 /* Affiche la map */
 display_map(map,rahan);

 /* Lit une commande */
 printf("*------------------------------------*\n");
 printf("Entrez une commande (H, B, G, D, E) : ");
 scanf(" %c", &direction);
 system("clear");
 if (direction == 'E')
 {
    printf("rahan possede\n");
    for (m = 0; m < 3; m++)
    {
      printf("%s : %s qui a une valeur de %d\n", rahan->equipement[m]->classe, rahan->equipement[m]->description, rahan->equipement[m]->valeur);
    }
 }
 else move_rahan(rahan,map,direction,liste_objets,liste_monstres);
 

 /* Déplace Rahan */

 /* Vérifie si Rahan est à une frontière */
 if (rahan->x == 0 || rahan->x >= map->width - 1 || rahan->y <= 0 || rahan->y >= map->height - 1) {
  printf("Rahan est à une frontière !\n");
 }
}

printf("RAHAN EST MORT !!!\n");


 /* Libère la mémoire allouée */
 free_map(map);
 free(rahan);
 for (x = 0; x < 3; x++)
 {
    stdprof_free(liste_objets[x]);
    stdprof_free(liste_monstres[x]);
    stdprof_free(liste_equipement[x]);
 }

 return 0;
}

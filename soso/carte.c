#include <stdio.h>
#include <stdlib.h>
#include "projet.h"
#include "stdprof.h"






/*---------------------------------------------------------------------------------*/
void demiurge(struct map *map,int nb_objets,int nb_monstres, int nb_rochers) {
 int i;
 for (i = 0; i < nb_objets; i++) {
  int x = rand() % map->width;
  int y = rand() % map->height;
  map->data[x][y] = '!'; /* objet */
 }

 /* Génère les monstres */
 for (i = 0; i < nb_monstres; i++) {
  int x = rand() % map->width;
  int y = rand() % map->height;
  while (map->data[x][y] != ' ') {
   x = rand() % map->width;
   y = rand() % map->height;
  }
  map->data[x][y] = '@'; /* Monstre */
 }

 /* Génère les rochers */
 for (i = 0; i < nb_rochers; i++) {
  int x = rand() % map->width;
  int y = rand() % map->height;
  while (map->data[x][y] != ' ') {
   x = rand() % map->width;
   y = rand() % map->height;
  }
  map->data[x][y] = '#'; /* Rocher */
 }
}


/*---------------------------------------------------------------------------------*/


/* Fonction pour initialiser la map */
struct map *init_map(int width, int height,int nb_objets,int nb_monstres,int nb_rochers) {
  int i, j;
  
  struct map *map = stdprof_malloc(sizeof(struct map));
  map->width = width;
  map->height = height;
  map->data = stdprof_malloc(sizeof(char *) * width);

  for (i = 0; i < width; i++) {
    map->data[i] = stdprof_malloc(sizeof(char) * height);
    for (j = 0; j < height; j++) {
      if (i == 0 || i == width - 1 || j == 0 || j == height - 1) {
        map->data[i][j] = '"'; /* frontières */
      } else {
          map->data[i][j] = ' '; /* case vide */
        }
      }
    }
  

   
  demiurge(map,nb_objets,nb_monstres,nb_objets);
  
  return map;
  }



/* Fonction pour libérer la mémoire allouée à la map */
void free_map(struct map *map) {
 int i;
 for (i = 0; i < map->width; i++) {
  stdprof_free(map->data[i]);
 }
 stdprof_free(map->data);
 stdprof_free(map);
}

/* Fonction pour afficher la map */
void display_map(struct map *map, struct rahan *rahan) {
  int i, j; 
  char tuile;
  printf("\n");

  for (i = 0; i < map->height; i++) {
    for (j = 0; j < map->width; j++) {
      tuile = map->data[j][i];


      /* Affiche la case */
      if (i == rahan->y && j == rahan->x){
      	printf("R");
      }else{
      printf("%c", tuile);}


    }
    printf("\n");
  }
}













#include <stdlib.h>
#include <stdio.h>
#include "stdprof.h"
#include "projet.h"


void move_rahan(struct rahan *rahan, struct map *map, char direction, struct objet *liste_objets[], struct monstre *liste_monstres[]) {
    char tuile;
    struct objet *o;
    struct monstre *monstre;
    int index;

    int new_x = rahan->x;
    int new_y = rahan->y;

    switch (direction) {
    case 'H':
        new_y = new_y - rahan->speed;
        break;
    case 'B':
        new_y = new_y + rahan->speed;
        break;
    case 'G':
        new_x = new_x - rahan->speed;
        break;
    case 'D':
        new_x = new_x + rahan->speed;
        break;
    }

    /* Vérifie si la case est accessible */
    if (new_x <= 0 || new_x >= map->width-1 || new_y <= 0 || new_y >= map->height-1) {
        printf("Rahan ne peut pas dépasser la limite de la carte ! \n");
        return;
    }

    /* Vérifie si la case contient un objet */
    tuile = map->data[new_x][new_y];
    
    index = rand() % 3;
    
    if (tuile == '!') {
    
    	printf("--------objet-récupéré-------\n");
    	o = liste_objets[index];
    	printf("%s \n",o->description);
    	
    	
    	
    	
    	
    	if (o->stat == 'F'){
    		if (o->valeur > rahan->equipement[0]->valeur){
    		rahan->equipement[0] = o;
    		rahan->force =  o->valeur + 50;
    		printf("La Force de Rahan augmente de %d \n",o->valeur); } else printf("Rahan choisis de ne pas le ramasser\n");
    	}else if (o->stat == 'V'){
    		if (o->valeur > rahan->equipement[2]->valeur){
    		rahan->equipement[2] = o;
    		rahan->speed =  o->valeur+1;
    		printf("La Vitesse de Rahan augmente de %d \n",o->valeur);} else printf("Rahan choisis de ne pas le ramasser\n");
    	} else { 
    		if (o->valeur > rahan->equipement[1]->valeur) {
    		rahan->equipement[1] = o;
    		rahan->sante = (rahan->sante + o->valeur);
    		printf("La Sante de Rahan augmente de %d \n",o->valeur);} else printf("Rahan choisis de ne pas le ramasser\n");
    	} 
    printf("------------------------------\n");
    }

    if (tuile == '@') {
      printf("VOUS VENEZ DE RENCONTRER UN MONSTRE !!!! \n");
    	monstre = liste_monstres[index];
    	printf("C'est un %s !!!!!!!!\n",monstre->nom);
    	printf("---------COMBAT-------------\n");
    	
    	while (rahan->sante > 0 && monstre->vie > 0){
    		
    		
    		printf("Rahan attaque %s et lui fait %d dégats !\n",monstre->nom,rahan->force);
    		monstre->vie = monstre->vie - rahan->force;
    		
    		if (monstre->vie >0){
    			printf("%s attaque Rahan et lui fait %d dégats !\n",monstre->nom,monstre->force);
    			rahan->sante = rahan->sante - monstre->force;
    		}
    	
    	
    	
    	
    	}
    	printf("----------FIN-DU-COMBAT-----------\n");
    	if (monstre->vie <=0){
    	printf("***RAHAN A BATTU LE MONSTRE***\n");
    	}
 
    	} 
    
    
    
    
    if (tuile =='#') {
    	printf("Vous ne pouvez pas marcher sur un Rocher ! \n");
    	return;}






    /* Déplace Rahan */
    map->data[rahan->x][rahan->y] = ' ';
    rahan->x = new_x;
    rahan->y = new_y;
    
}

#include <stdint.h>
#include <stdio.h>
#include "arbre.h"
#include <stdlib.h>

uint32_t compte = 0;
/////////////////////////////////////////////////////////////////////////////////////////////////
	void creerFeuille(struct noeud * arbre[256], uint32_t tab[256])
	{
		for(uint32_t i=0;i<256;i++) //parcourir le tableau
		{
			if (tab[i] != 0) //verifier si le est utiliser
			{
				arbre[compte]= malloc(sizeof(struct noeud));
				arbre[compte]->c = i;
				arbre[compte]->occurence = tab[i];
				arbre[compte]->code = 0;
				arbre[compte]->tailleCode = 0;
				arbre[compte]->droite = NULL;
				arbre[compte]->gauche = NULL;

				compte++;
			}
		}
	}
/////////////////////////////////////////////////////////////////////////////////////////////////
	uint32_t comptage_de_caracteres_total(uint8_t* chaine)
	{
		uint32_t compteur=0;
		uint32_t j=0;
		while(*(chaine+j) !='\0')
		{
			compteur++;
			j++;
		}
	return compteur;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////
	void afficherTabArbreHuffman(struct noeud* arbre[256] , uint32_t taille)
	{

		for(uint32_t i=0;i<taille;i++)
		{
			printf("le caractere initial est %c \r\n",arbre[i]->c);
			printf("le nombre d'occurences est %d \r\n",arbre[i]->occurence);
			printf("le code binaire dans l'arbre est %x \r\n",arbre[i]->code);
			printf("le nombre de bits du code est %d \r\n",arbre[i]->tailleCode);
			printf("\n");
		}
	}
//////////////////////////////////////////////////////////////////////////////////////////////////
	/*uint32_t comptage_de_caracteres_utiliser(uint32_t tab[256])
	{
		uint32_t compteur=0;
		for(uint32_t j=0;j<256;j++)
				{
					if (tab[j] != 0)
					{
					compteur++;
					}
				}
	return compteur;
	}*/
//////////////////////////////////////////////////////////////////////////////////////////////////
	void trieArbre(struct noeud* arbre[256] , uint32_t taille)
	{
		struct noeud* temp;


		    for (uint32_t i = 0; i < taille - 1; i++)
		    {
		        for (uint32_t j = 0; j < taille - i - 1; j++)
		        {
		            if (arbre[j]->occurence > arbre[j + 1]->occurence)
		            {
		                // Échange des éléments
		                temp = arbre[j];
		                arbre[j] = arbre[j + 1];
		                arbre[j + 1] = temp;
		            }
		        }
		    }
	}
//////////////////////////////////////////////////////////////////////////////////////////////////
	struct noeud* creeRacine( struct noeud * arbre[256], uint32_t taille)
	{
		struct noeud* racine_a_cree ;



		for (uint32_t i=1 ; i < taille ; i++)
		{
			//trieArbre(arbre , taille);

			racine_a_cree = malloc(sizeof(struct noeud));
			racine_a_cree->c= '!';
			racine_a_cree->occurence = arbre[i-1]->occurence + arbre[i]->occurence ;
			racine_a_cree->code = 0;
			racine_a_cree->tailleCode =0;
			racine_a_cree->droite = arbre[i] ;
			racine_a_cree->gauche = arbre[i-1] ;
			arbre[i]=racine_a_cree ;
		}
		return racine_a_cree ;
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////
	void afficherRacine(struct noeud* la_racine)
	{
		printf("affichege de la racine \r\n");
		printf("\n");

		printf("le caractere initial de la racine est %c \r\n",la_racine->c);
		printf("le nombre d'occurences de la recine est %d \r\n",la_racine->occurence);
		//printf("le code binaire dans l'arbre est %x \r\n",la_racine->code);
		//printf("le nombre de bits du code est %d \r\n",la_racine->tailleCode);
		printf("\r\n");
		printf("le caractere droit est %c \r\n",la_racine->droite->c);
		printf("son nombre d'ocurence est  %c \r\n",la_racine->droite->occurence);

		printf("le caractere gauche est %c \r\n",la_racine->gauche->c);
		printf("son nombre d'ocurence est  %c \r\n",la_racine->gauche->occurence);

		printf("\r\n");
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////
	void parcourirArbre(struct noeud* ptrNoeud)
	{
		if (ptrNoeud->droite == NULL && ptrNoeud->gauche == NULL)
		{
			printf("Je suis une feuille\r\n");
			printf("mon caractere initial est %c \r\n",ptrNoeud->c);
			printf("mon nombre d'occurences est %d \r\n",ptrNoeud->occurence);
			printf("\r\n");
		}

		else
		{
			printf("Je suis un nœud\r\n");
			//afficher le noeud
			printf("mon caractere initial est %c mon nombre d'occurences est %d \r\n",ptrNoeud->c ,ptrNoeud->occurence );
			// afficher gauche et droit du noeud
			printf("mon caractere initial droit est %c son nombre d'occurences est %d \r\n",ptrNoeud->droite->c ,ptrNoeud->droite->occurence);
			printf("mon caractere initial gauche est %c son nombre d'occurences est %d \r\n",ptrNoeud->gauche->c ,ptrNoeud->gauche->occurence);
			printf("---------------------\r\n");

			parcourirArbre (ptrNoeud->gauche); // On va a gauche
			parcourirArbre (ptrNoeud->droite); //On va a droite


		}
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////
	void afficherFeuilles(struct noeud* arbre[256] ,uint32_t taille)
	{
	    printf("Feuilles de l'arbre de Huffman :\r\n");
	    printf("Caractere\tOccurrences\tCode\t\tTaille Code\r\n");
	    printf("___________________________________________________________\r\n\n");

	    for (int i = 0; i < taille; i++)
	    {
	    	printf("%c\t\t%d\t\t%x\t\t%d\r\n",
	            arbre[i]->c,
	            arbre[i]->occurence,
				arbre[i]->code,
				arbre[i]->tailleCode);

	    }
	    printf("___________________________________________________________\r\n");
	    printf("\r\n");
	}
////////////////////////////////////////////////////////////////////////////////////////////////////////////:
	void LiberationMemoireArbre(struct noeud* ptrNoeud)
	{
	    if (ptrNoeud == NULL) {
	        return;
	    }
	    LiberationMemoireArbre(ptrNoeud->gauche);
	    LiberationMemoireArbre(ptrNoeud->droite);
	    free(ptrNoeud);
	}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void creerCode(struct noeud* ptrNoeud, uint32_t code, uint32_t taille) {
	    if (ptrNoeud == NULL) {
	        return;
	    }
	    if (ptrNoeud->gauche == NULL && ptrNoeud->droite == NULL) {
	        ptrNoeud->tailleCode = taille;
	        ptrNoeud->code = code;
	        printf("Caractere : '%c' \t Code : ", ptrNoeud->c);
	        for (int i = taille - 1; i >= 0; i--) {
	            printf("%d", (code >> i) & 1);
	        }
	        printf(" \t Taille : %d bits\r\n", taille);
	    } else {
	        creerCode(ptrNoeud->gauche, code << 1, taille + 1); // on inject 0
	        creerCode(ptrNoeud->droite, (code << 1) + 1, taille + 1); // on inject 1
	    }
	}
////////////////////////////////////////////////////////////////////////////////////////////////







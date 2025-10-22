#include <stdint.h>
#include <stdio.h>
#include "arbre.h"
#include <stdlib.h>

uint32_t compte = 0;
/////////////////////////////////////////////////////////////////////////////////////////////////
	void creerFeuille(struct noeud * arbre[256], uint32_t tab[256])
	{


		for(uint32_t i=0;i<256;i++)
		{
			if (tab[i] != 0)
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
	struct noeud* creeRacine(struct noeud * arbre[256], uint32_t taille)
	{
		struct noeud* racine;

		for (uint32_t i=1 ; i < taille ; i++)
		{
			racine = arbre[i] ;

			racine->c= '!';
			racine->occurence = arbre[i-1]->occurence + arbre[i]->occurence ;
			racine->code = 0;
			racine->tailleCode =0;
			racine->droite = arbre[i] ;
			racine->gauche = arbre[i-1] ;
		}
		return racine;
	}

///////////////////////////////////////////////////////////////////////////////////////////////////////
	void afficherRacine(struct noeud* laracine)
	{
		printf("affichege de la racine \r\n");
		printf("\n");

		printf("le caractere initial est %c \r\n",laracine->c);
		printf("le nombre d'occurences est %d \r\n",laracine->occurence);
		printf("le code binaire dans l'arbre est %x \r\n",laracine->code);
		printf("le nombre de bits du code est %d \r\n",laracine->tailleCode);
		printf("le caractere droit est %c \r\n",laracine->droite->c);
		printf("le caractere gauche est %c \r\n",laracine->gauche->c);

		printf("\n");
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////

	void parcourirArbre(struct noeud* ptrNoeud)
	{
		uint32_t test=0;

		if (ptrNoeud->droite == NULL && ptrNoeud->gauche == NULL)
		{
			printf("Je suis une feuille\r\n");
			printf("mon caractere initial est %c \r\n",ptrNoeud->c);
			printf("mon nombre d'occurences est %d \r\n",ptrNoeud->occurence);
		}

		else
		{
			printf("Je suis un nœud\r\n");
			//afficher le noeud
			printf("mon caractere initial est %c \r\n",ptrNoeud->c);
			printf("mon nombre d'occurences est %d \r\n",ptrNoeud->occurence);
			printf("\r\n");
			// afficher gauche et droit du noeud
			printf("mon caractere initial droit est %c \r\n",ptrNoeud->droite->c);
			printf("son nombre d'occurences est %d \r\n",ptrNoeud->droite->occurence);
			printf("\r\n");
			printf("mon caractere initial gauche est %c \r\n",ptrNoeud->gauche->c);
			printf("son nombre d'occurences est %d \r\n",ptrNoeud->gauche->occurence);


			if(test % 2 == 0)
			{
				parcourirArbre (ptrNoeud->gauche); // On va a gauche
				test++;
			}
			else
			{
				parcourirArbre (ptrNoeud->droite); //On va a droite
			}
		}
		test=0;
	}












#ifndef ARBRE_H_
#define ARBRE_H_

struct noeud{
	uint8_t c;                      //carac initial
	uint32_t occurence;             //nbr d occurences
	uint32_t code;                  //code binaire dans l'arbre
	uint32_t tailleCode;            //nbr de bits du code
	struct noeud *gauche, *droite;  //liens vers les noeud suivants
};

void creerFeuille(struct noeud * arbre[256], uint32_t tab[256]);
void afficherTabArbreHuffman(struct noeud* arbre[256] , uint32_t taille);
uint32_t comptage_de_caracteres_total(uint8_t* chaine);
//uint32_t comptage_de_caracteres_utiliser(uint32_t tab[256]);
void trieArbre(struct noeud* arbre[256] , uint32_t taille);
struct noeud* creeRacine(struct noeud * arbre[256], uint32_t taille);
void afficherRacine(struct noeud* arbre[256] , uint32_t taille);

#endif

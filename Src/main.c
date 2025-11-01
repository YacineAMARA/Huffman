#include <stdint.h>
#include <stm32f446xx.h>
#include <stdio.h>
#include "main.h"
#include "gpio.h"
#include "usart.h"
#include "timer.h"
#include "util.h"

#include "occurence.h"
#include "arbre.h"


int main(void)
{
	FPU_Init();
	GPIO_Init();
	USART2_Init();
	SYSTICK_Init();

	uint8_t texte[]="aaaabbbccd";
	//aaaaabbbbbccccccccddddddddd exemple ou il faut retrier a chaque fois
	uint32_t tabCaractere [256]={0};
	struct noeud* arbreHuffman[256];
	//uint32_t nbrCaractereDifferent=0;
	//uint32_t nbrCaractereTotal=0;
	extern uint32_t compte ; //pour la taille de l'arbre
	struct noeud* racine;



	occurence(texte , tabCaractere);

	creerFeuille(arbreHuffman,tabCaractere);
	afficherFeuilles(arbreHuffman, compte);

	trieArbre(arbreHuffman, compte);
	/*printf("tableau de huffman apres trie\r\n");
	afficherTabArbreHuffman(arbreHuffman , compte);
	printf("//////////////////\r\n");
	*/

	racine = creeRacine(arbreHuffman , compte);

	parcourirArbre(racine);

	LiberationMemoireArbre(racine);

	printf("Codes de Huffman pour chaque caractere :\r\n");
	creerCode(racine, 1, 0);


	while(1){
		SYSTICK_Delay(100);
		GPIOA->ODR ^= 1<<5;
		//printf("Hello\r\n");
	}
}

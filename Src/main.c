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
	uint32_t tabCaractere [256]={0};
	struct noeud* arbreHuffman[256];
	//uint32_t nbrCaractereDifferent=0;
	//uint32_t nbrCaractereTotal=0;
	extern uint32_t compte ; //pour la taille de l'arbre
	struct noeud* racine;



	occurence(texte , tabCaractere);
	//nbrCaractereDifferent = comptage_de_caracteres_utiliser(tabCaractere);
	creerFeuille(arbreHuffman,tabCaractere);
	//printf("arbre non trier\r\n");
	//afficherTabArbreHuffman(arbreHuffman , compte);
//////////////////////////////////////////////////////////////////////////
	trieArbre(arbreHuffman, compte);
	printf("arbre trier\r\n");
	afficherTabArbreHuffman(arbreHuffman , compte);
/////////////////////////////////////////////////////////////////////////////////////


	racine = creeRacine(arbreHuffman , compte);
	printf("arbre apres creation de la racine \r\n");
	afficherTabArbreHuffman(arbreHuffman , compte);

	afficherRacine(racine);

	parcourirArbre(racine);



	while(1){
		SYSTICK_Delay(100);
		GPIOA->ODR ^= 1<<5;
		//printf("Hello\r\n");
	}
}

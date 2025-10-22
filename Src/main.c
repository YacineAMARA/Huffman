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

	uint8_t texte[]="Une banane";
	uint32_t tabCaractere [256]={0};
	struct noeud* arbreHuffman[256];
	//uint32_t nbrCaractereDifferent=0;
	//uint32_t nbrCaractereTotal=0;
	extern uint32_t compte ;
	struct noeud* racine;



	occurence(texte , tabCaractere);
	//nbrCaractereDifferent = comptage_de_caracteres_utiliser(tabCaractere);
	creerFeuille(arbreHuffman,tabCaractere);
	//nbrCaractereDifferent = compte; // la valeur de comte (la taille) est deffinie apres la creation
	printf("arbre non trier\r\n");
	afficherTabArbreHuffman(arbreHuffman , compte);
//////////////////////////////////////////////////////////////////////////
	trieArbre(arbreHuffman, compte);
	printf("arbre trier\r\n");
	afficherTabArbreHuffman(arbreHuffman , compte);
/////////////////////////////////////////////////////////////////////////////////////


	racine = creeRacine(arbreHuffman , compte);
	//trieArbre(arbreHuffman, compte);
	printf("arbre apres creation de la racine \r\n");
	afficherTabArbreHuffman(arbreHuffman , compte);
	printf("la racine est:  \r\n");
	afficherRacine(arbreHuffman , compte);



	while(1){
		SYSTICK_Delay(100);
		GPIOA->ODR ^= 1<<5;
		//printf("Hello\r\n");
	}
}

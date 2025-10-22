#include <stdint.h>
#include <stdio.h>
#include "occurence.h"

	void occurence(uint8_t* chaine , uint32_t tab[256])
	{
		uint32_t i=0;
		uint32_t c;
		while(*(chaine+i) !='\0')
		{
			c=chaine[i];
			tab[c]++;
			i++;
		}

		for(uint32_t j=0;j<256;j++)
		{
			if (tab[j] != 0)
			{
			printf("le nombre d'occurence de %c est %ld \r\n",j,tab[j]);
			}
		}
		printf("\n");
	}


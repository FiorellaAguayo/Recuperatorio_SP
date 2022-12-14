#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "Pokemon.h"

int parser_PokemonesDesdeTexto(FILE* pFile, LinkedList* pArrayListPokemon)
{
	int todoOk = 0;

	ePokemon* unPokemon;

	char auxNumero[30];
	char auxNombre[30];
	char auxTipo[30];
	char auxTamanio[30];
	char auxAtaqueCargado[30];
	char auxValorAtaque[30];
	char auxEsVarioColor[30];

	if(pFile != NULL && pArrayListPokemon != NULL)
	{
		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxNumero, auxNombre, auxTipo, auxTamanio, auxAtaqueCargado, auxValorAtaque, auxEsVarioColor);

			unPokemon = pokemon_newParametros(auxNumero, auxNombre, auxTipo, auxTamanio, auxAtaqueCargado, auxValorAtaque, auxEsVarioColor);

			ll_add(pArrayListPokemon, unPokemon);
		}
		todoOk = 1;
	}
	return todoOk;
}

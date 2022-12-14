#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"
#include "LinkedList.h"
#include "Pokemon.h"
#include "parser.h"
#include "inputs.h"

int controller_CargaDePokemonesDesdeTexto(char* path, LinkedList* pArrayListPokemon)
{
	int todoOk = 0;
	FILE* pFile;

	if(path != NULL && pArrayListPokemon != NULL)
	{
		pFile = fopen(path, "r");
		if(pFile == NULL)
		{
			return todoOk;
		}
		else
		{
			parser_PokemonesDesdeTexto(pFile, pArrayListPokemon);
			todoOk = 1;
		}
	}
	fclose(pFile);
	return todoOk;
}

int controller_ListarPokemones(LinkedList* pArrayListPokemon)
{
	int todoOk = 0;
	ePokemon* unPokemon;
	int tam;

	if(pArrayListPokemon != NULL)
	{
		tam = ll_len(pArrayListPokemon);
		if(tam > 0)
		{
			pokemon_mostrarEncabezado();
			for(int i = 0; i < tam; i++)
			{
				unPokemon = ll_get(pArrayListPokemon, i);
				pokemon_mostrarUnPokemon(unPokemon);
			}
		}
		printf("\n---------------------------------------------------------------------------------------------------------------");
		todoOk = 1;
	}
	return todoOk;
}

int controller_ModificarValorAtaque(LinkedList* pArrayListPokemon)
{
	int todoOk = 0;
	int numero;
	int indice;
	int valorAtaque;
	char confirmar;
	ePokemon* unPokemon;

	if(pArrayListPokemon != NULL)
	{
		controller_ListarPokemones(pArrayListPokemon);
		pedirEntero(&numero, "\nIngrese el numero del pokemon que desea modificar: ", "\nError. Ingresaste un numero no valido. Vuelva a ingresar: ", 1, 151);

		indice = buscarPokemonPorNumero(pArrayListPokemon, numero);

		if(indice == -1)
		{
			printf("\nNo hay pokemones con ese numero.\n");
		}
		else
		{
			unPokemon = ll_get(pArrayListPokemon, indice);
			pokemon_mostrarEncabezado();
			pokemon_mostrarUnPokemon(unPokemon);
			printf("\n---------------------------------------------------------------------------------------------------------------");

			pedirCaracter(&confirmar, "\n¿Desea modificar el valor de ataque de este pokemon? (s = si | n = no): ", "\nError. Ingresaste un caracter no valido. Vuelva a ingresar: ", 's', 'n');
			if(confirmar == 's')
			{
				pedirEntero(&valorAtaque, "\nIngrese el nuevo valor de ataque: ", "\nError. Ingresaste un valor no valido. Vuelva a ingresar: ", 1, 100);
				pokemon_setValorAtaque(unPokemon, valorAtaque);
				todoOk = 1;
			}
			else
			{
				printf("\nModificacion cancelada.\n");
			}
		}
	}
	return todoOk;
}

int buscarPokemonPorNumero(LinkedList* pArrayListPokemon, int numero)
{
	int numeroComparar;
	int tam;
	int indice = -1;
	ePokemon* unPokemon;

	if(pArrayListPokemon != NULL && numero > 0)
	{
		tam = ll_len(pArrayListPokemon);
		for(int i = 0; i < tam; i++)
		{
			unPokemon = ll_get(pArrayListPokemon, i);
			if(unPokemon != NULL)
			{
				pokemon_getNumero(unPokemon, &numeroComparar);
				if(numeroComparar == numero)
				{
					indice = i;
					break;
				}
			}
		}
	}
	return indice;
}

//La función “ll_filter” recibirá una lista y una función criterio “fn”. Se deberá iterar todos los elementos
//de la lista y pasarlos a la función “fn”. La función “fn” devolverá 1 si ese ítem se debe agregar a la
//lista resultado o 0 si no debe agregarse. La función “ll_filter” generará la nueva lista resultado,
//agregará a la misma los ítems correspondientes y la devolverá.

int controller_Filtrado_Tipo(LinkedList* pArrayListPokemon)
{
	int todoOk = 0;
	LinkedList* auxLista;

	if(pArrayListPokemon != NULL)
	{
		auxLista = ll_filter(pArrayListPokemon, pokemon_FiltrarPorFuego);
		controller_cargarArchivo("filtradoFire.csv", auxLista);
		todoOk = 1;
	}

	return todoOk;
}

int controller_cargarArchivo(char* path, LinkedList* pArrayListPokemon)
{
	int todoOk = 0;
	FILE* pFile;
	ePokemon* unPokemon;

	int tam;

	int numero;
	char nombre[30];
	char tipo[30];
	char tamanio[30];
	char ataqueCargado[30];
	int valorAtaque;
	int esVarioColor;

	if(path != NULL && pArrayListPokemon != NULL)
	{
		pFile = fopen(path, "w");

		if(pFile == NULL)
		{
			printf("\nHubo al abrir el archivo.csv.\n");
		}
		else
		{
			unPokemon = pokemon_new();

			fprintf(pFile,"numero,nombre,tipo,tamanio,ataqueCargado,valorAtaque,esVariocolor");

			tam = ll_len(pArrayListPokemon);
			for(int i = 0; i < tam; i++)
			{
				unPokemon = (ePokemon*)ll_get(pArrayListPokemon, i);

				if(unPokemon != NULL)
				{
					pokemon_getNumero(unPokemon, &numero);
					pokemon_getNombre(unPokemon, nombre);
					pokemon_getTipo(unPokemon, tipo);
					pokemon_getTamanio(unPokemon, tamanio);
					pokemon_getAtaqueCargado(unPokemon, ataqueCargado);
					pokemon_getValorAtaque(unPokemon, &valorAtaque);
					pokemon_getEsVarioColor(unPokemon, &esVarioColor);

					fprintf(pFile, "\n%d,%s,%s,%s,%s,%d,%d", numero, nombre, tipo, tamanio, ataqueCargado, valorAtaque, esVarioColor);
					todoOk = 0;
				}
				else
				{
					break;
				}
			}
			printf("\nArchivo cargado con exito.\n");
			fclose(pFile);
		}
	}
    return todoOk;
}

int controller_Filtrado_ExtraGrande_TipoVeneno(LinkedList* pArrayListPokemon)
{
	int todoOk = 0;
	LinkedList* auxLista = NULL;

	if(pArrayListPokemon != NULL)
	{
		auxLista = ll_filter(pArrayListPokemon, pokemon_FiltrarExtraGrande_TipoVeneno);
	    controller_ListarPokemones(auxLista);
	    todoOk = 1;
	}

	return todoOk;
}

int controller_Mapear_AtaqueCargado(LinkedList* pArrayListPokemon)
{
	int todoOk = 0;

	if(pArrayListPokemon != NULL)
	{
		ll_map(pArrayListPokemon, pokemon_Mapeo);
		controller_ListarPokemones(pArrayListPokemon);
		todoOk = 1;
	}

	return todoOk;
}

int controller_batalla(LinkedList* pArrayListPokemon)
{
	int todoOk = 0;
	int contador = 0;

	if(pArrayListPokemon != NULL)
	{
		contador = ll_count(pArrayListPokemon, pokemon_validarPokemonesBatalla);
		if(contador >= 3)
		{
			printf("\n¡Felicidades, ganaste la batalla!");
		}
		else
		{
			printf("\n¡Oh no, perdiste la batalla!");
		}

		todoOk = 1;
	}
	return todoOk;
}

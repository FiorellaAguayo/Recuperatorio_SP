#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Pokemon.h"

ePokemon* pokemon_new()
{
	ePokemon* unPokemon = NULL;

	unPokemon = (ePokemon*) malloc(sizeof(ePokemon));

	if (unPokemon != NULL)
	{
		unPokemon->numero = 0;
		unPokemon->valorAtaque = 0;
		unPokemon->esVarioColor = 0;
		strcpy(unPokemon->nombre, " ");
		strcpy(unPokemon->tipo, " ");
		strcpy(unPokemon->tamanio, " ");
		strcpy(unPokemon->ataqueCargado, " ");
	}

	return unPokemon;
}

ePokemon* pokemon_newParametros(char *numeroStr, char *nombreStr, char *tipoStr, char *tamanioStr, char *ataqueCargadoStr, char *valorAtaqueStr,
		char *esVarioColorStr)
{
	ePokemon* unPokemon = NULL;

	unPokemon = pokemon_new();

	if (unPokemon != NULL)
	{
		if (( pokemon_setNumero(unPokemon, atoi(numeroStr))
			|| pokemon_setNombre(unPokemon, nombreStr)
			|| pokemon_setTipo(unPokemon, tipoStr)
			|| pokemon_setTamanio(unPokemon, tamanioStr)
			|| pokemon_setAtaqueCargado(unPokemon, ataqueCargadoStr)
			|| pokemon_setValorAtaque(unPokemon, atoi(valorAtaqueStr))
			|| pokemon_setEsVarioColor(unPokemon, atoi(esVarioColorStr))) != 0)
		{
			unPokemon = NULL;
			pokemon_delete(unPokemon);
		}
	}

	return unPokemon;
}

void pokemon_delete(ePokemon *this)
{
	if (this != NULL)
	{
		free(this);
	}
}

int pokemon_setNumero(ePokemon *this, int numero)
{
	int todoOk = -1;

	if (this != NULL && numero >= 0)
	{
		this->numero = numero;
		todoOk = 0;
	}
	else
	{
		printf("\nID invalido\n");
	}

	return todoOk;
}

int pokemon_getNumero(ePokemon *this, int *numero)
{
	int todoOk = -1;

	if (this != NULL && numero != NULL)
	{
		*numero = this->numero;
		todoOk = 0;
	}

	return todoOk;
}

int pokemon_setNombre(ePokemon *this, char *nombre)
{
	int todoOk = -1;

	if (this != NULL && nombre != NULL)
	{
		if (strlen(nombre) < 100 && strlen(nombre) > 1)
		{
			strcpy(this->nombre, nombre);
			strlwr(this->nombre);
			this->nombre[0] = toupper(this->nombre[0]);
			todoOk = 0;
		}
	}
	else
	{
		printf("\nNombre Invalido\n");
	}

	return todoOk;
}

int pokemon_getNombre(ePokemon *this, char *nombre)
{
	int todoOk = -1;

	if (this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		todoOk = 0;
	}

	return todoOk;
}

int pokemon_setTipo(ePokemon *this, char *tipo)
{
	int todoOk = -1;

	if (this != NULL && tipo != NULL)
	{
		if (strlen(tipo) < 100 && strlen(tipo) > 1)
		{
			strcpy(this->tipo, tipo);
			strlwr(this->tipo);
			this->tipo[0] = toupper(this->tipo[0]);
			todoOk = 0;
		}
	}
	else
	{
		printf("\nTipo Invalido\n");
	}
	return todoOk;
}

int pokemon_getTipo(ePokemon *this, char *tipo)
{
	int todoOk = -1;

	if (this != NULL && tipo != NULL)
	{
		strcpy(tipo, this->tipo);
		todoOk = 0;
	}

	return todoOk;
}

int pokemon_setTamanio(ePokemon *this, char *tamanio)
{
	int todoOk = -1;

	if (this != NULL && tamanio != NULL)
	{
		if (strlen(tamanio) < 100 && strlen(tamanio) > 1)
		{
			strcpy(this->tamanio, tamanio);
//			strlwr(this->tamanio);
//			this->tamanio[0] = toupper(this->tamanio[0]);
			todoOk = 0;
		}
	}
	else
	{
		printf("\nTamanio Invalida\n");
	}
	return todoOk;
}

int pokemon_getTamanio(ePokemon *this, char *tamanio)
{
	int todoOk = -1;

	if (this != NULL && tamanio != NULL)
	{
		strcpy(tamanio, this->tamanio);
		todoOk = 0;
	}

	return todoOk;
}

int pokemon_setAtaqueCargado(ePokemon *this, char *ataqueCargado)
{
	int todoOk = -1;

	if (this != NULL && ataqueCargado != NULL)
	{
		if (strlen(ataqueCargado) < 100 && strlen(ataqueCargado) > 1)
		{
			strcpy(this->ataqueCargado, ataqueCargado);
			strlwr(this->ataqueCargado);
			this->ataqueCargado[0] = toupper(this->ataqueCargado[0]);
			todoOk = 0;
		}
	}
	else
	{
		printf("\nTamanio Invalida\n");
	}
	return todoOk;
}

int pokemon_getAtaqueCargado(ePokemon *this, char *ataqueCargado)
{
	int todoOk = -1;

	if (this != NULL && ataqueCargado != NULL)
	{
		strcpy(ataqueCargado, this->ataqueCargado);
		todoOk = 0;
	}

	return todoOk;
}

int pokemon_setValorAtaque(ePokemon *this, int valorAtaque)
{
	int todoOk = -1;

	if (this != NULL && valorAtaque >= 0)
	{
		this->valorAtaque = valorAtaque;
		todoOk = 0;
	}
	else
	{
		printf("\nAltura invalida\n");
	}
	return todoOk;
}

int pokemon_getValorAtaque(ePokemon *this, int *valorAtaque)
{
	int todoOk = -1;

	if (this != NULL && valorAtaque != NULL)
	{
		*valorAtaque = this->valorAtaque;
		todoOk = 0;
	}

	return todoOk;
}

int pokemon_setEsVarioColor(ePokemon *this, int esVarioColor)
{
	int todoOk = -1;

	if (this != NULL && esVarioColor >= 0)
	{
		this->esVarioColor = esVarioColor;
		todoOk = 0;
	}
	else
	{
		printf("\nAltura invalida\n");
	}
	return todoOk;
}

int pokemon_getEsVarioColor(ePokemon *this, int *esVarioColor)
{
	int todoOk = -1;

	if (this != NULL && esVarioColor != NULL)
	{
		*esVarioColor = this->esVarioColor;
		todoOk = 0;
	}

	return todoOk;
}

void pokemon_mostrarEncabezado()
{
	printf("\n---------------------------------------------------------------------------------------------------------------");
	printf("\n| numero | nombre               | tipo       | tamanio | ataque cargado       | valor ataque | es vario color |");
	printf("\n---------------------------------------------------------------------------------------------------------------");
}

int pokemon_mostrarUnPokemon(ePokemon *unPokemon)
{
	int todoOk = -1;
	int numero;
	char nombre[30];
	char tipo[30];
	char tamanio[30];
	char ataqueCargado[30];
	int valorAtaque;
	int esVarioColor;

	if (unPokemon != NULL)
	{
		pokemon_getNumero(unPokemon, &numero);
		pokemon_getNombre(unPokemon, nombre);
		pokemon_getTipo(unPokemon, tipo);
		pokemon_getTamanio(unPokemon, tamanio);
		pokemon_getAtaqueCargado(unPokemon, ataqueCargado);
		pokemon_getValorAtaque(unPokemon, &valorAtaque);
		pokemon_getEsVarioColor(unPokemon, &esVarioColor);

		printf("\n| %-6d | %-20s | %-10s | %-7s | %-20s | %-12d | %-14d |", numero, nombre, tipo, tamanio, ataqueCargado, valorAtaque, esVarioColor);
		todoOk = 0;
	}
	return todoOk;
}

int pokemon_FiltrarPorFuego(void* pElement)
{
	int todoOk = 0;
	ePokemon* unPokemon = (ePokemon*) pElement;

	if(unPokemon != NULL)
	{
		if(strcmp(unPokemon->tipo, "Fire") == 0)
		{
			todoOk = 1;
		}
	}

	return todoOk;
}

int pokemon_FiltrarExtraGrande_TipoVeneno(void* pElement)
{
	int todoOk = 0;
	ePokemon* unPokemon = (ePokemon*) pElement;

	if(unPokemon != NULL)
	{
		if(strcmp(unPokemon->tamanio, "XL") == 0 && strcmp(unPokemon->tipo, "Poison") == 0)
		{
			todoOk = 1;
		}
	}

	return todoOk;
}

void* pokemon_Mapeo(void* pElement)
{
	ePokemon* unPokemon;
	int valorAtaque;
	int valorAtaqueAumentado;

	if(pElement != NULL)
	{
		unPokemon = (ePokemon*) pElement;

		if(strcmp(unPokemon->tipo, "Bug") == 0 || strcmp(unPokemon->tipo, "Fire") == 0 || strcmp(unPokemon->tipo, "Grass") == 0)
		{
			if(strcmp(unPokemon->tamanio, "XL") == 0)
			{
				pokemon_getValorAtaque(unPokemon, &valorAtaque);
				valorAtaqueAumentado = calcularAumento(valorAtaque, 20);
				pokemon_setValorAtaque(unPokemon, valorAtaqueAumentado);
			}
			else if(strcmp(unPokemon->tamanio, "L") == 0)
			{
				pokemon_getValorAtaque(unPokemon, &valorAtaque);
				valorAtaqueAumentado = calcularAumento(valorAtaque, 10);
				pokemon_setValorAtaque(unPokemon, valorAtaqueAumentado);
			}
			else
			{
				pokemon_getValorAtaque(unPokemon, &valorAtaque);
				valorAtaqueAumentado = calcularAumento(valorAtaque, 5);
				pokemon_setValorAtaque(unPokemon, valorAtaqueAumentado);
			}
		}
	}

	return unPokemon;
}

int calcularAumento(int valorAtaque, int porcentaje)
{
	int porcentajeCalculado;
	int valorAumentado;

	porcentajeCalculado = (porcentaje*valorAtaque)/100;
	valorAumentado = valorAtaque + porcentajeCalculado;

	return valorAumentado;
}

int pokemon_validarPokemonesBatalla(void* pElement)
{
	ePokemon* unPokemon;
	int todoOk = 0;
	if(pElement != NULL)
	{
		unPokemon = (ePokemon*) pElement;

		if(unPokemon != NULL)
		{
			if((strcmp(unPokemon->tipo, "Fire") == 0 && strcmp(unPokemon->tamanio, "XL") == 0 && strcmp(unPokemon->ataqueCargado, "Lanzallamas") == 0 && unPokemon->valorAtaque > 80)
			|| (strcmp(unPokemon->tipo, "Water") == 0 && strcmp(unPokemon->tamanio, "L") == 0 && strcmp(unPokemon->ataqueCargado, "Hidrobomba") == 0 && unPokemon->valorAtaque > 80))
			{
				todoOk = 1;
			}
		}
	}
	return todoOk;
}

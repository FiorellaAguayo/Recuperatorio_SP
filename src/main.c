/*
 ============================================================================
 Name        : practica.c
 Author      : Fiorella Aguayo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include "LinkedList.h"
#include "Controller.h"

int main(void)
{
	setbuf(stdout, NULL);

	LinkedList* lista = ll_newLinkedList();

	char confirmar= 'n';

	while(confirmar == 'n')
	{
		switch(menuPrincipal())
		{
			case 1:
				if(!controller_CargaDePokemonesDesdeTexto("Data_Pokemones.csv", lista))
				{
					printf("\nHubo un problema al hacer la carga de archivo.csv.\n");
				}
				else
				{
					printf("\nCarga de archivo.csv (modo texto) exitoso.\n");
				}
				break;

			case 2:
				if(controller_ModificarValorAtaque(lista))
				{
					printf("\nModificacion exitosa.\n");
				}
				break;

			case 3:
				if(!controller_ListarPokemones(lista))
				{
					printf("\nHubo un problema al hacer el listado de pokemones.\n");
				}
				break;

			case 4:
				if(!controller_Filtrado_Tipo(lista))
				{
					printf("\nHubo un problema al generar el filtrado.\n");
				}
				break;

			case 5:
				if(!controller_Filtrado_ExtraGrande_TipoVeneno(lista))
				{
					printf("\nHubo un problema al hacer el listado filtrado.\n");
				}
				break;

			case 6:
				if(!controller_Mapear_AtaqueCargado(lista))
				{
					printf("\nHubo un problema al hacer el mapeo de pokemones.\n");
				}
				break;

			case 7:
				if(!controller_batalla(lista))
				{
					printf("\nHubo un problema al hacer la batalla pokemon.\n");
				}
				break;

			case 8:
				pedirCaracter(&confirmar, "\n¿Deseas salir del programa? (s = si | n = no): ", "\nError. Ingresaste caracter no valido,", 's', 'n');
				break;
		}
	}

	return EXIT_SUCCESS;
}

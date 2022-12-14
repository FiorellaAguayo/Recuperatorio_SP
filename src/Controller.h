#include "LinkedList.h"
#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#endif /* CONTROLLER_H_ */

int controller_CargaDePokemonesDesdeTexto(char* path, LinkedList* pArrayListPokemon);
int controller_ListarPokemones(LinkedList* pArrayListPokemon);
int controller_ModificarValorAtaque(LinkedList* pArrayListPokemon);
int buscarPokemonPorNumero(LinkedList* pArrayListPokemon, int numero);
int controller_cargarArchivo(char* path, LinkedList* pArrayListPokemon);
int controller_Filtrado_Tipo(LinkedList* pArrayListPokemon);
int controller_Filtrado_ExtraGrande_TipoVeneno(LinkedList* pArrayListPokemon);
int controller_Mapear_AtaqueCargado(LinkedList* list);
int controller_batalla(LinkedList* pArrayListPokemon);

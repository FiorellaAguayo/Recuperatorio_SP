#ifndef INPUTS_H_
#define INPUTS_H_


#endif /* INPUTS_H_ */

int pedirEntero(int *enteroValidado, char mensaje[], char mensajeError[], int minimo, int maximo);
int pedirCaracter(char *charValidado, char mensaje[], char mensajeError[], char primerChar, char segundoChar);
int pedirCadena(char cadena[], char mensaje[], char mensajeError[], int max);
int validateCharacter(char string[]);
int firstCapitalChar(char name[]);
int menuPrincipal();

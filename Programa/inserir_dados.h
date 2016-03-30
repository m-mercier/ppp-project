#ifndef INSERIR_DADOS_H_INCLUDED
#define INSERIR_DADOS_H_INCLUDED
#include "estruturas.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int inserir_tipo(void);
void inserir_data(int ptr[]);
void inserir_horas(int ptr[]);
int verifica_matricula(int formato, char ptr2[]);
void inserir_matricula(char ptr2[]);
int index_cliente(lista1 lista_clientes);

#endif // INSERIR_DADOS_H_INCLUDED

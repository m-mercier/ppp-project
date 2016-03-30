#ifndef FICHEIROS_LEITURA_H_INCLUDED
#define FICHEIROS_LEITURA_H_INCLUDED
#include "clientes.h"

void dados1(lista1 lista_clientes,int numero, char *telefone, char nome[]);
void ler_clientes(lista1 lista_clientes);
void insere_reservas_lista(lista2 lista,lista2 no);
void dados2(lista2 lista,int *ptr, char *matricula);
void ler_reservas(lista2 lista_reservas);
void ler_pre_reservas(lista2 lista_pre_reservas);


#endif // FICHEIROS_LEITURA_H_INCLUDED

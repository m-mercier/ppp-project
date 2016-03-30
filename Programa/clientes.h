#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include "ficheiros_escrita.h"


void insere_cliente (lista1 lista_clientes,lista1 no);
int procura_numero(lista1 lista_clientes);
void inserir_tlm(char ptr[]);
int verifica_insere_cliente(lista1 lista_clientes,int num_cliente);
void dados_cliente (lista1 lista_clientes);
void imprime_clientes (lista1 lista_clientes);
void associa_nome_cliente(lista1 lista_clientes, char *nome, int num);


#endif // CLIENTES_H_INCLUDED

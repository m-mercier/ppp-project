#ifndef VERIFICACOES_H_INCLUDED
#define VERIFICACOES_H_INCLUDED
#include "estruturas.h"

int disponibilidade_reserva (lista2 lista_reservas, int hora_inicio, int hora_fim, int data);
int verifica_reserva(lista2 lista_reservas,int ptr[]);
int verifica_pre_reserva(lista2 lista_pre_reservas,int ptr[]);
int verifica_clientes(lista1 lista_clientes);



#endif // VERIFICACOES_H_INCLUDED

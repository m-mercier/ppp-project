#ifndef INSERIR_MARCACOES_H_INCLUDED
#define INSERIR_MARCACOES_H_INCLUDED
#include "verificacoes.h"
#include "ficheiros_escrita.h"
#include "inserir_dados.h"

void dados_reserva (lista1 lista_clientes,lista2 lista_reservas,lista2 lista_pre_reservas,int tipo);
void insere_reserva (lista2 lista_reservas,lista2 no);
void insere_pre_reserva (lista2 lista_pre_reservas, lista2 no);

#endif // INSERIR_MARCACOES_H_INCLUDED

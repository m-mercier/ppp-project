#ifndef IMPRIMIR_H_INCLUDED
#define IMPRIMIR_H_INCLUDED

#include "separar.h"
#include "ficheiros_leitura.h"

void apaga_lista(lista2 lista);
void ordena_pre_reservas(lista2 lista);
void imprime_contrario (lista2 lista, int num_cliente);
void pede_cliente(lista1 lista_clientes,lista2 lista,int p);
void imprime_pre_reservas_completo (lista1 lista_clientes,lista2 lista_pre_reservas);
void imprime_pre_reservas_diario (lista1 lista_clientes,lista2 lista_pre_reservas);
void imprime_pre_reservas_cliente (lista1 lista_clientes,lista2 lista_pre_reservas);
void imprime_reservas_completo (lista1 lista_clientes,lista2 lista, int p);
void imprime_reservas_diario (lista1 lista_clientes,lista2 lista, int p);


#endif // IMPRIMIR_H_INCLUDED

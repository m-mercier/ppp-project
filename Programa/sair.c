#include "sair.h"

/*Actualiza os ficheiros quando saímos do programa*/
void sair(lista1 lista_clientes, lista2 lista_reservas, lista2 lista_pre_reservas)
{
    escrever_clientes(lista_clientes);
    escrever_reservas(lista_reservas);
    escrever_pre_reservas(lista_pre_reservas);
}

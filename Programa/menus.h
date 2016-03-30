#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include "eliminar_efectuar.h"
#include "imprimir.h"
#include "sair.h"

void menu(lista1 lista_clientes, lista2 lista_reservas, lista2 lista_pre_reservas);
void submenu1_cliente(lista1 lista_clientes, lista2 lista_reservas,lista2 lista_pre_reservas);
void submenu1_reservar (lista1 lista_clientes, lista2 lista_reservas,lista2 lista_pre_reservas);
void submenu2_listar (lista1 lista_clientes, lista2 lista_reservas,lista2 lista_pre_reservas);
void submenu3_listar_reservas (lista1 lista_clientes, lista2 lista_reservas,lista2 lista_pre_reservas);
void submenu4_listar_prereservas (lista1 lista_clientes, lista2 lista_reservas, lista2 lista_pre_reservas);




#endif // MENUS_H_INCLUDED

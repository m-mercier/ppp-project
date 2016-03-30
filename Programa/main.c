#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "info.h"
#include "menus.h"
#include "cria_lista.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    lista1 lista_clientes=cria_lista_cliente();
    lista2 lista_reservas=cria_lista();
    lista2 lista_pre_reservas=cria_lista();
    ler_clientes(lista_clientes);
    ler_reservas(lista_reservas);
    ler_pre_reservas(lista_pre_reservas);
    info();
    menu(lista_clientes,lista_reservas,lista_pre_reservas);
    return 0;
}

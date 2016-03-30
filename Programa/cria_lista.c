#include <stdio.h>
#include "cria_lista.h"

/*##################################
  #           Clientes             #
  ##################################*/

/*Cria/inicia a lista de clientes -> lista_clientes*/
lista1 cria_lista_cliente(void)
{
    lista1 aux;
    aux = (lista1) malloc (sizeof (node_clientes));
    if (aux != NULL)
    {
        aux->cliente.nome_cliente[0]='\0';
        aux->cliente.num_cliente = 0;
        aux->cliente.num_tlf[0]='\0';
        aux->next = NULL;
    }
    return aux;
}

/*########################################
  #Criar lista de reservas e pré-reservas#
  ########################################*/

/* Cria/inicia uma lista de reservas ou pré-reservas*/
lista2 cria_lista(void)
{
    lista2 aux;
    aux = (lista2) malloc (sizeof (node_reservas));
    if (aux != NULL)
    {
        aux->num_cliente = 0;
        aux->matricula[0]='\0';
        aux->horas_inicio=0;
        aux->horas_fim=0;
        aux->data=0;
        aux->tipo=0;
        aux->next = NULL;
    }
    return aux;
}

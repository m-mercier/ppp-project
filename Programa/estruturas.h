#ifndef ESTRUTURAS_H_INCLUDED
#define ESTRUTURAS_H_INCLUDED

#include <stdio.h>
#define MAX 41

/*##################################
  #      Estruturas/Listas         #
  ##################################*/

/*Estrutura de cliente*/
typedef struct
{
    int num_cliente;
    char nome_cliente[MAX];
    char num_tlf[10]; /*9 digitos + '\0'*/
}str_cliente;

/*Lista de clientes*/
typedef struct node1 *lista1;
typedef struct node1
{
    str_cliente cliente;
    lista1 next;

}node_clientes;

/*Lista de reservas/pré-reservas*/
typedef struct node2 *lista2;
typedef struct node2
{
    int num_cliente;
    char matricula[9];
    int horas_inicio;
    int horas_fim;
    int data;
    int tipo; /*Manutenção -> 1 hora -> 100; Lavagem -> 30 minutos -> 30*/
    lista2 next;

}node_reservas;

#endif // ESTRUTURAS_H_INCLUDED

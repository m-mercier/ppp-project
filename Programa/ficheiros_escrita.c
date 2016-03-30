#include "ficheiros_escrita.h"

/*##################################
  # Ficheiros - Escrita - Clientes #
  ##################################*/
  /*Escreve a lista de clientes no ficheiro 'clientes.txt'*/
  void escrever_clientes(lista1 lista_clientes)
  {
      FILE *f = fopen("clientes.txt","w");
      lista1 aux = lista_clientes->next;
      while (aux!=NULL)
      {
          fprintf(f,"%d\n%s\n%s\n",aux->cliente.num_cliente,aux->cliente.nome_cliente,aux->cliente.num_tlf);
          aux = aux->next;
      }
      fclose(f);
  }

  /*##################################
  # Ficheiros - Escrita - Reservas #
  ##################################*/
/*Escreve a lista de reservas no ficheiro 'reservas.txt'*/
void escrever_reservas(lista2 lista_reservas)
{
      FILE *f = fopen("reservas.txt","w");
      lista2 aux = lista_reservas->next;
      while (aux!=NULL)
      {
          fprintf(f,"%d\n%s\n%d\n%d\n%d\n%d\n",aux->num_cliente,aux->matricula,aux->horas_inicio,aux->horas_fim,aux->data,aux->tipo);
          aux = aux->next;
      }
      fclose(f);
}
/*######################################
  # Ficheiros - Escrita - Pré-Reservas #
  ######################################*/
/*Escreve a lista de pré-reservas no ficheiro 'pre_reservas.txt'*/
  void escrever_pre_reservas(lista2 lista_pre_reservas)
{
      FILE *f = fopen("pre_reservas.txt","w");
      lista2 aux = lista_pre_reservas->next;
      while (aux!=NULL)
      {
          fprintf(f,"%d\n%s\n%d\n%d\n%d\n%d\n",aux->num_cliente,aux->matricula,aux->horas_inicio,aux->horas_fim,aux->data,aux->tipo);
          aux = aux->next;
      }
      fclose(f);
}

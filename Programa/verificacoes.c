#include "verificacoes.h"

/*Verifica se há disponibilidade para marcar a reserva no horário pretendido*/
int disponibilidade_reserva (lista2 lista_reservas, int hora_inicio, int hora_fim, int data)
{
    lista2 actual;
    actual=lista_reservas->next;
    while(actual!=NULL)
    {
        if (data==actual->data && hora_inicio<actual->horas_fim) /*Só verifica no dia em que pretendemos fazer a marcação, se a hora de início (da marcação) for menor que a hora de fim do nó que estamos a analisar*/

        {
            if (hora_inicio==actual->horas_inicio) /*Se a hora de ínicio (da marcação) for coincidente com uma reserva já existente*/
            {
                return 1; /*1-> horário ocupado*/
            }
            else if (hora_inicio>actual->horas_inicio) /*Se a marcação é "no meio" de uma reserva já existente*/
            {
                return 1; /*1-> horário ocupado*/
            }
            else if (hora_fim>actual->horas_inicio && hora_fim<actual->horas_fim) /*Se a marcação é "no meio" de uma reserva já existente*/
            {
                return 1; /*1-> horário ocupado*/
            }
            else
            {
                return 0; /*0-> horário livre*/
            }
        }
        actual=actual->next;
    }
    return 0;/*0-> horário livre*/
}

/*Verifica se a nova reserva foi inserida na lista de reservas*/
int verifica_reserva(lista2 lista_reservas,int ptr[])
{
    lista2 aux;
    aux=lista_reservas->next;
    while(aux!=NULL)
    {
        if (aux->data==ptr[0] && aux->horas_inicio==ptr[1])
        {
            return 1; /*1-> a reserva foi inserida*/
        }
        aux = aux->next;
    }
    return 0; /*0-> a reserva não foi inserida*/
}

/*Verifica se a nova pré-reserva foi inserida na lista de pré-reservas*/
int verifica_pre_reserva(lista2 lista_pre_reservas,int ptr[])
{
    lista2 aux;
    aux=lista_pre_reservas->next;
    while(aux!=NULL)
    {
        if (aux->num_cliente==ptr[0] && aux->tipo==ptr[1]  && aux->data==ptr[2]  && aux->horas_inicio==ptr[3])
        {
            return 1; /*1-> a pré-reserva foi inserida*/
        }
        aux = aux->next;
    }
    return 0; /*0->a pré-reserva não foi inserida*/
}
/*Verifica se a lista de clientes está vazia*/
int verifica_clientes(lista1 lista_clientes)
{
    lista1 aux;
    aux=lista_clientes->next;
    if(aux==NULL)
    {
        return 0; /*0-lista vazia*/
    }
    else
    {
        return 1;   /*1-lista não vazia*/
    }
}

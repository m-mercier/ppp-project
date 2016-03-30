#include "verificacoes.h"

/*Verifica se h� disponibilidade para marcar a reserva no hor�rio pretendido*/
int disponibilidade_reserva (lista2 lista_reservas, int hora_inicio, int hora_fim, int data)
{
    lista2 actual;
    actual=lista_reservas->next;
    while(actual!=NULL)
    {
        if (data==actual->data && hora_inicio<actual->horas_fim) /*S� verifica no dia em que pretendemos fazer a marca��o, se a hora de in�cio (da marca��o) for menor que a hora de fim do n� que estamos a analisar*/

        {
            if (hora_inicio==actual->horas_inicio) /*Se a hora de �nicio (da marca��o) for coincidente com uma reserva j� existente*/
            {
                return 1; /*1-> hor�rio ocupado*/
            }
            else if (hora_inicio>actual->horas_inicio) /*Se a marca��o � "no meio" de uma reserva j� existente*/
            {
                return 1; /*1-> hor�rio ocupado*/
            }
            else if (hora_fim>actual->horas_inicio && hora_fim<actual->horas_fim) /*Se a marca��o � "no meio" de uma reserva j� existente*/
            {
                return 1; /*1-> hor�rio ocupado*/
            }
            else
            {
                return 0; /*0-> hor�rio livre*/
            }
        }
        actual=actual->next;
    }
    return 0;/*0-> hor�rio livre*/
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
    return 0; /*0-> a reserva n�o foi inserida*/
}

/*Verifica se a nova pr�-reserva foi inserida na lista de pr�-reservas*/
int verifica_pre_reserva(lista2 lista_pre_reservas,int ptr[])
{
    lista2 aux;
    aux=lista_pre_reservas->next;
    while(aux!=NULL)
    {
        if (aux->num_cliente==ptr[0] && aux->tipo==ptr[1]  && aux->data==ptr[2]  && aux->horas_inicio==ptr[3])
        {
            return 1; /*1-> a pr�-reserva foi inserida*/
        }
        aux = aux->next;
    }
    return 0; /*0->a pr�-reserva n�o foi inserida*/
}
/*Verifica se a lista de clientes est� vazia*/
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
        return 1;   /*1-lista n�o vazia*/
    }
}

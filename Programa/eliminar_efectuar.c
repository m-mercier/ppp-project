#include "eliminar_efectuar.h"

/*Elimina uma reserva da lista de reservas*/
void elimina_reserva (lista1 lista_clientes,lista2 lista_reservas,lista2 lista_pre_reservas)
{
    lista2 ant,actual,ant_pre,actual_pre,aux,no;
    int teste,data,horas[3],ptr[2];
    ant=lista_reservas;
    actual=lista_reservas->next;
    ant_pre=lista_pre_reservas;
    actual_pre=lista_pre_reservas->next;
    /*Ler dados*/
    if (actual==NULL)
    {
        system("cls");
        printf("\n\nA lista está vazia!\n\n");
        return;
    }
    printf("\n\t\tELIMINAR RESERVA\n\n");
    horas[2]=inserir_tipo();
    inserir_data(&data);
    ptr[0]=data;
    inserir_horas(&horas);
    ptr[1]=horas[0];

    /*Procurar nó e eliminar nó*/
    while(actual!=NULL && (actual->data!=ptr[0]  || actual->horas_inicio!=ptr[1]) )
    {
        ant=actual; /*Enquanto não encontra o nó, avança*/
        actual=actual->next;
    }
    if(actual!=NULL)
    {
        ant->next=actual->next; /*Quando encontra o nó, apaga-o*/
        free(actual);
        if(!verifica_reserva(lista_reservas,ptr))
        {
            system("cls");
            printf("\n\nA Reserva foi eliminada!\n\n");
        }
        else
        {
            system("cls");
            printf("\n\nOcorreu um erro! Tente novamente!\n\n");
        }

    }
    else
    {
        system("cls");
        printf("\n\nEssa reserva não existe!\n\n");
    }
    while(actual_pre!=NULL)
    {   /*Percorre a lista das pré-reservas para ver se alguma encaixa na nova vaga da lista de reservas*/
        teste = disponibilidade_reserva(lista_reservas,actual_pre->horas_inicio,actual_pre->horas_fim,actual_pre->data);
        if (teste==0) /*Teste=0 -> a pré-reserva pode ser inserida na lista de reservas*/
        {
            no = (lista2) malloc (sizeof (node_reservas));
            no->num_cliente=actual_pre->num_cliente;
            no->horas_inicio=actual_pre->horas_inicio;
            no->horas_fim= actual_pre->horas_fim;
            strcpy(no->matricula,actual_pre->matricula);
            no->data=actual_pre->data;
            no->tipo=actual_pre->tipo;
            insere_reserva(lista_reservas,no);
            aux=actual_pre;
            actual_pre=actual_pre->next;
            ant_pre->next=actual_pre;
            free(aux);
            ptr[0]=actual->data;
            ptr[1]=actual->horas_inicio;

        }
        else /*A pré-reserva não pode ser inserida na lista de reservas, por isso avança*/
        {
            ant_pre=actual_pre;
            actual_pre=actual_pre->next;
        }

    }
    escrever_reservas(lista_reservas); /*Actualiza o ficheiro de reservas (reservas.txt)*/
    escrever_pre_reservas(lista_pre_reservas); /*Actualiza o ficheiro de pré-reservas (pre_reservas.txt)*/

}

/*Elimina uma pré-reserva da lista de pré-reservas*/
void elimina_pre_reserva (lista1 lista_clientes,lista2 lista_pre_reservas)
{
    lista2 ant,actual;
    int data,horas[3],ptr[4];
    ant=lista_pre_reservas;
    actual=lista_pre_reservas->next;
    if (actual==NULL)   /*Verificar se a lista está vazia*/
    {
        system("cls");
        printf("\n\nA lista de Pré-Reservas está vazia!\n\n");
        return;
    }
    printf("\n\t\tELIMINAR PRÉ-RESERVA\n");
    /*Ler dados*/
    ptr[0]=index_cliente(lista_clientes);
    ptr[1]=inserir_tipo();
    horas[2]=ptr[1];
    inserir_data(&data);
    ptr[2]=data;
    inserir_horas(&horas);
    ptr[3]=horas[0];
    /*Procurar nó que queremos eliminar e eliminá-lo*/
    while(actual!=NULL && (actual->num_cliente!=ptr[0] || actual->tipo!=ptr[1]  || actual->data!=ptr[2]  || actual->horas_inicio!=ptr[3]) )
    {
        ant=actual; /*Se ainda não tiver encontrado o nó, avança*/
        actual=actual->next;
    }
    if(actual!=NULL)
    {
        ant->next=actual->next;     /*Quando encontra o nó, apaga-o*/
        free(actual);
        if (!verifica_pre_reserva(lista_pre_reservas,ptr))
        {
           system("cls");
           printf("\n\nA Pré-Reserva foi eliminada!\n\n");
        }
        else
        {
            system("cls");
            printf("\n\nOcorreu um erro! Volte a eliminar!\n\n");
        }

    }else
    {
        system("cls");
        printf("\n\nEssa pre-reserva não existe!\n\n");
    }
    escrever_pre_reservas(lista_pre_reservas); /*Actualiza o ficheiro das pré-reservas (pre_reservas.txt)*/

}

/*Considera que uma reserva foi efectuada, eliminando todas as reservas e pré-reservas com datas/horários anteriores à efectuada*/
void efectua_reserva(lista2 lista_reservas, lista2 lista_pre_reservas)
{
    lista2 ant,actual,ant_pre,actual_pre;
    int i,ptr[2],data,horas[3],horas_fim;
    ant=lista_reservas;
    actual=lista_reservas->next;
    ant_pre=lista_pre_reservas;
    actual_pre=lista_pre_reservas->next;
    /*Ler dados*/
    if (actual==NULL)
    {
        system("cls");
        printf("\n\nA lista está vazia!\n\n");
        return;
    }
    printf("\n\t\tEFECTUAR LAVAGEM/MANUTENÇÃO\n");
    horas[2]=inserir_tipo();
    inserir_data(&data);
    ptr[0] = data;
    inserir_horas(&horas);
    ptr[1]=horas[0];

    /*Procurar nó e eliminar nó*/
    while (actual!=NULL)
    {
        if(actual->data==ptr[0]  && actual->horas_inicio==ptr[1])
        {
            i=1; /* i=1 -> encontrou a reserva que foi efectuada*/
            horas_fim=actual->horas_fim;
        }
        ant=actual; /*Enquanto não encontra, avança*/
        actual=actual->next;
    }
    ant=lista_reservas;
    actual=lista_reservas->next;
    if (i==1) /*Se encontrou a reserva que foi efectuada*/
    {
        while(actual!=NULL && (actual->data<ptr[0]||(actual->horas_inicio<=ptr[1] && actual->data==ptr[0]))) /*Elimina todas as reservas com uma data anterior ou com a mesma data e uma hora de início anterior à da reserva efectuada*/
        {

            ant->next=actual->next;
            free(actual);
            actual=ant->next;
        }
        while(actual_pre!=NULL && actual_pre->data<ptr[0]) /*Elimina todas as pré-reservas com uma data anterior à reserva efectuada*/
        {
            ant_pre->next=actual_pre->next;
            free(actual_pre);
            actual_pre=ant_pre->next;
        }
        while(actual_pre!=NULL && actual_pre->data==ptr[0])
        {
            if(actual_pre->horas_inicio<horas_fim) /*Elimina as pré-reservas com a mesma data e horas de início menores que a hora de fim da reserva efetcuada*/
            {
                ant_pre->next=actual_pre->next;
                free(actual_pre);
                actual_pre=ant_pre->next;
            }
            else
            {
                ant_pre=actual_pre; /*Senão, avança*/
                actual_pre=actual_pre->next;
            }

        }
        if(!verifica_reserva(lista_reservas,ptr))
        {
            system("cls");
            printf("\n\nReserva efectuada!\n\n");
        }else
        {
            system("cls");
            printf("\n\nOcorreu um erro! A sua pré-reserva não foi eliminada!\n\n");
        }
    }
    else
    {
        printf("\n\nEssa reserva não existe!\n\n");
    }
    escrever_reservas(lista_reservas); /*Actualiza o ficheiro de reservas (reservas.txt)*/
    escrever_pre_reservas(lista_pre_reservas); /*Actualiza o ficheiro de pré-reservas (pre_reservas.txt)*/
}

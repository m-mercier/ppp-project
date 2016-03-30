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
        printf("\n\nA lista est� vazia!\n\n");
        return;
    }
    printf("\n\t\tELIMINAR RESERVA\n\n");
    horas[2]=inserir_tipo();
    inserir_data(&data);
    ptr[0]=data;
    inserir_horas(&horas);
    ptr[1]=horas[0];

    /*Procurar n� e eliminar n�*/
    while(actual!=NULL && (actual->data!=ptr[0]  || actual->horas_inicio!=ptr[1]) )
    {
        ant=actual; /*Enquanto n�o encontra o n�, avan�a*/
        actual=actual->next;
    }
    if(actual!=NULL)
    {
        ant->next=actual->next; /*Quando encontra o n�, apaga-o*/
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
        printf("\n\nEssa reserva n�o existe!\n\n");
    }
    while(actual_pre!=NULL)
    {   /*Percorre a lista das pr�-reservas para ver se alguma encaixa na nova vaga da lista de reservas*/
        teste = disponibilidade_reserva(lista_reservas,actual_pre->horas_inicio,actual_pre->horas_fim,actual_pre->data);
        if (teste==0) /*Teste=0 -> a pr�-reserva pode ser inserida na lista de reservas*/
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
        else /*A pr�-reserva n�o pode ser inserida na lista de reservas, por isso avan�a*/
        {
            ant_pre=actual_pre;
            actual_pre=actual_pre->next;
        }

    }
    escrever_reservas(lista_reservas); /*Actualiza o ficheiro de reservas (reservas.txt)*/
    escrever_pre_reservas(lista_pre_reservas); /*Actualiza o ficheiro de pr�-reservas (pre_reservas.txt)*/

}

/*Elimina uma pr�-reserva da lista de pr�-reservas*/
void elimina_pre_reserva (lista1 lista_clientes,lista2 lista_pre_reservas)
{
    lista2 ant,actual;
    int data,horas[3],ptr[4];
    ant=lista_pre_reservas;
    actual=lista_pre_reservas->next;
    if (actual==NULL)   /*Verificar se a lista est� vazia*/
    {
        system("cls");
        printf("\n\nA lista de Pr�-Reservas est� vazia!\n\n");
        return;
    }
    printf("\n\t\tELIMINAR PR�-RESERVA\n");
    /*Ler dados*/
    ptr[0]=index_cliente(lista_clientes);
    ptr[1]=inserir_tipo();
    horas[2]=ptr[1];
    inserir_data(&data);
    ptr[2]=data;
    inserir_horas(&horas);
    ptr[3]=horas[0];
    /*Procurar n� que queremos eliminar e elimin�-lo*/
    while(actual!=NULL && (actual->num_cliente!=ptr[0] || actual->tipo!=ptr[1]  || actual->data!=ptr[2]  || actual->horas_inicio!=ptr[3]) )
    {
        ant=actual; /*Se ainda n�o tiver encontrado o n�, avan�a*/
        actual=actual->next;
    }
    if(actual!=NULL)
    {
        ant->next=actual->next;     /*Quando encontra o n�, apaga-o*/
        free(actual);
        if (!verifica_pre_reserva(lista_pre_reservas,ptr))
        {
           system("cls");
           printf("\n\nA Pr�-Reserva foi eliminada!\n\n");
        }
        else
        {
            system("cls");
            printf("\n\nOcorreu um erro! Volte a eliminar!\n\n");
        }

    }else
    {
        system("cls");
        printf("\n\nEssa pre-reserva n�o existe!\n\n");
    }
    escrever_pre_reservas(lista_pre_reservas); /*Actualiza o ficheiro das pr�-reservas (pre_reservas.txt)*/

}

/*Considera que uma reserva foi efectuada, eliminando todas as reservas e pr�-reservas com datas/hor�rios anteriores � efectuada*/
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
        printf("\n\nA lista est� vazia!\n\n");
        return;
    }
    printf("\n\t\tEFECTUAR LAVAGEM/MANUTEN��O\n");
    horas[2]=inserir_tipo();
    inserir_data(&data);
    ptr[0] = data;
    inserir_horas(&horas);
    ptr[1]=horas[0];

    /*Procurar n� e eliminar n�*/
    while (actual!=NULL)
    {
        if(actual->data==ptr[0]  && actual->horas_inicio==ptr[1])
        {
            i=1; /* i=1 -> encontrou a reserva que foi efectuada*/
            horas_fim=actual->horas_fim;
        }
        ant=actual; /*Enquanto n�o encontra, avan�a*/
        actual=actual->next;
    }
    ant=lista_reservas;
    actual=lista_reservas->next;
    if (i==1) /*Se encontrou a reserva que foi efectuada*/
    {
        while(actual!=NULL && (actual->data<ptr[0]||(actual->horas_inicio<=ptr[1] && actual->data==ptr[0]))) /*Elimina todas as reservas com uma data anterior ou com a mesma data e uma hora de in�cio anterior � da reserva efectuada*/
        {

            ant->next=actual->next;
            free(actual);
            actual=ant->next;
        }
        while(actual_pre!=NULL && actual_pre->data<ptr[0]) /*Elimina todas as pr�-reservas com uma data anterior � reserva efectuada*/
        {
            ant_pre->next=actual_pre->next;
            free(actual_pre);
            actual_pre=ant_pre->next;
        }
        while(actual_pre!=NULL && actual_pre->data==ptr[0])
        {
            if(actual_pre->horas_inicio<horas_fim) /*Elimina as pr�-reservas com a mesma data e horas de in�cio menores que a hora de fim da reserva efetcuada*/
            {
                ant_pre->next=actual_pre->next;
                free(actual_pre);
                actual_pre=ant_pre->next;
            }
            else
            {
                ant_pre=actual_pre; /*Sen�o, avan�a*/
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
            printf("\n\nOcorreu um erro! A sua pr�-reserva n�o foi eliminada!\n\n");
        }
    }
    else
    {
        printf("\n\nEssa reserva n�o existe!\n\n");
    }
    escrever_reservas(lista_reservas); /*Actualiza o ficheiro de reservas (reservas.txt)*/
    escrever_pre_reservas(lista_pre_reservas); /*Actualiza o ficheiro de pr�-reservas (pre_reservas.txt)*/
}

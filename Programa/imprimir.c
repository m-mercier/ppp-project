#include "imprimir.h"

/*Apaga todos os elementos da lista, menos o header, ficando lista->header->NULL*/
void apaga_lista(lista2 lista)
{
    lista2 ant,aux;
    ant = lista->next;
    lista->next=NULL;
    while(ant!=NULL)
    {
        aux=ant;
        ant=ant->next;
        free(aux);
    }

}

/*Ordena a lista de pré-reservas -> da mais antiga para a mais recente
Nota: as pré-reservas já estão ordenadas por dia, mas não por hora*/
void ordena_pre_reservas(lista2 lista)
{
    int ordenado;
    lista2 ant, actual,aux_ant,aux_actual;
    if (lista->next==NULL)
    {
        return;
    }
    do
    {
        ordenado=1; /*1->a lista está ordenada*/
        for(aux_ant=lista,ant=lista->next,actual=ant->next;actual;)
        {
            if(ant->data == actual->data && actual->horas_inicio<ant->horas_inicio) /*Se o nó anterior (ant) e o nó actual (actual) tiverem a mesma data e a hora do actual for mais antiga (menor) que a do ant, trocam*/
            {
                aux_actual=actual;
                actual=actual->next;
                ant->next=aux_actual->next;
                aux_actual->next=ant;
                aux_ant->next=aux_actual;
                aux_ant=aux_ant->next;
                ordenado=0; /*0->a lista ainda não está ordenada*/
            }
            else /*Se já estiver ordenado, avança*/
            {
                aux_ant=ant;
                ant=actual;
                actual=actual->next;
            }
        }

    }while(!ordenado); /*Percorre o ciclo enquanto a lista não está ordenada, ordenado=0*/
}

/*Imprime a lista pela ordem inversa, de forma recursiva*/
void imprime_contrario (lista2 lista,int num_cliente)
{
    int data[4],horas[3];
    if (lista->next == NULL)
    {

        if (lista->num_cliente==num_cliente)
        {
            if(lista->tipo==100)
            {
                printf("\n\tManutenção\n");
            }
            else
            {
                printf("\n\tLavagem\n");
            }
            printf("Matrícula: %s \n",lista->matricula);
            data[0]=lista->data;
            separa_data(&data);
            printf("Data: %.2d/%.2d/%d \n\n",data[1],data[2],data[3]);
            horas[0]=lista->horas_inicio;
            separa_horas(&horas);
            printf("Horas: %.2d:%.2d \n\n", horas[1],horas[2]);
        }
    }
    else
    {
        imprime_contrario (lista->next,num_cliente);
        if (lista->num_cliente==num_cliente)
        {
            if(lista->tipo==100)
            {
                printf("\n\tManutenção\n");
            }

            else
            {
                printf("\n\tLavagem\n");
            }
            printf("Matrícula: %s \n",lista->matricula);
            data[0]=lista->data;
            separa_data(&data);
            printf("Data: %.2d/%.2d/%d \n",data[1],data[2],data[3]);
            horas[0]=lista->horas_inicio;
            separa_horas(&horas);
            printf("Horas: %.2d:%.2d \n\n", horas[1],horas[2]);

        }

    }
}

/*Pede ao utilizador o nº de cliente para imprimir as listas (reservas e pré-reservas) por cliente*/
void pede_cliente(lista1 lista_clientes,lista2 lista,int p)
{

    lista2 aux;
    int num_cliente,i=0;
    char nome[MAX];
    if(p==1)
    {
        ordena_pre_reservas(lista);
        printf("\n\t LISTA DE PRÉ-RESERVAS \n");
    }
    else if(p==0)
    {
        printf("\n\t LISTA DE RESERVAS \n");
    }
    if (lista->next==NULL)
    {
        system("cls");
        printf("\n\nA lista está vazia!\n\n");
        return;
    }
    num_cliente = index_cliente(lista_clientes);
    printf("\nNúmero de cliente: %.3d \n",num_cliente);
    associa_nome_cliente(lista_clientes,&nome,num_cliente);
    printf("Nome de cliente: %s \n", nome);
    aux=lista->next;
    while(aux)
    {
        if(aux->num_cliente==num_cliente)
        {
            i=1;
        }
        aux=aux->next;
    }
    if(i)
    {
        imprime_contrario(lista, num_cliente);
    }
    else
    {
        printf("Este cliente não tem marcações.\n\n");
    }
}

/*Imprime a lista de pré-reservas completa, da mais antiga para a mais recente*/
void imprime_pre_reservas_completo (lista1 lista_clientes,lista2 lista_pre_reservas)
{
    escrever_pre_reservas(lista_pre_reservas);
    imprime_reservas_completo(lista_clientes,lista_pre_reservas,1);
    apaga_lista(lista_pre_reservas);
    ler_pre_reservas(lista_pre_reservas);
}

/*Imprime a lista de pré-reservas de um dia (escolhido pelo utilizador), da mais antiga para a mais recente*/
void imprime_pre_reservas_diario (lista1 lista_clientes,lista2 lista_pre_reservas)
{
    escrever_pre_reservas(lista_pre_reservas);
    imprime_reservas_diario(lista_clientes,lista_pre_reservas,1);
    apaga_lista(lista_pre_reservas);
    ler_pre_reservas(lista_pre_reservas);
}

/*Imprime a lista de pré-reservas de um cliente, da mais recente para a mais antiga*/
void imprime_pre_reservas_cliente (lista1 lista_clientes,lista2 lista_pre_reservas)
{
    escrever_pre_reservas(lista_pre_reservas);
    pede_cliente(lista_clientes,lista_pre_reservas,1);
    apaga_lista(lista_pre_reservas);
    ler_pre_reservas(lista_pre_reservas);
}

/*Imprime a lista de reservas completa, da mais antiga para a mais recente*/
void imprime_reservas_completo (lista1 lista_clientes,lista2 lista, int p)
{
    int data[4],horas[3];
    char nome[MAX];
    lista2 aux;
    if (p==1)
    {
        ordena_pre_reservas(lista);
        printf("\n\t LISTA DE PRÉ-RESERVAS \n");
    }
    else if (p==0)
    {
        printf("\n\t LISTA DE RESERVAS \n");
    }
    aux = lista->next;
    if (aux==NULL)
    {
        system("cls");
        printf("\n\nA lista está vazia!\n\n");
    }
    while (aux!=NULL)
    {
        if(aux->tipo==100)
        {
            printf("\n\tManutenção\n");
        }
        else
        {
            printf("\n\tLavagem\n");
        }
        printf("\nNúmero de cliente: %.3d \n",aux->num_cliente);
        associa_nome_cliente(lista_clientes,&nome,aux->num_cliente);
        printf("Nome de cliente: %s \n", nome);
        printf("Matrícula: %s \n",aux->matricula);
        data[0]=aux->data;
        separa_data(&data);
        printf("Data: %.2d/%.2d/%d \n",data[1],data[2],data[3]);
        horas[0]=aux->horas_inicio;
        separa_horas(&horas);
        printf("Horas: %.2d:%.2d \n\n", horas[1],horas[2]);
        aux=aux->next;

     }
}

/*Imprime a lista de reservas de um dia, da mais antiga para a mais recente*/
void imprime_reservas_diario (lista1 lista_clientes,lista2 lista, int p)
{
    lista2 aux = lista;
    int data,horas[3],i=1;
    char nome[MAX];
    if(p==1)
    {
        ordena_pre_reservas(lista);
        printf("\n\t LISTA DE PRÉ-RESERVAS \n");
    }
    else if(p==0)
    {
        printf("\n\t LISTA DE RESERVAS \n");
    }
    if(aux->next==NULL)
    {
        system("cls");
        printf("\n\nA lista está vazia!\n\n");
        return;
    }
    inserir_data(&data);
    while (aux!=NULL)
    {
        if(aux->data==data)
        {
            i=0;
            if(aux->tipo==100)
            {
                printf("\n\tManutenção\n");
            }
            else if (aux->tipo==30)
            {
                printf("\n\tLavagem\n");
            }
            printf("\nNúmero de cliente: %.3d \n",aux->num_cliente);
            associa_nome_cliente(lista_clientes,&nome,aux->num_cliente);
            printf("Nome de cliente: %s \n", nome);
            printf("Matrícula: %s \n",aux->matricula);
            horas[0]=aux->horas_inicio;
            separa_horas(&horas);
            printf("Horas: %.2d:%.2d \n\n", horas[1],horas[2]);
        }

        aux=aux->next;
    }
     if(i)
     {
         printf("\n\t Não existem marcações nesse dia!\n\n");
     }
}

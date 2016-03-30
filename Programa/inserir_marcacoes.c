#include "inserir_marcacoes.h"

/*Pede ao utilizador os dados para criar uma nova reserva*/
void dados_reserva (lista1 lista_clientes,lista2 lista_reservas,lista2 lista_pre_reservas,int tipo)
{
    lista2 no;
    int escolha, teste=0;
    int horas[3],data;
    char matricula2[9];
    no = (lista2) malloc (sizeof (node_reservas));
    horas[2]=tipo;
    no->tipo=tipo;
    if (no != NULL)
    {
        printf("\n\t\t NOVA RESERVA \n");
        no->num_cliente=index_cliente(lista_clientes);
        inserir_matricula(&matricula2);
        strcpy(no->matricula,matricula2);
        inserir_data(&data);
        no->data=data;
        inserir_horas(&horas);
        no->horas_inicio=horas[0];
        no->horas_fim=horas[1];
        teste = disponibilidade_reserva(lista_reservas,no->horas_inicio,no->horas_fim,no->data); /*Verifica se pode inserir a reserva*/
        if(teste==0) /*teste=0->pode inserir a reserva*/
        {
            insere_reserva (lista_reservas,no);
            escrever_reservas(lista_reservas); /*Actualiza o ficheiro de reservas*/
        }
        else /*N�o pode inserir a reserva*/
        {
            system("cls");
            printf("\n\t\tMARCA��O DE PR�-RESERVA");
            printf("\n\nHor�rio ocupado!\n\nO que deseja fazer?\n\n");
            printf("\t\t1-Marcar Pr�-reserva.\n");
            printf("\t\t2-Marcar para outra hora.\n");
            printf("\t\t3-N�o fazer marca��o. Voltar para o men� principal.\n");
            printf("\n\n Escolha o que deseja:\n");
            escolha=verifica_int_menu();
            switch (escolha)
            {
                case 1: system("cls");insere_pre_reserva(lista_pre_reservas,no);break;
                case 2: system("cls");dados_reserva(lista_clientes,lista_reservas,lista_pre_reservas,tipo);break;
                case 3: system("cls");break;
                default:printf("\n\n\t\t****ERRO - Tem de inserir uma op��o v�lida!****\n\n");
            }
        }
    }
}

/* Insere um n� (nova reserva) na lista de reservas; lista ordenada da data e horas mais antigas para as mais recentes*/
void insere_reserva (lista2 lista_reservas,lista2 no)
{
    lista2 ant,actual;
    int ptr[2];
    ant = lista_reservas;
    actual = lista_reservas->next;
    ptr[0]=no->data;
    ptr[1]=no->horas_inicio;
    if (actual==NULL) /*Quando a lista est� vazia*/
    {
        no->next=NULL; /*Acrescenta o novo n� no fim*/
        ant->next=no;
        free(actual);
        if(verifica_reserva(lista_reservas,ptr))
        {
            system("cls");
            printf("\nA reserva foi inserida!\n\n");
        }
        else
        {
            system("cls");
            printf("\nOcorreu um erro! Tente novamente!\n\n");
        }
        return;
    }
    if(actual->data>no->data) /*Se a data do primeiro elemento da lista for maior que a data da reserva que queremos inserir*/
    {
        no->next = ant->next; /*Insere a nova reserva no in�cio da lista*/
        ant->next = no;
        if(verifica_reserva(lista_reservas,ptr))
        {
            system("cls");
            printf("\nA reserva foi inserida!\n\n");
        }
        else
        {
            system("cls");
            printf("\nOcorreu um erro! Tente novamente!\n\n");
        }
    }
    else /*Se a data do elemento da lista for menor ou igual ao da reserva que queremos inserir*/
    {
        while (actual!= NULL && (actual->data < no->data)) /*Enquanto a data dos elementos da lista for menor, avan�a*/
        {
            ant = actual;
            actual = actual->next;
        }
        while (actual!= NULL && actual->horas_inicio<no->horas_inicio && actual->data==no->data) /*Enquanto a data do elemento da lista for igual � da reserva que queremos inserir e as horas forem menores (mais antigas), avan�a*/
        {
            ant = actual;
            actual = actual->next;
        }
        no->next = ant->next; /*Insere o n� na lista quando o elemente seguinte tiver umas horas maiores*/
        ant->next = no;
        if(verifica_reserva(lista_reservas,ptr))
        {
            system("cls");
            printf("\n\nLista de reservas atualizada!\n\n");
        }
        else
        {
            system("cls");
            printf("\n\nOcorreu um erro! Tente novamente!\n\n");
        }
    }
}

/* Insere um n� (nova pr�-reserva) na lista de pr�-reservas; lista ordenada da data mais antiga
para a mais recente e dentro de cada dia ordenada pela ordem por que s�o inseridas as pr�-reservas*/
void insere_pre_reserva (lista2 lista_pre_reservas, lista2 no)
{
    lista2 ant, actual;
    int ptr[4];
    ant = lista_pre_reservas;
    actual = lista_pre_reservas->next;
    while (actual!=NULL  && (actual->data)<=no->data) /*Percorre a lista at� encontrar uma data maior do que a que quer inserir*/
    {
        ant=actual;
        actual=actual->next;
    }
    no->next=ant->next; /*Ao encontrar, insere o n� entre esse (actual) e o anterior ao encontrado(ant)*/
    ant->next=no;
    ptr[0]=no->num_cliente; /*Passa par�metros para um vector para fazer a verifica��o*/
    ptr[1]=no->tipo;
    ptr[2]=no->data;
    ptr[3]=no->horas_inicio;
    if (verifica_pre_reserva(lista_pre_reservas,ptr))
    {
        system("cls");
        printf("\n\nA sua Pr�-Reserva foi inserida!\n\n");
    }
    else
    {
        system("cls");
        printf("\n\nOcorreu um erro! Tente novamente!\n\n");
    }
    escrever_pre_reservas(lista_pre_reservas); /*Actualiza o ficheiro das pr�-reservas*/

}

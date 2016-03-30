#include "clientes.h"

/*##################################
  #           Clientes             #
  ##################################*/

/*Insere um nó com os dados de um novo cliente no fim da lista de clientes*/
void insere_cliente (lista1 lista_clientes,lista1 no)
{
    lista1 ant,actual;
    ant = lista_clientes;
    actual = lista_clientes->next;
    while (actual != NULL) /*Enquanto não chega ao fim da lista avança*/
    {
        ant = actual;
        actual = actual->next;
    }
    no->next = ant->next; /*Quando chega ao fim, acrescenta o no (novo cliente)*/
    ant->next = no;
    escrever_clientes(lista_clientes); /*Actualiza o ficheiro "clientes.txt"*/
}

/*Procura o nº do último cliente da lista para posteriormente lhe somar 1 dando origem ao nº do cliente seguinte*/
int procura_numero(lista1 lista_clientes)
{
    lista1 ant, actual;
    ant = lista_clientes; actual = lista_clientes->next;
    while (actual!= NULL) /*Percorre a lista de clientes até ao fim*/
    {
        ant = actual;
        actual = actual->next;
    }
    return ant->cliente.num_cliente; /*Devolve o nº do último cliente da lista (último cliente adicionado)*/

}

/*Pede ao utilizador o nº de telefone e verifica se é válido*/
void inserir_tlm(char ptr[])
{
    int i,j;
    printf("Introduza o telefone do cliente: ");
    scanf(" %[^(\n)]",ptr); /*lê o texto até à primeira mudança de linha, '\n'*/
    for (i=0;i<9;i++)
    {
        if(!isdigit(ptr[i]))    /*Verifica se todos os caracteres inseridos são dígitos*/
        {
            j=1;
        }
    }
    if (strlen(ptr)!=9 || j==1)
    {
        printf("\n\n\tNúmero de telefone errado! O número tem de ter 9 dígitos.\n\tVolte a inserir, por favor.\n\n");
        inserir_tlm(ptr);
    }

}

/*Verifica se o novo cliente foi inserido na lista de clientes*/
int verifica_insere_cliente(lista1 lista_clientes,int num_cliente)
{
    lista1 aux;
    aux = lista_clientes->next;
    while(aux!=NULL)
    {
        if (aux->cliente.num_cliente==num_cliente)
        {
            return 1;   /*1 -> O cliente foi inserido*/
        }
        aux=aux->next;
    }
    return 0;   /*0 -> O cliente não foi inserido*/
}

/*Pede dados ao utilizador para um novo cliente*/
void dados_cliente (lista1 lista_clientes)
{
    lista1 no;
    char telefone[MAX]; /*A dimensão do vector é MAX, para o caso de o utilizador se enganar e inserir mais de 9 dígitos*/
    int indice=procura_numero(lista_clientes)+1; /*Calcula o novo nº de cliente*/
    no = (lista1) malloc (sizeof (node_clientes));
    if (no != NULL)
    {
        printf("\n\t\t NOVA FICHA DE CLIENTE\n\n");
        printf("\nO seu numero de cliente é: %.3d\n",indice);
        no->cliente.num_cliente=indice;
        printf("Introduza o nome do cliente: ");
        scanf(" %[^(\n)]",no->cliente.nome_cliente);
        inserir_tlm(&telefone);
        strcpy(no->cliente.num_tlf,telefone);
        insere_cliente(lista_clientes,no);
        if (verifica_insere_cliente(lista_clientes,no->cliente.num_cliente))
        {
            system("cls");
            printf("\n\t\t A FICHA DE CLIENTE FOI GERADA! \n\t\t O Nº DE CLIENTE É: %.3d\n\n\n",no->cliente.num_cliente);
        }
        else
        {
            printf("\n\t\t OCOREU UM ERRO! TENTE DE NOVO!");
        }

     }
}
/*Imprime a lista de clientes completa*/
void imprime_clientes (lista1 lista_clientes)
{
    lista1 aux = lista_clientes->next; /*saltar o header da lista*/
    printf("\n\t LISTA DE CLIENTES \n");
    if (aux==NULL)
    {
        printf("\n\nA lista de clientes está vazia!\n\n");
    }
    while (aux!=NULL)
    {
        printf("\nNúmero de cliente: %.3d \n",aux->cliente.num_cliente);
        printf("Nome de cliente: %s \n", aux->cliente.nome_cliente);
        printf("Telemovel do cliente: %s \n\n", aux->cliente.num_tlf);
        aux=aux->next; /*Avança para o próximo cliente*/

    }
}
/*associa nome_cliente ao num_cliente*/
void associa_nome_cliente(lista1 lista_clientes, char *nome, int num)
{
    lista1 aux=lista_clientes->next;
    while (aux!=NULL && aux->cliente.num_cliente!=num)
    {
        aux=aux->next;
    }
    strcpy(nome,aux->cliente.nome_cliente);
}


 #include "ficheiros_leitura.h"

 /*################################
  # Ficheiros - Leitura - Clientes #
  ##################################*/
 /*Cria um nó com as informações do ficheiro de clientes para o inserir na lista de clientes*/
void dados1(lista1 lista_clientes,int numero, char *telefone, char nome[])
{
    lista1 no;
    no = (lista1) malloc (sizeof (node_clientes));
    if (no != NULL)
    {
        no->cliente.num_cliente=numero;
        strcpy(no->cliente.nome_cliente,nome);
        strcpy(no->cliente.num_tlf,telefone);
        insere_cliente(lista_clientes,no);
    }
}

/*Lê o ficheiro 'clientes.txt'*/
void ler_clientes(lista1 lista_clientes)
{
    FILE *f= fopen("clientes.txt","r");
    char frase[100],nome[MAX],telefone[10];
    int numero;
    if (f!=NULL)
    {
        while (fgets(frase,100,f)!=NULL)
        {
            numero=atoi(frase); /*numero de cliente*/
            fgets(frase,100,f);
            frase[strlen(frase) - 1] = '\0';
            strcpy(nome,frase); /*nome de cliente*/
            fgets(frase,100,f);
            frase[strlen(frase) - 1] = '\0';
            strcpy(telefone,frase); /*numero telefone*/
            dados1(lista_clientes,numero,telefone,nome);
        }
    }
    fclose(f);

}

/*################################################
  # Ficheiros - Leitura - Reservas e Pré-Reservas#
  ################################################*/
  /*Insere o nó criado na lista de reservas/pré-reservas*/
void insere_reservas_lista(lista2 lista,lista2 no)
{
    lista2 ant, actual;
    ant=lista;
    actual=lista->next;
    while (actual != NULL)
    {
        ant = actual;
        actual = actual->next;
    }
    no->next = ant->next;
    ant->next = no;


}

 /*Cria um nó com as informações do ficheiro de reservas/pré-reservas para o inserir na lista de reservas/pré-reservas*/
void dados2(lista2 lista,int *ptr, char *matricula)
{
    lista2 no;
    no = (lista2) malloc (sizeof (node_reservas));
    if (no != NULL)
    {
        no->num_cliente=ptr[0];
        strcpy(no->matricula,matricula);
        no->horas_inicio=ptr[1];
        no->horas_fim=ptr[2];
        no->data=ptr[3];
        no->tipo=ptr[4];
    }
    insere_reservas_lista(lista,no);
}

/*Lê o ficheiro 'reservas.txt'*/
void ler_reservas(lista2 lista_reservas)
{
    FILE *f= fopen("reservas.txt","r");
    char frase[100],matricula[9];
    int ptr[5];
    if (f!=NULL)
    {
        while (fgets(frase,100,f)!=NULL)
        {
            ptr[0]=atoi(frase); /*Nº cliente*/
            fgets(frase,100,f);
            frase[strlen(frase)- 1] = '\0';
            strcpy(matricula,frase); /*matricula*/
            fgets(frase,100,f);
            ptr[1]=atoi(frase); /*hora inicio*/
            fgets(frase,100,f);
            ptr[2]=atoi(frase); /*hora fim*/
            fgets(frase,100,f);
            ptr[3]=atoi(frase); /*data*/
            fgets(frase,100,f);
            ptr[4]=atoi(frase); /*tipo: manut ou lav*/
            dados2(lista_reservas,ptr,matricula);
        }
    }
    fclose(f);
}

/*Lê o ficheiro 'pre_reservas.txt'*/
void ler_pre_reservas(lista2 lista_pre_reservas)
{
    FILE *f= fopen("pre_reservas.txt","r");
    char frase[100],matricula[9];
    int ptr[5];
    if (f!=NULL)
    {
        while (fgets(frase,100,f)!=NULL)
        {
            ptr[0]=atoi(frase); /*Nº cliente*/
            fgets(frase,100,f);
            frase[strlen(frase)- 1] = '\0';
            strcpy(matricula,frase); /*matricula*/
            fgets(frase,100,f);
            ptr[1]=atoi(frase); /*hora inicio*/
            fgets(frase,100,f);
            ptr[2]=atoi(frase); /*hora fim*/
            fgets(frase,100,f);
            ptr[3]=atoi(frase); /*data*/
            fgets(frase,100,f);
            ptr[4]=atoi(frase); /*tipo: manut ou lav*/
            dados2(lista_pre_reservas,ptr,matricula);
        }

    }
    fclose(f);

}

#include "inserir_dados.h"
/*verifica se o que estamos a inserir é apenas um inteiro*/
int verifica_int_tipo()
{
    int num;
    char termo;
    while(scanf("%d%c", &num, &termo)!=2 || termo!='\n') /*verifica se inserimos um int seguido de um '\n'(mudança de linha)*/
    {
        printf("\n\nErro!\n\nInsira novamente: \n\n");
        do
        {
            scanf("%c",&termo);
        }while(termo != '\n');
    }
    return num; /*se inseriu correctamente o numero é devolvido*/
}
/*Pede ao utilizador o tipo de serviço (manutenção ou lavagem) e verifica se é válido*/
int inserir_tipo(void)
{
    int tipo;
    printf("\n\nIntroduza o tipo [Manutenção-100;Lavagem-30]: \n");
    tipo=verifica_int_tipo();
    if (tipo==100 || tipo==30)
    {
        return tipo; /*devolve o tipo, caso este seja inserido correctamente*/
    }
    else
    {
        printf("\n\nErro! Insira novamente, por favor.\n\n");
        inserir_tipo();
    }
}
/*verifica se o que estamos a inserir a data correctamente*/
int verifica_int_data (int num[])
{
    char termo;
    while(scanf("%d/%d/%d%c", &num[0],&num[1],&num[2], &termo)!=4 || termo!='\n')
    {
        printf("\n\nData inválida!\n\nInsira novamente (dd/mm/aaaa): ");
        do
        {
            scanf("%c",&termo);
        }while(termo != '\n');
    }

}
/*Pede ao utilizador a data e verifica se é válida*/
void inserir_data(int ptr[])
{
    int dia,mes,ano,y,t=0,num[3];
    printf("\nInsira a data (dd/mm/aaaa): ");
    verifica_int_data(&num);
    dia=num[0];
    mes=num[1];
    ano=num[2];
    *ptr=((ano*100)+mes)*100+dia;
    if (dia<0 || mes<0 || mes>12 || ano<0)
    {
        t=1;
    }
    else if ((mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12) && dia>31)
    {
        t=1;
    }
    else if ((mes==4 || mes==6 || mes==9 || mes==11) && dia>30)
    {
        t=1;
    }
    if (ano%400==0 || (ano%4==0 && ano%100!=0)) /*Ano é bissexto*/
    {
        y=1;
    }
    else    /*Ano não é bissexto*/
    {
        y=0;
    }
    if (y==1 && mes==2 && dia>29)
    {
        t=1; /*1-> data errada*/
    }
    else if (y==0 && mes==2 && dia>28)
    {
        t=1; /*1-> data errada*/
    }
    if (t==1)
    {
        printf("\n\nData errada!\n\nInsira nova data!");
        inserir_data(ptr);
    }

}
/*verifica se o que estamos a inserir as horas correctamente*/
int verifica_int_horas (int num[])
{
    char termo;
    while(scanf("%d:%d%c", &num[0], &num[1], &termo)!=3 || termo!='\n')
    {
        printf("\n\nHoras inválidas!\n\nInsira novamente (hh:mm): ");
        do
        {
            scanf("%c",&termo);
        }while(termo != '\n');
    }

}
/*Pede ao utilizador as horas e verifica se são válidas*/
void inserir_horas(int ptr[])
{
    int horas,minutos,minutos_novo,num[2];
    printf("\nInsira as horas (hh:mm): ");
    verifica_int_horas(&num);
    horas=num[0];
    minutos=num[1];
    ptr[0] = (horas*100)+minutos; /* DD/MM/AAAA -> AAAAMMDD*/
    /*Verifica se é uma manutenção (100) ou uma lavagem (30) para calcular a hora de fim*/
    if (ptr[2]==100)
    {
        ptr[1]=((horas+1)*100)+minutos;
    }
    else if (ptr[2]==30)
    {
        minutos_novo = minutos+30;
        if (minutos_novo>=60)
        {
            minutos_novo%=60;
            ptr[1]=((horas+1)*100)+minutos_novo;
        }
        else
        {
            ptr[1]=(horas*100)+minutos_novo;
        }
    }
    printf("%d",ptr[1]);
    /*Verifica se a hora inserida é válida*/
    if (ptr[0]<800 || ptr[1]>1800 || horas>24 || horas<0 || minutos<0 || minutos>60)
    {
        printf("\n\n\tHora inválida!\n");
        printf("\tHorário de funcionamento da Estação de Serviço: 8h-18h\n");
        inserir_horas(ptr);
    }

}

/*Verifica se a matrícula inserida é válida conforme o seu tipo*/
int verifica_matricula(int formato, char ptr2[])
{
    switch(formato)
    {
        case 1:
        {
            if (!isalpha(ptr2[0]) ||!isalpha(ptr2[1]) || !isdigit(ptr2[3]) || !isdigit(ptr2[4]) || !isdigit(ptr2[6]) || !isdigit(ptr2[7]) || strlen(ptr2)!=8 )
            {
               return 1;
            }
            break;
        }
        case 2:
        {
            if (!isdigit(ptr2[0]) ||!isdigit(ptr2[1]) || !isalpha(ptr2[3]) || !isalpha(ptr2[4]) || !isdigit(ptr2[6]) || !isdigit(ptr2[7]) || strlen(ptr2)!=8 )
            {
               return 1;
            }
            break;
        }
        case 3:
        {
             if (!isdigit(ptr2[0]) ||!isdigit(ptr2[1]) || !isdigit(ptr2[3]) || !isdigit(ptr2[4]) || !isalpha(ptr2[6]) || !isalpha(ptr2[7]) || strlen(ptr2)!=8 )
            {
               return 1;
            }
            break;
        }
    }
}

/*Pede ao utilizador a matrícula*/
void inserir_matricula(char ptr2[])
{
    int formato,teste;
    printf("\nEscolha o formato da sua matricula:");
    printf("\n\t\t1- XX.00.00");
    printf("\n\t\t2- 00.XX.00");
    printf("\n\t\t3- 00.00.XX\n");
    scanf("%d",&formato);
    switch(formato)
    {
        case 1:
            {
                printf("\nInsira a matricula (XX.00.00): ");
                scanf(" %[^(\n)]",ptr2);
                ptr2[0]=toupper(ptr2[0]); /*Para ter a certeza que as matrícula está em maiúsculas, caso o utilizador insira em minúsculas*/
                ptr2[1]=toupper(ptr2[1]);
                break;
            }
        case 2:
            {
                printf("\nInsira a matricula (00.XX.00): ");
                scanf(" %[^(\n)]",ptr2);
                ptr2[3]=toupper(ptr2[3]);
                ptr2[4]=toupper(ptr2[4]);
                break;
            }
        case 3:
            {
                printf("\nInsira a matricula (00.00.XX): ");
                scanf(" %[^(\n)]",ptr2);
                ptr2[6]=toupper(ptr2[6]);
                ptr2[7]=toupper(ptr2[7]);
                break;
            }
        default: printf("\n\n\t\t****ERRO - Tem de inserir uma opção válida!****\n\n");inserir_matricula(ptr2);
    }
    teste=verifica_matricula(formato,ptr2); /*Verifica se a matrícula é válida*/
    if (teste==1)
    {
        printf("\n\nMatricula errada!\n\nInsira novamente, por favor! ");
        inserir_matricula(ptr2);
    }
}
int verifica_int_cliente()
{
    int num;
    char termo;
    while(scanf("%d%c", &num, &termo)!=2 || termo!='\n')
    {
        printf("\n\nErro! Nº de cliente inválido!\n\nInsira novamente: \n\n");
        do
        {
            scanf("%c",&termo);
        }while(termo != '\n');
    }
    return num;
}
/*Pede ao utilizador o nº de cliente e verifica se existe na lista de clientes*/
int index_cliente(lista1 lista_clientes)
{
    lista1 aux;
    int i=0,num_cliente,j,h=0;
    char termo;
    aux=lista_clientes->next;
    printf("\n\nIntroduza o nº de cliente: ");
    num_cliente=verifica_int_cliente();
    while(aux!=NULL)
    {
        if(aux->cliente.num_cliente==num_cliente)
        {
            i=1; /* i=1 se o cliente existir*/
        }
        aux=aux->next;
    }
    if(i==0)
    {
        system("cls");
        printf("\n\nCliente não existente!\n");
        index_cliente(lista_clientes);
    }
    else
    {
        return num_cliente;
    }
}

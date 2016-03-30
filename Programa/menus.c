#include "menus.h"
/*##################################
  #              Menus             #
  ##################################*/
int verifica_int_menu()
{
    int num;
    char termo;
    while(scanf("%d%c", &num, &termo)!=2 || termo!='\n')
    {
        printf("\n\n\t\t****ERRO - Tem de inserir uma opção válida!****\n\nEscolha o que deseja:\n");
        do
        {
            scanf("%c",&termo);
        }while(termo != '\n');
    }
    return num;
}

void menu(lista1 lista_clientes, lista2 lista_reservas, lista2 lista_pre_reservas)
{
    int escolha;
    while(escolha!=7)
    {
        printf("\t\t\t\tMENU\n");
        printf("\n\t\t1-Fazer reserva");
        printf("\n\t\t2-Cancelar reserva");
        printf("\n\t\t3-Cancelar pré-reserva");
        printf("\n\t\t4-Consultar horários");
        printf("\n\t\t5-Consultar clientes");
        printf("\n\t\t6-Lavagem/Manutenção efectuada");
        printf("\n\t\t7-Sair");
        printf("\n\n Escolha o que deseja:\n");
        escolha=verifica_int_menu();
        switch(escolha)
        {
            case 1: system("cls");submenu1_cliente(lista_clientes,lista_reservas,lista_pre_reservas);break;
            case 2: system("cls");elimina_reserva(lista_clientes,lista_reservas,lista_pre_reservas);break;
            case 3: system("cls");elimina_pre_reserva(lista_clientes,lista_pre_reservas);break;
            case 4: system("cls");submenu2_listar(lista_clientes,lista_reservas,lista_pre_reservas);break;
            case 5: system("cls");imprime_clientes(lista_clientes);break;
            case 6: system("cls");efectua_reserva(lista_reservas,lista_pre_reservas);break;
            case 7: sair(lista_clientes,lista_reservas,lista_pre_reservas);exit(0);
            default:printf("\n\n\t\t****ERRO - Tem de inserir uma opção válida!****\n\n");
        }
    }
}

void submenu1_cliente(lista1 lista_clientes, lista2 lista_reservas,lista2 lista_pre_reservas)
{
    int escolha;
    printf("\t\t\t\tFAZER RESERVA\n");
    printf("\n\t\t1-Novo cliente");
    printf("\n\t\t2-Cliente existente");
    printf("\n\t\t3-Voltar ao Menu principal");
    printf("\n\t\t4-Sair");
    printf("\n\n Escolha o que deseja:\n");
    escolha=verifica_int_menu();
    switch (escolha)
    {
        case 1: system("cls");dados_cliente(lista_clientes);submenu1_reservar(lista_clientes,lista_reservas,lista_pre_reservas);break;
        case 2:
            {
                if(verifica_clientes(lista_clientes))
                {
                    system("cls");
                    submenu1_reservar(lista_clientes,lista_reservas,lista_pre_reservas);break;
                }else
                {
                    system("cls");
                    printf("\n\nNão existem clientes na lista!\nAo fazer a reserva crie um novo cliente.\n\n");
                    submenu1_cliente(lista_clientes,lista_reservas,lista_pre_reservas);
                    break;
                }

            }
        case 3: system("cls");break;
        case 4: sair(lista_clientes,lista_reservas,lista_pre_reservas);exit(0);
        default:printf("\n\n\t\t****ERRO - Tem de inserir uma opção válida!****\n\n");submenu1_cliente(lista_clientes,lista_reservas,lista_pre_reservas);
    }

}

void submenu1_reservar (lista1 lista_clientes, lista2 lista_reservas,lista2 lista_pre_reservas)
{
    int escolha;
    printf("\t\t\t\tFAZER RESERVA\n");
    printf("\n\t\t1-Reservar Manutenção");
    printf("\n\t\t2-Reservar Lavagem");
    printf("\n\t\t3-Voltar ao Menu principal");
    printf("\n\t\t4-Sair");
    printf("\n\n Escolha o que deseja:\n");
    escolha=verifica_int_menu();
    switch(escolha)
    {
        case 1: system("cls");dados_reserva(lista_clientes,lista_reservas,lista_pre_reservas,100);break;
        case 2: system("cls");dados_reserva(lista_clientes,lista_reservas,lista_pre_reservas,30);break;
        case 3: system("cls");break;
        case 4: sair(lista_clientes,lista_reservas,lista_pre_reservas);exit(0);
        default:printf("\n\n\t\t****ERRO - Tem de inserir uma opção válida!****\n\n");submenu1_reservar(lista_clientes,lista_reservas,lista_pre_reservas);
    }
}

void submenu2_listar (lista1 lista_clientes, lista2 lista_reservas,lista2 lista_pre_reservas)
{
    int escolha;
    printf("\t\t\t\tLISTAR HORÁRIOS\n");
    printf("\n\t\t1-Reservas");
    printf("\n\t\t2-Pré-Reservas");
    printf("\n\t\t3-Voltar ao Menu principal");
    printf("\n\t\t4-Sair");
    printf("\n\n Escolha o que deseja:\n");
    escolha=verifica_int_menu();
    switch(escolha)
    {
        case 1: system("cls");submenu3_listar_reservas(lista_clientes, lista_reservas, lista_pre_reservas);break;
        case 2: system("cls");submenu4_listar_prereservas(lista_clientes,lista_reservas,lista_pre_reservas);break;
        case 3: system("cls");break;
        case 4: sair(lista_clientes,lista_reservas,lista_pre_reservas);exit(0);
        default:printf("\n\n\t\t****ERRO - Tem de inserir uma opção válida!****\n\n");submenu2_listar(lista_clientes, lista_reservas, lista_pre_reservas);
    }
}

void submenu3_listar_reservas (lista1 lista_clientes, lista2 lista_reservas,lista2 lista_pre_reservas)
{
    int escolha;
    printf("\t\t\tLISTAR HORÁRIOS DE RESERVAS\n");
    printf("\n\t\t1-Completo");
    printf("\n\t\t2-Diário");
    printf("\n\t\t3-Cliente");
    printf("\n\t\t4-Retroceder");
    printf("\n\t\t5-Sair");
    printf("\n\n Escolha o que deseja:\n");
    escolha=verifica_int_menu();
    switch(escolha)
    {
        case 1: system("cls");imprime_reservas_completo(lista_clientes,lista_reservas,0);break;
        case 2: system("cls");imprime_reservas_diario(lista_clientes,lista_reservas,0);break;
        case 3: system("cls");pede_cliente(lista_clientes,lista_reservas,0);break;
        case 4: system("cls");submenu2_listar(lista_clientes,lista_reservas,lista_pre_reservas);break;
        case 5: sair(lista_clientes,lista_reservas,lista_pre_reservas);exit(0);
        default:printf("\n\n\t\t****ERRO - Tem de inserir uma opção válida!****\n\n");submenu3_listar_reservas(lista_clientes, lista_reservas, lista_pre_reservas);
    }
}

void submenu4_listar_prereservas (lista1 lista_clientes, lista2 lista_reservas, lista2 lista_pre_reservas)
{
    int escolha;
    printf("\t\t\tLISTAR HORÁRIOS DE PRÉ-RESERVAS\n");
    printf("\n\t\t1-Completo");
    printf("\n\t\t2-Diário");
    printf("\n\t\t3-Cliente");
    printf("\n\t\t4-Retroceder");
    printf("\n\t\t5-Sair");
    printf("\n\n Escolha o que deseja:\n");
    escolha=verifica_int_menu();
    switch(escolha)
    {
        case 1: system("cls");imprime_pre_reservas_completo(lista_clientes,lista_pre_reservas);break;
        case 2: system("cls");imprime_pre_reservas_diario(lista_clientes,lista_pre_reservas);break;
        case 3: system("cls");imprime_pre_reservas_cliente(lista_clientes,lista_pre_reservas);break;
        case 4: system("cls");submenu2_listar(lista_clientes, lista_reservas,lista_pre_reservas);break;
        case 5: sair(lista_clientes,lista_reservas,lista_pre_reservas);exit(0);
        default:printf("\n\n\t\t****ERRO - Tem de inserir uma opção válida!****\n\n");submenu4_listar_prereservas(lista_clientes, lista_reservas,lista_pre_reservas);
    }
}

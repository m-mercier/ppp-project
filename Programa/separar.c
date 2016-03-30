#include "separar.h"

/*Separa a data para imprimir: AAAAMMDD -> DD MM AAAA; ao ser inserida, a data � "convertida"
num n�mero s� (AAAAMMDD) para ser mais f�cil fazer compara��es*/
void separa_data(int ptr[])
{
    ptr[1]=ptr[0]%100;
    ptr[0]/=100;
    ptr[2]=ptr[0]%100;
    ptr[0]/=100;
    ptr[3]=ptr[0];
}

/*Separa as horas para imprimir: HHMM -> HH MM; ao serem inseridas, as horas s�o "convertidas"
num n�mero (HHMM) s� para ser mais f�cil fazer compara��es*/
void separa_horas (int ptr[])
{
    ptr[2]=ptr[0]%100;
    ptr[0]/=100;
    ptr[1]=ptr[0];
}

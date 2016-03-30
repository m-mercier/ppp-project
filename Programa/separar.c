#include "separar.h"

/*Separa a data para imprimir: AAAAMMDD -> DD MM AAAA; ao ser inserida, a data é "convertida"
num número só (AAAAMMDD) para ser mais fácil fazer comparações*/
void separa_data(int ptr[])
{
    ptr[1]=ptr[0]%100;
    ptr[0]/=100;
    ptr[2]=ptr[0]%100;
    ptr[0]/=100;
    ptr[3]=ptr[0];
}

/*Separa as horas para imprimir: HHMM -> HH MM; ao serem inseridas, as horas são "convertidas"
num número (HHMM) só para ser mais fácil fazer comparações*/
void separa_horas (int ptr[])
{
    ptr[2]=ptr[0]%100;
    ptr[0]/=100;
    ptr[1]=ptr[0];
}

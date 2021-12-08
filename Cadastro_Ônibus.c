#include <stdio.h>
#include <locale.h>

struct cadastro_onibus{
int poltronas;
char tipo_viagem[10];
int codigo_onibus;
char destino[20];
}x;

int main(){

setlocale(LC_ALL,"Portuguese");

printf("\nDigite o código do ônibus (001): ");
scanf("%d",&x.codigo_onibus);
printf("\nDigite o tipo de viagem que o ônibus realiza (Estadual ou Municipal): ");
scanf("%s",x.tipo_viagem);
printf("\nDigite o número de poltronas que o ônibus possui: ");
scanf("%d",&x.poltronas);
printf("\nDigite a cidade de destino do ônibus (Caxias-MA): ");
scanf("%s",&x.destino);

printf("\n O código do ônibus é %d, ele faz viagens do tipo %s, ele possui %d poltonas e o seu destino é %s\n",x.codigo_onibus,x.tipo_viagem,x.poltronas,x.destino);

return 0;
}

    
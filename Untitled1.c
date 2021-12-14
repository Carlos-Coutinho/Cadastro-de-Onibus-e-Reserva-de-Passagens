#include <stdio.h>
#include <locale.h>

struct cadastro_onibus
{
    int poltronas;
    char tipo_viagem[10];
    int codigo_onibus;
    char destino[45];
}x[];

int main()
{

    setlocale(LC_ALL, "Portuguese");

    int i,num_onibus;

    printf("Quantos ônibus você vai cadastrar? ");
    scanf("%d",&num_onibus);

    for (i = 0; i < num_onibus; i++)
    {
        printf("_______________");
        printf("\n Digite o código do ônibus (000): ");
        scanf("%d", &x[i].codigo_onibus);
        printf("\n Digite o tipo de viagem que o ônibus realiza (Estadual ou Municipal): ");
        scanf("%s", x[i].tipo_viagem);
        printf("\n Digite o número de poltronas que o ônibus possui: ");
        scanf("%d", &x[i].poltronas);
        printf("\n Digite a cidade de destino do ônibus (Caxias-MA): ");
        scanf("%s", &x[i].destino);}

        for (i = 0; i < num_onibus; i++){

        printf("\n O código do ônibus é %d, ele faz viagens do tipo %s, ele possui %d poltonas e o seu destino é %s\n", x[i].codigo_onibus, x[i].tipo_viagem, x[i].poltronas, x[i].destino);
    }

    return 0;
}

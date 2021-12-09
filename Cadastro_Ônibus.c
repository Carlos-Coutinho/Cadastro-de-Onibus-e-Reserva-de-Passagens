#include <stdio.h>
#include <locale.h>

# define indiceonibus 2 
struct cadastro_onibus
{
    int poltronas;
    char tipo_viagem[10];
    int codigo_onibus;
    char destino[20];
} x[indiceonibus];

int main()
{

    setlocale(LC_ALL, "Portuguese");

    int i;

    for (i = 0; i < indiceonibus; i++)
    {
        printf("_________________________________________");
        printf("\nDigite o código do ônibus (00%d): ",i);
        scanf("%d", &x[i].codigo_onibus);
        printf("\nDigite o tipo de viagem que o ônibus realiza (Estadual ou Municipal): ");
        scanf("%s", x[i].tipo_viagem);
        printf("\nDigite o número de poltronas que o ônibus possui: ");
        scanf("%d", &x[i].poltronas);
        printf("\nDigite a cidade de destino do ônibus (Caxias-MA): ");
        scanf("%s", &x[i].destino);

        printf("\n O código do ônibus é %d, ele faz viagens do tipo %s, ele possui %d poltonas e o seu destino é %s\n", x[i].codigo_onibus, x[i].tipo_viagem, x[i].poltronas, x[i].destino);
    }

    return 0;
}

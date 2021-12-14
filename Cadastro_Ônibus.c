#include <stdio.h>
#include <locale.h>

int n_onibus;

typedef struct
{
    int coluna;
    int linha;
} poltrona;

typedef struct
{
    int codigo_onibus;
    int tipo_onibus;
    poltrona p;
    char tipo_viagem[10];
    char destino[20];
} cadastro_onibus;

void menu()
{
    int menu_op;
    switch (menu_op)
    {
    case 1:
        cadastro_onibus_funcao();
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        system("exit");
        break;
    default:
        break;
    }
}
void cadastro_onibus_funcao()
{
    printf("\nDigite A Quantidade De ônibus:");
    scanf("%d", &n_onibus);
    cadastro_onibus vetor_onibus[n_onibus];
    int i;
    for (i = 0; i < n_onibus; i++)
    {
        printf("_________________________________________\n");
        printf("\n Digite O Código Do %d° Ônibus: ", i + 1);
        scanf("%d", &vetor_onibus[i].codigo_onibus);

        while (vetor_onibus[i].tipo_onibus > 2 || vetor_onibus[i].tipo_onibus < 1)
        {
            printf("\n Digite Um Número\n\n 1 - Micro-Ônibus\n 2 - Ônibus\n\n Tipo: ");

            scanf("%d", &vetor_onibus[i].tipo_onibus);

            switch (vetor_onibus[i].tipo_onibus)
            {
            case 1:
                vetor_onibus[i].p.linha = 7;
                break;
            case 2:
                vetor_onibus[i].p.linha = 10;
                break;
            }
        }

        fflush(stdin);
        printf("\n Digite o tipo de viagem que o ônibus realiza (Estadual ou Municipal): ");
        gets(vetor_onibus[i].tipo_viagem);
        printf("\n Digite a cidade de destino do ônibus (Caxias-MA): ");
        gets(vetor_onibus[i].destino);
        system("cls");
    }
    for (i = 0; i < n_onibus; i++)
    {
        printf("\n O código do ônibus é %d, ele faz viagens do tipo %s\nTipo: %d e o seu destino é %s\n", vetor_onibus[i].codigo_onibus, vetor_onibus[i].tipo_viagem, vetor_onibus[i].tipo_onibus, vetor_onibus[i].destino);
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    cadastro_onibus_funcao();
    return 0;
}

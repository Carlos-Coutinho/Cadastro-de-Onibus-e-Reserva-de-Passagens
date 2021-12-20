#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define total_onibus_vetor 50
#define total_passageiros_vetor 500

int n_onibus = 0;
int n_passageiros = 0;

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

typedef struct
{
    int codigo;
    char nome[50];
    char endereco[100];
    int cpf;
    poltrona p;
    int codigo_onibus;
} cadastro_passageiros;

cadastro_onibus vetor_onibus[total_onibus_vetor];
cadastro_passageiros vetor_passageiro[total_passageiros_vetor];

void menu()
{
    int menu_op;

    while (menu_op > 4 || menu_op < 1)
    {
        printf("\n\t---MENU---\n 01 - Cadastro De Onibus\n 02 - Reserva De Passagens\n 03 - Visualização De Poltronas\n 04 - Sair\n\n Digite Aqui:");
        scanf("%d", &menu_op);
        system("cls");
    }

    switch (menu_op)
    {
    case 1:
        cadastro_onibus_funcao();
        break;
    case 2:
        cadastro_passageiros_funcao();
        break;
    case 3:
        ocupacao_poltronas();
        break;
    case 4:
        printf("\nPrograma Finalizado!!\n");
        system("exit");
        break;
    }
}
int cadastro_onibus_funcao()
{
    for (n_onibus; n_onibus < total_onibus_vetor; n_onibus++)
    {
        char op = 'A';
        printf("\n\tCADASTRO DE ÔNIBUS\n\n");
        printf("__________________________________\n");
        printf("\n Digite O Código Do %d° Ônibus: ", n_onibus + 1);
        scanf("%d", &vetor_onibus[n_onibus].codigo_onibus);
        vetor_onibus->p.coluna = 4;

        while (vetor_onibus[n_onibus].tipo_onibus > 2 || vetor_onibus[n_onibus].tipo_onibus < 1)
        {
            printf("\n Digite Um Numero\n\n 1 - Micro-Ônibus\n 2 - Ônibus\n\n Tipo: ");
            scanf("%d", &vetor_onibus[n_onibus].tipo_onibus);
            switch (vetor_onibus[n_onibus].tipo_onibus)
            {
            case 1:
                vetor_onibus[n_onibus].p.linha = 7;
                break;
            case 2:
                vetor_onibus[n_onibus].p.linha = 10;
                break;
            }
        }

        fflush(stdin);
        while ((strcasecmp(vetor_onibus[n_onibus].tipo_viagem, "Estadual") != 0) && (strcasecmp(vetor_onibus[n_onibus].tipo_viagem, "Municipal") != 0))
        {
            fflush(stdin);
            printf("\n Digite O Tipo De Viagem Que O Ônibus Realiza (Estadual ou Municipal): ");
            gets(vetor_onibus[n_onibus].tipo_viagem);
        }
        printf("\n Digite a cidade de destino do Ônibus (Caxias-MA): ");
        gets(vetor_onibus[n_onibus].destino);

        while (op != 'Y')
        {
            printf(" Deseja Continuar? (Y/N):");
            scanf(" %c", &op);
            if (op == 'N')
            {
                system("cls");
                n_onibus++;
                menu();
            }
        }
        system("cls");
    }
}

int cadastro_passageiros_funcao()
{
    if (n_onibus == 0)
    {
        printf("\n\n\tRESERVAS FORA DO AR!\n\n\n");
        system("pause");
        system("cls");
        main(vetor_onibus, vetor_passageiro);
    }
    else
    {
        int i;
        for (n_passageiros; n_passageiros < total_passageiros_vetor; n_passageiros++)
        {
            vetor_passageiro[n_passageiros].codigo = n_passageiros + 1;
            char tipo_onibus[20] = "ABC", op = "A";
            fflush(stdin);
            printf("\n Digite O Nome Do Passageiro: ");
            gets(vetor_passageiro[n_passageiros].nome);
            printf("\n Digite O Endereço Do Passageiro: ");
            gets(vetor_passageiro[n_passageiros].endereco);
            fflush(stdin);
            while ((strcasecmp(tipo_onibus, "Estadual") != 0) && (strcasecmp(tipo_onibus, "Municipal") != 0))
            {
                fflush(stdin);
                printf("\n Digite O Tipo De Viagem Que O Ônibus Realiza (Estadual ou Municipal): ");
                gets(tipo_onibus);
            }
            for (i = 0; i <= n_onibus; i++)
            {
                fflush(stdin);
                if (strcasecmp(tipo_onibus, vetor_onibus[i].tipo_viagem) == 0)
                {
                    printf("\n %d - Tipo: %s Destino: %s\n", vetor_onibus[i].codigo_onibus, vetor_onibus[i].tipo_viagem, vetor_onibus[i].destino);
                }
            }
            fflush(stdin);
            while (op != 'Y')
            {
                printf("\n Deseja Continuar? (Y/N):");
                scanf("%c", &op);
                if (op == 'N')
                {
                    system("cls");
                    n_passageiros++;
                    menu();
                }
            }
            system("cls");
        }
    }
}

int ocupacao_poltronas()
{
    int menu_op, i;
    int matriz[4][2], j;
    while (menu_op > 3 || menu_op < 1)
    {
        printf("\n\tOCUPAÇÃO DE POLTRONAS\n\n01 - Lista A Ocupação De Todos Os Veículos\n02 - Veículo Específico\n03 - Retornar Ao Menu\n\nDigite Aqui:");
        scanf("%d", &menu_op);
        system("cls");
    }
    switch (menu_op)
    {
    case 1:
        printf("\n");
        for (j = 0; j < 10; j++)
        {
            for (i = 0; i < 2; i++)
            {
                printf("[ ] ");
            }
            printf("\t");
            for (i = 3; i < 5; i++)
            {
                printf("[ ] ");
            }
            printf("\n");
        }

        printf("\n");

        break;
    case 2:
        break;
    case 3:
        menu();
        break;
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    menu();
    return 0;
}

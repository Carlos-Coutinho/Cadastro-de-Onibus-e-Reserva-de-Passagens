#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include <string.h>

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
    int cpf;
    char endereco[100];
    int codigo_onibus;
    poltrona p;
} cadastro_passageiros;

void menu(cadastro_onibus vetor_onibus[n_onibus], cadastro_passageiros vetor_passageiro[n_passageiros],int count_passageiros)
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
        cadastro_onibus_funcao(vetor_onibus, vetor_passageiro,count_passageiros);
        break;
    case 2:
        cadastro_passageiros_funcao(vetor_onibus, vetor_passageiro,count_passageiros);
        break;
    case 3:
        ocupacao_poltronas(vetor_onibus, vetor_passageiro,count_passageiros);
        break;
    case 4:
        printf("\nPrograma Finalizado!!\n");
        system("exit");
        break;
    }
}
int cadastro_onibus_funcao(cadastro_onibus vetor_onibus[n_onibus], cadastro_passageiros vetor_passageiro[n_passageiros],int count_passageiros)
{
    for (n_onibus; n_onibus <= n_onibus; n_onibus++)
    {
        char op = 'A';
        printf("\n\tCADASTRO DE ÔNIBUS\n\n");
        printf("__________________________________\n");
        printf("\n Digite O Código Do %d° Ônibus: ", n_onibus);
        scanf("%d", &vetor_onibus[n_onibus].codigo_onibus);

        vetor_onibus[n_onibus].tipo_onibus = 0;
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
        printf("\n Digite O Tipo De Viagem Que O Ônibus Realiza (Estadual ou Municipal): ");
        gets(vetor_onibus[n_onibus].tipo_viagem);
        printf("\n Digite a cidade de destino do Ônibus (Caxias-MA): ");
        gets(vetor_onibus[n_onibus].destino);
        vetor_onibus[n_onibus].destino[strlen(vetor_onibus[n_onibus].destino)] = '\0';

        while (op != 'Y')
        {
            printf(" Deseja Continuar? (Y/N):");
            scanf(" %c", &op);
            if (op == 'N')
            {
                system("cls");
                n_onibus++;
                menu(vetor_onibus, vetor_passageiro,count_passageiros);
            }
        }
        system("cls");
    }
}

int cadastro_passageiros_funcao(cadastro_onibus vetor_onibus[n_onibus], cadastro_passageiros vetor_passageiro[n_passageiros],int count_passageiros)
{
    if (n_onibus == 0)
    {
        printf("\n\n\tRESERVAS FORA DO AR!\n\n\n");
        system("pause");
        system("cls");
        main(vetor_onibus,vetor_passageiro);
    }
    else
    {
        int i;
        char tipo_onibus[20], op;
        for (n_passageiros; n_passageiros <= n_passageiros; n_passageiros++)
        {
            op = "A";
            printf("\n %d \n",count_passageiros);
            fflush(stdin);
            printf("\n Digite O Nome Do Passageiro: ");
            gets(vetor_passageiro[count_passageiros].nome);
            printf("\n Digite O Endereço Do Passageiro: ");
            gets(vetor_passageiro[count_passageiros].endereco);
            fflush(stdin);
            count_passageiros++;
            printf("\n Digite O Tipo De Viagem Que O Ônibus Realiza (Estadual ou Municipal): ");
            gets(tipo_onibus);
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
                    menu(vetor_onibus, vetor_passageiro,count_passageiros);
                }
            }
            system("cls");
        }
    }
}

int ocupacao_poltronas(cadastro_onibus vetor_onibus[n_onibus], cadastro_passageiros vetor_passageiro[n_passageiros],int count_passageiros)
{
    int menu_op, i;
    while (menu_op > 3 || menu_op < 1)
    {
        printf("\n\tOCUPAÇÃO DE POLTRONAS\n\n01 - Lista A Ocupação De Todos Os Veículos\n02 - Veículo Específico\n03 - Retornar Ao Menu\n\nDigite Aqui:");
        scanf("%d", &menu_op);
        system("cls");
    }
    switch (menu_op)
    {
    case 1:
        for (i = 1; i <= n_onibus; i++)
        {
            printf("%s\n", vetor_onibus[i].destino);
        }
        break;
    case 2:
        break;
    case 3:
        menu(vetor_onibus, vetor_passageiro,count_passageiros);
        break;
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    cadastro_passageiros vetor_passageiro[n_passageiros];
    cadastro_onibus vetor_onibus[n_onibus];
    int count_passageiros = 0;
    menu(vetor_onibus, vetor_passageiro,count_passageiros);
    return 0;
}

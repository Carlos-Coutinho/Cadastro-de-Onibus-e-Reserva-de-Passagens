#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

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
    int vagas;
} cadastro_onibus;

typedef struct
{
    int codigo;
    char nome[50];
    char endereco[100];
    int cpf;
    int codigo_onibus;
} cadastro_passageiros;

cadastro_onibus vetor_onibus[total_onibus_vetor];
cadastro_passageiros vetor_passageiro[total_passageiros_vetor];

void menu()
{
    int menu_op;

    while (menu_op > 4 || menu_op < 1)
    {
        printf("\n\t---MENU---\n 01 - Cadastro De Onibus\n 02 - Reserva De Passagens\n 03 - Visualização De Poltronas\n 04 - Sair\n\n Digite Aqui: ");
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
    if (n_onibus == total_onibus_vetor)
    {
        printf("\n\n\tLIMITE ALCANÇADO\n\n");
        system("pause");
        system("cls");
        main();
    }
    else
    {
        for (n_onibus; n_onibus < total_onibus_vetor; n_onibus++)
        {
            int vetor_codigo_onibus[total_onibus_vetor], i, verificador = 0;
            char op = 'A';
            printf("\n\tCADASTRO DE ÔNIBUS\n\n");
            printf("__________________________________\n");

            do
            {
                printf("\n Digite O Código Do %d° Ônibus: ", n_onibus + 1);
                scanf("%d", &vetor_onibus[n_onibus].codigo_onibus);
                for (i = n_onibus - 1; i >= 0; i--)
                {
                    if (vetor_onibus[n_onibus].codigo_onibus == vetor_onibus[i].codigo_onibus)
                    {
                        printf("\nCódigo Em Utilização!!\n");
                        verificador = 1;
                    }
                    else
                    {
                        verificador = 0;
                    }
                }
            } while (verificador == 1);

            while (vetor_onibus[n_onibus].tipo_onibus > 2 || vetor_onibus[n_onibus].tipo_onibus < 1)
            {
                printf("\n Digite Um Numero\n\n 1 - Micro-Ônibus\n 2 - Ônibus\n\n Tipo: ");
                scanf("%d", &vetor_onibus[n_onibus].tipo_onibus);
                vetor_onibus[n_onibus].p.coluna = 4;
                switch (vetor_onibus[n_onibus].tipo_onibus)
                {
                case 1:
                    vetor_onibus[n_onibus].p.linha = 7;
                    vetor_onibus[n_onibus].vagas = 28;
                    break;
                case 2:
                    vetor_onibus[n_onibus].p.linha = 10;
                    vetor_onibus[n_onibus].vagas = 40;
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
                printf(" Deseja Continuar? (Y/N): ");
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
        int i, codigo_onibus_vetor[total_onibus_vetor], codigo_onibus_vetor_indice[total_onibus_vetor];
        for (n_passageiros; n_passageiros < total_passageiros_vetor; n_passageiros++)
        {
            int j = 0, count_codigos, tipo_onibus = 0, verificador = 0;
            vetor_passageiro[n_passageiros].codigo = n_passageiros + 1;
            char op = "A";
            fflush(stdin);
            printf("\n Digite O Nome Do Passageiro: ");
            gets(vetor_passageiro[n_passageiros].nome);
            printf("\n Digite O Endereço Do Passageiro: ");
            gets(vetor_passageiro[n_passageiros].endereco);
            fflush(stdin);
            while (verificador == 0)
            {
                char tipo_viagem[20] = "ABC";
                while (tipo_onibus > 2 || tipo_onibus < 1)
                {
                    printf("\n Defina O Tipo De Onibus Que Deseja Realizar\n\n 1 - Micro-Onibus\n 2 - Ônibus\n\n Digite Aqui: ");
                    scanf("%d", &tipo_onibus);
                }
                while ((strcasecmp(tipo_viagem, "Estadual") != 0) && (strcasecmp(tipo_viagem, "Municipal") != 0))
                {
                    fflush(stdin);
                    printf("\n Digite O Tipo De Viagem Que Deseja Realizar (Estadual ou Municipal): ");
                    gets(tipo_viagem);
                }
                for (i = 0; i <= n_onibus; i++)
                {
                    fflush(stdin);
                    if (strcasecmp(tipo_viagem, vetor_onibus[i].tipo_viagem) == 0 && tipo_onibus == vetor_onibus[i].tipo_onibus)
                    {
                        if (vetor_onibus[i].vagas > 0)
                        {
                            verificador++;
                            codigo_onibus_vetor_indice[j] = i;
                            codigo_onibus_vetor[j] = vetor_onibus[i].codigo_onibus;
                            j++;
                            printf("\n %d - Tipo: %s - Destino: %s - Vagas: %d", vetor_onibus[i].codigo_onibus, vetor_onibus[i].tipo_viagem, vetor_onibus[i].destino, vetor_onibus[i].vagas);
                        }
                    }
                }
                if (verificador == 0)
                {
                    printf("\n Nenhuma Ônibus Listado Com Essas Caracteríticas. Por Favor, Recomeçar!\n");
                    tipo_onibus = 0;
                }
            }
            verificador = 1;
            while (verificador != 0)
            {
                printf("\n\n Digite O Código Do Ônibus Desejado: ");
                scanf("%d", &vetor_passageiro[n_passageiros].codigo_onibus);
                for (count_codigos = 0; count_codigos < j; count_codigos++)
                {
                    if (vetor_passageiro[n_passageiros].codigo_onibus == codigo_onibus_vetor[count_codigos])
                    {
                        verificador = 0;
                        vetor_onibus[codigo_onibus_vetor_indice[count_codigos]].vagas--;
                        printf("\n Ônibus %d Definido!\n", vetor_passageiro[n_passageiros].codigo_onibus);
                    }
                    else
                    {
                        printf("\n Código Inválido - Escolha Um Dos Códigos Listados!\n");
                    }
                }
            }

            fflush(stdin);
            while (op != 'Y')
            {
                printf("\n Deseja Continuar? (Y/N): ");
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
    int menu_op, i = 8;
    int matriz[4][2], j;
    while (menu_op > 3 || menu_op < 1)
    {
        printf("\n\tOCUPAÇÃO DE POLTRONAS\n\n01 - Lista A Ocupação De Todos Os Veículos\n02 - Veículo Específico\n03 - Retornar Ao Menu\n\nDigite Aqui: ");
        scanf("%d", &menu_op);
        system("cls");
    }
    switch (menu_op)
    {
    case 1:

        printf("\n");
        for (j = 1; j <= 40; j++)
        {
            if (i > 0)
            {
                printf("[ O ]");
                i--;
            }
            else
            {
                printf("[ L ]");
            }
            if (j % 4 == 0)
            {
                printf("\n");
            }
            else if (j % 2 == 0)
            {
                printf("\t");
            }
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

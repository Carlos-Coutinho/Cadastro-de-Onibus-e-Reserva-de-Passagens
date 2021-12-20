#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
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
    poltrona p;
    int codigo_onibus;
} cadastro_passageiros;

void menu(cadastro_onibus vetor_onibus[n_onibus], cadastro_passageiros vetor_passageiro[n_passageiros],int count_cadastro_passageiros)
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
        cadastro_onibus_funcao(vetor_onibus, vetor_passageiro);
        break;
    case 2:
        cadastro_passageiros_funcao(vetor_onibus,vetor_passageiro,count_cadastro_passageiros);
        break;
    case 3:
        ocupacao_poltronas(vetor_onibus, vetor_passageiro);
        break;
    case 4:
        printf("\nPrograma Finalizado!!\n");
        system("exit");
        break;
    }
}
int cadastro_onibus_funcao(cadastro_onibus vetor_onibus[n_onibus], cadastro_passageiros vetor_passageiro[n_passageiros])
{
    n_onibus++;
    for (n_onibus - 1; n_onibus - 1 < n_onibus; n_onibus++)
    {
        char op = 'A';
        printf("\n\tCADASTRO DE ÔNIBUS\n\n");
        printf("__________________________________\n");
        printf("\n Digite O Código Do %d° Ônibus: ", n_onibus);
        scanf("%d", &vetor_onibus[n_onibus - 1].codigo_onibus);

        vetor_onibus[n_onibus - 1].tipo_onibus = 0;
        while (vetor_onibus[n_onibus - 1].tipo_onibus > 2 || vetor_onibus[n_onibus - 1].tipo_onibus < 1)
        {
            printf("\n Digite Um Numero\n\n 1 - Micro-Ônibus\n 2 - Ônibus\n\n Tipo: ");
            scanf("%d", &vetor_onibus[n_onibus - 1].tipo_onibus);
            switch (vetor_onibus[n_onibus - 1].tipo_onibus)
            {
            case 1:
                vetor_onibus[n_onibus - 1].p.linha = 7;
                break;
            case 2:
                vetor_onibus[n_onibus - 1].p.linha = 10;
                break;
            }
        }

        fflush(stdin);
        printf("\n Digite O Tipo De Viagem Que O Ônibus Realiza (Estadual ou Municipal): ");
        gets(vetor_onibus[n_onibus - 1].tipo_viagem);
        printf("\n Digite a cidade de destino do Ônibus (Caxias-MA): ");
        gets(vetor_onibus[n_onibus - 1].destino);

        while (op != 'Y')
        {
            printf(" Deseja Continuar? (Y/N):");
            scanf("%c");
            scanf(" %c", &op);
            if (op == 'N')
            {
                system("cls");
                return 0;
                menu(vetor_onibus, vetor_passageiro,NULL);
            }
        }
        return 0;
        system("cls");
    }
}

int cadastro_passageiros_funcao(cadastro_passageiros vetor_passageiro[n_passageiros],cadastro_onibus vetor_onibus[n_onibus],int count_cadastro_passageiros)
{
    n_passageiros++;
    for (n_passageiros;n_passageiros<=n_passageiros;n_passageiros++)
    {
        int teste = n_passageiros-1;
        printf("%d e %d",n_passageiros,teste);
        printf("Digite Seu Nome:");
        gets(vetor_passageiro[teste].nome);
    }
}

int ocupacao_poltronas(cadastro_onibus vetor_onibus[n_onibus], cadastro_passageiros vetor_passageiro[n_passageiros])
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
        menu(vetor_onibus, vetor_passageiro,NULL);
        break;
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    cadastro_passageiros vetor_passageiro[n_passageiros];
    cadastro_onibus vetor_onibus[n_onibus];
    menu(vetor_onibus, vetor_passageiro,0);
    return 0;
}

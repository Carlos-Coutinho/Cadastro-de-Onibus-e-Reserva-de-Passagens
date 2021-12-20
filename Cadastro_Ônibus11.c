#include<stdio.h>
#include<locale.h>

int main(void)
{
    setlocale(LC_ALL,"Portuguese");
    int n_alunos=1,i=0;

    printf("\nBem Vindo Ao Cadastro De Nota!\n");
//Vetor De Estrutura Para Oraganizar Cada Aluno Na Sua Devida Ficha Com Tamanho De n_alunos Que Iniciará Em 1 Para Indice 0
    struct ficha_aluno
    {
        char nome[50];
        float nota_prova1;
        float nota_prova2;
        float media;
    }boletim[n_alunos];
//For Com Contagem Progressiva A Cada Loop Com Condição De Parada No Valor Da Nota 1 Para O Respectivo Indice Representado Pela Variavel i
    for (n_alunos;boletim[i].nota_prova1!=50;n_alunos++)
    {
        printf("\nDigite O Nome Do %d° Aluno:",i+1);
        fflush(stdin); //Limpeza Do Buffer Do Teclado
        gets(boletim[i].nome);
        printf("Digite A Primeira Nota Do Aluno:");
        scanf("%f",&boletim[i].nota_prova1);
//Teste De Valor De Parada E Limitante Para Nota 1
        if (boletim[i].nota_prova1==50)
        break;
        else
        {
            while (boletim[i].nota_prova1<0 || boletim[i].nota_prova1>10)
            {
                printf("Digite Novamente A Primeira Nota:");
                scanf("%f",&boletim[i].nota_prova1);
            }
        }
        printf("Digite A Segunda Nota:");
        scanf("%f",&boletim[i].nota_prova2);
//Inicio Do Limitante Para A Nota 2
        while (boletim[i].nota_prova2<0 || boletim[i].nota_prova2>10)
        {
            printf("Digite Novamente A Segunda Nota:");
            scanf("%f",&boletim[i].nota_prova2);
        }
//Calculo E Atribuição De Média Para O Vetor De Estrutura Correspondente Ao Indice
        boletim[i].media = (boletim[i].nota_prova1 + boletim[i].nota_prova2)/2;
        printf("A Média Do Aluno Foi: %.2f\n", boletim[i].media);
        i++; //Acrescimetno Do Indice Com Inicio 0 A Cada Loop
    }
// Após Ser Digitado 50 Para A Primeira Nota Do Aluno Já Exibirá O Boletim Completo Desconsiderando O Aluno Com Nota 1 = 50
    printf("\n--------------- Boletim ---------------\n");
    for ( i = 0; i < n_alunos-1; i++)
    {
        printf("\n------- Aluno %d -------",i+1);
        printf("\nNome Do Aluno: %s",boletim[i].nome);
        printf("\nPrimeira Nota: %.2f",boletim[i].nota_prova1);
        printf("\nSegunda Nota: %.2f",boletim[i].nota_prova2);
        printf("\nMédia Do Aluno: %.2f\n",boletim[i].media);
    }
}
// O Codigo Só Irá Parar Com O Valor 50 Sem Limite Para O Número De Alunos
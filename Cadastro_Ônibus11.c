#include <stdio.h>
#include <locale.h>

# define indiceonibus 2 
struct cadastro_onibus
{
    int poltronas;
    char tipo_viagem[10];
    int codigo_onibus;
    char destino[20];
    int ocupados[4] [4];
    char escolha;
    
} x[indiceonibus];

int main()
{

    int i;
    for (i = 0; i < indiceonibus; i++);
    
	{

        printf("\nDigite o codigo do Onibus (00%d): ",i);
        scanf("%d",&x[i].codigo_onibus);
        printf("\nDigite o tipo de viagem que o Onibus realiza (Estadual ou Municipal): ");
        scanf("%s",&x[i].tipo_viagem);
        printf("\nDigite o numero de poltronas que o Onibus possui: ");
        scanf("%d",&x[i].poltronas);
        printf("\nDigite a cidade de destino do Onibus (Teresina-PI): ");
        scanf("%s",&x[i].destino);
        printf("\nDesejo continuar?<s/n");
        scanf("%d",&x[i].);
        
        printf("\n O codigo do Onibus%d, ele faz viagens do tipo %s, ele possui %d poltonas e o seu destino %s\n", x[i].codigo_onibus, x[i].tipo_viagem, x[i].poltronas, x[i].destino);
    }

    return 0;
}

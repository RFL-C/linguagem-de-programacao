#include <stdio.h>
#include <stdlib.h>
#define MAX 100

float calcularMedia(float valorTotal[], int indiceInscricao) {
    float valorTotalGeral = 0;
    for (int j = 0; j < indiceInscricao; j++) {
        valorTotalGeral += valorTotal[j];
    }
    float mediaGeral = valorTotalGeral / indiceInscricao;
    return mediaGeral;
}

float calcularMediaSvcExclusivo(int indiceInscricao, int svcBebidas[], float valorTotal[]) {
    float somaSvcExclusivo = 0, mediaSvcExclusivo;
    int contador = 0;
    for (int j = 0; j<indiceInscricao; j++) {
        if (svcBebidas[j] == 1) {
            somaSvcExclusivo += valorTotal[j];
            contador++;
        }
    }
    return mediaSvcExclusivo = somaSvcExclusivo / contador;
}

int nInscricaoMaiorValor(int i, int numeroInscricao[], float valorTotal[]) {
    int numeroInscricaoCalculo[MAX];
    float valorTotalCalculo[MAX], aux;
    for (int j = 0; j<i; j++)
            {
            numeroInscricaoCalculo[j] = numeroInscricao[j];
            valorTotalCalculo[j] = valorTotal[j];
            }
            for (int j = 0; j<i; j++) {
                for (int k = 0; k<i-1; k++) {
                    if (valorTotalCalculo[k] < valorTotalCalculo[k+1]){
                        aux = valorTotalCalculo[k];
                        valorTotalCalculo[k] = valorTotalCalculo[k+1];
                        valorTotalCalculo[k+1] = aux;

                        aux = numeroInscricaoCalculo[k];
                        numeroInscricaoCalculo[k] = numeroInscricaoCalculo[k+1];
                        numeroInscricaoCalculo[k+1] = aux;
                    }
                }
            }
    return numeroInscricaoCalculo[0];
}

float porcentagemBuffet(int indiceInscricao, int tipoBuffet[]) {
    int contadorBuffet = 0;
    float porcentagem;
    for (int j = 0; j<indiceInscricao; j++) {
        if (tipoBuffet[j] == 3) {
            contadorBuffet++;
        }
    }
    return porcentagem = (((float)contadorBuffet/(float)indiceInscricao) * 100);
}

int calcularQtdPessoas(int indiceInscricao, int qtdPessoas[]) {
    int qtdPessoaTotal = 0;
    for (int j = 0; j<indiceInscricao; j++) {
            qtdPessoaTotal += qtdPessoas[j];
    }
    return qtdPessoaTotal;
}

int main() {
    /*
    bufe basico basico = 50, premium = 80, deluxe = 120;
    ate 20 pessoas: sem desconto, 21 a 50 : 10% sobre valor total, >50: 15% desconto
    bebidas exclusivas: 10% de acrescimo
    */
    char continuar;
    int numeroInscricao[MAX], buffet[MAX], qtdPessoas[MAX], svcBebidas[MAX],opc,i = 0, desconto, acrescimo;
    float valorPessoa[MAX], valorTotal[MAX],aux;

    int numeroInscricaoCalculo[MAX], buffetCalculo[MAX], qtdPessoasCalculo[MAX],svcBebidasCalculo[MAX];
    float valorPessoaCalculo[MAX], valorTotalCalculo[MAX];

    do
    {
        system("cls");
        printf("0 - Sair\n");
        printf("1 - Inserir mais registros\n");
        printf("2 - Apresentar resultados\n");
        printf("3 - Ordenar os registros pelo valor total da inscricao (decrescente)\n");
        printf("4 - Imprimir registros de inscricoes\n");
        printf("\nOpcao escolhida: ");
        scanf("%d", &opc);
        printf("\n");
        switch(opc)
        {
        case 0:
            printf("Encerrando...");
            break;


            //Cadastro de clientes
        case 1:
            do
            {
                system("cls");
                printf("Numero da inscricao: %d\n", i+1);
                numeroInscricao[i] = i+1;
                printf("Tipo de buffet (1 - Basico, 2 - Premium, 3 - Deluxe, 0 - Cancelar): ");
                scanf("%d", &buffet[i]);

                switch(buffet[i])
                {
                case 0:
                    printf("Encerrando"); // cancelar registro
                    return 0;
                case 1:
                    valorPessoa[i] = 50;
                    break;
                case 2:
                    valorPessoa[i] = 80;
                    break;
                case 3:
                    valorPessoa[i] = 120;
                    break;

                default:
                    printf("Opcao Invalida!");
                    getchar();
                    scanf("%c", &continuar);
                    break;
                }

            } while(buffet[i] != 1 && buffet[i] != 2 && buffet[i] != 3);

            printf("Valor por pessoa: %.2f\n", valorPessoa[i]);

            printf("Quantidade de pessoas: ");
            scanf("%d", &qtdPessoas[i]);
            if (qtdPessoas >20 && qtdPessoas[i] <= 50) {
                desconto = 10;
            } else if (qtdPessoas[i] > 50) {
                desconto = 15;
            } else if (qtdPessoas[i] <0) {
                printf("Erro: Quantidade invalida de pessoas!");
                return 1;
            } else {
                desconto = 0;
            }

            do {
            printf("Servico de bebidas exclusivas (1 - Sim, 0 - Nao): " );
            scanf("%d", &svcBebidas[i]);
            if (svcBebidas[i] != 0 && svcBebidas[i] != 1) {
                printf("Opcao Invalida!\n");
                getchar();
                scanf("%c", &continuar);
            }
            } while(svcBebidas[i] != 0 && svcBebidas[i] != 1);
            if (svcBebidas == 0) {
                acrescimo = 0;
            } else {
                acrescimo = 10;
            }
            valorTotal[i] = (valorPessoa[i] * qtdPessoas[i]) * (1+((acrescimo-desconto)/100));

            i++;
            break;


            // Resultados e Insights
        case 2:
            printf("Resultados e Insights\n\n");
            printf("Media do valor de todas as inscricoes: R$ %.2f\n", calcularMedia(valorTotal, i));
            printf("Media das inscricoes que incluem servico de bebidas exclusivas: R$ %.2f\n", calcularMediaSvcExclusivo(i,svcBebidas,valorTotal));
            printf("Numero da inscricao com maior valor: %d\n", nInscricaoMaiorValor(i,numeroInscricao,valorTotal));
            printf("Percentual de inscricoes para o buffet Deluxe: %.2f%%\n", porcentagemBuffet(i,buffet));
            printf("Total geral de pessoas inscritas: %d\n", calcularQtdPessoas(i,qtdPessoas));
            printf("Pressione enter para continuar");
            getchar();
            scanf("%c", &continuar);
            break;


            // Registros pelo valor total decrescente
        case 3:
            for (int j = 0; j<i; j++)
            {
            numeroInscricaoCalculo[j] = numeroInscricao[j];
            buffetCalculo[j] = buffet[j];
            qtdPessoasCalculo[j] = qtdPessoas[j];
            svcBebidasCalculo[j] = svcBebidas[j];
            valorPessoaCalculo[j] = valorPessoa[j];
            valorTotalCalculo[j] = valorTotal[j];
            }
            for (int j = 0; j<i; j++) {
                for (int k = 0; k<i-1; k++) {
                    if (valorTotalCalculo[k] < valorTotalCalculo[k+1]){
                        aux = valorTotalCalculo[k];
                        valorTotalCalculo[k] = valorTotalCalculo[k+1];
                        valorTotalCalculo[k+1] = aux;

                        aux = numeroInscricaoCalculo[k];
                        numeroInscricaoCalculo[k] = numeroInscricaoCalculo[k+1];
                        numeroInscricaoCalculo[k+1] = aux;

                        aux = buffetCalculo[k];
                        buffetCalculo[k] = buffetCalculo[k+1];
                        buffetCalculo[k+1] = aux;

                        aux = qtdPessoasCalculo[k];
                        qtdPessoasCalculo[k] = qtdPessoasCalculo[k+1];
                        qtdPessoasCalculo[k+1] = aux;

                        aux = svcBebidasCalculo[k];
                        svcBebidasCalculo[k] = svcBebidasCalculo[k+1];
                        svcBebidasCalculo[k+1] = aux;

                        aux = valorPessoaCalculo[k];
                        valorPessoaCalculo[k] = valorPessoaCalculo[k+1];
                        valorPessoaCalculo[k+1] = aux;
                    }
                }
            }
            for (int j = 0; j<i; j++) {
                printf("Numero da inscricao: %d\n",numeroInscricaoCalculo[j]);
                switch(buffetCalculo[j])
                {
                case 1:
                    printf("Tipo de Buffet: Basico\n");
                    break;
                case 2:
                    printf("Tipo de Buffet: Premium\n");
                    break;
                case 3:
                    printf("Tipo de Buffet: Deluxe\n");
                    break;
                }
                printf("Quantidade de pessoas: %d\n", qtdPessoasCalculo[j]);
                if (svcBebidasCalculo[j] == 1) {
                    printf("Bebidas exclusivas: Sim\n");
                } else {
                    printf("Bebidas exclusivas: Nao\n");
                }
                printf("Valor Total: R$ %.2f\n\n\n", valorTotalCalculo[j]);
            }
            printf("Pressione enter para continuar");
            getchar();
            scanf("%c", &continuar);
            break;


            // Registros de inscricoes
        case 4:
            for (int j = 0; j<i; j++) {
                printf("Numero da inscricao: %d\n",numeroInscricao[j]);
                switch(buffet[j])
                {
                case 1:
                    printf("Tipo de Buffet: Basico\n");
                    break;
                case 2:
                    printf("Tipo de Buffet: Premium\n");
                    break;
                case 3:
                    printf("Tipo de Buffet: Deluxe\n");
                    break;
                }
                printf("Quantidade de pessoas: %d\n", qtdPessoas[j]);
                if (svcBebidas[j] == 1) {
                    printf("Bebidas exclusivas: Sim\n");
                } else {
                    printf("Bebidas exclusivas: Nao\n");
                }
                printf("Valor Total: R$ %.2f\n\n\n", valorTotal[j]);
            }
            printf("Pressione enter para continuar");
            getchar();
            scanf("%c", &continuar);
            break;

        default:
            printf("Opcao Invalida!");
            break;
        }




    } while (opc != 0);
    return 0;
}

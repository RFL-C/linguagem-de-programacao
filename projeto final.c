#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define buffetBasico 50
#define buffetPremium 80
#define buffetDeluxe 120

float calcularMedia(float valorTotal[], int indiceInscricao);
void calcularMediaSvcExclusivo(int indiceInscricao, int svcBebidas[], float valorTotal[]);
int nInscricaoMaiorValor(int i, int numeroInscricao[], float valorTotal[]);
float porcentagemBuffet(int indiceInscricao, int tipoBuffet[]);
int calcularQtdPessoas(int indiceInscricao, int qtdPessoas[]);
void menuPrincipal();
void mostrarResultados();
void inserirRegistro();
void registrosValDecrescente();
void mostrarRegistros();
void bubbleSortingInt(int vetor[], float auxiliar, int indice);
void bubbleSortingFloat(float vetor[], float auxiliar, int indice);

int numeroInscricao[MAX], buffet[MAX], qtdPessoas[MAX], svcBebidas[MAX],opc,i = 0;
float valorPessoa[MAX], valorTotal[MAX];

int main() {
    do
    {
        menuPrincipal();
        switch(opc)
        {
        case 0: // Sair
            printf("Encerrando...");
            break;

        case 1: // Inserir Registros
            inserirRegistro();
            break;

        case 2: // Resultados e Insights
            mostrarResultados();
            break;

        case 3: // Registros pelo valor total decrescente
            registrosValDecrescente();
            break;

        case 4: // Registros de inscricoes
            mostrarRegistros();
            break;

        default:
            printf("Opcao Invalida!\n");
            system("pause");
            break;
        }

    } while (opc != 0);
    return 0;
}

float calcularMedia(float valorTotal[], int indiceInscricao) {
    float valorTotalGeral = 0;
    for (int j = 0; j < indiceInscricao; j++) {
        valorTotalGeral += valorTotal[j];
    }
    return valorTotalGeral / indiceInscricao;
}

void calcularMediaSvcExclusivo(int indiceInscricao, int svcBebidas[], float valorTotal[]) {
    float somaSvcExclusivo = 0;
    int contador = 0;
    for (int j = 0; j < indiceInscricao; j++) {
        if (svcBebidas[j] == 1) {
            somaSvcExclusivo += valorTotal[j];
            contador++;
        }
    }
    if (contador == 0) {
        printf("Nao houveram cadastros com servico de bebidas exclusivo ainda!\n");
    } else {
        printf("Media das inscricoes que incluem servico de bebidas exclusivas: R$ %.2f\n", somaSvcExclusivo / contador);
    }
}

int nInscricaoMaiorValor(int i, int numeroInscricao[], float valorTotal[]) {
    int inscricaoMaiorValor = numeroInscricao[0];
    float maiorValor = valorTotal[0];
    for (int j = 0; j<i; j++){
        if (maiorValor < valorTotal[j]){
            maiorValor = valorTotal[j];
            inscricaoMaiorValor = numeroInscricao[j];
        }
    }
    return inscricaoMaiorValor;
}

float porcentagemBuffet(int indiceInscricao, int tipoBuffet[]) {
    int contadorBuffet = 0;
    float porcentagem;
    for (int j = 0; j<indiceInscricao; j++) {
        if (tipoBuffet[j] == 3) {
            contadorBuffet++;
        }
    }
    return porcentagem = (float)contadorBuffet/(float)indiceInscricao * 100;
}

int calcularQtdPessoas(int indiceInscricao, int qtdPessoas[]) {
    int qtdPessoaTotal = 0;
    for (int j = 0; j<indiceInscricao; j++) {
            qtdPessoaTotal += qtdPessoas[j];
    }
    return qtdPessoaTotal;
}

void menuPrincipal() {
    system("cls");
    printf("Menu principal\n\n");
    printf("[0] Sair\n");
    printf("[1] Inserir mais registros\n");
    printf("[2] Apresentar resultados\n");
    printf("[3] Ordenar os registros pelo valor total da inscricao (decrescente)\n");
    printf("[4] Imprimir registros de inscricoes\n");
    printf("\nOpcao escolhida: ");
    scanf("%d", &opc);
    printf("\n\n");
}

void mostrarResultados() {
    system("cls");
    printf("Resultados e Insights:\n\n");
    if (i == 0) {
        printf("Nao ha nenhum resultado a ser exibido! Insira algum registro e tente novamente.\n\n");
    } else {
        printf("Media do valor de todas as inscricoes: R$ %.2f\n", calcularMedia(valorTotal, i));
        calcularMediaSvcExclusivo(i,svcBebidas,valorTotal);
        printf("Numero da inscricao com maior valor: %d\n", nInscricaoMaiorValor(i,numeroInscricao,valorTotal));
        printf("Percentual de inscricoes para o buffet Deluxe: %.2f%%\n", porcentagemBuffet(i,buffet));
        printf("Total geral de pessoas inscritas: %d\n\n", calcularQtdPessoas(i,qtdPessoas));
    }
    system("pause");
}

void inserirRegistro() {
    int desconto, acrescimo;

    do {
        system("cls");
        printf("Numero da inscricao: %d\n\n", i+1);
        numeroInscricao[i] = i+1;
        printf("[1 - Basico] [2 - Premium] [3 - Deluxe] [0 - Cancelar]\n");
        printf("Tipo de buffet: ");
        scanf("%d", &buffet[i]);

        switch(buffet[i])
        {
        case 0:
            printf("Voltando ao menu..."); // cancelar registro
            return;
        case 1:
            valorPessoa[i] = buffetBasico;
            break;
        case 2:
            valorPessoa[i] = buffetPremium;
            break;
        case 3:
            valorPessoa[i] = buffetDeluxe;
            break;
        default:
            printf("Opcao Invalida!\n");
            system("pause");
            break;
        }
    } while(buffet[i] < 1 || buffet[i] > 3);

    printf("\nValor por pessoa: %.2f\n\n", valorPessoa[i]);

    printf("Quantidade de pessoas: ");
    scanf("%d", &qtdPessoas[i]);

    if (qtdPessoas[i] <1) {
        system("cls");
        printf("Erro: Quantidade invalida! Insira um valor maior que 0.\n\n");
        printf("Voltando ao menu principal...\n");
        system("pause");
        return;
    } else if (qtdPessoas[i] >20 && qtdPessoas[i] <= 50) {
        desconto = 10;
    } else if (qtdPessoas[i] > 50) {
        desconto = 15;
    } else {
        desconto = 0;
    }

    do {
        printf("\nServico de bebidas exclusivas [1 - Sim] [0 - Nao]: " );
        scanf("%d", &svcBebidas[i]);
        if (svcBebidas[i] < 0 || svcBebidas[i] > 1) {
            printf("Opcao Invalida!\n");
            system("pause");
        }
    } while(svcBebidas[i] < 0 || svcBebidas[i] > 1);

    if (svcBebidas == 0) {
        acrescimo = 0;
    } else {
        acrescimo = 10;
    }

    valorTotal[i] = (valorPessoa[i] * qtdPessoas[i]) * (1+((acrescimo-desconto)/100));

    printf("\n\nInscricao realizada com sucesso\n");
    i++;
    system("pause");
}

void bubbleSortingInt(int vetor[], float auxiliar, int indice) {
    auxiliar = vetor[indice];
    vetor[indice] = vetor[indice+1];
    vetor[indice+1] = auxiliar;
}

void bubbleSortingFloat(float vetor[], float auxiliar, int indice) {
    auxiliar = vetor[indice];
    vetor[indice] = vetor[indice+1];
    vetor[indice+1] = auxiliar;
}

void registrosValDecrescente() {
    float aux;

    system("cls");
    printf("Registros pelo valor total decrescente:\n\n");

    if (i > 0) {
        int numeroInscricaoCalculo[MAX], buffetCalculo[MAX], qtdPessoasCalculo[MAX],svcBebidasCalculo[MAX];
        float valorPessoaCalculo[MAX], valorTotalCalculo[MAX];
        for (int j = 0; j<i; j++){
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
                    bubbleSortingInt(numeroInscricaoCalculo,aux,k);
                    bubbleSortingInt(buffetCalculo,aux,k);
                    bubbleSortingInt(qtdPessoasCalculo,aux,k);
                    bubbleSortingInt(svcBebidasCalculo,aux,k);
                    bubbleSortingFloat(valorTotalCalculo,aux,k);
                    bubbleSortingFloat(valorPessoaCalculo,aux,k);
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

    } else {
        printf("Nao ha nenhum registro a ser exibido! Insira algum registro e tente novamente.\n\n");
    }
    system("pause");
}

void mostrarRegistros() {
    system("cls");
    printf("Registros:\n\n");
    if (i > 0) {
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
    } else {
        printf("Nao ha nenhum registro a ser exibido! Insira algum registro e tente novamente.\n\n");
    }
    system("pause");
}

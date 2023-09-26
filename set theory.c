/*Fazer um programa para trabalhar com conjuntos*/

// Função para ler um vetor
void lerVetor(int vetor[], int tamanho){
    for (int i = 0; i < tamanho; i++){
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }
}

// Função para ordenar um vetor usando o Bubble Sort
void bubbleSort(int vetor[], int tamanhoVetor){ // só funciona o bubbleSort normal, o melhorado não funcionou
    int auxTroca, i, j;
    for(i = 0; i < tamanhoVetor - 1; i++){
        for(j = 0; j < tamanhoVetor - i - 1; j++){
            if (vetor[j] > vetor[j + 1]) {
                auxTroca = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = auxTroca;
            }
        }
    }
}

// Função para verificar se esta no vetor ou não
int presente_no_conjunto(int vetor[], int tamanhoVetor, int numero){
    int resultFlag = 0;
        for(int i = 0; i < tamanhoVetor; i++){
            if(vetor[i] == numero){
                resultFlag = 1;
                break;
            }
        }
    return resultFlag;
}

void funcao_presente_no_conjunto(int vetor[], int tamanhoVetor){
    int resultFlag = 0, numero;
    printf("Digite o numero a ser analisado: ");
    scanf("%d", &numero);
        for(int i = 0; i < tamanhoVetor; i++){
            if(vetor[i] == numero){
                resultFlag = 1;
                break;
            }
        }
        if(resultFlag == 1){
            printf("O numero %d esta presente no conjunto! :D\n", numero);
        }else{
            printf("O numero %d NAO esta presente no conjunto :(\n", numero);
        }
}

void elemento_repetido(int vetor[], int tamanhoVetor){
    int repetido = 0;
        for(int i = 0; i < tamanhoVetor - 1 ; i++){ // garante que o loop não ultrapasse o limite do vetor
            for(int j = i + 1; j < tamanhoVetor; j++){ // garante que não estamos comparando o elemento com ele mesmo ou com elementos anteriores
                if(vetor[i] == vetor[j]){
                    repetido = repetido + 1;
                }
            }
        }
        if(repetido != 0){
            printf("Ha %d numeros repetidos nesse conjunto!\n", repetido);
        }else{
            printf("Nao ha numeros repetidos nesse conjunto :D\n");
        }
}

// Função para uniao (não deu pra fazer sem ser por ponteiro)
void uniao(int a[], int b[], int tamanhoA, int tamanhoB, int resultadoFinal[], int *resultadoTamanho){ // ponteiro é usado para MUDAR e não COPIAR o valor
    int i = 0;
    *resultadoTamanho = 0; // tem que iniciar com 0 para evitar qualquer conflito com outras operacoes
    for(i = 0; i < tamanhoA; i++) {
        resultadoFinal[i] = a[i]; // copia os valores do conjunto A para o resultado final
        *resultadoTamanho = (*resultadoTamanho) + 1; // incrementa 1 para saber o tamanho do vetor final
    }
    for(i = 0; i < tamanhoB; i++){
        if(presente_no_conjunto(resultadoFinal, *resultadoTamanho, b[i]) == 0){
            resultadoFinal[*resultadoTamanho] = b[i];
            *resultadoTamanho = (*resultadoTamanho) + 1;
        }
    }
}

// funcao para intersecção (ela é parecida com união, mas é o oposto ao mesmo tempo)
void interseccao(int a[], int b[], int tamanhoA, int tamanhoB, int resultadoFinal[], int *resultadoTamanho){
    int i = 0;
    *resultadoTamanho = 0;
    // não precisa do primeiro FOR do união porque o tamanho SEMPRE será menor do que o conjunto A ou B
        for(i = 0; i < tamanhoB; i++){ 
            if(presente_no_conjunto(b, tamanhoB, a[i]) == 1){
                resultadoFinal[*resultadoTamanho] = a[i]; // o ponteiro vai ser como "i"
                *resultadoTamanho = (*resultadoTamanho) + 1;
            }
        }
}

void diferenca_conjuntos(int a[], int b[], int tamanhoA, int tamanhoB, int resultadoFinal[], int *resultadoTamanho){
    int i = 0;
    *resultadoTamanho = 0;
        for(i = 0; i < tamanhoB; i++){ 
            if(presente_no_conjunto(b, tamanhoB, a[i]) == 0){ 
                // a funcao é IDENTICA a intersecção, a unica diferença é que queremos os elementos que não se repetem, ou seja, o resultFlag == 0
                resultadoFinal[*resultadoTamanho] = a[i]; // o ponteiro vai ser como "i"
                *resultadoTamanho = (*resultadoTamanho) + 1;
            }
        }
}

void resultado_final(int vetor[], int tamanhoVetor){
    printf("{");
        for(int i = 0; i < tamanhoVetor; i++){
            printf("%d, ", vetor[i]);
        }
    printf("}\n");
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
int main () {
    int n, m, menu;
    printf("\nPrograma para trabalhar com conjuntos\n\n");
    printf("Digite a quantidade de numeros para o PRIMEIRO conjunto A: ");
    scanf("%d", &n);
    printf("Digite a quantidade de numeros para o SEGUNDO conjunto B: ");
    scanf("%d", &m); 
    int conjuntoA[n];
    int conjuntoB[m];
    printf("\nVamos colocar os numeros do CONJUNTO A\n");
    lerVetor(conjuntoA, n);
    printf("\nVamos colocar os numeros do CONJUNTO B\n");
    lerVetor(conjuntoB, m);
    bubbleSort(conjuntoA, n);
    bubbleSort(conjuntoB, m);
    int resultado[n + m];
    int tamResultado = 0;
        do{
            printf("\n\tMENU\n\n");
            printf("1 - Uniao\n");
            printf("2 - Interseccao\n");
            printf("3 - Diferenca entre A e B\n");
            printf("4 - Diferenca entre B e A\n");
            printf("5 - Verificar se algum elemento esta no conjunto A\n");
            printf("6 - Verificar se algum elemento esta no conjunto B\n");
            printf("7 - Ha algum elemento repetido em A?\n");
            printf("8 - Ha algum elemento repetido em B?\n");
            printf("9 - Sair\n");
            printf("Digite o numero correspodente a operacao que deseja: ");
            scanf("%d", &menu);
                switch(menu){
                    case 1:
                        uniao(conjuntoA, conjuntoB, n, m, resultado, &tamResultado);
                        printf("uniao: ");
                        resultado_final(resultado, tamResultado);
                        break;
                    case 2:
                        interseccao(conjuntoA, conjuntoB, n, m, resultado, &tamResultado);
                        printf("interseccao: ");
                        resultado_final(resultado, tamResultado);
                        break;
                    case 3:
                        diferenca_conjuntos(conjuntoA, conjuntoB, n, m, resultado, &tamResultado);
                        printf("Diferenca entre A - B:  ");
                        resultado_final(resultado, tamResultado);
                        break;
                    case 4:
                        diferenca_conjuntos(conjuntoB, conjuntoA, m, n, resultado, &tamResultado);
                        printf("Diferenca entre B - A: ");
                        resultado_final(resultado, tamResultado);
                        break;
                    case 5:
                        funcao_presente_no_conjunto(conjuntoA, n);
                        break;
                    case 6:
                        funcao_presente_no_conjunto(conjuntoB, m);
                        break;
                    case 7:
                        elemento_repetido(conjuntoA, n);
                        break;
                    case 8:
                        elemento_repetido(conjuntoB, m);
                        break;
                    case 9:
                        printf("\nFinalizando o programa.\n");
                        break;
                    default:
                        printf("\nOpcao invalida. Digite um numero que esteja no menu.\n");
                        break;
                }
            if(menu != 9){
                char continuar[3];
                printf("\nDeseja continuar?\n");
                printf("Digite SIM ou NAO: ");
                scanf("%s", &continuar);
                    if(strcmp(continuar, "NAO") == 0 || strcmp(continuar, "Nao") == 0 || strcmp(continuar, "nao") == 0){
                        menu = 9;
                    }
            }
        }while(menu != 9);
}
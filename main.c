/**
* @file
* @author Bruno Keller Margaritelli, João Pedro Moreto Lourenção
* @r.a:  2150883 e 2150980
* @date 31 OUT 2021
* @brief  Linguagem reversa - Lr = { wwr | w pertence {a,b}*}
*/

#include "pilhaDin.h"

#define TAM 200 //Define o tamanho da palavra

int main(int argc, const char * argv[]) {

    char palavra[TAM]; //palavra a ser lida
    char metade1[TAM/2] = "\0"; //primeira metade da palavra
    char comp[TAM/2] = "\0"; // string de comparação
    char metade2[TAM/2] = "\0"; //segunda metade da palavra
    pilhadim pilha; //inicia a struct pilha
    objetoDin obj; //inicia o objeto da struct pilha, que contem char chave
    iniciaPilhaDin(&pilha); //função que inicia a pilha
    unsigned long int indice = 0, meio = 0;
    printf("\t****** Autômato Linguagem Reversa ******\n");
    printf("Digite a palavra: ");
    scanf("%s", palavra); //le a palavra do teclado
    if (strlen(palavra) % 2 != 0) { //se a palavra tiver um número impar de caracteres, não pode ser reversa
        printf("A palavra não pode ser reversa!\n");
    } else{
        printf("A palavra pode ser uma palavra reversa, vamos verificar!\n");
        meio = (strlen(palavra)/2); //determina o meio da palavra
        
        while (indice < meio) { //laço de repetição do inicio ate o meio da palavra
            char elemento = palavra[indice]; // elemento recebe cada caractere da palavra
            
            if (elemento == 'a' || elemento == 'b') { //permite ler apenas os caracteres 'a' e 'b', pertencentes à linguagem do autômato
                obj.chave = elemento;
                pushDin(obj, &pilha); // empilha o elemento atraves da função pushDin()
                printDin(&pilha); //mostra a pilha através da funcao printDin()
                metade1[indice] = elemento; //armazena o elemento lido numa segunda string que vai do inicio ao meio da palavra original
                indice++; //incrementa o indice
            } else{
                printf("A palavra inserida não pertence à linguagem do autômato!\n");
                exit(1);
            }
        }
        printf("\nMetade1: %s", metade1);
        // a parte baixo armazena a segunda metade da palavra na string metade2
        indice = meio;
        int i = 0;
        unsigned long int final = strlen(palavra);
        while (indice < final) {
            char elemento = palavra[indice];
            if (elemento == 'a' || elemento == 'b') {
                metade2[i] = elemento;
                indice++;
                i++;
            }
        }
        printf("\n\nmetade2: %s", metade2);
        objetoDin aux; //inicia outro objeto da struct pilha
        char letra;
        for (indice = 0; indice<meio; indice++) {
            //Para cada indice, remove o elemento da pilha e o armazena na string comp
            popDin(&pilha, &aux);
            letra = aux.chave;
            comp[indice] = letra;
        }
        printf("\n\nString que a pilha retornou para ser comparada com a metade 2: %s\n", comp);
        // a parte abaixo compara elemento por elemento das strings metade2 e comp
        for (int j = 0; j<meio; j++) {
            if (metade2[j] != comp[j]) { //se algum dos elementos for diferente, não é reversa
                printf("\nA palavra pertence à linguagem do autômato, mas não é reversa, pois %s é diferente de %s\n", metade1, metade2);
                return 0;
            }
        }
        // se passar pelo laço for e obedecer os critérios, então é reversa
        printf("\nA palavra obedece à linguagem wwr do autômato, então é reversa!\n");
        printf("\n%s é reversa de %s\n", metade1, metade2);
    }
    
    return 0;
}

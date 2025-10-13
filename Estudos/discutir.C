#include <stdio.h>

int indexOf(char str[], char subStr[]) {
    int i, j, k;

    for (i = 0; str[i] != '\0'; i++) {
        // Se o caractere inicial for igual, vamos verificar o restante
        if (str[i] == subStr[0]) {
            k = i;      // guarda posição inicial
            j = 0;      // índice para subStr

            // compara os próximos caracteres
            while (str[k] != '\0' && subStr[j] != '\0' && str[k] == subStr[j]) {
                k++;
                j++;
            }

            // se percorreu toda subStr, significa que achou
            if (subStr[j] == '\0') {
                return i; // índice inicial da ocorrência
            }
        }
    }

    return -1; // se não encontrar
}

int main() {
    char str[100] = "programar em C é divertido";
    char subStr[20] = "divertido";

    int pos = indexOf(str, subStr);

    if (pos != -1)
        printf("Substring encontrada na posicao %d\n", pos);
    else
        printf("Substring nao encontrada\n");

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

void main (){

    int i, vetor[10];

    for(i=0; i<10; i++){
        printf("Digite 10 valores:");
        scanf("%d", &vetor[i]);
    }
    for(i=0; i<10; i++){
        printf("O valor do vetor e: %d\n", vetor[i]);
    }

    return 0;

}

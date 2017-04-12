#include <stdio.h>
#include <stdlib.h>

void main (){

    int i,j;
    int vetor[3][4];


       for(i=0; i<3; i++){
        for(j=0; j<4; j++){
            printf("Entre com um numero:");
            scanf("%d", &vetor[i][j]);
        }
    }
    printf("Matriz 3x4 e a seguinte:\n\n");
    for(i=0; i<3; i++){
        for(j=0; j<4; j++){
            printf("%3d", vetor[i][j]);
        }
        printf("\n");
    }

return 0;

}

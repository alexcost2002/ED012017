#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

int main ()
{
    char posa [5][5], posb [5][5],posc[5][5],posd[5][5], opt;
    srand (time(NULL));

    int i,j,linha,col,z,cont=0,contpc=0,ale=1,contale=0;

    puts("\n\n");
    puts("      _______________________________________________________________");
    puts("     |                                                               |");
    puts("     |  ***********************************************************  |");
    puts("     |  *                                                         *  |");
    puts("     |  *                                                         *  |");
    puts("     |  *                     BATALHA NAVAL                       *  |");
    puts("     |  *                                                         *  |");
    puts("     |  *              Universidade de Brasilia - UnB             *  |");
    puts("     |  *              Disciplina: Estrutura de Dados             *  |");
    puts("     |  *              Profº: Gustavo van Erv                     *  |");
    puts("     |  *              Aluno: Alexandre Gama Costa                *  |");
    puts("     |  *              Matricula: 140079513                       *  |");
    puts("     |  *                                                         *  |");
    puts("     |  *                                                         *  |");
    puts("     |  *                                                         *  |");
    puts("     |  ***********************************************************  |");
    puts("     |_______________________________________________________________|");

    printf("\n\n");
    opt=getch();
    system("cls");


//  --------------------------- IMRRIME MATRIZ DO JOGADOR --------------------------------------------------------------
    printf ("TABULEIRO DO JOGADOR: \n\n");
    // COLOCA TODAS AS POSIÇÕES COM O SIMBOLO '#'
     for (i=0;i<5;i++)
     {
         for (j=0;j<5;j++)
         {
             posa[i][j] = '#';
             posb[i][j] = '#';
             posc[i][j] = '#';
             posd[i][j] = '#';
         }
     }
     // VERIFICANDO MATRIZ
        printf ("    1  2  3  4  5\n");
        for (i=0;i<5;i++)
        {
         printf (" %d ",i+1);
         for (j=0;j<5;j++)
         {
            printf (" %c ", posa[i][j]);
         }
         printf ("\n");
        }

     // INSERINDO BARCOS -------------------------------------------------------
    {
     // INSERINDO BARCOS ALEATORIAMENTE ------------------------------------------------------------

        while (contale< 10)
        {
              linha = rand() %5;
              col = rand() %5;
              if (posb [linha][col] == 'B')
              {
                 printf ("-");
              }
              else
              {
              posb [linha][col] = 'B';
              contale ++;
              }
        }
        printf ("\n\n --------- POSICAO DOS SEUS BARCOS NA BATALHA -------- \n\n");
        printf ("    1  2  3  4  5\n");
        for (i=0;i<5;i++)
        {
            printf (" %d ",i+1);
            for (j=0;j<5;j++)
            {
                printf (" %c ", posb[i][j]);
            }
            printf ("\n");
        }
        printf ("\n");
        system ("pause");
     }
     // INSERINDO BARCOS DO ADVERSARIO ------------------------------------------------------------

        int contb=0;
        while (contb< 10)
        {
              linha = rand() %5;
              col = rand() %5;
              if (posd [linha][col] == 'B')
              {
                 printf ("-");
                   }
              else
              {
              posd [linha][col] = 'B';
              contb ++;
              }
        }

 //------------------------   TESTE IMPRIMINDO BARCOS DO PC
 //    system("cls");
 //    printf ("\n\n --------- POSICACAO DOS BARCOS DO ADVERSARIO - VERIFICACAO -------- \n\n");
 //    printf ("    1  2  3  4  5\n");
  //     for (i=0;i<5;i++)
 //    {
  //       printf (" %d ",i+1);
  //       for (j=0;j<5;j++)
  //       {
  //          printf (" %c ", posd[i][j]);
 //        }
 //        printf ("\n");
 //    }
// ---------------------- DEFINIÇÃO DO TABULEIRO  --------------------------

                printf ("\n TABULEIRO JOGADOR\t         TABULEIRO ADVERSARIO\n");
                printf("\n");
                printf ("    1  2  3  4  5\t             1  2  3  4  5\n");
                 for (i=0;i<5;i++)
                {
                     printf (" %d ",i+1);
                    for (j=0;j<5;j++)
                    {
                        printf (" %c ", posa[i][j]);

                    }
                    printf ("\t\t ");
                    printf (" %d ",i+1);
                    for (j=0;j<5;j++)
                    {
                      printf (" %c ",posc[i][j]);
                    }
                    printf ("\n");
                }

     //ADVERSARIO ATIRANDO ----------------------------------------------------------------------------
      int numtiro=0,numtiropc=0;
      // CONTROLE DE ENCERRAMENTO DO JOGO
       while (cont < 9 || contpc < 9)
       {
        int tiro =0,tiropc =0;
        while (tiro<=0)
        {
         printf ("\nSua vez de atirar!\n");
         printf ("\nCordenadas do Tiro: \n");
         printf ("Numero da Linha: ");
         scanf ("%d", &linha);
         printf ("Numero da Coluna: ");
         scanf ("%d", &col);

         // VERIFICA SE JÁ REALIZOU O TIRO
         while (posc[linha-1][col-1] == '1' || posc[linha-1][col-1] == '0')
         {
               printf ("\nVoce ja atirou neste local\n");
               printf ("Escolha outra cordenada\n");
               printf ("Numero da Linha: ");
               scanf ("%d", &linha);
               printf ("Numero da Coluna: ");
               scanf ("%d", &col);
                while ((linha <= 0 || linha >5) || (col <= 0 || col >5))
                {
                       printf ("Valor Invalido! Digite outro!\n");
                       printf ("Numero da Linha: ");
                       scanf ("%d", &linha);
                       printf ("Numero da Coluna: ");
                       scanf ("%d", &col);
                }
         }
         // VERIFICA SE AS COORDENADAS SAO VALIDAS
          while ((linha <= 0 || linha >5) || (col <= 0 || col >5))
                {
                       printf ("Valor Invalido! Digite outro!\n");
                       printf ("Numero da Linha: ");
                       scanf ("%d", &linha);
                       printf ("Numero da Coluna: ");
                       scanf ("%d", &col);
                       while (posc[linha-1][col-1] == '1' || posc[linha-1][col-1] == '0')
                       {
                               printf ("\nVoce ja atirou neste local\n");
                               printf ("Escolha outra cordenada\n");
                               printf ("Numero da Linha: ");
                               scanf ("%d", &linha);
                               printf ("Numero da Coluna: ");
                               scanf ("%d", &col);
                       }
                }
                printf ("\n");
                system ("cls");

         //VERIFICA SE ERROU OU ACERTOU O TIRO
         if (posd[linha-1][col-1] == '#')
         {
             posc [linha-1][col-1] = '0';
             tiro=1;
             numtiro++;
             system("cls");
             printf ("\nVoce errou o Tiro!\n");
             printf ("Voce ja acertou %d de 10 navios", cont);
             printf ("\nNumero de Tiros Jogador: %d\n",numtiro);

               //VERIFICA ONDE VOCÊ ATIROU

                printf ("\nSeu tiro: \n");
                printf ("Cordenadas do seu tiro.\nLinha: %d Coluna: %d\n",linha,col);
                printf ("\n TABULEIRO JOGADOR\t         TABULEIRO ADVERSARIO\n");
                printf ("    1  2  3  4  5\t             1  2  3  4  5\n");
                 for (i=0;i<5;i++)
                {
                     printf (" %d ",i+1);
                    for (j=0;j<5;j++)
                    {
                        printf (" %c ", posa[i][j]);

                    }
                    printf ("\t\t ");
                    printf (" %d ",i+1);
                    for (j=0;j<5;j++)
                    {
                      printf (" %c ",posc[i][j]);
                    }
                    printf ("\n");
                }

                printf ("\n");
                system ("pause");
                system ("cls");

         }
         else
         {
            numtiro++;
            system("cls");
            posc [linha-1][col-1] = '1';
            tiro=0;
            cont++;
            printf ("\nVoce acertou o Tiro! Jogue Novamente!\n");
            printf ("Voce ja acertou %d de 10 navios", cont);
            printf ("\nNumero de Tiros Jogador: %d\n",numtiro);


             printf ("\nSeu tiro: \n");
             printf ("Cordenadas do seu tiro.\nLinha: %d Coluna: %d\n",linha,col);
                printf ("\n TABULEIRO JOGADOR\t         TABULEIRO ADVERSARIO\n");
                printf ("    1  2  3  4  5\t             1  2  3  4  5\n");
                 for (i=0;i<5;i++)
                {
                     printf (" %d ",i+1);
                    for (j=0;j<5;j++)
                    {
                        printf (" %c ", posa[i][j]);

                    }
                    printf ("\t\t ");
                    printf (" %d ",i+1);
                    for (j=0;j<5;j++)
                    {
                      printf (" %c ",posc[i][j]);
                    }
                    printf ("\n");
                }

                printf ("\n");
                system ("pause");


                // ENCERRA O JOGO QUANDO VOCE GANHOU
                if (cont==10)
                {

                    printf ("\nVoce Ganhou o Jogo! Parabens!\n");
                    printf ("Voce Atirou %d tiros e Pc Atirou %d tiros\n",numtiro,numtiropc);
                    system ("pause");
                    return 0;
                }
         }
        }


// ADVERSARIO ATIRANDO --------------------------------------------

        while (tiropc<=0)
        {
        //ADEVERSARIO ATIRANDO ALETARORIAMENTE
         linha = rand() %5;
         col = rand() %5;
         // VERIFICA SE O ADVERSARIO ATIROU NA MESMA COORDENADA
         while (posa[linha][col] == '0' || posa[linha][col] == '1')
         {
                 linha = rand() %5;
                 col = rand() %5;
         }
         //VERIFICA SE O ADVERSARIO ACERTOU O TIRO
         if (posb[linha][col] == '#')
         {
             numtiropc++;
             posa [linha][col] = '0';
             tiropc=1;

             printf ("\nAdversario errou o Tiro!\n");
             printf ("O Adversario  ja acertou %d de 10 navios", contpc);
             printf ("\nNumero de Tiros Adversario: %d\n",numtiropc);
             //IMPRIMINDO O TIRO
              printf ("\nOnde o Adversario atirou: \n");
              printf ("Linha: %d  Coluna: %d\n", linha+1,col+1);
                printf ("\n TABULEIRO JOGADOR\t         TABULEIRO ADVERSARIO\n");
                printf ("    1  2  3  4  5\t             1  2  3  4  5\n");
                 for (i=0;i<5;i++)
                {
                     printf (" %d ",i+1);
                    for (j=0;j<5;j++)
                    {
                        printf (" %c ", posa[i][j]);

                    }
                    printf ("\t\t ");
                    printf (" %d ",i+1);
                    for (j=0;j<5;j++)
                    {
                      printf (" %c ",posc[i][j]);
                    }
                    printf ("\n");
                }
                printf ("\n");
                system ("pause");


         }
         else
         {
            numtiropc++;
            posa [linha][col] = '1';
            tiropc=0;
            contpc++;

            system("cls");
            printf ("\nAdversario  acertou o Tiro!\n");
            printf ("O Adversario  ja acertou %d de 10 navios", contpc);
            printf ("\nNumero de Tiros Adversario: %d\n",numtiropc);
            //IMPRIMINDO O TIRO
              printf ("\nOnde o Adversario  atirou: \n");
              printf ("Linha: %d  Coluna: %d\n", linha+1,col+1);
                printf ("\n TABULEIRO JOGADOR\t         TABULEIRO ADVERSARIO\n");
                printf ("    1  2  3  4  5\t             1  2  3  4  5\n");
                 for (i=0;i<5;i++)
                {
                     printf (" %d ",i+1);
                    for (j=0;j<5;j++)
                    {
                        printf (" %c ", posa[i][j]);

                    }
                    printf ("\t\t ");
                    printf (" %d ",i+1);
                    for (j=0;j<5;j++)
                    {
                      printf (" %c ",posc[i][j]);
                    }
                    printf ("\n");
                }
                printf ("\n");
                system ("pause");
                system ("cls");


         }
         // ENCERRA O JOGO CASO O ADVERSARIO GANHOU
          if (contpc==10)
                {
                    printf ("\nVoce Perdeu o Jogo!\n");
                    printf ("Voce Atirou %d tiros e Adversario Atirou %d tiros\n",numtiro,numtiropc);
                    system ("pause");
                    return 0;
                }

        }
       }
       printf ("\n");
       system ("pause");
}

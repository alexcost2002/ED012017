/*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
 *     
 * bookmng.C - End of File
 \*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

/*Estrutura agenda */
typedef struct agenda
{
    char nome[20];
    int telefone;
}agenda;

/*Varivaies globais*/
FILE *arq;
agenda contato;

/*Funcao menu, onde retorna alguma opcao*/
char menu()
{
    system("cls");
    printf("***************  Agenda de Contatos: ***************\n");
    printf("\n");
    printf("[1] - Adicionar contato\n");
    printf("[2] - Mostrar lisa de contatos\n");
    printf("[3] - Procurar contato pelo Nome\n");
    printf("[4] - Procurar contato pelo Numero\n");
    printf("[5] - Modificar contato\n");
    printf("[6] - Remover contato\n");
    printf("[9] - Sair\n");
    printf("\n");
    printf("> ");
    return (toupper(getche()));
}

/*Funcao que serve para verificar se no arquivo "banco.bin", já existe nome do contato, retornando 1*/
int verifica(char nome[])
{
    fread(&contato,sizeof(agenda),1,arq);
    while(!feof(arq))
    {
        if (strcmp(contato.nome,nome) == 0)

        {
            fseek(arq,-sizeof(agenda),SEEK_CUR);
            return 1;
        }
        fread(&contato,sizeof(agenda),1,arq);
    }

    return 0;
}

/*Funcao que serve para verificar se no arquivo "banco.bin", já existe telefone do contato, retornando 1*/
int verifica_num(int num)
{
    fread(&contato,sizeof(agenda),1,arq);
    while(!feof(arq))
    {
        if (contato.telefone == num)
        {
            fseek(arq,-sizeof(agenda),SEEK_CUR);
            return 1;
        }
        fread(&contato,sizeof(agenda),1,arq);
    }
    return 0;
}

/*Funcao para add contatos na agenda*/
void adicionar_contato()
{
    char nome[20];

    arq = fopen("banco.bin","a+b");
    if (arq == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return;
    }

    printf("\n\n");
    printf("Digite o nome: ");
    fflush(stdin);
    gets(nome);

    if (verifica(nome) == 1)
    {

        printf("\nNome ja existe.\n");
    }
    else
    {
        strcpy(contato.nome,nome);
        printf("Digite o telefone: ");
        scanf("%d", &contato.telefone);
        fwrite(&contato,sizeof(agenda),1,arq);
    }
    fclose(arq);
}

/*Funcao para modificar contato*/
void modificar()
{
    char nome[20];

    arq = fopen("banco.bin","r+b");
    if (arq == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return;
    }

    printf("\n\n");
    printf("Digite nome do contato: ");
    fflush(stdin);
    gets(nome);

    if (verifica(nome) == 1)
    {
        printf("\nDigite um novo nome: ");
        fflush(stdin);
        gets(nome);
        strcpy(contato.nome,nome);
        printf("\nDigite um novo numero de telefone: ");
        scanf("%d", &contato.telefone);
        fwrite(&contato,sizeof(agenda),1,arq);
    }

    else
    {
        printf("\nNome nao existe.\n");
    }

    fclose(arq);
}

/*Funcao para remover contato*/
void remover_contato()
{
    char nome[20];
    FILE *tmp;

    arq = fopen("banco.bin","r+b");
    if (arq == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return;
    }

    tmp = fopen("banco.txt","a+b");

    printf("\n\n");
    printf("Digite nome do contato: ");
    fflush(stdin);
    gets(nome);

    fread(&contato,sizeof(agenda),1,arq);
    while (!feof(arq))
    {

        if (strcmp(contato.nome,nome) != 0) //compara o nome, para exceder
        {
           fwrite(&contato,sizeof(agenda),1,tmp); //grava no arquivo temp
        }
        fread(&contato,sizeof(agenda),1,arq); //lê arquivo

    }
    fclose(arq);
    fclose(tmp);

    system("del banco.bin");
    system("ren banco.txt banco.bin");
}

/*Procura contato pelo nome*/
void procura_nome()
{
    char nome[20];

    arq = fopen("banco.bin","r+b");
    if (arq == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return;
    }

    printf("\n\n");
    printf("Digite o nome: ");
    fflush(stdin);
    gets(nome);

    if (verifica(nome) == 1)
    {
        fread(&contato,sizeof(agenda),1,arq);
        printf("\n\n");
        printf("----------------------------------------\n");
        printf("CONTATOS          |            TELEFONE \n");
        printf("----------------------------------------\n");
        printf("%-20s           %8d\n", contato.nome,contato.telefone);
        printf("----------------------------------------\n");

    }

    else
    {
        printf("\nContato nao existe.\n");
    }

    fclose(arq);
}

/*Procura contato pelo telefone*/
void procura_num()
{
    int num;

    arq = fopen("banco.bin","r+b");
    if (arq == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return;
    }

    printf("\n\n");
    printf("Digite o telefone: ");
    scanf("%d", &num);

    if (verifica_num(num) == 1)
    {
        fread(&contato,sizeof(agenda),1,arq);
        printf("\n\n");
        printf("----------------------------------------\n");
        printf("CONTATOS          |            TELEFONE \n");
        printf("----------------------------------------\n");
        printf("%-20s           %8d\n", contato.nome,contato.telefone);
        printf("----------------------------------------\n");
    }

    else
    {
        printf("\nContato nao existe.\n");
    }

    fclose(arq);
}

/*Lista contatos*/
void mostrar_lista()
{
    arq = fopen("banco.bin","r+b");
    if (arq == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return;
    }

    printf("\n\n");
    printf("----------------------------------------\n");
    printf("CONTATOS          |            TELEFONE \n");
    printf("----------------------------------------\n");

    fread(&contato,sizeof(agenda),1,arq);
    while (!feof(arq))
    {
        printf("%-20s           %8d\n", contato.nome,contato.telefone);
        fread(&contato,sizeof(agenda),1,arq);
    }
    printf("----------------------------------------\n");

    fclose(arq);
}

/*Funcao principal*/
int main()
{
    char op;

    do
    {
        op = menu();

        switch(op)
        {
            case '1': adicionar_contato(); break;
            case '2': mostrar_lista(); break;
            case '3': procura_nome(); break;
            case '4': procura_num(); break;
            case '5': modificar(); break;
            case '6': remover_contato(); break;
        }

        printf("\n");
        system("PAUSE");

    }while (op != '9');

    return 0;
}

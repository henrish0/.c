#include <math.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
main()
{
    int exc;
    printf("\n Lista nao oficial de strings\n");
exec:
    printf(" Digite um exercio [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14]: ");
    scanf("%i", &exc);
    printf("\n");
    fflush(stdin);
    switch (exc)
    {
    case 1:
        ex1();
        break;
    case 2:
        ex2();
        break;
    case 3:
        ex3();
        break;
    case 4:
        ex4();
        break;
    case 5:
        ex5();
        break;
    case 6:
        ex6();
        break;
    case 7:
        ex7();
        break;
    case 8:
        ex8();
        break;
    case 9:
        ex9();
        break;
    case 10:
        ex10();
        break;
    case 11:
        ex11();
        break;
    case 12:
        ex12();
        break;
    case 13:
        ex13();
        break;
    case 14:
        ex14();
        break;
    default:
        printf(" Opcao invalida.");
        exc = 0;
        goto exec;
    }
}
void ex1()
{
    char entrada[50], maior[50], menor[50], alfamaior[50], alfamenor[50];
    printf(" Digite uma palavra: ");
    gets(entrada);
    strcpy(maior, entrada);
    strcpy(alfamaior, entrada);
    strcpy(menor, entrada);
    strcpy(alfamenor, entrada);
    while (strcmp(entrada, "fim") != 0)
    {
        if (strlen(entrada) > strlen(maior))
            strcpy(maior, entrada);
        if (strlen(entrada) < strlen(menor))
            strcpy(menor, entrada);
        if (strcmp(entrada, alfamaior) == 1)
            strcpy(alfamaior, entrada);
        if (strcmp(entrada, alfamenor) == -1)
            strcpy(alfamenor, entrada);
        printf(" Digite uma palavra: ");
        gets(entrada);
    }
    printf("\n Maior: %s\nMenor: %s\nAlfanumericamente maior: %s\nAlfanumericamente menor: %s", maior, menor, alfamaior, alfamenor);
}
void ex2()
{
    char entrada[50];
    int a = 0;
    printf(" Digite uma palavra: ");
    gets(entrada);
    for (int i = 0; i < 50; i++)
        if (entrada[i] == 'A')
            a++;
    printf(" Ha %d 'A' em sua palavra", a);
}
void ex3()
{
    char entrada[50];
    int a = 0;
    printf(" Digite uma palavra: ");
    gets(entrada);
    for (int i = 0; i < 50; i++)
        if (entrada[i] == 'A')
            printf(" Existe um 'A' em: %d\n", i);
}
void ex4()
{
    char entrada[50], letra;
    int t = 0;
    printf(" Digite uma palavra: ");
    gets(entrada);
    printf(" Digite uma letra: ");
    scanf(" %c", &letra);
    for (int i = 0; i < strlen(entrada); i++)
        if (entrada[i] == letra)
        {
            printf(" Existe um '%c' em: %d\n", letra, i);
            t++;
        }
}
void ex5()
{
    char entrada[50], letra[2];
    int t = 0;
    printf(" Digite uma palavra: ");
    gets(entrada);
    printf(" Digite uma letra: ");
    gets(letra);
    strcpy(entrada, strlwr(entrada));
    strcpy(letra, strlwr(letra));
    if (letra[0] >= 'A' && letra[0] <= 'z')
        for (int i = 0; i < strlen(entrada); i++)
            if (entrada[i] == letra[0])
            {
                printf(" Existe um '%c' em: %d\n", letra[0], i);
                t++;
            }
            else
                printf(" Seu caracter nao esta entre A e z");
    printf(" A letra %c aparece %i vezes", letra[0], t);
}
void ex6()
{
    char entrada[50];
    int letras = 0, numeros = 0, indef = 0;
    printf(" Digite caracteres: ");
    gets(entrada);
    for (int i = 0; i < strlen(entrada); i++)
    {
        if (entrada[i] >= 'A' && entrada[i] <= 'z')
            letras++;
        else if (entrada[i] >= '0' && entrada[i] <= '9')
            numeros++;
        else
            indef++;
    }
    printf(" Existem %i letras, %i numeros e %i caracteres especiais", letras, numeros, indef);
}
void ex7()
{
    char palavra[50], temp;
    printf(" Digite uma string: ");
    gets(palavra);
    for (int i = 0; i < (strlen(palavra) / 2); i++)
    {
        temp = palavra[i];
        palavra[i] = palavra[strlen(palavra) - i - 1];
        palavra[strlen(palavra) - i - 1] = temp;
    }
    printf(" Sua nova string sera %s", palavra);
}
void ex8()
{
    char string[50], stringauxiliar[50];
    printf(" Digite uma string: ");
    gets(string);
    for (int i = 0; i < strlen(string); i++)
        if (string[i] == ' ')
            for (int j = i; j < strlen(string); j++)
                string[j] = string[j + 1];
    printf(" Sua nova string sera %s", string);
}
void ex9()
{
    char string[50];
    printf(" Digite uma string: ");
    gets(string);
    for (int i = 0; i < strlen(string); i++)
        if (string[i] == ' ')
            for (int j = i; j < strlen(string); j++)
                string[j] = string[j + 1];
    printf(" Sua nova string sera %s", string);
}
void ex10()
{
    char entrada[50], letras[4];
    int t = 0;
    printf(" Digite uma palavra: ");
    gets(entrada);
    printf(" Digite tres letras: ");
    gets(letras);
    for (int i = 0; i < strlen(entrada); i++)
    {
        if (strlen(letras) == 3 && entrada[i] == letras[0] && entrada[i + 1] == letras[1] && entrada[i + 2] == letras[2])
        {
            printf(" Existe '%s' em: %d\n", letras, i);
            t++;
        }
        else if (strlen(letras) == 2 && entrada[i] == letras[0] && entrada[i + 1] == letras[1])
        {
            printf(" Existe '%s' em: %d\n", letras, i);
            t++;
        }
        else if (strlen(letras) == 1 && entrada[i] == letras[0])
        {
            printf(" Existe '%s' em: %d\n", letras, i);
            t++;
        }
    }
    printf(" No total, ocorreram %i '%s' em %s", t, letras, entrada);
}
void ex11()
{
    char entrada[1000];
    int t = 0;
    printf(" Digite uma cadeia de caracteres: ");
    gets(entrada);
    for (int i = 0; i < strlen(entrada); i++)
        if (entrada[i] == entrada[strlen(entrada) - i - 1])
            t++;
    if (t == strlen(entrada))
        printf("\n Sua cadeia e palindromo\n");
}
void ex12()
{
    char entrada[100], surname[100];
    int n;
    printf(" Digite um nome completo: ");
    gets(entrada);
    for (int i = 0; i < strlen(entrada); i++)
        if (entrada[i] == ' ')
        {
            n = i;
            for (int j = 0; j < strlen(entrada) - n; j++)
                surname[j] = entrada[j + n + 1];
            i = strlen(entrada);
        }
    entrada[n] = '\0';
    printf("\n %s, %s\n", surname, entrada);
}
// Fiz os dois casos pra estudar mais 😎😎😎💪💪💪💪
void ex13()
{
    srand(time(NULL));
    char entrada[102], characters[7] = "@!#%*^", characters1[5] = "349", characters2[5] = "&go";
    int r;
    printf(" Digite uma frase: ");
    gets(entrada);
    for (int i = 0; i < strlen(entrada); i++)
    {
        /*Regra 1*/
        if ((i == 0 && entrada[i] != ' ' || entrada[i] != ' ' && entrada[i - 1] == ' ') && (entrada[i] >= 'a' && entrada[i] <= 'z'))
            entrada[i] = (entrada[i] - 32);
        else if (entrada[i] >= 'A' && entrada[i] <= 'Z')
            entrada[i] = (entrada[i] + 32);
        /*Regra 2*/
        if (entrada[i] == 'a' || entrada[i] == 'i' || entrada[i] == 'k' || entrada[i] == 'p' || entrada[i] == 'x' || entrada[i] == 'y')
        {
            r = rand() % 6;
            entrada[i] = characters[r];
        }
        /*Regra 4*/
        if (entrada[i] == '8' || entrada[i] == '9' || entrada[i] == '0')
        {
            r = rand() % 3;
            entrada[i] = characters2[r];
        }
        /*Regra 3*/
        if (entrada[i] == 'e' || entrada[i] == 'f' || entrada[i] == 'g')
        {
            r = rand() % 3;
            entrada[i] = characters1[r];
        }
        /*Regra 5*/
        if (entrada[i] == ' ')
            for (int j = i; j < strlen(entrada); j++)
                entrada[j] = entrada[j + 1];
    }
    printf(" %s", entrada);
}
void ex14()
{
    char entrada[2050];
    int counter = 0;
    printf(" Digite seu texto: ");
    gets(entrada);
    strupr(entrada);
    for (char c = 'A'; c <= 'Z'; c++)
    {
        for (int i = 0; i < strlen(entrada); i++)
            if (entrada[i] == c)
                counter++;
        if (counter != 0)
            printf(" A letra %c aparece %i vezes em seu texto\n", c, counter);
        counter = 0;
    }
}

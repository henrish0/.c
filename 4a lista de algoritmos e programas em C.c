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
    srand(time(NULL));
    printf("\n 4a lista de algoritmos e programas em C\n");
exec:
    printf(" Digite um exercio [1, 2, 3, 4, 5, 6, 7]: ");
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
    default:
        printf(" Opcao invalida,");
        exc = 0;
        goto exec;
    }
}
void ex1()
{
    int vet[20];
    for (int i = 0; i < 20; i++)
    {
        vet[i] = rand() % 90 + 10;
        printf(" %i ", vet[i]);
    }
}
void ex2()
{
    int vet[20];
    for (int i = 0; i < 20; i++)
    {
        vet[i] = rand() % 90 + 10;
        printf(" Vetor [%i] = %i\n", i, vet[i]);
    }
}
void ex3()
{
    int vet[20], s = time(NULL), b = 0, sum = 0;
    for (int i = 0; i < 20; i++)
    {
        vet[i] = rand() % 90 + 10;
        printf(" Vetor [%i] = %i\n", i, vet[i]);
    }
    for (int i = 0; i < 20; i++)
    {
        if (s > vet[i])
            s = vet[i];
        if (b < vet[i])
            b = vet[i];
        sum = sum + vet[i];
    }
    printf(" maior= %i menor= %i soma= %i media= %i", b, s, sum, sum / 20);
}
void ex4()
{
    int vet[20], x;
    for (int i = 0; i < 20; i++)
    {
        vet[i] = rand() % 90 + 10;
        printf(" Vetor [%i] = %i\n", i, vet[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        x = vet[i];
        vet[i] = vet[20 - i - 1];
        vet[20 - i - 1] = x;
    }
    for (int i = 0; i < 20; i++)
        printf(" Vetor [%i] = %i\n", i, vet[i]);
}
void ex5()
{
    int vet[20], par = 0, imp = 0, primo = 0;
    bool tof = false;
    for (int i = 0; i < 20; i++)
    {
        vet[i] = rand() % 90 + 10;
        printf(" Vetor [%i] = %i\n", i, vet[i]);
    }
    for (int i = 0; i < 20; i++)
    {
        if (vet[i] % 2 == 0)
            par++;
        else
            imp++;
        for (int j = 10; j <= vet[i] / 2; ++j)
            if (vet[i] % j == 0)
            {
                tof = true;
                j = vet[i];
            }
        if (tof == true)
            primo++;
        tof = false;
    }
    printf(" pares= %i impares= %i primos= %i", par, imp, primo);
}
void ex6()
{
    int vet[20], a;
    for (int i = 0; i < 20; i++)
    {
        vet[i] = rand() % 90 + 10;
        printf(" Vetor [%i] = %i\n", i, vet[i]);
    }
    for (int i = 0; i < 20; ++i)
    {
        for (int j = i + 1; j < 20; ++j)
            if (vet[i] > vet[j])
            {
                a = vet[i];
                vet[i] = vet[j];
                vet[j] = a;
            }
        printf(" Vetor [%i] = %i\n", i, vet[i]);
    }
}
void ex7()
{
    int vet[1000], loc[61], t = 0, n, par = 0, imp = 0, s = 60, b = 0, sum = 0;
    for (int i = 0; i < 61; i++)
        loc[i] = 0;
    for (int i = 0; i < 1000; i++)
    {
        vet[i] = rand() % 60 + 1;
        loc[vet[i]]++;
        if (s > vet[i])
            s = vet[i];
        if (b < vet[i])
            b = vet[i];
        sum = sum + vet[i];
        if (vet[i] % 2 == 0)
            par++;
        else
            imp++;
    }
    for (int i = 0; i < 61; i++)
        if (t < loc[i])
        {
            t = loc[i];
            n = i;
        }
    printf("\n O numero de maior frequencia foi: %i, ocorrendo %i vezes.\n Ha %i numeros pares e %i numeros impares.\n O maior numero foi: %i, sendo que o menor foi: %i.\n A soma de todos os termos e: %i, sua media: %i\n", n, t, par, imp, b, s, sum, sum / 1000);
}

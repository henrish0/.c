#include <math.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
FILE *arquivo, *arquivomatriz, *pares, *impares, *primos;
main()
{
    char exc;
    srand(time(NULL));
    printf("\n 5a lista de Arquivos sequenciais em C\n");
exec:
    printf(" Digite um exercio [a, b, c, d, e, f]: ");
    scanf(" %c", &exc);
    printf("\n");
    fflush(stdin);
    switch (exc)
    {
    case 'a':
        ex1();
        break;
    case 'b':
        ex2();
        break;
    case 'c':
        ex3();
        break;
    case 'd':
        ex4();
        break;
    case 'e':
        ex5();
        break;
    default:
        printf(" Opcao invalida,");
        exc = 0;
        goto exec;
    }
    printf("\n Codigo executado\n");
    fclose(arquivo);
    fclose(arquivomatriz);
    fclose(pares);
    fclose(impares);
    fclose(primos);
}
void ex1()
{
    double t = 0, u = 1, s = 0;
    if ((arquivo = fopen("arquivo.txt", "a")) == NULL)
        printf("Erro de abertura! \n");
    else
    {
        for (double i = 0; i < 64; i++)
            if (i < 63)
            {
                t = u;
                u = s;
                s = t + u;
                fprintf(arquivo, "%.0lf = %.0lf, ", i + 1, s);
            }
        fprintf(arquivo, "\n");
    }
}
void ex2()
{
    int termo;
    double valor, matriz[8][8];
    if ((arquivo = fopen("arquivo.txt", "r")) == NULL)
        printf(" Erro de abertura! \n");
    else
        for (int i = 0; i < 64; i++)
        {
            fscanf(arquivo, "%i = %lf, ", &termo, &valor);
            matriz[i / 8][i % 8] = valor;
            printf(" matriz[%i][%i] = %.0lf\n", i / 8, i % 8, matriz[i / 8][i % 8]);
        }
}
void ex3()
{
    int termo;
    double valor, matriz[8][8];
    if (((arquivo = fopen("arquivo.txt", "r")) == NULL) || ((arquivomatriz = fopen("arquivomatriz.txt", "a")) == NULL))
        printf(" Erro de abertura! \n");
    else
    {
        for (int i = 0; i < 64; i++)
        {
            fscanf(arquivo, "%i = %lf, ", &termo, &valor);
            matriz[i / 8][i % 8] = valor;
            fprintf(arquivomatriz, "matriz[%i][%i] = %.0lf, ", i / 8, i % 8, matriz[i / 8][i % 8]);
        }
        fprintf(arquivomatriz, "\n");
    }
}
void ex4()
{
    int termo;
    double valor;
    if (((arquivo = fopen("arquivo.txt", "r")) == NULL) || ((pares = fopen("pares.txt", "a")) == NULL) || ((impares = fopen("impares.txt", "a")) == NULL))
        printf(" Erro de abertura! \n");
    else
    {
        for (int i = 0; i < 64; i++)
        {
            fscanf(arquivo, "%i = %lf, ", &termo, &valor);
            if (fmod(valor, 2) == 0)
                fprintf(pares, "%i = %.0lf, ", termo, valor);
            else
                fprintf(impares, "%i = %.0lf, ", termo, valor);
        }
        fprintf(pares, "\n");
        fprintf(impares, "\n");
    }
}
void ex5()
{
    bool tof = true;
    int termo, k = 0;
    double valor, vet[64];
    if (((arquivo = fopen("arquivo.txt", "r")) == NULL) || ((primos = fopen("primos.txt", "a")) == NULL))
        printf(" Erro de abertura! \n");
    else
    {
        for (int i = 0; i < 64; i++)
        {
            fscanf(arquivo, "%i = %lf, ", &termo, &valor);
            for (int j = 2; j < valor / 2; ++j)
                if (fmod(valor, j) == 0)
                {
                    tof = false;
                    j = valor;
                }
            if (tof == true)
            {
                vet[k] = valor;
                k++;
                fprintf(primos, "%i = %.0lf, ", termo, valor);
            }
            tof = true;
        }
        fprintf(primos, "\n");
    }
}

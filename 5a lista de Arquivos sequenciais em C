#include <math.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
main()
{
    char exc;
    srand(time(NULL));
    printf("\n 5a lista de Arquivos sequenciais em C\n");
exec:
    printf(" Digite um exercio [a, b, c, d, e]: ");
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
}
void ex1()
{
    FILE * arquivo;
    double t = 0, u = 1, s = 0;
    if ((arquivo = fopen("arquivo.txt","a")) == NULL) // modo de escrita ativo
    {
        printf("Erro de abertura! \n");
    }
    else
    {
        for (double i = 0; i < 64; i++)
        {
            if (i < 63)
            {
            t = u;
            u = s;
            s = t + u;
            fprintf(arquivo, "%.0lf = %.0lf, ", i + 1, s);
            }
        }
    }
    fprintf(arquivo, "\n");
    fclose(arquivo);
    printf("Codigo executado");
    return 0;
}
void ex2()
{

}
void ex3()
{}
void ex4()
{}
void ex5()
{}

#include <math.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
main()
{
    srand(time(NULL));
    int exc;
    printf("\n 3a lista de algoritmos e programas em C\n");
exec:
    printf(" Digite um exercio [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]: ");
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
    default:
        printf(" Opcao invalida,");
        exc = 0;
        goto exec;
    }
}
void ex1()
{
    int qp = 0, qi = 0, x = 0;
    while (x != 9999)
    {
        printf(" Digite um numero inteiro: ");
        scanf("%d", &x);
        if (x % 2 == 0)
            qp++;
        else if (x % 2 == 1 && x != 9999)
            qi++;
    }
    printf(" %d numeros pares e %d numeros impares", qp, qi);
}
void ex2()
{
    int x, i;
    float m;
    printf(" digite um numero inteiro positivo: ");
    scanf("%d", &x);
    int bg = x, sm = x, sum = x + 1;
    for (i = 0; x != -1; i++)
        if (x != -1)
        {
            printf(" digite um numero inteiro positivo: ");
            scanf("%d", &x);
            sum = sum + x;
            if (x > bg)
                bg = x;
            else if (x < sm && x != -1)
                sm = x;
        }
    m = sum / i;
    printf(" O maior numero digitado foi: %d", bg);
    printf("\n O menor numero digitado foi: %d", sm);
    printf("\n A media aritmetica entre os numeros digitados foi: %.3f", m);
}
void ex3()
{
    printf(" INICIO\n var n,f\n imprimir(' Digite um numero: ')\n ler(n)\n para(var i=n-1,i>1,i=i-1)\n     f = n * i\n imprimir(f)\n FIM\n");
}
void ex4()
{
    int n;
    double s = 0;
    printf(" Digite o total de termos: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        s = s + pow((-1), i) / (pow((2 * i + 1), 3));
    printf(" O resultado final e: %f", s);
}
void ex5()
{
    int n, t = 0, u = 1, s;
    printf(" Digite o total de termos: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        t = u;
        u = s;
        s = t + u;
        printf(" %d,", s);
    }
}
void ex6()
{
    int n;
    double s = 0;
    printf(" Digite o total de termos: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        s = s + pow((-1), i) * (i + 1) / (n - i);
    printf(" O resultado final e: %f", s);
}
void ex7()
{
    int t = 0;
    for (int i = 10000; i <= 99999; i++)
    {
        if ((i / 10000 % 10 == i % 10) && (i / 10 % 10 == i / 1000 % 10))
            printf(" Palindromo encontrado: %d\n", i);
        t++;
    }
    printf(" Total de palindromos: %d", t);
}
void ex8()
{
    for (int i = 1000; i <= 9999; i++)
        if (i == (i / 100 + i % 100) * (i / 100 + i % 100))
            printf(" Numero encontrado: %d\n", i);
}
void ex9()
{
    int t;
    printf(" Digite 0 para cara e 1 para coroa: ");
    scanf("%d", &t);
    for (int i = 0; i < 10; i++)
    {
        if (rand() % 2 == t)
            printf(" Voce venceu\n");
        else
            printf(" Voce perdeu\n");
    }
}
void ex10()
{
    float t;
    int n, min = 0, max = 1023;
    char s = 0;
    printf(" ~~~~ Pense em um numero entre 1 e 1023, eu terei dez tentativas para descobri-lo ~~~~");
    t = rand() % max;
    for (int i = 0; i < 10; i++)
        if (s != '=')
        {
            printf("\n\n Minha tentativa: %.0f\n", t);
again:
            printf("\n Meu numero e igual(=), maior(>) ou menor(<) ao que foi escolhido?: ");
            scanf(" %c", &s);
            if (s == '=')
                printf("\n ~~ Eu ganhei! :) ~~\n");
            else if (s == '<')
            {
                min = t;
                t = rand() % (max - min - 1) + min + 1;
            }
            else if (s == '>')
            {
                max = t;
                t = rand() % (max - min - 1) + min + 1;
            else
            {
                goto again;
            }
        }
    printf("\n Fim de jogo\n");
}

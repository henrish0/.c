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
    printf("\n 2a lista de algoritmos e programas em C\n");
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
    int n;
    printf(" Insira um numero");
    scanf("%d", &n);
    if (n % 2 == 1)
        printf(" Numero impar");
    else
        printf(" Numero par");
}
void ex2()
{
    char name[20];
    float a1, a2, a3;
    printf(" Digite um nome; ");
    scanf("%s", &name);
    printf(" Digite a primeira nota; ");
    scanf("%s", &a1);
    printf(" Digite a segunda nota; ");
    scanf("%s", &a2);
    printf(" Digite a terceira nota; ");
    scanf("%s", &a3);
    if ((a1 + a2 + a3) / 3 >= 6)
        printf(" O aluno %s foi aprovado", name);
    else
        printf(" O aluno %s foi reprovado", name);
}
void ex3()
{
    float a;
    printf(" Digite a temperatura: ");
    scanf("%f", &a);
    if (a <= 0)
        printf(" A agua esta congelada");
    if (a > 0 && a < 100)
        printf(" A agua esta liquida");
    else
        printf(" A agua esta em estado gasoso");
}
void ex4()
{
    float x;
    printf(" Digite o valor de x: ");
    scanf("%f", &x);
    if (x <= 0)
        printf("%f", pow(x, 2) + 4);
    else
        printf("%f", pow(x, 3) - 3);
}
void ex5()
{
    float a, b, c, i;
    printf(" Digite o valor A: ");
    scanf("%f", &a);
    printf(" Digite o valor B: ");
    scanf("%f", &b);
    printf(" Digite o valor C: ");
    scanf("%f", &c);
    float a1 = a, b1 = b, c1 = c;
    float lol[3] = {a, b, c};
    if (c1 > b1)
    {
        i = b1;
        b1 = c1;
        c1 = i;
    }
    if (b1 > a1)
    {
        i = a1;
        a1 = b1;
        b1 = i;
    }
    printf(" A=%.3f, B=%.3f, C=%.3f", a1, b1, c1);
}
void ex6()
{
    int X, Y, Z;
    printf(" Digite o valor X: ");
    scanf("%d", &X);
    printf(" Digite o valor Y: ");
    scanf("%d", &Y);
    printf(" Digite o valor Z: ");
    scanf("%d", &Z);
    if ((X % Y == 0) && (X % Z == 0))
        printf(" O numero e divisivel por Y e Z.");
    else if ((X % Y == 0) && !(X % Z == 0))
        printf(" O numero e divisivel por Y mas nao por Z.");
    else if ((!X % Y == 0) && (X % Z == 0))
        printf(" O numero e divisivel por Z mas nao por Y.");
    else
        printf(" O numero nao e divisivel nem Y nem por Z.");
}
void ex7()
{
    int n, a, b, c, d;
    printf(" De um numero de quatro digitos: ");
    scanf("%d", &n);
    if (n <= 999 || n >= 10000)
        printf(" Seu numero nao tem quatro digitos");
    else
    {
        if ((10 * (n / 1000 % 10) + n / 100 % 10 + 10 * (n / 10 % 10) + n % 10)*(10 * (n / 1000 % 10) + n / 100 % 10 + 10 * (n / 10 % 10) + n % 10) == n)
            printf(" O numero possui a caracteristica");
        else
            printf(" O numero nao possui a caracteristica");
    }
}
void ex8()
{
    int n;
    printf(" Digite o codigo: ");
    scanf("%d", &n);
    if (n = 221)
        printf(" Bernardo");
    else if (n = 211)
        printf(" Eustaquio");
    else if (n = 311)
        printf(" Luiz");
    else if (n = 312)
        printf(" Mario");
    else if (n = 332)
        printf(" Artur");
    else
        printf(" Seu código não está cadastrado");
}
void ex9()
{
    int n, a, b, c, d, e;
    printf(" De um numero de cinco digitos: ");
    scanf("%d", &n);
    if (n <= 9999 || n >= 100000)
        printf(" Seu numero nao possui cinco digitos");
    else
    {
        if ((n / 10000 % 10 == n % 10) && (n / 10 % 10 == n / 1000 % 10))
            printf(" O numero possui a caracteristica");
        else
            printf(" O numero nao possui a caracteristica");
    }
}
void ex10()
{
    float c;
    int t;
    printf(" Selecione sua categoria:\n\n  Residencial - 1 \n  Comercial - 2 \n  Industrial - 3 \n  ");
    scanf("%d", &t);
    printf("\n Digite seu consumo em metros cubicos: ");
    scanf("%f", &c);
    if (t == 1)
        printf(" Sua conta valera: %.2f reais", 3.5 * c);
    else if (t == 2)
    {
        if (c <= 80)
            printf(" Sua conta valera: 500 reais");
        else
            printf(" Sua conta valera: %.2f reais", 5.5 * (c - 80) + 500);
    }
    else if (t == 3)
    {
        if (c <= 100)
            printf(" Sua conta valera: 800 reais");
        else
            printf(" Sua conta valera: %.2f reais", 8 * (c - 100) + 800);
    }
    else
        printf("\n Digite uma categoria valida\n");
}

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
    printf(" 1a lista de algoritmos e programas em C\n");
exec:
    printf(" Digite um exercio [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 , 15, 16, 17, 18, 19, 20 , 21, 22, 23, 24, 25, 26, 27]: ");
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
    case 15:
        ex15();
        break;
    case 16:
        ex16();
        break;
    case 17:
        ex17();
        break;
    case 18:
        ex18();
        break;
    case 19:
        ex19();
        break;
    case 20:
        ex20();
        break;
    case 21:
        ex21();
        break;
    case 22:
        ex22();
        break;
    case 23:
        ex23();
        break;
    case 24:
        ex24();
        break;
    case 25:
        ex25();
        break;
    case 26:
        ex26();
        break;
    case 27:
        ex27();
        break;
    default:
        printf(" Opcao invalida,");
        exc = 0;
        goto exec;
    }
}
void ex1()
{
    int a, fim;
    printf(" Digite um valor ");
    scanf("%d", &a);
    fim = a + 1;
    printf(" O sucessor de %d e igual a %d", a, fim);
}
void ex2()
{
    int a, b, c, d;
    float fim;
    printf(" Digite o primeiro valor ");
    scanf("%d", &a);
    printf(" Digite o segundo valor ");
    scanf("%d", &b);
    printf(" Digite o terceiro valor ");
    scanf("%d", &c);
    printf(" Digite o quarto valor ");
    scanf("%d", &d);
    fim = (a + b + c + d) / 4;
    printf(" A media entre os valores e igual a %.2f", fim);
}
void ex3()
{
    int values, values_length = 0, sum = 0;
    while (values != 0)
    {
        printf(" Digite os valores (0 para encerrar): ");
        scanf("%d", &values);
        sum += values;
        values_length++;
    }
    printf(" A media dos valores e: %.2f", (float)sum / values_length);
}
void ex4()
{
    float grade_1, grade_2, grade_3, sum;
    int weight_1, weight_2, weight_3;
    printf(" Digite o valor da nota: ");
    scanf("%f", &grade_1);
    printf(" Digite seu peso: ");
    scanf("%d", &weight_1);
    printf(" Digite o valor da nota: ");
    scanf("%f", &grade_2);
    printf(" Digite seu peso: ");
    scanf("%d", &weight_2);
    printf(" Digite o valor da nota: ");
    scanf("%f", &grade_3);
    printf(" Digite seu peso: ");
    scanf("%d", &weight_3);
    sum = (grade_1 * weight_1 + grade_2 * weight_2 + grade_3 * weight_3) / (weight_1 + weight_2 + weight_3);
    printf(" A media ponderada entre os valores e %.2f", sum);
}
void ex5()
{
    float C, F;
    printf(" Digite o valor em Celsius para ser convertido em Fahrenheit: ");
    scanf("%f", &C);
    F = (9 * C / 5) + 32;
    printf(" Temperatura em Fahrenheit: %.2f", F);
}
void ex6()
{
    int choice;
    float C, F;
    printf(" Digite 1 para Celsius ou 0 para Fahrenheit: ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf(" Digite o valor em Celsius para ser convertido em Fahrenheit: ");
        scanf("%f", &C);
        F = (9 * C / 5) + 32;
        printf(" Temperatura em Fahrenheit: %.2f", F);
    }
    else
    {
        printf(" Digite o valor em Fahrenheit para ser convertido em Celsius: ");
        scanf("%f", &F);
        C = 5 * (F - 32) / 9;
        printf(" Temperatura em Fahrenheit: %.2f", C);
    }
}
void ex7()
{
    float salary, raise, salary_final;
    printf(" Digite o salario: ");
    scanf("%f", &salary);
    printf(" Digite o aumento percentual: ");
    scanf("%f", &raise);
    salary_final = salary + salary * raise / 100;
    printf(" O salario final sera: %.2f", salary_final);
}
void ex8()
{
    float h, w, area;
    printf(" Digite a altura: ");
    scanf("%f", &h);
    printf(" Digite a base: ");
    scanf("%f", &w);
    area = h * w / 2;
    printf(" A area do triangulo e: %.5f", area);
}
void ex9()
{
    float ration, nutrition, result;
    printf(" Digite a racao total em quilos: ");
    scanf("%f", &ration);
    printf(" Digite o consumo de cada gato por dia em gramas: ");
    scanf("%f", &nutrition);
    result = ration * 1000 - 5 * nutrition * 2;
    if (result < 0)
        printf(" Seus gatos nao terao comida suficiente.");
    else
        printf(" Sobrarao %.2f gramas de racao", result);
}
void ex10()
{
    float a, b, c;
    printf(" Digite o valor de a: ");
    scanf("%f", &a);
    printf(" Digite o valor de b: ");
    scanf("%f", &b);
    c = a;
    a = b;
    b = c;
    printf(" Seu valor de a: %.2f\n", a);
    printf(" Seu valor de b: %.2f", b);
}
void ex11()
{
    int a, remainder;
    printf(" Digite um numero maior que 7 para descobrir seu resto: ");
    scanf("%d", &a);
    remainder = a % 7;
    printf(" Sua sobra e %d", remainder);
}
void ex12()
{
    float sum, a1, an, n;
    printf(" Digite o primeiro termo: ");
    scanf("%f", &a1);
    printf(" Digite o segundo termo: ");
    scanf("%f", &an);
    printf(" Digite o numero de termos: ");
    scanf("%f", &n);
    sum = n * (a1 + an) / 2;
    printf(" Seu resultado e %f", sum);
}
void ex13()
{
    int a;
    printf(" Digite o termo: ");
    scanf("%d", &a);
    if (a % 2 == 0)
        printf(" 1");
    else
        printf(" 0");
}
void ex14()
{
    int a;
    printf(" Digite o termo: ");
    scanf("%d", &a);
    if (a % 2 == 1 || a == 1)
        printf(" 1");
    else
        printf(" 0");
}
void ex15()
{
    int a;
    printf(" Digite o termo: ");
    scanf("%d", &a);
    if (a % 2 == 1 && a > 100)
        printf(" 1");
    else
        printf(" 0");
}
void ex16()
{
    int a;
    printf(" Digite o termo: ");
    scanf("%d", &a);
    if ((a % 2 == 0 && a < 100) || (a % 2 == 1 && a > 100))
        printf(" 1");
    else
        printf(" 0");
}
void ex17()
{
    int a;
    printf(" Digite o termo: ");
    scanf("%d", &a);
    if (a > 25 && a < 75)
        printf(" 1");
    else
        printf(" 0");
}
void ex18()
{
    int a;
    printf(" Digite o termo: ");
    scanf("%d", &a);
    if (a >= 25 && a <= 75)
        printf(" 1");
    else
        printf(" 0");
}
void ex19()
{
    int a;
    printf(" Digite o termo: ");
    scanf("%d", &a);
    if ((a >= 15 && a <= 45) || (a >= 66 && a <= 99))
        printf(" 1");
    else
        printf(" 0");
}
void ex20()
{
    int a, b;
    printf(" Digite o primeiro termo: ");
    scanf("%d", &a);
    printf(" Digite o segundo termo: ");
    scanf("%d", &b);
    if ((a % 2 == 0) && (b % 2 == 1 || b == 1))
        printf(" 1");
    else
        printf(" 0");
}
void ex21()
{
    int a, b;
    printf(" Digite o primeiro termo: ");
    scanf("%d", &a);
    printf(" Digite o segundo termo: ");
    scanf("%d", &b);
    if ((a % 2 == 0 && a >= 0) && ((b % 2 == 1 || b == 1) && (a < 0)))
        printf(" 1");
    else
        printf(" 0");
}
void ex22()
{
    int a, b;
    printf(" Digite o primeiro termo: ");
    scanf("%d", &a);
    printf(" Digite o segundo termo: ");
    scanf("%d", &b);
    if (a > b)
        printf(" maior");
    else
    {
        if (a < b)
            printf(" menor");
        else
            printf(" igual");
    }
}
void ex23()
{
    int a, b, c;
    printf(" Digite o primeiro termo: ");
    scanf("%d", &a);
    printf(" Digite o segundo termo: ");
    scanf("%d", &b);
    printf(" Digite o terceiro termo: ");
    scanf("%d", &c);
    if (((b > c) && (a < b && a > c)) || (c > b) && (a > b && a < c))
        printf(" 1");
    else
        printf(" 0");
}
void ex24()
{
    int a, b, c;
    printf(" Digite o primeiro termo: ");
    scanf("%d", &a);
    printf(" Digite o segundo termo: ");
    scanf("%d", &b);
    printf(" Digite o terceiro termo: ");
    scanf("%d", &c);
    if (((b > c) && (a < b && a > c)) || (c > b) && (a > b && a < c))
        printf(" 0");
    else
        printf(" 1");
}
void ex25()
{
    char x, y, z;
    printf(" Digite o primeiro termo: ");
    scanf(" %c", &x);
    printf(" Digite o segundo termo: ");
    scanf(" %c", &y);
    printf(" Digite o terceiro termo: ");
    scanf(" %c", &z);
    int a = x;
    int b = y;
    int c = z;
    if (((b > c) && (a < b && a > c)) || (c > b) && (a > b && a < c))
        printf(" 1");
    else
        printf(" 0");
}
void ex26()
{
    char x, y, z;
    printf(" Digite o primeiro termo: ");
    scanf(" %c", &x);
    printf(" Digite o segundo termo: ");
    scanf(" %c", &y);
    printf(" Digite o terceiro termo: ");
    scanf(" %c", &z);
    int a = x;
    int b = y;
    int c = z;
    if (a < b && b < c)
        printf(" 1");
    else
        printf(" 0");
}
void ex27()
{
    char x = 'A', y, z = 'Z';
    printf(" Digite o termo: ");
    scanf(" %c", &y);
    int a = x;
    int b = y;
    int c = z;
    if (a < b && b < c)
        printf(" 1");
    else
        printf(" 0");
}

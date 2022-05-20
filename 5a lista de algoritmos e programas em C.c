#include <math.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
FILE *diary;
main()
{
    printf("\n 5a lista de algoritmos e programas em C\n");
    fclose(diary);
}
int detectaPrimo(int p)
{
    if (p < 2)
        return 0;
    for (int i = 2; i <= p / 2; ++i)
        if (p % i == 0)
            return 0;
    return 1;
}
int fibo(int p, int v[100])
{
    double t = 0, u = 1, s;
    int n1 = 2;
    for (int i = 0; i < 100; i++)
    {
        s = t + u;
        t = u;
        u = s;
        v[i] = 0;
        if (s <= p)
        {
            v[i] = s;
            n1++;
        }
        else
            i = 100;
    }
    if (p == 0)
        n1 = 1;
    if (p < 0)
        n1 = 0;
    return n1;
}
int detectaFibonacci(int p)
{
    int t = 0, u = 1, s;
    for (int i = 0; i < 46; i++) // apos 46, s se torna maior do que o valor limite para int
    {
        s = t + u;
        t = u;
        u = s;
        if (s == p)
            return 1;
    }
    return 0;
}
void matrizPrimo(int m[4][4])
{
    for (int i = 0; i < 16; i++)
        m[i / 4][i % 4] = 0;
    int ar = 0, prime = 1;
    for (int i = 2; i <= 53; i++)
    {
        for (int j = 2; j <= i / 2; j++)
            if (i % j == 0)
                prime = 0;
        if (prime == 1)
        {
            m[ar / 4][ar % 4] = i;
            ar++;
        }
        prime = 1;
    }
}
int mdc(int m[4][4])
{
    int vet[100], k = 0, i, gcd = 0;
    for (i = 0; i < 16; i++)
        for (int j = 1; j <= m[i / 4][i % 4]; j++)
            if (m[0][0] % j == 0 && m[0][1] % j == 0 && m[0][2] % j == 0 && m[0][3] % j == 0 &&
                m[1][0] % j == 0 && m[1][1] % j == 0 && m[1][2] % j == 0 && m[1][3] % j == 0 &&
                m[2][0] % j == 0 && m[2][1] % j == 0 && m[2][2] % j == 0 && m[2][3] % j == 0 &&
                m[3][0] % j == 0 && m[3][1] % j == 0 && m[3][2] % j == 0 && m[3][3] % j == 0)
                if (gcd < j)
                    gcd = j;
    return gcd;
}
int mmc(int m[4][4])
{
    int lcm = m[0][0], gcd = m[0][0];
    for (int i = 1; i < 16; i++)
    {
        gcd = mdc2(m[i / 4][i % 4], lcm);
        lcm = (lcm * m[i / 4][i % 4]) / gcd;
    }
    return lcm;
}
int mdc2(int n, int n1)
{
    int gcd2;
    for (int i = 1; i <= n && i <= n1; i++)
        if (n % i == 0 && n1 % i == 0)
            gcd2 = i;
    return gcd2;
}
int determinante3(int m[3][3])
{
    int det = 0;
    for (int i = 0; i < 3; i++)
        det = det + (m[0][i] * (m[1][(i + 1) % 3] * m[2][(i + 2) % 3] - m[1][(i + 2) % 3] * m[2][(i + 1) % 3]));
    return det;
}
void multiMatriz(int a[2][3], int b[3][2], int c[2][2])
{
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
            sum = sum + a[i / 2][j] * b[j][i % 2];
        c[i / 2][i % 2] = sum;
        sum = 0;
    }
}
int agenda(FILE *f, int a[100])
{
    // enunciado incompreensivel
}
int validaCPF(int cpf[11])
{
    int sum = 0, r1, r2, d1, d2, v;
    for (int i = 0; i < 11; i++)
        if (cpf[i] < 0 || cpf[i] > 9)
            return 0;
    if (cpf[0] == cpf[1] && cpf[1] == cpf[2] &&
        cpf[2] == cpf[3] && cpf[3] == cpf[4] &&
        cpf[4] == cpf[5] && cpf[5] == cpf[6] &&
        cpf[6] == cpf[7] && cpf[7] == cpf[8] &&
        cpf[8] == cpf[9] && cpf[9] == cpf[10])
        return 0;
    for (int i = 0; i < 9; i++)
        sum = sum + cpf[i] * (10 - i);
    r1 = sum % 11;
    if (r1 == 0 || r1 == 1)
        d1 = 0;
    else
        d1 = 11 - r1;
    sum = 0;
    for (int i = 0; i < 10; i++)
        sum = sum + cpf[i] * (11 - i);
    v = (sum / 11) * 11;
    r2 = sum - v;
    if (r2 == 0 || r2 == 1)
        d2 = 0;
    else
        d2 = 11 - r2;
    if (d1 == cpf[9] && d2 == cpf[10])
        return 1;
    else
        return 0;
}

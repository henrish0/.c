#include <conio.h>
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
    printf("\n Tests\n");
exec:
    printf(" Type in a test [1, 2, 3]: ");
    scanf("%i", &exc);
    printf("\n");
    fflush(stdin);
    switch (exc)
    {
    case 1:
        tst1();
        break;
    case 2:
        tst2();
        break;
    case 3:
        tst3();
        break;
    default:
        printf(" Invalid option,");
        exc = 0;
        goto exec;
    }
}
void tst1()
{
    // a better way to read strings
    char str[102];
    for (int i = 0; i < sizeof str; i++)
        str[i] = NULL;
    printf(" Type in your string: ");
    fgets(str, sizeof str, stdin);
    printf("\n ");
    str[strcspn(str, "\n")] = 0;
    for (int j = 0; j <= sizeof str; j++)
        printf("%c", str[j]);
    printf("\n\n");
}
void tst2()
{
    // unsigned data type
    unsigned int i = 0;
    printf(" %u - 1 = %u", i, i - 1);
    i--;
    printf("\n %u + 1 = %u\n\n", i, i + 1);
}
void tst3()
{
    /* will generate a vector of a size you choose, fill it with numbers you choose a range from and return
    the most frequent number, its frequency, how many primes, even and odd, the biggest and the smallest,
    the sum and the arithmetic mean.*/
    bool tof = false;
    int var, t = 0, n, even = 0, odd = 0, s = 60, b = 0, sum = 0, primes = 0;
    printf(" Type in how many random characters you wish to analyse: ");
    scanf(" %i", &var);
    const int sz = var;
    printf(" Type in the span of your characters: ");
    scanf(" %i", &var);
    const int sp = var;
    int vet[sz], loc[sp];
    fflush(stdin);
    for (int i = 0; i < sp; i++)
        loc[i] = 0;
    for (int i = 0; i < sz; i++)
    {
        vet[i] = rand() % (sp) + 1;
        loc[vet[i]]++;
        if (s > vet[i])
            s = vet[i];
        if (b < vet[i])
            b = vet[i];
        sum = sum + vet[i];
        if (vet[i] % 2 == 0)
            even++;
        else
            odd++;
        for (int j = 2; j < vet[i] / 2; ++j)
            if (vet[i] % j == 0)
            {
                tof = true;
                j = vet[i];
            }
        if (tof == false)
            primes++;
        tof = false;
    }
    for (int i = 0; i < sp; i++)
        if (t < loc[i])
        {
            t = loc[i];
            n = i;
        }
    printf("\n The most frequent number was: %i, occurring %i times.\n There are %i prime numbers, %i even numbers and %i odd numbers.\n The greatest integer was: %i, while the smallest was: %i.\n The sum of all terms is: %i and their mean: %i\n\n", n, t, primes, even, odd, b, s, sum, sum / sz);
}

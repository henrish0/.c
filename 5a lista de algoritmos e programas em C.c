// 5a lista de algoritmos e programas em C
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
    int a = 0, b = 1, s = 0, n = 0;
    for (int i = 0; i < 46 && s <= p; i++) // apos 46, s se torna maior do que o valor limite para int
    {
        v[i] = s;
        n++;
        a = b;
        b = s;
        s = b + a;
    }
    return n;
}
int detectaFibonacci(int p)
{
    int a = 0, b = 1, s = 0;
    for (int i = 0; i < 46; i++) // apos 46, s se torna maior do que o valor limite para int
    {
        a = b;
        b = s;
        s = b + a;
        if (s == p)
            return 1;
    }
    return 0;
}
void matrizPrimo(int m[4][4])
{
    int primo = 1, k = 0;
    for (int i = 2; i < 48; i++)
    {
        for (int j = 2; j < i / 2; j++)
            if (i % j == 0)
                primo = 0;
        if (primo == 1)
        {
            m[k / 4][k % 4] = i;
            k++;
        }
        primo = 1;
    }
}
int mdc(int m[4][4])
{
    int i, gcd = 0;
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
// tudo parte da proxima funcao
struct sEndereco
{
    char rua[100];
    char numero[10];
    char complemento[10];
    char bairro[50];
    char cidade[50];
    char estado[3];
    char cep[10];
};
typedef struct sEndereco tEndereco;
struct sContato
{
    char nome[50];
    char telefone[12];
    char email[100];
    tEndereco endereco;
};
typedef struct sContato tContato;
int agenda(FILE *f, tContato a[100])
{
    int i;
    if ((f = fopen("f.txt", "r")) == '\0')
        return 0;
    else
        for (i = 0; strcmp(a[i].nome, "EOF") == 0; i++)
            fscanf(f, "--Nome %s\n--Telefone %s\n--Email %s\n--Rua %s\n--Numero %s\n--Complemento %s\n--Bairro %s\n--Cidade %s\n--Estado %s\n--Cep %s\nfim contato \n", &a[i].nome, &a[i].telefone, &a[i].email, &a[i].endereco.rua, &a[i].endereco.numero, &a[i].endereco.complemento, &a[i].endereco.bairro, &a[i].endereco.cidade, &a[i].endereco.estado, &a[i].endereco.cep);
    return i;
}
int validaCPF(int cpf[11])
{
    int sum = 0, r1, r2, d1, d2, v;
    for (int i = 0; i < 11; i++)
        if (cpf[i] < 0 || cpf[i] > 9)
            return 0;
    if (cpf[0] == cpf[1] && cpf[1] == cpf[2] && cpf[2] == cpf[3] && cpf[3] == cpf[4] && cpf[4] == cpf[5] &&
        cpf[5] == cpf[6] && cpf[6] == cpf[7] && cpf[7] == cpf[8] && cpf[8] == cpf[9] && cpf[9] == cpf[10])
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

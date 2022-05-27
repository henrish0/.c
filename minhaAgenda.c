#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define TAM 200

struct sEndereco
{
    char rua[100];
    char numero[10];
    char complemento[10];
    char bairro[50];
    char cidade[50];
    char estado[3];
    char cep[15];

};

typedef struct sEndereco tEndereco;

struct sAmigo
{
    char nome[50];
    char celular[15];
    char email[100];
    tEndereco endereco;
};

typedef struct sAmigo tAmigo;

tAmigo agenda[TAM];

struct sAmigo inicializaAmigo(char p1[], char p2[],char p3[],char p4[], char p5[],char p6[],char p7[], char p8[], char p9[], char p10[])
{
    tAmigo x;

    strcpy(x.nome,p1);
    strcpy(x.celular,p2);
    strcpy(x.email,p3);
    strcpy(x.endereco.rua,p4);
    strcpy(x.endereco.numero,p5);
    strcpy(x.endereco.complemento,p6);
    strcpy(x.endereco.bairro,p7);
    strcpy(x.endereco.cidade,p8);
    strcpy(x.endereco.estado,p9);
    strcpy(x.endereco.cep,p10);

    return x;
}

void printAmigo(tAmigo p)
{
    printf("\nAmigo -----------");
    printf("\n  nome:%s",p.nome);
    printf("\n  cel:%s",p.celular);
    printf("\n  email:%s",p.email);
    printf("\n  endereco:");
    printf("\n     rua %s, %s, %s",p.endereco.rua, p.endereco.numero, p.endereco.complemento);
    printf("\n     %s, %s, %s",p.endereco.cidade, p.endereco.estado, p.endereco.cep);
    printf("\n");
}

void tratarOpcao(int p)
{

    if (p == 1)
        IncluirAmigo();
    else if (p == 2)
        excluirAmigo();
    else if (p == 3)
        alterarAmigo();
    else if (p == 4)
        pesquisarPorNome();
    else if (p == 5)
        listaNomeETelefone();
    else if (p == 6)
        listarAmigo();
}

int buscaEXATAPorNome(char p[])
{
    int i, r;
    r = -1;
    for (i = 0; i<TAM && strcmp(agenda[i].nome,"EOF") != 0 ; i++)
    {
        if (strcasecmp(p,agenda[i].nome) == 0)
        {
            r = i;
            i = TAM;
        }
    }
    return r;
}

void IncluirAmigo()
{
    tAmigo p;
    int i;

    system("cls");
    printf("\n-- Inclusao de um contato -------\n");
    printf("\n\nDigite o nome: ");
    scanf(" %[^\n]",&p.nome);

    if ( buscaEXATAPorNome(p.nome) >= 0 )
    {
        printf("\n\nNao é possivel incluir. Contato existente");
    }
    else
    {
        printf("  cel: ");
        scanf(" %s",&p.celular);
        printf("  email: ");
        scanf("%s",&p.email);
        printf("  endereco:");
        printf("\n     rua: ");
        scanf(" %[^\n]",&p.endereco.rua);
        printf("     nro: ");
        scanf("%s",&p.endereco.numero);
        printf("     complemento: ");
        scanf(" %[^\n]",&p.endereco.complemento);
        printf("     bairro: ");
        scanf(" %[^\n]",&p.endereco.bairro);
        printf("     cidade: ");
        scanf(" %[^\n]",&p.endereco.cidade);
        printf("     estado: ");
        scanf("%s",&p.endereco.estado);
        printf("     cep: ");
        scanf("%s",&p.endereco.cep);

        i = proximoIndice();
        agenda[i] = p;
        strcpy( agenda[i+1].nome, "EOF");
        printf("\n\nContato %s incluido.",p.nome);
    }
}

void excluirAmigo()
{
    char p[150];
    int i;

    system("cls");
    printf("\n-- Exclusao do contato --------\n");
    printf("\n\nDigite o nome: ");
    scanf(" %[^\n]",&p);

    i = buscaEXATAPorNome(p);
    if ( i < 0 )
    {
        printf("\n\nNao é possivel excluir. Contato inexistente");
    }
    else
    {
        while( i<TAM && strcmp(agenda[i].nome,"EOF") != 0 )
        {
            agenda[i] = agenda[i+1];
            i++;
        }
        printf("\n\nContato %s excluido.",p);
    }
}

void alterarAmigo()
{
    char p[150];
    char opcao[1];
    int i;

    system("cls");
    printf("\n-- Alterar os dados contato -------\n");
    printf("\n\nDigite o nome: ");
    scanf(" %[^\n]",&p);

    i = buscaEXATAPorNome(p);
    if ( i < 0 )
    {
        printf("\n\nNao é possivel alterar. Contato existente");
    }
    else
    {
        printf("  cel: %s. Deseja alterar (s/n)? ",agenda[i].celular);
        scanf("%s",opcao);
        if (strcasecmp(opcao,"s") == 0)
        {
            printf("digite o novo celular :");
            scanf("%s",&p);
            strcpy(agenda[i].celular,p);
        }

    }
}

int pesquisarPorNome()
{
    char p[150];

    system("cls");
    printf("\n--------- Lista dos amigos com filtro ----------\n");
    printf("digite o filtro para o nome : ");
    scanf("%s",&p);

    printf("\n\nNumero, nome, celular, cep");

    for (int i = 0; i<TAM && strcmp(agenda[i].nome,"EOF") != 0; i++)
    {
        if ( myStrCmp(p,agenda[i].nome) == 0)
            printf("\n%d, %s, %s, %s",i,agenda[i].nome, agenda[i].celular,agenda[i].endereco.cep);
    }
    printf("\n\n");

}

void listaNomeETelefone()
{
    system("cls");
    printf("\n--------- Lista dos amigos ----------\n");
    printf("\nnumero, nome, celular, cep");
    for (int i=0; i<TAM && strcmp(agenda[i].nome,"EOF") != 0; i++)
    {
        printf("\n%d, %s, %s, %s",i,agenda[i].nome, agenda[i].celular,agenda[i].endereco.cep);
    }
    printf("\n\n");
}

void listarAmigo()
{
    system("cls");
    printf("\n--------- Lista dos amigos ----------\n");
    for (int i=0; i<TAM && strcmp(agenda[i].nome,"EOF") != 0; i++)
    {
        printAmigo(agenda[i]);
    }

}

int proximoIndice()
{
    int i, r;
    r = -1;
    for (i = 0; i<TAM; i++)
    {
        if (strcasecmp("EOF",agenda[i].nome) == 0)
        {
            r = i;
            i = TAM;
        }
    }
    return r;
}

int myStrCmp(char p1[], char p2[2])
{
    char x[150];
    int r, i;
    if (strlen(p1) < strlen(p2))
    {
        for (i=0; i<strlen(p1); i++) {
            x[i]=p2[i];
        }

        x[i]='\0';
        r = strcasecmp(p1,x);
    }
    else
        r = strcasecmp(p1,p2);
    return r;
}

void carregaDadosDoArquivo()
{
    FILE *arquivo;
    tAmigo contato;
    char p1[150];
    char p2[150];
    int ret, i = 0 ;

    // abre o arquivo
    arquivo = fopen("agenda.txt","r");

    // se o arquivo pode ser aberto para leitura
    if (arquivo != NULL)
    {
        // loop de leitura do arquivo
        ret = fscanf(arquivo,"%s %[^\n]", &p1, &p2);
        while (ret != EOF)
        {

            // identifica que é um novo registro
            if (strcasecmp(p1,"inicio") == 0)
            {
                strcpy(contato.nome,"");
                strcpy(contato.email,"");
                strcpy(contato.celular,"");
            }
            // processa cada um dos componente da estrutura
            else if (strcasecmp(p1,"--nome") == 0)
            {
                strcpy(contato.nome,p2);
            }
            else if (strcasecmp(p1,"--celular") == 0)
            {
                strcpy(contato.celular,p2);
            }
            else if (strcasecmp(p1,"--email") == 0)
            {
                strcpy(contato.email,p2);
            }
            else if (strcasecmp(p1,"--rua") == 0)
            {
                strcpy(contato.endereco.rua,p2);
            }
            else if (strcasecmp(p1,"--nro") == 0)
            {
                strcpy(contato.endereco.numero,p2);
            }
            else if (strcasecmp(p1,"--comp") == 0)
            {
                strcpy(contato.endereco.complemento,p2);
            }
            else if (strcasecmp(p1,"--bairro") == 0)
            {
                strcpy(contato.endereco.bairro,p2);
            }
            else if (strcasecmp(p1,"--cidade") == 0)
            {
                strcpy(contato.endereco.cidade,p2);
            }
            else  if (strcasecmp(p1,"--estado") == 0)
            {
                strcpy(contato.endereco.estado,p2);
            }
            else if (strcasecmp(p1,"--cep") == 0)
            {
                strcpy(contato.endereco.cep,p2);
            }
            // muda a posição do vetor
            else if (strcasecmp(p1,"fim") == 0)
            {
                agenda[i] = contato;
                i = i + 1;
            }
            // lendo o proximo registro dentro da lógica do loop
            ret = fscanf(arquivo,"%s %[^\n]", &p1, &p2);
        }

        strcpy(agenda[i].nome,"EOF");
    }
}

void salvaDadosDoArquivo()
{
    FILE *arquivo ;
    int i = 0 ;
    arquivo = fopen("agenda.txt","w");
    if (arquivo != NULL)
    {
        while (strcmp("EOF",agenda[i].nome) != 0)
        {

            fprintf(arquivo,"inicio contato \n");
            fprintf(arquivo,"--Nome %s\n",agenda[i].nome);
            fprintf(arquivo,"--Email %s\n",agenda[i].email);
            fprintf(arquivo,"--Celular %s\n",agenda[i].celular);
            fprintf(arquivo,"--Rua %s\n",agenda[i].endereco.rua);
            fprintf(arquivo,"--Nro %s\n",agenda[i].endereco.numero);
            fprintf(arquivo,"--Comp %s\n",agenda[i].endereco.complemento);
            fprintf(arquivo,"--Bairro %s\n",agenda[i].endereco.bairro);
            fprintf(arquivo,"--Cidade %s\n",agenda[i].endereco.cidade);
            fprintf(arquivo,"--Estado %s\n",agenda[i].endereco.estado);
            fprintf(arquivo,"--Cep %s\n",agenda[i].endereco.cep);
            fprintf(arquivo,"fim contato \n");

            i = i + 1;
        }
        fclose(arquivo);
    }
}

// funcao principal - entry point de execução do programa
int main()
{
    carregaDadosDoArquivo();
/*
        // simula uma carga atraves da inicialização do vetor
            tAmigo a ;
            agenda[0] = inicializaAmigo("Joao Luiz","31-99990-1231","Joaoluiz@gmail","rua da luz","692","casa","Santa Lucia","Belo Horizonte","MG","30.110-111");
            //printf("\n.....%s, %s, %s",agenda[0].nome, agenda[0].celular,agenda[0].endereco.cep);
            agenda[1] = inicializaAmigo("Ana Maria","31-99990-1232","Joaoluiz@gmail","rua da luz","692","casa","Santa Lucia","Belo Horizonte","MG","30.110-112");
            agenda[2] = inicializaAmigo("Zoroastro","31-99990-1233","Joaoluiz@gmail","rua da luz","692","casa","Santa Lucia","Belo Horizonte","MG","30.110-113");
            agenda[3] = inicializaAmigo("Otelo","31-99990-1234","Joaoluiz@gmail","rua da luz","692","casa","Santa Lucia","Belo Horizonte","MG","30.110-114");
            agenda[4] = inicializaAmigo("Daise","31-99990-1235","Joaoluiz@gmail","rua da luz","692","casa","Santa Lucia","Belo Horizonte","MG","30.110-115");
            agenda[5] = inicializaAmigo("Henrique","31-99999-6666","henrique@hot","rua da felicidade","1000","apto 101","bla","blu","mg","12345-123");
            strcpy(agenda[6].nome,"EOF");
*/
    int opcao = 0;

    while (opcao != 9)
    {
        system("cls");
        printf("\n------- Agenda de Amigos---------\n");
        printf("\n1.Incluir ");
        printf("\n2.Excluir ");
        printf("\n3.Alterar ");
        printf("\n4.Pesquisar por nome");
        printf("\n5.Listar nome e telefone ");
        printf("\n6.Listar tudo ");
        printf("\n9.Encerrar ");

        printf("\n\ndigite sua opcao : ");
        scanf(" %d",&opcao);
        if (opcao >=1 && opcao <=6)
        {
            tratarOpcao(opcao);
            printf("\n\n");
            system("pause");
        }
    }

    salvaDadosDoArquivo();
    return 0;
}


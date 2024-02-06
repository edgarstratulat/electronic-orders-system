#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
    char user[60];
    int idade;
    char email[60];
    char passe[60];
    char confirmacaopasse[60];
    char tel[9];
} Utilizador;

typedef struct
{
    char nome[50];
    int quantidade;
    float custo;
} componente;

typedef struct
{
    char nome[50];
    int ncomp;
    componente componentes[20];
} loja;

// Array utilizadores
Utilizador utilizadores[10];
int NumUtilizador = 0;

// Array Lojas
loja lojas[5];
int nlojas = 0;

// Função registo
void registo(Utilizador utilizadores[]);

// Função login
int login(Utilizador utilizadores[], int NumUtilizador);

// Função Pesquisar por loja
void pesquisarPorLoja(const loja lojas[], int nlojas, const char *nomeLoja);

void pesquisarPorComponente(const loja lojas[], int nlojas, const char *nomeComponente);

int validarNome(const char *letra)
{
    while (*letra)
    {
        if (!isalpha(*letra))
        {
            return 0;
        }
        letra++;
    }
    return 1;
}

int validarNumero(const char *numero)
{
    while (*numero)
    {
        if (!isdigit(*numero))
        {
            return 0;
        }
        numero++;
    }
    return 1;
}

void limparBuffer()
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

void registo(Utilizador utilizadores[])
{
    Utilizador NovoUtilizador;
    fflush(stdin);

    // Validação para o nome
    do
    {
        printf("Nome de Utilizador: ");
        scanf("%s", NovoUtilizador.user);
        if (!validarNome(NovoUtilizador.user))
        {
            printf("O nome de utilizador só deve conter letras!\n");
        }
    } while (!validarNome(NovoUtilizador.user));

    // Validação para a idade
    do
    {
        printf("Idade: ");
        scanf("%d", &NovoUtilizador.idade);
        if (NovoUtilizador.idade <= 0)
        {
            printf("Idade não pode ser menor que 0\n");
        }
    } while (NovoUtilizador.idade <= 0);

    // Validação para o email
    do
    {
        printf("Email: ");
        scanf("%s", NovoUtilizador.email);
        if (!strchr(NovoUtilizador.email, '@'))
        {
            printf("O email deve conter @\n");
        }
    } while (!strchr(NovoUtilizador.email, '@'));

    // Validar número
    do
    {
        printf("Número de Telemóvel: ");
        scanf("%s", NovoUtilizador.tel);
        if (!validarNumero(NovoUtilizador.tel))
        {
            printf("O número de telemóvel só deve conter números\n");
        }
    } while (!validarNumero(NovoUtilizador.tel));

    // Confirmação palavra-passe
    do
    {
        printf("Palavra-passe: ");
        scanf("%s", NovoUtilizador.passe);
        printf("Confirmar Palavra-passe: ");
        scanf("%s", NovoUtilizador.confirmacaopasse);
        if (strcmp(NovoUtilizador.passe, NovoUtilizador.confirmacaopasse) != 0)
        {
            printf("As palavras passes não coincidem!\n");
        }
    } while (strcmp(NovoUtilizador.passe, NovoUtilizador.confirmacaopasse) != 0);

    utilizadores[NumUtilizador++] = NovoUtilizador;

    printf("Registo concluído com sucesso!\n");
}

int login(Utilizador utilizadores[], int numUtilizador)
{
    Utilizador UtilizadorExistente;

    printf("Email: ");
    scanf("%s", UtilizadorExistente.email);

    printf("Palavra-passe: ");
    scanf("%s", UtilizadorExistente.passe);

    for (int i = 0; i < numUtilizador; i++)
    {
        if (strcmp(UtilizadorExistente.email, utilizadores[i].email) == 0 &&
            strcmp(UtilizadorExistente.passe, utilizadores[i].passe) == 0)
        {
            return i; // Retorna a posição do utilizador no array
        }
    }

    return -1; // Retorna -1 se o login falhar
}

void menuUtilizador(Utilizador utilizador, const loja lojas[], int nlojas)
{
    int opcao;

    printf("\nMenu Utilizador\n");
    printf("Selecione uma opção!\n");
    printf("1. Pesquisar por Loja\n");
    printf("2. Pesquisar por componente eletrônico\n");
    printf("3. Sair\n");

    while (1)
    {
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao)
        {
        case 1:
            printf("Opção 1 selecionada\n");
            printf("Lojas disponíveis:\n");
            for (int i = 0; i < nlojas; i++)
            {
                printf("%d. %s\n", i + 1, lojas[i].nome);
            }
            int escolha;
            printf("Escolha a loja (1-%d): ", nlojas);
            scanf("%d", &escolha);
            if (escolha >= 1 && escolha <= nlojas)
            {
                pesquisarPorLoja(lojas, nlojas, lojas[escolha - 1].nome);
            }
            else
            {
                printf("Escolha inválida!\n");
            }
            break;
        case 2:
            printf("Opção 2 selecionada\n");
            char nomeComponente[50];
            printf("Digite o nome do componente: ");
            scanf("%s", nomeComponente);
            limparBuffer();
            pesquisarPorComponente(lojas, nlojas, nomeComponente);
            break;
            break;
        case 3:
            printf("Até já!\n");
            return;
        default:
            printf("Opção inválida!\n");
            break;
        }
    }
}

void pesquisarPorLoja(const loja lojas[], int nlojas, const char *nomeLoja)
{
    int encontrou = 0;

    for (int i = 0; i < nlojas; i++)
    {
        if (strcmp(lojas[i].nome, nomeLoja) == 0)
        {
            encontrou = 1;
            printf("Loja: %s\n", lojas[i].nome);
            printf("Componentes disponíveis:\n");
            for (int j = 0; j < lojas[i].ncomp; j++)
            {
                printf("%d - %s - Quantidade: %d - Preço: %.2f\n", j + 1, lojas[i].componentes[j].nome,
                       lojas[i].componentes[j].quantidade, lojas[i].componentes[j].custo);
            }
            break;
        }
    }
    if (!encontrou)
    {
        printf("Loja não encontrada.\n");
    }
}

void pesquisarPorComponente(const loja lojas[], int nlojas, const char *nomeComponente)
{
    int encontrou = 0;

    for (int i = 0; i < nlojas; i++)
    {
        for (int j = 0; j < lojas[i].ncomp; j++)
        {
            if (strcmp(lojas[i].componentes[j].nome, nomeComponente) == 0)
            {
                encontrou = 1;
                printf("Componente encontrado na loja: %s\n", lojas[i].nome);
                printf("Nome: %s - Quantidade: %d - Preço: %.2f\n", lojas[i].componentes[j].nome,
                       lojas[i].componentes[j].quantidade, lojas[i].componentes[j].custo);
            }
        }
    }

    if (!encontrou)
    {
        printf("Componente não encontrado em nenhuma loja.\n");
    }
}

int main()
{

    // Loja 1
    strcpy(lojas[0].nome, "EletroFun");
    lojas[0].componentes[0].custo = 0.1;
    lojas[0].componentes[1].custo = 25;
    strcpy(lojas[0].componentes[0].nome, "resistencia 2.2kohm");
    strcpy(lojas[0].componentes[1].nome, "arduino");
    lojas[0].componentes[0].quantidade = 1000;
    lojas[0].componentes[1].quantidade = 50;
    lojas[0].ncomp = 2;
    nlojas++;

    // Loja 2
    strcpy(lojas[1].nome, "Castro Eletronica");
    lojas[1].componentes[0].custo = 0.1;
    lojas[1].componentes[1].custo = 0.5;
    strcpy(lojas[1].componentes[0].nome, "resistencia 10ohm 100W");
    strcpy(lojas[1].componentes[1].nome, "ligadores");
    lojas[1].componentes[0].quantidade = 500;
    lojas[1].componentes[1].quantidade = 150;
    lojas[1].ncomp = 2;
    nlojas++;

    // Loja 3
    strcpy(lojas[2].nome, "Mauser");
    lojas[2].componentes[0].custo = 20;
    lojas[2].componentes[1].custo = 0.2;
    strcpy(lojas[2].componentes[0].nome, "disjuntor");
    strcpy(lojas[2].componentes[1].nome, "sensor ldr");
    lojas[2].componentes[0].quantidade = 50;
    lojas[2].componentes[1].quantidade = 500;
    lojas[2].ncomp = 2;
    nlojas++;

    int opcao;
    int usuarioAutenticado = 0;

    do
    {
        printf("Bem-vindo a loja de eletrónicos!\n\n");
        printf("Selecione uma opção!\n");
        printf("1. Registar\n");
        printf("2. Entrar\n");
        printf("3. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Opção 1 selecionada!\n\n");
            registo(utilizadores);
            break;

        case 2:
            printf("Opção 2 selecionada!\n");
            int indiceUsuario = login(utilizadores, NumUtilizador);
            if (indiceUsuario != -1)
            {
                printf("Login bem-sucedido!\n");
                usuarioAutenticado = 1;
                menuUtilizador(utilizadores[indiceUsuario], lojas, nlojas);
            }
            else if (usuarioAutenticado)
            {
                printf("Opção do menu selecionada!\n");
            }
            else
            {
                printf("Email ou Palavra-passe incorretos. Tente novamente.\n");
            }
            break;

        case 3:
            printf("Tenha um bom dia!\n");
            break;

        default:
            printf("Opção inválida!\n");
            break;
        }
    } while (opcao != 3);
    return 0;
}

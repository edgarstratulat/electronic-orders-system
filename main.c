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

// Array utilizadores
Utilizador utilizadores[10];

// Função registo
void registo(Utilizador utilizadores[]);

// Função login
void login(Utilizador utilizadores[]);

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

    printf("Registo concluído com sucesso!");
}

void login(Utilizador utilizadores[])
{
    Utilizador UtilizadorExistente;

    printf("Email:\n");
    scanf("%s", UtilizadorExistente.email);
    printf("Palavra-passe:\n");
    scanf("%s", UtilizadorExistente.passe);
}

int main()
{

    int opcao;

    printf("Bem-vindo a loja de eletrónicos!\n\n");
    printf("Selecione uma opção!\n");
    printf("1. Registar\n");
    printf("2. Entrar\n");
    printf("3. Sair\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    // Switch para selecionar opções do menu
    switch (opcao)
    {
    case 1:
        printf("Opção 1 selecionada!\n\n");
        registo(utilizadores);

        break;

    case 2:
        printf("Opção 2 selecionada!\n");
        login(utilizadores);
        break;

    case 3:
        printf("Tenha um bom dia!\n");
        break;

    default:
        printf("Opção inválida!");
        break;
    }
}
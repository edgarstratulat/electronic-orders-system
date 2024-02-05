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
int NumUtilizador = 0;

// Função registo
void registo(Utilizador utilizadores[]);

// Função login
int login(Utilizador utilizadores[], int NumUtilizador);

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
            return 1;
        }
    }

    return 0;
}

int main()
{
    int opcao;
    int opcaologin;
    int usuarioAutenticado = 0; // Adicionada variável para controlar autenticação

    do
    {
        printf("Bem-vindo a loja de eletrónicos!\n\n");

        if (usuarioAutenticado)
        {
            // Se o usuário estiver autenticado, exibir menu
            printf("Selecione uma opção\n");
            printf("1. Pesquisar por Loja\n");
            printf("2. Pesquisar por produto\n");
            printf("3. Carrinho de Compras\n");
            printf("4. Sair\n");
            printf("Opção: ");
            scanf("%d", &opcaologin);
        }
        else
        {
            // Se o usuário não estiver autenticado, exibir opções de login/registo
            printf("Selecione uma opção!\n");
            printf("1. Registar\n");
            printf("2. Entrar\n");
            printf("3. Sair\n");
            printf("Opção: ");
            scanf("%d", &opcao);
        }

        switch (opcao)
        {
        case 1:
            printf("Opção 1 selecionada!\n\n");
            registo(utilizadores);
            break;

        case 2:
            printf("Opção 2 selecionada!\n");
            if (!usuarioAutenticado && login(utilizadores, NumUtilizador))
            {
                // Apenas autenticar se o usuário não estiver autenticado
                printf("Login bem-sucedido!\n");
                usuarioAutenticado = 1; // Atualizar o status de autenticação
            }
            else if (usuarioAutenticado)
            {
                // Opções do menu após o login bem-sucedido
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

    switch (opcaologin)
    {

        // Mais cases que falta
    case 4:
        printf("Tenha um bom dia!\n");
        break;
    
    default:
        break;
    }

    return 0;
}
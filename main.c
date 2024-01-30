#include <stdio.h>

typedef struct
{
    char user[60];
    int idade;
    char email[60];
    char passe[60];
    char tel[9];
} Utilizador;

// Array
Utilizador utilizadores[];

void registo();

int main()
{

    int opcao;

    printf("Bem-vindo a loja de eletrónicos!\n\n");
    printf("Selecione uma opção!\n\n");
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
        registo();
        break;

    case 2:
        printf("Opção 2 selecionada!\n");
        break;

    case 3:
        printf("Tenha um bom dia!\n");
        break;

    default:
        printf("Opção inválida!");
        break;
    }
}

// Função registo
void registo()
{

    Utilizador NovoUtilizador;

    printf("Nome de Utilizador:\n");
    scanf("%s", &NovoUtilizador.user);
    printf("Idade:\n");
    scanf("%d", &NovoUtilizador.idade);
    printf("Email:\n");
    scanf("%s", &NovoUtilizador.email);
    printf("Número de Telefone:\n");
    scanf("%s", &NovoUtilizador.tel);
    printf("Palavra-passe:\n");
    scanf("%s", &NovoUtilizador.passe);

    printf("Registo concluído com sucesso!");
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// estruturas
typedef struct
{
    char nome[100];
    char telefone_celular[20];
    char telefone_fixo[20];
    char telefone_residencia[20];
    char telefone_trabalho[20];
    char data_aniversario[11];
    char email[100];
} AGENDA;

// declarando as funcoes
void adicionarContato(AGENDA *contatos, int quant_contatos);
void dadosAgenda();
void alterarContato(AGENDA *contato, int tamanho, const char *nome);
void listarContatos(AGENDA *contato, int tamanho);
void apagarContato(AGENDA *contato, int *tamanho, const char *nome);
void ordenarNomes(AGENDA *contato, int tamanho);
void exibirTamanhoAgenda(int tamanho);
void exibirPosicaoElemento(AGENDA *contato, int tamanho);

int main()
{
    int opcao, quant_contatos = 0;
    AGENDA contatos[100];

    do
    {
        dadosAgenda();
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            adicionarContato(contatos, quant_contatos);
            quant_contatos++;
            break;
        case 2:
        {
            char nome[100];
            printf("Digite o nome do contato que deseja apagar: ");
            scanf(" %99[^\n]", nome);
            apagarContato(contatos, &quant_contatos, nome);
            break;
        }

        case 3:
        {
            char nome[100];
            printf("Digite o nome do contato que deseja alterar: ");
            scanf(" %99[^\n]", nome);
            alterarContato(contatos, quant_contatos, nome);
            break;
        }
        case 4:
            listarContatos(contatos, quant_contatos);
            break;
        case 5:
            ordenarNomes(contatos, quant_contatos);
            printf("\nA agenda foi organizada com sucesso! Para conferir, acesse a opcao 4 (listar contatos)!\n");
            break;
        case 6:
            exibirTamanhoAgenda(quant_contatos);
            break;
        case 7:
            exibirPosicaoElemento(contatos, quant_contatos);
            break;
        case 8:
            printf("\nsaindo...");
            break;

        default:
            printf("Opcao invalida, tente novamente");
            break;
        }
    } while (opcao != 8 && (1 <= opcao && opcao <= 8));
}

// funcoes para separar dps
void dadosAgenda()
{
    printf("\n---Agenda pessoal---\n"
           "1 - Adicionar contato\n"
           "2 - Apagar contato\n"
           "3 - Alterar contato\n"
           "4 - Listar contatos\n"
           "5 - Ordenar contatos por nome\n"
           "6 - Exibir tamanho da agenda\n"
           "7 - Exibir posicao de cada elemento\n"
           "8 - Sair\n"
           "Escolha a opcao: ");
}

void adicionarContato(AGENDA *contatos, int quant_contatos)
{
    if (quant_contatos >= 100)
    {
        printf("A agenda já está cheia.\n");
        return;
    }
    printf("Informe o nome do contato: ");
    scanf(" %99[^\n]", contatos[quant_contatos].nome);

    for (int i = 0; i < quant_contatos; i++)
    {
        if (strcmp(contatos[i].nome, contatos[quant_contatos].nome) == 0)
        {
            printf("Erro: Já existe um contato com esse nome na agenda.\n");
            return;
        }
    }
    printf("Informe o telefone celular do contato: ");
    scanf(" %19[^\n]", contatos[quant_contatos].telefone_celular);
    printf("Informe o telefone fixo do contato: ");
    scanf(" %19[^\n]", contatos[quant_contatos].telefone_fixo);
    printf("Informe o telefone residencial do contato: ");
    scanf(" %19[^\n]", contatos[quant_contatos].telefone_residencia);
    printf("Informe o telefone do trabalho do contato: ");
    scanf(" %19[^\n]", contatos[quant_contatos].telefone_trabalho);
    printf("Informe a data de aniversário do contato: ");
    scanf(" %10[^\n]", contatos[quant_contatos].data_aniversario);
    printf("Informe o email do contato: ");
    scanf(" %99[^\n]", contatos[quant_contatos].email);

    printf("\nAdicionando...\n");
    printf("\nAdicionado!\n\n");
}

void apagarContato(AGENDA *contato, int *tamanho, const char *nome)
{
    int encontrado = 0;
    for (int i = 0; i < *tamanho; i++)
    {
        if (strcmp(contato[i].nome, nome) == 0)
        {
            encontrado = 1;
            // Desloca os contatos uma posição para frente para "apagar" o contato
            for (int j = i; j < (*tamanho) - 1; j++)
            {
                contato[j] = contato[j + 1];
            }
            (*tamanho)--;
            printf("Contato \"%s\" apagado com sucesso.\n", nome);
            break;
        }
    }
    if (!encontrado)
    {
        printf("Contato \"%s\" não encontrado.\n", nome);
    }
}

void alterarContato(AGENDA *contato, int tamanho, const char *nome)
{
    int encontrado = 0;
    for (int i = 0; i < tamanho; i++)
    {
        if (strcmp(contato[i].nome, nome) == 0)
        {
            encontrado = 1;
            printf("Digite as novas informações para o contato %s:\n", nome);
            printf("Infome o nome do contato: ");
            scanf(" %99[^\n]", contato[i].nome);
            printf("Infome o telefone celular do contato: ");
            scanf(" %19[^\n]", contato[i].telefone_celular);
            printf("Infome o telefone fixo do contato: ");
            scanf(" %19[^\n]", contato[i].telefone_fixo);
            printf("Infome o telefone residencial do contato: ");
            scanf(" %19[^\n]", contato[i].telefone_residencia);
            printf("Infome o telefone do trabalho do contato: ");
            scanf(" %19[^\n]", contato[i].telefone_trabalho);
            printf("Infome a data de aniversario do contato: ");
            scanf(" %10[^\n]", contato[i].data_aniversario);
            printf("Infome o email do contato: ");
            scanf(" %99[^\n]", contato[i].email);
            printf("Contato \"%s\" alterado com sucesso.\n", nome);
            break;
        }
    }
    if (!encontrado)
    {
        printf("Contato \"%s\" não encontrado.\n", nome);
    }
}

void listarContatos(AGENDA *contato, int tamanho)
{
    printf("\n---*Lista de contatos*---\n");
    if (tamanho == 0)
    {
        printf("\nNao ha nenhum contato salvo!\n\n");
    }
    for (int i = 0; i < tamanho; i++)
    {
        printf("--Contato %d--\n", i + 1);
        printf("Nome: %s\n", contato[i].nome);
        printf("Telefone celular: %s\n", contato[i].telefone_celular);
        printf("Telefone fixo: %s\n", contato[i].telefone_fixo);
        printf("Telefone residencial: %s\n", contato[i].telefone_residencia);
        printf("Telefone de trabalho: %s\n", contato[i].telefone_trabalho);
        printf("Data de nascimento: %s\n", contato[i].data_aniversario);
        printf("Email: %s\n\n", contato[i].email);
    }
}
void ordenarNomes(AGENDA *contato, int tamanho)
{
    for (int i = 0; i < tamanho - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < tamanho; j++)
        {
            if (strcmp(contato[j].nome, contato[min_index].nome) < 0)
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            AGENDA temp = contato[i];
            contato[i] = contato[min_index];
            contato[min_index] = temp;
        }
    }
}
void exibirTamanhoAgenda(int tamanho)
{
    printf("\nO tamanho da agenda é: %d\n\n", tamanho);
}
void exibirPosicaoElemento(AGENDA *contato, int tamanho)
{
    printf("\n---*Posição de cada elemento na agenda*---\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("Nome: %s - Posição: %d\n", contato[i].nome, i + 1);
    }
    printf("\n");
}

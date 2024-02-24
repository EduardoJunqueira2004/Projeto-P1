//___________________________________________________________________________Serviços.h____________________________________________________

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <locale.h>
#include <unistd.h>
#include <sys/types.h>
#include "structs.h"
#include "funcoes.h"
#include "Clear.h"

void AdicionarServicos(servico **servicos, int *numservico, int *idservico)
{

    printf("|___________Adicionar Serviços___________|\n");

    // Criar um novo nó da lista encadeada
    servico *novo = (servico *)malloc(sizeof(servico));
    if (novo == NULL)
    {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    // Preencher os dados do serviço
    printf("\n\tNome do Serviço:\n");
    scanf("%s", novo->nome);
    printf("\n\tPreço:\n");
    scanf("%f", &novo->preco);
    printf("\n\tId do serviço:\n");
    scanf("%d", &novo->idservico);
    printf("\n\t Insira o Modelo da Matricula\n");
    scanf("%9s", novo->matricula);

    // Verificar se o ID de serviço já existe
    servico *atual = *servicos;
    while (atual != NULL)
    {
        if (atual->idservico == novo->idservico)
        {
            printf("ID de serviço já existente.\n");
            free(novo);
            return;
        }
        atual = atual->next;
    }

    // Adicionar o novo nó no início da lista encadeada
    novo->next = *servicos;
    *servicos = novo;

    (*numservico)++;
}

void EditarServicos(servico *servicos, int numservico)
{
    int id;
    ClearTerminal();
    printf("|___________Editar Serviços___________|\n");

    printf("Insira o ID do Serviço que deseja editar: ");
    scanf("%d", &id);

    for (int i = 0; i < numservico; i++)
    {
        if (servicos[i].idservico == id)
        {
            printf("\n\tNome do Serviço: ");
            scanf("%s", servicos[i].nome);
            printf("\tPreço: ");
            scanf("%f", &servicos[i].preco);
            printf("\tId do serviço: ");
            scanf("%d", &servicos[i].idservico);
            printf("\tInsira o Modelo da Matricula: ");
            scanf("%9s", servicos[i].matricula);

            return;
        }
    }

    printf("Serviço com o ID %d não encontrado.\n", id);
}

void RemoverServicos(struct servico **servicos, int *numservico)
{
    int idservico;
    ClearTerminal();
    printf("\n\t|___________Remover Serviços___________|\n");
    printf("Insira o ID do Serviço que deseja remover: ");
    scanf("%d", &idservico);

    for (int i = 0; i < *numservico; i++)
    {
        if ((*servicos)[i].idservico == idservico)
        {
            // Remover o serviço
            for (int j = i; j < *numservico - 1; j++)
            {
                (*servicos)[j] = (*servicos)[j + 1];
            }
            (*numservico)--;
            printf("Serviço com ID '%d' removido com sucesso.\n", idservico);
            return;
        }
    }

    printf("Serviço com o ID '%d' não encontrado.\n", idservico);
}

void ListarServicos(struct servico *servicos, int numServicos)
{
    ClearTerminal();
    printf("|_________Lista de serviços_________|:\n");
    for (int i = 0; i < numServicos; i++)
    {
        printf("Nome: %s\n", servicos[i].nome);
        printf("Preço: %.2f\n", servicos[i].preco);
        printf("ID: %d\n", servicos[i].idservico);
        printf("Matrícula: %s\n", servicos[i].matricula);
        printf("\n");
    }
}

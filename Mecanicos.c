// ___________________________________________________________________________Mecanicos.h____________________________________________________
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
void AdicionarMecanicos(gestao **inicio, int *nummecanicos) // Função que adiciona os mecânicos
{

    ClearTerminal();
    gestao *novo = (gestao *)malloc(sizeof(gestao));

    printf("\033[1;36m");
    printf("|______________________-Adicionar Mecânicos______________________|\n");
    printf("\033[0m");
    printf("\tNome do Mecânico: ");
    scanf("%s", novo->nome);
    printf("\tNIF: ");
    scanf("%ld", &novo->NIF);
    printf("\tNúmero de Telefone: ");
    scanf("%d", &novo->Telefone);
    printf("\tMorada: ");
    scanf("%s", novo->Morada);
    printf("\tData de Nascimento (dd/mm/aaaa): ");
    scanf("%s", novo->datanasc);
    printf("\tID do Mecânico: ");
    scanf("%d", &novo->idmecanico);

    novo->next = NULL;

    if (*inicio == NULL)
    {
        *inicio = novo;
    }
    else
    {
        gestao *atual = *inicio;
        while (atual->next != NULL)
        {
            atual = atual->next;
        }
        atual->next = novo;
    }

    (*nummecanicos)++;
    printf("\nMecânico adicionado com sucesso!\n");
}

void EditarMecanicos(gestao **inicio, int nummecanicos) // Função que edita os mecânicos
{

    ClearTerminal();
    int id;

    printf("\033[1;36m");
    printf("|______________________Editar Mecânicos______________________|\n");
    printf("\033[0m");
    printf("Insira o ID do Mecânico que deseja editar: ");
    scanf("%d", &id);

    gestao *atual = *inicio;
    gestao *anterior = NULL;
    while (atual != NULL)
    {
        if (atual->idmecanico == id)
        {
            printf("\033[1;36m");
            printf("\n\tNome do Mecânico: ");
            scanf("%s", atual->nome);
            printf("\tNIF: ");
            scanf("%ld", &atual->NIF);
            printf("\tNúmero de Telefone: ");
            scanf("%d", &atual->Telefone);
            printf("\tMorada: ");
            scanf("%s", atual->Morada);
            printf("\tData de Nascimento (dd/mm/aaaa): ");
            scanf("%s", atual->datanasc);
            printf("\033[0m");
            printf("\nMecânico editado com sucesso!\n");
            return;
        }
        atual = atual->next;
    }

    printf("Mecânico com o ID %d não encontrado.\n", id);
}

void OrdenarMecanicosPorIdade(gestao *inicio)
{
    if (inicio == NULL || inicio->next == NULL)
    {
        return; // Não há nada para ordenar
    }

    gestao *atual;
    gestao *menor;

    for (atual = inicio; atual->next != NULL; atual = atual->next)
    {
        menor = atual;

        gestao *proximo;
        for (proximo = atual->next; proximo != NULL; proximo = proximo->next)
        {
            // Comparar as idades dos mecânicos
            if (strcmp(proximo->datanasc, menor->datanasc) < 0)
            {
                menor = proximo;
            }
        }

        // Trocar o mecânico atual com o mecânico de menor idade
        // TrocarMecanicos(atual, menor);
    }
}

void ListarMecanicos(gestao *inicio) // Função que Lista os mecânicos
{
    ClearTerminal();

    int opcao;
    printf("\033[1;36m");
    printf("|______________________Listar Mecânicos______________________|\n");
    printf("\033[0m");
    gestao *atual = inicio;
    while (atual != NULL)
    {
        printf("\n\tNome do Mecânico: %s\n", atual->nome);
        printf("\tNIF: %ld\n", atual->NIF);
        printf("\tNúmero de Telefone: %d\n", atual->Telefone);
        printf("\tMorada: %s\n", atual->Morada);
        printf("\tData de Nascimento: %s\n", atual->datanasc);
        printf("\tId do Mecânico: %d\n", atual->idmecanico);
        atual = atual->next;
    }

    printf("\nOpções:\n");
    printf("\033[1;36m");
    printf("1 - Colocar em ordem de idade ascendente\n");
    printf("2 - Não fazer nenhuma ordenação\n");
    printf("\033[0m");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
    {
        OrdenarMecanicosPorIdade(&inicio);
        ListarMecanicos(&inicio);
        break;
    }
    case 2:
    {
        printf("\033[1;36m");
        printf("Saindo...\n");
        printf("\033[0m");
        break;
    }
    default:
    {
        printf("\033[1;36m");
        printf("Opção inválida! Insira uma opção válida.\n");
        printf("\033[0m");
        break;
    }
    }
}

void Mecanicodisponibilidade(gestao *mecanico) // Função que Verifia a disponibilidade dos mecânicos
{
    ClearTerminal();

    char disponivel;
    printf("\033[1;36m");
    printf("---------------Menu disponibilidade------------------\n\n");
    printf("\033[0m");

    printf("Digite o id do Mecânico:\n");
    scanf("%d", &mecanico->idmecanico);

    printf("O mecânico %s está disponível? (S/N)\n", mecanico->nome);
    scanf(" %c", &disponivel);
    disponivel = toupper(disponivel);

    while (disponivel != 'S' && disponivel != 'N')
    {
        printf("\033[1;36m");
        printf("----Menu disponibilidade----\n\n");
        printf("\033[0m");

        printf("Opção inválida! Insira S ou N.\n");
        printf("O mecânico %s está disponível? (S/N)\n", mecanico->nome);
        scanf(" %c", &disponivel);
        disponivel = toupper(disponivel);
    }

    if (disponivel == 'S')
    {
        mecanico->disponibilidade = true;
        printf("\033[1;36m");
        printf("------------------Menu disponibilidade------------------\n\n");
        printf("O mecânico %s está disponível.\n", mecanico->nome);
        printf("\033[0m");
    }
    else
    {
        mecanico->disponibilidade = false;
        printf("\033[1;36m");
        printf("------------------Menu disponibilidade------------------\n\n");
        printf("O mecânico %s não está disponível.\n", mecanico->nome);
        printf("\033[0m");
    }
}

void RemoverMecanicos(gestao **inicio, int *nummecanicos) // Função que remove os mecânicos
{
    ClearTerminal();
    int id;

    printf("\033[1;36m");
    printf("|______________________Remover Mecânicos______________________|\n");
    printf("\033[0m");
    printf("Insira o ID do Mecânico que deseja remover: ");
    scanf("%d", &id);

    gestao *atual = *inicio;
    gestao *anterior = NULL;
    while (atual != NULL)
    {
        if (atual->idmecanico == id)
        {
            if (anterior == NULL)
            {
                *inicio = atual->next;
            }
            else
            {
                anterior->next = atual->next;
            }
            free(atual);
            (*nummecanicos)--;
            printf("\nMecânico removido com sucesso!\n");
            return;
        }
        anterior = atual;
        atual = atual->next;
    }

    printf("Mecânico com o ID %d não encontrado.\n", id);
}

void gravarMecanicosArquivo(gestao *inicio, const char *nomeArquivo)
{
    ClearTerminal();
    printf("A gerar Relatório...\n");

    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    gestao *atual = inicio;
    while (atual != NULL)
    {
        fprintf(arquivo, "ID do Mecânico: %d\n", atual->idmecanico);
        fprintf(arquivo, "Nome do Mecânico: %s\n", atual->nome);
        fprintf(arquivo, "NIF: %ld\n", atual->NIF);
        fprintf(arquivo, "Número de Telefone: %d\n", atual->Telefone);
        fprintf(arquivo, "Morada: %s\n", atual->Morada);
        fprintf(arquivo, "Data de Nascimento: %s\n\n", atual->datanasc);
        atual = atual->next;
    }

    fclose(arquivo);
    printf("Dados dos mecânicos gravados no ficheiro com sucesso.\n");
}

void PrintGestaoData(gestao *inicio)
{

    ClearTerminal();
    printf("|________Gestão Data________|\n\n");
    gestao *current = inicio; // array
    while (current != NULL)
    {
        printf("Número: %d\n", current->numero);
        printf("ID Mecânico: %d\n", current->idmecanico);
        printf("Nome: %s\n", current->nome);
        printf("NIF: %ld\n", current->NIF);
        printf("Morada: %s\n", current->Morada);
        printf("Telefone: %d\n", current->Telefone);
        printf("Data de Nascimento: %s\n", current->datanasc);
        printf("Disponibilidade: %s\n", current->disponibilidade ? "Disponível" : "Indisponível");
        printf("\n");

        current = current->next;
    }
}

/*void OrdenarMecanicosPorIdade(gestao *inicio)
{
    ClearTerminal();
    printf("|________Ordenar Mecânicos por Idade________|\n\n");
    if (inicio == NULL || inicio->next == NULL)
    {
        return; // Não há nada para ordenar
    }

    bool trocou;
    gestao *atual;
    gestao *anterior = NULL;
    gestao *proximo;

    do
    {
        trocou = false;
        atual = inicio;

        while (atual->next != NULL)
        {
            proximo = atual->next;

            // Comparar as idades dos mecânicos
            if (strcmp(atual->datanasc, proximo->datanasc) > 0)
            {
                if (anterior != NULL)
                {
                    anterior->next = proximo;
                }
                else
                {
                    inicio = proximo;
                }

                atual->next = proximo->next;
                proximo->next = atual;
                trocou = true;
            }
            else
            {
                anterior = atual;
                atual = atual->next;
            }
        }

    } while (trocou);
}
*/

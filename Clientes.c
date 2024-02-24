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
Cliente totalClientes[100];
int numClientes = 0;
void adicionarCliente()
{

    if (numClientes >= 100)
    {
        printf("Limite máximo de clientes atingido.\n");
        return;
    }

    Cliente novoCliente[100];
    printf("Nome do cliente: ");
    scanf("%s", novoCliente[numClientes].nome);
    printf("NIF do cliente: ");
    scanf("%d", &novoCliente[numClientes].nif);
    printf("Contacto do cliente: ");
    scanf("%d", &novoCliente[numClientes].contato);
    printf("Matrícula do veículo: ");
    scanf("%s", novoCliente[numClientes].matricula);
}

void listarClientesPorNome()
{
    if (numClientes == 0)
    {
        printf("Não há clientes cadastrados.\n");
        return;
    }

    // Listar os clientes por ordem alfabética usando selection sort
    int i, j, minIndex;
    for (i = 0; i < numClientes - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < numClientes; j++)
        {
            if (strcmp(totalClientes[j].nome, totalClientes[minIndex].nome) < 0)
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            Cliente temp = totalClientes[i];
            totalClientes[i] = totalClientes[minIndex];
            totalClientes[minIndex] = temp;
        }
    }

    printf("Clientes por ordem alfabética de nome:\n");
    for (i = 0; i < numClientes; i++)
    {
        printf("Nome: %s\n", totalClientes[i].nome);
        printf("NIF: %d\n", totalClientes[i].nif);
        printf("Contacto: %d\n", totalClientes[i].contato);
        printf("Matrícula: %s\n", totalClientes[i].matricula);
        printf("---------------------------------\n");
    }
}

void exibirClientePorNIF()
{
    if (numClientes == 0)
    {
        printf("Não há clientes cadastrados.\n");
        return;
    }

    int nif;
    printf("NIF do cliente: ");
    scanf("%d", &nif);

    for (int i = 0; i < numClientes; i++)
    {
        if (totalClientes[i].nif == nif)
        {
            printf("Nome: %s\n", totalClientes[i].nome);
            printf("NIF: %d\n", totalClientes[i].nif);
            printf("Contacto: %d\n", totalClientes[i].contato);
            printf("Matrícula: %s\n", totalClientes[i].matricula);
            return;
        }
    }
    printf("Cliente com NIF %d não encontrado.\n", nif);
}

void removerCliente()
{

    if (numClientes == 0)
    {
        printf("Não há clientes cadastrados.\n");
        return;
    }

    int nif;
    printf("NIF do cliente: ");
    scanf("%d", &nif);

    for (int i = 0; i < numClientes; i++)
    {
        if (totalClientes[i].nif == nif)
        {
            for (int j = i; j < numClientes - 1; j++)
            {
                totalClientes[j] = totalClientes[j + 1];
            }
            numClientes--;
            printf("Cliente removido com sucesso.\n");
            return;
        }
    }
    printf("Cliente com NIF %d não encontrado.\n", nif);
}
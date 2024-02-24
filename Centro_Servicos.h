#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funcoes.h"
#include "structs.h"

void menuOpcoesServico()
{
    servico servicos[15];
    int numservicos = 0;
    int resposta;

    do
    {
        printf("\033[1;36m");
        printf("\n\t╔════════════════════════════════════════════════════╗");
        printf("\n\t║                                                    ║");
        printf("\n\t║            1-Quer remover o Serviço?               ║");
        printf("\n\t║                                                    ║");
        printf("\n\t╚════════════════════════════════════════════════════╝");
        printf("\n\t╔════════════════════════════════════════════════════╗");
        printf("\n\t║                                                    ║");
        printf("\n\t║            2-Quer alterar o Serviço?               ║");
        printf("\n\t║                                                    ║");
        printf("\n\t╚════════════════════════════════════════════════════╝");
        printf("\n\t╔════════════════════════════════════════════════════╗");
        printf("\n\t║                                                    ║");
        printf("\n\t║            3-Quer listar o Serviço?                ║");
        printf("\n\t║                                                    ║");
        printf("\n\t╚════════════════════════════════════════════════════╝");
        printf("\n\t╔════════════════════════════════════════════════════╗");
        printf("\n\t║                                                    ║");
        printf("\n\t║            4-Quer voltar para o MenuInicial?       ║");
        printf("\n\t║                                                    ║");
        printf("\n\t╚════════════════════════════════════════════════════╝");
        printf("\033[0m");

        fflush(stdin);
        printf("\n\tOpção: ");
        scanf("%d", &resposta);

        switch (resposta)
        {
        case 1:
        {
            RemoverServicos(servicos, &numservicos);
            printf("Serviço removido com sucesso!\n");
            break;
        }
        case 2:
        {
            EditarServicos(servicos, &numservicos);
            printf("Serviço alterado com sucesso!\n");
            break;
        }
        case 3:
        {
            ListarServicos(servicos, &numservicos);
            printf("Serviço listado com sucesso!\n");
            break;
        }
        case 4:
        {
            printf("Voltando para o Menu Inicial\n");
            // MenuInicial();
            break;
        }
        default:
            printf("Opção inválida!\n");
            return;
        }
    } while (resposta <= 4);
}

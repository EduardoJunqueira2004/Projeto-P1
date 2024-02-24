//___________________________________________________________________________Centro_Mecanicos.h____________________________________________________
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funcoes.h"

void menuOpcoesMecanico()
{
    fflush(stdin); // limpa o lixo do Buffer

    gestao mecanica[15]; // array de 15 mecÂnicos
    int numservicos = 0; // numero de serviços
    int idmecanico;      // idmecanico
    int idservico;       // idservico
    int inicio = 0;
    int nummecanicos = 0;    // numero de mecánicos
    int op;                  // opção
    int tamanho = 0;         // tamanho do array
    int ops;                 // opção
    int numindisponivel = 0; // mecanicos indisponiveis
    char s;                  // sim
    char n;                  // não    char n; não
    int j;
    int i;
    int resposta;
    do
    {
        printf("\033[1;36m"); // cor ciano brilhante para o cabeçalho
        printf("\n\t╔════════════════════════════════════════════════════╗");
        printf("\n\t║                                                    ║");
        printf("\n\t║            1-Quer remover o Mecânico?              ║");
        printf("\n\t║                                                    ║");
        printf("\n\t╚════════════════════════════════════════════════════╝");
        printf("\n\t╔════════════════════════════════════════════════════╗");
        printf("\n\t║                                                    ║");
        printf("\n\t║            2-Quer aterar o Mecânico?               ║");
        printf("\n\t║                                                    ║");
        printf("\n\t╚════════════════════════════════════════════════════╝");
        printf("\n\t╔════════════════════════════════════════════════════╗");
        printf("\n\t║                                                    ║");
        printf("\n\t║            3-Quer listar o Mecânico?               ║");
        printf("\n\t║                                                    ║");
        printf("\n\t╚════════════════════════════════════════════════════╝");
        printf("\n\t╔════════════════════════════════════════════════════╗");
        printf("\n\t║                                                    ║");
        printf("\n\t║            4-Quer voltar para o MenuInicial?       ║");
        printf("\n\t║                                                    ║");
        printf("\n\t╚════════════════════════════════════════════════════╝");

        printf("\033[0m"); // volta a cor padrão do terminal
        fflush(stdin);
        printf("\n\tOpção: ");
        scanf("%d", &resposta);

        switch (resposta)
        {
        case 1:
        {
            int idmecanico;
            printf("\n\tDigite o ID do Mecânico: ");
            scanf("%d", &idmecanico);
            RemoverMecanicos(mecanica, &nummecanicos);
            break;
        }
        case 2:
        {
            printf("Insira o id que deseja alterar");
            scanf("%d", &idmecanico);
            EditarMecanicos(mecanica, nummecanicos);
            break;
        }
        case 3:
        {
            // ListarMecanicos(&mecanica, nummecanicos);
            printf("Mecânico listado com sucesso!\n");
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
    } while (resposta != 4);
}

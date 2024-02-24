// ___________________________________________________________________________Projeto 1________________________________________________________________
// Grupo:Andrei Talle Eduardo Junqueira Sergio Gonçalves;
// Projeto.c --> Código principal que executa todos os outros secundários do tipo .h

// Bibliotecas de Sistema
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include <locale.h>
#include <unistd.h>
#include <sys/types.h>

// Bibliotecas adicionais para o código
#include "structs.h"
#include "Clear.h"
#include "Clientes.c"
#include "Servicos.c"
#include "Mecanicos.c"
#include "CentroMec.c"
#include "Centro_Mecanicos.h"
#include "Centro_Servicos.h"
#include "funcoes.h"

void MenuInicial()
{

    fflush(stdin);        // limpa o lixo do Buffer
    gestao mecanica[15];  // array de 15 mecânicos
    servico servicos[80]; // array de 80 serviços
    int numservicos = 0;  // numero de serviços
    int idmecanico;       // idmecanico
    int idservico;        // idservico
    int inicio = 0;
    int nummecanicos = 0;    // numero de mecánicos
    int op;                  // opção
    int tamanho = 0;         // tamanho do array
    int numindisponivel = 0; // mecanicos indisponiveis
    char s;                  // sim
    char n;                  // não    char n; não
    int j;
    int i;

    do
    {
        printf("\033[1;36m"); // cor ciano brilhante para o cabeçalho
        // MenuInicial Centro de Mecânica Rápida
        printf("\n\t╔══════════════════════════════════════════════════════════════════════════════════════════════════╗");
        printf("\n\t║                           Gestão de um centro de mecânica rápida                                 ║");
        printf("\n\t║══════════════════════════════════════════════════════════════════════════════════════════════════╢");
        printf("\n\t║                                                                                                  ║");
        printf("\n\t║                        1. Gerir Serviços.                                                        ║");
        printf("\n\t║                        2. Gerir Mecânicos.                                                       ║");
        printf("\n\t║                        3. Listar mecânicos por ordem alfabética do nome.                         ║"); // Listar mecânicos por ordem alfabética do nome. Listar mecânicos, ordenados por idade ascendente.
        printf("\n\t║                        4. Listar mecânicos, ordenados por idade ascendente.                      ║");
        printf("\n\t║                        5. Disponibilidade Mecânicos.                                             ║");
        printf("\n\t║                        6. Gerar Relatório.                                                       ║");
        printf("\n\t║                        7. O centro de mecânica rápida                                            ║");
        printf("\n\t║                        8. Sair.                                                                  ║");
        printf("\n\t║                                                                                                  ║");
        printf("\n\t╚══════════════════════════════════════════════════════════════════════════════════════════════════╝");
        printf("\033[0m"); // volta a cor padrão do terminal

        // escolha da opção
        fflush(stdin);
        printf("\n\tOpção: ");
        scanf("%[^\n]d", &op);

    } while (!(op >= '1' && op <= '8')); // 1 <= op <= 8
    // opção escolhida
    switch (op)
    {

    case '1':          // Gerir Serviços
        clearBuffer(); // Limpa o lixo desnecessário do buffer -->utilizado pela função void clearBuffer()
                       // chamar a função Servicos
        AdicionarServicos(servicos, &numservicos, &idservico);
        break;

    case '2': // Gerir Mecânicos
        clearBuffer();
        AdicionarMecanicos(mecanica, &nummecanicos);
        break;

    case '3': // Listar mecânicos por ordem alfabética do nome.
        printf("-------------------Listagem dos Mecânicos por oderm alfabética-------------------\n");
        // ListarMecanicos(&mecanica, nummecanicos);
        clearBuffer();
        break;

    case '4': // Listar mecânicos, ordenados por idade ascendente
        printf("-------------------Listagem dos Mecânicos por idade ascendente-------------------\n");
        OrdenarMecanicosPorIdade(inicio);
        clearBuffer();
        break;

    case '5': // Disponibilidade Mecânicos.
        printf("-------------------Disponibilidade dos Mecânicos-------------------\n");
        Mecanicodisponibilidade(mecanica);
        clearBuffer();
        break;

    case '6': // Gerar Relatório.
        printf("-------------------Gerar Relatório-------------------\n");
        gravarMecanicosArquivo(inicio, "mecanicos.txt");
        clearBuffer();
        break;

    case '7':                // Aplicação de Gestão de Mecânica
        menuOpcoesRapidas(); // CentroMec
        clearBuffer();
        break;

    case '8': // Sair
        printf("\n\tSaindo...");
        clearBuffer();
        break;

    default:
        printf("\n\tOpção inválida! Insira uma opção válida.\n");
        clearBuffer();
        break;
    }
}
int main()
{
    MenuInicial(); // implementação da função MenuInicial no int main;
    return 0;
}

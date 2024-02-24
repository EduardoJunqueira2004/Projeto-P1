//___________________________________________________________________________CentroMec.h____________________________________________________
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

void agendarServico() // case 4
{
    printf("\t\t|________________Agendar Serviço________________|\n\n");
    struct aplicacoes novoServico; // Criar uma nova instancia da estrutura "aplicacoes"

    printf("Digite o ID do cliente: ");
    scanf("%d", &novoServico.idCliente);
    printf("Digite o ID do mecânico: ");
    scanf("%d", &novoServico.idMecanico);
    printf("Digite a data e hora do serviço (formato: dd/mm/yyyy hh:mm): ");
    scanf("%s", novoServico.dataHora);
    printf("Digite o estado do serviço (1-Marcado, 2-Realizado, 3-Não compareceu): ");
    scanf("%d", &novoServico.estado);
    printf("Digite o relatório de intervenção: ");
    scanf("%s", novoServico.relatorio);
    printf("Digite o preço a pagar: ");
    scanf("%f", &novoServico.preco);
    // Salvar o serviço em algum lugar (por exemplo, em um array ou em um arquivo)
    printf("Serviço agendado com sucesso!\n");

    // Display the values of novoServico
    printf("\nInformações do novo serviço:\n");
    printf("ID do cliente: %d\n", novoServico.idCliente);
    printf("ID do mecânico: %d\n", novoServico.idMecanico);
    printf("Data e hora do serviço: %s\n", novoServico.dataHora);
    printf("Estado do serviço: %d\n", novoServico.estado);
    printf("Relatório de intervenção: %s\n", novoServico.relatorio);
    printf("Preço a pagar: %.2f\n", novoServico.preco);
}

void listarServicosHoje(servico *servicos, int numservicos)
{
    // Obter a data atual
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    int diaAtual = local->tm_mday;
    int mesAtual = local->tm_mon + 1;
    int anoAtual = local->tm_year + 1900;

    printf("\t\t|________________Listar Serviços Hoje________________|\n\n");
    printf("Listando os serviços marcados para hoje (%02d/%02d/%d):\n", diaAtual, mesAtual, anoAtual);

    // Percorrer a lista de serviços e verificar se estão marcados para hoje
    for (int i = 0; i < numservicos; i++)
    {
        if (servicos[i].dia == diaAtual && servicos[i].mes == mesAtual && servicos[i].ano == anoAtual)
        {
            printf("ID do Serviço: %d\n", servicos[i].idservico);
            printf("Nome: %s\n", servicos[i].nome);
            printf("Descrição: %s\n", servicos[i].descricao);
            printf("Preço: %.2f\n", servicos[i].preco);
            printf("-----------------\n");
        }
    }
}
void listarServicosDia(servico *servicos)
{
    printf("\t\t|________________Listar Serviços Dia________________|\n\n");
    // Digite a data desejada
    printf("Digite a data desejada (formato: dd/mm/yyyy): ");
    char data[11];
    scanf("%s", data);

    // Extrair dia, mês e ano da data digitada
    int dia, mes, ano;
    sscanf(data, "%d/%d/%d", &dia, &mes, &ano);

    // Obter a data atual
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    int diaAtual = local->tm_mday;
    int mesAtual = local->tm_mon + 1;
    int anoAtual = local->tm_year + 1900;

    // Verificar se a data digitada é válida
    if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 1900 || ano > 2100)
    {
        printf("Data inválida.\n");
        return;
    }

    // Verificar se a data é no futuro
    if (ano > anoAtual || (ano == anoAtual && mes > mesAtual) || (ano == anoAtual && mes == mesAtual && dia > diaAtual))
    {
        printf("Data no futuro.\n");
        return;
    }

    printf("Listando os serviços marcados para o dia %s:\n", data);

    // Percorrer a lista de serviços
    servico *atual = servicos;
    while (atual != NULL)
    {
        if (atual->dia == dia && atual->mes == mes && atual->ano == ano)
        {
            // Exibir o serviço
            printf("ID: %d\n", atual->idservico);
            printf("Nome: %s\n", atual->nome);
            printf("Descrição: %s\n", atual->descricao);
            printf("Preço: %.2f\n", atual->preco);
            printf("-----------------\n");
        }

        atual = atual->next;
    }
}

/*void listarServicosMecanicoDia(struct servico *inicio)
{
    ClearTerminal();
    Printf("\t\t|________________Listar Serviços Mecânico Dia________________|\n\n");
    // Digite a data desejada
    printf("Digite a data desejada (formato: dd/mm/yyyy): ");
    char data[11];
    scanf("%s", data);

    // Digite o ID do mecânico
    printf("Digite o ID do mecânico: ");
    int idMecanico;
    scanf("%d", &idMecanico);

    printf("Listando os serviços marcados para o dia %s do mecânico %d:\n", data, idMecanico);

    struct servico *atual = inicio;
    bool encontrados = false;

    while (atual != NULL)
    {
        if (strcmp(atual->data, data) == 0 && atual->idMecanico == idMecanico)
        {
            // Exibir o serviço encontrado
            printf("ID do serviço: %d\n", atual->idservico);
            printf("Nome: %s\n", atual->nome);
            printf("Descrição: %s\n", atual->descricao);
            printf("Preço: %.2f\n", atual->preco);
            printf("-----------------\n");
            encontrados = true;
        }

        atual = atual->next;
    }

    if (!encontrados)
    {
        printf("Nenhum serviço encontrado para a data e mecânico especificados.\n");
    }
}

void listarServicosPorTipoDia(struct servico *inicio)
{

    printf("\t\t|________________Listar Serviços Por Tipo Dia________________|\n\n");
    // Digite a data desejada
    printf("Digite a data desejada (formato: dd/mm/yyyy): ");
    char data[11];
    scanf("%s", data);

    printf("Listando os serviços marcados para o dia %s, por tipo de serviço:\n", data);

    struct servico *atual = inicio;
    bool encontrados = false;

    while (atual != NULL)
    {
        if (strcmp(atual->data, data) == 0)
        {
            // Exibir o serviço encontrado
            printf("Tipo de serviço: %s\n", atual->tipo);
            printf("ID do serviço: %d\n", atual->idservico);
            printf("Nome: %s\n", atual->nome);
            printf("Descrição: %s\n", atual->descricao);
            printf("Preço: %.2f\n", atual->preco);
            printf("-----------------\n");
            encontrados = true;
        }

        atual = atual->next;
    }

    if (!encontrados)
    {
        printf("Nenhum serviço encontrado para a data especificada.\n");
    }
}

void listarServicosPorMatricula(struct servico *inicio, const char *matriculaVeiculo)
{

    printf("\t\t|________________Listar Serviços Por Matricula________________|\n\n");

    Printf("Digite a matrícula do veículo: \n");
    scanf("%s", servico.matricula);

    printf("Listando os serviços associados à matrícula do veículo %s:\n", matriculaVeiculo);

    struct servico *atual = inicio;
    bool encontrados = false;

    while (atual != NULL)
    {
        if (strcmp(atual->matricula, matriculaVeiculo) == 0)
        {
            // Exibir o serviço encontrado
            printf("ID do serviço: %d\n", atual->idservico);
            printf("Nome: %s\n", atual->nome);
            printf("Descrição: %s\n", atual->descricao);
            printf("Preço: %.2f\n", atual->preco);
            printf("Matricula %S\n" atual->matricula);
            printf("-----------------\n");
            encontrados = true;
        }

        atual = atual->next;
    }

    if (!encontrados)
    {
        printf("Nenhum serviço encontrado para a matrícula do veículo especificada.\n");
    }
}
*/
void realizarServicoPorMecanicoData(servico *servicos, int idMecanico, char data[])
{

    ClearTerminal();
    printf("\t\t|________________Realizar Serviço Por Mecânico Data________________|\n\n");

    printf("Realizando serviços para o mecânico de ID %d na data %s:\n", idMecanico, data);

    servico *atual = servicos;
    bool encontrouServico = false;

    while (atual != NULL)
    {
        if (strcmp(atual->matricula, data) == 0 && atual->idservico == idMecanico)
        {
            printf("ID do Serviço: %d\n", atual->idservico);
            printf("Nome: %s\n", atual->nome);
            printf("Descrição: %s\n", atual->descricao);
            printf("Preço: %.2f\n", atual->preco);
            printf("Matricula: %s\n", atual->matricula);
            printf("----------------------\n");
            encontrouServico = true;
        }
        atual = atual->next;
    }

    if (!encontrouServico)
    {
        printf("Nenhum serviço encontrado para o mecânico de ID %d na data %s.\n", idMecanico, data);
    }
}

/*void listarServicosNaoComparecidos(servico *servicos, char data[])
{

    ClearTerminal();
    Printf("\t\t|________________Listar Serviços Não Comparecidos________________|\n\n");

    printf("Listando os serviços em que o cliente não compareceu no dia %s:\n", data);

    servico *atual = servicos;
    bool encontrouServico = false;

    while (atual != NULL)
    {
        if (strcmp(atual->data, data) == 0 && !atual->compareceu)
        {
            printf("ID do Serviço: %d\n", atual->idservico);
            printf("Nome: %s\n", atual->nome);
            printf("Descrição: %s\n", atual->descricao);
            printf("Preço: %.2f\n", atual->preco);
            printf("----------------------\n");
            encontrouServico = true;
        }
        atual = atual->next;
    }

    if (!encontrouServico)
    {
        printf("Nenhum serviço encontrado em que o cliente não compareceu no dia %s.\n", data);
    }
}

void faturamentoTipoServicoHojeMes() // case 12
{
    ClearTerminal();
    printf("\t\t|________________Faturamento Tipo Serviço Hoje Mês________________|\n\n");

    // Saber por cada tipo de serviço, quando foi faturado hoje e este mês
    printf("Saber por cada tipo de serviço, quando foi faturado hoje e este mês:\n");
    // Implementação

    // Obter a data atual
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    int diaAtual = local->tm_mday;
    int mesAtual = local->tm_mon + 1;
    int anoAtual = local->tm_year + 1900;
}


void quantidadeServicosMecanicoMes() // case 13
{
    ClearTerminal();
    Printf("\t\t|________________Quantidade Serviços Mecânico Mês________________|\n\n")

        // Saber quantos serviços realizou cada mecânico este mês
        printf("Saber quantos serviços realizou cada mecânico este mês:\n");
    // Implementação
}



void gerarRelatorioContasDiaMes() // case 14
{
    ClearTerminal();
    Printf("\t\t|________________Gerar Relatório Contas Dia Mês________________|\n\n")

        // Gerar um relatório por dia e por mês de contas. O relatório deverá organizar a informação por tipo de serviço
        printf("Gerando relatório por dia e por mês de contas:\n");
    // Implementação
}
*/

void menuOpcoesRapidas()
{
    char opcao[3];
    int numservicos = 0; // numero de serviços
    int idmecanico;      // idmecanico
    int idservico;       // idservico
    int inicio = 0;
    int op;                  // opção
    int tamanho = 0;         // tamanho do array
    int ops;                 // opção
    int numindisponivel = 0; // mecanicos indisponiveis
    char s;                  // sim
    char n;                  // não    char n; não
    int j;
    int i;
    int casos = 15;

    for (i = 0; i < casos; i++)
    {
        int valor;
        scanf("%d", &valor);

        if (valor <= 10)
        {
            printf("Valor lido: %d\n", valor);
        }
        else
        {
            printf("Valor ignorado: %d\n", valor);
        }
    }

    printf("\033[1;36m"); // cor ciano brilhante para o cabeçalho
                          // Aplicação Principal Do Centro de Mecânica/Aplicação
    do
    {
        printf("\n\t╔═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗");
        printf("\n\t║                                        Centro de Mecânica/Aplicação                                                                               ║");
        printf("\n\t╟═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╢");
        printf("\n\t║                                                                                                                                                   ║");
        printf("\n\t║                                  1. Adicionar cliente.                                                                                            ║");
        printf("\n\t║                                  2. Exibir informações de cliente por NIF.                                                                        ║");
        printf("\n\t║                                  3. Agendar um serviço.                                                                                           ║");
        printf("\n\t║                                  4. Listar todos os serviços de hoje e de um determinado dia ordenados por hora ascendente.                       ║");
        printf("\n\t║                                  5. Listar todos os serviços de hoje e de um determinado dia para um determinado mecânico.                        ║");
        printf("\n\t║                                  6. Listar todos os serviços de hoje e de um determinado dia por tipo de serviço.                                 ║");
        printf("\n\t║                                  7. Saber o histórico de serviços de um determinado veículo pela matrícula.                                       ║");
        printf("\n\t║                                  8. Simular a realização de um serviço: informar qual o mecânico e a data e hora do serviço.                      ║");
        printf("\n\t║                                  9.Listar os serviços em que o cliente não compareceu para um determinado dia.                                   ║");
        printf("\n\t║                                  10.Saber por cada tipo de serviço, quando foi faturado hoje e este mês.                                          ║");
        printf("\n\t║                                  11.Saber quantos serviços realizou cada mecânico este mês.                                                       ║");
        printf("\n\t║                                  12.Gerar um relatório por dia e por mês de contas. O relatório deverá organizar a informação por tipo de serviço.║");
        printf("\n\t║                                  13.Sair.                                                                                                         ║");
        printf("\n\t║                                                                                                                                                   ║");
        printf("\n\t╚═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝");

        printf("\033[0m"); // volta a cor padrão do terminal

        fflush(stdin);
        printf("\n\tOpção: ");
        scanf("%[^\n]s", opcao);

        switch (opcao[0])
        {
        case '1':
            printf("Opção 1 selecionada: Adicionar cliente\n");
            adicionarCliente();
            // MenuInicial();

        case '2':
            printf("Opção 2 selecionada: Exibir informações de cliente por NIF\n");

            int nif;
            printf("Insira o NIF do cliente: ");
            scanf("%d", &nif);
            // exibirInformacoesClienteNIF(nif);
            //  MenuInicial();

        case '3':
            printf("Opção 3 selecionada: Agendar um serviço\n");
            agendarServico();
            MenuInicial();

        case '4':
            printf("Opção 4 selecionada: Listar todos os serviços de hoje e de um determinado dia ordenados por hora ascendente\n");
            // listarServicosHoje(servicos, &numservicos);
            // MenuInicial();

        case '5':
            printf("Opção 5 selecionada: Listar todos os serviços de hoje e de um determinado dia ordenados por hora ascendente\n");
            // listarServicosDia(servicos);
            // MenuInicial();

        case '6':
            printf("Opção 6 selecionada: Listar todos os serviços de hoje e de um determinado dia para um determinado mecânico\n");
            // listarServicosMecanicoDia();
            MenuInicial();

        case '7':
            printf("Opção 7 selecionada: Listar todos os serviços de hoje e de um determinado dia por tipo de serviço\n");
            // listarServicosPorTipoDia();
            MenuInicial();

        case '8':
            printf("Opção 8 selecionada: Saber o histórico de serviços de um determinado veículo pela matrícula\n");
            // listarServicosPorMatricula();
            // MenuInicial();

        case '9':
            printf("Opção 9 selecionada: Simular a realização de um serviço: informar qual o mecânico e a data e hora do serviço\n");
            // realizarServicoPorMecanicoData();
            MenuInicial();

        case '10':
            printf("Opção 10 selecionada: Listar os serviços em que o cliente não compareceu para um determinado dia\n");
            // listarServicosNaoComparecidos();
            MenuInicial();

        case '11':
            printf("Opção 11 selecionada: Saber por cada tipo de serviço, quando foi faturado hoje e este mês\n");
            // faturamentoTipoServicoHojeMes();
            MenuInicial();
        case '12':
            printf("Opção 12 selecionada: Saber quantos serviços realizou cada mecânico este mês\n");
            // quantidadeServicosMecanicoMes();
            MenuInicial();
        case '13':
            printf("Opção 13 selecionada: Gerar um relatório por dia e por mês de contas. O relatório deverá organizar a informação por tipo de serviço\n");
            // gerarRelatorioContasDiaMes();
            MenuInicial();
        case '14':
            printf("Voltando para o Menu Inicial\n");
            MenuInicial();

        default:
            printf("Opção inválida. Tente novamente.\n");
            MenuInicial();
        }
    } while (opcao >= 1 && opcao < 16);
}

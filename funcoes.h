#ifndef FUNCOES_H
#define FUNCOES_H

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
// MenuInicial
void MenuInicial();

void AdicionarMecanicos(gestao **inicio, int *nummecanicos);
void EditarMecanicos(gestao **inicio, int nummecanicos);
void ListarMecanicos(gestao *inicio);
void Mecanicodisponibilidade(gestao *mecanico);
void RemoverMecanicos(gestao **inicio, int *nummecanicos);
void gravarMecanicosArquivo(gestao *inicio, const char *nomeArquivo);
void PrintGestaoData(gestao *inicio);
void OrdenarMecanicosPorIdade(gestao *inicio);
void ImprimirMecanicos(gestao *inicio);
// Servicos.c
void AdicionarServicos(servico **servicos, int *numservico, int *idservico);
void EditarServicos(servico *servicos, int numservico);
void RemoverServicos(struct servico **servicos, int *numservico);
void ListarServicos(struct servico *servicos, int numServicos);

//  Clientes.c
void AdicionarClientes();
void adicionarCliente(); // para centro de Mecânica/Rápida
void listarClientesPorNome();
void exibirClientePorNIF(); // para centro de Mecânica/Rápida
void removerCliente();

// Centro de Mecânica Rápida
// void agendarServico();
// void listarServicosHoje();
// void listarServicosDia();
// void listarServicosMecanicoDia();
// void listarServicosTipoServico();
// void historicoServicosVeiculo();
void simularRealizacaoServico();
void listarServicosClienteNaoCompareceu();
void faturamentoTipoServicoHojeMes();
void quantidadeServicosMecanicoMes();
void gerarRelatorioContasDiaMes();
void menuOpcoesRapidas();

#endif

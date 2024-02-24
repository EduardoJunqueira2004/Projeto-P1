#ifndef STRUCTS_H
#define STRUCTS_H

// struct cliente;
typedef struct Cliente
{
    char nome[50];
    int nif;
    int contato;
    char matricula[10];
    int numcliente;
    struct Cliente *next;

} Cliente;

// struct cliente;
typedef struct servico
{
    int idservico;
    char nome[30];
    char descricao[100];
    float preco;
    int numservico;
    bool disponibilidade;
    int dia; // dia do serviço
    int mes; // mês do serviço
    int ano; // ano do serviço
    char matricula[8];
    char data[20];
    bool compareceu;
    struct servico *next;
} servico;

// struct gestao mecânicos:
typedef struct gestao
{
    int numero;
    int idmecanico;
    char nome[30];
    long NIF;
    char Morada[30];
    int Telefone;
    char datanasc[20];
    int nummecanico;
    bool disponibilidade;
    struct gestao *next;
} gestao;

// struct disponivel/indisponível mecânicos
typedef struct
{
    int id;
    bool disponivel;

} disponivel;

// struct alterar dados
typedef struct
{
    char altnome[30];
    char altNIF[10];
    char altMorada[80];
    char altTelefone[10];
    char altdata[30];
    char altdisponibilidade[30];

} alterar;

// struct aplicacoes
typedef struct aplicacoes
{
    int idCliente;
    int idMecanico;
    char dataHora[20];
    int estado;
    char relatorio[100];
    float preco;
    int idServico;
    int idAplicacao;
    struct aplicacoes *next;

} novoServico;

#endif
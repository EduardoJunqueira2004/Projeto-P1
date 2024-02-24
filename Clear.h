// ___________________________________________________________________________Clear.h-->Para limpar o Buuffer e o Terminal____________________________________________________
//- Limpa o Buffer

#ifndef clear_H
#define clear_H
void clearBuffer()
{
    int buffer = 0;

    while (buffer != '\n' && buffer != EOF)
    {
        buffer = getchar();
    }
}

//- Limpa o Terminal
void ClearTerminal()
{
#if defined(_WIN32)
    system("cls");
#else
    system("clear");
#endif
}
#endif

#include <iostream>
#include <string>
#include "Sistema.h"

using namespace std;

int main(void)
{
    Sistema sistema;
    string comando;
    while (cin >> comando)
    {
        if (comando == "FIM")
        {
            break;
        }

        if (comando == "CADASTRAR_ASTRONAUTA")
        {
            string cpf, nome; 
            int idade; 

            cin >> cpf >> idade; 
            getline(cin >> ws, nome);
            
            sistema.cadastrarAstronauta(cpf, idade, nome);
        }

        if (comando == "CADASTRAR_VOO")
        {
            int codigo;

            cin >> codigo;

            sistema.cadastrarVoo(codigo);
        }

        if (comando == "ADICIONAR_ASTRONAUTA")
        {
            string cpf;
            int codigo;

            cin >> cpf >> codigo;

            sistema.adicionarAstronauta(cpf, codigo);
        }

        if (comando == "REMOVER_ASTRONAUTA")
        {
            string cpf;
            int codigo;

            cin >> cpf >> codigo;

            sistema.removerAstronauta(cpf, codigo);
        }

        if (comando == "LANCAR_VOO")
        {
            int codigo;

            cin >> codigo;

            sistema.lancarVoo(codigo);
        }
        
        if (comando == "EXPLODIR_VOO")
        {
            int codigo;

            cin >> codigo;

            sistema.explodirVoo(codigo);
        }

        if (comando == "FINALIZAR_VOO")
        {
            int codigo;

            cin >> codigo;

            sistema.finalizarVoo(codigo);
        }

        if (comando == "LISTAR_VOOS")
        {
            sistema.listarVoos();
        }

        if (comando == "LISTAR_MORTOS")
        {
            sistema.listarMortos();
        }   
    }
    return 0;
}

#include <iostream>
#include "sistema.h"
#include "astronauta.h"
#include "voo.h"

using namespace std;

void Sistema::cadastrarAstronauta(string cpf, int idade, string nome)
{
    // verifica se há outro astronauta com o mesmo CPF
    bool temAstronauta = false;
    for (int i = 0; i < astronautas.size(); i++)
    {
        if (astronautas[i]->getCpf() == cpf)
        {
            cout << "Não foi possível realizar o cadastro, pois já existe um astronauta com CPF " << cpf << endl;
            temAstronauta = true;
            break;
        }
    }
    // se não houver astronautas cadastrados com o CPF inserido
    if (!temAstronauta)
    {
        auto a = make_shared<Astronauta>(cpf, idade, nome);
        astronautas.push_back(a);

        cout << "Astronauta cadastrado com sucesso" << endl; 
    }
}

void Sistema::cadastrarVoo(int codigo)
{
    // verifica se há outro voo com o mesmo código
    int jaExiste = false;
    for (int i = 0; i < voos.size(); i++)
    {
        if (voos[i].getCodigo() == codigo)
        {
            cout << "Não foi possível realizar o cadastro, pois já existe um voo com código " << codigo << endl;
            jaExiste = true;
            break;
        }
    }
    // se não houver outro voo com o mesmo codigo, o voo pode ser cadastrado
    if (!jaExiste)
    {
        Voo v(codigo);
        voos.push_back(v);

        cout << "Voo cadastrado com sucesso" << endl;
    }
}

void Sistema::adicionarAstronauta(string cpf, int codigo)
{
    // cria objetos que serão usados 
    shared_ptr<Astronauta> astronauta = nullptr;
    Voo* voo = nullptr;

    // verifica se o astronauta já existe no vetor de astronautas e adiciona ele ao objeto astronauta
    for (int i = 0; i < astronautas.size(); i++)
    {
        if (astronautas[i]->getCpf() == cpf)
        {
            astronauta = astronautas[i];
            break;
        }
    }
    // se o astronauta não foi cadastrado
    if (astronauta == nullptr)
    {
        cout << "Não é possível adicionar o astronauta de CPF " << cpf << " ao voo, pois ele não está cadastrado no banco de astronautas." << endl;
        return; 
    }
    // verifica se o voo já foi cadastrado 
    for (int i = 0; i < voos.size(); i++)
    {
        if (voos[i].getCodigo() == codigo)
        {
            voo = &voos[i];
            break;
        }
    }
    // se o voo não fo cadastrado 
    if (voo == nullptr)
    {
        cout << "Não é possível adicionar o astronauta ao voo " << codigo << " porque esse código de voo não existe " << endl;
        return; 
    } 

    // depois de validar se o astronauta e o voo existem, podemos chamar o metodo Voo::adicionarAstronauta() para adicionar o objeto ao vector astronautas

    if (voo->adicionarAstronauta(astronauta))
    {
        cout << "Astronauta adicionado ao voo " << codigo << endl;  
    }
    else
    {
        cout << "Não foi possível adicionar o astronauta ao voo " << codigo << endl;     
    }   
}

void Sistema::removerAstronauta(string cpf, int codigo)
{
    Voo* voo = nullptr;

    // procura voo no vetor de voos 
    for (int i = 0; i < voos.size(); i++)
    {
        if (voos[i].getCodigo() == codigo)
        {
            voo = &voos[i];
            break;
        }
    }
    // se o voo inserido não existir 
    if (voo == nullptr)
    {
        cout << "O código " << codigo << " não pertence a nenhum voo cadastrado." << endl;
        return;
    }

    if (voo->removerAstronauta(cpf))
    {
        cout << "Astronauta removido do voo." << endl;
    } 
    else
    {
         cout << "O astronauta não foi removido, porque não fazia parte do voo." << endl;
    }
}

void Sistema::lancarVoo(int codigo)
{
    Voo* voo = nullptr;
    // verifica se o voo existe
    for (int i = 0; i < voos.size(); i++)
    {
        if (voos[i].getCodigo() == codigo)
        {
            voo = &voos[i];
            break;
        }
    }
    // se o voo inserido não foi cadastrado 
    if (voo == nullptr)
    {
        cout << "O voo que você deseja lançar não foi cadastrado." << endl;
        return;
    }

    // chama o método Voo::lancar()
    if (voo->lancar())
    {
        cout << "O voo foi lançado com sucesso." << endl;
    }
    else
    {
        cout << "Não foi possível lançar o voo." << endl;
    }
}

void Sistema::explodirVoo(int codigo)
{
    Voo* voo = nullptr;

    // procura voo
    for (int i = 0; i < voos.size(); i++)
    {
        if (voos[i].getCodigo() == codigo)
        {
            voo = &voos[i];
            break;
        }
    }

    // voo não encontrado
    if (voo == nullptr)
    {
        cout << "O voo que você deseja explodir não foi cadastrado." << endl;
        return;
    }

    // chama função da classe voo
    if (voo->explodir())
    {
        cout << "O voo explodiu." << endl;
    }
    else
    {
        cout << "Não foi possível explodir o voo. :<" << endl;
    }
}

void Sistema::finalizarVoo(int codigo)
{
    Voo* voo = nullptr;

    // procura voo
    for (int i = 0; i < voos.size(); i++)
    {
        if (voos[i].getCodigo() == codigo)
        {
            voo = &voos[i];
            break;
        }
    }

    // voo não encontrado
    if (voo == nullptr)
    {
        cout << "O voo que você deseja finalizar não foi cadastrado." << endl;
        return;
    }

    // chama método da classe voo
    if (voo->finalizar())
        cout << "Voo finalizado com sucesso." << endl;
    else
        cout << "Nao foi possivel finalizar o voo." << endl;
}

void Sistema::listarVoos()
{
    cout << "===== VOOS PLANEJADOS =====" << endl;
    for (int i = 0; i < voos.size(); i++)
    {
        if (voos[i].getEstado() == 0)
            voos[i].exibirDados();
    }

    cout << endl;
    cout << "===== VOOS EM CURSO =====" << endl;
    for (int i = 0; i < voos.size(); i++)
    {
        if (voos[i].getEstado() == 1)
            voos[i].exibirDados();
    }

    cout << endl;
    cout << "===== VOOS FINALIZADOS COM SUCESSO =====" << endl;
    for (int i = 0; i < voos.size(); i++)
    {
        if (voos[i].getEstado() == 2)
            voos[i].exibirDados();
    }

    cout << endl;
    cout << "===== VOOS FINALIZADOS COM EXPLOSAO =====" << endl;
    for (int i = 0; i < voos.size(); i++)
    {
        if (voos[i].getEstado() == 3)
            voos[i].exibirDados();
    }
}

void Sistema::listarMortos()
{
    cout << "===== ASTRONAUTAS MORTOS =====" << endl;

    for (int i = 0; i < astronautas.size(); i++)
    {
        if (!astronautas[i]->estaVivo())
        {
            cout << "CPF: " << astronautas[i]->getCpf() << endl;
            cout << "Nome: " << astronautas[i]->getNome() << endl;

            cout << "Voos participados: ";

            bool encontrou = false;

            for (int j = 0; j < voos.size(); j++)
            {
                int estado = voos[j].getEstado();

                // conta apenas voos lançados
                if (estado == 1 || estado == 2 || estado == 3)
                {
                    if (voos[j].temAstronauta(astronautas[i]->getCpf()))
                    {
                        cout << voos[j].getCodigo() << " ";
                        encontrou = true;
                    }
                }
            }

            if (!encontrou)
                cout << "Nenhum";

            cout << endl << endl;
        }
    }
}

#include <iostream>
#include "voo.h"

using namespace std;

Voo::Voo()
{
    this->codigo = 0; 
    this->estado = 0;
}

Voo::Voo(int codigo)
{
    this->codigo = codigo; 
    this->estado = 0;
}

int Voo::getCodigo()
{
    return codigo;
}

int Voo::getEstado()
{
    return estado;
}

bool Voo::adicionarAstronauta(shared_ptr<Astronauta> a)
{
    // testa se o voo está em estado == planejado
    if (estado != 0)
    {
        cout << "Não é possível adicionar astronautas ao voo, porque ele não está em estado de planejamento." << endl;
        return false;
    }
    // testa se o astronauta está vivo 
    if (!a->estaVivo())
    {
        cout << "Não é possível adicionar um astronauta morto ao voo." << endl;
        return false;
    }
    // testa se o astronauta já foi adicionado ao voo
    for (int i = 0; i < astronautasPassageiros.size(); i++)
    {
        if (astronautasPassageiros[i]->getCpf() == a->getCpf())
        {
            cout << "O astronauta de CPF " << a->getCpf() << " já faz parte do voo." << endl;
            return false;
        }
    }

    // adiciona o astronauta ao voo (finalmente)
    astronautasPassageiros.push_back(a);

    return true;
}

bool Voo::removerAstronauta(string cpf)
{
    if (estado != 0)
    {
        cout << "Não é possível remover astronautas de voos que estejam em estado diferente de planejamento" << endl;
        return false;
    }
    
    for (int i = 0; i < astronautasPassageiros.size(); i++)
    {
        if (astronautasPassageiros[i]->getCpf() == cpf)
        {
            // torna o astronauta disponivel novamente
            astronautasPassageiros[i]->liberar();
            astronautasPassageiros.erase(astronautasPassageiros.begin() + i);
            return true;
        }
    }
    return false;
}

bool Voo::lancar()
{
    // verifica se o voo está com estado == planejado
    if (estado != 0)
    {
        return false;
    }
    // verifica se o voo tem astronautas cadastrados
    if (astronautasPassageiros.size() == 0)
    {
        return false;
    }

    // verifica se os astronautas cadastrados estão vivos e disponíveis
    for (int i = 0; i < astronautasPassageiros.size(); i++)
    {
        if (!astronautasPassageiros[i]->estaVivo() || !astronautasPassageiros[i]->estaDisponivel())
        {
            cout << "Não é possível lançar um voo onde há astronautas mortos ou que não estão disponíveis" << endl;
            return false;
        }
    }

    // mudando o status de estado de todos os astronautas do voo para ocupado
    for (int i = 0; i < astronautasPassageiros.size(); i++)
    {
        astronautasPassageiros[i]->ocupar();
    }

    // mudando o estado do voo para em curso
    estado = 1;
    return true;
}

bool Voo::finalizar()
{
    // verifica se o voo está em curso
    if (estado != 1)
        return false;

    // libera astronautas vivos
    for (int i = 0; i < astronautasPassageiros.size(); i++)
    {
        if (astronautasPassageiros[i]->estaVivo())
        {
            astronautasPassageiros[i]->liberar();
        }
    }

    // muda estado para finalizado com sucesso
    estado = 2;

    return true;
}

bool Voo::explodir()
{
    // verifica se o voo está em curso
    if (estado != 1)
        return false;

    // mata todos astronautas
    for (int i = 0; i < astronautasPassageiros.size(); i++)
    {
        astronautasPassageiros[i]->morrer();
    }

    // finalizado com explosão
    estado = 3;
    return true;
}

bool Voo::temAstronauta(string cpf)
{
    for (int i = 0; i < astronautasPassageiros.size(); i++)
    {
        if (astronautasPassageiros[i]->getCpf() == cpf)
            return true;
    }

    return false;
}

void Voo::exibirDados()
{
    cout << "Codigo do voo: " << codigo << endl;

    cout << "Estado: ";

    if (estado == 0)
    {
        cout << "Planejado";
    }
    else if (estado == 1)
    {
        cout << "Em curso";
    }
    else if (estado == 2)
    {
        cout << "Finalizado com sucesso";
    }
    else if (estado == 3)
    {
        cout << "Finalizado com explosao";
    }

    cout << endl;

    cout << "Astronautas:" << endl;

    for (int i = 0; i < astronautasPassageiros.size(); i++)
    {
        cout << "CPF: " << astronautasPassageiros[i]->getCpf() << endl;
        cout << "Nome: " << astronautasPassageiros[i]->getNome() << endl;
    }
}

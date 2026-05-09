#include "Astronauta.h"

Astronauta::Astronauta()
{    
    this->nome = "";
    this->cpf = "";
    this->idade = 0;
    this->vivo = true;
    this->disponivel = true;
}

Astronauta::Astronauta(string cpf, int idade, string nome)
{
    this->nome = nome;
    this->cpf = cpf;
    this->idade = idade;
    this->vivo = true;
    this->disponivel = true; 
}

string Astronauta::getCpf()
{
    return cpf;
}

string Astronauta::getNome()
{
    return nome;
}

int Astronauta::getIdade()
{
    return idade;
}

bool Astronauta::estaVivo()
{
    return vivo;
}

bool Astronauta::estaDisponivel()
{
    return disponivel;
}

void Astronauta::morrer()
{
    this->vivo = false;
}

void Astronauta::ocupar()
{
    this->disponivel = false;
}

void Astronauta::liberar()
{
    this->disponivel = true;
}

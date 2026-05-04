#ifndef ASTRONAUTA_H
#define ASTRONAUTA_H

#include <string>
using namespace std;

class Astronauta
{
private:
    string nome;
    string cpf;
    int idade;

    bool vivo;
    bool disponivel; 
 
public:
    Astronauta(); // construtor
    Astronauta(string cpf, int idade, string nome);

    string getCpf();
    string getNome();
    int getIdade();

    bool estaVivo();
    bool estaDisponivel();

    void morrer();
    void ocupar();
    void liberar();

    // para teste
    //void mostrarDados();
};

#endif
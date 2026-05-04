#ifndef SISTEMA_H
#define SISTEMA_H
#include <string>
#include <vector>
#include "astronauta.h"
#include "voo.h"

using namespace std;

class Sistema
{
private: 
    vector<shared_ptr<Astronauta>> astronautas;
    vector<Voo> voos;

public:
    void cadastrarAstronauta(string cpf, int idade, string nome);
    void cadastrarVoo(int codigo); 

    void adicionarAstronauta(string cpf, int codigo);
    void removerAstronauta(string cpf, int codigo);
    
    void lancarVoo(int codigo); 
    void explodirVoo(int codigo); 
    void finalizarVoo(int codigo); 

    void listarVoos();
    void listarMortos();
};


#endif
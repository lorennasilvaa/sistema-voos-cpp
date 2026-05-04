#ifndef VOO_H
#define VOO_H

#include <vector>
#include <memory>
#include "astronauta.h"

using namespace std;

class Voo
{
private: 
    int codigo;
    int estado; // 0 = planejado | 1 = em curso | 2 = finalizado com sucesso | 3 = finalizado com explosão

    vector<shared_ptr<Astronauta>> astronautasPassageiros;

public:
    Voo(); 
    Voo(int codigo);

    int getCodigo();
    int getEstado();

    bool adicionarAstronauta(shared_ptr<Astronauta> a);
    bool removerAstronauta(string cpf);

    bool lancar();
    bool finalizar();
    bool explodir();

    bool temAstronauta(string cpf);
    void exibirDados();
};

#endif
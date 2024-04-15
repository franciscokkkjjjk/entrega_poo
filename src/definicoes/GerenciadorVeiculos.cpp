#include <iostream>
#include <list>
#include "../headers/GerenciadorVeiculos.h"
#include "../headers/Veiculo.h"

using namespace std;

GerenciadorVeiculos::GerenciadorVeiculos()
{
    this->veiculosAtivos = new list<Veiculo *>;
};

GerenciadorVeiculos::~GerenciadorVeiculos()
{
    delete this->veiculosAtivos;
};
list<Veiculo *> *GerenciadorVeiculos::getVeiculosAtivos()
{
    return this->veiculosAtivos;
};

int GerenciadorVeiculos::adicionarVeiculo(Veiculo *veiculo)
{
    if (!veiculo->getIsAtivo())
        return 0;
    this->veiculosAtivos->push_back(veiculo);
    return 1;
}

int GerenciadorVeiculos::removerVeiculo(Veiculo *veiculo)
{
    bool veiculoPresente = false;
    for (Veiculo *v : *this->veiculosAtivos)
        if (veiculo->getNumeroChassi() == veiculo->getNumeroChassi())
        {
            veiculoPresente = true;
            break;
        }

    if (veiculoPresente)
    {
        this->veiculosAtivos->remove(veiculo);
        return 1;
    }

    return 0;
}

Veiculo *GerenciadorVeiculos::buscaVeiculo(string numeroChassi)
{
    for (Veiculo *v : *this->veiculosAtivos)
        if (v->getNumeroChassi() == numeroChassi)
            return v;
    return NULL;
}

Veiculo *GerenciadorVeiculos::buscaVeiculoByLocalizacao(string localizacao)
{
    for (Veiculo *v : *this->veiculosAtivos)
        if (v->getLocalizacao() == localizacao)
            return v;
    return NULL;
}

list<Veiculo *> *GerenciadorVeiculos::obterVeiculosAtivos()
{
    return this->veiculosAtivos;
}

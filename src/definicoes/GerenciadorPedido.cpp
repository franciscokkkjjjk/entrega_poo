#include <iostream>
#include <set>
#include "../headers/GerenciadorPedido.h"
#include "../headers/Pedido.h"
#include "../headers/GerenciadorVeiculos.h"

GerenciadorPedido::GerenciadorPedido(GerenciadorVeiculos *veiculos) {
    this->veiculos = veiculos;
    this->pedidos = new list<Pedido*>;
}
GerenciadorPedido::~GerenciadorPedido() {
    delete this->pedidos;
    delete this->veiculos;
}

void GerenciadorPedido::defineVeiculosTransport(list<Pedido*> *listaPedidos) {
    int capacidadeTotalDoVeiculo, contagemAtual; 
    int *indicesAdicionados = new int[listaPedidos->size()]; 
    
    list<Veiculo *> *veiculosAtivos = this->veiculos->getVeiculosAtivos();

    for(Veiculo *veiculo: *veiculosAtivos) {
        capacidadeTotalDoVeiculo = veiculo->getCapacidadeDeCarga();  
        contagemAtual = 0;
        for(Pedido *pedido: *listaPedidos) {
            if(pedido->getPesoDaCarga() > capacidadeTotalDoVeiculo) continue; 

            if(!indicesAdicionados[contagemAtual]) continue;

            pedido->setVeiculoDeTransporte(veiculo);
            
            this->pedidos->push_back(pedido);

            indicesAdicionados[contagemAtual] = contagemAtual;

            capacidadeTotalDoVeiculo = capacidadeTotalDoVeiculo - pedido->getPesoDaCarga();
        }
    }
}

bool GerenciadorPedido::defineVeiculosTransport(Pedido *pedido) {
    list<Veiculo *> *veiculosAtivos = this->veiculos->getVeiculosAtivos();
    for(Veiculo *veiculo: *veiculosAtivos) {  
        if(pedido->getPesoDaCarga() > veiculo->getCapacidadeDeCarga()) continue; 
        pedido->setVeiculoDeTransporte(veiculo);
        this->pedidos->push_back(pedido);
        return true;
    }
    return false;
}
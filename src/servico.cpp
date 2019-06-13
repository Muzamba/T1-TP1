#include "./modulos.h"
// ---------------Apresentação---------------
bool MSA::autenticar(const CPF& cpf, const Senha& senha) {

}

// ---------------Usuario---------------
bool MSU::cadastrar(const Usuario& usuario, const CartaoDeCredito& cartao) {

}

bool MSU::descadastrar(const CPF& cpf) {

};

// ---------------Evento---------------
std::vector<Evento> MSE::buscar(Data inicio, Data fim, Cidade cidade, Estado estado) {

}

bool MSE::criarEvento(const CPF& cpf, const Evento& evento, const std::vector<Apresentacao>& vectorApresenta) {

}

bool MSE::alteraEvento(const Evento& evento)  {

}

bool MSE::descadastrarEvento(const CodigoDeEvento& codigo) {
    
}

// ---------------Vendas---------------
bool MSV::compraIngresso(const CPF& cpf, const CodigoDeApresentacao& codigo, const int) {

}

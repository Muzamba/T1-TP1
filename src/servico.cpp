// Copyright
#include "./modulos.h"
// ---------------Apresentação---------------
bool MSA::autenticar(const CPF& cpf, const Senha& senha) {
    if (cpf.getConteudo() == "05289706151" &&
     senha.getConteudo() == "Aas123") {
         return true;
     } else {
         return false;
     }
}

// ---------------Usuario---------------
bool MSU::cadastrar(const Usuario& usuario, const CartaoDeCredito& cartao) {
    return false;
}

bool MSU::descadastrar(const CPF& cpf) {
    return false;
};

// ---------------Evento---------------
std::vector<Evento> MSE::buscar(Data inicio, Data fim, Cidade cidade, Estado estado) {
    return std::vector<Evento>();
}

bool MSE::criarEvento(const CPF& cpf, const Evento& evento, const std::vector<Apresentacao>& vectorApresenta) {
    return false;
}

bool MSE::alteraEvento(const Evento& evento)  {
    return false;
}

bool MSE::descadastrarEvento(const CodigoDeEvento& codigo) {
    return false;
}

// ---------------Vendas---------------
bool MSV::compraIngresso(const CPF& cpf, const CodigoDeApresentacao& codigo, const int) {
    return false;
}

// Copyright
#include "./modulos.h"
#include <vector>
#include <unordered_map>

std::unordered_map<std::string, Usuario> userTable;
std::unordered_map<std::string, Evento> eventTable;
std::unordered_map<std::string, Apresentacao> apreTable;
std::unordered_map<std::string, Ingresso> ticketTable;


// ---------------Apresentação---------------
bool MSA::autenticar(const CPF& cpf, const Senha& senha) {
    // if (cpf.getConteudo() == "05289706151" &&
    //  senha.getConteudo() == "Aas123") {
    //      return true;
    //  } else {
    //      return false;
    //  }

    auto aux = userTable.find(cpf.getConteudo());

    if(aux == userTable.end()){
        return false; //nao existe esse cpf cadastrado
    }

    if((*aux).second.GetSenha().getConteudo() == senha.getConteudo()) {
        return true; // senha correta
    }
    return false; // senha incorreta
}

// ---------------Usuario---------------
bool MSU::cadastrar(const Usuario& usuario, const CartaoDeCredito& cartao) {
    auto user = usuario;
    user.cartao = cartao;
    userTable[user.GetCPF().getConteudo()] = user;
    return true;
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

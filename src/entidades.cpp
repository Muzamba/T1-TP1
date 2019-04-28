#include "entidades.h"

void Usuario::SetCPF(CPF cpf) {
    this->cpf = cpf;
}
CPF Usuario::GetCPF() {
    return cpf;
}


void Usuario::SetSenha(Senha senha) {
    this->senha = senha;
}
Senha Usuario::GetSenha() {
    return senha;
}




void Evento::SetCodigoDeEvento(CodigoDeEvento codigo) {
    this->codigo = codigo;
}
CodigoDeEvento Evento::GetCodigoDeEvento() {
    return codigo;
}


void Evento::SetNomeDeEvento(NomeDeEvento nome) {
    this->nome = nome;
}
NomeDeEvento Evento::GetNomeDeEvento() {
    return nome;
}


void Evento::SetCidade(Cidade cidade) {
    this->cidade = cidade;
}
Cidade Evento::GetCidade() {
    return cidade;
}


void Evento::SetEstado(Estado estado) {
    this->estado = estado;
}
Estado Evento::GetEstado() {
    return estado;
}


void Evento::SetClasseDeEvento(ClasseDeEvento classe) {
    this->classe = classe;
}
ClasseDeEvento Evento::GetClasseDeEvento() {
    return classe;
}


void Evento::SetFaixaEtaria(FaixaEtaria faixa) {
    this->faixa = faixa;
}
FaixaEtaria Evento::GetFaixaEtaria() {
    return faixa;
}




void Apresentacao::SetCodigoDeApresentacao(CodigoDeApresentacao codigo) {
    this->codigo = codigo;
}
CodigoDeApresentacao Apresentacao::GetCodigoDeApresentacao() {
    return codigo;
}

void Apresentacao::SetData(Data data) {
    this->data = data;
}
Data Apresentacao::GetData() {
    return data;
}

void Apresentacao::SetHorario(Horario horario) {
    this->horario = horario;
}
Horario Apresentacao::GetHorario() {
    return horario;
}

void Apresentacao::SetPreco(Preco preco) {
    this->preco = preco;
}
Preco Apresentacao::GetPreco() {
    return preco;
}

void Apresentacao::SetNumeroDeSala(NumeroDeSala numero) {
    this->sala = numero;
}
NumeroDeSala Apresentacao::GetNumeroDeSala() {
    return sala;
}

void Apresentacao::SetDisponibilidade(Disponibilidade disponibilidade) {
    this->disponibilidade = disponibilidade;
}
Disponibilidade Apresentacao::GetDisponibilidade() {
    return disponibilidade;
}




void Ingresso::SetCodigoDeIngresso(CodigoDeIngresso codigo) {
    this->codigo = codigo;
}
CodigoDeIngresso Ingresso::GetCodigoDeIngresso() {
    return codigo;
}




void CartaoDeCredito::SetNumCartaoCredito(NumCartaoCredito numero) {
    this->numero = numero;
}
NumCartaoCredito CartaoDeCredito::GetNumCartaoCredito() {
    return numero;
}

void CartaoDeCredito::SetCVV(CVV cvv) {
    this->codigo = cvv;
}
CVV CartaoDeCredito::GetCVV() {
    return codigo;
}

void CartaoDeCredito::SetDataDeValidade(DataDeValidade data) {
    this->dataDeValidade = data;
}
DataDeValidade CartaoDeCredito::GetDataDeValidade() {
    return dataDeValidade;
}

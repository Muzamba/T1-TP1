#include "dominios.h"

class Usuario {
public:
    void SetCPF();
    CPF GetCPF();

    void SetSenha();
    Senha GetSenha();

private:
    CPF cpf;
    Senha senha;
};

class Evento {
public:
    void SetCodigoDeEvento(CodigoDeEvento codigo);
    CodigoDeEvento GetCodigoDeEvento();

    void SetNomeDeEvento(NomeDeEvento nome);
    NomeDeEvento GetNomeDeEvento();
    
    void SetCidade();
    Cidade GetCidade();

    void SetEstado(Estado estado);
    Estado GetEstado();

    void SetClasseDeEvento(ClasseDeEvento classe);
    ClasseDeEvento GetClasseDeEvento();

    void SetFaixaEtaria(FaixaEtaria faixa);
    FaixaEtaria GetFaixaEtaria();

private:
    CodigoDeEvento codigo;
    NomeDeEvento nome;
    Cidade cidade;
    Estado estado;
    ClasseDeEvento classe;
    FaixaEtaria faixa;
};


class Apresentacao {
public:
    void SetCodigoDeApresentacao(CodigoDeApresentacao codigo);
    CodigoDeApresentacao GetCodigoDeApresentacao();
    
    void SetData(Data data);
    Data GetData();
    
    void SetHorario(Horario horario);
    Horario GetHorario();
    
    void SetPreco(Preco preco);
    Preco GetPreco();
    
    void SetNumeroDeSala(NumeroDeSala numero);
    NumeroDeSala GetNumeroDeSala();
    
    void SetDisponibilidade(Disponibilidade disponibilidade);
    Disponibilidade GetDisponibilidade();

private:
    CodigoDeApresentacao codigo;
    Data data;
    Horario horario;
    Preco preco;
    NumeroDeSala sala;
    Disponibilidade disponibilidade;
};

class Ingresso {
public:
    void SetCodigoDeIngresso(CodigoDeIngresso codigo);
    CodigoDeIngresso GetCodigoDeIngresso();

private:
    CodigoDeIngresso codigo;
};

class CartaoDeCredito {
public:
    void SetNumCartaoCredito(NumCartaoCredito numero);
    NumCartaoCredito GetNumCartaoCredito();

    void SetCVV(CVV cvv);
    CVV GetCVV();

    void SetDataDeValidade(DataDeValidade data);
    DataDeValidade GetDataDeValidade();

private:
    NumCartaoCredito numero;
    CVV codigo;
    DataDeValidade dataDeValidade;
};

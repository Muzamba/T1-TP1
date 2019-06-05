#ifndef MODULOS_H
#define MODULOS_H

#include "interfaces.h"


// ------------- Modulos de Apresentação ----------------------

// Apresentação de Autenticação
class MAA : public Super_int {
 public:
    void executar() override;
 private:
    ISA* servico;
    void autenticar();
};

// Apresentação de Usuário
class MAU : public Super_int {
 public:
    void executar() override;
 private:
    ISU* servico;

};

// Apresentação de Eventos
class MAE : public Super_int {
 public:
    void executar() override;
 private:
    ISE* servico;
};

// Apresentação de Vendas
class MAV : public Super_int {
 public:
    void executar() override;
 private:
    ISV* servico;
};


//---------------Modulos de Serviço-------------
// Serviço de Autenticação
class MSA : public ISA {
 public:
    virtual bool autenticar(const CPF& cpf, const Senha& senha) override;
};


// Serviço de Usuário
class MSU : public ISU {
 public:
    bool cadastrar(const Usuario&, const CartaoDeCredito&) override;
    bool descadastrar(const CPF&) override;
};

// Serviço de Eventos
class MSE :public ISE {
 public:
    virtual std::vector<Evento> buscar(Data inicio, Data fim, Cidade, Estado) override;
    virtual bool criarEvento(const CPF&, const Evento&, const std::vector<Apresentacao>&) override;
    virtual bool alteraEvento(const Evento&) override;
    virtual bool descadastrarEvento(const CodigoDeEvento&) override;
};

// Serviço de Vendas
class MSV :public ISV {
 public:
    virtual bool compraIngresso(const CPF&, const CodigoDeApresentacao&, const int) override;
};


#endif //MODULO_H

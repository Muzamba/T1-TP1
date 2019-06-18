// Copyright
#ifndef INCLUDE_MODULOS_H_
#define INCLUDE_MODULOS_H_
class MAA;
class MAU;
class MAE;
class MAV;

class MSA;
class MSU;
class MSE;
class MSV;

#include "./interfaces.h"


// ------------- Modulos de Apresentação ----------------------

// Apresentação de Autenticação
class MAA : public IAA {
friend class Builder;
 public:
    void executar() override;
 private:
    void autenticar();
    void draw_tela_autenticada();
};

// Apresentação de Usuário
class MAU : public IAU {
friend class Builder;
 public:
    void executar() override;
 private:

};

// Apresentação de Eventos
class MAE : public IAE {
friend class Builder;
 public:
    void executar() override;
 private:

};

// Apresentação de Vendas
class MAV : public IAV {
friend class Builder;
 public:
    void executar() override;

};


// ---------------Modulos de Serviço-------------
// Serviço de Autenticação
class MSA : public ISA {
friend class Builder;
 public:
    bool autenticar(const CPF& cpf, const Senha& senha) override;
};


// Serviço de Usuário
class MSU : public ISU {
friend class Builder;
 public:
    bool cadastrar(const Usuario&, const CartaoDeCredito&) override;
    bool descadastrar(const CPF&) override;
};

// Serviço de Eventos
class MSE :public ISE {
friend class Builder;
 public:
    std::vector<Evento> buscar(Data inicio, Data fim, Cidade, Estado) override;
    bool criarEvento(const CPF&, const Evento&, const std::vector<Apresentacao>&) override;
    bool alteraEvento(const Evento&) override;
    bool descadastrarEvento(const CodigoDeEvento&) override;
};

// Serviço de Vendas
class MSV :public ISV {
friend class Builder;
 public:
    bool compraIngresso(const CPF&, const CodigoDeApresentacao&, const int) override;
};


#endif  // INCLUDE_MODULOS_H_

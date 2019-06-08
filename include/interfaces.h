
#ifndef INCLUDE_INTERFACES_H_
#define INCLUDE_INTERFACES_H_

class IAA;
class IAU;
class IAE;
class IAV;

class ISA;
class ISU;
class ISE;
class ISV;


#include <string>
#include <iostream>
#include <vector>


#include "./dominios.h"
#include "./entidades.h"
#include "./controller.h"
#include "./builder.h"

// -------------------------Interface de Apresentação--------------------------
class IAA {
    friend class Builder;
 public:
    virtual void executar() = 0;
 protected:
    Controller* controller;
    ISA* servico;
};

class IAU {
    friend class Builder;
 public:
    virtual void executar() = 0;
 protected:
    Controller* controller;
    ISU* servico;
};

class IAE {
    friend class Builder;
 public:
    virtual void executar() = 0;
 protected:
    Controller* controller;
    ISE* servico;
};

class IAV {
    friend class Builder;
 public:
    virtual void executar() = 0;
 protected:
    Controller* controller;
    ISV* servico;
};


// ------------- Interfaces de Serviço ----------------------

// Serviço de Autenticação
class ISA {
    friend class Builder;
 public:
    virtual bool autenticar(const CPF& cpf, const Senha& senha) = 0;
 protected:
    IAA* iaa;
};


// Serviço de Usuário
class ISU {
    friend class Builder;
 public:
    virtual bool cadastrar(const Usuario&, const CartaoDeCredito&) = 0;
    virtual bool descadastrar(const CPF&) = 0;
 protected:
    IAU* iau;
};


// Serviço de Eventos
class ISE {
    friend class Builder;
 public:
    virtual std::vector<Evento> buscar(Data inicio, Data fim, Cidade, Estado) = 0;
    virtual bool criarEvento(const CPF&, const Evento&, const std::vector<Apresentacao>&) = 0;
    virtual bool alteraEvento(const Evento&) = 0;
    virtual bool descadastrarEvento(const CodigoDeEvento&) = 0;
 protected:
    IAE* iae;
};


// Serviço de Vendas
class ISV {
    friend class Builder;
 public:
    virtual bool compraIngresso(const CPF&, const CodigoDeApresentacao&, const int) = 0;
 protected:
    IAV* iav;
};


#endif  // INCLUDE_INTERFACES_H_

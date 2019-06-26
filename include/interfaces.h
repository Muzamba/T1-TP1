// Copyright
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
    Controller* controller = nullptr;
    ISA* servico = nullptr;
};

class IAU {
    friend class Builder;
 public:
    virtual void executar() = 0;
    virtual void verPerfil() = 0;
 protected:
    Controller* controller = nullptr;
    ISU* servico = nullptr;
};

class IAE {
    friend class Builder;
 public:
    virtual void executar() = 0;
    virtual void criarEvento() = 0;
 protected:
    Controller* controller = nullptr;
    ISE* servico = nullptr;
};

class IAV {
    friend class Builder;
 public:
    virtual void executar() = 0;
 protected:
    Controller* controller = nullptr;
    ISV* servico = nullptr;
};


// ------------- Interfaces de Serviço ----------------------

// Serviço de Autenticação
class ISA {
    friend class Builder;
 public:
    virtual bool autenticar(const CPF& cpf, const Senha& senha) = 0;
 protected:
    IAA* iaa = nullptr;
};


// Serviço de Usuário
class ISU {
    friend class Builder;
 public:
    virtual bool cadastrar(const Usuario&, const CartaoDeCredito&) = 0;
    virtual bool descadastrar(const CPF&) = 0;
    virtual Usuario infoLoggedUser(const char*) = 0;
 protected:
    IAU* iau = nullptr;
};


// Serviço de Eventos
class ISE {
    friend class Builder;
 public:
    virtual std::vector<Evento> buscar(Data inicio,
     Data fim, Cidade, Estado) = 0;
    virtual bool criarEvento(const CPF&, const Evento&,
     const std::vector<Apresentacao>&) = 0;
    virtual bool alteraEvento(const Evento&) = 0;
    virtual bool descadastrarEvento(const CodigoDeEvento&) = 0;
 protected:
    IAE* iae = nullptr;
};


// Serviço de Vendas
class ISV {
    friend class Builder;
 public:
    virtual bool compraIngresso(const CPF&, const CodigoDeApresentacao&, const int) = 0;
    virtual Apresentacao getApresbycodigo(const char*) = 0; 
 protected:
    IAV* iav = nullptr;
};


#endif  // INCLUDE_INTERFACES_H_

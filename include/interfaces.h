/**
 * @file interfaces.h
 * @author Ariel e João Pedro
 * @brief Biblioteca simples de Interfaces
 * @version 0.1
 * @date 2019-04-29
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef INCLUDE_INTERFACES_H_
#define INCLUDE_INTERFACES_H_

#include <string>
#include <iostream>
#include <vector>


#include "./dominios.h"
#include "./entidades.h"

class Controller {
 public:
    void executar();
 private:
    Super_int* maa;
    Super_int* mau;
    Super_int* mae;
    Super_int* mav;
};

class Super_int {
 public:
    virtual void executar() = 0;
 protected:
    Controller* controller;
};

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

// ------------- Interfaces de Serviço ----------------------

// Serviço de Autenticação
class ISA {
 public:
    virtual bool autenticar(const CPF& cpf, const Senha& senha) = 0;
 private:
    Super_int* iaa;
};

class MSA : public ISA {
 public:
    virtual bool autenticar(const CPF& cpf, const Senha& senha) override;
};

// Serviço de Usuário
class ISU {
 public:
    virtual bool cadastrar(const Usuario&, const CartaoDeCredito&) = 0;
    virtual bool descadastrar(const CPF&) = 0;
    virtual std::vector<Evento> getEventos(const CPF&) = 0;
    virtual std::vector<Apresentacao> getApresentacoes(const CodigoDeEvento&) = 0;
    virtual std::vector<Ingresso> getIngressos(const CodigoDeApresentacao&) = 0;
    virtual bool criarEvento(const CPF&, const Evento&, const std::vector<Apresentacao>&) = 0;
    virtual bool alteraEvento(const Evento&) = 0;
    virtual bool descadastrarEvento(const CodigoDeEvento&) = 0;
 private:
    Super_int* iau;
};

class MSU : public ISU {
 public:
    virtual bool cadastrar(const Usuario&, const CartaoDeCredito&) override;
    virtual bool descadastrar(const CPF&) override;
    virtual std::vector<Evento> getEventos(const CPF&) override;
    virtual std::vector<Apresentacao> getApresentacoes(const CodigoDeEvento&) override;
    virtual std::vector<Ingresso> getIngressos(const CodigoDeApresentacao&) override;
    virtual bool criarEvento(const CPF&, const Evento&, const std::vector<Apresentacao>&) override;
    virtual bool alteraEvento(const Evento&) override;
    virtual bool descadastrarEvento(const CodigoDeEvento&) override;
};

// Serviço de Eventos
class ISE {
 public:
    virtual std::vector<Evento> buscar(Data inicio, Data fim, Cidade, Estado) = 0;
 private:
    Super_int* iae;
};

class MSE :public ISE {
 public:
    virtual std::vector<Evento> buscar(Data inicio, Data fim, Cidade, Estado) override;
};

// Serviço de Vendas
class ISV {
 public:
    virtual bool compraIngresso(const CPF&, const CodigoDeApresentacao&, const int) = 0;
 private:
    Super_int* iav;
};

class MSV :public ISV {
 public:
    virtual bool compraIngresso(const CPF&, const CodigoDeApresentacao&, const int) override;
};



#endif  // INCLUDE_INTERFACES_H_

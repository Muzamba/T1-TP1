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
#include "controller.h"
#include "builder.h"

// -------------------------Interface de Apresentação--------------------------
class Super_int {
 friend class Builder;
 public:
    virtual void executar() = 0;
 protected:
    Controller* controller;
};


// ------------- Interfaces de Serviço ----------------------

// Serviço de Autenticação
class ISA {
 friend class Builder;
 public:
    virtual bool autenticar(const CPF& cpf, const Senha& senha) = 0;
 private:
    Super_int* iaa;
};


// Serviço de Usuário
class ISU {
 friend class Builder;
 public:
    virtual bool cadastrar(const Usuario&, const CartaoDeCredito&) = 0;
    virtual bool descadastrar(const CPF&) = 0;
    virtual std::vector<Evento> getEventos(const CPF&) = 0;
    virtual std::vector<Apresentacao> getApresentacoes(const CodigoDeEvento&) = 0;
    virtual std::vector<Ingresso> getIngressos(const CodigoDeApresentacao&) = 0;
    
 private:
    Super_int* iau;
};


// Serviço de Eventos
class ISE {
 friend class Builder;
 public:
    virtual std::vector<Evento> buscar(Data inicio, Data fim, Cidade, Estado) = 0;
    virtual bool criarEvento(const CPF&, const Evento&, const std::vector<Apresentacao>&) = 0;
    virtual bool alteraEvento(const Evento&) = 0;
    virtual bool descadastrarEvento(const CodigoDeEvento&) = 0;
 private:
    Super_int* iae;
};


// Serviço de Vendas
class ISV {
 friend class Builder;
 public:
    virtual bool compraIngresso(const CPF&, const CodigoDeApresentacao&, const int) = 0;
 private:
    Super_int* iav;
};


#endif  // INCLUDE_INTERFACES_H_

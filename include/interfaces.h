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
#include <typeinfo>
#include <vector>
#include <memory>
#include <unordered_map>

#include "./dominios.h"
#include "./entidades.h"

class Super_int {
 public:
    virtual void executar() = 0;
};

// ------------- Interfaces de Apresentação ----------------------

// Apresentação de Autenticação
class MAA : public Super_int {
 public:
    void executar() override;
 private:
    MSA* servico;
    void autenticar();
};

// Apresentação de Usuário
class MAU : public Super_int {
 public:
    void executar() override;
 private:
    MSU* servico;

};

// Apresentação de Eventos
class MAE : public Super_int {
 public:
    void executar() override;
 private:
    MSE* servico;
};

// Apresentação de Vendas
class MAV : public Super_int {
 public:
    void executar() override;
 private:
    MSV* servico;
};

// ------------- Interfaces de Serviço ----------------------

// Serviço de Autenticação
class MSA : public Super_int {
 public:
    void executar() override;
    bool executar(const Usuario &user);
 private:
    bool autenticar(CPF cpf, Senha senha);
};

// Serviço de Usuário
class MSU : public Super_int {
 public:
    void executar() override;
    void executar(const CPF &cpf);
 private:
    void get_data(Usuario &user);
};

// Serviço de Eventos
class MSE : public Super_int {
 public:
    void executar() override;
};

// Serviço de Vendas
class MSV : public Super_int {
 public:
    void executar() override;
};

// -------------- ERROR ---------------------------------------

// class ERROR : public Super_int {
//  public:
//  private:
//   ERROR();
// };

#endif  // INCLUDE_INTERFACES_H_

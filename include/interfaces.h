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

#include "./dominios.h"
#include "./entidades.h"

class Super_int {
 public:
    virtual void acao(std::string comando,
              std::vector<std::unique_ptr<Super_dom>> dominios =
                std::vector<std::unique_ptr<Super_dom>>(),
              std::vector<std::unique_ptr<Super_ent>> entidades =
                std::vector<std::unique_ptr<Super_ent>>()) = 0;
};

// ------------- Interfaces de Apresentação ----------------------

class IAA : public Super_int {};

class IAU : public Super_int {};

class IAE : public Super_int {};

class IAV : public Super_int {};

// ------------- Interfaces de Serviço ----------------------

class ISA : public Super_int {};

class ISU : public Super_int {};

class ISE : public Super_int {};

class ISV : public Super_int {};

// -------------- ERROR ---------------------------------------

class ERROR : public Super_int {};

#endif  // INCLUDE_INTERFACES_H_

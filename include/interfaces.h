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
    virtual void acao(std::string comando,
              std::vector<std::unique_ptr<Super_dom>> dominios =
                std::vector<std::unique_ptr<Super_dom>>(),
              std::vector<std::unique_ptr<Super_ent>> entidades =
                std::vector<std::unique_ptr<Super_ent>>()) = 0;
 protected:
    std::unordered_map<std::string,int> map;
};

// ------------- Interfaces de Apresentação ----------------------

class MAA : public Super_int {
 public:
  static MAA& Get();
  void acao(std::string comando,
              std::vector<std::unique_ptr<Super_dom>> dominios =
                std::vector<std::unique_ptr<Super_dom>>(),
              std::vector<std::unique_ptr<Super_ent>> entidades =
                std::vector<std::unique_ptr<Super_ent>>()) override;
 private:
  MAA();
};

class MAU : public Super_int {
 public:
  static MAU& Get();
  void acao(std::string comando,
              std::vector<std::unique_ptr<Super_dom>> dominios =
                std::vector<std::unique_ptr<Super_dom>>(),
              std::vector<std::unique_ptr<Super_ent>> entidades =
                std::vector<std::unique_ptr<Super_ent>>()) override;
 private:
  MAU();
};

class MAE : public Super_int {
 public:
  static MAE& Get();
  void acao(std::string comando,
              std::vector<std::unique_ptr<Super_dom>> dominios =
                std::vector<std::unique_ptr<Super_dom>>(),
              std::vector<std::unique_ptr<Super_ent>> entidades =
                std::vector<std::unique_ptr<Super_ent>>()) override;
 private:
  MAE();
};

class MAV : public Super_int {
 public:
  static MAV& Get();
  void acao(std::string comando,
              std::vector<std::unique_ptr<Super_dom>> dominios =
                std::vector<std::unique_ptr<Super_dom>>(),
              std::vector<std::unique_ptr<Super_ent>> entidades =
                std::vector<std::unique_ptr<Super_ent>>()) override;
 private:
  MAV();
};

// ------------- Interfaces de Serviço ----------------------

class MSA : public Super_int {
 public:
  static MSA& Get();
  void acao(std::string comando,
              std::vector<std::unique_ptr<Super_dom>> dominios =
                std::vector<std::unique_ptr<Super_dom>>(),
              std::vector<std::unique_ptr<Super_ent>> entidades =
                std::vector<std::unique_ptr<Super_ent>>()) override;
 private:
  MSA();
};

class MSU : public Super_int {
 public:
  static MSU& Get();
  void acao(std::string comando,
              std::vector<std::unique_ptr<Super_dom>> dominios =
                std::vector<std::unique_ptr<Super_dom>>(),
              std::vector<std::unique_ptr<Super_ent>> entidades =
                std::vector<std::unique_ptr<Super_ent>>()) override;
 private:
  MSU();
};

class MSE : public Super_int {
 public:
  static MSE& Get();
  void acao(std::string comando,
              std::vector<std::unique_ptr<Super_dom>> dominios =
                std::vector<std::unique_ptr<Super_dom>>(),
              std::vector<std::unique_ptr<Super_ent>> entidades =
                std::vector<std::unique_ptr<Super_ent>>()) override;
 private:
  MSE();
};

class MSV : public Super_int {
 public:
  static MSV& Get();
  void acao(std::string comando,
              std::vector<std::unique_ptr<Super_dom>> dominios =
                std::vector<std::unique_ptr<Super_dom>>(),
              std::vector<std::unique_ptr<Super_ent>> entidades =
                std::vector<std::unique_ptr<Super_ent>>()) override;
 private:
  MSV();
};

// -------------- ERROR ---------------------------------------

class ERROR : public Super_int {
 public:
  static ERROR& Get();
  void acao(std::string comando,
              std::vector<std::unique_ptr<Super_dom>> dominios =
                std::vector<std::unique_ptr<Super_dom>>(),
              std::vector<std::unique_ptr<Super_ent>> entidades =
                std::vector<std::unique_ptr<Super_ent>>()) override;
 private:
  ERROR();
};

#endif  // INCLUDE_INTERFACES_H_

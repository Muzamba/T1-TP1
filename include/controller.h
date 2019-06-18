// Copyright
#ifndef INCLUDE_CONTROLLER_H_
#define INCLUDE_CONTROLLER_H_

class Controller;

#include <ncurses.h>
#include <string>
#include "./interfaces.h"
#include "./builder.h"

class Controller {
  friend class Builder;
 public:
    void executar();
    void login(bool, const char*);
    std::string getCpf();
    Controller();
    ~Controller();
 private:
    IAA* maa;
    IAU* mau;
    IAE* mae;
    IAV* mav;
    bool isLogged;
    std::string cpf;
};


#endif  // INCLUDE_CONTROLLER_H_


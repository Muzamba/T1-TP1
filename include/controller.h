// Copyright
#ifndef INCLUDE_CONTROLLER_H_
#define INCLUDE_CONTROLLER_H_

class Controller;

#include <ncurses.h>
#include "./interfaces.h"
#include "./builder.h"

class Controller {
  friend class Builder;
 public:
    void executar();
    Controller();
    ~Controller();
 private:
    IAA* maa;
    IAU* mau;
    IAE* mae;
    IAV* mav;
};


#endif  // INCLUDE_CONTROLLER_H_


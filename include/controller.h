#ifndef CONTROLER_H
#define CONTROLER_H

#include "interfaces.h"
#include "builder.h"
#include <ncurses.h>

class Controller {
  friend class Builder;
 public:
    void executar();
    Controller();
 private:
    Super_int* maa;
    Super_int* mau;
    Super_int* mae;
    Super_int* mav;
};


#endif //CONTROLER_H


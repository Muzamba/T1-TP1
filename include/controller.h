#ifndef CONTROLER_H
#define CONTROLER_H
class Controller;

#include "interfaces.h"
#include "builder.h"
#include <ncurses.h>

class Controller {
  friend class Builder;
 public:
    void executar();
    Controller();
 private:
    IAA* maa;
    IAU* mau;
    IAE* mae;
    IAV* mav;
};


#endif //CONTROLER_H


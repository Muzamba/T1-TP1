#ifndef BUILDER_H
#define BUILDER_H
class Builder;

#include "interfaces.h"
#include "container.h"

class Builder {
 public:
    static Controller* buildSistema();
    static DataBase*  buildDB();
};


#endif //BUILDER_H

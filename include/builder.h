// Copyright
#ifndef INCLUDE_BUILDER_H_
#define INCLUDE_BUILDER_H_
class Builder;

#include "./interfaces.h"
#include "./container.h"
// #include "./controller.h"

class Builder {
 public:
    static Controller* buildSistema();
    static DataBase*  buildDB();
    static void destroySistema(Controller*);
    static void destroyDB(DataBase*);
};


#endif  // INCLUDE_BUILDER_H_

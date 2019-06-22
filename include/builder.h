// Copyright
#ifndef INCLUDE_BUILDER_H_
#define INCLUDE_BUILDER_H_
class Builder;

#include "./interfaces.h"
// #include "./controller.h"

class Builder {
 public:
    static Controller* buildSistema();
    static void destroySistema(Controller*);
};


#endif  // INCLUDE_BUILDER_H_

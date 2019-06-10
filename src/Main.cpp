// Copyright
#include "./builder.h"
#include "./container.h"
#include "./controller.h"
#include "./dominios.h"
#include "./entidades.h"
#include "./interfaces.h"
#include "./modulos.h"

int main(int argc, char const *argv[]) {
    auto controller = Builder::buildSistema();

    controller->executar();

    Builder::destroySistema(controller);
    delete controller;
    return 0;
}

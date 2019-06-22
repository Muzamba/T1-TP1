// Copyright
#include "./builder.h"
#include "./modulos.h"

Controller* Builder::buildSistema() {
    Controller* controller = new Controller();

    IAA* maa = new MAA();
    IAE* mae = new MAE();
    IAU* mau = new MAU();
    IAV* mav = new MAV();

    ISA* msa = new MSA();
    ISE* mse = new MSE();
    ISU* msu = new MSU();
    ISV* msv = new MSV();

    msa->iaa = maa;
    mse->iae = mae;
    msu->iau = mau;
    msv->iav = mav;

    maa->controller = controller;
    mae->controller = controller;
    mau->controller = controller;
    mav->controller = controller;

    maa->servico = msa;
    mae->servico = mse;
    mau->servico = msu;
    mav->servico = msv;

    controller->maa = maa;
    controller->mae = mae;
    controller->mau = mau;
    controller->mav = mav;

    controller->isLogged = false;

    return controller;
}

void Builder::destroySistema(Controller* controller) {
    // Liberando o espaço alocado durante o build do sistema

    delete controller->maa->servico;
    delete controller->mae->servico;
    delete controller->mau->servico;
    delete controller->mav->servico;

    delete controller->maa;
    delete controller->mae;
    delete controller->mau;
    delete controller->mav;
}

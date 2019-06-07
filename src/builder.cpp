#include "builder.h"
#include "modulos.h"

Controller* Builder::buildSistema() {
    auto controller = new Controller();

    auto maa = new MAA();
    auto mae = new MAE();
    auto mau = new MAU();
    auto mav = new MAV();

    maa->controller = controller;
    mae->controller = controller;
    mau->controller = controller;
    mav->controller = controller;


    maa->servico = new MSA();
    mae->servico = new MSE();
    mau->servico = new MSU();
    mav->servico = new MSV();

    auto db = buildDB();

    controller->maa = maa;
    controller->mae = mae;
    controller->mau = mau;
    controller->mav = mav;


    return controller;
}



DataBase*  Builder::buildDB() {
    auto db = new DataBase();

    db->usuarios = new Usuarios();
    db->eventos = new Eventos();
    db->apresentacoes = new Apresentacoes();
    db->cartoes = new CartoesDeCredito();
    db->ingressos = new Ingressos();

    return db;
}
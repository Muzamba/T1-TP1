#include "interfaces.h"


// MSA---------------------------------------------------------------
MSA::MSA() {
    map["comando"] = 0; //id
}

void MSA::acao( std::string comando,
                std::vector<std::unique_ptr<Super_dom>> dominios,
                std::vector<std::unique_ptr<Super_ent>> entidades) {
    switch (map[comando]) {
    case 0:
        break;
    
    default:
        break;
    }
}

MSA& MSA::Get() {
    static MSA msa = MSA();
    return msa;
}
//-------------------------------------------------------------------

// MSU---------------------------------------------------------------
MSU::MSU() {
    map["comando"] = 0; //id
}

void MSU::acao( std::string comando,
                std::vector<std::unique_ptr<Super_dom>> dominios,
                std::vector<std::unique_ptr<Super_ent>> entidades) {
    switch (map[comando]) {
    case 0:
        break;
    
    default:
        break;
    }
}

MSU& MSU::Get() {
    static MSU msu = MSU();
    return msu;
}
//-------------------------------------------------------------------

// MSE---------------------------------------------------------------
MSE::MSE() {
    map["comando"] = 0; //id
}

void MSE::acao( std::string comando,
                std::vector<std::unique_ptr<Super_dom>> dominios,
                std::vector<std::unique_ptr<Super_ent>> entidades) {
    switch (map[comando]) {
    case 0:
        break;
    
    default:
        break;
    }
}

MSE& MSE::Get() {
    static MSE mse = MSE();
    return mse;
}
//-------------------------------------------------------------------

// MSV---------------------------------------------------------------
MSV::MSV() {
    map["comando"] = 0; //id
}

void MSV::acao( std::string comando,
                std::vector<std::unique_ptr<Super_dom>> dominios,
                std::vector<std::unique_ptr<Super_ent>> entidades) {
    switch (map[comando]) {
    case 0:
        break;
    
    default:
        break;
    }
}

MSV& MSV::Get() {
    static MSV msv = MSV();
    return msv;
}
//-------------------------------------------------------------------

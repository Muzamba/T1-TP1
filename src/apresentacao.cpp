#include "interfaces.h"


// MAA---------------------------------------------------------------
MAA::MAA() {
    map["comando"] = 0; //id
}

void MAA::acao( std::string comando,
                std::vector<std::unique_ptr<Super_dom>> dominios,
                std::vector<std::unique_ptr<Super_ent>> entidades) {
    switch (map[comando]) {
    case 0:
        break;
    
    default:
        break;
    }
}

MAA& MAA::Get() {
    static MAA maa = MAA();
    return maa;
}
//-------------------------------------------------------------------


// MAU---------------------------------------------------------------
MAU::MAU() {
    map["comando"] = 0; //id
}

void MAU::acao( std::string comando,
                std::vector<std::unique_ptr<Super_dom>> dominios,
                std::vector<std::unique_ptr<Super_ent>> entidades) {
    switch (map[comando]) {
    case 0:
        break;
    
    default:
        break;
    }

}

MAU& MAU::Get() {
    static MAU mau = MAU();
    return mau;
}
//-------------------------------------------------------------------

// MAE---------------------------------------------------------------
MAE::MAE() {
    map["comando"] = 0; //id
}

void MAE::acao( std::string comando,
                std::vector<std::unique_ptr<Super_dom>> dominios,
                std::vector<std::unique_ptr<Super_ent>> entidades) {
    switch (map[comando]) {
    case 0:
        break;
    
    default:
        break;
    }
}

MAE& MAE::Get() {
    static MAE mae = MAE();
    return mae;
}
//-------------------------------------------------------------------

// MAV---------------------------------------------------------------
MAV::MAV() {
    map["comando"] = 0; //id
}

void MAV::acao( std::string comando,
                std::vector<std::unique_ptr<Super_dom>> dominios,
                std::vector<std::unique_ptr<Super_ent>> entidades) {
    switch (map[comando]) {
    case 0:
        break;
    
    default:
        break;
    }
}

MAV& MAV::Get() {
    static MAV mav = MAV();
    return mav;
}
//-------------------------------------------------------------------


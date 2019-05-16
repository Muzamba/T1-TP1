#include "interfaces.h"


// ERROR-------------------------------------------------------------
ERROR::ERROR() {
    map["comando"] = 0; //id
}

void ERROR::acao( std::string comando,
                std::vector<std::unique_ptr<Super_dom>> dominios,
                std::vector<std::unique_ptr<Super_ent>> entidades) {
    switch (map[comando]) {
    case 0:
        break;
    
    default:
        break;
    }
}

ERROR& ERROR::Get() {
    static ERROR error = ERROR();
    return error;
}
//-------------------------------------------------------------------

#include "controller.h"


Controller::Controller() {
    auto window = initscr();
    
}

void Controller::executar() {
    while(1){
        refresh();
    }
}



// Copyright
#include "./controller.h"


Controller::Controller() {
    initscr();
    cbreak();
}

Controller::~Controller() {
    endwin();
}
void Controller::executar() {
    // Menu principal
    int height, widht, start_y, start_x;
    height = 38;
    widht = 135;
    start_y = 2;
    start_x = 5;


    WINDOW* win = newwin(height, widht, start_y, start_x);
    refresh();

    box(win, 0, 0);
    wrefresh(win);

    int c = getch();
}



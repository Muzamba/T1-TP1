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
    std::string opcoes[4] = {"Ver Eventos", "Login", "Cadastrar", "sair"};
    int y_max, x_max;
    getmaxyx(stdscr, y_max, x_max);

    static WINDOW* win = newwin(6, x_max-12, y_max-25, 5);
    box(win, 0, 0);
    refresh();
    wrefresh(win);

    keypad(win, true);
    int choice;
    int highlight = 0;

    while (true) {
        for (int i = 0; i < 4; i++) {
            if (i == highlight) {
                wattron(win, A_REVERSE);
            }
            int win_y, win_x;
            getmaxyx(win, win_y, win_x);
            mvwprintw(win, i+1, win_x/2-5, opcoes[i].c_str());
            wattroff(win, A_REVERSE);
        }
        choice = wgetch(win);

        switch (choice) {
            case KEY_UP:
                highlight--;
                if (highlight == -1) {
                    highlight = 0;
                }
                break;
            case KEY_DOWN:
                highlight++;
                if (highlight == 3) {
                    highlight = 3;
                }
                break;
            default:
                break;
        }

        if (choice == 10) {
            switch (highlight) {
                case 0:
                    mav->executar();
                    break;
                case 1:
                    maa->executar();
                    break;
                case 2:
                    mau->executar();
                default:
                    break;
            }
        }

        box(win, 0, 0);
        clear();
        refresh();
    }
    int c = getch();
}



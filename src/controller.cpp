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
    std::string nome = "Switch Dreams";
    int y_max, x_max;
    int wy_max, wx_max;

    getmaxyx(stdscr, y_max, x_max);

    static WINDOW* win = newwin(10, 30, y_max/2 - 5, x_max/2 - 15);

    getmaxyx(win, wy_max, wx_max);

    cbreak();
    noecho();
    curs_set(0);
    keypad(win, true);

    int choice;
    int highlight = 0;

    box(win, 0, 0);
    mvwprintw(win, 0, wx_max/2 - nome.size()/2, nome.c_str());
    wrefresh(win);

    while (true) {
        for (int i = 0; i < 4; i++) {
            if (i == highlight) {
                wattron(win, A_REVERSE);
            }
            int win_y, win_x;
            getmaxyx(win, win_y, win_x);
            mvwprintw(win, i + 3, win_x / 2 - opcoes[i].size()/2,
             opcoes[i].c_str());
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
                if (highlight == 4) {
                    highlight = 3;
                }
                break;
            default:
                break;
        }

        if (choice == 10) {
            switch (highlight) {
                case 0:  // Ver eventos
                    mae->executar();
                    break;
                case 1:  // Login
                    maa->executar();
                    box(win, 0, 0);
                    mvwprintw(win, 0, wx_max/2 - nome.size()/2, nome.c_str());
                    wrefresh(win);
                    break;
                case 2:  // Cadastrar
                    mau->executar();
                default:
                    return;
                    break;
            }
        }
    }
}



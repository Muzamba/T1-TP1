// Copyright
#include "./controller.h"


Controller::Controller() {
    initscr();
    cbreak();
}

Controller::~Controller() {
    endwin();
}

void Controller::login(bool isLogged, const char* cpf) {
    if (isLogged) {
        this->isLogged = isLogged;
        this->cpf = cpf;
    } else {
        this->isLogged = isLogged;
        this->cpf = "";
    }
}

void Controller::executar() {
    // Menu principal
    std::string opcoes[4] = {"Ver Eventos", "Login", "Cadastrar", "sair"};
    std::string nome = "Switch Dreams";
    int y_max, x_max;
    int nl_wy_max, nl_wx_max;  // Not Logged Y e X
    int l_wy_max, l_wx_max;  // Logged Y e X

    getmaxyx(stdscr, y_max, x_max);

    static WINDOW* not_log_win = newwin(10, 30, y_max/2 - 5, x_max/2 - 15);
    static WINDOW* logged_win = newwin(10, 30, y_max/2 - 5, x_max/2 - 15);

    getmaxyx(not_log_win, nl_wy_max, nl_wx_max);
    getmaxyx(logged_win, l_wy_max, l_wx_max);

    cbreak();
    noecho();
    curs_set(0);
    keypad(not_log_win, true);

    int choice;
    int highlight = 0;

    box(not_log_win, 0, 0);
    mvwprintw(not_log_win, 0, nl_wx_max/2 - nome.size()/2, nome.c_str());
    wrefresh(not_log_win);

    while (true) {
        for (int i = 0; i < 4; i++) {
            if (i == highlight) {
                wattron(not_log_win, A_REVERSE);
            }
            int not_log_win_y, not_log_win_x;
            getmaxyx(not_log_win, not_log_win_y, not_log_win_x);
            mvwprintw(not_log_win, i + 3,
             not_log_win_x / 2 - opcoes[i].size()/2, opcoes[i].c_str());
            wattroff(not_log_win, A_REVERSE);
        }
        choice = wgetch(not_log_win);

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
                    if (isLogged) {
                        box(logged_win, 0, 0);
                        mvwprintw(logged_win, 0, l_wx_max/2 - cpf.size()/2,
                         cpf.c_str());
                        wrefresh(logged_win);
                        break;
                    } else {
                        box(not_log_win, 0, 0);
                        mvwprintw(not_log_win, 0, nl_wx_max/2 - nome.size()/2,
                         nome.c_str());
                        wrefresh(not_log_win);
                        break;
                    }
                case 2:  // Cadastrar
                    mau->executar();
                default:
                    return;
                    break;
            }
        }
    }
}



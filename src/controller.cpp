// Copyright
#include "./controller.h"


Controller::Controller() {
    initscr();
    cbreak();
}

Controller::~Controller() {
    endwin();
}

void Controller::login(bool isLogged, const char* cpf = "") {
    if (isLogged) {
        this->isLogged = isLogged;
        this->cpf = cpf;
    } else {
        this->isLogged = isLogged;
        this->cpf = "";  // Resetando o cpf armazenado
    }
}

std::string Controller::getCpf() {
    if (isLogged) {
        return cpf;
    } else {
        return "";
    }
}

void Controller::executar() {
    // Menu principal
    // Not Logged opções
    std::string nl_opcoes[4] = {"Ver Eventos", "Login", "Cadastrar", "sair"};
    // Logged opções
    std::string l_opcoes[5] = {"Ver Perfil", "Cadastrar Eventos",
     "Ver Eventos", "Comprar Eventos", "Logout"};
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
    keypad(logged_win, true);

    int choice;
    int highlight = 0;

    box(not_log_win, 0, 0);
    mvwprintw(not_log_win, 0, nl_wx_max/2 - nome.size()/2, nome.c_str());
    wrefresh(not_log_win);

    while (true) {
        if (isLogged) {
            for (int i = 0; i < 5; i++) {
                if (i == highlight) {
                    wattron(logged_win, A_REVERSE);
                }
                mvwprintw(logged_win, i + 3,
                l_wx_max / 2 - l_opcoes[i].size()/2, l_opcoes[i].c_str());
                wattroff(logged_win, A_REVERSE);
            }
            choice = wgetch(logged_win);

            switch (choice) {
                case KEY_UP:
                    highlight--;
                    if (highlight == -1) {
                        highlight = 0;
                    }
                    break;
                case KEY_DOWN:
                    highlight++;
                    if (highlight == 5) {
                        highlight = 4;
                    }
                    break;
                default:
                    break;
            }

            if (choice == 10) {
                switch (highlight) {
                    case 0:
                        continue;
                        break;
                    case 1:
                        continue;
                        break;
                    case 2:
                        mae->executar();
                        box(logged_win, 0, 0);
                        mvwprintw(logged_win, 0, l_wx_max/2 - cpf.size()/2,
                        cpf.c_str());
                        wrefresh(logged_win);
                        break;
                    case 3:
                        continue;
                        break;
                    default:
                        login(false);
                        wclear(logged_win);
                        wrefresh(logged_win);
                        box(not_log_win, 0, 0);
                        mvwprintw(not_log_win, 0, nl_wx_max/2-nome.size()/2,
                         nome.c_str());
                        wrefresh(not_log_win);
                        // Voltando o Highlight para o primeiro elemento
                        highlight = 0;
                        break;
                }
            }
        } else {
            for (int i = 0; i < 4; i++) {
                if (i == highlight) {
                    wattron(not_log_win, A_REVERSE);
                }
                mvwprintw(not_log_win, i + 3,
                nl_wx_max / 2 - nl_opcoes[i].size()/2, nl_opcoes[i].c_str());
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
                        box(not_log_win, 0, 0);
                        mvwprintw(not_log_win, 0, nl_wx_max/2-nome.size()/2,
                        nome.c_str());
                        wrefresh(not_log_win);
                        break;
                    case 1:  // Login
                        maa->executar();
                        if (isLogged) {
                            box(logged_win, 0, 0);
                            mvwprintw(logged_win, 0, l_wx_max/2 - cpf.size()/2,
                            cpf.c_str());
                            wrefresh(logged_win);
                            // Voltando o Highlight para o primeiro elemento
                            highlight = 0;
                            break;
                        } else {
                            box(not_log_win, 0, 0);
                            mvwprintw(not_log_win, 0, nl_wx_max/2-nome.size()/2,
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
}



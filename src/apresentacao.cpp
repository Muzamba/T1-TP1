// Copyright
#include <ncurses.h>
#include <string.h>
#include "./modulos.h"

// ---------Apresentação---------
void MAA::executar() {
    clear();
    int y_max, x_max;
    getmaxyx(stdscr, y_max, x_max);

    // static WINDOW* win = newwin(y_max-5, x_max-12, y_max-40, 5);
    static WINDOW* win = newwin(10, x_max-12, y_max-27, 5);
    box(win, 0, 0);
    refresh();
    wrefresh(win);

    int wy_max, wx_max;
    char cpf[] = "Digite o CPF  : ";
    char senha[] = "Digite a senha: ";
    char usr_cpf[80];
    char usr_senha[80];

    getmaxyx(win, wy_max, wx_max);
    mvprintw(wy_max/2, (wx_max-strlen(cpf))/2, "%s", cpf);
    getstr(usr_cpf);
    mvprintw(wy_max/2 + 2, (wy_max-strlen(usr_senha))/2, "%s", campo2);
    clear();

    getch();
    wclear(win);
    wrefresh(win);
}

void MAA::autenticar() {

}

// ---------------Usuarios---------------
void MAU::executar() {

}

// ---------------Eventos---------------
void MAE::executar() {

}

// ---------------Vendas---------------
void MAV::executar() {

}


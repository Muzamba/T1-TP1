// Copyright
#include <ncurses.h>
#include <string.h>
#include "./modulos.h"

// ---------Apresentação---------
void MAA::executar() {
    
    int y_max, x_max;
    int wy_max, wx_max;


    std::string ops[] = {"Confirmar", "Voltar"};
    std::string login = "Login";
    std::string cpfLabel = "Cpf";
    std::string senhaLabel = "Senha";

    char cpf[15];
    char senha[10];


    getmaxyx(stdscr, y_max, x_max);
    auto win_erro = newwin(5, 30, 0, x_max - 30);

    // static WINDOW* win = newwin(y_max-5, x_max-12, y_max-40, 5);
    WINDOW* win = newwin(10, 30, y_max/2 - 5, x_max/2 - 15);
    getmaxyx(win, wy_max, wx_max);

    box(win, 0, 0);
    mvwprintw(win, 0, wx_max/2 - login.size()/2, login.c_str());
    mvwprintw(win, 3, 14 - cpfLabel.size(), cpfLabel.c_str());
    mvwprintw(win, 6, 14 - senhaLabel.size(), senhaLabel.c_str());
    wrefresh(win);

    WINDOW *cpfForm, *senhaForm;
    cpfForm = newwin(3, 13, win->_begy + 2, win->_begx + 15);
    senhaForm = newwin(3, 8, win->_begy + 5, win->_begx + 15);


    box(cpfForm,0,0);
    wrefresh(cpfForm);

    box(senhaForm, 0, 0);
    wrefresh(senhaForm);

    CPF u_cpf;
    Senha u_senha;

    while(true) {
        echo();
        curs_set(1);

        wmove(cpfForm, 1, 1);
        wgetstr(cpfForm,cpf);

        wmove(senhaForm, 1, 1);
        wgetstr(senhaForm, senha);

        try {
            u_cpf.setConteudo(cpf);

            u_senha.setConteudo(senha);
        } catch (...) {
            wmove(win_erro, 1, 0);
            wprintw(win_erro, "Erro no Formato");
            wrefresh(win_erro); 
            continue;
        }

        

        if(servico->autenticar(u_cpf, u_senha)) {
            wmove(win_erro, 1, 0);
            wprintw(win_erro, "Login realizado com sucesso");
            wrefresh(win_erro);
            break;
        } else {
            wmove(win_erro, 1, 0);
            wprintw(win_erro, "Falha na autenticação");
            wrefresh(win_erro);
        } 
    }

    wclear(win);
    wrefresh(win);
    delwin(win);

    wclear(cpfForm);
    wrefresh(cpfForm);
    delwin(cpfForm);

    wclear(senhaForm);
    wrefresh(senhaForm);
    delwin(senhaForm);

    noecho();
    curs_set(0);
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


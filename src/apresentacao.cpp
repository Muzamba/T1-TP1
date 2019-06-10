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
    clear();
    refresh();
    int y_max, x_max;
    getmaxyx(stdscr, y_max, x_max);

    auto leftWin = newwin(y_max - 2, x_max / 2 - 2, 1, 1);
    box(leftWin, 0, 0);
    //wrefresh(leftWin);

    auto rightWin = newwin(y_max - 2, x_max / 2 - 2, 1,  x_max / 2 + 2);
    box(rightWin, 0, 0);
    //wrefresh(rightWin);

    auto searchWin = newwin(18, 40, y_max/2 - 9, x_max /2 - 20);
    box(searchWin, 0, 0);

    std::string eventos = "Eventos";
    mvwprintw(searchWin, 0, searchWin->_maxx / 2 - eventos.size() / 2, eventos.c_str());
    

    WINDOW* form[4];
    std::string labels[4] = {"Data de Inicio", "Data de Termino", "Cidade", "Estado"};
    
    
    for(int i = 0;i < 4;i++) {
        form[i] = newwin(3, 17,searchWin->_begy + 3 + i * 3, searchWin->_begx + searchWin->_maxx - 19);
        box(form[i], 0, 0);
        //wrefresh(form[i]);
    }

    for(int i = 0;i < 4;i++) {
        mvwprintw(searchWin, form[i]->_begy - searchWin->_begy + 1, form[i]->_begx - searchWin->_begx - labels[i].size() - 1, labels[i].c_str());
    }
    wrefresh(searchWin);

    for(int i = 0; i < 4;i++){
        wrefresh(form[i]);
    }

    getch();





    wclear(leftWin);
    wrefresh(leftWin);
    delwin(leftWin);

    wclear(rightWin);
    wrefresh(rightWin);
    delwin(rightWin);

    wclear(searchWin);
    wrefresh(searchWin);
    delwin(searchWin);
}

// ---------------Vendas---------------
void MAV::executar() {

}


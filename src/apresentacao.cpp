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
    WINDOW* win_erro = newwin(5, 30, 0, x_max - 30);

    // static WINDOW* win = newwin(y_max-5, x_max-12, y_max-40, 5);
    // Janela principal do menu de login
    WINDOW* win = newwin(12, 30, y_max/2 - 6, x_max/2 - 15);
    getmaxyx(win, wy_max, wx_max);

    box(win, 0, 0);

    // Campos que serão utilizados nos forms
    mvwprintw(win, 0, wx_max/2 - login.size()/2, login.c_str());
    mvwprintw(win, 3, 14 - cpfLabel.size(), cpfLabel.c_str());
    mvwprintw(win, 6, 14 - senhaLabel.size(), senhaLabel.c_str());
    wrefresh(win);

    // Janelas referentes aos campos cpf e senha no formulário
    WINDOW *cpfForm, *senhaForm;
    cpfForm = newwin(3, 13, win->_begy + 2, win->_begx + 15);
    senhaForm = newwin(3, 8, win->_begy + 5, win->_begx + 15);

    box(cpfForm, 0, 0);
    wrefresh(cpfForm);

    box(senhaForm, 0, 0);
    wrefresh(senhaForm);

    keypad(win, true);

    // Objetos CPF e Senha que serão utilizados para a validação do formato
    CPF u_cpf;
    Senha u_senha;

    bool digitou = false;
    int highlight = 0;
    int choice;

    // Lógica que desenha o menu
    while (true) {
        echo();
        curs_set(1);

        int16_t cont = 0;

        wmove(cpfForm, 1, 1);

        // Previne o sistema de receber mais caracteres caso o usuário já tenha
        // digitado
        if (!digitou) {
            wgetstr(cpfForm, cpf);
            cont++;
        }
        wmove(senhaForm, 1, 1);
        if (!digitou) {
            wgetstr(senhaForm, senha);
            cont++;
        }

        if (cont == 2) digitou = true;

        // highlight na opção a ser selecionada
        for (int i = 0; i < 2; i++) {
            if (i == highlight) {
                wattron(win, A_REVERSE);
            }
            int win_y, win_x;
            getmaxyx(win, win_y, win_x);
            mvwprintw(win, win_y-2, 2+ i*(ops[i-1].size()+6), ops[i].c_str());
            wattroff(win, A_REVERSE);
        }

        choice = wgetch(win);

        switch (choice) {
            case KEY_LEFT:
                highlight--;
                if (highlight == -1) {
                    highlight = 0;
                }
                break;
            case KEY_RIGHT:
                highlight++;
                if (highlight == 2) {
                    highlight = 1;
                }
                break;
            default:
                break;
        }

        if (choice == 10) {
            switch (highlight) {
                case 0:
                    // Tratamento dos erros que podem ser gerados por formato
                    // incorreto de input
                    try {
                        u_cpf.setConteudo(cpf);

                        u_senha.setConteudo(senha);
                    } catch (...) {
                        wmove(win_erro, 1, 0);
                        wprintw(win_erro,
                         "Erro no Formato, insira os dados novamente");

                        // Limpando os campos dos forms
                        mvwprintw(cpfForm, 1, 1, "           ");
                        mvwprintw(senhaForm, 1, 1, "      ");

                        wrefresh(win_erro);
                        wrefresh(cpfForm);
                        wrefresh(senhaForm);

                        digitou = false;
                        cont = 0;
                        continue;
                    }

                    if (servico->autenticar(u_cpf, u_senha)) {
                        wmove(win_erro, 1, 0);
                        wprintw(win_erro, "Login realizado com sucesso");
                        wrefresh(win_erro);
                        draw_tela_autenticada();

                        box(win, 0, 0);
                        mvwprintw(win, 0, wx_max/2 - login.size()/2,
                         login.c_str());
                        mvwprintw(win, 3, 14 - cpfLabel.size(),
                         cpfLabel.c_str());
                        mvwprintw(win, 6, 14 - senhaLabel.size(),
                         senhaLabel.c_str());
                        wrefresh(win);

                        box(cpfForm, 0, 0);
                        box(senhaForm, 0, 0);

                        // Limpando os campos dos forms
                        mvwprintw(cpfForm, 1, 1, "           ");
                        mvwprintw(senhaForm, 1, 1, "      ");

                        // Limpando o buffer das strings que recebem as infos
                        // dos forms
                        snprintf(cpf, sizeof(cpf), "");
                        snprintf(senha, sizeof(senha), "");

                        wrefresh(cpfForm);
                        wrefresh(senhaForm);
                        break;
                    } else {
                        wmove(win_erro, 1, 0);
                        wprintw(win_erro, "Falha na autenticação");
                        wrefresh(win_erro);
                    }
                    break;
                case 1:
                    wclear(win);
                    wrefresh(win);
                    delwin(win);

                    wclear(cpfForm);
                    wrefresh(cpfForm);
                    delwin(cpfForm);

                    wclear(senhaForm);
                    wrefresh(senhaForm);
                    delwin(senhaForm);

                    return;
                    break;
            }
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

void MAA::draw_tela_autenticada() {
    int y_max, x_max;
    getmaxyx(stdscr, y_max, x_max);

    WINDOW* win = newwin(12, 30, y_max/2 - 6, x_max/2 - 15);
    box(win, 0, 0);
    wrefresh(win);
    getch();

    wclear(win);
    wrefresh(win);
    delwin(win);
    return;
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


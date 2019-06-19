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
    char senha[6] = {0};


    getmaxyx(stdscr, y_max, x_max);
    WINDOW* win_erro = newwin(5, 45, 0, x_max/2-20);

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
        keypad(senhaForm, true);
        if (!digitou) {
            noecho();
            int p = 0;
            p = wgetch(senhaForm);
            if (p == 10) {  // 10 -> tecla enter apertada
                goto enter;  // Se digitou enter n quer botar nada
            } else {         // então pula a parte de preencher a senha
                senha[0] = p;
                wprintw(senhaForm, "*");
                wmove(senhaForm, 1, 2);
                for (int i = 1; i <= 5; i++) {
                    senha[i] = wgetch(senhaForm);
                    wprintw(senhaForm, "*");
                    wmove(senhaForm, 1, 2+i);
                }
                wprintw(senhaForm, "*");
            }
            // wgetstr(senhaForm, senha);
            enter:
            echo();
            cont++;
        }


        if (cont == 2) digitou = true;

        curs_set(0);
        // highlight na opção a ser selecionada
        for (int i = 0; i < 2; i++) {
            if (i == highlight) {
                wattron(win, A_REVERSE);
            }
            int win_y, win_x;
            getmaxyx(win, win_y, win_x);
            mvwprintw(win, win_y-2, 2 + i*(ops[i-1].size()+11), ops[i].c_str());
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
                        controller->login(true, cpf);

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
    printw("%d %d", y_max, x_max);
    wgetch(win);

    wclear(win);
    wrefresh(win);
    delwin(win);
    return;
}

void MAA::autenticar() {
}

// ---------------Usuarios---------------
void MAU::executar() {
    // Inputs do usuária
    char cpf[20];
    char senha[20];
    char senha_rep[20];
    char cart_cred[20];
    char validade[20];
    char cvv[20];

    const int NUM_FIELDS = 6;

    // Buttons
    std::string opcoes[2] = {"Menu", "Cadastrar"};

    // Cleaning up
    clear();
    refresh();

    // Screen boundaries
    int y_max, x_max;
    getmaxyx(stdscr, y_max, x_max);

    // sign up window
    auto cad_win = newwin(25, 44, y_max/2 - 12, x_max/2 - 20);
    box(cad_win, 0, 0);
    keypad(cad_win, true);

    // Win name
    std::string cadastro = "Cadastro";
    mvwprintw(cad_win, 0, cad_win->_maxx / 2 - cadastro.size() / 2 + 1,
     cadastro.c_str());

    // Forms and labels
    WINDOW* form[NUM_FIELDS];
    std::string labels[NUM_FIELDS] = {"CPF", "Senha", "Senha Novamente",
     "Cartão de Crédito", "Validade do Cartão", "CVV"};

    // Form boxes
    for (int i = 0; i < NUM_FIELDS; i++) {
        form[i] = newwin(3, 17, cad_win->_begy + 3 + i * 3,
         cad_win->_begx + cad_win->_maxx - 19);
        box(form[i], 0, 0);
    }

    // Form Labels
    for (int i = 0; i < NUM_FIELDS; i++) {
        mvwprintw(cad_win, form[i]->_begy - cad_win->_begy + 1,
         form[i]->_begx - cad_win->_begx - labels[i].size() - 1,
         labels[i].c_str());
    }

    // Buttons
    for (int i = 0; i < 2; i++) {
        mvwprintw(cad_win,
         cad_win->_maxy - 1, 5 + i * (30 - opcoes[i].size()),
         opcoes[i].c_str());
    }

    wrefresh(cad_win);
    // Refreshes
    for (int i = 0; i < NUM_FIELDS; i++) {
        wrefresh(form[i]);
    }

    // Form Loop
    int highlight = 0;
    int choice = 0;
    CPF usr_cpf;
    Senha usr_senha;
    Senha usr_senha_rep;
    CartaoDeCredito usr_cart_cred;
    DataDeValidade usr_validade;
    CVV usr_cvv;

    while (true) {
        echo();
        curs_set(1);

        wmove(form[0], 1, 1);
        wgetstr(form[0], cpf);

        noecho();
        wmove(form[1], 1, 1);
        wgetstr(form[1], senha);

        wmove(form[2], 1, 1);
        wgetstr(form[2], senha_rep);
        echo();

        wmove(form[3], 1, 1);
        wgetstr(form[3], cart_cred);

        wmove(form[4], 1, 1);
        wgetstr(form[4], validade);

        wmove(form[5], 1, 1);
        wgetstr(form[5], cvv);

        noecho();
        curs_set(0);

        // Interaction Loop
        while (true) {
            // opcoes
            for (int i = 0; i < 2; i++) {
                if (i == highlight) {
                    wattron(cad_win, A_REVERSE);
                }
                mvwprintw(cad_win,
                 cad_win->_maxy - 1, 5 + i * (30 - opcoes[i].size()),
                 opcoes[i].c_str());
                wattroff(cad_win, A_REVERSE);
            }
            choice = wgetch(cad_win);

            // Selection
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
            // Action

            if (choice == 10) {
                switch (highlight) {
                    case 0:
                        for (int i = 0; i < NUM_FIELDS; i++) {
                            wclear(form[i]);
                            wrefresh(form[i]);
                            delwin(form[i]);
                        }
                        wclear(cad_win);
                        wrefresh(cad_win);
                        delwin(cad_win);
                        return;
                        break;
                    case 1:
                        return;
                        break;
                    default:
                        break;
                }
            }
        }
    }

    // getch();
    wclear(cad_win);
    wrefresh(cad_win);
    delwin(cad_win);
    return;
}

// ---------------Eventos---------------
void MAE::executar() {
    // variaveis para guardar a info que entrar no form
    char dataI[20];
    char dataT[20];
    char cidade[20];
    char estado[20];

    // O que vai ter escrito nos botoes em baixo
    std::string opcoes[2] = {"Menu", "Buscar"};

    // limpando tela antes de começar
    clear();
    refresh();

    // pegando tamanhos da tela total
    int y_max, x_max;
    getmaxyx(stdscr, y_max, x_max);

    // aba para a seleção do evento desejado
    auto leftWin = newwin(y_max - 2, x_max / 2 - 2, 1, 1);
    box(leftWin, 0, 0);

    // aba que mostra as apresentações da do evento selecionado na aba esquerda
    auto rightWin = newwin(y_max - 2, x_max / 2 - 2, 1,  x_max / 2 + 2);
    box(rightWin, 0, 0);


    // Janela de busca
    auto searchWin = newwin(18, 40, y_max/2 - 9, x_max /2 - 20);
    box(searchWin, 0, 0);
    keypad(searchWin, true);

    // Nome da janela
    std::string usr_cpf = controller->getCpf();
    std::string eventos;
    if (usr_cpf.size() > 0) {
        eventos = "Eventos " + usr_cpf;
    } else {
        eventos = "Eventos";
    }
    mvwprintw(searchWin, 0, searchWin->_maxx / 2 - eventos.size() / 2,
     eventos.c_str());

    // espaçoes para os form
    WINDOW* form[4];
    std::string labels[4] = {"Data de Inicio", "Data de Termino", "Cidade",
     "Estado"};

    // caixas dos forms
    for (int i = 0; i < 4; i++) {
        form[i] = newwin(3, 17, searchWin->_begy + 3 + i * 3,
         searchWin->_begx + searchWin->_maxx - 19);
        box(form[i], 0, 0);
        // wrefresh(form[i]);
    }
    // labels dos forms
    for (int i = 0; i < 4; i++) {
        mvwprintw(searchWin, form[i]->_begy - searchWin->_begy + 1,
         form[i]->_begx - searchWin->_begx - labels[i].size() - 1,
         labels[i].c_str());
    }
    // botoes em baixo
    for (int i = 0; i < 2; i++) {
        mvwprintw(searchWin,
         searchWin->_maxy - 1, 5 + i * (30 - opcoes[i].size()),
         opcoes[i].c_str());
    }
    wrefresh(searchWin);

    // Refresh nas box's dos form's
    for (int i = 0; i < 4; i++) {
        wrefresh(form[i]);
    }

    // Janela para o log de erro
    auto win_erro = newwin(5, 40, 0, x_max/2 - 20);

    // loop do form
    bool manterBuscaWin = true;
    int highlight = 0;
    int choice = 0;
    Data dateI;
    Data dateT;
    Cidade cid;
    Estado est;
    bool deuRuim = false;
    std::vector<Evento> vetor;
    while (true) {
        // Get dos forms
        echo();
        curs_set(1);
        wmove(form[0], 1, 1);
        wgetstr(form[0], dataI);
        wmove(form[1], 1, 1);
        wgetstr(form[1], dataT);
        wmove(form[2], 1, 1);
        wgetstr(form[2], cidade);
        wmove(form[3], 1, 1);
        wgetstr(form[3], estado);
        noecho();
        curs_set(0);

        if (deuRuim) {
            manterBuscaWin = true;
        }
        // seleção entre o  botao menu e buscar
        while (manterBuscaWin) {
            // printando opções
            for (int i = 0; i < 2; i++) {
                if (i == highlight) {
                    wattron(searchWin, A_REVERSE);
                }

                mvwprintw(searchWin,
                 searchWin->_maxy - 1, 5 + i * (30 - opcoes[i].size()),
                 opcoes[i].c_str());
                wattroff(searchWin, A_REVERSE);
            }
            choice = wgetch(searchWin);
            // seleção do opção
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
                // acao do menu de busca
            if (choice == 10) {
                switch (highlight) {
                    case 0:  // Menu
                        wclear(win_erro);
                        wrefresh(win_erro);
                        delwin(win_erro);

                        wclear(leftWin);
                        wrefresh(leftWin);
                        delwin(leftWin);

                        wclear(rightWin);
                        wrefresh(rightWin);
                        delwin(rightWin);

                        wclear(searchWin);
                        wrefresh(searchWin);
                        delwin(searchWin);
                        return;
                        break;
                    case 1:  // Buscar
                        deuRuim = false;

                        // verificação dos formatos
                        try {
                            dateI.setConteudo(dataI);
                            mvwprintw(win_erro, 0, 0,
                             "                                 ");
                        } catch(...) {
                            mvwprintw(win_erro, 0, 0,
                             "Erro no formato da data de inicio");
                            deuRuim = true;
                        }

                        try {
                            dateT.setConteudo(dataT);
                            mvwprintw(win_erro, 1, 0,
                            "                                  ");
                        } catch(...) {
                            mvwprintw(win_erro, 1, 0,
                            "Erro no formato da data de termino");
                            deuRuim = true;
                        }

                        try {
                            cid.setConteudo(cidade);
                            mvwprintw(win_erro, 2, 0,
                            "                         ");
                        } catch(...) {
                            mvwprintw(win_erro, 2, 0,
                            "Erro no formato da cidade");
                            deuRuim = true;
                        }

                        try {
                            est.setConteudo(estado);
                            mvwprintw(win_erro, 3, 0,
                            "                         ");
                        } catch(...) {
                            mvwprintw(win_erro, 3, 0,
                            "Erro no formato do estado");
                            deuRuim = true;
                        }

                        wrefresh(win_erro);
                        manterBuscaWin = false;
                        if (deuRuim) {  // saindo caso tenha dado erro
                            break;
                        }
                        // aquisição do vetor de eventos
                        vetor = servico->buscar(dateI, dateT, cid, est);
                        clear();
                        refresh();

                        // desenhando tela para mostrar eventos e apresentaçoes
                        mvwprintw(leftWin, 0,
                        leftWin->_maxx/2 - eventos.size()/2, eventos.c_str());
                        mvwprintw(leftWin, 1, 1,
                         "Pressione 'q' para voltar ao menu inicial");
                        mvwprintw(rightWin, 0, rightWin->_maxx/2 - 7,
                         "Apresentacoes");
                        wrefresh(leftWin);
                        wrefresh(rightWin);

                        highlight = 0;
                        int a;

                        // escolha de evento
                        while (true) {
                            std::vector<Apresentacao> vetorA;
                            // printando a lista de todos os eventos
                            for (int i = 0; i < vetor.size(); i++) {
                                if (i == highlight) {
                                    wattron(leftWin, A_REVERSE);
                                }

                                // Fazer metodo ja retorna formatado
                                mvwprintw(leftWin, 2 + i, 3,
                                vetor[i].GetNomeDeEvento().getConteudo().c_str());
                                wattroff(searchWin, A_REVERSE);
                            }
                            // adiquirindo vetor de apresentação
                            vetor[highlight];  // vetorA=buscaApre(vetor[highlight]) //fazer funcao ou metodo que retona todas as apresentações de um evento passado como parametro
                            // printando as apresentaçoes na janela direita
                            for (int i = 0; i < vetorA.size(); i++) {
                                // fazer metodo que retorna o q ira aparecer em cada apresentação
                                mvwprintw(rightWin, 2 + i, 3,
                                vetorA[i].GetCodigoDeApresentacao().getConteudo().c_str()); 
                            }

                            a = getch();
                            // selecionando evento ou saindo
                            switch (a) {
                                case KEY_UP:
                                    highlight--;
                                    if (highlight == -1) {
                                        highlight = 0;
                                    }
                                    break;
                                case KEY_DOWN:
                                    highlight++;
                                    if (highlight == vetor.size() + 1) {
                                        highlight = vetor.size();
                                    }
                                    break;

                                case 'q':
                                    wclear(win_erro);
                                    wrefresh(win_erro);
                                    delwin(win_erro);

                                    wclear(leftWin);
                                    wrefresh(leftWin);
                                    delwin(leftWin);

                                    wclear(rightWin);
                                    wrefresh(rightWin);
                                    delwin(rightWin);

                                    wclear(searchWin);
                                    wrefresh(searchWin);
                                    delwin(searchWin);
                                    return;

                                default:
                                    break;
                            }
                        }
                        break;
                    default:
                        break;
                }
            }
        }
    }
    wclear(win_erro);
    wrefresh(win_erro);
    delwin(win_erro);

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


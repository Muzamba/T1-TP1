// Copyright
#include <ncurses.h>
#include <string.h>
#include "./modulos.h"

// ---------Autenticação---------
void MAA::executar() {
    int y_max, x_max;
    int wy_max, wx_max;


    std::string ops[] = { "Menu", "Confirmar"};
    std::string login = "Login";
    std::string cpfLabel = "Cpf";
    std::string senhaLabel = "Senha";

    char cpf[15];
    std::string senha;

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

    for (int i = 0; i < 2; i++) {
        int win_y, win_x;
        getmaxyx(win, win_y, win_x);
        mvwprintw(win, win_y-2, 2 + i*(ops[i-1].size()+11), ops[i].c_str());
    }
    wrefresh(win);

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
            noecho();
            int p = 0;
            int x = 1;

            senha.clear();
            while (true) {
                wmove(senhaForm, 1, x);
                p = wgetch(senhaForm);
                if (p != 10 && x < 7) {
                    wmove(senhaForm, 1, x);
                    wprintw(senhaForm, "*");
                    senha += p;
                } else {
                    break;
                }
                x++;
            }
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
                case 1:
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
                    }

                    if (servico->autenticar(u_cpf, u_senha)) {
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

                        wclear(win_erro);
                        wrefresh(win_erro);
                        delwin(win_erro);

                        return;
                    } else {
                        wmove(win_erro, 1, 0);
                        wprintw(win_erro, "Falha na autenticação");
                        wrefresh(win_erro);

                        // Limpando os campos dos forms
                        mvwprintw(cpfForm, 1, 1, "           ");
                        mvwprintw(senhaForm, 1, 1, "      ");

                        wrefresh(win_erro);
                        wrefresh(cpfForm);
                        wrefresh(senhaForm);

                        digitou = false;
                        cont = 0;
                    }
                    break;
                case 0:
                    wclear(win);
                    wrefresh(win);
                    delwin(win);

                    wclear(cpfForm);
                    wrefresh(cpfForm);
                    delwin(cpfForm);

                    wclear(senhaForm);
                    wrefresh(senhaForm);
                    delwin(senhaForm);

                    wclear(win_erro);
                    wrefresh(win_erro);
                    delwin(win_erro);

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

    wclear(win_erro);
    wrefresh(win_erro);
    delwin(win_erro);

    noecho();
    curs_set(0);
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

    // Error window
    auto win_erro = newwin(5, 50, 0, x_max/2 - 20);


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
        form[i] = newwin(3, 18, cad_win->_begy + 3 + i * 3,
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
    int cont = 0;
    bool deuRuim = false;
    bool manterCadWin = true;
    CPF usr_cpf;
    Senha usr_senha;
    Senha usr_senha_rep;
    NumCartaoCredito usr_cart_cred;
    DataDeValidade usr_validade;
    CVV usr_cvv;

    while (true) {
        echo();
        curs_set(1);

        wmove(form[0], 1, 1);
        wgetstr(form[0], cpf);

        // noecho();
        wmove(form[1], 1, 1);
        wgetstr(form[1], senha);

        wmove(form[2], 1, 1);
        wgetstr(form[2], senha_rep);
        // echo();

        wmove(form[3], 1, 1);
        wgetstr(form[3], cart_cred);

        wmove(form[4], 1, 1);
        wgetstr(form[4], validade);

        wmove(form[5], 1, 1);
        wgetstr(form[5], cvv);

        noecho();
        curs_set(0);

        if (deuRuim) {
            manterCadWin = true;
        }

        // Interaction Loop
        while (manterCadWin) {
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
                    case 0:  // sair
                        for (int i = 0; i < NUM_FIELDS; i++) {
                            wclear(form[i]);
                            wrefresh(form[i]);
                            delwin(form[i]);
                        }
                        wclear(cad_win);
                        wrefresh(cad_win);
                        delwin(cad_win);

                        wclear(win_erro);
                        wrefresh(win_erro);
                        delwin(win_erro);

                        return;
                        break;
                    case 1: {  // cadastrar
                        // Trying to set the values
                        deuRuim = false;

                        try {
                            usr_cpf.setConteudo(cpf);
                            mvwprintw(win_erro, 0, 0,
                             "                                              ");
                        } catch (...) {
                            mvwprintw(win_erro, 0, 0, "Erro no formato do CPF");
                            deuRuim = true;
                        }

                        try {
                            usr_senha.setConteudo(senha);
                            mvwprintw(win_erro, 1, 0,
                             "                                              ");
                        } catch (...) {
                            mvwprintw(win_erro, 1, 0,
                             "Erro no formato da senha");
                            deuRuim = true;
                        }

                        try {
                            usr_senha_rep.setConteudo(senha_rep);
                            mvwprintw(win_erro, 2, 0,
                             "                                              ");
                        } catch (...) {
                            mvwprintw(win_erro, 2, 0,
                             "Erro no formato da repetição da senha");
                            deuRuim = true;
                        }

                        if (usr_senha.getConteudo() !=
                         usr_senha_rep.getConteudo()) {
                            mvwprintw(win_erro, 2, 0,
                             "As duas senhas não coincidem");
                        }

                        try {
                            usr_cart_cred.setConteudo(cart_cred);
                            mvwprintw(win_erro, 3, 0,
                             "                                              ");
                        } catch (...) {
                            mvwprintw(win_erro, 3, 0,
                             "Erro no formato do Número do Cartão de Crédito");
                            deuRuim = true;
                        }

                        try {
                            usr_validade.setConteudo(validade);
                            mvwprintw(win_erro, 4, 0,
                             "                                              ");
                        } catch (...) {
                            mvwprintw(win_erro, 4, 0,
                             "Erro no formato da Data de Validade");
                            deuRuim = true;
                        }

                        try {
                            usr_cvv.setConteudo(cvv);
                            mvwprintw(win_erro, 5, 0,
                             "                                              ");
                        } catch (...) {
                            mvwprintw(win_erro, 5, 0,
                             "Erro no formato do CVV");
                            deuRuim = true;
                        }
                        wrefresh(win_erro);

                        manterCadWin = false;
                        if (deuRuim) {
                            for (int i = 0; i < NUM_FIELDS; i++) {
                                mvwprintw(form[i], 1, 1,
                                "                ");
                                wrefresh(form[i]);
                            }
                            break;
                        }

                        Usuario usuario;
                        CartaoDeCredito cartao_cred;

                        usuario.SetCPF(usr_cpf);
                        usuario.SetSenha(usr_senha);

                        cartao_cred.SetCVV(usr_cvv);
                        cartao_cred.SetDataDeValidade(usr_validade);
                        cartao_cred.SetNumCartaoCredito(usr_cart_cred);

                        if (servico->cadastrar(usuario, cartao_cred)) {
                            continue;
                        } else {
                            mvwprintw(win_erro, 1, 1,
                             "Erro ao cadastrar! Usuário já existe!");
                            wrefresh(win_erro);
                            deuRuim = true;
                            // Limpando os campos dos forms
                            for (int i = 0; i < NUM_FIELDS; i++) {
                                mvwprintw(form[i], 1, 1,
                                "                ");
                                wrefresh(form[i]);
                            }
                        }
                        break;
                    }
                    default:
                        break;
                }
            }
        }
        if (!deuRuim) {  // Retornando ao menu principal caso tudo esteja bem
            break;
        }
    }
    for (int i = 0; i < NUM_FIELDS; i++) {
        wclear(form[i]);
        wrefresh(form[i]);
        delwin(form[i]);
    }

    wclear(win_erro);
    wrefresh(win_erro);
    delwin(win_erro);

    wclear(cad_win);
    wrefresh(cad_win);
    delwin(cad_win);
    return;
}

void MAU::verPerfil() {
    std::string firstOps[4] = {"Eventos Cadastrados", "Dados de Usuário", "Descadastrar", "Voltar"};
    std::string info = "Info Perfil";
    int y_max, x_max, wy_max, wx_max, i_wy_max, i_wx_max;
    int choice, highlight = 0;
    Usuario tmp;
    std::string cpf = controller->getCpf();
    getmaxyx(stdscr, y_max, x_max);

    auto perfWin = newwin(10, 30, y_max/2 - 5, x_max/2 - 15);
    auto infoWin = newwin(12, 40, y_max/2 - 6, x_max/2 - 20);
    keypad(perfWin, true);
    auto win_erro = newwin(5, 45, 0, x_max/2 - 20);

    clear();
    refresh();
    cbreak();
    noecho();
    curs_set(0);

    getmaxyx(perfWin, wy_max, wx_max);
    getmaxyx(infoWin, i_wy_max, i_wx_max);

    box(perfWin, 0, 0);
    mvwprintw(perfWin, 0, wx_max/2 - cpf.size()/2, cpf.c_str());
    wrefresh(perfWin);
    CPF usuario;
    while (true) {
        for (int i = 0; i < 4; i++) {
            if (i == highlight) {
                wattron(perfWin, A_REVERSE);
            }
            mvwprintw(perfWin, i + 3,
             wx_max/2 - firstOps[i].size()/2, firstOps[i].c_str());
            wattroff(perfWin, A_REVERSE); 
        }
        choice = wgetch(perfWin);

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
                case 0:  // Eventos cadastrados
                    verEventos();
                    box(perfWin, 0, 0);
                    mvwprintw(perfWin, 0, wx_max/2 - cpf.size()/2, cpf.c_str());
                    wrefresh(perfWin);
                    break;
                case 1:  // Dados do usuário
                    wclear(perfWin);
                    wrefresh(perfWin);

                    tmp = servico->infoLoggedUser(controller->getCpf().c_str());

                    box(infoWin, 0, 0);
                    mvwprintw(infoWin, 0, i_wx_max/2 - info.size()/2, info.c_str());
                    wrefresh(infoWin);

                    mvwprintw(infoWin, 2, 2, "CPF: %s", tmp.GetCPF().getConteudo().c_str());
                    mvwprintw(infoWin, 3, 2, "Cartão de Credito: %s", tmp.cartao.GetNumCartaoCredito().getConteudo().c_str());
                    mvwprintw(infoWin, 4, 2, "Validade do Cartão: %s", tmp.cartao.GetDataDeValidade().getConteudo().c_str());
                    mvwprintw(infoWin, 5, 2, "CVV: %s", tmp.cartao.GetCVV().getConteudo().c_str());
                    mvwprintw(infoWin, 6, 2, "Eventos Cadastrados: %d", tmp.vecEventos.size());
                    mvwprintw(infoWin, 10,2, "Pressione qualquer tecla para voltar");
                    wrefresh(infoWin);

                    getch();
                    wclear(infoWin);
                    wrefresh(infoWin);
                    box(perfWin, 0, 0);
                    mvwprintw(perfWin, 0, wx_max/2 - cpf.size()/2, cpf.c_str());
                    wrefresh(perfWin);
                    break;
                case 2:  // Descadastrar
                    
                    usuario.setConteudo(controller->getCpf());
                    if(servico->descadastrar(usuario)) {
                        wclear(perfWin);
                        wrefresh(perfWin);
                        delwin(perfWin);

                        wclear(infoWin);
                        wrefresh(infoWin);
                        delwin(infoWin);
                        controller->login(false, "");
                        

                        return;
                    } else {
                        mvwprintw(win_erro, 0, 0, "Erro ao descadastrar");
                        wrefresh(win_erro);
                    }
                    break;
                default:  // Sair
                    wclear(infoWin);
                    wrefresh(infoWin);
                    delwin(infoWin);

                    wclear(perfWin);
                    wrefresh(perfWin);
                    delwin(perfWin);
                    return;
                    break;
            }
        }
        wrefresh(perfWin);
    }
    // getch();

    

    wclear(perfWin);
    wrefresh(perfWin);
    delwin(perfWin);
    return;
}

void MAU::verEventos() {
    clear();
    refresh();
    int x_max, y_max;
    getmaxyx(stdscr, y_max, x_max);

    WINDOW* winEvento = newwin(y_max - 2, 40, 1, x_max/2 - 20);
    box(winEvento, 0, 0);
    mvwprintw(winEvento, 0, winEvento->_maxx/2 - 3, "Eventos");
    wrefresh(winEvento);
    keypad(winEvento, true);



    auto eventos = servico->infoLoggedUser(controller->getCpf().c_str()).vecEventos;

    bool manterTela = true;
    int highlight = 0, choice;
    while(manterTela) {
        for (int i = 0; i < eventos.size(); i++) {
            if (i == highlight) {
                wattron(winEvento, A_REVERSE);
            }
            int win_y, win_x;
            getmaxyx(winEvento, win_y, win_x);
            mvwprintw(winEvento, 2 + 1 * i , 2, eventos[i].GetNomeDeEvento().getConteudo().c_str());
            wattroff(winEvento, A_REVERSE);
        }

        choice = wgetch(winEvento);

        switch (choice) {
            case KEY_UP:
                highlight--;
                if (highlight == -1) {
                    highlight = 0;
                }
                break;
            case KEY_DOWN:
                highlight++;
                if (highlight == eventos.size()) {
                    highlight = eventos.size() - 1;
                }
                break;

            case 'q':
                return;
            default:
                break;
        }

        if(choice == 10) {
            manterTela = false;
        }
    }
    std::string opcoes[4] = {"Apresenta", "Editar", "Remover", "Voltar"};
    int highlight2 = 0;
    while(true) {
        for (int i = 0; i < 4; i++) {
            if (i == highlight2) {
                wattron(winEvento, A_REVERSE);
            }
            int win_y, win_x;
            getmaxyx(winEvento, win_y, win_x);
            mvwprintw(winEvento, win_y - 2 , 2 + i * 10, opcoes[i].c_str());
            wattroff(winEvento, A_REVERSE);
        }

        choice = wgetch(winEvento);

        switch (choice) {
            case KEY_LEFT:
                highlight2--;
                if (highlight2 == -1) {
                    highlight2 = 0;
                }
                break;
            case KEY_RIGHT:
                highlight2++;
                if (highlight2 == 4) {
                    highlight2 = 3;
                }
                break;

            case 'q':
                clear();
                refresh();
                    
                wclear(winEvento);
                wrefresh(winEvento);
                delwin(winEvento);
                return;
            
            default:
                break;
        }

        if(choice == 10) {
            switch(highlight2) {
                case 0: //Apresenta
                    break;

                case 1: //Editar
                    break;

                case 2: //Remover
                    break;

                case 3: //Voltar
                    clear();
                    refresh();
                    
                    wclear(winEvento);
                    wrefresh(winEvento);
                    delwin(winEvento);
                    return;
                    break;
            }
        }

        
    }
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
    keypad(leftWin, true);

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
                        for (int i = 0; i < 4; i++) {
                            wclear(form[i]);
                            wrefresh(form[i]);
                            delwin(form[i]);
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
                        return;
                        break;
                    case 1:  // Buscar
                        deuRuim = false;

                        // verificação dos formatos
                        try {
                            dateI.setConteudo(dataI);
                            mvwprintw(win_erro, 0, 0,
                             "                                              ");
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
                        // Limpando os campos
                        manterBuscaWin = false;
                        if (deuRuim) {  // saindo caso tenha dado erro
                            for (int i = 0; i < 4; i++) {
                                mvwprintw(form[i], 1, 1,
                                "              ");
                                wrefresh(form[i]);
                            }
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
                            
                            // printando a lista de todos os eventos
                            for (int i = 0; i < vetor.size(); i++) {
                                if (i == highlight) {
                                    wattron(leftWin, A_REVERSE);
                                }

                                // Fazer metodo ja retorna formatado
                                std::string classeS;
                                auto classe = std::stoi(vetor[i].GetClasseDeEvento().getConteudo());

                                switch (classe) {
                                    case 1:
                                        classeS = "TEATRO";
                                        break;
                                    case 2:
                                        classeS = "ESPORTE";
                                        break;
                                    case 3:
                                        classeS = "SHOW NACIONAL";
                                        break;
                                    case 4:
                                        classeS = "SHOW INTERNACIONAL";
                                        break;

                                }

                                mvwprintw(leftWin, 2 + i, 3, " Nome: %s - Classe: %s - Faixa: %s",
                                vetor[i].GetNomeDeEvento().getConteudo().c_str(),
                                classeS.c_str(),
                                vetor[i].GetFaixaEtaria().getConteudo().c_str());
                                wattroff(leftWin, A_REVERSE);
                            }
                            wrefresh(leftWin);
                            // adiquirindo vetor de apresentação
                            vetor[highlight];  // vetorA=buscaApre(vetor[highlight]) //fazer funcao ou metodo que retona todas as apresentações de um evento passado como parametro
                            // printando as apresentaçoes na janela direita
                            std::string apreInfo;  // info das apresentações
                            if(vetor.size()!=0) {
                                for (int i = 0; i < vetor[highlight].vecApres.size(); i++) {
                                    // fazer metodo que retorna
                                    //  o q ira aparecer em cada apresentação
                                    //apreInfo = MSE::infoApresentacao(vetor[highlight].vecApres[i]);
                                    //mvwprintw(rightWin, 7*i + 3, 3, apreInfo.c_str());

                                    mvwprintw(rightWin, 2+i + 7*i, 3, "Código da Apresentação: %s", vetor[highlight].vecApres[i].GetCodigoDeApresentacao().getConteudo().c_str());
                                    mvwprintw(rightWin, 3+i + 7*i, 3, "Data: %s", vetor[highlight].vecApres[i].GetData().getConteudo().c_str());
                                    mvwprintw(rightWin, 4+i + 7*i, 3, "Disponibilidade: %s", vetor[highlight].vecApres[i].GetDisponibilidade().getConteudo().c_str());
                                    mvwprintw(rightWin, 5+i + 7*i, 3, "Horário: %s", vetor[highlight].vecApres[i].GetHorario().getConteudo().c_str());
                                    mvwprintw(rightWin, 6+i + 7*i, 3, "Sala: %s", vetor[highlight].vecApres[i].GetNumeroDeSala().getConteudo().c_str());
                                    mvwprintw(rightWin, 7+i + 7*i, 3, "Preço: %s", vetor[highlight].vecApres[i].GetPreco().getConteudo().c_str());
                                }
                            }
                            wrefresh(rightWin);

                            a = wgetch(leftWin);
                            wclear(rightWin);
                            box(rightWin, 0, 0);
                            wrefresh(rightWin);
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
                                    if (highlight == vetor.size()) {
                                        highlight = vetor.size() - 1;
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

void MAE::criarEvento() {
    echo();
    int y_max, x_max;
    getmaxyx(stdscr, y_max, x_max);
    wrefresh(stdscr);
    
    // Janela onde ficara o formulario
    auto janelaEvento = newwin(23, 40, y_max/2 - 10, x_max/2 - 20);
    box(janelaEvento, 0, 0);
    mvwprintw(janelaEvento, 0, janelaEvento->_maxx/2 - 8,"Cadastrar Evento");
    // printando as labels
    std::string labels[6] = {"Nome", "Cidade", "Estado", "Classe", "Faixa", "N de apresentacoes"};
    for(int i = 0;i < 6;i++) {
        mvwprintw(janelaEvento, 5 + 3 * i, 20 - labels[i].size()- 1, labels[i].c_str());
    }
    //desenhando na tela
    wrefresh(janelaEvento);
    // janela de erro
    WINDOW* win_erro = newwin(6, 45, 0, x_max/2-20);


    //array de windows para as caixas de texto
    WINDOW* forms[6] = {nullptr};
    for(int i = 0; i < 6; i++) {
        forms[i] = newwin(3, 19, janelaEvento->_begy + 4 + 3 * i, janelaEvento->_begx + 20);
        box(forms[i], 0, 0);
        wrefresh(forms[i]);
    }
    //variaveis para a verificação
    NomeDeEvento nome;
    Cidade cidade;
    Estado estado;
    ClasseDeEvento classe;
    FaixaEtaria faixa;
    int nmrDeApresentacoes = 0;


    //loop de incersão
    bool manterTelaCriarEvento = true;
    char respForm[6][18] = {{' '}};
    curs_set(1);
    while(manterTelaCriarEvento){
        //limpando form
        for(int i = 0;i < 6;i++) {
            mvwprintw(forms[i],1,1,"                 ");
            wrefresh(forms[i]);
            wmove(forms[i],1,1);
        }
        //pegando info
        for(int i = 0;i < 6;i++) {
            wgetstr(forms[i],respForm[i]);
        }
        //verificando infos
        {
            manterTelaCriarEvento = false;
            try{
                nome.setConteudo(respForm[0]);
                mvwprintw(win_erro, 0, 0, "                    ");
            }catch(...) {
                manterTelaCriarEvento = true;
                mvwprintw(win_erro, 0, 0, "Erro no nome");
            }

            try{
                cidade.setConteudo(respForm[1]);
                mvwprintw(win_erro, 1, 0, "                    ");
            }catch(...) {
                manterTelaCriarEvento = true;
                mvwprintw(win_erro, 1, 0, "Erro na cidade");
                
            }

            try{
                estado.setConteudo(respForm[2]);
                mvwprintw(win_erro, 2, 0, "                    ");
            }catch(...) {
                manterTelaCriarEvento = true;
                mvwprintw(win_erro, 2, 0, "Erro no estado");
                
            }

            try{
                classe.setConteudo(respForm[3]);
                mvwprintw(win_erro, 3, 0, "                    ");
            }catch(...) {
                manterTelaCriarEvento = true;
                mvwprintw(win_erro, 3, 0, "Erro na classe");
                
            }

            try{
                faixa.setConteudo(respForm[4]);
                mvwprintw(win_erro, 4, 0, "                    ");
            }catch(...) {
                manterTelaCriarEvento = true;
                mvwprintw(win_erro, 4, 0, "Erro na faixa");
                
            }

            try{
                nmrDeApresentacoes = std::stoi(respForm[5]);
                if(nmrDeApresentacoes > 10){
                    manterTelaCriarEvento = true;
                    mvwprintw(win_erro, 5, 0, "Erro no numero");  
                      
                } else {
                    mvwprintw(win_erro, 5, 0, "                    ");
                }
            }catch(...){
                manterTelaCriarEvento = true;
                mvwprintw(win_erro, 5, 0, "Erro no numero");
                
            }
            wrefresh(win_erro);
        }

    }

    wclear(janelaEvento);
    wrefresh(janelaEvento);
    delwin(janelaEvento);

    for(int i = 0;i < 6;i++) {
        wclear(forms[i]);
        wrefresh(forms[i]);
        delwin(forms[i]);
    }

    
    //Construindo o objeto evento
    Evento evento;
    evento.SetNomeDeEvento(nome);
    evento.SetCidade(cidade);
    evento.SetEstado(estado);
    evento.SetClasseDeEvento(classe);
    evento.SetFaixaEtaria(faixa);
    evento.dono.setConteudo(controller->getCpf());
    //vetor de apresentações
    std::vector<Apresentacao> vecApre(nmrDeApresentacoes);

    // janela onde sera criado as apresentações 
    auto janelaCriarApre = newwin(23, 40, y_max/2 - 10, x_max/2 - 20);
    box(janelaCriarApre, 0, 0);
    mvwprintw(janelaCriarApre, 0, janelaCriarApre->_maxx/2 - 10,"Criar Apresentacao ");
    //printando as labels
    std::string labels2[5] = {"Data", "Horario", "Preco", "Sala", "Disponibilidade"};
    for(int i = 0;i < 5;i++) {
        mvwprintw(janelaCriarApre, 5 + 3 * i, 20 - labels2[i].size() - 1, labels2[i].c_str());
    }

    //desenhando a tela
    wclear(win_erro);
    wrefresh(win_erro);
    wrefresh(janelaCriarApre);
    

    for(int i = 0; i < 5; i++) {
        forms[i] = newwin(3, 19, janelaCriarApre->_begy + 4 + 3 * i, janelaCriarApre->_begx + 20);
        box(forms[i], 0, 0);
        wrefresh(forms[i]);
    }

    //Variaveis para verificação
    Data data;
    Horario horario;
    Preco preco;
    NumeroDeSala nSala;
    Disponibilidade dispo;

    //loop para cração de apresentações
    bool manterCriaApres = true;
    Apresentacao apresen;
    for(int i = 0;i < nmrDeApresentacoes;i++) {
        //printando o numero da apresentação no top da tela
        mvwprintw(janelaCriarApre, 0, janelaCriarApre->_maxx/2 + 9,"%d", i + 1);
        wrefresh(janelaCriarApre);
        //loop de uma janela
        while(manterCriaApres) {
            //limpando forms
            for(int i = 0;i < 5;i++) {
                mvwprintw(forms[i],1,1,"                 ");
                wrefresh(forms[i]);
                wmove(forms[i],1,1);
            }

            //pegando info
            for(int i = 0;i < 5;i++) {
                wgetstr(forms[i],respForm[i]);
            }

            //verificando as infos
            {
                manterCriaApres = false;
                try{
                    data.setConteudo(respForm[0]);
                    mvwprintw(win_erro, 0, 0, "                       ");
                }catch(...){
                    manterCriaApres = true;
                    mvwprintw(win_erro, 0, 0, "Erro na data");
                }

                try{
                    horario.setConteudo(respForm[1]);
                    mvwprintw(win_erro, 1, 0, "                       ");
                }catch(...){
                    manterCriaApres = true;
                    mvwprintw(win_erro, 1, 0, "Erro no horario");
                }

                try{
                    preco.setConteudo(respForm[2]);
                    mvwprintw(win_erro, 2, 0, "                       ");
                }catch(...){
                    manterCriaApres = true;
                    mvwprintw(win_erro, 2, 0, "Erro no preco");
                }

                try{
                    nSala.setConteudo(respForm[3]);
                    mvwprintw(win_erro, 3, 0, "                       ");
                }catch(...){
                    manterCriaApres = true;
                    mvwprintw(win_erro, 3, 0, "Erro na Sala");
                }

                try{
                    dispo.setConteudo(respForm[4]);
                    mvwprintw(win_erro, 4, 0, "                       ");
                }catch(...){
                    manterCriaApres = true;
                    mvwprintw(win_erro, 4, 0, "Erro na disponibilidade");
                }
                wrefresh(win_erro);

            }
        }
        wclear(win_erro);
        wrefresh(win_erro);

        apresen.SetData(data);
        apresen.SetHorario(horario);
        apresen.SetPreco(preco);
        apresen.SetNumeroDeSala(nSala);
        apresen.SetDisponibilidade(dispo);

        manterCriaApres = true;
        vecApre[i] = apresen;
    }
    CPF cpf;
    cpf.setConteudo(controller->getCpf());
    servico->criarEvento(cpf, evento, vecApre);






    wclear(janelaCriarApre);
    wrefresh(janelaCriarApre);
    delwin(janelaCriarApre);


    for(int i = 0;i < 5;i++) {
        wclear(forms[i]);
        wrefresh(forms[i]);
        delwin(forms[i]);
    }

    wclear(win_erro);
    wrefresh(win_erro);
    delwin(win_erro);

    wrefresh(stdscr);
}

// ---------------Vendas---------------
void MAV::executar() {
    char CodApres[10];
    char qtd[10];

    std::string opcoes[2] = {"Menu", "Comprar"};
    std::string compra = "Compra";

    clear();
    refresh();

    int y_max, x_max, wy_max, wx_max;
    getmaxyx(stdscr, y_max, x_max);

    auto compraWin = newwin(14, 50, y_max/2 - 7, x_max/2 - 25);
    auto win_erro = newwin(5, 50, 0, x_max/2 - 20);
    box(compraWin, 0, 0);
    keypad(compraWin, true);
    getmaxyx(compraWin, wy_max, wx_max);
    mvwprintw(compraWin, 0, compraWin->_maxx / 2 - compra.size() / 2,
     compra.c_str());
    
    WINDOW* form[2];
    std::string labels[2] = {"Codigo da Apresentacao", "Quantidade"};

    for (int i = 0; i < 2; i++) {
        form[i] = newwin(3, 17, compraWin->_begy + 3 + i * 3,
         compraWin->_begx + compraWin->_maxx - 19);
        box(form[i], 0, 0); 
    }

    for (int i = 0; i < 2; i++) {
        mvwprintw(compraWin, form[i]->_begy - compraWin->_begy + 1,
         form[i]->_begx - compraWin->_begx - labels[i].size() - 1,
         labels[i].c_str());
    }

    for (int i = 0; i < 2; i++) {
        mvwprintw(compraWin,
         compraWin->_maxy - 1, 5 + i * (30 - opcoes[i].size()),
         opcoes[i].c_str());
    }
    wrefresh(compraWin);

    for (int i = 0; i < 2; i++) {
        wrefresh(form[i]);
    }

    int highlight = 0;
    int choice = 0;
    bool deuRuim = false;
    bool manterCompraWin = true;
    CodigoDeApresentacao codApres;
    Ingresso ingresso;
    Apresentacao apresentacao;
    CPF dono;

    while (true) {
        echo();
        curs_set(1);
        wmove(form[0], 1, 1);
        wgetstr(form[0], CodApres);
        wmove(form[1], 1, 1);
        wgetstr(form[1], qtd);
        noecho();
        curs_set(0);

        if (deuRuim) {
            manterCompraWin = true;
        }

        while (manterCompraWin) {
            for (int i = 0; i < 2; i++) {
                if (i == highlight) {
                    wattron(compraWin, A_REVERSE);
                }
                mvwprintw(compraWin,
                 compraWin->_maxy - 1, 5 + i * (30 - opcoes[i].size()),
                 opcoes[i].c_str());
                wattroff(compraWin, A_REVERSE);
            }
            choice = wgetch(compraWin);

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
                    case 0: // Menu
                        for (int i = 0; i < 2; i++) {
                        wclear(form[i]);
                        wrefresh(form[i]);
                        delwin(form[i]);
                        }
                        wclear(compraWin);
                        wrefresh(compraWin);
                        delwin(compraWin);

                        wclear(win_erro);
                        wrefresh(win_erro);
                        delwin(win_erro);

                        return;
                        break;
                    case 1: // Confirmar
                        apresentacao = servico->getApresbycodigo(CodApres);
                        if (apresentacao.GetData().getConteudo().empty()) {
                            mvwprintw(win_erro, 0, 0, "Apresentação não Encontrada");
                            deuRuim = true;
                            //break;
                        } else if (std::stoi(apresentacao.GetDisponibilidade().getConteudo()) == 0) {
                           mvwprintw(win_erro, 1, 0, "Sem ingressos disponíveis");
                            deuRuim = true;
                            //break; 
                        } else if (std::stoi(qtd) > std::stoi(apresentacao.GetDisponibilidade().getConteudo())) {
                            mvwprintw(win_erro, 2, 0, "Ingressos insuficientes na apresentação");
                            deuRuim = true;
                            //break; 
                        }
                        wrefresh(win_erro);
                        manterCompraWin = false;
                        if (deuRuim) {
                            for (int i = 0; i < 2; i++) {
                                mvwprintw(form[i], 1, 1, "          ");
                                wrefresh(form[i]);
                            }
                            break;
                        }

                        dono.setConteudo(controller->getCpf());
                        codApres.setConteudo(CodApres);
                        servico->compraIngresso(dono, codApres,std::stoi(qtd));                      
                        


                        break;
                    default:
                        break;
                }
            }
        }
        if (!deuRuim) {
            break;
        }
    }

    for (int i = 0; i < 2; i++) {
        wclear(form[i]);
        wrefresh(form[i]);
        delwin(form[i]);
    }
    wclear(compraWin);
    wrefresh(compraWin);
    delwin(compraWin);

    wclear(win_erro);
    wrefresh(win_erro);
    delwin(win_erro);

    return;
}


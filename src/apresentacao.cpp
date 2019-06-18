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
    

    //variaveis para guardar a info que entrar no form
    char dataI[20];
    char dataT[20];
    char cidade[20];
    char estado[20];

    //O que vai ter escrito nos botoes em baixo
    std::string opcoes[2] = {"Menu", "Buscar"};

    //limpando tela antes de começar
    clear();
    refresh();

    //pegando tamanhos da tela total
    int y_max, x_max;
    getmaxyx(stdscr, y_max, x_max);

    //aba para a seleção do evento desejado
    auto leftWin = newwin(y_max - 2, x_max / 2 - 2, 1, 1);
    box(leftWin, 0, 0);

    //aba que mostra as apresentações da do evento selecionado na aba esquerda
    auto rightWin = newwin(y_max - 2, x_max / 2 - 2, 1,  x_max / 2 + 2);
    box(rightWin, 0, 0);
    

    //Janela de busca
    auto searchWin = newwin(18, 40, y_max/2 - 9, x_max /2 - 20);
    box(searchWin, 0, 0);
    keypad(searchWin, true);

    // Nome da janela
    std::string eventos = "Eventos";
    mvwprintw(searchWin, 0, searchWin->_maxx / 2 - eventos.size() / 2, eventos.c_str());
    
    // espaçoes para os form
    WINDOW* form[4];
    std::string labels[4] = {"Data de Inicio", "Data de Termino", "Cidade", "Estado"};
    
    // caixas dos forms
    for(int i = 0;i < 4;i++) {
        form[i] = newwin(3, 17,searchWin->_begy + 3 + i * 3, searchWin->_begx + searchWin->_maxx - 19);
        box(form[i], 0, 0);
        //wrefresh(form[i]);
    }
    //labels dos forms
    for(int i = 0;i < 4;i++) {
        mvwprintw(searchWin, form[i]->_begy - searchWin->_begy + 1, form[i]->_begx - searchWin->_begx - labels[i].size() - 1, labels[i].c_str());
    }
    // botoes em baixo
    for (int i = 0; i < 2; i++) {
        mvwprintw(searchWin, searchWin->_maxy - 1, 5 + i * (30 - opcoes[i].size()) , opcoes[i].c_str());
    }
    wrefresh(searchWin);
    //Refresh nas box's dos form's
    for(int i = 0; i < 4;i++){
        wrefresh(form[i]);
    }
    
    // Janela para o log de erro
    auto win_erro = newwin(5, 40, 0, x_max/2 - 20);
    
    

    //loop do form
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
        //Get dos forms
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
        
        
        if(deuRuim) {
            manterBuscaWin = true;
        }
        //seleção entre o  botao menu e buscar
        while(manterBuscaWin) {
            //printando opções
            for (int i = 0; i < 2; i++) {
                if (i == highlight) {
                    wattron(searchWin, A_REVERSE);
                }

                mvwprintw(searchWin, searchWin->_maxy - 1, 5 + i * (30 - opcoes[i].size()) , opcoes[i].c_str());
                wattroff(searchWin, A_REVERSE);
            }
            choice = wgetch(searchWin);
            //seleção do opção
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
                    case 0: // Menu
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
                    case 1: // Buscar
                        deuRuim = false;
                        
                        //verificação dos formatos
                        try{
                            dateI.setConteudo(dataI);
                            mvwprintw(win_erro, 0, 0, "                                 ");
                        } catch(...) {
                            mvwprintw(win_erro, 0, 0, "Erro no formato da data de inicio");
                            deuRuim = true;
                        }

                        try{
                            dateT.setConteudo(dataT);
                            mvwprintw(win_erro, 1, 0, "                                  ");
                        } catch(...) {
                            mvwprintw(win_erro, 1, 0, "Erro no formato da data de termino");
                            deuRuim = true;
                        }
                        
                        try{
                            cid.setConteudo(cidade);
                            mvwprintw(win_erro, 2, 0, "                         ");
                        } catch(...) {
                            mvwprintw(win_erro, 2, 0, "Erro no formato da cidade");
                            deuRuim = true;
                        }

                        try{
                            est.setConteudo(estado);
                            mvwprintw(win_erro, 3, 0, "                         ");
                        } catch(...) {
                            mvwprintw(win_erro, 3, 0, "Erro no formato do estado");
                            deuRuim = true;
                        }
                        
                        wrefresh(win_erro);
                        manterBuscaWin = false;
                        if(deuRuim) { //saindo caso tenha dado erro
                            break;
                        }
                        //aquisição do vetor de eventos
                        vetor = servico->buscar(dateI, dateT, cid, est);
                        clear();
                        refresh();

                        //desenhando tela para mostrar eventos e apresentaçoes
                        mvwprintw(leftWin, 0, leftWin->_maxx/2 - 4, "Eventos");
                        mvwprintw(leftWin, 1, 1, "Precione 'q' para voltar ao menu inicial");
                        mvwprintw(rightWin, 0, rightWin->_maxx/2 - 7, "Apresentacoes");
                        wrefresh(leftWin);
                        wrefresh(rightWin);
                        
                        highlight = 0;
                        int a;
                        
                        //escolha de evento
                        while(true) {
                            std::vector<Apresentacao> vetorA;
                            //printando a lista de todos os eventos
                            for (int i = 0; i < vetor.size(); i++) {
                                if (i == highlight) {
                                    wattron(leftWin, A_REVERSE);
                                }

                                mvwprintw(leftWin, 2 + i, 3 , vetor[i].GetNomeDeEvento().getConteudo().c_str()); //Fazer metodo ja retorna formatado 
                                wattroff(searchWin, A_REVERSE);
                            }
                            //adiquirindo vetor de apresentação
                            vetor[highlight];//vetorA=buscaApre(vetor[highlight]) //fazer funcao ou metodo que retona todas as apresentações de um evento passado como parametro
                            //printando as apresentaçoes na janela direita
                            for(int i = 0; i < vetorA.size();i++) {
                                mvwprintw(rightWin, 2 + i, 3 , vetorA[i].GetCodigoDeApresentacao().getConteudo().c_str()); // fazer metodo que retorna o q ira aparecer em cada apresentação
                            }

                            a = getch();
                            //selecionando evento ou saindo
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


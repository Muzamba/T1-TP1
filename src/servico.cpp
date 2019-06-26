// Copyright
#include <vector>
#include <unordered_map>
#include "./modulos.h"

std::unordered_map<std::string, Usuario> userTable;
std::unordered_map<std::string, Evento> eventTable;
std::unordered_map<std::string, Apresentacao> apreTable;
std::unordered_map<std::string, Ingresso> ticketTable;


// ---------------Apresentação---------------
bool MSA::autenticar(const CPF& cpf, const Senha& senha) {
    auto aux = userTable.find(cpf.getConteudo());

    if (aux == userTable.end()) {
        return false;  // nao existe esse cpf cadastrado
    }
    if (aux->second.GetSenha().getConteudo() == senha.getConteudo()) {
        return true;  // senha correta
    }
    return false;  // senha incorreta
}

// ---------------Usuario---------------
bool MSU::cadastrar(const Usuario& usuario, const CartaoDeCredito& cartao) {
    auto user = usuario;
    user.cartao = cartao;
    // Se a tabela for vazia só adiciona
    auto aux = userTable.find(user.GetCPF().getConteudo());
    if (aux == userTable.end()) {
        userTable[user.GetCPF().getConteudo()] = user;
        return true;
    } else {
        // Checa se tem outro com o mesmo cpf
        return false;
    }
}

bool MSU::descadastrar(const CPF& cpf) {
    if(userTable[cpf.getConteudo()].vecEventos.size() == 0) {
        userTable.erase(cpf.getConteudo());
        return true;
    } else {
        return false;
    }
}

Usuario MSU::infoLoggedUser(const char* cpf) {
    Usuario tmp;
    auto aux = userTable.find(cpf);

    return tmp = aux->second;
}

// ---------------Evento---------------
std::vector<Evento> MSE::buscar(Data inicio, Data fim,
 Cidade cidade, Estado estado) {
    std::vector<Evento> aux1,aux2;
    for(auto event : eventTable){
        aux1.push_back(event.second);
    }

    for(auto event : aux1) {
        if(event.GetEstado().getConteudo() == estado.getConteudo()) {
            aux2.push_back(event);
        } 
    }
    aux1.clear();
    for(auto event : aux2) {
        if(event.GetCidade().getConteudo() == cidade.getConteudo()) {
           aux1.push_back(event);
        }
    }
    aux2.clear();

    for(auto event : aux1) {
        for(auto apres : event.vecApres) {
            if(dateToInt(apres.GetData().getConteudo()) <= dateToInt(fim.getConteudo())) {
                aux2.push_back(event);
                break;
            }
        }
    }
    aux1.clear();

    for(auto event : aux2) {
        for(auto apres : event.vecApres) {
            if(dateToInt(apres.GetData().getConteudo()) >= dateToInt(inicio.getConteudo())) {
                aux1.push_back(event);
                break;
            }
        }
    }


    return aux1;
}

bool MSE::criarEvento(const CPF& cpf, const Evento& evento,
 const std::vector<Apresentacao>& vectorApresenta) {
    auto event = evento;
    auto aux_usr = userTable.find(cpf.getConteudo());
    Usuario &tmp = aux_usr->second;
    event.vecApres = vectorApresenta;
    static std::string codEvento = "000";
    CodigoDeEvento codEvent;
    codEvent.setConteudo(codEvento);
    
    event.SetCodigoDeEvento(codEvent);
    // setando aque evnto pertence
    for(int i = 0;i < event.vecApres.size();i++) {
        event.vecApres[i].evento.setConteudo(codEvento);
    }

    int aux;
    static std::string codApres = "0000";
    CodigoDeApresentacao codApre;
    codApre.setConteudo(codApres);

    //colando os codigos nas apresentações
    for(auto& a : event.vecApres) {
        a.SetCodigoDeApresentacao(codApre);
        apreTable[codApres] = a;

        aux = std::stoi(codApres);
        aux++;
        codApres = std::to_string(aux);
        if(codApres.size() < 4) {
            if(codApres.size() < 3) {
                if(codApres.size() < 2) {
                    codApres.insert(0, "0");
                }
                codApres.insert(0, "0");
            }
            codApres.insert(0, "0");
        }
        codApre.setConteudo(codApres);
    }
    eventTable[codEvento] = event;
    

    aux = std::stoi(codEvento);
    aux++;
    codEvento = std::to_string(aux);
    if(codEvento.size() < 3) {
        if(codEvento.size() < 2) {
            codEvento.insert(0,"0");
        }
        codEvento.insert(0,"0");
    }
    tmp.vecEventos.push_back(event);
    return true;
}

bool MSE::alteraEvento(const Evento& evento)  {
    return false;
}

bool MSE::descadastrarEvento(const CodigoDeEvento& codigo) {
    return false;
}

int MSE::dateToInt(std::string date) {
    auto diaS = date.substr(0,2);
    auto mesS = date.substr(3,2);
    auto anoS = date.substr(6,2);

    int dia = std::stoi(diaS);
    int mes = std::stoi(mesS);
    int ano = std::stoi(anoS);

    return dia + 100 * mes + 10000 * ano;
}

std::string MSE::infoApresentacao(Apresentacao apre) {
    std::string codigo = apre.GetCodigoDeApresentacao().getConteudo();
    std::string data = apre.GetData().getConteudo();
    std::string disp = apre.GetDisponibilidade().getConteudo();
    std::string hora = apre.GetHorario().getConteudo();
    std::string numSala = apre.GetNumeroDeSala().getConteudo();
    std::string preco = apre.GetPreco().getConteudo();
    std::string info;

    info += "Codigo do Evento: " + codigo + "\n";
    info += "Data: " + data + "\n";
    info += "Disponibilidade: " + disp + "\n";
    info += "Horário: " + hora + "\n";
    info += "Sala: " + numSala + "\n";
    info += "Preco: " + preco + "\n";
    info += "------------------------------------\n";

    return info;
}

// ---------------Vendas---------------
bool MSV::compraIngresso(const CPF& cpf, const CodigoDeApresentacao& codigo, const int qtd) {

    auto aux_apre = apreTable.find(codigo.getConteudo());
    auto aux_usr = userTable.find(cpf.getConteudo());
    Usuario usuario = aux_usr->second;
    Apresentacao& apresentacao = aux_apre->second;
    int disp = std::stoi(apresentacao.GetDisponibilidade().getConteudo());
    int aux;
    Ingresso ingresso;
    Disponibilidade new_disp;

    static std::string Icodigo = "00000";
    CodigoDeIngresso ICodigo;
    ICodigo.setConteudo(Icodigo);

    ingresso.dono = cpf;
    ingresso.apresentacao = codigo;

    disp -= qtd;
    mvwprintw(stdscr, 1, 1, "%d", disp);
    wrefresh(stdscr);
    new_disp.setConteudo(std::to_string(disp));
    apresentacao.SetDisponibilidade(new_disp);
    mvwprintw(stdscr, 2, 1, "%s", apresentacao.GetDisponibilidade().getConteudo().c_str());
    wrefresh(stdscr);

    for (auto i : apresentacao.vecIngre) {
        i.SetCodigoDeIngresso(ICodigo);
        ticketTable[Icodigo] = i;

        aux = std::stoi(Icodigo);
        aux++;
        Icodigo = std::to_string(aux);
        if (Icodigo.size() < 5) {
            if(Icodigo.size() < 4) {
                if(Icodigo.size() < 3) {
                    if(Icodigo.size() < 2) {
                        Icodigo.insert(0, "0");
                    }
                    Icodigo.insert(0, "0");
                }
                Icodigo.insert(0, "0");
            }
        }
        ICodigo.setConteudo(Icodigo);
    }

    ingresso.SetCodigoDeIngresso(ICodigo);
    apresentacao.vecIngre.push_back(ingresso);
    apreTable[codigo.getConteudo()] = apresentacao;

    for (auto e : usuario.vecEventos) {
        for (auto a: e.vecApres) {
            if (a.GetCodigoDeApresentacao().getConteudo() == codigo.getConteudo()) {
                a.SetDisponibilidade(new_disp);
            }
        }
    }
    userTable[cpf.getConteudo()] = usuario;

    auto aux_eve = eventTable.find(apresentacao.evento.getConteudo());
    Evento event = aux_eve->second;
    
    for (int i = 0; i < event.vecApres.size(); i++) {
        if (event.vecApres[i].GetCodigoDeApresentacao().getConteudo() == codigo.getConteudo()) {
            event.vecApres[i] = apresentacao;
        }
    }
    eventTable[event.GetCodigoDeEvento().getConteudo()] = event;
    return true;
}

Apresentacao MSV::getApresbycodigo(const char* codigo) {
    auto aux = apreTable.find(codigo);
    Apresentacao vazio;
    if (aux == apreTable.end()) {
        return vazio;
    } else {
        return aux->second;
    }
}
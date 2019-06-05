#ifndef CONTAINER_H
#define CONTAINER_H

#include "entidades.h"
#include "builder.h"
#include <unordered_map>

class DataBase {
friend class Builder;
public:

private:
    Usuarios* usuarios; 
    CartoesDeCredito* cartoes;
    Eventos* eventos;
    Apresentacoes* apresentacoes;
    Ingressos* Ingressos;
};


class Usuarios {
public:
    Usuario Get(CPF);
    bool Add(Usuario);
    bool Remove(CPF);

private:
    std::unordered_map<std::string, Usuario> userTable;
};

class CartoesDeCredito {
public:
    CartaoDeCredito Get(NumCartaoCredito);
    bool Add(CartaoDeCredito);
    bool Remove(NumCartaoCredito);

private:
    std::unordered_map<std::string, CartaoDeCredito> cardTable;
};

class Eventos {
public:
    Evento Get(CodigoDeEvento);
    bool Add(Evento);
    bool Remove(CodigoDeEvento);

private:
    std::unordered_map<std::string, Evento> eventTable;
};

class Apresentacoes {
public:
    Apresentacao Get(CodigoDeApresentacao);
    bool Add(Apresentacao);
    bool Remove(CodigoDeApresentacao);

private:
    std::unordered_map<std::string, Apresentacao> showTable;
};

class Ingressos {
public:
    Ingresso Get(CodigoDeIngresso);
    bool Add(Ingresso);
    bool Remove(CodigoDeIngresso);

private:
    std::unordered_map<std::string, Ingresso> ticketTable;
};


#endif // CONTAINER_H

#ifndef INCLUDE_CONTAINER_H_
#define INCLUDE_CONTAINER_H_
class DataBase;
class Usuarios;
class CartoesDeCredito;
class Eventos;
class Apresentacoes;
class Ingressos;


#include "entidades.h"
#include "builder.h"
#include <unordered_map>




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

class DataBase {
friend class Builder;
public:

private:
    Usuarios* usuarios; 
    CartoesDeCredito* cartoes;
    Eventos* eventos;
    Apresentacoes* apresentacoes;
    Ingressos* ingressos;
};

#endif // CONTAINER_H

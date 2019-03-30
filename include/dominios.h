#ifndef DOMINIOS_H
#define DOMINIOS_H
#include <string>

class CodigoDeEvento {
private:
    std::string codigo;
    bool validar();

public:
    CodigoDeEvento();
    CodigoDeEvento(int codigo);
    void setCodigo(std::string codigo);    
    inline std::string getCodigo();
};

class CodigoDeApresentacao {

};

class CodigoDeIngresso {

};

class NomeDeEvento {

};

class Data {

};

class Horario {

};

class Preco {

};

class NumeroDeSala {

};

class Cidade {

};

class Estado {

};

class Disponibilidade {

};

class FaixaEtaria {

};

class CPF {

};

class Senha {

};

class NumeroDeCartaoDeCredito {

};

class CodigoDeSeguranca {

};

class DataDeValidade {

};


#endif
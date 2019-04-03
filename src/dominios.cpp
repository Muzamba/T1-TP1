// Copyright Ariel e João Pedro
#include <iostream>
#include "../include/dominios.h"

/**************** Classe Super ****************/
void Super::setConteudo(std::string conteudo) {
    validar(conteudo);
    this->conteudo = conteudo;
}
/**************** Classe CodigoDeEvento ****************/
void CodigoDeEvento::validar(std::string codigo) {
    bool valid = true;
    for (auto &c : codigo) {
        if ((c - '0') < 0) {
            valid = false;
        }
    }
    if (codigo.size() != 3) {
        throw std::invalid_argument("Código de Evento deve ter 3 caracteres");
    } else if (valid == false) {
        throw std::invalid_argument("Código de Evento possui dígitos negativos");
    }
}

/**************** Classe CodigoDeApresentacao ****************/

/**************** Classe CodigoDeIngresso ****************/

/**************** Classe NomeDeEvento ****************/

/**************** Classe Data ****************/

/**************** Classe Horario ****************/

/**************** Classe Preco ****************/

/**************** Classe NumeroDeSala ****************/

/**************** Classe Cidade ****************/

/**************** Classe Estado ****************/

/**************** Classe Disponibilidade ****************/

/**************** Classe ClasseDeEvento ****************/

/**************** Classe FaixaEtaria ****************/

/**************** Classe CPF ****************/

void CPF::validar(std::string cpf) {
    int digito1, digito2;
    int soma = 0;

    for (int i = 0; i < 9; i++) {
        soma += (cpf[i] - '0') * (10 - i);
    }
    soma %= 11;

    if (soma < 2)  {
        digito1 = 0;
    } else {
        digito1 = 11 - soma;
    }

    soma = 0;

    for (int i = 0; i < 10; i++) {
        soma += (cpf[i] - '0') * (11 - i);
    }
    soma %= 11;

    if (soma < 2)  {
        digito2 = 0;
    } else {
        digito2 = 11 - soma;
    }

    if (digito1 != (cpf[9] - '0') || digito2 != (cpf[10]) - '0') {
        throw std::invalid_argument("CPF invalido");
    }
}

/**************** Classe Senha ****************/

/**************** Classe NumCartaoCredito ****************/

/**************** Classe CVV ****************/

/**************** Classe DataDeValidade ****************/

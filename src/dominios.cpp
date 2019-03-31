// Copyright Ariel e João Pedro
#include <iostream>
#include "../include/dominios.h"

/**************** Classe CodigoDeEvento ****************/

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

CPF::CPF(std::string cpf) {
    this->cpf.assign(cpf);
}

void CPF::setCPF(std::string cpf) {
    try {
        CPF Cpf(cpf);
        if (Cpf.validar() == false) {
            throw "CPF invalido";
        } else {
            this->cpf.assign(cpf);
        }
    } catch (const char* error) {
        std::cout << "ERRO! Causado por: " << error << std::endl;
    }
}

bool CPF::validar() {
    int digito1, digito2;
    int soma = 0;

    for (int i = 0; i < 9; i++) {
        soma += (this->cpf[i] - '0') * (10 - i);
    }
    soma %= 11;

    if (soma < 2)  {
        digito1 = 0;
    } else {
        digito1 = 11 - soma;
    }

    soma = 0;

    for (int i = 0; i < 10; i++) {
        soma += (this->cpf[i] - '0') * (10 - i);
    }
    soma %= 11;

    if (soma < 2)  {
        digito1 = 0;
    } else {
        digito1 = 11 - soma;
    }

    if (digito1 == cpf[9] && digito2 == cpf[10]) {
        return true;
    } else {
        return false;
    }
}

/**************** Classe Senha ****************/

/**************** Classe NumCartaoCredito ****************/

/**************** Classe CVV ****************/

/**************** Classe DataDeValidade ****************/

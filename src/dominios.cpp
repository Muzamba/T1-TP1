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
    for (char &c : codigo) {
        if (!isdigit(c)) {
            valid = false;
            break;
        }
    }
    if (codigo.size() != 3 && valid == false) {
        throw std::invalid_argument(
        "Código de Evento deve ter apenas 3 caracteres não negativos");
    } else if (valid == false) {  // Condição nunca será alcançada, pois str
        throw std::invalid_argument(  // negativa possui tamanho max_size + 1
        "Código de Evento não deve possuir dígitos negativos");
    } else if (codigo.size() != 3) {
        throw  std::invalid_argument(
        "Código de Evento deve ter apenas 3 caracteres");
    }
}

/**************** Classe CodigoDeApresentacao ****************/
void CodigoDeApresentacao::validar(std::string codigo) {
    bool valid = true;
    for (char &c : codigo) {
        if (!isdigit(c)) {
            valid = false;
            break;
        }
    }
    if (codigo.size() != 4 && valid == false) {
        throw std::invalid_argument(
        "Código de Apresentação deve ter apenas 3 caracteres não negativos");
    } else if (valid == false) {  // Condição nunca será alcançada, pois str
        throw std::invalid_argument(  // negativa possui tamanho max_size + 1
        "Código de Apresentação não deve possuir dígitos negativos");
    } else if (codigo.size() != 4) {
        throw  std::invalid_argument(
        "Código de Apresentação deve ter apenas 4 caracteres");
    }
}

/**************** Classe CodigoDeIngresso ****************/
void CodigoDeIngresso::validar(std::string codigo) {
    bool valid = true;
    for (char &c : codigo) {
        if (!isdigit(c)) {
            valid = false;
            break;
        }
    }
    if (codigo.size() != 5 && valid == false) {
        throw std::invalid_argument(
        "Código de Ingresso deve ter apenas 5 caracteres não negativos");
    } else if (valid == false) {  // Condição nunca será alcançada, pois str
        throw std::invalid_argument(  // negativa possui tamanho max_size + 1
        "Código de Ingresso não deve possuir dígitos negativos");
    } else if (codigo.size() != 5) {
        throw  std::invalid_argument(
        "Código de Ingresso deve ter apenas 5 caracteres");
    }
}

/**************** Classe NomeDeEvento ****************/

void NomeDeEvento::validar(std::string nome) {
    bool check = false;
    unsigned char cont = 0;
    for(char &c : nome) {
        if (isalnum(c)) {  
            cont = 0;
            check = true;
        } else if(isspace) {
            cont++;
            if (cont == 2) {
                throw std::invalid_argument("Nome de Evento não pode ter dois espaços seguidos");
            }
        } else {
            throw std::invalid_argument("Somente caracteres alphanumericos");
        }
    }
    if (!check) {
        throw std::invalid_argument("Deve Conter pelo menos um caracter alphanumerico");
    }
}

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
    if (cpf.size() != 11) {
        throw std::invalid_argument(
        "CPF possui um número diferente de caracteres do que o permitido");
    } else {
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
            throw std::invalid_argument("Dígito verificador do CPF inválido");
        }
    }
}

/**************** Classe Senha ****************/

/**************** Classe NumCartaoCredito ****************/

/**************** Classe CVV ****************/

/**************** Classe DataDeValidade ****************/

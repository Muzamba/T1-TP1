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
    if (nome.size() > 20) {
        throw std::invalid_argument(
        "Nome de Evento deve ter no máximo 20 caracteres");
    } else {
        for (char &c : nome) {
            if (isalpha(c)) {
                cont = 0;
                check = true;
            } else if (isdigit(c)) {
                cont = 0;
            } else if (isspace(c)) {
                cont++;
                if (cont == 2) {
                    throw std::invalid_argument(
                        "Nome de Evento não pode ter dois espaços seguidos");
                }
            } else {
                throw std::invalid_argument("Somente caracteres alfanumericos");
            }
        }
        if (!check) {
            throw std::invalid_argument(
                "Deve Conter pelo menos um caractere alfanumerico");
        }
    }
}

/**************** Classe Data ****************/
void Data::validar(std::string data) {
    if (data.size() != 8) {
        throw std::invalid_argument("A data deve seguir o formato DD/MM/AA");
    } else {
        int dia, mes, ano;
        int duracaoMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        dia = std::stoi(data.substr(0, 2));
        mes = std::stoi(data.substr(3, 2));
        ano = std::stoi(data.substr(6, 2));

        if ((dia > 31 || dia < 1) || (mes > 12 || mes < 1)) {
            throw std::invalid_argument("Data invalida");
        }
        if (!(ano%4) && mes == 2) {
            duracaoMes[1]++;
        }
        if (dia > duracaoMes[mes-1]) {
            throw std::invalid_argument(
                "Número de dias maior do que o permitido");
        }
    }
}

/**************** Classe Horario ****************/
void Horario::validar(std::string horario) {
    if (horario.size() != 5) {
        throw std::invalid_argument(
            "O horário deve seguir o formato HH:MM");
    } else {
        int hora, minuto;
        hora = std::stoi(horario.substr(0, 2));
        minuto = std::stoi(horario.substr(3, 2));

        if (hora < 7 || hora > 22) {
            throw std::invalid_argument(
                "A hora deve estar no intervalo [7,22]");
        } else if (minuto != 0 || minuto != 15 ||
                 minuto != 30 || minuto != 45) {
                     throw std::invalid_argument(
                 "O minuto só pode estar contido no conjunto {0, 15, 30, 45}");
        }
    }
}

/**************** Classe Preco ****************/
void Preco::validar(std::string preco) {
    double price;
    price = std::atof(preco.c_str());
    if (price < 0.0  || price > 1000.00) {
        throw std::invalid_argument(
            "O preço deve estar no intervalo [0.00, 1000.00");
    }
}

/**************** Classe NumeroDeSala ****************/
void NumeroDeSala::validar(std::string numSala) {
    int numero;
    numero = std::stoi(numSala);
    if (1 > numero || numero > 10) {
        throw std::invalid_argument(
            "Número deve pertencer ao intervalo [1, 10]");
    }
}

/**************** Classe Cidade ****************/


/**************** Classe Estado ****************/

/**************** Classe Disponibilidade ****************/
void Disponibilidade::validar(std::string disp) {
    int numero;
    numero = std::stoi(disp);
    if (0 > numero || numero > 250) {
        throw std::invalid_argument(
            "Número deve pertencer ao intervalo [0, 250]");
    }
}

/**************** Classe ClasseDeEvento ****************/

/**************** Classe FaixaEtaria ****************/
void FaixaEtaria::validar(std::string fxEtaria) {
    if (!fxEtaria.compare("L") || !fxEtaria.compare("10")
    || !fxEtaria.compare("12") || !fxEtaria.compare("14")
    || !fxEtaria.compare("16") || !fxEtaria.compare("18")) {
    } else {
        throw std::invalid_argument(
            "Faixa etária só pode ser L, 10, 12, 14, 16 e 18");
    }
}

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
void NumCartaoCredito::validar(std::string) {
    
}

/**************** Classe CVV ****************/
void CVV::validar(std::string cvv) {
    bool valid = true;
    for (char &c : cvv) {
        if (!isdigit(c)) {
            valid = false;
            break;
        }
    }
    if (cvv.size() != 3 && valid == false) {
        throw std::invalid_argument(
        "CVV deve ter apenas 3 caracteres não negativos");
    } else if (valid == false) {  // Condição nunca será alcançada, pois str
        throw std::invalid_argument(  // negativa possui tamanho max_size + 1
        "CVV não deve possuir dígitos negativos");
    } else if (cvv.size() != 3) {
        throw  std::invalid_argument(
        "CVV deve ter apenas 3 caracteres");
    }
}

/**************** Classe DataDeValidade ****************/
void DataDeValidade::validar(std::string data) {
    if (data.size() != 5) {
        throw std::invalid_argument("A data deve seguir o formato MM/AA");
    } else {
        int mes, ano;
        mes = std::stoi(data.substr(0, 2));
        ano = std::stoi(data.substr(3, 2));

        if ((mes > 12 || mes < 1) || (ano < 0 || ano > 99)) {
            throw std::invalid_argument("Data invalida");
        }
    }
}

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
        } else if ((minuto % 15) != 0) {
                     throw std::invalid_argument(
                 "O minuto só pode estar contido no conjunto {0, 15, 30, 45}");
        } else if (minuto > 60) {
            throw std::invalid_argument("O minuto não pode ser maior que 60");
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

void Cidade::validar(std::string cidade) {
    int cont = 0;
    bool check = false;
    char temp = '#';
    if (cidade.size() > 15) {
        throw std::invalid_argument(
        "Nome de Cidade deve ter no máximo 15 caracteres");
    } else {
        for (char &c : cidade) {
            if (isalpha(c)) {
                cont = 0;
                check = true;
            } else if (isspace(c)) {
                cont++;
                if (cont == 2) {
                    throw std::invalid_argument(
                        "Nome de Evento não pode ter dois espaços seguidos");
                }
            } else if (c == '.') {
                cont = 0;
                if (!isalpha(temp)) {
                    throw std::invalid_argument(
                        "Ponto não é precedido por letra.");
                }
            } else {
                throw std::invalid_argument(
                    "Somente caracteres alfabéticos e ponto");
            }
            temp = c;
        }
    }
}



/**************** Classe Estado ****************/
void Estado::validar(std::string est) {
    if (est.size() != 2) {
        throw std::invalid_argument("Tamanho inválido");
    } else if (!est.compare("AC") || !est.compare("AL") || !est.compare("AP") ||
               !est.compare("AM") || !est.compare("BA") || !est.compare("CE") ||
               !est.compare("DF") || !est.compare("ES") || !est.compare("GO") ||
               !est.compare("MA") || !est.compare("MT") || !est.compare("MG") ||
               !est.compare("PA") || !est.compare("PB") || !est.compare("PR") ||
               !est.compare("PE") || !est.compare("PI") || !est.compare("RJ") ||
               !est.compare("RN") || !est.compare("RS") || !est.compare("RO") ||
               !est.compare("RR") || !est.compare("SC") || !est.compare("SP") ||
               !est.compare("SP") || !est.compare("SE") || !est.compare("TO")) {
            } else {
                throw std::invalid_argument("Estado Inválido");
            }
}

/**************** Classe Disponibilidade ****************/
void Disponibilidade::validar(std::string disp) {
    int numero;
    numero = std::stoi(disp);
    if (0 > numero || numero > 250) {
        throw std::invalid_argument(
            "Número deve pertencer ao intervalo [0, 250]");
    }
}

/**************** Classe ClasseDeEvento ****************///----------------------------------------

void ClasseDeEvento::validar(std::string classe) {

    if (classe.size() != 1){
        throw std::invalid_argument("Deve possuir tamanho 1");
    }

    if (!isdigit(classe[0])) {
        throw std::invalid_argument("Somente numeros");
    }
    int temp = stoi(classe);

    if (temp > 4 || temp < 1) {
        throw std::invalid_argument("O numero deve estar no intervalo [1,4]");
    }
}

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

void Senha::validar(std::string senha) {
    bool validarMai = false;
    bool validarMin = false;
    bool validarDig = false;

    if (senha.size() != 6) {
        throw std::invalid_argument("Tamanho da senha invalido");
    }
    for (auto& c : senha) {
        if (!isalnum(c)) {
            throw std::invalid_argument("Somente caracteres alfanumericos");
        } else {
            if (isupper(c)) {
                validarMai = true;
            } else if (islower(c)) {
                validarMin = true;
            } else if (isdigit(c)) {
                validarDig = true;
            }
        }
        for (auto& d : senha) {
            bool itself = false;
            if (c == d) {
                if (itself) {
                    throw std::invalid_argument(
                        "Nao pode ter caracteres repetidos");
                } else {
                    itself = true;
                }
            }
        }
    }
    if (!validarMai) {
        throw std::invalid_argument("Sem letra maiuscula");
    } else if (!validarMin) {
        throw std::invalid_argument("Sem letra minuscula");
    } else if (!validarDig) {
        throw std::invalid_argument("Sem digito");
    }
}

/**************** Classe NumCartaoCredito ****************/
void NumCartaoCredito::validar(std::string numero) {
    if (numero.size() != 16) {
        throw std::invalid_argument("Tamanho invalido");
    }
    for(auto c : numero) {
        if(!isdigit(c)) {
            throw std::invalid_argument("Somente numeros");
        }
    }

    int nSum       = 0;
    int nDigits    = numero.size();
    int nParity    = (nDigits-1) % 2;
    char cDigit[2] = "\0";
    for (int i = nDigits; i > 0 ; i--) {
      cDigit[0]  = numero[i-1];
      int nDigit = atoi(cDigit);

      if (nParity == i % 2)
        nDigit = nDigit * 2;

      nSum += nDigit/10;
      nSum += nDigit%10;
    }
    if (!(0 == nSum % 10)) {
        throw std::invalid_argument("Numero Invalido");

    };

    /*
    if (numero.size() != 16) {
        printf("aaaaaaaaaaa\n");
        throw std::invalid_argument("Tamanho invalido");
    }
    for(auto c : numero) {
        if(!isdigit(c)) {
            printf("bbbbbbbbbbbb\n");
            throw std::invalid_argument("Somente numeros");
        }
    }
    int temp;
    int somatorio = 0;
    bool check = true;
    for(auto c = numero.begin();c != numero.end();c++) {
        if (check) {
            if((*c) == numero[15]) {
                break;
            }
            temp = (*c) - '0';

            somatorio += temp;

            check = false;
        } else {
            if(*c == numero[15]) {
                break;
            }
            temp = (*c) - '0';
            temp *= temp;
            if(temp > 9) {
                temp = temp - 9;
            }
            somatorio += temp;
            check = true;
        }
    }
    char c = numero[15];
    int n = c - '0';

    int comparador = (somatorio * 9) % 10;

    if(comparador != n) {
        printf("cccccccccccc\n");
        throw std::invalid_argument("Numero invalido");
    }
    */
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

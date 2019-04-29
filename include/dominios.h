// Copyright Ariel e João Pedro
/**
 * @file dominios.h
 * @author Ariel e João Pedro
 * @brief Biblioteca simples de dominios    
 * @version 0.1
 * @date 2019-04-29
 * 
 * @copyright Copyright (Ariel e João Pedro) 2019
 * 
 */

#ifndef INCLUDE_DOMINIOS_H_
#define INCLUDE_DOMINIOS_H_
#include <string>
#include <stdexcept>
#include <cctype>


/**
 * @class Super
 * 
 * @brief Classe abstrata o qual todos os dominios herdam.
 */
class Super {
 protected:
    std::string conteudo; /** tipo padrão para todas as classes filhas */
    virtual void validar(std::string) = 0;
 public:
 /**
  * @brief Set basico para as classe filhas
  * 
  * @param conteudo string a ser inserida dentro do objeto.
  * 
  * @throw std::invalid_argument Caso a validação de errado (Cada classe possui
  *  a sua) lança um objeto explicando o erro.
  */
    void setConteudo(std::string conteudo);

    /**
     * @brief Get padrão.
     * 
     * @return std::string Retorna o que esta contido no objeto.
     */
    std::string getConteudo() {
        return conteudo;
    }
};

/**
 * @class CodigoDeEvento
 * 
 * @brief Codigo destinado a indentificar um Evento.
 * 
 * @details A validação desse codigo apenas valida o tamanho de 3 digitos e se
 * são numero positivos.
 * 
 */
class CodigoDeEvento : public Super {
 private:
    void validar(std::string) override;
};

/**
 * @class CodigoDeApresentacao
 * 
 * @brief Codigo destinado a indentificar uma Apresentacao.
 * 
 * @details A validação desse codigo apenas valida o tamanho de 4 digitos e se
 * são numero positivos.
 */
class CodigoDeApresentacao : public Super {
 private:
    void validar(std::string) override;
};

/**
 * @class CodigoDeIngresso 
 * 
 * @brief Codigo destinado a indentificar Ingressos distintos.
 * 
 * @details A validação desse codigo apenas valida o tamanho de 5 digitos e se
 * são numero positivos.
 */
class CodigoDeIngresso : public Super {
 private:
    void validar(std::string) override;
};

/**
 * @class NomeDeEvento
 * 
 * @brief Nomeia um Evento.
 * 
 * @details A validação desse nome apenas valida o tamanho de até 20 caracteres e se
 * possui ao menos uma letra.(Espaços seguidos tambem não são válidos)
 * 
 */
class NomeDeEvento : public Super {
 private:
    void validar(std::string) override;
};

/**
 * @class Data
 * 
 * @brief Armazena a data de um Evento ou Apresentacao
 * 
 * @details A validação verifica se a data inserida é válida, checando o número de dias
 * de cada mês e considerando anos bissextos
 * 
 */
class Data : public Super {
 private:
    void validar(std::string) override;
};

/**
 * @class Horario
 * 
 * @brief Armazena o horário de um Evento ou Apresentacao
 * 
 * @details A validação consiste em verificar se o horário inserido está no formato desejado
 * HH:MM e se este está no intervalo permitido
 * 
 */
class Horario : public Super {
 private:
    void validar(std::string) override;
};

/**
 * @class Preco
 * 
 * @brief Classe que armazena o preço de uma Apresentacao
 * 
 * @details A validação consiste em converter uma std::string em um float e checar se está no 
 * intervalo permitido
 * 
 */
class Preco : public Super {
 private:
    void validar(std::string) override;
};

/**
 * @class NumeroDeSala
 * 
 * @brief Armazena o número da sala de uma Apresentacao
 * 
 * @details A validação apenas checa se o número está no intervalo permitido 
 * 
 */
class NumeroDeSala : public Super {
 private:
    void validar(std::string) override;
};

/**
 * @class Cidade
 * 
 * @brief Armazena a cidade de um Evento ou Apresentacao
 * 
 * @details Verifica o formato do nome inserido
 * 
 */
class Cidade : public Super {
 private:
    void validar(std::string) override;
};

/**
 * @class Estado
 * 
 * @brief Define um estado para o Evento.
 * 
 * @details Verifica a validade da informação no formato UF.
 */
class Estado : public Super {
 private:
    void validar(std::string) override;
};

/**
 * @class Disponibilidade
 * 
 * @brief Disponibilidade de uma Apresentacao.
 * 
 * @details Verifica se é um numero positivo que esta no intervalo [0, 250].
 */
class Disponibilidade : public Super {
 private:
    void validar(std::string) override;
};

/**
 * @class ClasseDeEvento
 * 
 * @brief Define uma classe de um Evento.
 * 
 * @details Verifica se o numero esta no intervalo [1, 4].<br>
 * 1 = TEATRO<br>
 * 2 = ESPORTE<br>
 * 3 = SHOW NACIONAL<br>
 * 4 = SHOW INTERNACIONAL<br>
 * 
 */
class ClasseDeEvento : public Super{
 private:
    void validar(std::string) override;
};

/**
 * @class FaixaEtaria
 * 
 * @brief Faixa etaria de um Evento.
 * 
 * @details Verica se é um desses tipos {L, 10, 12, 14, 16 ,18}.
 * 
 */
class FaixaEtaria : public Super {
 private:
    void validar(std::string) override;
};

/**
 * @class CPF
 * 
 * @brief Armazena o cpf de um Usuario.
 * 
 * @details Verifica se o cpf e valido antes de colocar dentro.
 */
class CPF : public Super {
 private:
    void validar(std::string) override;
};

/**
 * @class Senha
 * 
 * @brief Armazena a senha de um Usuario.
 * 
 * @details A senha deve conter 6 caracteres nao repetidos que contenha pelo
 * menos 1 letra maiuscula, 1 letra minuscula e 1 digito.
 * 
 */
class Senha : public Super {
 private:
    void validar(std::string) override;
};

/**
 * @class NumCartaoCredito
 * 
 * @brief Armazena o numero de cartão de crédito de um Usuario.
 * 
 * @details Verifica se o numero é valido de acordo com o Algoritmo de Luhn.
 * 
 */
class NumCartaoCredito : public Super {
 private:
    void validar(std::string) override;
};
/**
 * @class CVV
 * 
 * @brief Armazena o codigo CVV de um CartaoDeCredito
 * 
 * @details Apenas verifica se possui 3 digitos. 
 * 
 */
class CVV : public Super {
 private:
    void validar(std::string) override;
};

/**
 * @class DataDeValidade
 * 
 * @brief Armazena a data de validade de um CartaoDeCredito.
 * 
 * @details Verifica se esta no formato mm/aa.
 * 
 */
class DataDeValidade : public Super {
 private:
    void validar(std::string) override;
};


#endif  // INCLUDE_DOMINIOS_H_

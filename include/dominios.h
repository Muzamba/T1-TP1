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
    std::string conteudo; /**< tipo padrão para todas as classes filhas */
    /**
     * @brief Método virtual de validação
     * 
     * O método que valida o formato de entrada dos dados. Caso a entrada
     * seja inválida uma exceção será retornada
     * 
     * @param string com o conteúdo
     * 
     * @throw std::invalid_argument com a devida mensagem de erro
     * 
     */
    virtual void validar(std::string) = 0;

 public:
 /**
  * @brief Set basico para as classe filhas
  * 
  * @param conteudo string a ser inserida dentro do objeto.
  * 
  * @throw std::invalid_argument Caso a validação de errado (Cada classe possui
  *  a sua) lança um objeto explicando o erro.
  * 
  * @see validar()
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
 * @see Super
 */
class CodigoDeEvento : public Super {
 private:
    /**
     * @brief Validação do CódigodeEvento
     * 
     * Verifica se a string de entrada representa um número e se possui o
     * tamanho correto, que é de 3 caracteres
     * 
     * @param String a ser validada como CodigoDeEvento
     * 
     * @throw std::invalid_argument com a devida mensagem de erro 
     * 
     */
    void validar(std::string) override;
};

/**
 * @class CodigoDeApresentacao
 * 
 * @brief Codigo destinado a indentificar uma Apresentacao.
 * 
 * @details A validação desse codigo apenas valida o tamanho de 4 digitos e se
 * são numero positivos.
 * 
 * @see Super
 */
class CodigoDeApresentacao : public Super {
 private:
    /**
     * @brief Validação do CódigodeApresentação
     * 
     * Verifica se a string de entrada representa um número e se possui o
     * tamanho correto, que é de 4 caracteres
     * 
     * @param String a ser validada como CodigoDeApresntação
     * 
     * @throw std::invalid_argument com a devida mensagem de erro 
     * 
     */
    void validar(std::string) override;
};

/**
 * @class CodigoDeIngresso 
 * 
 * @brief Codigo destinado a indentificar Ingressos distintos.
 * 
 * @details A validação desse codigo apenas valida o tamanho de 5 digitos e se
 * são numero positivos.
 * 
 * @see Super
 */
class CodigoDeIngresso : public Super {
 private:
    /**
     * @brief Validação do CódigodeIngresso
     * 
     * Verifica se a string de entrada representa um número e se possui o
     * tamanho correto, que é de 5 caracteres
     * 
     * @param String a ser validada como CodigoDeIngresso
     * 
     * @throw std::invalid_argument com a devida mensagem de erro 
     * 
     */
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
 * @see Super
 */
class NomeDeEvento : public Super {
 private:
    /**
     * @brief Validação do NomedeEvento
     * 
     * Verifica se a string de entrada possui até 20 caracteres e se possui ao menos
     * uma letra, sendo que espaços brancos em seguida não são válidos
     * 
     * @param String a ser validada como NomeDeEvento
     * 
     * @throw std::invalid_argument com a devida mensagem de erro 
     * 
     */
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
 * @see Super
 */
class Data : public Super {
 private:
    /**
     * @brief Validação da Data
     * 
     * Verifica se a string de entrada representa uma data e se ela está no formato
     * correto. Também é checado se os números de dia, mês e ano são consistentes. Por
     * fim, checa-se por anos bissextos
     * 
     * @param String a ser validada como Data
     * 
     * @throw std::invalid_argument com a devida mensagem de erro 
     * 
     */
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
 * @see Super
 */
class Horario : public Super {
 private:
    /**
     * @brief Validação do Horario
     * 
     * Verifica se a string de entrada representa um horário e se ele está no formato
     * HH:MM. Depois, é checado se os números que representam hora e minuto estão no
     * intervalo correto
     * 
     * @param String a ser validada como Horario
     * 
     * @throw std::invalid_argument com a devida mensagem de erro 
     * 
     */
    void validar(std::string) override;
};

/**
 * @class Preco
 * 
 * @brief Classe que armazena o preço de uma Apresentacao
 * 
 * @details A validação consiste em converter uma std::string em um double e checar se está no 
 * intervalo permitido
 * 
 * @see Super
 * 
 */
class Preco : public Super {
 private:
    /**
     * @brief Validação do Preco
     * 
     * Verifica se a string de entrada representa um preço. A string é convertida para um
     * double e é verificado se está dentro do intervalo permitido
     * 
     * @param String a ser validada como Preco
     * 
     * @throw std::invalid_argument com a devida mensagem de erro 
     * 
     */
    void validar(std::string) override;
};

/**
 * @class NumeroDeSala
 * 
 * @brief Armazena o número da sala de uma Apresentacao
 * 
 * @details A validação apenas checa se o número está no intervalo permitido 
 * 
 * @see Super
 * 
 */
class NumeroDeSala : public Super {
 private:
    /**
     * @brief Validação do NumeroDeSala
     * 
     * Verifica se a string de entrada representa um numéro de sala e é verificado
     * se está dentro do intervalo permitido
     * 
     * @param String a ser validada como NumeroDeSala
     * 
     * @throw std::invalid_argument com a devida mensagem de erro 
     * 
     */
    void validar(std::string) override;
};

/**
 * @class Cidade
 * 
 * @brief Armazena a cidade de um Evento ou Apresentacao
 * 
 * @details Verifica o formato do nome inserido
 * 
 * @see Super
 * 
 */
class Cidade : public Super {
 private:
    /**
     * @brief Validação do Cidade
     * 
     * Verifica se a string de entrada representa uma cidade, além de seu formato
     * e tamanho.Se cada caractere da entrada é letra, espaço ou ponto, se não há
     * espaços seguidos e se cada ponto é precedido por uma letra
     * 
     * @param String a ser validada como Cidade
     * 
     * @throw std::invalid_argument com a devida mensagem de erro 
     * 
     */
    void validar(std::string) override;
};

/**
 * @class Estado
 * 
 * @brief Define um estado para o Evento.
 * 
 * @details Verifica a validade da informação no formato UF.
 * 
 * @see Super
 */
class Estado : public Super {
 private:
    /**
     * @brief Validação do Estado
     * 
     * Verifica se a string de entrada representa um estado, verificando apenas se 
     * consta nos estados possíveis
     * 
     * @param String a ser validada como Estado
     * 
     * @throw std::invalid_argument com a devida mensagem de erro 
     * 
     */
    void validar(std::string) override;
};

/**
 * @class Disponibilidade
 * 
 * @brief Disponibilidade de uma Apresentacao.
 * 
 * @details Verifica se é um numero positivo que esta no intervalo [0, 250].
 * 
 * @see Super
 */
class Disponibilidade : public Super {
 private:
    /**
     * @brief Validação da Disponibilidade
     * 
     * Verifica se a string de entrada representa uma disponibilidade, checando se
     * é um número positivo no intervalo [0, 250]
     * 
     * @param String a ser validada como Disponibilidade
     * 
     * @throw std::invalid_argument com a devida mensagem de erro 
     * 
     */
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
 * @see Super
 */
class ClasseDeEvento : public Super{
 private:
    /**
     * @brief Validação da ClasseDeEvento
     * 
     * Verifica se a string de entrada representa uma classe de evento.
     * Checa se o numero esta no intervalo [1, 4].<br>
     * 1 = TEATRO<br>
     * 2 = ESPORTE<br>
     * 3 = SHOW NACIONAL<br>
     * 4 = SHOW INTERNACIONAL<br>
     * 
     * @param String a ser validada como cidade
     * 
     * @throw std::invalid_argument com a devida mensagem de erro 
     * 
     */
    void validar(std::string) override;
};

/**
 * @class FaixaEtaria
 * 
 * @brief Faixa etaria de um Evento.
 * 
 * @details Verica se é um desses tipos {L, 10, 12, 14, 16 ,18}.
 * 
 * @see Super 
 */
class FaixaEtaria : public Super {
 private:
    /**
     * @brief Validação da FaixaEtaria
     * 
     * Verifica se a string de entrada representa uma faixa etária. Verifica se é
     * um dos seguintes tipos {L, 10, 12, 14, 16, 18}
     * 
     * @param String a ser validada como FaixaEtaria
     * 
     * @throw std::invalid_argument com a devida mensagem de erro 
     * 
     */
    void validar(std::string) override;
};

/**
 * @class CPF
 * 
 * @brief Armazena o cpf de um Usuario.
 * 
 * @details Verifica se o cpf e valido antes de colocar dentro.
 * 
 * @see Super
 */
class CPF : public Super {
 private:
    /**
     * @brief Validação do CPF
     * 
     * Verifica se a string de entrada representa um CPF, inserido apenas em números.
     * É utilizado algorítmo padrão para cálculo de dígitos verificadores de CPF
     * 
     * @param String a ser validada como CPF
     * 
     * @throw std::invalid_argument com a devida mensagem de erro 
     * 
     */
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
 * @see Super
 * 
 */
class Senha : public Super {
 private:
    /**
     * @brief Validação da Senha
     * 
     * Verifica se a string de entrada representa uma senha, sendo que
     * esta deve conter 6 caracteres nao repetidos que contenha pelo 
     * menos 1 letra maiuscula, 1 letra minuscula e 1 digito.
     * 
     * @param String a ser validada como Disponibilidade
     * 
     * @throw std::invalid_argument com a devida mensagem de erro
     */
    void validar(std::string) override;
};

/**
 * @class NumCartaoCredito
 * 
 * @brief Armazena o numero de cartão de crédito de um Usuario.
 * 
 * @details Verifica se o numero é valido de acordo com o Algoritmo de Luhn.
 * 
 * @see Super
 */
class NumCartaoCredito : public Super {
 private:
    /**
     * @brief Validação de NumCartaoCredito
     * 
     * Verifica se a string de entrada representa um número de cartão de crédito
     * usando o Algoritmo de Luhn (https://en.wikipedia.org/wiki/Luhn_algorithm)
     * 
     * @param String a ser validada como NumCartaoCredito
     * 
     * @throw std::invalid_argument com a devida mensagem de erro
     */
    void validar(std::string) override;
};
/**
 * @class CVV
 * 
 * @brief Armazena o codigo CVV de um CartaoDeCredito
 * 
 * @details Apenas verifica se possui 3 digitos. 
 * 
 * @see Super
 * 
 */
class CVV : public Super {
 private:
    /**
     * @brief Validação de CVV
     * 
     * Verifica se a string de entrada representa um código CVV, checando apenas se
     * possui 3 dígitos no intervalo permitido
     * 
     * @param String a ser validada como CVV
     * 
     * @throw std::invalid_argument com a devida mensagem de erro
     */
    void validar(std::string) override;
};

/**
 * @class DataDeValidade
 * 
 * @brief Armazena a data de validade de um CartaoDeCredito.
 * 
 * @details Verifica se esta no formato MM/AA.
 * 
 * @see Super
 */
class DataDeValidade : public Super {
 private:
    /**
     * @brief Validação de DataDeValidade
     * 
     * Verifica se a string de entrada representa uma DataDeValidade, vendo apenas
     * se está no formato MM/AA
     * 
     * @param String a ser validada como DataDeValidade
     * 
     * @throw std::invalid_argument com a devida mensagem de erro
     */
    void validar(std::string) override;
};


#endif  // INCLUDE_DOMINIOS_H_

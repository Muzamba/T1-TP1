// Copyright Ariel e João Pedro
/**
 * @file dominios.h
 * @author Ariel e João Pedro (you@domain.com)
 * @brief Biblioteca simples de dominios    
 * @version 0.1
 * @date 2019-04-29
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef INCLUDE_DOMINIOS_H_
#define INCLUDE_DOMINIOS_H_
#include <string>
#include <stdexcept>
#include <cctype>


/**
 * @brief Classe abstrata o qual todos os dominios herdam.
 */
class Super {
 protected:
    std::string conteudo;
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
 * @brief Codigo destinado a indentificar eventos distintos.
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
 * @brief Codigo destinado a indentificar Apresentações distintas.
 * 
 * @details A validação desse codigo apenas valida o tamanho de 4 digitos e se
 * são numero positivos.
 */
class CodigoDeApresentacao : public Super {
 private:
    void validar(std::string) override;
};

/**
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
 * @brief Nomeia um evento.
 * 
 * @details A validação desse nome apenas valida o tamanho de até 20 caracteres e se
 * possui ao menos uma letra.(Espaços seguidos tambem não são válidos)
 * 
 */
class NomeDeEvento : public Super {
 private:
    void validar(std::string) override;
};

class Data : public Super {
 private:
    void validar(std::string) override;
    bool bissexto(int);
};

class Horario : public Super {
 private:
    void validar(std::string) override;
};

class Preco : public Super {
 private:
    void validar(std::string) override;
};

class NumeroDeSala : public Super {
 private:
    void validar(std::string) override;
};

class Cidade : public Super {
 private:
    void validar(std::string) override;
};

class Estado : public Super {
 private:
    void validar(std::string) override;
};

class Disponibilidade : public Super {
 private:
    void validar(std::string) override;
};


class ClasseDeEvento : public Super{
 private:
    void validar(std::string) override;
};

class FaixaEtaria : public Super {
 private:
    void validar(std::string) override;
};

class CPF : public Super {
 private:
    void validar(std::string) override;
};

class Senha : public Super {
 private:
    void validar(std::string) override;
};

class NumCartaoCredito : public Super {
 private:
    void validar(std::string) override;
};

class CVV : public Super {
 private:
    void validar(std::string) override;
};

class DataDeValidade : public Super {
 private:
    void validar(std::string) override;
};


#endif  // INCLUDE_DOMINIOS_H_

/**
 * @file entidades.h
 * @author Ariel e João Pedro
 * @brief Biblioteca simples de Entidaes
 * @version 0.1
 * @date 2019-04-29
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef INCLUDE_ENTIDADES_H_
#define INCLUDE_ENTIDADES_H_
class Usuario;
class Evento;
class Apresentacao;
class Ingresso;
// class CartaoDeCredito;

#include <vector>
#include "./dominios.h"



class Super_ent {
};

/**
 * @class CartaoDeCredito
 * 
 * @brief Classe que armazena dados de um cartão de crédito
 * 
 * Esta classe representa um CartaoDeCredito no decorrer no programa. Tem como
 * atributos o numero do cartão, um CVV e uma data de validade. A classe não possui
 * métodos de validação pois assume-se que os domínios já estarão criados
 * (e portato validados)
 * 
 * @see NumCartaoCredito
 * @see CVV
 * @see DataDeValidade
 */
class CartaoDeCredito : public Super_ent {
 public:
    /**
     * @brief Método set do CartaoDeCredito
     * 
     * @param numero 
     */
    void SetNumCartaoCredito(NumCartaoCredito numero);
    /**
     * @brief Método get do CartaoDeCredito
     * 
     * @return NumCartaoCredito 
     */
    NumCartaoCredito GetNumCartaoCredito();

    /**
     * @brief Método set do CVV
     * 
     * @param cvv 
     */
    void SetCVV(CVV cvv);
    /**
     * @brief Método get do CVV
     * 
     * @return CVV 
     */
    CVV GetCVV();

    /**
     * @brief Método set da DataDeValidade
     * 
     * @param data 
     */
    void SetDataDeValidade(DataDeValidade data);
    /**
     * @brief Método get da DataDeValidade
     * 
     * @return DataDeValidade 
     */
    DataDeValidade GetDataDeValidade();

 private:
    NumCartaoCredito numero; /**< numero do cartão, chave primária no BD*/
    CVV codigo;/**< código CVV do cartão*/
    DataDeValidade dataDeValidade;/**< data de validade do cartão*/
};

/**
 * @class Usuario
 * 
 * @brief Classe que deve armazenar dados de um usuário
 * 
 * Esta classe é a representação de um usuário no programa e possui como
 * atributos um CPF e uma Senha. A classe não possui métodos de validação
 * pois assume-se que os domínios já estarão criados (e portato validados)
 * 
 * @see CPF
 * @see Senha
 * 
 */
class Usuario : public Super_ent {
 public:
   /**
    * @brief Método set do Cpf
    * 
    * @param cpf 
    */
    void SetCPF(CPF cpf);

    /**
     * @brief Método get do Cpf
     * 
     * @return CPF 
     */
    CPF GetCPF();

    /**
     * @brief Método set da Senha
     * 
     * @param senha 
     */
    void SetSenha(Senha senha);

    /**
     * @brief Método get da Senha
     * 
     * @return Senha 
     */
    Senha GetSenha();

 private:
    CPF cpf; /**< CPF do usuário, que será chave primária no BD*/
    Senha senha; /**< Senha do usuário*/

 public:
    CartaoDeCredito cartao;
    std::vector<Evento> vecEventos;
};

/**
 * @class Evento
 * 
 * @brief Classe que armazena dados de um Evento
 * 
 * Esta classe representa um Evento no decorrer do programa. Tem como atributos
 * um código, nome, cidade, estado, classe e faixa etária. A classe não possui métodos de validação
 * pois assume-se que os domínios já estarão criados (e portato validados)
 * 
 * @see CodigoDeEvento
 * @see NomeDeEvento
 * @see Cidade
 * @see Estado
 * @see ClasseDeEvento
 * @see FaixaEtaria
 * 
 */
class Evento : public Super_ent {
 public:
    /**
     * @brief Método set do CodigoDeEvento
     * 
     * @param codigo 
     */
    void SetCodigoDeEvento(CodigoDeEvento codigo);
    /**
     * @brief Método get do CodigoDeEvento
     * 
     * @return CodigoDeEvento 
     */
    CodigoDeEvento GetCodigoDeEvento();

    /**
     * @brief Método set do NomeDeEvento
     * 
     * @param nome 
     */
    void SetNomeDeEvento(NomeDeEvento nome);
    /**
     * @brief Método get do NomeDeEvento
     * 
     * @return NomeDeEvento 
     */
    NomeDeEvento GetNomeDeEvento();

    /**
     * @brief Método set da Cidade
     * 
     * @param cidade 
     */
    void SetCidade(Cidade cidade);
    /**
     * @brief Método get da Cidade
     * 
     * @return Cidade 
     */
    Cidade GetCidade();

    /**
     * @brief Método set do Estado
     * 
     * @param estado 
     */
    void SetEstado(Estado estado);
    /**
     * @brief Método get do Estado
     * 
     * @return Estado 
     */
    Estado GetEstado();

    /**
     * @brief Métoto set da ClasseDeEvento
     * 
     * @param classe 
     */
    void SetClasseDeEvento(ClasseDeEvento classe);
    /**
     * @brief Método get da ClasseDeEvento
     * 
     * @return ClasseDeEvento 
     */
    ClasseDeEvento GetClasseDeEvento();

    /**
     * @brief Método set da FaixaEtaria
     * 
     * @param faixa 
     */
    void SetFaixaEtaria(FaixaEtaria faixa);
    /**
     * @brief Método set da FaixaEtaria
     * 
     * @return FaixaEtaria 
     */
    FaixaEtaria GetFaixaEtaria();

 private:
    CodigoDeEvento codigo; /**<Código do envento, chave primária no BD*/
    NomeDeEvento nome; /**<Nome do envento*/
    Cidade cidade; /**<Cidade onde o evento ocorrerá*/
    Estado estado; /**<Estado onde o evento ocorrerá*/
    ClasseDeEvento classe; /**<Classe do evento*/
    FaixaEtaria faixa; /**<Faixa etária do evento*/

 public:
    CPF dono;
    std::vector<Apresentacao> vecApres;
};

/**
 * @class Apresentacao
 * 
 * @brief Classe que armazena dados de uma Apresentação
 * 
 * Esta classe representa uma apresentação no decorrer do programa.
 * Tem como atributos código, data, horário, preço, numero de sala e
 * disponibilidade. A classe não possui métodos de validação
 * pois assume-se que os domínios já estarão criados (e portato validados)
 * 
 * @see CodigoDeApresentacao
 * @see Data
 * @see Horario
 * @see NumeroDeSala
 * @see Preco
 * @see Disponibilidade
 */
class Apresentacao : public Super_ent {
 public:
    /**
     * @brief Método set da Apresentaco
     * 
     * @param codigo 
     */
    void SetCodigoDeApresentacao(CodigoDeApresentacao codigo);
    /**
     * @brief Método get do CodigoDeApresentacao
     * 
     * @return CodigoDeApresentacao 
     */
    CodigoDeApresentacao GetCodigoDeApresentacao();

    /**
     * @brief Método set da Data
     * 
     * @param data 
     */
    void SetData(Data data);
    /**
     * @brief Método get da Data
     * 
     * @return Data 
     */
    Data GetData();

    /**
     * @brief Método set do Horário
     * 
     * @param horario 
     */
    void SetHorario(Horario horario);
    /**
     * @brief Método get do Horario
     * 
     * @return Horario 
     */
    Horario GetHorario();

    /**
     * @brief Método set do Preco 
     * 
     * @param preco 
     */
    void SetPreco(Preco preco);
    /**
     * @brief Método get do Preco
     * 
     * @return Preco 
     */
    Preco GetPreco();

    /**
     * @brief Método set da Sala
     * 
     * @param numero 
     */
    void SetNumeroDeSala(NumeroDeSala numero);
    /**
     * @brief Método get do NumeroDeSala
     * 
     * @return NumeroDeSala 
     */
    NumeroDeSala GetNumeroDeSala();

    /**
     * @brief Método set da Disponibilidade
     * 
     * @param disponibilidade 
     */
    void SetDisponibilidade(Disponibilidade disponibilidade);
    /**
     * @brief Método get da Disponibilidade
     * 
     * @return Disponibilidade 
     */
    Disponibilidade GetDisponibilidade();

 private:
    CodigoDeApresentacao codigo; /**<Código da apres, chave primária do BD*/
    Data data; /**<Data da apresentação*/
    Horario horario; /**<Horário da apresentação*/
    Preco preco; /**<Preço da apresentação*/
    NumeroDeSala sala; /**<Numero da sala da apresentação*/
    Disponibilidade disponibilidade; /**<Disponibilidade da apresentação*/

 public:
    CodigoDeEvento evento;
    std::vector<Ingresso> vecIngre;
};

/**
 * @class Ingresso
 * 
 * @brief Classe que armazena dados de um ingresso
 * 
 * Esta classe representa um ingresso ao decorrer do programa. Tem como atributo
 * apenas o código do ingresso. A classe não possui métodos de validação
 * pois assume-se que os domínios já estarão criados (e portato validados)
 * 
 * @see CodigoDeIngresso
 */
class Ingresso : public Super_ent {
 public:
    /**
     * @brief Método set do CodigoDeIngresso
     * 
     * @param codigo 
     */
    void SetCodigoDeIngresso(CodigoDeIngresso codigo);
    /**
     * @brief Método get do CodigoDeIngresso
     * 
     * @return CodigoDeIngresso 
     */
    CodigoDeIngresso GetCodigoDeIngresso();

 private:
    CodigoDeIngresso codigo; /**< Código do ingresso, chave primária do BD*/

 public:
    CodigoDeApresentacao apresentacao;
    CPF dono;
};




#endif    //  INCLUDE_ENTIDADES_H_

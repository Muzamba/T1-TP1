// Copyright Ariel e João Pedro
#define CATCH_CONFIG_MAIN
#include <iostream>
#include <string>
#include "catch.hpp"
#include "dominios.h"

TEST_CASE("Classe CPF") {
    std::string real_cpf("05289706151");
    std::string fake_cpf1("12345678910");
    std::string fake_cpf2("123039230940");
    CPF cpf;
    CPF cpf_fake;

    std::cout << "\n------ Testes da classe CPF ------\n" << std::endl;

    cpf.setConteudo(real_cpf);
    REQUIRE(!cpf.getConteudo().compare(real_cpf));

    SECTION("Problemáticos") {
        try {
            cpf_fake.setConteudo(fake_cpf1);
        } catch (const std::invalid_argument& erro) {
            std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!cpf_fake.getConteudo().size());
        }

        try {
            cpf_fake.setConteudo(fake_cpf2);
        } catch (const std::invalid_argument& erro) {
            std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!cpf_fake.getConteudo().size());
        }
    }
}

TEST_CASE("Classe CodigoDeEvento") {
    /**
     * Código de Evento válido => Inteiro positivo de apenas 3 dígitos
     * 
     * Código de Evento inválido => Literalmente qualquer outra coisa 
     */
    std::string codigo_valido("978");
    std::string codigo_invalido1("-4530");
    std::string codigo_invalido2("-495");
    std::string codigo_invalido3("78934");

    CodigoDeEvento valido;
    CodigoDeEvento invalido;

    std::cout << "\n------ Testes da classe CodigoDeEvento ------\n"
    << std::endl;

    valido.setConteudo(codigo_valido);
    REQUIRE(!valido.getConteudo().compare(codigo_valido));

    SECTION("Problemáticos") {
        try {
            invalido.setConteudo(codigo_invalido1);
        } catch (const std::invalid_argument& erro) {
            std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!invalido.getConteudo().size());
        }

        try {
            invalido.setConteudo(codigo_invalido2);
        } catch (const std::invalid_argument& erro) {
            std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!invalido.getConteudo().size());
        }

        try {
            invalido.setConteudo(codigo_invalido3);
        } catch (const std::invalid_argument& erro) {
            std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!invalido.getConteudo().size());
        }
    }
}

TEST_CASE("Classe CodigoDeApresentacao") {
    /**
     * Código de Apresentação válido => Inteiro positivo de apenas
     * 4 dígitos
     * 
     * Código de Aprensentação inválido => Literalmente qualquer outra
     * coisa 
     */

    std::string codigo_valido("9783");
    std::string codigo_invalido1("-4530");
    std::string codigo_invalido2("-495092");
    std::string codigo_invalido3("78");

    CodigoDeApresentacao valido;
    CodigoDeApresentacao invalido;

    std::cout << "\n------ Testes da classe CodigoDeApresentacao ------\n"
    << std::endl;

    valido.setConteudo(codigo_valido);
    REQUIRE(!valido.getConteudo().compare(codigo_valido));

    SECTION("Problemáticos") {
        try {
            invalido.setConteudo(codigo_invalido1);
        } catch (const std::invalid_argument& erro) {
            std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!invalido.getConteudo().size());
        }

        try {
            invalido.setConteudo(codigo_invalido2);
        } catch (const std::invalid_argument& erro) {
            std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!invalido.getConteudo().size());
        }

        try {
            invalido.setConteudo(codigo_invalido3);
        } catch (const std::invalid_argument& erro) {
            std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!invalido.getConteudo().size());
        }
    }
}

TEST_CASE("Classe CodigoDeIngresso") {
    /**
     * Código de Ingresso válido => Inteiro positivo de apenas
     * 5 dígitos
     * 
     * Código de Ingresso inválido => Literalmente qualquer outra
     * coisa 
     */

    std::string codigo_valido("97832");
    std::string codigo_invalido1("-4530");
    std::string codigo_invalido2("-495092");
    std::string codigo_invalido3("7898");

    CodigoDeIngresso valido;
    CodigoDeIngresso invalido;

    std::cout << "\n------ Testes da classe CodigoDeIngresso ------\n"
    << std::endl;

    valido.setConteudo(codigo_valido);
    REQUIRE(!valido.getConteudo().compare(codigo_valido));

    SECTION("Problemáticos") {
        try {
            invalido.setConteudo(codigo_invalido1);
        } catch (const std::invalid_argument& erro) {
            std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!invalido.getConteudo().size());
        }

        try {
            invalido.setConteudo(codigo_invalido2);
        } catch (const std::invalid_argument& erro) {
            std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!invalido.getConteudo().size());
        }

        try {
            invalido.setConteudo(codigo_invalido3);
        } catch (const std::invalid_argument& erro) {
            std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!invalido.getConteudo().size());
        }
    }
}
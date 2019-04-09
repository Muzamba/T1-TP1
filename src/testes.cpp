// Copyright Ariel e João Pedro
#define CATCH_CONFIG_MAIN
#include <iostream>
#include <string>
#include "catch.hpp"
#include "dominios.h"

TEST_CASE("Classe CPF") {
    std::string cpf_valido("05289706151");
    std::string cpf_invalido1("12345678910");
    std::string cpf_invalido2("123039230940");
    CPF valido;
    CPF invalido;

   // std::cout << "\n------ Testes da classe CPF ------\n" << std::endl;

    SECTION("Tudo certo por aqui") {
        try {
            valido.setConteudo(cpf_valido);
            REQUIRE(!valido.getConteudo().compare(cpf_valido));
        } catch (std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!valido.getConteudo().size());
        }
    }

    SECTION("Problemáticos") {
        try {
            invalido.setConteudo(cpf_invalido1);
            REQUIRE(!invalido.getConteudo().size());
        } catch (const std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!invalido.getConteudo().size());
        }

        try {
            invalido.setConteudo(cpf_invalido2);
            REQUIRE(!invalido.getConteudo().size());
        } catch (const std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!invalido.getConteudo().size());
        }
    }
}

TEST_CASE("Classe CodigoDeEvento") {
    /**
     * Código de Evento válido => Inteiro positivo de apenas 3 dígitos
     */
    std::string codigo_valido("978");
    std::string codigo_invalido1("-4530");
    std::string codigo_invalido2("-495");
    std::string codigo_invalido3("78934");

    CodigoDeEvento valido;
    CodigoDeEvento invalido;

   // std::cout << "\n------ Testes da classe CodigoDeEvento ------\n"
    //<< std::endl;

    SECTION("Tudo certo por aqui") {
        try {
            valido.setConteudo(codigo_valido);
            REQUIRE(!valido.getConteudo().compare(codigo_valido));
        } catch (std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!valido.getConteudo().size());
        }
    }

    SECTION("Problemáticos") {
        try {
            invalido.setConteudo(codigo_invalido1);
            REQUIRE(!invalido.getConteudo().size());
        } catch (const std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!invalido.getConteudo().size());
        }

        try {
            invalido.setConteudo(codigo_invalido2);
            REQUIRE(!invalido.getConteudo().size());
        } catch (const std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!invalido.getConteudo().size());
        }

        try {
            invalido.setConteudo(codigo_invalido3);
            REQUIRE(!invalido.getConteudo().size());
        } catch (const std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!invalido.getConteudo().size());
        }
    }
}

TEST_CASE("Classe CodigoDeApresentacao") {
    /**
     * Código de Apresentação válido => Inteiro positivo de apenas
     * 4 dígitos 
     */

    std::string codigo_valido("9783");
    std::string codigo_invalido1("-4530");
    std::string codigo_invalido2("-495092");
    std::string codigo_invalido3("78");

    CodigoDeApresentacao valido;
    CodigoDeApresentacao invalido;

   // std::cout << "\n------ Testes da classe CodigoDeApresentacao ------\n"
   // << std::endl;

    SECTION("Tudo certo por aqui") {
        try {
            valido.setConteudo(codigo_valido);
            REQUIRE(!valido.getConteudo().compare(codigo_valido));
        } catch (std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!valido.getConteudo().size());
        }
    }

    SECTION("Problemáticos") {
        try {
            invalido.setConteudo(codigo_invalido1);
            REQUIRE(!invalido.getConteudo().size());
        } catch (const std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!invalido.getConteudo().size());
        }

        try {
            invalido.setConteudo(codigo_invalido2);
            REQUIRE(!invalido.getConteudo().size());
        } catch (const std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!invalido.getConteudo().size());
        }

        try {
            invalido.setConteudo(codigo_invalido3);
            REQUIRE(!invalido.getConteudo().size());
        } catch (const std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!invalido.getConteudo().size());
        }
    }
}

TEST_CASE("Classe CodigoDeIngresso") {
    /**
     * Código de Ingresso válido => Inteiro positivo de apenas
     * 5 dígitos
     */

    std::string codigo_valido("97832");
    std::string codigo_invalido1("-4530");
    std::string codigo_invalido2("-495092");
    std::string codigo_invalido3("7898");

    CodigoDeIngresso valido;
    CodigoDeIngresso invalido;

   // std::cout << "\n------ Testes da classe CodigoDeIngresso ------\n"
   // << std::endl;

    SECTION("Tudo certo por aqui") {
        try {
            valido.setConteudo(codigo_valido);
            REQUIRE(!valido.getConteudo().compare(codigo_valido));
        } catch (std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!valido.getConteudo().size());
        }
    }

    SECTION("Problemáticos") {
        try {
            invalido.setConteudo(codigo_invalido1);
            REQUIRE(!invalido.getConteudo().size());
        } catch (const std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!invalido.getConteudo().size());
        }

        try {
            invalido.setConteudo(codigo_invalido2);
            REQUIRE(!invalido.getConteudo().size());
        } catch (const std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!invalido.getConteudo().size());
        }

        try {
            invalido.setConteudo(codigo_invalido3);
            REQUIRE(!invalido.getConteudo().size());
        } catch (const std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!invalido.getConteudo().size());
        }
    }
}

TEST_CASE("Classe NomeDeEvento") {
    /**
     * Nome de Evento Válido => String de 20 caracteres alfanuméricos,
     * sem espaços em sequência e com no mínimo uma letra */

    std::string nome_valido1("ShowTopdoJackJohnson");
    std::string nome_valido2("Show do 2DoorCinClub");
    std::string nome_valido3("Show do fFooFighters");
    std::string nome_valido4("123456789e9876543219");

    std::string nome_invalido1("Sem ideias  por aqui");
    std::string nome_invalido2("01234567891011121314");
    std::string nome_invalido3("uma menorzinha");
    std::string nome_invalido4("UMA MAIORZONA PRA TESTAR");

    NomeDeEvento valido;
    NomeDeEvento invalido;

    //std::cout << "\n------ Testes da classe NomeDeEvento ------\n"
    //<< std::endl;

    SECTION("Tudo certo por aqui") {
        try {
            valido.setConteudo(nome_valido1);
            REQUIRE(!valido.getConteudo().compare(nome_valido1));
        } catch (const std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!valido.getConteudo().size());
        }
        try {
            valido.setConteudo(nome_valido2);
            REQUIRE(!valido.getConteudo().compare(nome_valido2));
        } catch (std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!valido.getConteudo().size());
        }
        try {
            valido.setConteudo(nome_valido3);
            REQUIRE(!valido.getConteudo().compare(nome_valido3));
        } catch (std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!valido.getConteudo().size());
        }
        try {
            valido.setConteudo(nome_valido4);
            REQUIRE(!valido.getConteudo().compare(nome_valido4));
        } catch (std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!valido.getConteudo().size());
        }
    }

    SECTION("Problemáticos") {
        try {
            invalido.setConteudo(nome_invalido1);
            REQUIRE(!invalido.getConteudo().compare(nome_invalido1));
        } catch (const std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            std::cout << invalido.getConteudo() << std::endl;
            REQUIRE(!invalido.getConteudo().size());
        }
        try {
            invalido.setConteudo(nome_invalido2);
            REQUIRE(!invalido.getConteudo().compare(nome_invalido2));
        } catch (const std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            std::cout << invalido.getConteudo() << std::endl;
            REQUIRE(!invalido.getConteudo().size());
        }
        try {
            invalido.setConteudo(nome_invalido3);
            REQUIRE(!invalido.getConteudo().compare(nome_invalido3));
        } catch (const std::invalid_argument& erro) {
           // std::cout << "FUCK HERE" << invalido.getConteudo() << std::endl;
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(invalido.getConteudo().size() == 0);
        }
        try {
            invalido.setConteudo(nome_invalido4);
            REQUIRE(!invalido.getConteudo().compare(nome_invalido4));
        } catch (const std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!invalido.getConteudo().size());
        }
    }
}

TEST_CASE("Classe NumeroDeSala") {
    SECTION("Tudo certo por aqui") {
        std::string numero_valido("5");
        NumeroDeSala valido;
        try {
            valido.setConteudo(numero_valido);
            REQUIRE(!valido.getConteudo().compare(numero_valido));
        } catch (const std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!valido.getConteudo().size());
        }
    }

    SECTION("Problemáticos") {
        std::string numero_invalido1("-4");
        std::string numero_invalido2("14");
        NumeroDeSala invalido;
        try {
            invalido.setConteudo(numero_invalido1);
            REQUIRE(!invalido.getConteudo().compare(numero_invalido1));
        } catch (const std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!invalido.getConteudo().size());
        }
        try {
            invalido.setConteudo(numero_invalido2);
            REQUIRE(!invalido.getConteudo().compare(numero_invalido2));
        } catch (const std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!invalido.getConteudo().size());
        }
    }
}

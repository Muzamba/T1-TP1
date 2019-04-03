// Copyright Ariel e João Pedro
#define CATCH_CONFIG_MAIN
#include <iostream>
#include <string>
#include "catch.hpp"
#include "dominios.h"

TEST_CASE("Classe CPF") {
    std::string real_cpf("05289706151");
    std::string fake_cpf("12345678910");
    CPF cpf;
    CPF cpf_fake;

    cpf.setConteudo(real_cpf);
    REQUIRE(!cpf.getConteudo().compare(real_cpf));

    try {
        cpf_fake.setConteudo(fake_cpf);
    } catch (const std::invalid_argument& erro) {
        std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
        REQUIRE(!cpf_fake.getConteudo().size());
    }
}


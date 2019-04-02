// Copyright Ariel e João Pedro
#define CATCH_CONFIG_MAIN
#include <iostream>
#include <string>
#include "catch.hpp"
#include "../../include/dominios.h"

TEST_CASE("Classe CPF") {
    std::string digitos("05289706151");
    std::string fake_digitos("32145809876");

    CPF cpf(digitos);
    REQUIRE(cpf.getCPF() == digitos);

    CPF fake_cpf(fake_digitos);
}



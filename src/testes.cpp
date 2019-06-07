// Copyright Ariel e João Pedro
#ifdef DEBUG

#define CATCH_CONFIG_MAIN
#include <iostream>
#include <string>
#include "catch.hpp"
#include "dominios.h"
#include "entidades.h"
#define VALIDO 0

// --------------------------------Teste-CPF------------------------------------
TEST_CASE("Dominio CPF") {
    std::string val;
    CPF uniTest;
    SECTION("Certo") {
        SECTION("1") {
            val = "05289706151";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
    }
    SECTION("Excessão") {
        SECTION("1") {
            val = "12345678910";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
        SECTION("2") {
            val = "123039230940";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
    }
}

// ------------------------Teste-Codigo-de-Evento-------------------------------o
/**
 * Código de Evento válido => Inteiro positivo de apenas 3 dígitos
 */
TEST_CASE("Dominio CodigoDeEvento") {
    std::string val;
    CodigoDeEvento uniTest;
    SECTION("Certo") {
        SECTION("1") {
            val = "978";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
    }
    SECTION("Excessão") {
        SECTION("1") {
            val = "-4530";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
        SECTION("2") {
            val = "-495";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
        SECTION("3") {
            val = "78934";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
    }
}

/**
 * Código de Apresentação válido => Inteiro positivo de apenas
 * 4 dígitos 
 */
TEST_CASE("Dominio CodigoDeApresentacao") {
    std::string val;
    CodigoDeApresentacao uniTest;
    SECTION("Certo") {
        SECTION("1") {
            val = "9783";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
    }
    SECTION("Excessão") {
        SECTION("1") {
            val = "-4530";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
        SECTION("2") {
            val = "-495092";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
        SECTION("3") {
            val = "78";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
    }
}

/**
 * Código de Ingresso válido => Inteiro positivo de apenas
 * 5 dígitos
 */
TEST_CASE("Dominio CodigoDeIngresso") {
    std::string val;
    CodigoDeIngresso uniTest;
    SECTION("Certo") {
        SECTION("1") {
            val = "97832";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
    }
    SECTION("Excessão") {
        SECTION("1") {
            val = "-4530";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
        SECTION("2") {
            val = "-495092";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
        SECTION("3") {
            val = "7898";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
    }
}

/**
 * Nome de Evento Válido => String de 20 caracteres alfanuméricos,
 * sem espaços em sequência e com no mínimo uma letra 
 * */
TEST_CASE("Dominio NomeDeEvento") {
    std::string val;
    NomeDeEvento uniTest;
    SECTION("Certo") {
        SECTION("1") {
            val = "Show do Jack Johnson";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
        SECTION("2") {
            val = "Show do TDCC";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
        SECTION("3") {
            val = "Show do fFooFighters";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
        SECTION("4") {
            val = "123456789e9876543219";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
    }
    SECTION("Excessão") {
        SECTION("1") {
            val = "Sem ideias  por aqui";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
        SECTION("2") {
            val = "01234567891011121314";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
        SECTION("3") {
            val = "This should fail  1234";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
        SECTION("4") {
            val = "UMA MAIORZONA PRA TESTAR";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
    }
}

TEST_CASE("Dominio NumeroDeSala") {
    std::string val;
    NumeroDeSala uniTest;
    SECTION("Certo") {
        SECTION("1") {
            val = "5";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
    }
    SECTION("Excessão") {
        SECTION("1") {
            val = "-4";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
        SECTION("2") {
            val = "14";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
    }
}

TEST_CASE("Dominio Disponibilidade") {
    std::string val;
    Disponibilidade uniTest;
    SECTION("Certo") {
        SECTION("1") {
            val = "176";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
    }
    SECTION("Excessão") {
        SECTION("1") {
            val = "-340";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
        SECTION("2") {
            val = "549";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
    }
}

TEST_CASE("Dominio FaixaEtaria") {
    std::string val;
    FaixaEtaria uniTest;
    SECTION("Certo") {
        SECTION("1") {
            val = "L";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
        SECTION("2") {
            val = "10";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
        SECTION("3") {
            val = "12";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
        SECTION("4") {
            val = "14";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
        SECTION("5") {
            val = "16";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
        SECTION("6") {
            val = "18";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
    }
    SECTION("Excessão") {
        SECTION("1") {
            val = "M";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
        SECTION("2") {
            val = "13";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
    }
}

TEST_CASE("Dominio Horario") {
    std::string val;
    Horario uniTest;
    SECTION("Certo") {
        SECTION("1") {
            val = "19:00";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
        SECTION("2") {
            val = "07:15";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
        SECTION("3") {
            val = "10:30";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
        SECTION("4") {
            val = "14:45";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
    }
    SECTION("Excessão") {
        SECTION("1") {
            val = "06:00";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
        SECTION("2") {
            val = "08:28";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
        SECTION("3") {
            val = "23:30";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
    }
}

TEST_CASE("Dominio Preco") {
    std::string val;
    Preco uniTest;
    SECTION("Certo") {
        SECTION("1") {
            val = "120.00";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
        SECTION("2") {
            val = "760.97";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
    }
    SECTION("Excessão") {
        SECTION("1") {
            val = "-120.00";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
        SECTION("2") {
            val = "10000.08";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
    }
}

TEST_CASE("Dominio Data") {
    std::string val;
    Data uniTest;
    SECTION("Certo") {
        SECTION("1") {
            val = "22/01/01";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
        SECTION("2") {
            val = "29/02/20";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
    }
    SECTION("Excessão") {
        SECTION("1") {
            val = "88/01/98";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
        SECTION("2") {
            val = "21/32/03";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
        SECTION("3") {
            val = "00/01/98";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
        SECTION("4") {
            val = "29/02/01";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
        SECTION("5") {
            val = "5/4/49";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
    }
}

TEST_CASE("Dominio CVV") {
    std::string val;
    CVV uniTest;
    SECTION("Certo") {
        SECTION("1") {
            val = "897";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
        SECTION("2") {
            val = "000";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
        SECTION("3") {
            val = "999";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
    }
    SECTION("Excessão") {
        SECTION("1") {
            val = "4321";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
        SECTION("2") {
            val = "24";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
        SECTION("3") {
            val = "-788";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
    }
}

TEST_CASE("Dominio DataDeValidade") {
    std::string val;
    DataDeValidade uniTest;
    SECTION("Certo") {
        SECTION("1") {
            val = "01/01";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
        SECTION("2") {
            val = "02/20";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
        SECTION("3") {
            val = "12/99";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
    }
    SECTION("Excessão") {
        SECTION("1") {
            val = "00/00";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
        SECTION("2") {
            val = "5/4";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
        SECTION("3") {
            val = "02/9";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
        SECTION("4") {
            val = "3/05";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
        SECTION("5") {
            val = "34/49";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
    }
}

TEST_CASE("Dominio Estado") {
    std::string val;
    Estado uniTest;
    SECTION("Certo") {
        SECTION("1") {
            val = "BA";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
        SECTION("2") {
            val = "DF";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
        SECTION("3") {
            val = "SP";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
    }
    SECTION("Excessão") {
        SECTION("1") {
            val = "GG";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
        SECTION("2") {
            val = "3";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
        SECTION("3") {
            val = "FUK";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
    }
}

// -------------------------Teste Cidade-----------------------------
TEST_CASE("Dominio Cidade") {
    std::string val;
    Cidade uniTest;
    SECTION("Certo") {
        SECTION("1") {
            val = "Valinhos";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
        SECTION("2") {
            val = "Muzambinho.";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
        SECTION("3") {
            val = "Jambo do norte";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
        SECTION("4") {
            val = "Constantinopla.";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
    }
    SECTION("Excessão") {
        SECTION("1") {
            val = "abacate  legal";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
        SECTION("2") {
            val = "jorger&.";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
        SECTION("3") {
            val = "aaaaaaaaaaaaaaaaaaaaa";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
        SECTION("4") {
            val = "123456789101112";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
    }
}

// ---------------------Teste Senha-------------------------

TEST_CASE("Dominio Senha") {
    std::string val;
    Senha uniTest;
    SECTION("Certo") {
        SECTION("1") {
            val = "AbC123";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
        SECTION("2") {
            val = "P0popo";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
        SECTION("3") {
            val = "5432Io";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
        SECTION("4") {
            val = "JAC4Bo";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
    }
    SECTION("Excessão") {
        SECTION("1") {
            val = "semma1";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
        SECTION("2") {
            val = "SEMM1N";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
        SECTION("3") {
            val = "SemDig";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
        SECTION("4") {
            val = "#charE";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
        SECTION("5") {
            val = "AAAAAAAaaaaaaa4444444";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
        SECTION("6") {
            val = "Aa4";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
    }
}

// -----------------------ClasseDeEvento-----------------------------

TEST_CASE("Dominio ClasseDeEvento") {
    std::string val;
    ClasseDeEvento uniTest;
    SECTION("Certo") {
        SECTION("1") {
            val = "2";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
    }
    SECTION("Excessão") {
        SECTION("1") {
            val = "r";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
        SECTION("2") {
            val = "43";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
    }
}





// -----------------------CartaoDeCredito-----------------------------
TEST_CASE("Dominio NumCartaoCredito") {
    std::string val;
    NumCartaoCredito uniTest;
    SECTION("Certo") {
        SECTION("1") {
            val = "5307272897032722";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
    }
    SECTION("Excessão") {
        SECTION("1") {
            val = "1234567891011129";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
        SECTION("2") {
            val = "a";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
    }
}


// -----------------------ModelDominio-----------------------------
/*
TEST_CASE("Classe x") {
    std::string val;
    x uniTest;
    SECTION("Certo") {
        SECTION("1") {
            val = "";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) == VALIDO);
            }
        }
    }
    SECTION("Excessão") {
        SECTION("1") {
            val = "";
            try {
                uniTest.setConteudo(val);
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            } catch (const std::invalid_argument& erro) {
                REQUIRE(uniTest.getConteudo().compare(val) != VALIDO);
            }
        }
    }
}
*/
//---------------------------------------------------------------



//-------------------------------------------------------------Entidades

//---------------------------Usuario-----------------------------

TEST_CASE("Entidade Usuario") {
    Usuario entidade;
    SECTION("Atributo CPF") {
        std::string val("10279735073");
        
        CPF temp;
        temp.setConteudo(val);

        entidade.SetCPF(temp);

        REQUIRE(entidade.GetCPF().getConteudo().compare(val) == VALIDO);

    }

    SECTION("Atributo Senha") {
        std::string val("AbC123");
        
        Senha temp;
        temp.setConteudo(val);

        entidade.SetSenha(temp);

        REQUIRE(entidade.GetSenha().getConteudo().compare(val) == VALIDO);

    }
}


//---------------------------------Evento--------------------------------------

TEST_CASE("Entidade Evento") {
    Evento entidade;
    SECTION("Atributo CodigoDeEvento") {
        std::string val("123");
        
        CodigoDeEvento temp;
        temp.setConteudo(val);

        entidade.SetCodigoDeEvento(temp);

        REQUIRE(entidade.GetCodigoDeEvento().getConteudo().compare(val) == VALIDO);

    }
    SECTION("Atributo NomeDeEvento") {
        std::string val("Show do Jack Johnson");
        
        NomeDeEvento temp;
        temp.setConteudo(val);

        entidade.SetNomeDeEvento(temp);

        REQUIRE(entidade.GetNomeDeEvento().getConteudo().compare(val) == VALIDO);

    }
    SECTION("Atributo Cidade") {
        std::string val("Valinhos");
        
        Cidade temp;
        temp.setConteudo(val);

        entidade.SetCidade(temp);

        REQUIRE(entidade.GetCidade().getConteudo().compare(val) == VALIDO);

    }
    SECTION("Atributo Estado") {
        std::string val("DF");
        
        Estado temp;
        temp.setConteudo(val);

        entidade.SetEstado(temp);

        REQUIRE(entidade.GetEstado().getConteudo().compare(val) == VALIDO);

    }
    SECTION("Atributo ClasseDeEvento") {
        std::string val("2");
        
        ClasseDeEvento temp;
        temp.setConteudo(val);

        entidade.SetClasseDeEvento(temp);

        REQUIRE(entidade.GetClasseDeEvento().getConteudo().compare(val) == VALIDO);

    }
    SECTION("Atributo FaixaEtaria") {
        std::string val("L");
        
        FaixaEtaria temp;
        temp.setConteudo(val);

        entidade.SetFaixaEtaria(temp);

        REQUIRE(entidade.GetFaixaEtaria().getConteudo().compare(val) == VALIDO);

    }
}



//-------------------------------Apresentacao----------------------------------

TEST_CASE("Entidade Apresentacao") {
    Apresentacao entidade;
    SECTION("Atributo CodigoDeApresentacao") {
        std::string val("9783");
        
        CodigoDeApresentacao temp;
        temp.setConteudo(val);

        entidade.SetCodigoDeApresentacao(temp);

        REQUIRE(entidade.GetCodigoDeApresentacao().getConteudo().compare(val) == VALIDO);

    }
    SECTION("Atributo Data") {
        std::string val("22/01/01");
        
        Data temp;
        temp.setConteudo(val);

        entidade.SetData(temp);

        REQUIRE(entidade.GetData().getConteudo().compare(val) == VALIDO);

    }
    SECTION("Atributo Horario") {
        std::string val("19:00");
        
        Horario temp;
        temp.setConteudo(val);

        entidade.SetHorario(temp);

        REQUIRE(entidade.GetHorario().getConteudo().compare(val) == VALIDO);

    }
    SECTION("Atributo Preco") {
        std::string val("120.00");
        
        Preco temp;
        temp.setConteudo(val);

        entidade.SetPreco(temp);

        REQUIRE(entidade.GetPreco().getConteudo().compare(val) == VALIDO);

    }
    SECTION("Atributo NumeroDeSala") {
        std::string val("5");
        
        NumeroDeSala temp;
        temp.setConteudo(val);

        entidade.SetNumeroDeSala(temp);

        REQUIRE(entidade.GetNumeroDeSala().getConteudo().compare(val) == VALIDO);

    }
    SECTION("Atributo Disponibilidade") {
        std::string val("176");
        
        Disponibilidade temp;
        temp.setConteudo(val);

        entidade.SetDisponibilidade(temp);

        REQUIRE(entidade.GetDisponibilidade().getConteudo().compare(val) == VALIDO);

    }
}




//----------------------------Ingresso-------------------------


TEST_CASE("Entidade Ingresso") {
    Ingresso entidade;
    SECTION("Atributo CodigoDeIngresso") {
        std::string val("97832");
        
        CodigoDeIngresso temp;
        temp.setConteudo(val);

        entidade.SetCodigoDeIngresso(temp);

        REQUIRE(entidade.GetCodigoDeIngresso().getConteudo().compare(val) == VALIDO);

    }
}



TEST_CASE("Entidade CartaoDeCredito") {
    CartaoDeCredito entidade;
    SECTION("Atributo NumCartaoCredito") {
        std::string val("5307272897032722");
        
        NumCartaoCredito temp;
        temp.setConteudo(val);

        entidade.SetNumCartaoCredito(temp);

        REQUIRE(entidade.GetNumCartaoCredito().getConteudo().compare(val) == VALIDO);

    }
    SECTION("Atributo CVV") {
        std::string val("897");
        
        CVV temp;
        temp.setConteudo(val);

        entidade.SetCVV(temp);

        REQUIRE(entidade.GetCVV().getConteudo().compare(val) == VALIDO);

    }
    SECTION("Atributo DataDeValidade") {
        std::string val("01/01");
        
        DataDeValidade temp;
        temp.setConteudo(val);

        entidade.SetDataDeValidade(temp);

        REQUIRE(entidade.GetDataDeValidade().getConteudo().compare(val) == VALIDO);

    }
}


//--------------------ModelEntidade------------------------------
/*
TEST_CASE("Entidade X") {
    X entidade;
    SECTION("Atributo Y") {
        std::string val("");
        
        Y temp;
        temp.setConteudo(val);

        entidade.SetY(temp);

        REQUIRE(entidade.GetY().getConteudo().compare(val) == VALIDO);

    }
}
*/


#endif  //DEBUG

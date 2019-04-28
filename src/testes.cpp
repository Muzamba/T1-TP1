// Copyright Ariel e João Pedro
#define CATCH_CONFIG_MAIN
#include <iostream>
#include <string>
#include "catch.hpp"
#include "dominios.h"
#define VALIDO 0

// --------------------------------Teste-CPF------------------------------------
TEST_CASE("Classe CPF") {
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
TEST_CASE("Classe CodigoDeEvento") {
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
TEST_CASE("Classe CodigoDeApresentacao") {
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
TEST_CASE("Classe CodigoDeIngresso") {
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
TEST_CASE("Classe NomeDeEvento") {
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

TEST_CASE("Classe NumeroDeSala") {
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

TEST_CASE("Classe Disponibilidade") {
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

TEST_CASE("Classe FaixaEtaria") {
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

TEST_CASE("Classe Horario") {
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

TEST_CASE("Classe Preco") {
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

TEST_CASE("Classe Data") {
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

TEST_CASE("Classe CVV") {
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

TEST_CASE("Classe DataDeValidade") {
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

TEST_CASE("Classe Estado") {
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
TEST_CASE("Classe Cidade") {
    std::string val;
    Cidade uniTest;
    SECTION("Tudo certo por aqui") {
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
    SECTION("Problemáticos") {
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

TEST_CASE("Classe Senha") {
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

TEST_CASE("Classe ClasseDeEvento") {
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
TEST_CASE("Classe NumCartaoCredito") {
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

// -----------------------Model-----------------------------
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

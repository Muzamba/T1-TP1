// Copyright Ariel e João Pedro
#define CATCH_CONFIG_MAIN
#include <iostream>
#include <string>
#include "catch.hpp"
#include "dominios.h"
#define VALIDO 0

//--------------------------------Teste-CPF------------------------------------
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
    SECTION("Exessao") {
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

/*
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
            REQUIRE(valido.getConteudo().compare(cpf_valido) == VALIDO);
        } catch (std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(valido.getConteudo().compare(cpf_valido) == VALIDO);
        }
    }

    SECTION("Problemáticos") {
        try {
            invalido.setConteudo(cpf_invalido1);
            REQUIRE(invalido.getConteudo().compare(cpf_invalido1) != VALIDO);
        } catch (const std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(invalido.getConteudo().compare(cpf_invalido1) != VALIDO);
        }

        try {
            invalido.setConteudo(cpf_invalido2);
            REQUIRE(invalido.getConteudo().compare(cpf_invalido2));
        } catch (const std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!invalido.getConteudo().compare(cpf_invalido2));
        }
    }
}
*/ 

//------------------------Teste-Codigo-de-Evento-------------------------------o
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
    SECTION("Exessao") {
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
/*
TEST_CASE("Classe CodigoDeEvento") {
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
            REQUIRE(valido.getConteudo().size());
        }
    }

    SECTION("Problemáticos") {
        try {
            invalido.setConteudo(codigo_invalido1);
            REQUIRE(invalido.getConteudo().compare(codigo_invalido1));
        } catch (const std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!invalido.getConteudo().size());
        }

        try {
            invalido.setConteudo(codigo_invalido2);
            REQUIRE(invalido.getConteudo().compare(codigo_invalido2));
        } catch (const std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!invalido.getConteudo().size());
        }

        try {
            invalido.setConteudo(codigo_invalido3);
            REQUIRE(invalido.getConteudo().compare(codigo_invalido3));
        } catch (const std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!invalido.getConteudo().size());
        }
    }
}
*/






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
    SECTION("Exessao") {
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

/*

TEST_CASE("Classe CodigoDeApresentacao") {

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
            REQUIRE(valido.getConteudo().size());
        }
    }

    SECTION("Problemáticos") {
        try {
            invalido.setConteudo(codigo_invalido1);
            REQUIRE(invalido.getConteudo().compare(codigo_invalido1));
        } catch (const std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!invalido.getConteudo().size());
        }

        try {
            invalido.setConteudo(codigo_invalido2);
            REQUIRE(invalido.getConteudo().compare(codigo_invalido2));
        } catch (const std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!invalido.getConteudo().size());
        }

        try {
            invalido.setConteudo(codigo_invalido3);
            REQUIRE(invalido.getConteudo().compare(codigo_invalido3));
        } catch (const std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!invalido.getConteudo().size());
        }
    }
}
*/


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
    SECTION("Exessao") {
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

/*

TEST_CASE("Classe CodigoDeIngresso") {

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
            REQUIRE(valido.getConteudo().size());
        }
    }

    SECTION("Problemáticos") {
        try {
            invalido.setConteudo(codigo_invalido1);
            REQUIRE(invalido.getConteudo().compare(codigo_invalido1));
        } catch (const std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!invalido.getConteudo().size());
        }

        try {
            invalido.setConteudo(codigo_invalido2);
            REQUIRE(invalido.getConteudo().compare(codigo_invalido2));
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
*/

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
    SECTION("Exessao") {
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

/*
TEST_CASE("Classe NomeDeEvento") {

    std::string nome_valido1("Show do Jack Johnson");
    std::string nome_valido2("Show do TDCC");
    std::string nome_valido3("Show do fFooFighters");
    std::string nome_valido4("123456789e9876543219");

    std::string nome_invalido1("Sem ideias  por aqui");
    std::string nome_invalido2("01234567891011121314");
    std::string nome_invalido3("This should fail  1234");
    std::string nome_invalido4("UMA MAIORZONA PRA TESTAR");

    NomeDeEvento valido;
    NomeDeEvento invalido;

    // std::cout << "\n------ Testes da classe NomeDeEvento ------\n"
    // << std::endl;

    SECTION("Tudo certo por aqui") {
        try {
            valido.setConteudo(nome_valido1);
            REQUIRE(!valido.getConteudo().compare(nome_valido1));
        } catch (const std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(valido.getConteudo().size());
        }
        try {
            valido.setConteudo(nome_valido2);
            REQUIRE(!valido.getConteudo().compare(nome_valido2));
        } catch (std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(valido.getConteudo().size());
        }
        try {
            valido.setConteudo(nome_valido3);
            REQUIRE(!valido.getConteudo().compare(nome_valido3));
        } catch (std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(valido.getConteudo().size());
        }
        try {
            valido.setConteudo(nome_valido4);
            REQUIRE(!valido.getConteudo().compare(nome_valido4));
        } catch (std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(valido.getConteudo().size());
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
*/

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
    SECTION("Exessao") {
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


/*
TEST_CASE("Classe NumeroDeSala") {
    SECTION("Tudo certo por aqui") {
        std::string numero_valido("5");
        NumeroDeSala valido;
        try {
            valido.setConteudo(numero_valido);
            REQUIRE(!valido.getConteudo().compare(numero_valido));
        } catch (const std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(valido.getConteudo().size());
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
*/


TEST_CASE("Classe Disponibilidade") {
    SECTION("Tudo certo por aqui") {
        std::string numero_valido("176");
        Disponibilidade valido;
        try {
            valido.setConteudo(numero_valido);
            REQUIRE(!valido.getConteudo().compare(numero_valido));
        } catch (const std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(valido.getConteudo().size());
        }
    }

    SECTION("Problemáticos") {
        std::string numero_invalido1("-340");
        std::string numero_invalido2("549");
        Disponibilidade invalido;
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

TEST_CASE("Classe FaixaEtaria") {
    SECTION("Tudo certo por aqui") {
        std::string faixa_valido1("L");
        std::string faixa_valido2("10");
        std::string faixa_valido3("12");
        std::string faixa_valido4("14");
        std::string faixa_valido5("16");
        std::string faixa_valido6("18");
        FaixaEtaria valido;

        try {
            valido.setConteudo(faixa_valido1);
            REQUIRE(!valido.getConteudo().compare(faixa_valido1));
        } catch (const std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(valido.getConteudo().size());
        }
        try {
            valido.setConteudo(faixa_valido2);
            REQUIRE(!valido.getConteudo().compare(faixa_valido2));
        } catch (const std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(valido.getConteudo().size());
        }
        try {
            valido.setConteudo(faixa_valido3);
            REQUIRE(!valido.getConteudo().compare(faixa_valido3));
        } catch (const std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(valido.getConteudo().size());
        }
        try {
            valido.setConteudo(faixa_valido4);
            REQUIRE(!valido.getConteudo().compare(faixa_valido4));
        } catch (const std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(valido.getConteudo().size());
        }
        try {
            valido.setConteudo(faixa_valido5);
            REQUIRE(!valido.getConteudo().compare(faixa_valido5));
        } catch (const std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(valido.getConteudo().size());
        }
        try {
            valido.setConteudo(faixa_valido6);
            REQUIRE(!valido.getConteudo().compare(faixa_valido6));
        } catch (const std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(valido.getConteudo().size());
        }
    }

    SECTION("Problemáticos") {
        std::string faixa_invalido1("M");
        std::string faixa_invalido2("13");
        FaixaEtaria invalido;

        try {
            invalido.setConteudo(faixa_invalido1);
             REQUIRE(!invalido.getConteudo().compare(faixa_invalido1));
        } catch (const std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!invalido.getConteudo().size());
        }
        try {
            invalido.setConteudo(faixa_invalido2);
             REQUIRE(!invalido.getConteudo().compare(faixa_invalido2));
        } catch (const std::invalid_argument& erro) {
            // std::cout << "ERRO! Motivo -> " << erro.what() << std::endl;
            REQUIRE(!invalido.getConteudo().size());
        }
    }
}

TEST_CASE("Classe Horario") {
    SECTION("Tudo certo por aqui") {
        std::string horario_valido1("19:00");
        std::string horario_valido2("07:15");
        std::string horario_valido3("10:30");
        std::string horario_valido4("14:45");
        Horario valido;

        try {
            valido.setConteudo(horario_valido1);
            REQUIRE(!valido.getConteudo().compare(horario_valido1));
        } catch (const std::invalid_argument& erro) {
            REQUIRE(valido.getConteudo().compare(horario_valido1));
        }
        try {
            valido.setConteudo(horario_valido2);
            REQUIRE(!valido.getConteudo().compare(horario_valido2));
        } catch (const std::invalid_argument& erro) {
            REQUIRE(valido.getConteudo().size());
        }
        try {
            valido.setConteudo(horario_valido3);
            REQUIRE(!valido.getConteudo().compare(horario_valido3));
        } catch (const std::invalid_argument& erro) {
            REQUIRE(valido.getConteudo().size());
        }
        try {
            valido.setConteudo(horario_valido4);
            REQUIRE(!valido.getConteudo().compare(horario_valido4));
        } catch (const std::invalid_argument& erro) {
            REQUIRE(valido.getConteudo().size());
        }
    }

    SECTION("Problemáticos") {
        std::string horario_invalido1("06:00");
        std::string horario_invalido2("08:28");
        std::string horario_invalido3("23:30");
        Horario invalido;

        try {
            invalido.setConteudo(horario_invalido1);
            REQUIRE(!invalido.getConteudo().compare(horario_invalido1));
        } catch (const std::invalid_argument& erro) {
            REQUIRE(!invalido.getConteudo().size());
        }
        try {
            invalido.setConteudo(horario_invalido2);
            REQUIRE(!invalido.getConteudo().compare(horario_invalido2));
        } catch (const std::invalid_argument& erro) {
            REQUIRE(!invalido.getConteudo().size());
        }
        try {
            invalido.setConteudo(horario_invalido2);
            REQUIRE(!invalido.getConteudo().compare(horario_invalido2));
        } catch (const std::invalid_argument& erro) {
            REQUIRE(!invalido.getConteudo().size());
        }
    }
}

TEST_CASE("Classe Preco") {
    SECTION("Tudo certo por aqui") {
        std::string preco_valido1("120.00");
        std::string preco_valido2("760.97");
        Preco valido;

        try {
            valido.setConteudo(preco_valido1);
            REQUIRE(!valido.getConteudo().compare(preco_valido1));
        } catch (const std::invalid_argument& erro) {
            REQUIRE(valido.getConteudo().size());
        }
        try {
            valido.setConteudo(preco_valido2);
            REQUIRE(!valido.getConteudo().compare(preco_valido2));
        } catch (const std::invalid_argument& erro) {
            REQUIRE(valido.getConteudo().size());
        }
    }

    SECTION("Problematicos") {
        std::string preco_invalido1("-120.00");
        std::string preco_invalido2("10000.08");
        Preco invalido;

        try {
            invalido.setConteudo(preco_invalido1);
            REQUIRE(!invalido.getConteudo().compare(preco_invalido1));
        } catch (const std::invalid_argument& erro) {
            REQUIRE(!invalido.getConteudo().size());
        }
        try {
            invalido.setConteudo(preco_invalido2);
            REQUIRE(!invalido.getConteudo().compare(preco_invalido2));
        } catch (const std::invalid_argument& erro) {
            REQUIRE(!invalido.getConteudo().size());
        }
    }
}

TEST_CASE("Classe Data") {
    SECTION("Tudo certo por aqui") {
        std::string data_valida1("22/01/01");
        std::string data_valida2("29/02/20");
        Data valida;

        try {
            valida.setConteudo(data_valida1);
            REQUIRE(!valida.getConteudo().compare(data_valida1));
        } catch (const std::invalid_argument& erro) {
            REQUIRE(!valida.getConteudo().size());
        }
        try {
            valida.setConteudo(data_valida2);
            REQUIRE(!valida.getConteudo().compare(data_valida2));
        } catch (const std::invalid_argument& erro) {
            REQUIRE(!valida.getConteudo().size());
        }
    }

    SECTION("Problemáticos") {
        std::string data_invalida1("88/01/98");
        std::string data_invalida2("21/32/03");
        std::string data_invalida3("00/01/98");
        std::string data_invalida4("29/02/01");
        std::string data_invalida5("5/4/49");
        Data invalida;

        try {
            invalida.setConteudo(data_invalida1);
            REQUIRE(!invalida.getConteudo().compare(data_invalida1));
        } catch (const std::invalid_argument& erro) {
            REQUIRE(!invalida.getConteudo().size());
        }
        try {
            invalida.setConteudo(data_invalida2);
            REQUIRE(!invalida.getConteudo().compare(data_invalida2));
        } catch (const std::invalid_argument& erro) {
            REQUIRE(!invalida.getConteudo().size());
        }
        try {
            invalida.setConteudo(data_invalida3);
            REQUIRE(!invalida.getConteudo().compare(data_invalida3));
        } catch (const std::invalid_argument& erro) {
            REQUIRE(!invalida.getConteudo().size());
        }
        try {
            invalida.setConteudo(data_invalida4);
            REQUIRE(!invalida.getConteudo().compare(data_invalida4));
        } catch (const std::invalid_argument& erro) {
            REQUIRE(!invalida.getConteudo().size());
        }
        try {
            invalida.setConteudo(data_invalida5);
            REQUIRE(!invalida.getConteudo().compare(data_invalida5));
        } catch (const std::invalid_argument& erro) {
            REQUIRE(!invalida.getConteudo().size());
        }
    }
}

TEST_CASE("Classe CVV") {
    SECTION("Tudo certo por aqui") {
        std::string cvv_valido1("897");
        std::string cvv_valido2("000");
        std::string cvv_valido3("999");
        CVV valido;

        try {
            valido.setConteudo(cvv_valido1);
            REQUIRE(!valido.getConteudo().compare(cvv_valido1));
        } catch (const std::invalid_argument& erro) {
            REQUIRE(valido.getConteudo().size());
        }
        try {
            valido.setConteudo(cvv_valido2);
            REQUIRE(!valido.getConteudo().compare(cvv_valido2));
        } catch (const std::invalid_argument& erro) {
            REQUIRE(valido.getConteudo().size());
        }
        try {
            valido.setConteudo(cvv_valido3);
            REQUIRE(!valido.getConteudo().compare(cvv_valido3));
        } catch (const std::invalid_argument& erro) {
            REQUIRE(valido.getConteudo().size());
        }
    }

    SECTION("Problemáticos") {
        std::string cvv_invalido1("1234");
        std::string cvv_invalido2("24");
        std::string cvv_invalido3("-778");
        CVV invalido;

        try {
            invalido.setConteudo(cvv_invalido1);
            REQUIRE(!invalido.getConteudo().compare(cvv_invalido1));
        } catch (const std::invalid_argument& erro) {
            REQUIRE(!invalido.getConteudo().size());
        }
        try {
            invalido.setConteudo(cvv_invalido2);
            REQUIRE(!invalido.getConteudo().compare(cvv_invalido2));
        } catch (const std::invalid_argument& erro) {
            REQUIRE(!invalido.getConteudo().size());
        }
        try {
            invalido.setConteudo(cvv_invalido3);
            REQUIRE(!invalido.getConteudo().compare(cvv_invalido3));
        } catch (const std::invalid_argument& erro) {
            REQUIRE(!invalido.getConteudo().size());
        }
    }
}

TEST_CASE("Classe DataDeValidade") {
    SECTION("Tudo certo por aqui") {
        std::string data_valida1("01/01");
        std::string data_valida2("02/20");
        std::string data_valida3("12/99");
        DataDeValidade valida;

        try {
            valida.setConteudo(data_valida1);
            REQUIRE(!valida.getConteudo().compare(data_valida1));
        } catch (const std::invalid_argument& erro) {
            REQUIRE(!valida.getConteudo().size());
        }
        try {
            valida.setConteudo(data_valida2);
            REQUIRE(!valida.getConteudo().compare(data_valida2));
        } catch (const std::invalid_argument& erro) {
            REQUIRE(!valida.getConteudo().size());
        }
        try {
            valida.setConteudo(data_valida3);
            REQUIRE(!valida.getConteudo().compare(data_valida3));
        } catch (const std::invalid_argument& erro) {
            REQUIRE(!valida.getConteudo().size());
        }
    }

    SECTION("Problemáticos") {
        std::string data_invalida1("00/00");
        std::string data_invalida2("5/4");
        std::string data_invalida3("02/9");
        std::string data_invalida4("3/05");
        std::string data_invalida5("34/49");
        DataDeValidade invalida;

        try {
            invalida.setConteudo(data_invalida1);
            REQUIRE(!invalida.getConteudo().compare(data_invalida1));
        } catch (const std::invalid_argument& erro) {
            REQUIRE(!invalida.getConteudo().size());
        }
        try {
            invalida.setConteudo(data_invalida2);
            REQUIRE(!invalida.getConteudo().compare(data_invalida2));
        } catch (const std::invalid_argument& erro) {
            REQUIRE(!invalida.getConteudo().size());
        }
        try {
            invalida.setConteudo(data_invalida3);
            REQUIRE(!invalida.getConteudo().compare(data_invalida3));
        } catch (const std::invalid_argument& erro) {
            REQUIRE(!invalida.getConteudo().size());
        }
        try {
            invalida.setConteudo(data_invalida4);
            REQUIRE(!invalida.getConteudo().compare(data_invalida4));
        } catch (const std::invalid_argument& erro) {
            REQUIRE(!invalida.getConteudo().size());
        }
        try {
            invalida.setConteudo(data_invalida5);
            REQUIRE(!invalida.getConteudo().compare(data_invalida5));
        } catch (const std::invalid_argument& erro) {
            REQUIRE(!invalida.getConteudo().size());
        }
    }
}

TEST_CASE("Classe Estado") {
    SECTION("Tudo certo por aqui") {
        std::string estado_valido1("BA");
        std::string estado_valido2("MA");
        std::string estado_valido3("DF");
        Estado valido;

        try {
            valido.setConteudo(estado_valido1);
            REQUIRE(!valido.getConteudo().compare(estado_valido1));
        } catch (const std::invalid_argument& erro) {
            REQUIRE(valido.getConteudo().size());
        }
        try {
            valido.setConteudo(estado_valido2);
            REQUIRE(!valido.getConteudo().compare(estado_valido2));
        } catch (const std::invalid_argument& erro) {
            REQUIRE(valido.getConteudo().size());
        }
        try {
            valido.setConteudo(estado_valido3);
            REQUIRE(!valido.getConteudo().compare(estado_valido3));
        } catch (const std::invalid_argument& erro) {
            REQUIRE(valido.getConteudo().size());
        }
    }

    SECTION("Problemáticos") {
        std::string estado_invalido1("GG");
        std::string estado_invalido2("3");
        std::string estado_invalido3("EFG");
        Estado invalido;

        try {
            invalido.setConteudo(estado_invalido1);
            REQUIRE(invalido.getConteudo().compare(estado_invalido1));
        } catch (const std::invalid_argument& erro) {
            REQUIRE(!invalido.getConteudo().compare(estado_invalido1));
        }
        try {
            invalido.setConteudo(estado_invalido2);
            REQUIRE(invalido.getConteudo().compare(estado_invalido2));
        } catch (const std::invalid_argument& erro) {
            REQUIRE(!invalido.getConteudo().compare(estado_invalido2));
        }
        try {
            invalido.setConteudo(estado_invalido3);
            REQUIRE(invalido.getConteudo().compare(estado_invalido3));
        } catch (const std::invalid_argument& erro) {
            REQUIRE(!invalido.getConteudo().compare(estado_invalido3));
        }
    }
}

//-------------------------Teste Cidade-----------------------------
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

//---------------------Teste Senha-------------------------

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
    SECTION("Exessao") {
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




//-----------------------Model-----------------------------
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
    SECTION("Exessao") {
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

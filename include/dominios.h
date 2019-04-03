// Copyright Ariel e João Pedro
#ifndef INCLUDE_DOMINIOS_H_
#define INCLUDE_DOMINIOS_H_
#include <string>
#include <stdexcept>

class Super {
 protected:
    std::string conteudo;
    virtual void validar(std::string) = 0;
 public:
    void setConteudo(std::string conteudo);
    std::string getConteudo() {
        return conteudo;
    }
};

class CodigoDeEvento : public Super {
 private:
    void validar(std::string) override;
};

class CodigoDeApresentacao : public Super {
 private:
    void validar(std::string) override;
};

class CodigoDeIngresso : public Super {
 private:
    void validar(std::string) override;
};

class NomeDeEvento : public Super {
 private:
    void validar(std::string) override;
};

class Data : public Super {
 private:
    void validar(std::string) override;
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

// Decidir com o Ariel como implementar (ints, str ou enum?)
/*class ClasseDeEvento {
 private:

 public:
};*/

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

 public:
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

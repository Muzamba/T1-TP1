// Copyright Ariel e João Pedro
#ifndef INCLUDE_DOMINIOS_H_
#define INCLUDE_DOMINIOS_H_
#include <string>

class CodigoDeEvento {
 private:
    std::string codigo;
    bool validar();

 public:
    CodigoDeEvento();
    explicit CodigoDeEvento(int codigo);
    void setCodigo(std::string codigo);
    inline std::string getCodigo();
};

class CodigoDeApresentacao {
 private:
    std::string codigo;
    bool validar();

 public:
    CodigoDeApresentacao();
    explicit CodigoDeApresentacao(int codigo);
    void setCodigo(std::string codigo);
    inline std::string getCodigo();
};

class CodigoDeIngresso {
 private:
    std::string codigo;
    bool validar();

 public:
    CodigoDeIngresso();
    explicit CodigoDeIngresso(int codigo);
    void setCodigo(std::string codigo);
    inline std::string getCodigo();
};

class NomeDeEvento {
 private:
    std::string nome;
    bool validar();

 public:
    NomeDeEvento();
    explicit NomeDeEvento(std::string nome);
    void setNome(std::string nome);
    inline std::string getNome();
};

class Data {
 private:
    std::string data;
    bool validar();

 public:
    Data();
    explicit Data(std::string data);
    void setData(std::string data);
    inline std::string getData();
};

class Horario {
 private:
    std::string hora;
    bool validar();

 public:
    Horario();
    explicit Horario(std::string hora);
    void setHora(std::string hora);
    inline std::string getHora();
};

class Preco {
 private:
    float preco;
    bool validar();

 public:
    Preco();
    explicit Preco(float preco);
    void setPreco(float preco);
    inline float getPreco();
};

class NumeroDeSala {
 private:
    std::string numSala;
    bool validar();

 public:
    NumeroDeSala();
    explicit NumeroDeSala(std::string numSala);
    void setNumSala(std::string numSala);
    inline std::string getNumSala();
};

class Cidade {
 private:
    std::string cidade;
    bool validar();

 public:
    Cidade();
    explicit Cidade(std::string cidade);
    void setCidade(std::string cidade);
    inline std::string getCidade();
};

class Estado {
 private:
    std::string estado;
    bool validar();

 public:
    Estado();
    explicit Estado(std::string estado);
    void setEstado(std::string estado);
    inline std::string getEstado();
};

class Disponibilidade {
 private:
    std::string disp;
    bool validar();

 public:
    Disponibilidade();
    explicit Disponibilidade(std::string disp);
    void setDisp(std::string disp);
    inline std::string getDisp();
};

// Decidir com o Ariel como implementar (ints, str ou enum?)
/*class ClasseDeEvento {
 private:

 public:
};*/

class FaixaEtaria {
 private:
    std::string fxEtaria;
    bool validar();

 public:
    FaixaEtaria();
    explicit FaixaEtaria(std::string fxEtaria);
    void setFxEtaria(std::string fxEtaria);
    inline std::string getFxEtaria();
};

class CPF {
 private:
    std::string cpf;
    bool validar(std::string cpf);

 public:
    CPF();
    explicit CPF(std::string cpf);
    void setCPF(std::string cpf);
    std::string getCPF() {
        return cpf;
    }
};

class Senha {
 private:
    std::string senha;
    bool validar();

 public:
    Senha();
    explicit Senha(std::string senha);
    void setSenha(std::string senha);
    inline std::string getSenha();
};

class NumCartaoCredito {
 private:
    std::string numCart;
    bool validar();

 public:
    NumCartaoCredito();
    explicit NumCartaoCredito(std::string numCart);
    void setNumCart(std::string numCart);
    inline std::string getNumCart();
};

class CVV {
 private:
    std::string cvv;
    bool validar();

 public:
    CVV();
    explicit CVV(std::string cvv);
    void setCVV(std::string cvv);
    inline std::string getCVV();
};

class DataDeValidade {
 private:
    std::string dataVal;
    bool validar();

 public:
    DataDeValidade();
    explicit DataDeValidade(std::string dataVal);
    void setDataVal(std::string dataVal);
    inline std::string getDataVal();
};


#endif  // INCLUDE_DOMINIOS_H_

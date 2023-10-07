#ifndef PRODUTO_HPP
#define PRODUTO_HPP
#include <string>
#include <float.h>

class Produto
{
private:
    std::string nome;
    float preco;
public:
    Produto();
    
    void setNome(const std::string& nome);
    void setPreco(const float& preco);
    std::string getNome() const;
    float getPreco() const;
};

void cadastrarSuco(std::string nome, float preco);
void listarSuco();
void cadastrarSanduiche(std::string nome, float preco);
void listarSanduiche();

#endif

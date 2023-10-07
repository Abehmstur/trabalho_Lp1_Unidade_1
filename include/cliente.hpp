#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <string>

class Cliente
{
private:
    std::string nome;
public:
    Cliente();
    
    void setNome(const std::string& nome);
    std::string getNome() const;
};

void cadastrarCliente(std::string nome);
void listarCliente();

#endif

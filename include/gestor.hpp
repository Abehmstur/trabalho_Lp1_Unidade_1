#ifndef GESTOR_HPP
#define GESTOR_HPP
#include <string>

class Gestor
{
private:
    std::string nome, senha="admin";
public:
    Gestor();
    
    void setNome(const std::string& nome);
    std::string getNome() const;
};

void cadastrarGestor(std::string nome);
void listarGestor();

#endif

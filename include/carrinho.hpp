#ifndef CARRINHO_HPP
#define CARRINHO_HPP

#include <string>

class Carrinho{
    private:
        std::string item;
        float preco;
    public:
        Carrinho();
        
        void setItem(const std::string& item);
        std::string getItem();
        void setPreco(const float& preco);
        float getPreco() const;
};

#endif
#include "campanha.hpp"
#include <iostream>

int main(){
    int n_seguidores, n_propostas;
    
    while(std::cin >> n_seguidores >> n_propostas){
        if(!n_seguidores && !n_propostas) break;

        Campanha c = Campanha(n_seguidores, n_propostas);
        c.read_opinions();
        if(c.can_satisfy()){
            std::cout << "sim\n";
        } else {
            std::cout << "nao\n";
        }
    }

    return 0;
}
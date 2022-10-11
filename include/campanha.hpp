#ifndef CAMPANHA_H_
#define CAMPANHA_H_

#include <iostream>
#include "grafo.hpp"

class Campanha{
    int n_seguidores, n_propostas;
    Graph* g;

    inline int APV(int x){
        return 2*(x-1);
    }

    inline int REJ(int x){
        return APV(x)+1;
    }

    public:
        Campanha(int n_seguidores, int n_propostas);
        void read_opinions();
        bool can_satisfy();
        ~Campanha();
};

#endif
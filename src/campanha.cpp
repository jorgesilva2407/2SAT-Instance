#include "campanha.hpp"

Campanha::Campanha(int n_seguidores, int n_propostas){
    this->n_seguidores = n_seguidores;
    this->n_propostas = n_propostas;
    this->g = new Graph(2*n_propostas);
}

void Campanha::read_opinions(){
    for(int i=0; i < n_seguidores; i++){
        int a1, a2, r1, r2;

        std::cin >> a1 >> a2 >> r1 >> r2;

        if(a1 && a2){
            g->new_edge(REJ(a1), APV(a2));
            g->new_edge(REJ(a2), APV(a1));
        } else if(!a1 && a2){
            g->all_edges_to(APV(a2));
        } else if(a1 && !a2){
            g->all_edges_to(APV(a1));
        }


        if(r1 && r2){
            g->new_edge(APV(r1), REJ(r2));
            g->new_edge(APV(r2), REJ(r1));
        } else if(r1 && !r2){
            g->all_edges_to(REJ(r1));
        } else if(!r1 && r2){
            g->all_edges_to(REJ(r2));
        }
    }
}

bool Campanha::can_satisfy(){
    g->find_ending_times();
    g->find_SCC();

    for(int i=0; i < n_propostas; i+=2){
        if(g->components[i] == g->components[i+1])
            return false;
    }

    return true;
}

Campanha::~Campanha(){
    delete g;
}
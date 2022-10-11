#include "grafo.hpp"

Graph::Graph(int n_nodes){
    this->n_nodes = n_nodes;
    this->nodes = new Node[n_nodes];
    this->visited = new bool[n_nodes];
    this->components = new int[n_nodes];

    for(int i=0; i < n_nodes; i++){
        visited[i] = false;
        components[i] = -1;
    }
}

void Graph::new_edge(int src, int dst){
    nodes[src].adj.push_back(dst);
    nodes[dst].trans_adj.push_back(src);
}

void Graph::all_edges_to(int dst){
    for(int i=0; i < n_nodes; i++){
        new_edge(i, dst);
    }
}

void Graph::dfs(int current){
    visited[current] = true;

    for(unsigned int i=0; i < nodes[current].adj.size(); i++){
        if(visited[nodes[current].adj[i]] == false)
            dfs(nodes[current].adj[i]);
    }

    trans_dfs_order.push(current);
    return;
}

void Graph::find_ending_times(){
    for(int i=0; i < n_nodes; i++){
        if(visited[i] == false)
            dfs(i);
    }
}

void Graph::trans_dfs(int current, int component){
    components[current] = component;

    for(unsigned int i=0; i < nodes[current].trans_adj.size(); i++){
        if(components[nodes[current].trans_adj[i]] == -1)
            trans_dfs(nodes[current].trans_adj[i], component);
    }

    return;
}

void Graph::find_SCC(){
    while(trans_dfs_order.empty() == false){
        int current = trans_dfs_order.top();
        
        if(components[current] == -1)
            trans_dfs(current, current);
        
        trans_dfs_order.pop();
    }

    // for(int i=0; i < n_nodes; i++){
    //     std::cout << components[i] << " ";
    // }
    // std::cout << std::endl;
}

Graph::~Graph(){
    delete[] nodes;
    delete visited;
    delete components;
}
#ifndef GRAFO_H_
#define GRAFO_H_

#include <vector>
#include <stack>
#include <iostream>

struct Node{
    std::vector<int> adj;
    std::vector<int> trans_adj;
};

struct Graph{
    int n_nodes;
    int* components;
    bool* visited;
    std::stack<int> trans_dfs_order;
    Node* nodes = nullptr;

    Graph(int n_nodes);
    void new_edge(int src, int dst);
    void all_edges_to(int dst);
    void dfs(int current);
    void find_ending_times();
    void trans_dfs(int current, int component);
    void find_SCC();
    ~Graph();
};

#endif
#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

class Graph {
public:
    map<int, vector<int>> adj;

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    int DLS(int v, int goal, int limit);

    int IDDFS(int src, int goal, int maxDepth);
};

int Graph::DLS(int v, int goal, int limit) {
    if (v == goal) {
        return 1;
    }
    for (auto i = adj[v].begin(); i != adj[v].end(); ++i) {
        if (limit - 1 >= 0) {
            cout<<*i<<" ";
            if (DLS(*i, goal, limit - 1) != -1)
                return 1;
        }
    }
    return -1;
}

int Graph::IDDFS(int src, int goal, int maxDepth) {
    for (int i = 0; i <= maxDepth; i++) {
        cout << "Iteration " << i << ": " << src << " ";
        if (DLS(src, goal, i) == 1) {
            return 1;
        }
        cout << endl;
    }
    return -1;
}

int main() {
    Graph gp;
    int edges, src, goal, limit;

    cout << "Enter the number of edges: ";
    cin >> edges;

    cout << "Enter the edges (format: source destination):" << endl;
    for (int i = 0; i < edges; i++) {
        int v, w;
        cin >> v >> w;
        gp.addEdge(v, w);
    }

    cout << "Enter the source node: ";
    cin >> src;

    cout << "Enter the target node: ";
    cin >> goal;

    cout << "Enter the depth limit: ";
    cin >> limit;

    if (gp.IDDFS(src, goal, limit) == 1)
        cout << "\nGoal node found within depth limit" << endl;
    else
        cout << "Goal node not found!" << endl;

    return 0;
}


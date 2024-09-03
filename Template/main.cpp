#include <iostream>
#include "DFS_Visit.h"
#include <bits/stdc++.h>
int N;

void customReadGraph() {
    cin >> N;
    cin >> startPoint;
    cin >> endPoint;
    for (int u = 1; u <= N; u++) {
        int v = 1;
        while (v != 0) {
            cin >> v;
            if (v == 0) break;
            addCanhUV(u, v);
        }
    }
    trace[startPoint] = startPoint;
}

void testDFS() {
    freopen("../dfsVisit.txt", "r",stdin);
    initGraph();
    customReadGraph();
    DFSVisit(startPoint);
    for (int i = 1; i <= N; i++)
        if (trace[i] != 0) std::cout << i << " ";
    cout << "\n";
    printPath(startPoint, endPoint);
}

int main() {
    testDFS();


    return 0;
}

//
// Created by vtx on 03/09/2024.
//

#ifndef DFS_VISIT_H
#define DFS_VISIT_H
#include <iostream>
#include <map>
#include <vector>
const int N_MAX =100'005;
using namespace std;
int startPoint=1;
int endPoint=10;
struct Data {
    Data(int _u=0, int _v=0, int _w=0) : u(_u), v(_v), weight(_w) {}
    int u,v; //u-v la 1 canh cua do thi
    int weight; //
};
map<int, vector<int>> mapConnect; //mapConnect[u]: Cac dinh ma u co the den duoc
int trace[N_MAX]; //trace[v]=u <=> Dinh v duoc xuat phat qua dinh u
/*
 * Thu tu thuc hien
 * - initGraph
 * - readGraph
 * - DFSVisit
 * - printPath //Truy vet duong di
 */
void addCanhUV(int u, int v) {
    if(mapConnect.find(u) == mapConnect.end()) {
        mapConnect.insert(make_pair(u, vector<int>(1, v)));
    }else {
        mapConnect[u].push_back(v);
    }
}
void initGraph()
{
    mapConnect.clear();
    for(int i=0; i<N_MAX; i++) {
        trace[i] = 0;
    }
}
void readGraph() {
    int N;
    cin>>N;
    cin>>startPoint;
    cin>>endPoint;
    for(int i=0; i<N; i++) {
        int u,v;
        cin>>u>>v;
        addCanhUV(u, v);
        addCanhUV(v, u);
    }
    trace[startPoint] = startPoint;
}
void printPath(int startPoint, int endPoint) {
    if(trace[endPoint] == 0) {
        cout<<"No Path from "<<startPoint<<" to "<<endPoint<<endl;
        return;
    }
    int t= endPoint;
    cout<<endPoint<<"<--";
    while(t!=startPoint) {
        cout<<trace[t];
        t=trace[t];
        if(t!=startPoint) cout<<"<--";
    }


}
void DFSVisit(int u) {
    if(mapConnect.find(u) == mapConnect.end()) {
        return;
    }
    vector<int> listV = mapConnect.at(u);
    int v;
    for(int i=0; i<listV.size(); i++) {
        v = listV[i];
        if(trace[v] == 0) {
            trace[v] = u;
            DFSVisit(v);
        }
    }
}

#endif //DFS_VISIT_H

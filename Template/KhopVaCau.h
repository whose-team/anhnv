//
// Created by anhnv on 04/09/2024.
//

#ifndef KHOPVACAU_H
#define KHOPVACAU_H
#include <bits/stdc++.h>

using namespace std;

const int maxN = 10010;

int n, m;
bool joint[maxN];
int timeDfs = 0, bridge = 0;
int low[maxN], num[maxN];
vector <int> g[maxN];

void DFS_KhopCau(int u, int pre) //pre: Đỉnh gốc của cây DFS
{
    int child = 0; // Số lượng con trực tiếp của đỉnh u trong cây DFS
    num[u] = low[u] = ++timeDfs;
    for (int v : g[u]) {
        if (v == pre) continue;
        if (!num[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]); //Duyet xong thi cap nhật low[v]
            if (low[v] == num[v]) bridge++; //Tinh cau
            //Tinh khop
            child++;
            if (u == pre) { // Nếu u là đỉnh gốc của cây DFS
                if (child > 1) joint[u] = true;
            }
            else if (low[v] >= num[u]) joint[u] = true;
        }
        else low[u] = min(low[u], num[v]);
    }
}
void initKhopCau()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}
void calculate() {
    for (int i = 1; i <= n; i++)
        if (!num[i]) dfs(i, i);
}
void printResult() {
    int cntJoint = 0;
    for (int i = 1; i <= n; i++) cntJoint += joint[i];
    cout << cntJoint << ' ' << bridge;
}
#endif //KHOPVACAU_H

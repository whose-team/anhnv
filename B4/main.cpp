#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
using namespace std;
const int nMax =100'005;
class Solusion{

    public:
        Solusion(){};
        void readData()
        {
            cin>>n>>m;
            for(int i=0;i<m;i++) {
                int u, v;
                cin>>u>>v;
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
        }
        void DFS_Cau(int u, int pre) {
            num[u]=low[u]=++timeDFS;
            for(int v:graph[u]) {
                if(v==pre) continue;
                if(!num[v]) {
                    DFS_Cau(v,u);
                    low[u]=min(low[u],low[v]);
                    if(low[v]==num[v]) bridge++;
                }else low[u]= min(low[u],num[v]);
            }
        }
        void process()
        {
            for(int i=1;i<=n;i++) num[i]=0;
            for(int i=1;i<=n;i++)
                if(!num[i]) DFS_Cau(i,i);
            cout<<"OUT: ";
            int res= bridge/2+bridge%2;
            cout<<bridge-1<<endl;
        }
    public:
        vector<int> graph[nMax];
        int n,m;
        int timeDFS =0;
        int bridge=0;
        int low[nMax], num[nMax];
};

int main(){
    int testNum=1;
    // #ifdef LOCAL
    // freopen("../input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    // cin >> testNum;
    for (int test=0; test<testNum;test++){
        Solusion solution;
        solution.readData();
        solution.process();
    }

    return 0;
}
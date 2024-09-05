#include <bits/stdc++.h>
using namespace std;
struct Data{
    Data(){}
};
class Solusion{

    public:
        Solusion(int _testIndex){
            readData();
            process();
        };
        void readData()
        {

        }
        void process()
        {

        }
    public:
    int testIndex;
        
};

int main(){
    int testNum=1;
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    // cin >> testNum;
    for (int test=0; test<testNum;test++){
        Solusion solution(test);        
    }

    return 0;
}
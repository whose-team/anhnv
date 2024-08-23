#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
using namespace std;

class Solusion{

    public:
        Solusion(){};
        void readData()
        {

        }
        void process()
        {

        }
    public:
        
};

int main(){
    int testNum=1;
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> testNum;
    for (int test=0; test<testNum;test++){
        Solusion solution;
        solution.readData();
        solution.process();
    }

    return 0;
}
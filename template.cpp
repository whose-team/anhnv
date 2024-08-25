#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
using namespace std;

class Solusion{

    public:
        Solusion(int _testIndex)
        : testIndex(_testIndex)
        {
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
    
    freopen("inputG.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    cin >> testNum;
    for (int test=0; test<testNum;test++){
        Solusion solution(test);
    }

    return 0;
}
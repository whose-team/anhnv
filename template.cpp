#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
using namespace std;
bool MULTI_TEST= false;  //Sử dụng nhiều tập test
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
    int testNum;

    if (!MULTI_TEST ){
        Solusion solution;
        solution.readData();
        solution.process();
    }else{
        cin >> testNum;
        for (int test=0; test<testNum;test++){
            Solusion solution;
            solution.readData();
            solution.process();
        }
    }
    return 0;
}
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
            cin >>inputN >> inputP >>inputQ;
            inputA.clear();
            int temp;
            for (int i=0;i<inputN;i++)
            {
                cin>>temp;
                inputA.push_back(temp);
            }
                
        }
        void process()
        {
            outResult=0;
            valueStatus.clear();
            for (int i=0;i<inputN;i++)
                valueStatus.push_back(-1);
            int currentValue = inputP;
            int tempValue=0;
            int index=0;
            while(1){
                if(index>inputN) break;
                if(index==inputN) index=0;
                if(inputA.at(index)<0) {
                    tempValue = -min(currentValue, abs(inputA.at(index)));   
                }else{tempValue=inputA.at(index);}
                currentValue+=tempValue;
                outResult++;
                if(currentValue<=inputQ){
                    break;
                }
                if(valueStatus[index]!=-1&&valueStatus[index]<=currentValue){
                    outResult=-1;
                    break;
                }
                index++;
            }
            cout<<"AAAAA: "<<endl;
            cout<<outResult<<endl;

        }
    public:
    int inputN, inputP, inputQ;
    int outResult;
    vector<int> inputA;
    vector<int> valueStatus;
        
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
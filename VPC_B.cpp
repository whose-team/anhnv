#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
bool MULTI_TEST= true;  //Sử dụng nhiều tập test
struct Data
{
    long long x;
    long long d;
};

class Solusion{
    public: Solusion(){};
    public:
        void readData()
        {
            cin>>inputC>>inputM>>inputN;
            listData.clear();
            int tempX, tempD;
            Data inputData;
            for (size_t i = 0; i < inputM; i++)
            {
                cin>>inputData.x;
                inputData.d = -1;
                listData.push_back(inputData);
            }
            for (size_t i = 0; i < inputN; i++)
            {
                cin>>inputData.x>>inputData.d;
                listData.push_back(inputData);
            }
            // cout<<"begin"<<endl;
            // for(int i=0;i<listData.size();i++){
            //     cout<<listData.at(i).x<<"    ";
            // }
            // cout<<"endl"<<endl;
            
        }
        void process()
        {
            sort(listData.begin(),listData.end(),[](const Data& DataA, const Data&  DataB){
                return DataA.x<DataB.x;
            });    
            // cout<<"begin"<<endl;
            // for(int i=0;i<listData.size();i++){
            //     cout<<listData.at(i).x<<" "<<listData.at(i).d<<"    ";
            // }
            // cout<<"endl"<<endl;
            long long outputSum = 0, currentValue=inputC;
            for(int index=0;index<listData.size();index++){
                Data item = listData.at(index);
                if(item.d<0){
                    currentValue = inputC;
                }else{
                    if(currentValue>=item.d){
                        outputSum+=item.d;
                        currentValue-=item.d;
                    }
                }
            }
            // cout<<"OUTPUT:";
            cout<<outputSum<<endl;

        }
    public:
        long long inputC, inputM, inputN;
        vector<Data> listData;

};
void init(int& testNum)
{
    cin >> testNum;
}

int main(){
    int testNum;
    

    if (!MULTI_TEST ){
        Solusion solution;
        solution.readData();
        solution.process();
    }else{
        init(testNum);
        for (int test=0; test<testNum;test++){
            Solusion solution;
            solution.readData();
            solution.process();
        }
    }
    return 0;
}
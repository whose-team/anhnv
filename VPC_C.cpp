#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
bool MULTI_TEST= false;  //Sử dụng nhiều tập test
struct Data
{
    Data(long long _c, long long _p, int _index)
        : valueC(_c), valueP(_p), index(_index)
        {}
    long long valueC, valueP;
    int index;
};
bool compair(const Data& A,const Data& B)
{
    if(A.valueC*B.valueP==A.valueP*B.valueC){
        return A.index<B.index;
    }
    return A.valueC*B.valueP<A.valueP*B.valueC;
}
class Solusion{

    public:
        Solusion(){};
        void readData()
        {
            cin>>inputN;
            int temp;
            listC.clear();
            listP.clear();
            for(int i=0;i<inputN;i++)
            {
                cin>>temp;
                listC.push_back(temp);
            }
            for(int i=0;i<inputN;i++)
            {
                cin>>temp;
                listP.push_back(temp);
            }
            listInput.clear();
            for(int i=0;i<inputN;i++)
            {
                Data item(listC.at(i),listP.at(i),i);
                listInput.push_back(item);
            }
        }
        void process()
        {
            // cout<<"Output:\n";
            // for(int i=0;i<inputN;i++)
            // {
            //     cout<<i<<": "<<listInput.at(i).valueC<<"-"<<listInput.at(i).valueP<<"==>";

            // }
            sort(listInput.begin(), listInput.end(),compair);
            // cout<<"Output:\n";
            // for(int i=0;i<inputN;i++)
            // {
            //     cout<<listInput.at(i).index<<"->";

            // }
            cout<<1<<endl;
            cout<<listInput.at(0).index+1<<endl;
        }
    public:
        int inputN;
        vector<int> listC,listP;
        vector<Data> listInput;
        
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
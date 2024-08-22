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
            long long temp;
            sum=0;
            for (long long i=0;i<inputN;i++)
            {
                cin>>temp;
                inputA.push_back(temp);
                sum+=temp;
            }
                
        }
        void process()
        {
            outResult=0;
            valueStatus.clear();
            for (int i=0;i<inputN;i++)
                valueStatus.push_back(-1);
            long long currentValue = inputP;
            outResult=-1;
            for(int i=0;i<inputN;i++){
                currentValue+=inputA[i];
                valueStatus[i] = currentValue;
                if(currentValue<=inputQ){
                    outResult=i+1;
                    break;
                }
            }
            if(outResult==-1 && sum<0){
                long long min=100000000000;
                long long index=0;
                int temp=0;
                if (abs(sum)>inputQ)
                {
                    for(int i=0;i<inputN;i++)
                    {
                        temp = int(valueStatus[i]%abs(sum)>inputQ);
                        int current = long(valueStatus[i]/abs(sum))+temp;
                        if( min>current){
                            index=i+1;
                            min=current;
                        }
                    }
                    outResult = min*inputN+index;
                        
                }
                else if (abs(sum)==inputQ)
                {
                    for(int i=0;i<inputN;i++)
                    {
                        temp = int(valueStatus[i]%abs(sum)==0);
                        if( min>long(valueStatus[i]/abs(sum))-temp){
                            index=i+1;
                            min=long(valueStatus[i]/abs(sum))-temp;
                        }
                    
                    }
                    outResult = min*inputN+index;

                }else{
                    for(int i=0;i<inputN;i++)
                    {
                        temp = int((valueStatus[i]-inputQ)%abs(sum)!=0);
                        int current = long((valueStatus[i]-inputQ)/abs(sum))+temp;
                        if( min>current){
                            index=i+1;
                            min=current;
                        }
                    
                    }
                    outResult = min*inputN+index;

                }
                
            }
            
            // cout<<"AAAAA: "<<endl;
            cout<<outResult<<endl;

        }
    public:
    long long inputN, inputP, inputQ;
    long long sum=0;
    long long outResult;
    vector<long long> inputA;
    vector<long long> valueStatus;
        
};

int main(){
    long long testNum;

    if (!MULTI_TEST ){
        Solusion solution;
        solution.readData();
        solution.process();
    }else{
        cin >> testNum;
        for (long long test=0; test<testNum;test++){
            Solusion solution;
            solution.readData();
            solution.process();
        }
    }
    return 0;
}
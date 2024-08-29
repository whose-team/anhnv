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
            cin>>inputL>>inputR;

        }
        bool checkK(int k, long long value){
            int res=-1;
            
            double mu=pow(value,1.0/(double)k);
            int mu_min = ceil(mu);
            int mu_max = floor(mu);
            long long powMax = pow(mu_max,k);
            long long powMin = pow(mu_min,k);
            if(powMin==value||powMax==value) {
                res=max(res,k);
                
            }
            
            return res>-1;
        }
        bool check(int k){
            // if(inputL)
            double aaa=pow(inputL,1.0/(double)k);
            double bbb=pow(inputR,1.0/(double)k);
            int ceilValue = ceil(aaa);
            int floorValue = floor(bbb);
            // long long powMax = pow(floorValue,k);
            // long long powMin = pow(ceilValue,k);
            // return (inputL<=powMin&&powMin<=inputR)||(inputL<=powMin&&powMax<=inputR);
            return ceilValue<=floorValue;
        }
        int find_k(int _min, int _max){
            int minValue=_min;
            int maxValue=_max;
            int res=1;
            while(minValue<=maxValue){
                int mid = (minValue+maxValue)/2;
                if (check(mid)){
                    minValue = mid+1;
                    res = mid;
                }else{
                    maxValue = mid-1;
                }
            }
            return res;
        }
        
        void process()
        {
            int res=1;
            long long xValue;
            if(inputL==inputR){
                for(int k=40;k>=2;k--)
                if(checkK(k, inputL)){
                    res=k;
                    break;
                }
                
            }else{
                res=1;
                for(int k=40;k>=2;k--)
                if(checkK(k, inputL)){
                    res=max(res,k);
                    break;
                }
                for(int k=40;k>=2;k--)
                if(checkK(k, inputR)){
                    res=max(res,k);
                    break;
                }
                res=max(res,find_k(1, 40));
            }
            cout<<"Case #"<<(testIndex+1)<<": "<<res<<endl;
        }
    public:
    int testIndex;
    long long inputL, inputR;

        
};

int main(){
    int testNum=1;
    
    // freopen("input_Power.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    cin >> testNum;
    for (int test=0; test<testNum;test++){
        Solusion solution(test);
    }

    return 0;
}
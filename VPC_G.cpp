#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
struct dataInput{
    long long x,y,w;
};
struct rangeData{
    long long start, finish;
};
bool compare(rangeData A, rangeData B){
    if (A.start == B.start) return A.finish<B.finish;
    return A.start<B.start;
}
class Solusion{

    public:
        Solusion(int _testIndex): testIndex(_testIndex){
            readData();
            process();
        };
        void readData()
        {
            cin>>N>>Xmax>>Ymax;
            dataInput data;
            listPoint.clear();
            
            for(int i=0;i<N;i++){
                cin>>data.x>>data.y>>data.w;
                listPoint.push_back(data);
            }
        }
        long long getNoWare(vector<rangeData> list, long long maxValue, long long minValue=1){
            long long res=0, currentP = 0;
            if(list.size()==0) return maxValue;
            //tinh doan i=0;
            res+=list.at(0).start-minValue;
            currentP = list.at(0).start;
            //doan giua
            rangeData itemRange, nextRange;
            long long delta;
            for(size_t index=0; index<list.size(); index++){
                itemRange = list.at(index);
                // nextRange = list.at(index+1);
                if(itemRange.start> currentP){
                    delta = itemRange.start - (currentP+1);
                    res+=delta;
                    currentP = itemRange.finish;   
                }else{
                    currentP = max(currentP, itemRange.finish);
                }
            }
            //tinh doan cuoi
            res+=maxValue-currentP;
            return res;
        }
        void process()
        {
            //create range
            rangeData itemX, itemY;
            long long Xmin=1, Ymin=1;
            rangeX.clear();
            rangeY.clear();
            for(int i=0;i<N;i++){
                itemX.start = max(Xmin,listPoint.at(i).x-listPoint.at(i).w);
                itemX.finish = min(Xmax,listPoint.at(i).x+listPoint.at(i).w);
                itemY.start = max(Ymin,listPoint.at(i).y-listPoint.at(i).w);
                itemY.finish = min(Ymax,listPoint.at(i).y+listPoint.at(i).w);
                rangeX.push_back(itemX);
                rangeY.push_back(itemY);
            }
            //sort range
            sort(rangeX.begin(), rangeX.end(), compare);
            sort(rangeY.begin(), rangeY.end(), compare);
            //calculate no ware range
            long long noWareX = getNoWare(rangeX,Xmax);
            long long noWareY = getNoWare(rangeY,Ymax);;
            
            //calculate result;
            result = Xmax*Ymax-noWareX*noWareY;
            // cout<<"Result of test "<<testIndex<<": ";
            cout<<result<<endl;
        }
    public:
        long long N, Xmax, Ymax;
        vector<dataInput> listPoint;
        vector<rangeData> rangeX, rangeY;
        long long result;
        int testIndex;
        
};

int main(){
    int testNum=1;
    
    // freopen("inputG.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    // cin >> testNum;
    for (int test=0; test<testNum;test++){
        Solusion solution(test);
    }

    return 0;
}
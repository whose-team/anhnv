#include <iostream>
#include <stdio.h>
#include <set>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int Nmax;

struct Point{
    Point(int _x=0, int _y=0)
    : x(_x), y(_y){};
    int x, y;
    double value;
};
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
            cin>>inputN;
            group.resize(inputN);
            listPoint.clear();
            for (size_t i = 0; i < inputN; i++)
            {
                Point p;
                cin>>p.x>>p.y;
                listPoint.push_back(p);
                group[i]=i;    
            }

            cin>>WValue>>CValue;

        }
        double distance(const Point& A, const Point& B, const double& value){
            return sqrt(pow(A.x-B.x,2)+pow(B.y-A.y,2))*value;
        }
        int getRoot(int k)
        {
            int u=k;
            while(u!=group[u]){
                u=group[u];
            }
            return u;

        }
        
        void process()
        {
            vector<Point> matrixPoint;
            vector<Point> tree;
            matrixPoint.clear();
            tree.clear();
            for (size_t i = 0; i < inputN-1; i++)
            {
                for (size_t j = i+1; j < inputN; j++)
                {
                    double tempValue = WValue;
                    double disValue = distance(listPoint.at(i), listPoint.at(j),CValue);
                    if (disValue<tempValue){
                        Point p;
                        p.x=i;
                        p.y=j;
                        p.value=disValue;
                        matrixPoint.push_back(p);
                    }
                    
                }
                
            }
            
            
            for(int i=0;i<group.size();i++){
                group[i]=i;
            }
            int minIndex=0;
            int index=0;
            Point item;
            while (tree.size()<inputN-1)
            {
                minIndex=0;
                index=0;
                while(index<matrixPoint.size())
                {
                    item = matrixPoint.at(index);
                    if(group[item.x]!=item.x){
                        group[item.x]=getRoot(item.x);
                    }
                    if(group[item.y]!=item.y){
                        group[item.y]=getRoot(item.y);
                    }
                    if(group[item.x]==group[item.y]){
                        matrixPoint.erase(matrixPoint.begin()+index);
                        continue;
                    }
                    if(item.value<=matrixPoint.at(minIndex).value){
                        minIndex=index;
                    }
                    index++;    
                    if(matrixPoint.empty()){
                        break;
                    }
                }
                if(matrixPoint.empty()){
                    break;
                }
                item= matrixPoint.at(minIndex);
                tree.push_back(item);
                int rootValue= min(getRoot(item.x), getRoot(item.y));
                group[getRoot(item.x)]=rootValue;
                group[getRoot(item.y)]=rootValue;
                // free[item.x]=true;
                // free[item.y]=true;
                matrixPoint.erase(matrixPoint.begin()+minIndex);
                
            }
            double res=0;
            set<int> setRoot;
            setRoot.clear();
            for(int i=0;i<group.size();i++){
                // printf("%d->",group[i]);
                int rootValue = getRoot(i);
                setRoot.insert(rootValue);
                if (mapGroup.find(rootValue)!=mapGroup.end()){
                    mapGroup[rootValue].push_back(i);
                }else{
                    // vec = {i};

                    mapGroup.insert(make_pair(rootValue, vector<int> {i}));
                }
            }
                // printf("Size setRoot: %d \n",int(setRoot.size()));
            for(size_t index=0;index<tree.size();index++){
                res+=tree.at(index).value;
            }
            // cout<<"AAAAAAAA:"<<endl;
            vector<Point> rootDistance;
            int u,v;
            if(setRoot.size()>1){
                //Tinh khoang cach cac cay con
                group.clear();
                group= vector<int> (inputN,-1);
                for(auto it=setRoot.begin(); it!=setRoot.end(); it++){
                    for(auto it2=it; it2!=setRoot.end(); it2++){
                        u= *it;
                        v= *it2;
                        group[u]=u;
                        if(u<v){
                            Point p;
                            p.x=u;
                            p.y=v;
                            p.value=1000'000'000;
                            for (int indexU=0;indexU<mapGroup[u].size(); indexU++){
                                 for (int indexV=0;indexV<mapGroup[v].size(); indexV++){
                                    Point pA = listPoint.at(mapGroup[u].at(indexU));
                                    Point pB = listPoint.at(mapGroup[v].at(indexV));
                                    p.value = min(p.value, distance(pA, pB,CValue));

                                 }
                            }
                            rootDistance.push_back(p);
                        }
                    }
                }

                // Xay dung cay khung moi
                
                int minIndex=0;
                int index=0;
                Point item;
                tree.clear();
                while (tree.size()<setRoot.size()-1)
                {
                    minIndex=0;
                    index=0;
                    while(index<rootDistance.size())
                    {
                        item = rootDistance.at(index);
                        if(group[item.x]!=item.x){
                            group[item.x]=getRoot(item.x);
                        }
                        if(group[item.y]!=item.y){
                            group[item.y]=getRoot(item.y);
                        }
                        if(group[item.x]==group[item.y]){
                            rootDistance.erase(rootDistance.begin()+index);
                            continue;
                        }
                        if(item.value<rootDistance.at(minIndex).value){
                            minIndex=index;
                        }
                        index++;    
                        if(rootDistance.empty()){
                            break;
                        }
                    }
                    if(rootDistance.empty()){
                        break;
                    }
                    item= rootDistance.at(minIndex);
                    tree.push_back(item);
                    int rootValue= min(getRoot(item.x), getRoot(item.y));
                    group[getRoot(item.x)]=rootValue;
                    group[getRoot(item.y)]=rootValue;
                    // free[item.x]=true;
                    // free[item.y]=true;
                    rootDistance.erase(rootDistance.begin()+minIndex);
                
                }
                double newRes=0;
                for(size_t index=0;index<tree.size();index++){
                                newRes+=tree.at(index).value;
                }
                res+=min(int(setRoot.size())*WValue, newRes);
            }
            // printf("Test %d output: ", testIndex);
            printf("%.10lf\n",res);
        }
    public:
    int testIndex;
    int inputN;
    double WValue,CValue;
    vector<Point> listPoint;
    vector<int> group;
    map<int, vector<int>> mapGroup;
    
        
};

int main(){
    int testNum=1;
    
    // freopen("inputD.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    // cin >> testNum;
    for (int test=0; test<testNum;test++){
        Solusion solution(test);
    }
    return 0;
}

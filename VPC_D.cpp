#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
bool MULTI_TEST= false;  //Sử dụng nhiều tập test
int Nmax;

struct Point{
    Point(int _x=0, int _y=0, double _value=0)
    : x(_x), y(_y), value(_value){};
    int x, y;
    double value;
};
class Solusion{

    public:
        Solusion(){};
        void readData()
        {
            cin >> inputN;
            listPoint.clear();
            for (size_t i = 0; i < inputN; i++)
            {
                Point p;
                cin>>p.x>>p.y;
                listPoint.push_back(p);
            }
            cin>>WValue>>CValue;

        }
        double distance(const Point& A, const Point& B, const int& value){
            return sqrt(pow(A.x-B.x,2)+pow(B.y-A.y,2))*value;
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
                    Point p;
                    p.x=i;
                    p.y=j;
                    double tempValue = WValue*2;
                    p.value=min(tempValue,distance(listPoint.at(i), listPoint.at(j),CValue));
                    matrixPoint.push_back(p);
                }
                
                /* code */
            }
            vector<bool> free(inputN+2,false);
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

                    if(free[item.x]&&free[item.y]){
                        matrixPoint.erase(matrixPoint.begin()+index);
                        continue;
                    }
                    if(item.value<matrixPoint.at(minIndex).value){
                        minIndex=index;
                    }
                    index++;    
                }
                item= matrixPoint.at(minIndex);
                tree.push_back(item);
                free[item.x]=true;
                free[item.y]=true;
                matrixPoint.erase(matrixPoint.begin()+minIndex);
                
            }
            double res=0;
            for(size_t index=0;index<tree.size();index++){
                res+=tree.at(index).value;
            }
            cout<<"AAAAAAAA:"<<endl;
            cout<<res<<endl;
        }
    public:
    int inputN;
    double WValue,CValue;
    vector<Point> listPoint;
    
        
};

int main()
{
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
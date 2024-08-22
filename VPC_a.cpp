#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
bool MULTI_TEST= false;  //Sử dụng nhiều tập test
vector<string> listString;
int r,c;
void init()
{
    cin>>r>>c;
}
vector<string> readData(int R, int C)
{
    vector<string>  inputList;
    inputList.clear();
    string tempStr;
    for (size_t i = 0; i < R; i++)
    {
        cin>>tempStr;
        inputList.push_back(tempStr);
    }
    return inputList;

}
void process(vector<string>  inputList)
{
    int resRow, resColumn;
    for (size_t i = 0; i < inputList.size(); i++)
    {
        string str = inputList.at(i);
        if(str.find("...")!= string::npos){
            resRow=i;
            resColumn=str.find("...");
            break;
        }
        // for (size_t j = 0; j < str.size()-2; j++)
        // {
            
        // }
        
    }
    resRow+=1;
    resColumn+=1;
    cout<<resRow<<" "<<resColumn<<endl;
    
}
int main(){
    int testNum;
    init();
    if (!MULTI_TEST ){
        listString= readData(r,c);
        process(listString);
    }else{
        cin >> testNum;
        for (int test=0; test<testNum;test++){
            // readData();
            // process();
        }
    }
    return 0;
}
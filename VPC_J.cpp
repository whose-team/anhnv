#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <map>
using namespace std;

class Solusion{

    public:
        Solusion(int _testIndex)
        : testIndex(_testIndex)
        {
            readData();
            process();
        };
        int getKey(int x, int y){
            return x*inputM+y;
        }
        void readData()
        {
            cin>>inputN>>inputM>>inputK;
            inputMatrix = vector<vector<int>> (inputN, vector<int>(inputM,-1));
            char ch;
            for(int x=0;x<inputN;x++)
            {
                for(int y=0;y<inputM;y++)
                {
                    cin>>ch;
                    if(ch!='#'){
                        inputMatrix[x][y]=0;
                        if(ch=='O'){
                            startX=x;
                            startY=y;
                        }    
                    }
                    // positionCount.insert(make_pair(getKey(x,y), 0));
                }
            }
        }

        void run(int x, int y){
            int u,v, keyUV, keyXY;
            keyXY= getKey(x,y);
            for(int index =0;index<deltaX.size();index++)
            if(visited[keyXY][index])
            {
                u = x+deltaX.at(index);
                v = y+deltaY.at(index);
                if(inputMatrix[u][v]==0){
                    numTimeTurn++;
                    historyString+=cmd.at(index);
                    visited[keyXY][index]=false; //Danh dau da di theo huong index
                    while(inputMatrix[u][v]==0){
                        keyUV = getKey(u,v);
                        if(positionCount.find(keyUV)!=positionCount.end()){
                            positionCount[keyUV]++;
                        }else{
                            positionCount.insert(make_pair(keyUV, 1));   
                        }
                        
                        u = u+deltaX.at(index);
                        v = v+deltaY.at(index);
                    }
                    //Lay vi tri truoc khi gap vat can
                    u = u-deltaX.at(index);
                    v = v-deltaY.at(index);
                    if(numTimeTurn>=inputK){
                        if(maxCount<positionCount.size()){
                            maxCount=positionCount.size();
                            resultString=historyString;
                        }
                    }else{
                        run(u,v);
                        while(u!=x && v!=y){
                        keyUV = getKey(u,v);
                        if(positionCount.find(keyUV)!=positionCount.end()){
                            if (positionCount[keyUV]>0){
                                positionCount[keyUV]--;
                            }
                            if (positionCount[keyUV]==0){
                                positionCount.erase(keyUV);
                            }
                        }
                        
                        u = u-deltaX.at(index);
                        v = v-deltaY.at(index);   
                    }
                    if(!historyString.empty())
                    {
                        historyString.pop_back();
                    }
                    
                    numTimeTurn--;
                    visited[keyXY][index]=true;
                    }

                }else{
                    visited[keyXY][index]=false;
                }
            }
            if(maxCount<positionCount.size()){
                            maxCount=positionCount.size();
                            resultString=historyString;
            }
        }
        void process()
        {
            visited = vector<vector<bool>> (inputN*inputM+10,vector<bool>(4, true));
            positionCount.clear();
            historyString="";
            maxCount=0;
            numTimeTurn=0;
            run(startX,startY);
            // cout<<"Output: ";
            cout<<resultString<<endl;

        }
    public:
    int testIndex;
    int inputN, inputM, inputK, startX, startY;
    vector<vector<int>> inputMatrix;
    vector<vector<bool>> visited;
    string cmd ="URDL";
    const vector<int> deltaX = {-1, 0,1,0};
    const vector<int> deltaY = {0,1,0,-1};
    string resultString;
    string historyString;
    int maxCount;
    int numTimeTurn;
    map<int,int> positionCount;

        
};

int main(){
    int testNum=10;
    // for ()
    
    // cin >> testNum;
    for (int test=0; test<testNum;test++){
        string inputfile = "vpc_j_inputs/input_"+to_string(test)+".txt";
        string outputfile = "vpc_j_out/output_"+to_string(test)+".txt";
        freopen(inputfile.c_str(), "r", stdin);
        freopen(outputfile.c_str(), "w", stdout);
    
        Solusion solution(test);
    }

    return 0;
}
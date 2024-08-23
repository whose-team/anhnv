#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class Solusion{

    public:
        Solusion(){
            readData();
            process();
        };
        void readData()
        {
            dict.clear();
            question.clear();
            cin>>N;
            string str;
            for(int i=0;i<N;i++){
                cin>>str;
                dict.push_back(str);
            }
            cin>>Q;
            for(int i=0;i<Q;i++){
                cin>>str;
                question.push_back(str);
            }

        }
        void search(int tryIndex){
            int next;
            if (hasResult) return;
            for(int i=0;i<N;i++)
            {
                if(!flag[i]) continue;
                if (hasResult) return;
                size_t pos = currentStr.find(dict[i], tryIndex);
                // if(pos ==string::npos){
                //     flag[i]=false;
                //     continue;
                // }
                if(pos==tryIndex){
                     next = tryIndex+dict[i].size();
                     if(next>currentStr.size()){
                        continue;
                     }else if(next==currentStr.size()){
                        //write result
                        resIndex.push_back(i);
                        hasResult=true;
                        for(int j=0;j<resIndex.size();j++){
                            cout<< dict[resIndex[j]];
                            if (j<resIndex.size()-1) cout<<" ";
                        }
                     }else{
                        //continue search
                        resIndex.push_back(i);
                        search(next);
                        resIndex.pop_back();
                     }   
                }    
            }
        }
        void process()
        {
            bool needSearch = false;
            for(int i=0;i<Q;i++){
                hasResult=false;
                currentStr=question[i];
                flag.clear();
                for(int index=0; index<N;index++)
                {
                    if(currentStr.find(dict[index])==string::npos){
                        flag.push_back(false);
                    }else{
                        flag.push_back(true);
                        needSearch = true;
                    }
                }
                resIndex.clear();
                if(needSearch) search(0);
                if(hasResult) cout<<endl;
                else cout<<"-1\n";
            }
        }
    public:
        int N,Q;
        vector<string> dict;
        vector<string> question;
        vector<int> resIndex; 
        string currentStr;
        bool hasResult;
        vector<bool> flag;
        
};

int main(){
    int testNum=1;
    
    freopen("inputF.2.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    // cin >> testNum;
    for (int test=0; test<testNum;test++){
        Solusion solution;
    }

    return 0;
}
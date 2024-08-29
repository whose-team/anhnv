#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
using namespace std;
struct Data{
    int length;
    bool delStatus; //true: can xoa
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
            Data flag;
            char ch;
            flag.length= __INT32_MAX__;
            flag.delStatus=false;
            inputList.clear();
            inputList.push_back(flag); //Chen can tren
            Data item;
            delNum = 0;
            for(int i=0;i<inputN;i++){
                cin>>ch>>item.length;
                item.delStatus = ch=='n' ?false:true;
                delNum += (int)item.delStatus==true;
                inputList.push_back(item);
            }
            inputList.push_back(flag);  //Chen can duoi
        }
        void process()
        {
            int res=0;
            vector<Data> currentList;
            Data flag, newItem;
            
            flag.length= __INT32_MAX__;
            flag.delStatus=false;
            int index;
            while(delNum>0){
                if(inputList.size()<=2) break; //Xoa khi list chi con 2 can
                currentList.clear();
                // currentList.push_back(flag);
                index = 0; //Chay tu diem can
                int currentValue;
                while(index<=inputList.size()-2){
                    bool fileTypeIndex;//true: can xoa
                    fileTypeIndex = inputList.at(index).delStatus;
                    currentValue= inputList.at(index).length;
                    while(index+1<inputList.size()&&inputList.at(index+1).delStatus==fileTypeIndex){
                        index++;
                        if(fileTypeIndex){
                             //Xoa chuoi ch='y', giu lai gia tri min
                            currentValue = min(currentValue, inputList.at(index).length);
                            delNum--; //Giam di 1 file can xoa
                        }else{
                            //Xoa chuoi ch='n', giu lai gia tri max
                            currentValue = max(currentValue, inputList.at(index).length);
                        }
                    }
                    newItem.length = currentValue;
                    newItem.delStatus = fileTypeIndex;
                    currentList.push_back(newItem);
                    index++; //Tiep tuc  
                   
                }
                currentList.push_back(flag);
                /// comment late
                // for(auto item:currentList){
                //     cout<<item.delStatus<<" "<<item.length<<endl;
                // }
                // duyet day
                index =1;
                // for (index=1;index<currentList.size()-2;index++){
                while(index<=currentList.size()-2)
                {
                    bool status = currentList.at(index).delStatus;
                    int value = currentList.at(index).length;
                    if(currentList.at(index).delStatus==true){
                        
                        if(value<=currentList.at(index-1).length&&value<=currentList.at(index+1).length
                        && status!=currentList.at(index-1).delStatus&&status!=currentList.at(index+1).delStatus){
                            res+=1; //Tang 1 lan xoa
                            delNum--; //Giam 1 lan xoa
                            currentList.erase(currentList.begin()+index);
                        }else{
                            index++;
                        }
                    }
                    else{
                        if(value<currentList.at(index-1).length&&value<currentList.at(index+1).length
                        && status!=currentList.at(index-1).delStatus&&status!=currentList.at(index+1).delStatus){
                            currentList.erase(currentList.begin()+index);
                           
                        }else{
                            index++;
                        }
                    }
                }
                inputList=currentList;
                /// comment late
                // cout<<"Late\n";
                // for(auto item:currentList){
                //     cout<<item.delStatus<<" "<<item.length<<endl;
                // }
            }
            cout<<"OUTPUT test "<<testIndex<<": ";
            cout<<res<<endl;
        }
    public:
    int testIndex, inputN;

    int length, delNum;
    vector<Data> inputList;
        
};

int main(){
    int testNum=1;
    
    freopen("input_b3_test.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    cin >> testNum;
    for (int test=0; test<testNum;test++){
        Solusion solution(test);
    }

    return 0;
}
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>
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

    }
    void process()
    {

    }
public:
    int testIndex;

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testNum=1;

    if(freopen("./input_b3_test.txt", "r", stdin)){
        cerr<<"Khong the mo file"<<endl;
        return 1;
    }
    // freopen("output.txt", "w", stdout);

    cin >> testNum;
    for (int test=0; test<testNum;test++){
        Solusion solution(test);
    }

    return 0;
}

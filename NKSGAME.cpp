#include <bits/stdc++.h>
using namespace std;
int main()
{
    const int maxN = 100003;
    int inputN;
    vector<int> inputB;
    vector<int> inputC;
    cin>>inputN;
    inputB = vector<int> (inputN,0);
    inputC = vector<int> (inputN,0);
    for(int i=0;i<inputN;i++)
        cin>>inputB[i];
    for(int i=0;i<inputN;i++)
        cin>>inputC[i];
    sort(inputB.begin(), inputB.end());
    sort(inputC.begin(), inputC.end());
    // qsort(&inputC, &inputC+inputN);
    int indexI=0;
    int indexJ=inputN-1;
    long long res = abs(inputB[0]+inputC[inputN-1]);
    while((indexI<inputN-1)||(indexJ>0)){
        if (indexI==inputN-1)
        {
            indexJ--;
        }
        else if (indexJ==0)
        {
            indexI++;
        }
        else if (abs(inputB[indexI+1]+inputC[indexJ])<abs(inputB[indexI]+inputC[indexJ-1])){
            indexI++;
        }else{
            indexJ--;
        }
        res = min(res, (long long)abs(inputB[indexI]+inputC[indexJ]));
        if (res == 0) break;
    }

    cout<<res<<endl;
    return 0;
}

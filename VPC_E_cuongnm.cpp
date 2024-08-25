#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
    long int n, p, q;
    cin >> n >> p >> q;
    vector<long long> a(n, 0);
    for (long int i = 0; i < n ; i++) {
        cin >> a[i];
    }

    long long result = -1;

    long long current = p; // số sỏi trên tay người thứ nhất


    //while ( current > q) {
    //anhnv: Lan choi 1
    for(size_t i=0;i<n;i++){
        
        if (a[i] < 0) {
            current -= min(current, -a[i]);
        }
        if (a[i] > 0) {
            current += a[i];
        }
        if (a[i] == 0) {
            continue;
        }
        if(current <= q){
            result = i+1;
            break;
        }
    }
    // anhnv:  Nếu chưa có nghiệm ở vòng chơi thứ nhất thì thực hiện
    if (result<0){
        // anhnv: tính tổng sum
        long long sum = 0;
        for(size_t i=0;i<n;i++){
            sum+=a[i];
        }
        // anhnv: sum>=0 thì vô nghiệm, result=-1
        if(sum<0){
            result = n; // anhnv: do đã chơi hết 1 vòng ở line 24
            //anhnv: trong khi số sỏi vẫn đủ thực hiện một vòng chơi hoàn chỉnh
            while(current>q){
                current = current - abs(sum); // 
                result+=n;
            }
            // anhnv: Thực hiện lượt chơi cuối khi số sỏi vẫn còn current>0;
            for(size_t i=0;i<n;i++){
                
                if (a[i] < 0) {
                    current -= min(current, -a[i]);
                }
                if (a[i] > 0) {
                    current += a[i];
                }
                if (a[i] == 0) {
                    continue;
                }
                if(current <= q){
                    result = result+i+1; // anhnv: Số lượt chơi hoàn chỉnh cộng với index lượt cuối
                    break;
                }
            }


        }
        // chuyển tiếp cho người chơi khác
        // if (i < n - 1) {
        //     i += 1;
        // } else {
        //     // nếu hết 1 vòng mà số ra nhiều hơn hoặc bằng số vào thì vô nghiệm
        //     int sum = std::accumulate(a.begin(), a.end(), 0);
        //     if ( current - abs(sum) >= q) {
        //         // vô hạn
        //         result = -1;
        //         break;
        //     }


        //     i = 0; // Quay lại người đầu tiên nếu hết 1 vòng
        // }
    }
    cout << result;
    return 0;
}

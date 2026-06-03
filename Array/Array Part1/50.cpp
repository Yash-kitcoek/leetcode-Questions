// Pow(x, n);

#include<iostream>
#include<vector>
using namespace std;

// Brute force
// int pow(int x, int n) {
//     int ans = 1;
//     for(int i=0; i<n; i++) {
//         ans *= x;
//     }
//     return ans;
// }

// Optimal o(logn)

int pow(int x, int n) {
    long binform = n;
    double ans = 1;

    if(n < 0) {
        x = 1/x;
        binform = -binform;
    }

    while(binform > 0) {
        if(binform % 2 == 1) {
            ans  *= x;
        }
        x *= x;
        binform /= 2;
    }
    return ans;
}


int main() {
    int x = 2;
    int n = 10;

    cout << pow(x, n);

    return 0;
}
// leetcode 560

// Brute force

// #include<iostream>
// #include<vector>
// using namespace std;

// int SubArraySum(vector<int> &nums, int k) {
//     int n = nums.size();
//     int count = 0;

//     for(int i=0; i<n; i++){
//         int sum = 0;

//         for(int j=i; j<n; j++){
//             sum += nums[j];

//             if(sum == k){
//                 count++;
//             }
//         }
//     }
//     return count;
// }

// int main() {
//     vector<int> nums = {1,2,3};
//     int k = 3;

//    cout << SubArraySum(nums, k);
// }

// Optimal Approach

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int SubArraySum(vector<int> &nums, int k) {
    int n = nums.size();

    int preSum = 0;
    int ans = 0;

    unordered_map<int, int> m;
    m[0] = 1;

    for(int i=0; i<n; i++) {
        preSum += nums[i];
        if(m.find(preSum - k) != m.end()) {
            ans += m[preSum-k];
        }

        m[preSum]++;
    }
    return ans;

    // end of the code 
}

int main() {
    vector<int> nums = {1,2,3};

    int k = 3;

    cout << SubArraySum(nums, k) << endl;


    return 0;
}
// leetcode 239

#include<iostream>
#include<algorithm>
#include<deque>
#include<vector>
using namespace std;

// vector<int> slidingWindowMax(vector<int> &nums, int k) { // O(n*k)
//     int n = nums.size();

//     vector<int> ans;

//     for(int i=0; i<=n-k; i++) {
//         int maxi = nums[i];
//         for(int j=i; j<i+k; j++) {
//            maxi = max(maxi, nums[j]);
//         }
//         ans.push_back(maxi);
//     }
//     return ans;
// }

// Optimal

vector<int> slidingWindowMax(vector<int> &nums, int k) {
    int n = nums.size();

    deque<int> dq;
    vector<int> res;

    // First window
    for(int i = 0; i < k; i++) {
        while(!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    // Remaining windows
    for(int i = k; i < n; i++) {

        // Maximum of previous window
        res.push_back(nums[dq.front()]);

        // Remove indices outside current window
        while(!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Remove smaller elements
        while(!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }

        // Add current index
        dq.push_back(i);
    }

    // Maximum of last window
    res.push_back(nums[dq.front()]);

    return res;
}
int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};

    int k = 3;

    vector<int> result = slidingWindowMax(nums, k);

    for(int val : result) {
        cout << val << " ";
    }
}
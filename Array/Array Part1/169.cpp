#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>& nums, int n) {
    int ans = 0, freq = 0;
    
    for(int i=0; i<n; i++) {
        if(freq == 0) {
            ans = nums[i];
        }
        
        if(ans == nums[i]) {
            freq++;
        } else {
            freq--;
        }
    }
    return ans;
    
    
}

int main() {
    vector<int> nums = {3,2,3};

    int n = nums.size();

    cout << majorityElement(nums, n);
}
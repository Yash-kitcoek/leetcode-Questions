#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int n, int target) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());

    for(int i = 0; i < n; i++) {
        
        if(i > 0 && nums[i] == nums[i-1])continue;

        for(int j = i+1; j < n; j++) {
            if(j > 0 && nums[j] == nums[j-1])continue;

            int left = j+1;
            int right = n-1;

            while(left < right) {
                long long sum = nums[i] + nums[j] + nums[left] + nums[right];

                if(sum == target) {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});
                    left++;
                    right--;
                }else if(sum < target) {
                    left++;
                }else {
                    right--;
                }
            }
        }
    }
    return result;
}

int main() {
    vector<int> nums = {1,0,-1,0,-2,2};
    int n = nums.size();
    int target = 0;

    vector<vector<int>> result = fourSum(nums,n, target);

    for(auto triplet : result) {
        for(int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }
}
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums, int n) {

    vector<vector<int>> result;

    sort(nums.begin(), nums.end());

    for(int i = 0; i < n - 2; i++) {

        // Skip duplicates
        if(i > 0 && nums[i] == nums[i - 1])
            continue;

        int target = -nums[i];

        int left = i + 1;
        int right = n - 1;

        while(left < right) {

            int sum = nums[left] + nums[right];

            if(sum == target) {

                result.push_back({nums[i], nums[left], nums[right]});

                // Skip duplicates
                while(left < right && nums[left] == nums[left + 1])
                    left++;

                while(left < right && nums[right] == nums[right - 1])
                    right--;

                left++;
                right--;
            }
            else if(sum < target) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    return result;
}

int main() {

    vector<int> nums = {-1,0,1,2,-1,-4};

    int n = nums.size();

    vector<vector<int>> res = threeSum(nums, n);

    for(auto triplet : res) {

        for(int num : triplet) {
            cout << num << " ";
        }

        cout << endl;
    }

    return 0;
}
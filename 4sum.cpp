#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums,int n,  int target) {
       vector<vector<int>> result;
       sort(nums.begin(), nums.end()); 

       
       for (int i = 0; i < n - 3; i++) {
           if (i > 0 && nums[i] == nums[i - 1]) continue; 


        
           for (int j = i + 1; j < n - 2; j++) {
               if (j > i + 1 && nums[j] == nums[j - 1]) continue; // Skip duplicates


               long long remainingTarget = (long long)target - nums[i] - nums[j];
               int left = j + 1, right = n - 1;


               // Two-pointer for the remaining two numbers
               while (left < right) {
                   int sum = nums[left] + nums[right];


                   if (sum < remainingTarget) {
                       left++; 
                   } else if (sum > remainingTarget) {
                       right--; 
                   } else {
                       
                       result.push_back({nums[i], nums[j], nums[left], nums[right]});

                       int prevLeft = nums[left], prevRight = nums[right];
                       while (left < right && nums[left] == prevLeft) left++;
                       while (left < right && nums[right] == prevRight) right--;
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
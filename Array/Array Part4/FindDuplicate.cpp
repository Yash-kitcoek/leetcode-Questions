// leetcode 287

// Brute Force

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// TC : O(n^2), SC : O(1)

// int duplicate(vector<int> &nums) {
//     int n = nums.size();

//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++) {
//             if(nums[i] == nums[j]) {
//                 return nums[i];
//             }
//         }
//     }
//     return -1;
// }

// Better Approach
// TC : O(n), SC : O(n)

// int duplicate(vector<int> &nums) {
//     int n = nums.size();

//     unordered_map<int, int> m;

//     for(int i=0; i<n; i++) {
//         m[nums[i]]++;
//         if(m[nums[i]]==2) {
//             return nums[i];
//         }
//     }

//     return -1;
// }
// Optimal : floyd Tortoise and hare Algorithms, TC : O(n), SC : O(1)
int duplicate(vector<int> &nums) {
    int n = nums.size();

    int slow = nums[0];
    int fast = nums[0];

    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }while(slow != fast);

    slow = nums[0];
    while(slow != fast){
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}


int main() {
    vector<int> nums = {1,2,3,3};

    cout << duplicate(nums);
}

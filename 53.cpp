#include<iostream>
#include<vector>
#include<math.h>
#include<climits>
using namespace std;

int maxSubArray(vector<int> nums) {
    int currSum = 0, maxSum = INT_MIN;

    for(int val : nums) {
        currSum += val;
        maxSum = max(currSum, maxSum);

        if(currSum < 0) {
            currSum = 0;
        }
    }
    return maxSum;
}


int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    cout << maxSubArray(nums);

}
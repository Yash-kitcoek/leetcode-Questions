#include<iostream>
#include<vector>
using namespace std;

void sortColors(vector<int> &nums, int n) {
    int low = 0, mid = 0, high = n-1;

    while(mid <= high) {
        if(nums[mid] == 0) {
            swap(nums[mid], nums[low]);
            low++, mid++;
        }
        else if(nums[mid] == 1) {
            mid++;
        }
        else {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main() {
    vector<int> nums = {2,1,0,0,1,2};
    int n = nums.size();
    
    sortColors(nums, n);

    for(int val : nums) {
        cout << val << " ";
    }
    cout << endl;
}
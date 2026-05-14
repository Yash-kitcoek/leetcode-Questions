#include<iostream>
#include<vector>
using namespace std;

void mergeSortedArray(vector<int> &nums1, vector<int> &nums2, int m, int n) {
    int i = m-1;
    int j = n-1;
    int idx = m+n-1;

    while(i >= 0 && j >= 0) {
        if(nums1[i] >= nums2[j]) {
            nums1[idx] = nums1[i];
            idx--, i--;
        } else {
            nums1[idx] = nums2[j];
            idx--, j--;
        }
    }
    
    while(j >= 0) {
        nums1[idx] = nums2[j];
        idx--, j--;
    }
}

int main() {
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};

    int m = 3;
    int n = 3;

    mergeSortedArray(nums1, nums2, m, n);

    // print sorted vector

    for(int val : nums1) {
        cout << val << " ";
    }

}
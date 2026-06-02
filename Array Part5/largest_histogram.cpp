// leetcode 84

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int largestHistogram(vector<int> &heights) {
    int n = heights.size();

    vector<int> left(n, 0);
    vector<int> right(n, 0);
    stack<int> s;

    //left smaller
    for(int i=n-1; i>=0; i--) {
        while(s.size() > 0 && heights[s.top()] >= heights[i]) {
            s.pop();
        }

        if(s.empty()) {
            right[i] = n;
        }else {
            right[i] = s.top();
        }

        s.push(i);
    }

    while(!s.empty()) {
        s.pop();
    }

    //left smaller
    for(int i=0; i<n; i++) {
        while(s.size() > 0 && heights[s.top()] >= heights[i]) {
            s.pop();
        }

        if(s.empty()) {
            left[i] = -1;
        }else {
            left[i] = s.top();
        }
        s.push(i);
    }

    int ans = 0;
    for(int i=0; i<n; i++) {
        int width = right[i] - left[i]-1;
        int currArea = heights[i] * width;

        ans = max(ans, currArea);
    }
    return ans;
}

int main() {
    vector<int> heights = {2,1,5,6,2,3};

    cout << largestHistogram(heights);
}
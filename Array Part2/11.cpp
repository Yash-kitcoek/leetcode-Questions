#include<iostream>
#include<vector>
using namespace std;

int maxArea(vector<int> heights, int n) {
    int maxArea = 0;
    int lp=0, rp=n-1;
    
    while(lp < rp) {
        int width = rp - lp;
        int minHeight = min(heights[lp], heights[rp]);
        int currArea = width * minHeight;

        maxArea = max(maxArea, currArea);

        if(heights[lp] < heights[rp]) {
            lp++;
        } else {
            rp--;
        }
    }
    return maxArea;
}

int main() {
    vector<int> heights = {1,8,6,2,5,4,8,3,7};
    int n = heights.size();

    cout << maxArea(heights, n);
}
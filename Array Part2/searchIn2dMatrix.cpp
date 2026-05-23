//leetcode 

#include<iostream>
#include<vector>
using namespace std;

bool searchinRow(vector<vector<int>> matrix, int target, int midRow) {
    int m = matrix[0].size();

    int st = 0;
    int end = m-1;

    while(st <= end) {
        int mid = st + (end - st)/2;

        if(target == matrix[midRow][mid]) {
            return true;
        }else if(target > matrix[midRow][mid]) {
            st = mid + 1;
        }else {
            end = mid - 1;
        }
    }
    return false;
}

bool searchin2d(vector<vector<int>> matrix,int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    int startRow = 0;
    int endRow = n-1;

    while(startRow < endRow) {
        int midRow = startRow + (endRow - startRow)/2;

        if(target >= matrix[midRow][0] && target <= matrix[midRow][m-1]) {
            return searchinRow(matrix, target, midRow);
        } else if(target > matrix[midRow][m-1]) {
            startRow = midRow + 1;
        }else {
            endRow = midRow - 1;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    int target = 6;

    cout << searchin2d(matrix, target);
}
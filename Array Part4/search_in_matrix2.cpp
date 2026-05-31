#include<iostream>
#include<vector>
using namespace std;

bool search_in_matrix2(vector<vector<int>> &matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    int r=0, c=m-1;

    while(r < n && c >= 0) {
        if(target == matrix[r][c]) {
            return true;
        }
        else if(target < matrix[r][c]) {
            c--;
        }else {
            r++;
        }
    }
    return false;
}

int main() {
    
    vector<vector<int>> matrix = {{1,4,7,11,15},
                                  {2,5,8,12,19},
                                  {3,6,9,16,22},
                                  {10,13,14,17,24}};

    int target = 12;
    
    cout << search_in_matrix2(matrix, target);
}
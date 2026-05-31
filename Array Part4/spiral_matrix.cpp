// leetcode 54

#include<iostream>
#include<vector>
using namespace std;

vector<int> sprialMatrix(vector<vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;

        int scol = 0, srow = 0, erow = n-1, ecol = m-1;

        while(scol <= ecol && srow <= erow){
            // top

            for(int j = scol; j <= ecol; j++) {
                ans.push_back(matrix[scol][j]);
            }
            
            //right

            for(int i = srow+1; i <= erow; i++) {
                ans.push_back(matrix[i][ecol]);
            }

            //bottom
            for(int j = ecol - 1; j >= scol; j--){
                if(srow == erow) {
                    break;
                }
                ans.push_back(matrix[erow][j]);
            }

            //left

            for(int i = erow-1; i >= srow + 1; i--) {
                if(scol == ecol) {
                    break;
                }
                ans.push_back(matrix[i][scol]);
            }
            scol++, srow++, erow--, ecol--;
        }
        return ans;
}

int main() {

    vector<vector<int>> matrix = {{1,2,3,4},
                                  {4,5,6,10},
                                  {7,8,9,11}};

     vector<int> result = sprialMatrix(matrix);   
     
     for(int val : result) {
        cout << val << " ";
     }
}
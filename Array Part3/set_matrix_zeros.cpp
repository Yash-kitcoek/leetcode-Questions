//leetcode 73

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> set_matrix_zeroes(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    int col0 = 1;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0;

                if(j != 0) {
                matrix[0][j] = 0;
            }else {
                col0 = 0;
            }
            }

        }
    }

    for(int i=1; i<n; i++) {
        for(int j=1; j<m; j++) {
            if(matrix[i][j] != 0) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    if(matrix[0][0] == 0) {
        for(int j=0; j<m; j++) {
            matrix[0][j] = 0;
        }
    } 

    if(col0 == 0) {
        for(int i=0; i<n; i++) {
            matrix[i][0] = 0;
        }
    }
    return matrix;
}

int main() {
    vector<vector<int>> matrix = {
                                {1,2,3},
                                {5,0,7},
                                {2,1,6}
};

     vector<vector<int>>result  = set_matrix_zeroes(matrix);        
     
    for(auto row : result) {
        for(int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}
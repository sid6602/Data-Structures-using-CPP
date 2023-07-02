// Question link
// https://leetcode.com/problems/set-matrix-zeroes/



// Solution 3 Optimal Solution
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int col0 = 1;
        
        // to set 1st column and 1st row elements to 0 to keep track 
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    if(j == 0)
                    { 
                        col0 = 0 ;
                    } 
                    else
                    {
                        matrix[0][j] = 0;
                    }
                
                }
            }
        }
        
        
        // to convert all boxes except boxes in 1st row and first columnn
        for(int i=1; i<n; i++)
        {
            for(int j=1; j<m; j++)
            {
                if(matrix[i][j] != 0)
                {
                     if(matrix[0][j] == 0 || matrix[i][0] == 0)
                    {
                        matrix[i][j]=0;
                    }
                }
            }
        }
        
        // to convert 1st row 
        if(matrix[0][0] == 0)
        {
            for(int i=0; i< m ; i++)
            {
                matrix[0][i] = 0;
            }
        }
        // to convert 1st col 
        if(col0 == 0)
        {
            for(int i=0; i< n ; i++)
            {
                matrix[i][0] = 0;
            }
        }
        
    }
};



    
    
    
    
// Solution 2 Better 
// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
    
//         int row[matrix.size()] ;
//         int col[matrix[0].size()];
        
//         for(int i=0; i< matrix.size(); i++)
//         {
//             for(int j=0; j< matrix[0].size(); j++)
//             {
//                 if(matrix[i][j] == 0)
//                 {
//                     row[i] = 1;
//                     col[j] = 1;
//                 }
//             }
//         } 
        
//         for(int i=0; i< matrix.size(); i++)
//         {
//             for(int j=0; j< matrix[0].size(); j++)
//             {
//                 if(row[i] == 1 || col[j] == 1)
//                 {
//                       matrix[i][j]=0;  
//                 }
//             }
//         } 
        
//     }
  
// };
    
    
    
    
    
    
    

// Solution 1 Bruitforce
// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         for(int i=0; i< matrix.size(); i++)
//         {
//             for(int j=0; j< matrix[0].size(); j++)
//             {
//                 if(matrix[i][j] == 0)
//                 {
//                     markRow(i, matrix);
//                     markCol(j, matrix);
//                 }
//             }
//         }
        
//        for(int i=0; i< matrix.size(); i++)
//         {
//             for(int j=0; j< matrix[0].size(); j++)
//             {
//                 if(matrix[i][j] == -1)
//                 {
//                     matrix[i][j] = 0;
//                 }
//             }
//         } 
        
        
        
//     }
    
//     void markRow(int i, vector<vector<int>>& matrix)
//     {
//         for(int k=0; k< matrix.size(); k++ )
//         {
//             if(matrix[i][k] != 0)
//             {
//                 matrix[i][k]= -1;
//             }
//         }
//     }
    
//     void markCol(int j, vector<vector<int>>& matrix)
//     {
//         for(int k=0; k<matrix[0].size(); k++ )
//         {
//             if(matrix[k][j] != 0)
//             {
//                 matrix[k][j]= -1;
//             }
//         }
//     }
// };














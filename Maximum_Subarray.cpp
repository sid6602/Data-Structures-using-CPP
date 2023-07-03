// Optimal Solution
class Solution {
public:
    int maximum = INT_MIN;
     int sum=0;
    int maxSubArray(vector<int>& nums) {
        
        for(int i=0; i< nums.size(); i++)
        {
            sum = sum+ nums[i];
            maximum =max(sum, maximum);
            
            if(sum<0)
            {
                sum =0;
            }  
        }
     return maximum;
    }  
};



//Better Solution
// class Solution {
// public:
//     int maximum = LONG_MIN;
//     int maxSubArray(vector<int>& nums) {
        
//         for(int i=0; i< nums.size(); i++)
//         {
//             int sum=0;
//             for(int j=i; j< nums.size(); j++)
//             {
//                     sum += nums[j];
//                     maximum = max(sum, maximum);
//             }
//         }
//         return maximum;
//     }
    
// };




// Bruit Force Approach
// class Solution {
// public:
//     int maximum = LONG_MIN ;
//     int maxSubArray(vector<int>& nums) {
        
//         for(int i=0; i< nums.size(); i++)
//         {
//             for(int j=i; j< nums.size(); j++)
//             {
//                 for(int k=i; k<= j; k++)
//                 {
//                     int sum=0;
//                     sum += nums[k];
//                     maximum = max(sum, maximum);
//                 }
//             }
//         }
//         return maximum;
//     }
    
// };

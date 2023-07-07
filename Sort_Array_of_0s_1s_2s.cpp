// Most Optimal solution (less iterations than optimal solution mentioned below)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low =0;
        int mid =0;
        int high = nums.size()-1;
        
        for(int i=0; i< nums.size(); i++)
        {
            if(nums[mid] == 0 )
            {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1)
            {
                mid++;
            }
            else if(nums[mid] == 2)
            {
                swap(nums[mid],nums[high]);
                high--;
            }
        }
        
    }   
};






//Better Solution


// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int cnt_0 = 0;       
//         int cnt_1 = 0;
//         int cnt_2 = 0;
    
//         for(int i=0; i< nums.size(); i++)
//         {
//             if(nums[i] == 0)
//             {
//                 cnt_0 ++;
//             }
//             if(nums[i] == 1)
//             {
//                 cnt_1 ++;
//             }
//             if(nums[i] == 2)
//             {
//                 cnt_2 ++;
//             }
//         }
        
//         for(int i=0; i<cnt_0; i++){ nums[i]=0; }
//         for(int i=cnt_0 ; i<cnt_0 + cnt_1; i++){ nums[i]=1; }
//         for(int i=cnt_0 + cnt_1; i<nums.size(); i++){ nums[i]=2; }
//     }
// };

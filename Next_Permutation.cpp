class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int breakpoint = -1;
        int n = nums.size();
        for(int i= n-2; i>=0; i--)
        {
            if(nums[i] < nums[i+1])
            {
                breakpoint = i;
                break;
            }
        }
            
        
        for(int i= n-1;  i>=breakpoint && breakpoint != -1 ; i--)
        {
            if(nums[i] > nums[breakpoint])
            {
                swap(nums[i], nums[breakpoint]);
                break;
            }
        }
        reverse(nums.begin() + breakpoint + 1, nums.end());     
    }
};

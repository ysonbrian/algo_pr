class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum_of_vec = 0;
        sum_of_vec = accumulate(nums.begin(), nums.end(), 0);
        int left = 0;
        int right = sum_of_vec;
        int j = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(left == (right - nums[i])){
                return i;
            }
            left += nums[i];
            right -= nums[i];


        }

        return -1;
    }
};
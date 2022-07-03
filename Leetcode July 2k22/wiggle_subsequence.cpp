//Solution 1

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int inc = 1, dec = 1;
        for(int i = 1; i< nums.size(); i++){
            if(nums[i]- nums[i-1] > 0) inc = dec+1;
            else if(nums[i] - nums[i-1] < 0) dec = inc +1;
        }
        return max(inc, dec);
    }
};

// Solution 2 from Ayushi Sharma
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()< 2)
            return nums.size();
        int prev = nums[1] - nums[0];
        int count = prev != 0 ? 2: 1;
        
        for(int i = 2; i < nums.size(); i++){
           int  diff = nums[i] - nums[i-1];
            if((diff< 0 && prev >= 0) || diff>0 && prev <= 0) {
                count++;
                prev = diff;
            }
        }
        return count;
    }
};

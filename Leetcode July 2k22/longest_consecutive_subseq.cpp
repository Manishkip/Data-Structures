class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        
        int maxlen = 0;
        
        for (auto n : nums) {
            if (set.count(n - 1)) continue;
            
            int len = 1;
            
            while (set.count(n + 1)) {
                n++;
                len++;
            }
            
            maxlen = max(maxlen, len);
        }
        
        return maxlen;
    }
};

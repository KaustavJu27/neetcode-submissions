class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;

            for (int num : nums) {
                if (mp[num] > 0) return 1;
                mp[num]++;
            }
            return 0;
    }
};
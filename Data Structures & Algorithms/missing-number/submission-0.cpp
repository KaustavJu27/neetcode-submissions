class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        // Tracker array initialized to 0 for all numbers from 0 to n
        vector<int> countTracker(n + 1, 0);

        // Track the numbers present in nums
        for (int num : nums) {
            countTracker[num]++;
        }

        // Loop from 0 to n to find the missing index
        for (int i = 0; i <= n; i++) {
            if (countTracker[i] == 0) {
                return i;  // Found the missing number
            }
        }

        return -1;
    }
};

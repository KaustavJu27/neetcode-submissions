class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;  // Store frequency of each element

        // Count the frequency of every number
        for (auto i : nums) {
            freq[i]++;
        }

        // Traverse the frequency map to find the duplicated number
        for (auto u : freq) {
            int data = u.first;
            int frequency = u.second;

            if (frequency > 1) {
                return data;  // Return the element whose frequency is greater than 1
            }
        }

        return -1;  // Safety return (problem guarantees one duplicate)
    }
};
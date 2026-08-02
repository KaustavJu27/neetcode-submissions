class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Get the sizes of both input vectors
        int n1 = nums1.size();
        int n2 = nums2.size();

        // Combined container for both arrays
        // FIXED: Kept empty so push_back inserts at index 0 (not after pre-allocated zeros)
        vector<int> all;

        // Copy all elements from the first array into the combined vector
        for (int i = 0; i < n1; i++) {
            all.push_back(nums1[i]);
        }

        // Copy all elements from the second array into the combined vector
        for (int k = 0; k < n2; k++) {
            all.push_back(nums2[k]);
        }

        // Sort the combined array in ascending order
        // Time Complexity of this step: O((n1 + n2) * log(n1 + n2))
        sort(all.begin(), all.end());

        // Variable to store the final calculated median value
        double op = 0;

        // Pointers/indices to calculate the exact middle position
        double low = 0;
        double high = all.size() - 1;

        // Calculate the central index while preventing integer overflow
        int mid = low + (high - low) / 2;

        // Check if the total number of elements is even
        if (all.size() % 2 == 0) {
            // Even size: Median is the average of the two middle elements
            op = (all[mid] + all[mid + 1]) / 2.0;

        } else {
            // Odd size: Median is simply the exact middle element
            // FIXED: Removed "/ 2.0" mathematical bug and added the missing semicolon
            op = all[mid];
        }

        // Return the final calculated median
        return op;
    }
};

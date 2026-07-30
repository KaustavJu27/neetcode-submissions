class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>freq;

        for(auto i : nums){
            freq[i]++;
        }

        for(auto u : freq){
            int data = u.first;
            int freq = u.second;

            if(freq>1){
                return data;
            }
        }
    }
};

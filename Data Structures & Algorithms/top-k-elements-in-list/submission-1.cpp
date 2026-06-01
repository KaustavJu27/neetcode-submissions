class Solution {
public:
    static bool cmp(pair<int,int>& a, pair<int,int>& b){
        return a.second < b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> mp;

        for(int x : nums){
            mp[x]++;
        }

        vector<pair<int,int>> hlpr(mp.begin(), mp.end());

        sort(hlpr.begin(), hlpr.end(), cmp);

        vector<int> ans;

        for(int i = hlpr.size()-1; i >= 0 && ans.size() < k; i--){
            ans.push_back(hlpr[i].first);
        }

        return ans;
    }
};
class Solution {
public:
    struct Compare{
        bool operator()(
            const pair<int, int>& a,
            const pair<int, int>& b
        ){
            return a.second<b.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(int i=0;i<nums.size();i++){
            if(map.find(nums[i])!=map.end()) map[nums[i]]++;
            else map[nums[i]]=1;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;  
        for(auto& it: map) pq.push(it);
        vector<int> ans;
        while(k--){
            pair<int, int> top=pq.top();
            int num=top.first;
            ans.push_back(num);
            pq.pop();
        }
        return ans;
    }
};

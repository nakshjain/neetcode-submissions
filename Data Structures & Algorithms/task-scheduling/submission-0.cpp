class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for(char c: tasks) count[c-'A']++;
        priority_queue<int> pq;
        for(int i: count) if(i) pq.push(i);
        int ans=0;
        while(!pq.empty()){
            vector<int> tmp;
            int toPop = min(n+1, (int)pq.size());
            while(toPop--){
                tmp.push_back(pq.top());
                pq.pop();
            }
            for(int i: tmp){
                if(i-1) pq.push(i-1);
            }
            ans+=pq.empty() ? tmp.size() : n+1;
        }
        return ans;
    }
};

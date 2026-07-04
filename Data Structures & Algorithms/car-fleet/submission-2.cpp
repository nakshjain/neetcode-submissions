class Solution {
public:
    struct Compare{
        bool operator()(const pair<int, float>& a, const pair<int, float>& b){
            return a.first < b.first;
        }
    };

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, float>> combine;
        for(int i=0;i<position.size();i++){
            int d=target-position[i];
            float time=(float)d/speed[i];
            combine.push_back({position[i], time});
        }
        sort(combine.begin(), combine.end(), Compare());
        int ans=0;
        stack<pair<int, float>> st;
        for(int i=0;i<combine.size();i++){
            st.push(combine[i]);
        }
        while(!st.empty()){
            float currTime=st.top().second;
            st.pop();
            while(!st.empty() && st.top().second<=currTime){
                st.pop();
            }
            ans++;
        }
        return ans;
    }
};

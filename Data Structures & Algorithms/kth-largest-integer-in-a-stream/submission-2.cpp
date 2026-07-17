class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int size=0;
    KthLargest(int k, vector<int>& nums) {
        int n = nums.size(), i=0;
        size=k;
        while(i<n){
            pq.push(nums[i]);
            i++;
        }
        i=0;
        while(i<n-k){
            pq.pop();
            i++;
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>size) pq.pop();
        int top = pq.top();
        return top;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyPrice=prices[0], profit=0;
        for(int i=1;i<prices.size();i++){
            int curr=prices[i]-buyPrice;
            if(curr>profit) profit=curr;
            else if(buyPrice>prices[i]) buyPrice=prices[i];
        }
        return profit;
    }
};

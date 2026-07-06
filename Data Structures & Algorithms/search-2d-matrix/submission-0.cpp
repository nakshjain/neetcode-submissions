class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix[0].size(), n=matrix.size(), l=0, r=(m*n)-1, i=0, j=0;
        while(l<=r){
            int mid = l +(r-l)/2;
            i=mid/m;
            j=mid%m;
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]<target) l=mid+1;
            else r=mid-1;
        }
        return false;
    }
};

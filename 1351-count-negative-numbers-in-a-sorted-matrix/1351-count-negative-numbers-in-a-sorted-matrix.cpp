class Solution {
public:
    int find(vector<int> a){
        int high = a.size()-1;
        int low =0;
        int mid = 0;
        while(low<=high){
            mid = (low+high)/2;
            if(a[mid]<0){
                high = mid -1;
            }
            else{
                low = mid +1;
            }
        }
        return (a.size()-high-1);
    }
    int countNegatives(vector<vector<int>>& grid) {
        int n1 = grid.size();
        int sum = 0;
        for(int i=0;i<n1;i++){
            sum+=find(grid[i]);
        }
        return sum;
    }
};
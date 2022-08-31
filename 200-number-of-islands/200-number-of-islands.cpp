class Solution {
public:
    void find_island(int x,int y,vector<vector<char>>& grid,int r,int c){
     if(x<0 || y<0 || x>=r || y>=c || grid[x][y] != '1'){
     return ;
     }
        grid[x][y]='2';
        find_island(x,y+1,grid,r,c);
         find_island(x+1,y,grid,r,c);
         find_island(x-1,y,grid,r,c);
         find_island(x,y-1,grid,r,c);
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if(row == 0){
            return 0;
        }
        int island = 0;
        int col = grid[0].size();
        for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
        if(grid[i][j]=='1'){
            find_island(i,j,grid,row,col);
            island+=1;
        }
        }
        }
        return island;
    }
};
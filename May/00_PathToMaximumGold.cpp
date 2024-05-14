
// https://leetcode.com/problems/path-with-maximum-gold/description/

// In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

// Return the maximum amount of gold you can collect under the conditions:

// Every time you are located in a cell you will collect all the gold in that cell.
// From your position, you can walk one step to the left, right, up, or down.
// You can't visit the same cell more than once.
// Never visit a cell with 0 gold.
// You can start and stop collecting gold from any position in the grid that has some gold.
 

 // hindi  version m smjhte h abh
 // hme maximum value of gold nikali h 
 // ek step m ek direction m jaa skte h  ( top down right left) --- chaaro direction m se max nikalna h + jis block  m ho uski ki gold ki value 

 // shuru khi  se bhi krlo  ( jhn value 0 nh whn se krlo bro)
 // toh phir isko solve krne k liye hm bfs use kre ya dfs 

 // bfs toh less time k liye krte h jaise (rotter oranges m kiye the )  or dfs se saari possibilty dekhenge but sirf dfs se kaam nhi chlega hme backtracking bhi use krenge boss
 // Approach - DFS + backtracking 


 // chlo ek example p dry run krte h sir

 // 0 6 0 
 // 5 8 7
 // 0 9 0   // ans = 24

 // 6-->(top , down , right , left ) -->(0,down (explore), 0 , 0 ) --> down (6 ko abhi k 0 krdenge jisse ki uspe dobra nh jaye)(8-->(top , down , right , lef)--->(0,down(explore),right(explore),left(explore))-->asie explore or jo maximum value ayegi woh + us block ki value )
  // or har bar check krenge ki ans max h ya computed ans uske according update kr denge


  // chlo abh issi baat p code krte h guyss 
#include<bits/stdc++.h>
using namespace std;


int dfs(int i , int j , vector<vector<int>>&grid){
  int n = grid.size();
  int m = grid[0].size();

  if(i<0 || i>=n || j<0 || j>=m || grid[i][j] == 0){
    return 0;
  }
  int gold = grid[i][j];
  grid[i][j] = 0;
  int maxPath = max(dfs(i-1,j,grid),max(dfs(i+1,j,grid),max(dfs(i,j+1,grid),dfs(i,j-1,grid))));
  grid[i][j] = gold; // backtrack
  return maxPath+gold;



}
int getMaximumGold(vector<vector<int>>& grid) {

  int  n = grid.size();
  int m = grid[0].size();
  int ans =0;
  for(int i =0;i<n;i++){
    for(int j =0;j<m;j++){
      if(grid[i][j]!=0){
          ans = max(ans, dfs(i,j,grid));
      }
    

    }
  }
  return ans;
        
}

int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<int>> grid;
  for(int i=0;i<n;i++){
    vector<int> temp;
    for(int j =0;j<m;j++){
      int x;
      cin>>x;
      temp.push_back(x);
    }
    grid.push_back(temp);
  }

  int result = getMaximumGold(grid);
  cout<< result << endl;
  return 0;
}
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 

    //Function to find minimum time required to rot all oranges. 
    
    {
    public:
        int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> q;
        vector<pair<int,int>> changes{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        if(q.size() == 0) return 0;
        int count = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto node = q.front(); q.pop();
                int x = node.first, y = node.second;
                for(auto change : changes){
                    int xt = x+change.first;
                    int yt = y+change.second;
                    if(xt < n && xt >= 0 && yt < m && yt>=0){
                        if(grid[xt][yt] == 1){
                            grid[xt][yt] = 2;
                            q.push({xt, yt});
                        }
                    }
                }
            }
            count++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return count-1;
    
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
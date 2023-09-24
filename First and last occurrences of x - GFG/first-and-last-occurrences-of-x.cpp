//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {   vector<int>v;
    int cnt=0;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
            
        }
        for(int i=0;i<n;i++){
            if(arr[i]==x){
                v.push_back(i);
                v.push_back(m[arr[i]]+i-1);
            }
            else {
                cnt++;
            } 
        }
        if(cnt==n){
            v.push_back(-1);
                v.push_back(-1);
        }
        
        
       return v; 
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends
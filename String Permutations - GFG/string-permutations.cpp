//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    
    vector<string> permutation(string S)
    {  int n=S.length();
       vector<string>v;
       long long p=1;
       for(int i=1;i<=S.length();i++){
            p*=i;
       }
       string k=S;
       v.push_back(S);
      next_permutation(k.begin(),k.end());
       long long i=2;
       while(i<=p){
            v.push_back(k);
           next_permutation(k.begin(),k.end());
          
           i++;
       }
       sort(v.begin(),v.end());
       return v;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


void printCorner(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}



int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        printCorner(root);
        cout<<endl;
    }
    return 0;
}









// } Driver Code Ends


/* Function to print corner node at each level */

/*
Structure of a node is as following
struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};
*/

    void levelOrder(Node *root, vector<vector<int>> &ans)
{
    if(root==NULL)
    return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        vector<int> v;
        for(int i=0;i<size;i++)
        {
            Node* node=q.front();
            q.pop();
            if(node->left)
            {
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }
            v.push_back(node->data);
        }
        ans.push_back(v);
    }
    return;
}
void printCorner(Node *root)
{

// Your code goes here
vector<vector<int>> ans;
levelOrder(root, ans);
for(int i=0;i<ans.size();i++)
{
   for(int j=0;j<ans[i].size();j++)
   {
       if(ans[i].size()==1)
       {
           cout<<ans[i][j]<<" ";
       }
       else if(j==0)
       {
           cout<<ans[i][j]<<" ";
       }
       else if(j==ans[i].size()-1)
       {
           cout<<ans[i][j]<<" ";
       }
   }
}
}




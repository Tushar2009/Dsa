#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node (int x)
    {
        data=x;
        left=right=NULL;
    }
};
// Time complexity is O(nlog(hd)) hd= Total no. of possible horizontal distances.
void Bottomview(Node *root)
{
    map<int,int> mp;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(q.empty()==false)
    {
        auto p = q.front();
        Node *curr=p.first;
        int hd=p.second;
        mp[hd]=curr->data;
        q.pop();
        if(curr->left!=NULL)
        {
            q.push({curr->left,hd-1});
        }
        if(curr->right!=NULL)
        {
            q.push({curr->right,hd+1});
        }
    }
   for(auto x:mp){
        cout<<x.second<<" ";
    }
}
int main() {
	
	Node *root = new Node(10);  
    root->left = new Node(20);  
    root->right = new Node(30);  
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    
    Bottomview(root);
          
    return 0;  
	
}
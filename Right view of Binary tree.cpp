#include<bits/stdc++.h>
using namespace std;
class node{
	public:
	int data;
	node *left;
	node *right;
	node(int d)
	{
		data = d;
	    left = NULL;
		right = NULL;
	}
};

node *build()
{
	queue<node *> q;
	int d;
	cin>>d;
	
	node *root = new node(d);
	q.push(root);
	while(!q.empty())
	{
		node *f = q.front();
		q.pop();
		int l,r;
		cin>>l>>r;
		
		if(l != -1)
		{
			f->left = new node(l);
			q.push(f->left);
		}
	
		 if(r != -1)
		{

		   f->right = new node(r);
		   q.push(f->right);
		}
        
	}

	return root;
}
vector<int> v;
int max_level = -1;
void helper(node *root,int level)
{
	if(root ==  NULL)
	 return;
	if(level > max_level)
	{
		max_level = level;
		v.push_back(root->data);

	}
	helper(root->right,level+1);
	helper(root->left,level+1);
}
void rightview(node *root)
{
	helper(root,0);
} 
int main()
{
  node *root = build();
  rightview(root);
  for(int i=0;i<v.size();i++)
   cout<<v[i]<<" ";
  return 0;
}

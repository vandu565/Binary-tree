#include<iostream>
#include<queue>
#include<string>
using namespace std;
class node{
	public:
		int data;
		node* left;
		node* right;

		node(int d){
			data=d;
			left=NULL;
			right=NULL;
		}
};
node* insert(){
	int d;
	string value;
	cin>>d;
	cin>>value;
	node* root=new node(d);
	if(value=="true"){
		root->left=insert();
	}
	cin>>value;
	if(value=="true"){
		root->right=insert();
	}
	return root;
}

bool compare(node* root1,node* root2){
	if(root1==NULL&&root2==NULL)
		return true;
	else if(root1==NULL&&root2!=NULL)
		return false;
	else if(root1!=NULL&&root2==NULL)
		return false;

	if(root1!=NULL&&root2!=NULL){
	bool left=compare(root1->left,root2->left);
	bool right=compare(root1->right,root2->right);
	return (left&&right);
	}
}
void print(node* root){
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	print(root->left);
	print(root->right);
}
int main(){
	node* root1=NULL;
	node* root2=NULL;
	root1=insert();
	root2=insert();
	if(compare(root1,root2)){
		cout<<"true\n";
	}
	else
		cout<<"false\n";
	return 0;
}

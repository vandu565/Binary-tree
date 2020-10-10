vector<int> result;
int recurse(TreeNode* root, int k, TreeNode* target){
if(root==NULL)return -1;
else if(root ==target){
percolateDown(root, k);
reutrn 1 // distance of my own value}
else{
int L=recurse(root->left);
int R=recurse(root->right);
if(L!=1){
if(L==K) result.push_back(root->val);
percolateDown(root,K-L-1);
reutrn L+1;
}
else if(R!=1){
if(R==K) result.push_back(root->val);
percolateDown(root,K-R-1);
reutrn R+1;
}
else return -1;

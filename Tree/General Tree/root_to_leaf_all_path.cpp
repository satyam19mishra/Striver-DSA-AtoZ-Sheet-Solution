
//GFG solution
void path_to_leaf(Node* root,vector<vector<int>>&ans,vector<int>&temp){
    if(root->left==NULL and root->right==NULL){
        temp.push_back(root->data);
        ans.push_back(temp);
        temp.pop_back();
        return;
    }
    temp.push_back(root->data);
    if(root->left) path_to_leaf(root->left,ans,temp);
    if(root->right) path_to_leaf(root->right,ans,temp);
    
    temp.pop_back();
    return;
} 

vector<vector<int>> Paths(Node* root){
    vector<vector<int>> ans;
    vector<int> temp;
    path_to_leaf(root,ans,temp);
    return ans;
}

//TC - O(N)
//SC -O(N)  <--- recursive stack space 
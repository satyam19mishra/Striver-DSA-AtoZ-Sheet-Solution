void post_trav(Node* root, vector<int>&ans){
    if(root==NULL) return ;
    post_trav(root->left,ans);
    post_trav(root->right,ans);
    ans.push_back(root->data);
}
vector <int> postOrder(Node* root){
    vector<int> ans;
    post_trav(root,ans);
    return ans;
}

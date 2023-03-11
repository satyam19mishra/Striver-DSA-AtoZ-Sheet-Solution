//Function to return a list containing the preorder traversal of the tree.
 void pre_order(Node*root,vector<int>& ans){
        if(root==NULL) return ;
        
        ans.push_back(root->data);
        
        pre_order(root->left,ans);
        
        pre_order(root->right,ans);
    }
    vector<int> preorder(Node* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        pre_order(root,ans);
        return ans;
    }

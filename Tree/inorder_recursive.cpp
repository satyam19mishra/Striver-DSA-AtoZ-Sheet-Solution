class Solution {
    private:
    void in_trav(Node* root, vector<int>&ans){
        if(root==NULL) return ;
        in_trav(root->left,ans);
        ans.push_back(root->data);
        in_trav(root->right,ans);
    }
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int> ans;
        in_trav(root,ans);
        return ans;
    }
};

//approach
// First traverse left boundary excluding leaf (go left and left and if left doesnt exist go right)
// Secondly add entire leaf in ans array by traversing in inorder manner otherwise leaf order will be wrong
// finally traverse right boundary excluding leaf (go right and right if right doesnt exist then go left) 
// and push value in stack finaly pop from stack and push it in ans array because we need it in reverse order


//GFG solution
class Solution {
public:
    bool isLeaf(Node* root){
        if(root->left==NULL and root->right==NULL) return true;
        return false;
    }
    
    // traversing the left boundary
    void add_left_boundary(Node* root,vector<int>&ans){
        Node* curr = root->left;
        while(curr){
            if(!isLeaf(curr)) ans.push_back(curr->data);
            if(curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }
    
    //traversing the right boundary
    void add_right_boundary(Node* root, vector<int>&ans){
        Node* curr = root->right;
        vector<int> temp;
        while(curr){
            if(!isLeaf(curr)) temp.push_back(curr->data);
            if(curr->right) curr = curr->right;
            else curr = curr ->left;
        }
        for(int i=temp.size()-1;i>=0;i--){
            ans.push_back(temp[i]);
        }
    }
    
    //adding the leaf node
    void add_leaf_node(Node* root, vector<int>&ans){
        if(isLeaf(root)){
            ans.push_back(root->data);
            return;
        }
        if(root->left) add_leaf_node(root->left,ans);
        if(root->right) add_leaf_node(root->right,ans);
        return;
    }
    vector <int> boundary(Node *root){
        vector<int> ans;
        if(!root) return {};
        if(!isLeaf(root)) ans.push_back(root->data);
        
        add_left_boundary(root,ans);
        add_leaf_node(root,ans);
        add_right_boundary(root,ans);
        
        return ans;
    }
};

//TC - O(N)
//SC -O(N)

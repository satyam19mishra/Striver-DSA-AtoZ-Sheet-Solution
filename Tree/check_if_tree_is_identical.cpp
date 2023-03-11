   
//GFG solution
class Solution
{
    public:
    bool is_identical(Node* root1,Node*root2){
        if(root1==NULL and root2==NULL) return true;
        if(root1==NULL and root2!=NULL) return false;
        if(root1!=NULL and root2==NULL) return false;
        
        if(root1->data!=root2->data) return false;
        
        bool left = is_identical(root1->left,root2->left);
        bool right = is_identical(root1->right,root2->right);
        
        return left && right;
    }
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2){
    return is_identical(r1,r2);
}
};
//GFG solution
class Solution{
    public:
    pair<int,bool> is_balanced(Node* node){
        if(node==NULL){
            pair<int,bool> obj;
            obj.first = 0;
            obj.second = true;
            return obj;
        }
        pair<int,bool> left = is_balanced(node->left);
        pair<int,bool> right = is_balanced(node->right);
        
        int height = 1 + max(left.first , right.first);
        bool balanced = (abs(left.first-right.first) <=1 && left.second && right.second);
        
        pair<int,bool> obj;
        obj.first = height;
        obj.second = balanced;
        return obj;
    }
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root){
        pair<int,bool> obj =  is_balanced(root);
        return obj.second;
    }
};
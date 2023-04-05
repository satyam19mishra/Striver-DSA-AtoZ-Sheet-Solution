//GFG solution

/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */


// approach-1 TC - O(N)
class Solution {
  public:
    
    int height(Node* node,int& diameter){
        if(node==NULL) return 0;
        int left_h = height(node->left,diameter);
        int right_h = height(node->right,diameter);
        
        diameter = max(diameter,left_h + right_h);
        
        return (1 + max(left_h,right_h));
    }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // Your code here
        int diameter = 0;
        height(root,diameter);
        return diameter +1 ;
    }
};

// Approach-2 TC - O(N)

class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    pair<int,int> diam(Node*root){
        if(root==NULL){
            pair<int,int> p;
            p.first = 0;
            p.second = 0;
            return p;
        }
         pair<int,int> left_diam = diam(root->left);
         pair<int,int> right_diam = diam(root->right);
         
         int height = max(left_diam.first,right_diam.first) + 1;
         int d_iam = max((left_diam.first + right_diam.first) , max(left_diam.second,right_diam.second));
         
         pair<int,int> p;
         p.first = height;
         p.second = d_iam;
         return p;
    }
    int diameter(Node* root) {
        pair<int,int> p = diam(root);
        return p.second + 1;
    }
};

// note - bruteforce will be O(N*N) because we need to find the height of the tree at every node
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


class Solution {
  public:
  
   int find_path_sum(Node* root,int& max_sum){
       if(root==NULL) return 0;
       
      int left_sum = max(0,find_path_sum(root->left,max_sum));
      int right_sum = max(0,find_path_sum(root->right,max_sum));
      
      max_sum = max(max_sum,root->data +left_sum+right_sum);
      
      return root->data + max(left_sum,right_sum);
    }
    //Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node* root){
       int max_sum=INT_MIN;
       find_path_sum(root,max_sum);
       return max_sum;
    }
};

// TC -O(N)
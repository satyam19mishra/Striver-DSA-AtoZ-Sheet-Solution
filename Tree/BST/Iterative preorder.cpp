//GFG solution
class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int> ans;
        Node* node = root;
        stack<Node*> st;
 
        while(true){
            if(node!=NULL){
                st.push(node);
                node = node->left;
            }
            else{
                if(st.empty()==true) break;
                node = st.top();
                st.pop();
                ans.push_back(node->data);
                node = node->right;
            }
        }
        return ans;
    }
};

//Time complexity - O(N)
//Space complexity - O(stack space N) + O(ans array -N) = O(N)

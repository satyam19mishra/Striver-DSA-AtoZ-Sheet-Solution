//GFG solution
//Function to return a list containing the postorder traversal of the tree.
vector <int> postOrder(Node* root){
    vector<int> ans;
    
    stack<Node*> st_one;
    stack<int> st_two;
    
    st_one.push(root);
    while(!st_one.empty()){
        Node* node = st_one.top();
        st_one.pop();
        if(node->left) st_one.push(node->left);
        if(node->right) st_one.push(node->right);
        st_two.push(node->data);
    }
    while(!st_two.empty()){
        ans.push_back(st_two.top());
        st_two.pop();
    }
    return ans;
}

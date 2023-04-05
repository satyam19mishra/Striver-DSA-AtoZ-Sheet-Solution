   
//GFG solution
class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root){
        vector<vector<int>> result;
        vector<int> ans;
        queue<Node*> q;
        q.push(root);
        bool LeftToRight = true;
        while(!q.empty()){
            int size = q.size();
            vector<int> row(size);
            for(int i=0;i<size;i++){
                Node* node = q.front();
                q.pop();
                
                int index = LeftToRight ? i : size-1-i;
                
                row[index] = node->data;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            LeftToRight = !LeftToRight;
            result.push_back(row);
        }
        for(int i=0;i<result.size();i++){
            for(int j=0;j<result[i].size();j++){
                ans.push_back(result[i][j]);
            }
        }
        return ans;
    }
};

//TC - O(N)
//SC -O(N)
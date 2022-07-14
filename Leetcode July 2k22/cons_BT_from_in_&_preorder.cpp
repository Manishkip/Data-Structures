class Solution {
public:
    unordered_map<int, int> mp;
    int p=0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); ++i) mp[inorder[i]]=i;
        return tree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
    
    TreeNode* tree(vector<int>& pre, int lpre, int hpre, vector<int>& in, int lin, int hin) {
        if(lin>hin) return NULL;
        TreeNode* root=new TreeNode(pre[p++]);
        int index=mp[root->val];
        root->left=tree(pre, lpre+1, lpre+index, in, lin, index-1);
        root->right=tree(pre, lpre+index+1, hpre, in, index+1, hin);
     return root;
    }
};

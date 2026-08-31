class Solution {
public:

    vector<vector<int>> verticalTraversal(TreeNode* root)
    {
        map<int, map<int, multiset<int>>> nodes;

        queue<pair<TreeNode*, pair<int,int>>> q;

        q.push({root, {0, 0}});

        while(!q.empty())
        {
            auto p = q.front();
            q.pop();

            TreeNode* node = p.first;

            int row = p.second.first;
            int col = p.second.second;

            nodes[col][row].insert(node->val);

            if(node->left != NULL)
            {
                q.push({
                    node->left,
                    {row + 1, col - 1}
                });
            }

            if(node->right != NULL)
            {
                q.push({
                    node->right,
                    {row + 1, col + 1}
                });
            }
        }

        vector<vector<int>> ans;

        for(auto p : nodes)
        {
            vector<int> temp;

            for(auto q : p.second)
            {
                temp.insert(
                    temp.end(),
                    q.second.begin(),
                    q.second.end()
                );
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
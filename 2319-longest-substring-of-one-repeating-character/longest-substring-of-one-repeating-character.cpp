class Solution {
public:
    struct Node {
        char leftChar, rightChar;
        int leftRun, rightRun;
        int best;
        int length;

        Node() {}

        Node(char c) {
            leftChar = c;
            rightChar = c;
            leftRun = 1;
            rightRun = 1;
            best = 1;
            length = 1;
        }
    };

    vector<Node> tree;

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        int k = queryIndices.size();

        tree.resize(4 * n + 5);
        build(s, 1, 0, n - 1);

        vector<int> answer(k);

        for (int i = 0; i < k; i++) {
            int index = queryIndices[i];
            char newChar = queryCharacters[i];
            update(1, 0, n - 1, index, newChar);
            answer[i] = tree[1].best;
        }

        return answer;
    }

private:
    void build(string &s, int node, int left, int right) {
        if (left == right) {
            tree[node] = Node(s[left]);
            return;
        }

        int mid = left + (right - left) / 2;
        build(s, node * 2, left, mid);
        build(s, node * 2 + 1, mid + 1, right);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int left, int right, int index, char newChar) {
        if (left == right) {
            tree[node] = Node(newChar);
            return;
        }

        int mid = left + (right - left) / 2;

        if (index <= mid)
            update(node * 2, left, mid, index, newChar);
        else
            update(node * 2 + 1, mid + 1, right, index, newChar);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    Node merge(Node a, Node b) {
        Node result;

        result.length = a.length + b.length;
        result.leftChar = a.leftChar;
        result.rightChar = b.rightChar;

        result.leftRun = a.leftRun;
        if (a.leftRun == a.length && a.rightChar == b.leftChar)
            result.leftRun = a.leftRun + b.leftRun;

        result.rightRun = b.rightRun;
        if (b.rightRun == b.length && a.rightChar == b.leftChar)
            result.rightRun = a.rightRun + b.rightRun;

        result.best = max(a.best, b.best);
        if (a.rightChar == b.leftChar)
            result.best = max(result.best, a.rightRun + b.leftRun);

        return result;
    }
};
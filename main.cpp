#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int left;
    int right;
    TreeNode(int l = -1, int r = -1) : left(l), right(r) {}
};

vector<TreeNode> tree;
vector<int> depth;

void calculateDepths(int node, int currentDepth) {
    if (node == -1) return;
    depth[node] = currentDepth;
    if (tree[node].left != -1) {
        calculateDepths(tree[node].left, currentDepth + 1);
    }
    if (tree[node].right != -1) {
        calculateDepths(tree[node].right, currentDepth + 1);
    }
}

void swapSubtrees(int node) {
    if (node == -1) return;
    swap(tree[node].left, tree[node].right);
}

void inorderTraversal(int node, vector<int>& result) {
    if (node == -1) return;
    inorderTraversal(tree[node].left, result);
    result.push_back(node);
    inorderTraversal(tree[node].right, result);
}

int main() {
    int n;
    cin >> n;
    
    tree.resize(n + 1);
    depth.resize(n + 1);
    
    // Read tree structure
    for (int i = 1; i <= n; i++) {
        int left, right;
        cin >> left >> right;
        tree[i] = TreeNode(left, right);
    }
    
    // Calculate depths starting from root (node 1)
    calculateDepths(1, 1);
    
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int k;
        cin >> k;
        
        // Find all nodes with depth that is multiple of k
        for (int node = 1; node <= n; node++) {
            if (depth[node] % k == 0) {
                swapSubtrees(node);
            }
        }
        
        // Perform inorder traversal
        vector<int> result;
        inorderTraversal(1, result);
        
        // Output result
        for (int val : result) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}
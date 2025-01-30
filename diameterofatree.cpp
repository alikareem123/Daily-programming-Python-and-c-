#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int dat) : data(dat), left(nullptr), right(nullptr) {}
};
int diameter(Node *root)
{
    int diameter = 0;

    height(root, diameter);

    return diameter;
}
int height(Node *root, int &diameter)
{
    if (root == nullptr)
        return 0;
    int lH = height(root->left, diameter);
    int rH = height(root->right, diameter);

    int maxdiameter = lH + rH;
    diameter = max(diameter, maxdiameter);

    return 1 + max(lH, rH);
}

bool isLeaf(Node *root)
{
    return !root->left && !root->right;
}
void addLeftBoundary(Node *root, vector<int> res)
{
    Node *curr = root->left;
    while (curr)
    {
        if (!isLeaf(curr))
        {
            res.push_back(curr->data);
        }
        if (curr->left)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
}
void addRightBoundary(Node *root, vector<int> res)
{
    Node *curr = root->right;
    vector<int> temp;
    while (curr)
    {
        if (!isLeaf(curr))
        {
            temp.push_back(curr->data);
        }
        if (curr->right)
        {
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
    }
    for (int i = temp.size() - 1; i > 0; i--)
    {
        res.push_back(temp[i]);
    }
}
void addLeaves(Node *root, vector<int> res)
{
    if (isLeaf(root))
    {
        res.push_back(root->data);
    }
    if (root->left)
    {
        addLeaves(root->left, res);
    }
    if (root->right)
    {
        addLeaves(root->right, res);
    }
}
vector<int> printBoundary(Node *root)
{
    vector<int> res;
    if (!root)
    {
        return res;
    }
    if (!isLeaf(root))
    {
        res.push_back(root->data);
    }

    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);

    return res;
}
vector<vector<int>> zigzagLevel(Node* root){
    vector<vector<int>> result;
    if (root == nullptr)
    {
        return result;  
    }
    queue<Node*> nodesQueue;
    nodesQueue.push(root);
    bool leftToRight = true;

    while (!nodesQueue.empty())
    {
        int size = nodesQueue.size();
        vector<int> row(size);
        for (int i = 0; i < size; i++)
        {
            Node* node = nodesQueue.front();
            nodesQueue.pop();
            
        }
        
    }
    
    
}
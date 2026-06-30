#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;

Node *buildTree(vector<int> pre)
{
    idx++;

    if (pre[idx] == -1)
    {
        return NULL;
    }

    Node *root = new Node(pre[idx]);

    root->left = buildTree(pre);
    root->right = buildTree(pre);

    return root;
}
void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);

    postOrder(root->right);
    cout << root->data << " ";
}
// level order

void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);

    while (q.size() > 0)
    {
        Node *current = q.front();
        q.pop();

        cout << current->data << " ";
        if (current->left != NULL)
        {
            q.push(current->left);
        }
        if (current->right != NULL)
        {
            q.push(current->right);
        }
    }
    cout << endl;
}
// levelwise traversal

void levelWiseOrder(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();

        if (current == NULL)
        {
            cout << endl;

            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << current->data << " ";

            if (current->left)
                q.push(current->left);

            if (current->right)
                q.push(current->right);
        }
    }
}
int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    return max(lh, rh) + 1;
}

int count(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lc = count(root->left);
    int lr = count(root->right);

    return lc + lr + 1;
}

int sumOfNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ls = sumOfNodes(root->left);

    int rs = sumOfNodes(root->right);

    return ls + rs + root->data;
}

void topView(Node *root)
{
    queue<pair<Node *, int>> q;
    map<int, int> m; // Hd,nodevalue//

    q.push({root, 0});
    while (q.size() > 0)
    {
        Node *curr = q.front().first;
        int currHD = q.front().second;
        q.pop();
        if (m.find(currHD) == m.end())
        {
            m[currHD] = curr->data;
        }

        if (curr->left != NULL)
        {
            q.push({curr->left, currHD - 1});
        }
        if (curr->right != NULL)
        {
            q.push({curr->right, currHD + 1});
        }
    }
    for (auto it : m)
    {
        cout << it.second << " ";
    }
    cout << endl;
}

void kthLevel(Node *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 1)
    {
        cout << root->data << " ";
        return;
    }
    kthLevel(root->left, k - 1);
    kthLevel(root->right, k - 1);
}
int main()
{
    vector<int> pre = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node *root = buildTree(pre);
    cout << root->data << endl;
    cout << root->left->data << endl;
    cout << root->right->data << endl;
    preOrder(root);
    cout << "preOrder" << endl;
    inOrder(root);
    cout << "inOrder" << endl;
    postOrder(root);
    cout << "postOrder" << endl;
    cout << "levelOrder" << endl;
    levelOrder(root);

    cout << "levelWiseOrder" << endl;
    levelWiseOrder(root);

    cout << "height of tree" << endl;
    cout << height(root) << endl;

    cout << "count of nodes" << endl;
    cout << count(root) << endl;
    cout << "sum of nodes" << endl;
    cout << sumOfNodes(root);
    cout << endl;

    cout << "topView" << endl;
    topView(root);
    cout << endl;
    kthLevel(root, 2);
    return 0;
}
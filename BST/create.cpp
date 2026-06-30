#include <iostream>
#include <vector>
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

// Insert in BST
Node *insert(Node *root, int val)
{

    if (root == NULL)
    {
        return new Node(val);
    }

    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }

    return root;
}

// Build BST
Node *buildBST(vector<int> arr)
{

    Node *root = NULL;

    for (int val : arr)
    {
        root = insert(root, val);
    }

    return root;
}

// Inorder Traversal
void inorder(Node *root)
{

    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Inorder Successor
Node *getInorderSuccessor(Node *root)
{

    while (root != NULL && root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

// Delete Node in BST
Node *deNode(Node *root, int key)
{

    if (root == NULL)
    {
        return NULL;
    }

    // Search
    if (key < root->data)
    {
        root->left = deNode(root->left, key);
    }

    else if (key > root->data)
    {
        root->right = deNode(root->right, key);
    }

    else
    {

        // Case 1 : No child / Right child only
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // Case 2 : Left child only
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // Case 3 : Two children
        else
        {

            Node *IS = getInorderSuccessor(root->right);

            root->data = IS->data;

            root->right = deNode(root->right, IS->data);
        }
    }

    return root;
}

int main()
{

    vector<int> arr = {3, 2, 1, 5, 6, 4};

    Node *root = buildBST(arr);

    cout << "Before Deletion : ";
    inorder(root);
    cout << endl;

    root = deNode(root, 5);

    cout << "After Deletion : ";
    inorder(root);
    cout << endl;

    return 0;
}
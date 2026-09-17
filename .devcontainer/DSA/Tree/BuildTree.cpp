#include <iostream>
using namespace std;

struct node
{
    node *left;
    int item;
    node *right;
    node(int data)
    {
        item = data;
        left = nullptr;
        right = nullptr;
    }
};

class Btree
{
private:
    node *root;
    int idx;

public:
    Btree()
    {
        root = nullptr;
        idx = -1;
    }

    node *buildTree(int nodes[])
    {
        idx++;
        if (nodes[idx] == -1)
        {
            return nullptr;
        }
        node *newnode = new node(nodes[idx]);
        newnode->left = buildTree(nodes);
        newnode->right = buildTree(nodes);

        return newnode;
    }
    void setRoot(int nodes[])
    {
        root = buildTree(nodes);
    }

    void preorder(node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        cout << root->item << " ";
        preorder(root->left);
        preorder(root->right);
    }
    void inorder(node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        inorder(root->left);
        cout << root->item << " ";
        inorder(root->right);
    }
    void postorder(node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout << root->item << " ";
    }
    void deleteTree(node *current)
    {
        if (current == nullptr)
        {
            return;
        }

        deleteTree(current->left);
        deleteTree(current->right);

        delete current;
    }
    ~Btree()
    {
        deleteTree(root);
    }
};

int main()
{

    int nodes[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Btree tree;
    node *R = tree.buildTree(nodes);
    cout << "Preeorder Traverse: " << endl;
    tree.preorder(R);
    cout << endl;
    cout << "inorder Traversal :" << endl;
    tree.inorder(R);
    cout << endl;
    cout << "postorder traversal : " << endl;
    tree.postorder(R);
    return 0;
}
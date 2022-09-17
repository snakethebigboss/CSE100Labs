#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#ifndef BST_H
#define BST_H

// Representation of an element in the tree
struct Node {
  int val;   // Value of the node
  Node *left;   // Pointer to the left node
  Node *right;  // Pointer to the right node
  Node *parent; // Pointer to the parent node
};

class BST {
  public: 
	enum TraversalOrder { InOrderTrav, PreOrderTrav, PostOrderTrav };

  public:
    BST(); 
    virtual ~BST(); 

    void Insert(int toInsert);
    void Delete(int toDelete);
    void Print(enum TraversalOrder);

  private:
    Node *root;

    Node* Search(int toFind); // Search for a node in the tree
    Node* Successor(Node *curr); // Find the successor of the given node
    Node* Minimum(Node *curr); // Find the minimum node of the given subtree
    Node* Maximum(Node *curr); // Find the minimum node of the given subtree

    void Transplant(Node *a, Node *b); // Replace the subtree rooted at node a with the subtree rooted at node b
    void InOrder(Node *curr); // Inorder traversal
    void PreOrder(Node *curr); // Preorder traversal
    void PostOrder(Node *curr); // Postorder traversal
};

#endif

BST::BST() //Creator
{
    root = NULL;
}

void deltree(Node *x) //Destroyer
{
    if (x != NULL) 
    {
        deltree(x->left);
        deltree(x->right);
        delete x;
    }
}

BST::~BST()
{
}

void BST::Insert(int toInsert)
{
    Node *x;
    Node *y = NULL;
    Node *z = new Node();
    x = root;

    while (x != NULL) 
    {
        y = x;
        if (toInsert < x->val)
        {
            x = x->left;     
        }
        else
        {
            x = x->right;
        }
    }

    z->left = NULL;
    z->right = NULL;
    z->val = toInsert;
    z->parent = y;

    if (y == NULL)
    {
        root = z;
    }
    else if (z->val < y->val)
    {
        y->left = z;
    }
    else
    {
        y->right = z;
    }
}

void BST::Transplant(Node *a, Node *b)
{
    if (a->parent == NULL)
    {
        root = b;
    }
    else if (a == a->parent->left)
    {
        a->parent->left = b;
    }
    else
    {
        a->parent->right = b;
    }
    if (b != NULL)
    {
        b->parent = a->parent;
    }
}

Node *BST::Minimum(Node *x)
{
    while (x->left != NULL)
    {
        x = x->left;
    }

    return x;
}

Node *BST::Maximum(Node *x)
{
    while (x->right != NULL)
    {
        x = x->right;
    }

    return x;
}

Node *BST::Successor(Node *x)
{
    if (x->right != NULL)
    {
        return Minimum(x->right);
    }

    Node *y = y = x->parent;

    while (y != NULL && x == y->right)
    {
        x = y;
        y = y->parent;
    }
}

Node *BST::Search(int toFind)
{
    Node *x = root;

    while (x != NULL && toFind != x->val)
    {

        if (toFind < x->val)
            x = x->left;
        else
            x = x->right;
    }

    if (x == NULL || toFind != x->val)
    {
        return x;
    }
    return x;
}

void BST::Delete(int toDelete)
{
    Node *z = new Node();
    z = BST::Search(toDelete);
    if (z == NULL)
        return;
    else if (z != NULL)
    {
        if (z->left == NULL)
            Transplant(z, z->right);
        else if (z->right == NULL)
            Transplant(z, z->left);
        else
        {
            Node *y = new Node();
            y = Minimum(z->right);
            if (y->parent != z)
            {
                Transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            Transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
        }
    }
}

void BST::PreOrder(Node *x)
{
    if (x != NULL)
    {
        cout << x->val << endl;
        PreOrder(x->left);
        PreOrder(x->right);
    }
}

void BST::InOrder(Node *x)
{
    if (x != NULL)
    {
        InOrder(x->left);
        cout << x->val << endl;
        InOrder(x->right);
    }
}

void BST::PostOrder(Node *x)
{
    if (x != NULL)
    {
        PostOrder(x->left);
        PostOrder(x->right);
        cout << x->val << endl;
    }
}

void BST::Print(TraversalOrder Order)
{
    if (Order == InOrderTrav)
        InOrder(root);
    else if (Order == PreOrderTrav)
        PreOrder(root);
    else if (Order == PostOrderTrav)
        PostOrder(root);
}

int main(int argc, char **argv)
{

    BST Tree;

    // Using a fixed size buffer for reading content is not always safe,
    // but ok here because we know how our input has to be:
    char line[100];

    // Main loop
    while (std::cin.getline(line, 100))
    {
        string str(line);
        if (str.size() == 0)
            continue;
        if (str[0] == 'e')
            return 1;

        // Use cerr if you want to always print to the console, because cout
        // will be redirected to the output file when calling the Grade script:
        // cerr<<line<<endl;

        if (str[0] == 'o')
        {
            if (str.substr(0, 3) == "oin")
            {
                // Todo: in-order-traversal
                Tree.Print(BST::InOrderTrav);
            }
            else if (str.substr(0, 4) == "opre")
            {
                // Todo: pre-order-traversal
                Tree.Print(BST::PreOrderTrav);
            }
            else if (str.substr(0, 5) == "opost")
            {
                // Todo: post-order-traversal
                Tree.Print(BST::PostOrderTrav);
            }
        }
        else
        {
            int key;
            stringstream convert_stm(str.substr(1, str.size() - 1));
            if (!(convert_stm >> key))
            {
                key = -1; // invalid
            }
            if (str.substr(0, 1) == "i")
            {
                // Todo: insert key
                Tree.Insert(key);
            }
            else if (str.substr(0, 1) == "d")
            {
                // Todo: delete key
                Tree.Delete(key);
            }
        }
    }

    return 1;
}
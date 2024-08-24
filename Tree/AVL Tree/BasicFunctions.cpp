#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

struct AVLTree {
    Node* root;
};

// Create a new node
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;

    return newNode;
}

// Calculate height of Node
int height(Node* node) {
    if(node == NULL) return 0;
    return node->height;
}

// Right rotation
Node* rightRotate(Node* x) {
    if(x == NULL) return NULL;
    
    Node* y = x->left;
    Node* z = y->right;

    // rotation
    y->right = x;
    x->left = z;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Left rotation
Node* leftRotate(Node* x) {
    if(x == NULL) return NULL;  

    Node* y = x->right;
    Node* z = y->left;

    // Rotation
    y->left = x;
    x->right = z;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Get balance factor
int getBalance(Node* node) {
    if (node == NULL) return 0;
    return height(node->left) - height(node->right);
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    } else {
        return root;
    }

    // Update height of this node
    root->height = max(height(root->left), height(root->right)) + 1;

    // Get balance 
    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && data < root->left->data) {
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && data > root->right->data) {
        return leftRotate(root);
    }

    // Left Right Case
    if (balance > 1 && data > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && data < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void createAVLTree(AVLTree& T, int a[], int n) {
    T.root = createNode(a[0]);
    for(int i = 1; i < n; i++) {
        T.root = insert(T.root, a[i]);
    }
}

// delete a node with a given value from a given AVL tree
Node* findReplacementNode(Node* node) {
    if(node == NULL) return NULL;

    node = node->right;

    while(node->left != NULL) {
        node = node->left;
    }

    return node;
}

Node* deleteNode(Node* root, int value) {
    if(root == NULL) return NULL;

    if(value > root->data) {
        root->right = deleteNode(root->right, value);
    }

    else if(value < root->data) {
        root->left = deleteNode(root->left, value);
    }

    else {
        if(root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        else {
            Node* temp = findReplacementNode(root);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data); // delete a replacement node
        }
    }

    // update height of current node;
    root->height = max(height(root->left), height(root->right)) + 1;

    // check if the AVL tree is unbalanced

    int balance = getBalance(root);

    // Left - left case
    if(balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }

    // Left - right case
    if(balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right - right case
    if(balance < -1 && getBalance(root->right) < 0) {
        return leftRotate(root);
    }

    // Right - left case
    if(balance < -1 && getBalance(root->right) >= 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Check if the tree is an AVL tree
bool isAVLTree(Node* root) {
    if(root == NULL) return true;

    int balance = getBalance(root);

    if(abs(balance) < 1 && isAVLTree(root->left) && isAVLTree(root->right)) {
        return true;
    }

    return false;
}

// level - order traversal
void levelOrder(AVLTree T) {

    if(T.root == NULL) return;

    queue<Node*> q;
    q.push(T.root);

    while(!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";

        if(current->left != NULL) {
            q.push(current->left);
        }

        if(current->right != NULL) {
            q.push(current->right);
        }
    }
}

int main() {
    AVLTree T;
    int a[] = {44, 17, 32, 78, 50, 62, 48, 88};
    int n = sizeof(a)/sizeof(a[0]);

    createAVLTree(T, a, n);
    cout << "The newly created AVL tree: ";
    levelOrder(T);

    T.root = deleteNode(T.root, 44);
    cout << endl << "The AVL tree after delete a node 44: "; 
    levelOrder(T);
    
    cout << endl;
    if(isAVLTree(T.root)) cout << "This is an AVL tree";
    else cout << "This is not an AVL tree";
}


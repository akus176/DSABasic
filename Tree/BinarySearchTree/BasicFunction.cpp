#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

struct BST {
    Node* root;
};

// Initialize a Node from a given value
Node* createNode(int value) {
    Node* node = new Node;
    node->data = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// Add a node with given value into a given BST
void insert(Node* root, int value) {
    if(root == NULL) return;

    Node* current = root;
    while(current != NULL) {
        if(current->data == value) return;

        if(current->data > value) {
            if(current->left == NULL) {
                current->left = createNode(value);
                return;
            }
            current = current->left;
        }
        else if (current->data < value) {
            if(current->right == NULL) {
                current->right = createNode(value);
                return;
            }
            current = current->right;
        }
    }
}

// Add a node into BST with recursion
Node* insertByRecursion(Node* root, int value) {
    if(root == NULL) {
        return createNode(value);
    }

    else if(value < root->data) {
        root->left = insertByRecursion(root->left, value);
    }
    else if(value > root->data) {
        root->right = insertByRecursion(root->right, value);
    }
    
    return root;
}

// Find and return a node with given value from a given binary search tree
Node* Search(Node* root, int key) {
    if(root == NULL) return NULL;

    Node* current = root;
    while(current != NULL) {
        if(key == current->data) return current;
        else if(key > current->data) current = current->right;
        else current = current->left;
    }

    return NULL;
}

Node* SearchByRecursion(Node* root, int key) {
    if(root == NULL) return NULL;

    if(root->data == key) return root;
    else if(root->data > key) return Search(root->left, key);
    else return Search(root->right, key); 
}
 
 // Remove a node with given value from a given Binary Search Tree

Node* findReplacementNode(Node* current) {
    current = current->right;

    while(current->left != NULL) {
        current = current->left;
    }

    return current;
}

Node* deleteNode(Node* root, int value) {
    if(root == NULL) return NULL;

    if(root->data > value) {
        root->left = deleteNode(root->left, value);
    }
    else if(root->data < value) {
        root->right = deleteNode(root->right, value);
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
            root->right = deleteNode(root->right, temp->data); // delete replacement node
        }
    }

    return root;
}

 void Remove(BST& T, int value) {
    T.root = deleteNode(T.root, value);
 }

// Create BST from array
void createBST(BST& T, vector<int> a) {
    if(T.root == NULL) return;

    for(int i = 0; i < a.size(); i++) {
        insert(T.root, a[i]);
    }
}

void createBSTByRecursion(BST& T, vector<int> a, int i = 0) {
    if(i == a.size()) return;
    T.root = insertByRecursion(T.root, a[i]);
    createBSTByRecursion(T, a, i + 1);
} 

// Completely remove a given BST
void removeTree(Node* &root) {
    if(root == NULL) return;

    removeTree(root->left);
    removeTree(root->right);

    delete root;
    root = NULL;
}

// Caculate a height of node from a given binary search tree
int height(Node* root) {
    if(root == NULL) return -1;
    
    return max(height(root->left), height(root->right)) + 1; 
}

int heightOfNode(Node* root, int value) {
    if(root == NULL) return -1;

    Node* temp = Search(root, value);
    if(temp == NULL) return -1;
    if(temp->left == NULL && temp->right == NULL) return 0;

    return height(temp);
}

// Level-order traversal
void levelOrder (Node* root) {
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);

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
    vector<int> a = {10, 3, 6, 1,12, 13, 4};
    BST T;
    T.root = createNode(8);
    createBSTByRecursion(T, a);
    cout << "Level order traversal on BST: ";
    levelOrder(T.root);

    cout << endl;
    Node* n = SearchByRecursion(T.root, 4);
    if(n == NULL) cout << "Not found";
    else cout << "The node to find is: " << n->data;

    Remove(T, 6);
    cout << endl << "The BST after delete a node 6: ";
    levelOrder(T.root);

    cout << endl << "Height of node 10 in a given BST: " << heightOfNode(T.root, 10);

    removeTree(T.root);
    if(T.root == NULL) cout << endl << "The given BST was completely removed";
}
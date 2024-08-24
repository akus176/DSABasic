#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

struct BinaryTree {
    Node* root = NULL;
};

// Initialize a Node from a given value
Node* createNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// Create Binary Tree from string
void createBinaryTree(Node* root, int parent, int child, char direct) {
    if(root == NULL) return;

    if(root->data == parent) {
        Node* newNode = createNode(child);

        if(direct == 'L') {
            root->left = newNode;
        }
        else root->right = newNode;
    }
    else {
        createBinaryTree(root->left, parent, child, direct);
        createBinaryTree(root->right, parent, child, direct);
    }
}

void solveProblem(string s, BinaryTree& BT) {
    BT.root = createNode(s[0] - '0');

    int parent = 0, child = 0;
    char direct = ' ';

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ' ') continue;

        if(parent == 0) parent = s[i] - '0'; // convert from char type to int type
        else if(child == 0) child = s[i] - '0';
        else if(direct == ' ') direct = s[i];

        if(parent != 0 && child != 0 && direct != ' ') {
            createBinaryTree(BT.root, parent, child, direct);
            parent = 0; 
            child = 0;
            direct = ' ';
        }
    }
}

// Pre-order traversal 
void preOrder(Node* root) {
    if(root == NULL) return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// In-order traversal 
void inOrder(Node* root) {
    if(root == NULL) return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// Post-order traversal
void postOrder(Node* root) {
    if(root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// Level-order traversal
void levelOrder(Node* root) {
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

// Spiral-order traversal 
void spiralOrder(Node* root) {
    stack<Node*> stack1, stack2;

    stack1.push(root);

    while(!stack1.empty() || !stack2.empty()) {
        while(!stack1.empty()) {
            Node* current = stack1.top();
            cout << current->data << " ";
            stack1.pop();

            if(current->right != NULL) {
               stack2.push(current->right);
            }

            if(current->left != NULL) {
                stack2.push(current->left);
            }
        }

        while(!stack2.empty()) {
            Node* current = stack2.top();
            cout << current->data << " ";
            stack2.pop();

            if(current->left != NULL) {
                stack1.push(current->left);
            }

            if(current->right != NULL) {
                stack1.push(current->right);
            }
        }
    }
}

// Calculate a height of binary tree

int heightByRecursion(Node* root) { // O(2n+1) = O(n)

    if(root == NULL) return 0; // or -1

    int heightLeft = heightByRecursion(root->left);
    int heightRight = heightByRecursion(root->right);

    return max(heightLeft, heightRight) + 1;
}

int height(Node* root) {
    if(root == NULL) return 0; // or -1;
    queue<Node*> q;
    q.push(root);

    int height = 0;
    while(!q.empty()) {
        int size = q.size();
        height++;

        // level-order processing
        for(int i = 0; i < size; i++) {
            Node* current = q.front();
            q.pop();

            if(current->left != NULL) {
                q.push(current->left);
            }

            if(current->right != NULL) {
                q.push(current->right);
            }
        }
    }

    return height;
}

// Count the number of Node from a given binary tree
int countNode(Node* root) {
    queue<Node*> q;
    q.push(root);

    int count = 0;
    while(!q.empty()) {
        Node* current = q.front();
        q.pop();
        count++;

        if(current->left != NULL) {
            q.push(current->left);
        }

        if(current->right != NULL) {
            q.push(current->right);
        }
    }

    return count;
}

int countNodeByRecursion(Node* root) {
    if(root == NULL) return 0;

    return countNodeByRecursion(root->left) + countNodeByRecursion(root->right) + 1;
}

// Caculate the total value of all Nodes from a given binary tree
int sumNodeByRecursion(Node* root) {
    if(root == NULL) return 0;

    return sumNodeByRecursion(root->left) + sumNodeByRecursion(root->right) + root->data;
}

// Count the number of leaf node from a given binary tree
int countLeafNodeByRecursion(Node* root) {
    if(root == NULL) return 0;

    if(root->left == NULL && root->right == NULL) return 1;

    int count = 0;
    count += countLeafNodeByRecursion(root->left);
    count += countLeafNodeByRecursion(root->right);

    return count;
}

int main() {
    string s = "1 2 L 1 3 R 2 4 L 2 5 R 3 6 L 3 7 R";
    BinaryTree BT;
    solveProblem(s, BT);
    
    cout << "Pre-order traversal on binary tree: ";
    preOrder(BT.root);

    cout << endl << "In-order traversal on binary tree: ";
    inOrder(BT.root);

    cout << endl << "Post-order traversal on binary tree: ";
    postOrder(BT.root);

    cout << endl << "Level-order traversal on binary tree: ";
    levelOrder(BT.root);

    cout << endl << "Spiral-order traversal on binary tree: ";
    spiralOrder(BT.root);

    int h1 = height(BT.root);
    cout << endl << "Height of binary tree: " << h1;

    int h2 = heightByRecursion(BT.root);
    cout << endl << "Height of binary tree by recursion: " << h2;

    int count1 = countNode(BT.root);
    cout << endl << "Number of node from binary tree: " << count1;

    int count2 = countNodeByRecursion(BT.root);
    cout << endl << "Number of node from binary tree by recursion: " << count2;

    int sum = sumNodeByRecursion(BT.root);
    cout << endl << "Sum of all nodes from a given binary tree: " << sum;

    int count3 = countLeafNodeByRecursion(BT.root);
    cout << endl << "Number of leaf node from a given binary tree: " << count3;

}


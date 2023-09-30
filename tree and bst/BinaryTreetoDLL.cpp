#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Structure for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

// Function to perform in-order traversal of a binary tree
vector<int> inorderTraversal(Node* root) {
    vector<int> result;
    stack<Node*> s;
    Node* curr = root;

    while (curr != NULL || !s.empty()) {
        while (curr != NULL) {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();
        result.push_back(curr->data);

        curr = curr->right;
    }

    return result;
}

// Function to convert a binary tree to a doubly linked list (DLL)
Node* bToDLL(Node* root) {
    // Perform inorder traversal to get the values in sorted order
    vector<int> inorder = inorderTraversal(root);

    Node* head = NULL;
    Node* prev = NULL;

    // Create the DLL using the values from the inorder traversal
    for (int i = 0; i < inorder.size(); i++) {
        Node* newNode = new Node(inorder[i]);

        if (head == NULL) {
            head = newNode;
            prev = newNode;
        } else {
            prev->right = newNode;
            newNode->left = prev;
            prev = newNode;
        }
    }

    return head;
}

// Driver code
int main() {
    // Create a binary tree
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    // Convert the binary tree to a DLL
    Node* dllHead = bToDLL(root);

    // Print the DLL
    Node* curr = dllHead;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->right;
    }

    return 0;
}

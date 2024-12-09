#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Node structure for Binary Tree and Binary Search Tree
// This structure represents a node in the tree containing an integer value,
// and pointers to left and right children.
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Binary Tree Class
// The BinaryTree class implements basic binary tree operations such as insertion, deletion, and traversal.
class BinaryTree {
protected:
    TreeNode* root;  // Root of the binary tree

    // Inserts a new node with the given value into the tree
    virtual void insert(TreeNode*& node, int value) {
        if (!node) {
            node = new TreeNode(value);
            return;
        }
        if (value < node->value) {
            insert(node->left, value);  // Insert to the left subtree
        } else {
            insert(node->right, value); // Insert to the right subtree
        }
    }

    // Deletes a node with the given value from the tree
    TreeNode* deleteNode(TreeNode* node, int value) {
        if (!node) return nullptr;

        if (value < node->value) {
            node->left = deleteNode(node->left, value);  // Move to the left subtree
        } else if (value > node->value) {
            node->right = deleteNode(node->right, value); // Move to the right subtree
        } else {
            // Node with one or no child
            if (!node->left) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children: Get the inorder successor
            TreeNode* temp = findMin(node->right);  // Find the smallest node in the right subtree
            node->value = temp->value;  // Replace current node with the inorder successor
            node->right = deleteNode(node->right, temp->value); // Delete the successor
        }
        return node;
    }

    // Finds the node with the minimum value in the subtree
    TreeNode* findMin(TreeNode* node) {
        while (node && node->left) node = node->left;  // Traverse to the leftmost node
        return node;
    }

    // Searches for a node with the given value in the tree
    TreeNode* search(TreeNode* node, int value) {
        if (!node || node->value == value) return node;  // If the node is null or the value matches
        if (value < node->value) return search(node->left, value);  // Search in the left subtree
        return search(node->right, value);  // Search in the right subtree
    }

    // Preorder traversal (Root, Left, Right)
    void preorder(TreeNode* node) {
        if (node) {
            cout << node->value << " ";  // Visit the root
            preorder(node->left);  // Traverse the left subtree
            preorder(node->right); // Traverse the right subtree
        }
    }

    // Inorder traversal (Left, Root, Right)
    void inorder(TreeNode* node) {
        if (node) {
            inorder(node->left);  // Traverse the left subtree
            cout << node->value << " ";  // Visit the root
            inorder(node->right);  // Traverse the right subtree
        }
    }

    // Postorder traversal (Left, Right, Root)
    void postorder(TreeNode* node) {
        if (node) {
            postorder(node->left);  // Traverse the left subtree
            postorder(node->right); // Traverse the right subtree
            cout << node->value << " ";  // Visit the root
        }
    }

public:
    BinaryTree() : root(nullptr) {}  // Constructor initializes the root to nullptr

    // Public method to insert a value into the binary tree
    virtual void insert(int value) {
        insert(root, value);  // Insert starting from the root
    }

    // Public method to delete a value from the binary tree
    void deleteValue(int value) {
        root = deleteNode(root, value);  // Delete starting from the root
    }

    // Public method to search for a value in the binary tree
    void searchValue(int value) {
        TreeNode* result = search(root, value);
        if (result) {
            cout << "Value " << value << " found in the tree." << endl;
        } else {
            cout << "Value " << value << " not found in the tree." << endl;
        }
    }

    // Public method to perform preorder traversal
    void preorderTraversal() {
        cout << "Preorder Traversal: ";
        preorder(root);  // Perform preorder traversal
        cout << endl;
    }

    // Public method to perform inorder traversal
    void inorderTraversal() {
        cout << "Inorder Traversal: ";
        inorder(root);  // Perform inorder traversal
        cout << endl;
    }

    // Public method to perform postorder traversal
    void postorderTraversal() {
        cout << "Postorder Traversal: ";
        postorder(root);  // Perform postorder traversal
        cout << endl;
    }
};

// Binary Search Tree Class (inherits from BinaryTree)
// This class extends BinaryTree to implement a Binary Search Tree (BST) with the same basic insertions
// and deletions but ensures that the BST properties are maintained.
class BinarySearchTree : public BinaryTree {
protected:
    void insert(TreeNode*& node, int value) override {
        if (!node) {
            node = new TreeNode(value);
            return;
        }
        if (value < node->value) {
            insert(node->left, value);  // Insert in the left subtree
        } else {
            insert(node->right, value); // Insert in the right subtree
        }
    }

public:
    void insert(int value) {
        BinaryTree::insert(value);  // Call the parent class insert method
    }
};

// Heap Class
// This class represents a Heap data structure, which is either a Min-Heap or Max-Heap, depending on the flag.
class Heap {
private:
    vector<int> heap;  // Internal vector to store heap elements
    bool isMinHeap;  // Boolean flag to indicate if the heap is a Min-Heap or Max-Heap

    // Maintains the heap property by moving the element at the given index upwards
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            // If the element violates the heap property, swap it with its parent
            if ((isMinHeap && heap[parent] > heap[index]) || (!isMinHeap && heap[parent] < heap[index])) {
                swap(heap[parent], heap[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    // Maintains the heap property by moving the element at the given index downwards
    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largestOrSmallest = index;

        // Check if the left child exists and is in the correct position
        if (leftChild < heap.size() &&
            ((isMinHeap && heap[leftChild] < heap[largestOrSmallest]) ||
             (!isMinHeap && heap[leftChild] > heap[largestOrSmallest]))) {
            largestOrSmallest = leftChild;
        }

        // Check if the right child exists and is in the correct position
        if (rightChild < heap.size() &&
            ((isMinHeap && heap[rightChild] < heap[largestOrSmallest]) ||
             (!isMinHeap && heap[rightChild] > heap[largestOrSmallest]))) {
            largestOrSmallest = rightChild;
        }

        // If the largest/smallest is not the current element, swap and continue heapifying
        if (largestOrSmallest != index) {
            swap(heap[index], heap[largestOrSmallest]);
            heapifyDown(largestOrSmallest);
        }
    }

public:
    Heap(bool minHeap) : isMinHeap(minHeap) {}  // Constructor to initialize heap type

    // Insert a value into the heap and maintain the heap property
    void insert(int value) {
        heap.push_back(value);  // Add value to the end of the heap
        heapifyUp(heap.size() - 1);  // Move the new element to its correct position
    }

    // Rebuild the heap from scratch by heapifying all nodes
    void heapify() {
        for (int i = (heap.size() / 2) - 1; i >= 0; --i) {
            heapifyDown(i);  // Perform heapify down from the last non-leaf node
        }
    }

    // Traverse and display the heap elements
    void traverse() {
        if (heap.empty()) {
            cout << "Heap is empty." << endl;
            return;
        }
        cout << "Heap: ";
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Delete the root of the heap and maintain the heap property
    void deleteRoot() {
        if (heap.empty()) {
            cout << "Heap is empty, nothing to delete." << endl;
            return;
        }

        if (heap.size() == 1) {
            heap.pop_back();  // Remove the last element if it's the only one
            return;
        }

        // Move the last element to the root and heapify down
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    // Toggle between Min-Heap and Max-Heap and rebuild the heap
    void toggleHeapType() {
        isMinHeap = !isMinHeap;  // Switch the heap type
        heapify();  // Rebuild the heap to adhere to the new property
        cout << (isMinHeap ? "Heap converted to Min-Heap.\n" : "Heap converted to Max-Heap.\n");
    }
};

// Function to handle user input dynamically and ensure valid input
int getInput() {
    int choice;
    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail()) {
            cin.clear();  // Clear the fail state
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
            cout << "Invalid input, please enter a number.\n";
        } else {
            return choice;  // Return valid input
        }
    }
}

// Main Menu Function
int main() {
    int choice;
    do {
        cout << "\n--- Main Menu ---\n";
        cout << "1. Binary Search Tree\n";
        cout << "2. Binary Tree\n";
        cout << "3. Heaps\n";
        cout << "4. Exit\n";
        choice = getInput();  // Get user input for the main menu choice

        switch (choice) {
        case 1: {
            BinarySearchTree bst;  // Create a Binary Search Tree object
            int subChoice;
            do {
                cout << "\nBinary Search Tree Menu\n";
                cout << "1. Insert\n";
                cout << "2. Delete\n";
                cout << "3. Search\n";
                cout << "4. Display Traversals\n";
                cout << "5. Back to Main Menu\n";
                subChoice = getInput();  // Get user input for the BST menu

                // Process each sub-choice based on user input
                if (subChoice == 1) {
                    int value;
                    cout << "Enter value to insert: ";
                    cin >> value;
                    bst.insert(value);  // Insert value into BST
                } else if (subChoice == 2) {
                    int value;
                    cout << "Enter value to delete: ";
                    cin >> value;
                    bst.deleteValue(value);  // Delete value from BST
                } else if (subChoice == 3) {
                    int value;
                    cout << "Enter value to search: ";
                    cin >> value;
                    bst.searchValue(value);  // Search for value in BST
                } else if (subChoice == 4) {
                    bst.preorderTraversal();  // Display preorder traversal
                    bst.inorderTraversal();   // Display inorder traversal
                    bst.postorderTraversal(); // Display postorder traversal
                }
            } while (subChoice != 5);  // Exit back to main menu
            break;
        }
        case 2: {
            BinaryTree bt;  // Create a Binary Tree object
            int subChoice;
            do {
                cout << "\nBinary Tree Menu\n";
                cout << "1. Insert\n";
                cout << "2. Delete\n";
                cout << "3. Search\n";
                cout << "4. Display Traversals\n";
                cout << "5. Back to Main Menu\n";
                subChoice = getInput();  // Get user input for the Binary Tree menu

                // Process each sub-choice based on user input
                if (subChoice == 1) {
                    int value;
                    cout << "Enter value to insert: ";
                    cin >> value;
                    bt.insert(value);  // Insert value into Binary Tree
                } else if (subChoice == 2) {
                    int value;
                    cout << "Enter value to delete: ";
                    cin >> value;
                    bt.deleteValue(value);  // Delete value from Binary Tree
                } else if (subChoice == 3) {
                    int value;
                    cout << "Enter value to search: ";
                    cin >> value;
                    bt.searchValue(value);  // Search for value in Binary Tree
                } else if (subChoice == 4) {
                    bt.preorderTraversal();  // Display preorder traversal
                    bt.inorderTraversal();   // Display inorder traversal
                    bt.postorderTraversal(); // Display postorder traversal
                }
            } while (subChoice != 5);  // Exit back to main menu
            break;
        }
        case 3: {
            int subChoice;
            Heap* currentHeap = nullptr;  // Pointer to store current heap object

            // Heap menu where the user can perform heap operations
            do {
                cout << "\n--- Heaps Menu ---\n";
                cout << "1. Insert into Heap\n";
                cout << "2. Rebuild Heap (Heapify)\n";
                cout << "3. Delete Root\n";
                cout << "4. Toggle Heap Type (Min ↔ Max)\n";
                cout << "5. Back to Main Menu\n";
                subChoice = getInput();  // Get user input for the Heap menu

                // Process each sub-choice based on user input
                if (subChoice == 1) {
                    // If heap doesn't exist, create a new heap
                    if (!currentHeap) {
                        int heapType;
                        do {
                            cout << "Choose heap type (1 for Min-Heap, 2 for Max-Heap): ";
                            cin >> heapType;
                            if (heapType != 1 && heapType != 2) {
                                cout << "Invalid choice. Please enter 1 for Min-Heap or 2 for Max-Heap.\n";
                            }
                        } while (heapType != 1 && heapType != 2);

                        currentHeap = (heapType == 1) ? new Heap(true) : new Heap(false);
                        cout << (heapType == 1 ? "Min-Heap created.\n" : "Max-Heap created.\n");
                    }

                    int value;
                    cout << "Enter value to insert in Heap: ";
                    cin >> value;
                    currentHeap->insert(value);  // Insert value into heap
                    cout << "Value inserted successfully.\n";
                    currentHeap->traverse();  // Display the heap
                } else if (subChoice == 2) {
                    // Rebuild the heap (heapify operation)
                    if (currentHeap) {
                        currentHeap->heapify();
                        cout << "Heap rebuilt successfully:\n";
                        currentHeap->traverse();
                    } else {
                        cout << "No heap exists. Please create a heap first.\n";
                    }
                } else if (subChoice == 3) {
                    // Delete the root from the heap
                    if (currentHeap) {
                        currentHeap->deleteRoot();
                        cout << "Root deleted successfully.\n";
                        currentHeap->traverse();
                    } else {
                        cout << "No heap exists. Please create a heap first.\n";
                    }
                } else if (subChoice == 4) {
                    // Toggle between Min-Heap and Max-Heap
                    if (currentHeap) {
                        currentHeap->toggleHeapType();
                        currentHeap->traverse();
                    } else {
                        cout << "No heap exists. Please create a heap first.\n";
                    }
                }
            } while (subChoice != 5);  // Exit back to main menu

            delete currentHeap;  // Clean up memory after heap operations
            break;
        }
        case 4:
            cout << "Exiting program...\n";  // Exit the program
            break;
        default:
            cout << "Invalid choice, please try again.\n";  // Invalid choice handler
        }
    } while (choice != 4);  // Exit when the user chooses option 4

    return 0;  // Return 0 to indicate successful execution
}

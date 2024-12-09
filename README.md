# Binary Tree, Binary Search Tree, and Heap Implementation

## Contributors
- [Kristine O. Villanueva](https://github.com/szeistin)
- [Trisha Mae Repolona](https://github.com/TRISHAMAER)
- [Jemiel Honradez](https://github.com/Jemhonradez)

---
## Project Overview

This project demonstrates the implementation of three fundamental data structures in C++:
1. **Binary Tree**
2. **Binary Search Tree (BST)**
3. **Heap (Min-Heap and Max-Heap)**

The program provides a user-friendly interface to interact with these data structures and explore their core functionalities, including:
- Insertion, Deletion, and Searching.
- Traversals (Preorder, Inorder, Postorder for trees).
- Heap operations like heapification and visualization of Min-Heap and Max-Heap.

The primary goal is to help users understand and work with these essential data structures while visualizing their behavior and operations in real-time.

---

## How to Run the Code

### INSTRUCTIONS: Choosing a Data Structure:

- Choose **1** for **Binary Search Tree**.
- Choose **2** for **Binary Tree**.
- Choose **3** for **Min Heap**.
- Choose **4** for **Max Heap**.
- Choose **5** to exit the program.

### 4. Performing Operations:

#### For **Binary Search Tree (BST)**:
- **Insert**: Insert a value by choosing the Insert option. The program will prompt you to enter a value, and it will be inserted into the tree.
- **Display Traversals**: Display the tree in different traversal orders (Preorder, Inorder, Postorder).
- **Search**: Search for a value by choosing the Search option and entering the value you want to find.
- **Delete**: Delete a node by selecting the Delete option and entering the value of the node you want to remove.

#### For **Binary Tree**:
- **Insert**: Insert a node into the binary tree.
- **Display Traversals**: Display the tree in Preorder, Inorder, or Postorder format.
- **Search**: Search for a node by entering the value.
- **Delete**: Delete a node by entering the value, and the node will be removed.

#### For **Min and Max Heaps**:
- **Insert**: Insert values into the Min-Heap or Max-Heap.
- **Display Heap**: After each insertion, you can display the heap to view its structure. In a **Min-Heap**, the smallest value will always be at the root, and in a **Max-Heap**, the largest value will be at the root.

### 5. Exiting the Program:
You can exit the program at any time by selecting **Exit** from the Main Menu.

---

## Description of Each Functionality

### 1. **Binary Tree**
- **Insertion**: Adds nodes to the binary tree without a specific order.
- **Deletion**: Removes a node by value while maintaining the tree structure.
- **Search**: Checks if a specific value exists in the binary tree.
- **Traversals**:
  - Preorder: Visit the root, then the left subtree, and finally the right subtree.
  - Inorder: Visit the left subtree, then the root, and finally the right subtree.
  - Postorder: Visit the left subtree, then the right subtree, and finally the root.

### 2. **Binary Search Tree (BST)**
- **Insertion**: Adds nodes while maintaining the property: `left < root < right`.
- **Deletion**: Removes nodes, ensuring the BST property is preserved.
- **Search**: Efficiently checks if a value exists in the BST.
- **Traversals**:
  - Preorder: Root -> Left -> Right.
  - Inorder: Left -> Root -> Right (produces sorted order).
  - Postorder: Left -> Right -> Root.

### 3. **Heap**
- **Min-Heap**:
  - Ensures the smallest element is always at the root.
  - Maintains the heap property during insertions.
- **Max-Heap**:
  - Ensures the largest element is always at the root.
  - Maintains the heap property during insertions.
- **Heapify**: Converts an unordered list into a valid heap structure.
- **Traversal**: Displays the heap as a list of elements.

### Interactive Menu
The program includes an interactive menu where users can:
- Select a data structure to work with.
- Perform operations like insertion, deletion, searching, and traversals for trees.
- Visualize the heap structure for Min-Heap and Max-Heap.

---

## Example Menu
```plaintext
--- Main Menu ---
1. Binary Search Tree
2. Binary Tree
3. Min Heap
4. Max Heap
5. Exit

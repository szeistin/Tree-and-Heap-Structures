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

1. **Prerequisites**:
   - A C++ compiler (e.g., GCC, MinGW, Visual Studio, or Clang).
   - Git (optional, for cloning the repository).

2. **Steps to Compile and Run**:
   - Clone the repository o## Instructions

### Task 1: Insert Superhero Tasks into a Max-Heap
- You will insert superhero tasks (represented by their priority level) into a **Max-Heap**.
- The priority is represented as an integer, where higher values have higher priority.
- After each insertion, the Max-Heap will be displayed as a tree structure.

#### Steps:
1. Input a task's priority level (e.g., 40, 25, 10, etc.).
2. To stop inserting tasks, input `-1`.
3. The heap will be displayed as a tree after each insertion.

---

### Task 2: Remove the Root Task from the Max-Heap
- The root task, which has the highest priority, will be removed from the heap.
- After each deletion, the heap will be displayed as a tree.

#### Steps:
1. The program will automatically remove the root task from the Max-Heap.
2. The updated heap will be displayed after each deletion.

---

### Task 3: Heapify a Random List into a Min-Heap
- You will input a list of integers that represent task priorities.
- The list will be heapified into a **Min-Heap**, and the tree will be displayed.

#### Steps:
1. Enter a list of priorities as space-separated integers (e.g., `30 20 15 5 10`).
2. The list will be displayed as a Min-Heap after conversion.

---
## How to download the source code:
    ```bass
     git clone https://github.com/your-username/your-repository.git
     cd your-repository
     ```
   - Compile the code using a C++ compiler:
     ```bash
     g++ -o main main.cpp
     ```
   - Run the compiled program:
     ```bash
     ./main
     ```

3. **Follow the Menu Options**:
   - Select the data structure you want to work with.
   - Use the sub-menu to perform various operations like insertion, deletion, searching, and traversals.

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

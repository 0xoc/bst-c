# Binary Search Tree in C

This repository contains the implementation and testing of a binary search tree (BST) in C. The BST is a node-based binary tree data structure with the following properties:

- The left subtree of a node contains only nodes with keys less than the node's key.
- The right subtree of a node contains only nodes with keys greater than the node's key.
- Both the left and right subtrees must also be binary search trees.

## Files

The project is divided into two main files:

1. `bst.c`: This file contains the implementation of the binary search tree. It includes functions for inserting a node, deleting a node, and searching for a node in the tree. It also provides three types of tree traversal: inorder, preorder, and postorder.

2. `main.c`: This file includes a series of tests for the implemented BST functions. The tests include:

    - Setting up a test tree.
    - Testing search operation.
    - Testing inorder, preorder, and postorder traversals.
    - Testing delete operation.

## Usage

To use this project, you need a C compiler such as `gcc`. Once you have a compiler installed, you can compile and run the project as follows:

1. Compile the files:
   ```bash
   gcc bst.c main.c -o bst
   ```
2. Run the tests:
   ```bash
   ./bst
   ```
   This will run the series of tests defined in `main.c`.

## Test Cases

The test cases are designed to thoroughly validate the implementation of the binary search tree. They include:

- **Search Test**: Verifies the search operation by searching for all keys in the tree.

- **Inorder Traversal Test**: Verifies inorder traversal, which should visit nodes in ascending order of their keys.

- **Postorder Traversal Test**: Verifies postorder traversal, which should visit the root node last.

- **Preorder Traversal Test**: Verifies preorder traversal, which should visit the root node first.

- **Delete Test**: Verifies the delete operation by deleting the root node and checking the resulting tree structure.

If all tests pass, it indicates that the binary search tree functions are implemented correctly. (to the best of our knowledge at least!)

## Author

Ali Parvizi

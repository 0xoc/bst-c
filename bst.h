//
// Created by spsina on 7/14/23.
//

#ifndef BST_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define BST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int key;
    struct node* left;
    struct node* right;
};

// Function prototypes
struct node* createNode(int key);
struct node* insert(struct node* root, int key);
struct node* search(struct node* root, int key);
struct node* delete(struct node* root, int key);
void inorder(struct node* root, int* result, int* index);
void preorder(struct node* root, int* result, int* index);
void postorder(struct node* root, int* result, int* index);
int* traverseTree(struct node* root, int treeSize, void (*traversalFunc)(struct node*, int* result, int* index));
void freeTree(struct node* root);

#endif

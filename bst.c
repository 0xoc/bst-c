//
// Created by spsina on 7/14/23.
//

#include "bst.h"

struct node* createNode(int key) {
    struct node* _node = (struct node*) malloc(sizeof(struct node));

    _node->key = key;
    _node->left = NULL;
    _node->right = NULL;

    return _node;
}

struct node* insert(struct node* root, int key) {
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    // no duplicate keys in BST, so no operation for case key == root->key

    return root;
}


struct node* search(struct node* root, int key) {
    if (root == NULL || root->key == key)
        return root;

    if (root->key < key)
        return search(root->right, key);

    return search(root->left, key);
}

struct node* delete(struct node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = delete(root->left, key);
    else if (key > root->key)
        root->right = delete(root->right, key);

    // this is the node to be deleted
    else {
        // one child or no child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // smallest in right subtree
        struct node* temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;

        // swap with root
        root->key = temp->key;
        root->right = delete(root->right, temp->key);
    }
    return root;
}


void inorder(struct node* root, int* result, int* index) {
    if (root != NULL) {
        inorder(root->left, result, index);
        result[(*index)++] = root->key;
        inorder(root->right, result, index);
    }
}

void preorder(struct node* root, int* result, int* index) {
    if (root != NULL) {
        result[(*index)++] = root->key;
        preorder(root->left, result, index);
        preorder(root->right, result, index);
    }
}

void postorder(struct node* root, int* result, int* index) {
    if (root != NULL) {
        postorder(root->left, result, index);
        postorder(root->right, result, index);
        result[(*index)++] = root->key;
    }
}

int* traverseTree(struct node* root, int treeSize, void (*traversalFunc)(struct node*, int* result, int* index)) {
    int* result = (int*) malloc(treeSize * sizeof(int));
    int index = 0;

    traversalFunc(root, result, &index);

    return result;
}

void freeTree(struct node* root) {
    if(root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
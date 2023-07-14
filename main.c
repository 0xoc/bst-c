#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

const int TREE_SIZE = 7;
struct node* tree;

struct node* setupTestTree();
void testInorder();
void testPostorder();
void testPreorder();
void testDelete();
void testSearch();

int main() {
    tree = setupTestTree();

    testSearch();
    testInorder();
    testPostorder();
    testPreorder();
    testDelete();

    freeTree(tree);

    return 0;
}

struct node* setupTestTree() {
    struct node* tree = NULL;
    tree = insert(tree, 10);
    tree = insert(tree, 5);
    tree = insert(tree, 15);
    tree = insert(tree, 3);
    tree = insert(tree, 7);
    tree = insert(tree, 13);
    tree = insert(tree, 17);

    return tree;
}

void testSearch() {
    int keys[] = {3, 5, 7, 10, 13, 15, 17};

    for(int i = 0; i < TREE_SIZE; i++) {
        struct node* result = search(tree, keys[i]);
        if (result == NULL || result->key != keys[i]) {
            printf("test search: failed\n");
            return;
        }
    }

    printf("test search: passed\n");
}

void testInorder() {

    int *result = traverseTree(tree, TREE_SIZE, inorder);
    int trueResult[] = {3, 5, 7, 10, 13, 15, 17};

    for(int i = 0; i < TREE_SIZE; i++) {
        if (result[i] != trueResult[i]){
            printf("test inorder: failed\n");
            return;
        }
    }

    free(result);
    printf("test inorder: passed\n");
}

void testPostorder() {
    int *result = traverseTree(tree, TREE_SIZE, postorder);
    int trueResult[] = {3, 7, 5, 13, 17, 15, 10};

    for(int i = 0; i < TREE_SIZE; i++) {
        if (result[i] != trueResult[i]){
            printf("test postorder: failed\n");
            return;
        }
    }

    free(result);
    printf("test postorder: passed\n");
}

void testPreorder() {
    int *result = traverseTree(tree, TREE_SIZE, preorder);
    int trueResult[] = {10, 5, 3, 7, 15, 13, 17};

    for(int i = 0; i < TREE_SIZE; i++) {
        if (result[i] != trueResult[i]){
            printf("test preorder: failed\n");
            return;
        }
    }

    free(result);
    printf("test preorder: passe\n");
}



void testDelete() {
    delete(tree, 10);

    int *result = traverseTree(tree, TREE_SIZE - 1, inorder);

    int trueResult[] = {3, 5, 7, 13, 15, 17};

    for(int i = 0; i < TREE_SIZE - 1; i++) {
        if (result[i] != trueResult[i]){
            printf("test delete: failed\n");
            return;
        }
    }

    free(result);

    printf("test delete: passed\n");
}
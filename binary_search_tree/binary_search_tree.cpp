#include <cstdlib>
#include <iostream>

using namespace std;

typedef struct node { // binary search tree
    int number;
    node *left;
    node *right;
}Bst;

void printTree(node *tree);
void freeTree(node *tree);
bool search(node *tree, int number);

int main(void) {
    node *n;
    node *tree;

    n = (node*)malloc(sizeof(node));
    if (n == NULL) {
        return 1;
    }
    n->number = 1;
    n->left = NULL;
    n->right = NULL;
    tree = n;

    n = (node*)malloc(sizeof(node));
    if (n == NULL) {
        //free tree
        return 1;
    }
    n->number = 0;
    n->left = NULL;
    n->right = NULL;
    tree->left = n;

    n = (node*)malloc(sizeof(node));
    if (n == NULL) {
        //free tree
        return 1;
    }
    n->number = 2;
    n->left = NULL;
    n->right = NULL;
    tree->right = n;

    printTree(tree);
    cout << "is 2 in tree: " << search(tree, 2) << endl;
    freeTree(tree);


}


void printTree(node *root) {
    if (root == NULL) {
        return;
    }
    printTree(root->left);
    cout << (root->number) << endl;
    printTree(root->right);
    return;
}

void freeTree(node *root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
    return;
}

bool search(node *tree, int number) {
    if (tree == NULL) {
        return false;
    }
    else if (tree->number > number) {
        return search(tree->left, number);
    }
    else if (tree->number < number) {
        return search(tree->right, number);
    }
    else {
        return true;
    }
}












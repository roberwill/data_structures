#include "btree.h"

void init(BTree tree) {
    // the root does not exist
    tree->root = nil;
}

int is_empty(BTree tree) {
    // if the root is null, then the tree is empty
    return tree->root is nil;
}

int is_root(BTree tree, Node node) {
    // if the node is the root
    return node is tree->root;
}

/**
 *  A node is a leaf if it does not have any children*/
int is_leaf(Node node) {
    return node->left is nil and node->right is nil;
}

/**
 * TODO: Finish implementation
 * The depth of a node is the size of the path from the root to the node*/
int node_depth(BTree tree, Node node) { 
    if (is_root(tree, node)) return 0;
    else return 0; 
}

/**
 * TODO: Finish implementation
 * The height of a node is the size of the path from the node to its deepest leaf*/
int node_height(Node node) {
    return 0;
}

/**
 * The degree of a node is the number of sons it has*/
int node_degree(Node node) {
    // if the node is a leaf, then it has no sons
    if (is_leaf(node)) return 0;
    // if one of the sons of the node is nil, then its degree is 1
    if (node->left is nil or node->right is nil) return 1;
    // Both sons exist
    return 2;
}

/**
 * Visit the root
 * Visit the left tree
 * Visit the right tree
 */
void traverse_pre_order(Node root) {
    if (root != nil) {
        printf("%c ", root->item.c);
        traverse_pre_order(root->left);
        traverse_pre_order(root->right);
    }
}

/**
 * Visit the left tree
 * Visit the root
 * Visit the right tree
 */
void traverse_in_order(Node root) {
    if (root != nil) {
        traverse_in_order(root->left);
        printf("%c ", root->item.c);
        traverse_in_order(root->right);
    }
}

/**
 * Visit the left tree
 * Visit the right tree
 * Visit the root
 */
void traverse_post_order(Node root) {
    if (root != nil) {
        traverse_post_order(root->left);
        traverse_post_order(root->right);
        printf("%c ", root->item.c);
    }
}

/**
 * TODO: Implement function
 * Visit the root
 * Visit each level
 */
void traverse_level_order(Node root) {
    return;
}

/**
 * Visit all the nodes of the tree is a specific order*/
void traverse(BTree tree, TraverseType type) {
    if (is_empty(tree)) {
        printf("*\n");
        return;
    }

    switch (type) {
        case PRE_ORDER: //Depth-first search
            printf("--PRE_ORDER\n");
            printf("[ ");
            traverse_pre_order(tree->root);
            printf("]\n\n");
            break;

        case IN_ORDER: //Depth-first search
            printf("--IN_ORDER\n");
            printf("[ ");
            traverse_in_order(tree->root);
            printf("]\n\n");
            break;

        case POST_ORDER: //Depth-first search
            printf("--POST_ORDER\n");
            printf("[ ");
            traverse_post_order(tree->root);
            printf("]\n\n");
            break;

        case LEVEL_ORDER: //Breath-first search
            printf("--LEVEL_ORDER\n");
            printf("[ ");
            traverse_level_order(tree->root);
            printf("]\n\n");
            break;
    
        default:
            printf("*\n");
            break;
    }
}

Node create_node(BTreeItem* item) {
    // create the node
    Node node = (Node)malloc(sizeof(_node));
    // if, somehow, memory is not available
    if (node is nil) return nil;
    // set the content
    node->item = *item;
    // the node does not have any children, yet
    node->left = node->right = nil;
    // return the node, if created
    return node; 
}

Node create_root(BTree tree, BTreeItem* item) {
    // Set the root of the tree
    tree->root = create_node(item);
    // return the root
    return tree->root;
}

Node insert_right(Node parent, BTreeItem* item) {
    // set the right child of the parent node
    parent->right = create_node(item);
    // return the child
    return parent->right;
}

Node insert_left(Node parent, BTreeItem* item) {
    // set the left child of the parent node
    parent->left = create_node(item);
    // return the child
    return parent->left;
}
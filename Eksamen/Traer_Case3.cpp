//
// Created by amund on 14.09.2024.
//

#include <iostream>                  //  cout
using namespace std;



/**
 *  Node (med ID/key/data og venstre/høyre pekere til nodens barn,
 *        samt en 'settFor' som KAN brukes når det er nødvendig).
 */
struct Node {
    char ID; // Nodens ID/key/navn (en bokstav).
    int nivaa; // Nodens nivå i treet ift. rotnoden.
    Node* left; // Peker til venstre subtre, evt nullptr.
    Node* right; // Peker til høyre subtre, evt nullptr.
    Node(char id) { ID = id; nivaa = 0; left = right = nullptr; }
};

void settNivaa(Node* node);
Node* buildTree();
void printTree(Node* node);


Node* gRoot = nullptr; // Rot-peker.




int main(){
    gRoot = buildTree();

    settNivaa(gRoot);

    printTree(gRoot);

    return 0;

};
/**
 *  Builds a simple binary tree with at least 3 layers.
 *  The structure of the tree is as follows:
 *
 *          A
 *         / \
 *        B   C
 *       / \   \
 *      D   E   F
 */
Node* buildTree() {
    // Create nodes
    Node* root = new Node('A');
    Node* nodeB = new Node('B');
    Node* nodeC = new Node('C');
    Node* nodeD = new Node('D');
    Node* nodeE = new Node('E');
    Node* nodeF = new Node('F');

    // Connect nodes to form the tree
    root->left = nodeB;
    root->right = nodeC;

    nodeB->left = nodeD;
    nodeB->right = nodeE;

    nodeC->right = nodeF;

    return root;  // Return the root of the tree
}


void settNivaa(Node* node){
    if(node) {

        if(node -> left == nullptr && node ->right == nullptr) {
            settNivaa(node -> left);
        }
        settNivaa(node -> right);
        node -> nivaa ++;
    }
}

/**
 *  Prints the nodes of the tree along with their levels.
 */
void printTree(Node* node) {
    if (node) {
        cout << "Node " << node->ID << " is at level " << node->nivaa << endl;
        printTree(node->left);   // Print the left subtree
        printTree(node->right);  // Print the right subtree
    }
}
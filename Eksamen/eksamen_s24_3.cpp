
//
// Created by amund on 04.12.2024.
//

//a.)


struct Node {
    char ID; // Nodens ID/key/n�kkel/navn (ett tegn).
    Node *left, *right; // Referanser til begge subtr�rne eller neste i preorder rekkef�lge
    // eller nullptr/NULL (se resten av oppgaveteksten).
    bool nesteIPreorder; // Er false dersom h�yre subtre finnes,
    // er true dersom tomt h�yre subtre og at right
    // da i stedet peker til neste node i preorder rekkef�lge.
    // Har noden er tomt h�yre subtre, og er den aller siste i
    // preorder rekkef�lge, vil den ogs� v�re true,
    // bare at right da vil peke til nullptr/NULL.
    Node (char id, int p) // Constructor:
    { ID = id; nesteIPreorder = false; left = right = nullptr; }
};
Node* gRoot = nullptr, // Rot-peker (har alts� ikke at head->right er rota).
 * gForrige = nullptr; // Den forrige noden i preorder rekkef�lge (jfr. oppg.3b).

Node* neste(Node* node) {
    if(node){
        if(node -> left) {
            return node->left;
        }else {
            return node->right;
        }
    }
    return nullptr;

}
void settNeste(Node* node) {
 if(node) {
     if(node->right == nullptr){
         node -> right == neste(node);
     }
     else {

     }
     settNeste(node ->left);
 }
}
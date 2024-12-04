//
// Created by amund on 19.10.2024.
//
struct Node {
    char ID; // Nodens id/key/data
    Node* naboer[10]; // Nodens naboer (ligger i indeks nr. 0 - 9)
    int antNaboer; // Antall naboer (max. 10 stk)
    bool besokt; // Om besøkt noden hittil eller ei
    Node() = default;

    Node(char id, int ant_naboer);
};
Node* kopier(Node* node){
    Node* kopi = new Node(node->ID, node->antNaboer);
    for (int i = 0; i < node->antNaboer; i++)
        kopi->naboer[i] = kopier(node->naboer[i]);
    return kopi;
}

void brettUt(Node* node) {
    if(node) {
        for(int i = 0; node->besokt; i++) {
            if(node->naboer[i]->besokt) {
                node->naboer[i] = kopier(node);
            }
            node->naboer[i]->besokt=true;
            brettUt(node->naboer[i]);
        }
        node->besokt = true;
    }
}


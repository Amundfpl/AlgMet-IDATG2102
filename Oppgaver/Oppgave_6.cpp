//
// Created by amund on 12.09.2024.
//
/**
 *   Programeksempel nr 8 - Traverserer et bin�rt tre p� tre/fire ulike m�ter
 *                          (vha stack og queue).
 *
 *   Eksempel som viser traversering (vha. stakk/k�) av et bin�rt tre
 *   p� en preorder, levelorder og inorder m�te.
 *
 *   @file     EKS_08_TreTraversering.CPP
 *   @author   Frode Haug, NTNU
 */


#include <iostream>                  //  cout
using namespace std;


/**
 *  Node (med ID/key/data og venstre/h�yre pekere til nodens barn,
 *        samt en 'settFor' som KAN brukes n�r det er n�dvendig).
 */
struct Node {
    char ID;
    bool settFor;                     //  'settFor' brukes KUN ifm. postorder.
    Node *left, *right;               //  Initierende constructor:
    Node(char id)  {  ID = id;  left = right = nullptr;   settFor = false;  }
};


void  besok(const Node* node);
Node* byggTre();
int antallNoder(Node* node);
int nrPekerTilNull(Node* node);
int fulleNoder(Node* node);
void treNivaa(Node* node);


int sumNoder = 0;
int NoderSomPekerTilNull = 0;
int antallFulleNoder = 0;
int nivaa = 0;
int maxNivaa = 0;

/**
 *  Hovedprogrammet:
 */
int main()  {
    Node*  root;

    root = byggTre();

    sumNoder = 0;
    int totalNoder = antallNoder(root);
    cout << "Antall noder i treet: " << totalNoder << endl;

    NoderSomPekerTilNull = 0;
    int sumNoderLikNull = nrPekerTilNull(root);
    cout << "Antall noder som peker til null: " << sumNoderLikNull << endl;

    antallFulleNoder = 0;
    cout << "Noder med to barn: ";
    int sumFulleNoder = fulleNoder(root);
    cout << "\nAntall noder med to barn: " << sumFulleNoder << endl;

    treNivaa(root);
    cout << "Lengden p� treet: " << maxNivaa << endl;

    cout << "\n\n";

    return 0;
}


/**
 *  Bes�ker (visit) en node - ved � kun skrive ut dens ID/key/data.
 *
 *  'besok'/'visit' kan v�re s� mange ulike operasjoner.
 *   F.eks (som her) kun en ren utskrift. Men, det kan ogs� v�re slikt som
 *   � endre dens (ulike) data, sammenligne datene med noe, gj�re beregninger,
 *   endre p� nodens struktur, osv .....
 *
 *  @param   node  -  Aktuell node som skal bes�kes
 */
void  besok(const Node* node) {
    cout << ' ' << node->ID;
}


/**
 *  Bygger et bin�rt eksempel-tre.
 *
 *  @return   Peker til det bygde treets rot
 */
Node* byggTre() {
/*   Bygger treet:                                     A
                                              /                 \
                                         B                          C
                                    /         \                  /
                                  D             E              F
                              /       \           \          /
                            G           H           I      J
                              \        / \         /        \
                               K      L   M       N          O
*/
    Node*  noder[15];
    for (int i = 0; i < 15; i++)
        noder[i] = new Node(static_cast <char> ('A' + i));

    noder[0]->left = noder[1];  noder[0]->right = noder[2];
    noder[1]->left = noder[3];  noder[1]->right = noder[4];
    noder[2]->left = noder[5];
    noder[3]->left = noder[6];  noder[3]->right = noder[7];
                                noder[4]->right = noder[8];
    noder[5]->left = noder[9];
                                noder[6]->right = noder[10];
    noder[7]->left = noder[11]; noder[7]->right = noder[12];
    noder[8]->left = noder[13];
                                noder[9]->right = noder[14];
    return noder[0];
}

int antallNoder(Node* node) {
    if(node) {
        sumNoder++;
        antallNoder(node -> left);
        antallNoder(node -> right);
    }
    return sumNoder;
}

int nrPekerTilNull(Node* node) {
    if(node) {
        nrPekerTilNull(node -> right);
        nrPekerTilNull(node -> left);
        if(!node ->left){
            NoderSomPekerTilNull++;
        }
        if(!node -> right) {
            NoderSomPekerTilNull++;
        }
    }
    return NoderSomPekerTilNull;
}

int fulleNoder(Node* node) {
    if(node) {
        if(node -> left && node -> right) {
            antallFulleNoder++;
            besok(node);
        }
        fulleNoder(node ->left);
        fulleNoder(node ->right);
    }
    return antallFulleNoder;
}

void treNivaa(Node* node) {
    if(node) {
        nivaa++;
        if(maxNivaa < nivaa) {
            maxNivaa = nivaa;
        }
        treNivaa(node -> left);
        treNivaa(node ->right);
        nivaa--;
    }
}


/**
 *   Hovedrisset til oppgave nr 8.
 *
 *   For programmets funksjonalitet:  se oppgaveteksten.
 *
 *   (Dette var oppg.nr.3 p� eksamen 15/8-2016 i IMT2021-Algoritmiske metoder)
 *
 *   @file	  OPPG_08-HOVEDRISS.CPP
 *   @author  Frode Haug, NTNU
 */


#include <iostream>
using namespace std;


/**
 *  Node (med ID/key/data og venstre/h�yre pekere til nodens barn).
 */
struct Node {
    int   ID;	        //  Nodens ID/key/n�kkel/navn (et tall).
    Node* left;	      //  Peker til venstre subtre, evt. 'nullptr' n�r tomt.
    Node* right;	    //  Peker til h�yre subtre, evt. 'nullptr' n�r tomt.
                      //  Constructor:
    Node(int id, Node* l, Node* r) { ID = id;  left = l, right = r; }
};


Node* byggTre();
bool  erBST(Node* n);                        //  Oppgave B
int   finnMax(Node* n);                      //  Oppgave A2
int   finnMin(Node* n);                      //  Oppgave A1


Node* gRoot = nullptr;	  ///<  Peker til hele treets rot.
const int MIN = 0,        ///<  Verdier mindre/st�rre enn ALLE ID'er i treet.
          MAX = 9999;


/**
 *  Hovedprogrammet:
 */
int main() {

    gRoot = byggTre();

    cout << "\n\nTester oppgave A - Minste og st�rste verdi i treet:\n";
    cout << "Minste  verdi i treet er:  " << finnMin(gRoot) << '\n';   //   3
    cout << "St�rste verdi i treet er:  " << finnMax(gRoot) << '\n';   //  82


    cout << "\n\nTester oppgave B - Er treet et bin�rt s�ketre eller ei:\n";
    cout << "Treet er " << (erBST(gRoot) ? "" : "IKKE ")      //  Er IKKE BST!
         << "et bin�rt S�KEtre\n\n";

    return 0;
}


/**
 *  Bygger et bin�rt testtre.
 *
 *  @return   Peker til rota i treet som er bygd
 */
Node* byggTre() {
    //          Bygger treet:                         //
    //                       17                       //
    //                  /          \                  //
    //                 33           11                //
    //               /    \       /    \              //
    //              7      35   82      5             //
    //            /   \           \    /              //
    //           27     13        31  34              //
    //                   \        /                   //
    //                   10      57                   //
    //                          /  \                  //
    //                         3   30                 //
    Node *n3  = new Node(3, nullptr, nullptr),
         *n30 = new Node(30, nullptr, nullptr),
         *n10 = new Node(10, nullptr, nullptr),
         *n57 = new Node(57, n3, n30),
         *n27 = new Node(27, nullptr, nullptr),
         *n13 = new Node(13, nullptr, n10),
         *n31 = new Node(31, n57, nullptr),
         *n34 = new Node(34, nullptr, nullptr),
         *n7  = new Node(7, n27, n13),
         *n35 = new Node(35, nullptr, nullptr),
         *n82 = new Node(82, nullptr, n31),
         *n5  = new Node(5, n34, nullptr),
         *n33 = new Node(33, n7, n35),
         *n11 = new Node(11, n82, n5),
         *n17 = new Node(17, n33, n11);
    return n17;
}


/**
 *  OPPGAVE B - Finner ut om et bin�rt tre er et bin�rt S�KEtre (BST)
 *
 *  @param    node  -  Aktuell node � behandle
 *  @return   Om treet under 'node' er bin�rt s�ketre (BST) eller ei
 *  @see      finnMax(...)
 *  @see      finnMin(...)
 */
bool erBST(Node* node) {
    // Basistilfelle: Hvis noden er nullptr, er treet gyldig (et tomt tre er et BST)
    if (node == nullptr) {
        return true;
    }

    // Sjekk om noden overholder BST-regelen
    if ((node->left != nullptr && finnMax(node->left) >= node->ID) ||
        (node->right != nullptr && finnMin(node->right) <= node->ID)) {
        return false;  // Ikke et BST hvis noden bryter regelen
        }

    // Rekursivt sjekk om b�de venstre og h�yre subtre ogs� er BST
    return erBST(node->left) && erBST(node->right);
}


/**
 *  OPPGAVE A2 - Finner ST�RSTE verdi i et bin�rt (IKKE n�dvendigvis S�KE)tre.
 *
 *  @param    node  -  Aktuell node � behandle
 *  @return   ALLER st�rste verdi (ID) funnet i HELE treet under 'node'
 */
int finnMax(Node* node) {
    if(node == nullptr) {
        return MIN;
    }
    int venstreMax = finnMax(node -> left);
    int hoeyreMax = finnMax(node -> right);
    return max(node ->ID, max(venstreMax, hoeyreMax));
}


/**
 *  OPPGAVE A1 - Finner MINSTE verdi i et bin�rt (IKKE n�dvendigvis S�KE)tre.
 *
 *  @param    node  -  Aktuell node � behandle
 *  @return   ALLER minste verdi (ID) funnet i HELE treet under 'node'
 */
int finnMin(Node* node) {
    if(node == nullptr) {
        return MAX;
    }
    int venstreMin  = finnMin(node -> left);
    int hoeyreMin = finnMin(node -> right);
    return min(node -> ID, min(venstreMin, hoeyreMin));
}
/*dsdsddasdsadsal�dsaldas�kdl
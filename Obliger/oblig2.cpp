/**
 *   Hovedrisset til oblig nr 2.
 *
 *   For programmets funksjonalitet se:  Oblig2.pdf
 *
 *   @file    OBLIG2.CPP
 *   @author  Frode Haug, NTNU
 */


#include <iostream>             //  cout
using namespace std;


/**
 *  Node (med ID/key/data og venstre/høyre pekere til nodens barn).
 */
struct Node {
    int ID;                  //  Nodens ID/key/nøkkel/navn (et tall).
    Node *left, *right;      //  Peker til begge subtrærne (evt. 'nullptr').
    Node(int id) { ID = id;  left = right = nullptr; }
};


Node* gRoot = nullptr;  ///<  Peker til treets rot.
int   gNivaa,           ///<  Nåværende nodenivå (rota er på nivå nr.0).
      gNoder[50];       ///<  IDene for nodene på nåværende sti fra rota til
                        ///<  bladnoder (oppg A). 0 eller 1 til om node lengst
                        ///<  til høyre ennå er sett på nivå nr.'i' (oppg B).

Node* byggTre();
void  finnOgSkrivAlleStier(Node* node);      //  Oppgave A
void  skrivHoyreView(Node* node);            //  Oppgave B
void skrivVenstreView(Node* node);


/**
 *  Hovedprogrammet:
 */
int main() {

    gRoot = byggTre();


    cout << "\n\nTester oppgave A - ALLE stier fra rot til ALLE bladnoder:\n";
    gNivaa = -1;
    finnOgSkrivAlleStier(gRoot);                //  Oppgave A
                                                //  Utskriften bør være:
                                                //       1 2 4
                                                //       1 2 5 8
                                                //       1 3 6 9 11
                                                //       1 3 7 10

    cout << "\n\nTester oppgave B - Høyre view:\n";
    gNivaa = -1;                                //  Nullstiller dataene igjen:
    for (int i = 0; i < 50; i++)  gNoder[i] = 0;
    
    skrivHoyreView(gRoot);                      //  Oppgave B
                                                //  Utskriften bør være:
                                                //       1  3  7  10  11


    cout << "\n\nTester oppgave B2 - Venstre view:\n";
    gNivaa = -1;                                //  Nullstiller dataene igjen:
    for (int i = 0; i < 50; i++)  gNoder[i] = 0;

    skrivVenstreView(gRoot);


    cout << "\n\n";
    return 0;
}


/**
 *  Bygger et binært testtre.
 *
 *  @return   Peker til rota i treet som er bygd
 */
Node* byggTre() {                                //  Bygger treet:          //
    Node* p[12];                                 //           1             //
    for (int i = 1; i <= 11; i++)                //       /       \         //
        p[i] = new Node(i);                      //      2         3        //
    p[1]->left = p[2];    p[1]->right = p[3];    //    /   \     /   \      //
    p[2]->left = p[4];    p[2]->right = p[5];    //   4     5   6     7     //
    p[3]->left = p[6];    p[3]->right = p[7];    //        /     \   /      //
    p[5]->left = p[8];    p[6]->right = p[9];    //       8       9 10      //
    p[7]->left = p[10];   p[9]->left = p[11];    //              /          //
    return p[1];                                 //             11          //
}


/**
 *  OPPGAVE A- Genererer og skriver ALLE stier fra rota og ned til bladnodene.
 *
 *  @param   node  -  Aktuell node å behandle
 */
void finnOgSkrivAlleStier(Node* node) {
    if(node) {
        //Øk nivået og legg til Node ID i gNoder arrayen
        gNivaa++;
        gNoder[gNivaa] = node ->ID;

        //Hvis det er en bladnode (ingen barn)
        if(!node -> left && !node -> right) {
            for(int i = 0; i <= gNivaa; i++) { // skriv ut stien fra roten til bladene
                cout << gNoder[i] << (i < gNivaa ? " " : "\n"); // Så lenge i er mindre eller lik gNivaa vil den legge til mellomrom
            }                                                   //ellers vil den legge til et linje skift.
        }else {
            //Fortsett rekursonen til venstre og høyre
            finnOgSkrivAlleStier(node -> left);
            finnOgSkrivAlleStier(node -> right);
        }
        gNivaa --;
        }
    //Skru ned nivået når vi går tilbake
        }



  //  }
    //  LAG INNMATEN  (se oppgaveteksten)


/**
 *  OPPGAVE B - Finner og skriver ALLE nodene lengst til HØYRE på ALLE nivåer.
 *
 *  @param   node  -  Aktuell node å behandle
 */
void skrivHoyreView(Node* node) {
    if(node) {
        gNivaa++;
        if(gNoder[gNivaa] == 0) { //Hvis det er ingen noder lagret i arrayet på det nivået.
            gNoder[gNivaa] = node -> ID; //Lagre noden sin ID
            cout << node -> ID << " "; //Skriv ut noden sin ID.
        }
        skrivHoyreView(node -> right); //Traverser til høyre først slik at alle verdiene som blir lagret først er de lengst til høyre
        skrivHoyreView(node -> left); //Deretter traverser til venstre for å se om det er noen trær som har et dypere nivaa til
        //venstre for å lagre den verdien, som vil være den noden lengst til høyre på den dybden.
        gNivaa --;
    }
}

void skrivVenstreView(Node* node) {
    if(node) {
        gNivaa++;
        if(gNoder[gNivaa] == 0) { //Hvis det er ingen noder lagret i arrayet på det nivået.
            gNoder[gNivaa] = node -> ID; //Lagre noden sin ID
            cout << node -> ID << " "; //Skriv ut noden sin ID.
        }
        skrivVenstreView(node -> left); //Traverser til høyre først slik at alle verdiene som blir lagret først er de lengst til høyre
        skrivVenstreView(node -> right); //Deretter traverser til hoyre for å se om det er noen trær som har et dypere nivaa til
        //hoyre for å lagre den verdien, som vil være den noden lengst til venstre på den dybden.
        gNivaa --;
    }
}
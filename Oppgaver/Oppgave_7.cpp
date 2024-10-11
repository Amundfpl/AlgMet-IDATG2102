#include <iostream>    //  cout
#include <cstring>     //  For memset

using namespace std;

const int MAX = 8;     ///<  Brettets størrelse.

int gBrett[MAX][MAX];  // Brett som nå har int-verdier (0, 1, 2)
bool visited[MAX][MAX]; // Holde styr på besøkte noder
int nrGrupper = 0;     // Teller for grupper

void writeBoard();
void placePiece(int rad, int kol);
void numberOfGroups();
int markGroups(int i, int j, int groupNumber);
void numberOfPiecesInGroup();

int main() {
    // Plasser brikker på brettet
    placePiece(1, 2);
    placePiece(1, 3);
    placePiece(4, 1);
    placePiece(4, 2);
    placePiece(7, 1);
    placePiece(7, 2);

    writeBoard();  // Skriver ut brettet før grupper markeres

    // Tell antall grupper og marker de
    numberOfGroups();

    cout << "\nAntall grupper: " << nrGrupper << "\n\n";

    // Tell antall ruter i hver gruppe
    numberOfPiecesInGroup();

    return 0;
}

void placePiece(int rad, int kol) {
    if (rad >= 0 && rad < MAX && kol >= 0 && kol < MAX) {
        gBrett[rad][kol] = 1;  // Setter brikke (1) på brettet
    } else {
        cout << "Ugyldig posisjon!" << endl;
    }
}

/**
 *  Skriver ut brettets innhold (1 = brikke, 0 = tomt felt, 2 = markert brikke).
 */
void writeBoard() {
    cout << "\n\t";
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cout << gBrett[i][j] << "  ";
        }
        cout << "\n\t";
    }
}

/**
 *  Flood fill-lignende funksjon for å markere gruppen og besøkte noder.
 *  Returnerer antall ruter i gruppen.
 */
int markGroups(int i, int j, int groupNumber) {
    if (i < 0 || i >= MAX || j < 0 || j >= MAX) {
        return 0;  // Utenfor brettet
    }
    if (gBrett[i][j] != 1 || visited[i][j]) {
        return 0;  // Ikke en brikke eller allerede besøkt
    }

    // Marker denne som besøkt og sett den til del av en gruppe
    visited[i][j] = true;
    gBrett[i][j] = 2;  // Brikken er nå en del av en gruppe (markert som '2')

    // Skriv ut posisjonen til ruten i denne gruppen
    cout << "Gruppe " << groupNumber << " har rute (" << i << ", " << j << ")\n";

    // Sjekk nabocellene (opp, ned, venstre, høyre) og tell ruter
    int count = 1;  // Teller denne ruten
    count += markGroups(i - 1, j, groupNumber);
    count += markGroups(i + 1, j, groupNumber);
    count += markGroups(i, j + 1, groupNumber);
    count += markGroups(i, j - 1, groupNumber);

    return count;  // Returnerer totalt antall ruter i denne gruppen
}

/**
 *  Funksjon som finner og teller antall grupper.
 */
void numberOfGroups() {
    memset(visited, false, sizeof(visited));  // Nullstiller visited-arrayet
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (gBrett[i][j] == 1 && !visited[i][j]) {
                nrGrupper++;  // Ny gruppe funnet
                cout << "\nStarter ny gruppe nr. " << nrGrupper << ":\n";
                markGroups(i, j, nrGrupper);  // Marker hele gruppen
            }
        }
    }
}

/**
 *  Funksjon som teller antall ruter i hver gruppe.
 */
void numberOfPiecesInGroup() {
    memset(visited, false, sizeof(visited));  // Nullstiller visited-arrayet
    int currentGroup = 1;  // Use the correct group number
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (gBrett[i][j] == 2 && !visited[i][j]) {
                int numPieces = markGroups(i, j, currentGroup);
                cout << "\nGruppe " << currentGroup << " har " << numPieces << " ruter.\n";
                currentGroup++;
            }
        }
    }
}

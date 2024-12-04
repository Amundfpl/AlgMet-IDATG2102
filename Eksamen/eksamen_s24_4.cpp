//
// Created by amund on 04.12.2024.
//
#include <iostream>                  //  cout
#include <stack>                     //  stack fra STL
using namespace std;
#include <iomanip>     //  setw

/**
 *  Beregner (om mulig) datoen i et ikke-skuddår for et gitt dagnummer i året.
 *
 *  @param  dagNr  -  Aktuelt dagnummer i året å finne datoen for
 */
void skrivDato(const int dagNr) {
    int dag, mnd = 0, sum = 0;           //  Setter opp antall dager i månedene:
    int dagerPrMnd[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (dagNr >= 1  &&  dagNr <= 365)  {       //  Dagnummeret i rett intervall:
        while (sum + dagerPrMnd[mnd] < dagNr)   //  Ennå ikke nådd rett måned:
            sum += dagerPrMnd[mnd++];         //  Summerer og teller opp 'mnd'.

        dag = dagNr - sum;                      //  Finner dagen.
        //  Skriver funnet dag og måned:
        cout << "\tDag nr." << setw(3) << dagNr << " er datoen:  "
             << setw(2) << dag << '/' << setw(2) << mnd+1 << '\n';
        //  +1, da teller mnd fra nr.0
    }  else
        cout << "\n\tDagnummer MAA vaere i intervallet 1-365!\n\n";
}


/**
 *   Hovedprogram.
 */
int main()  {

    cout << "\n\nDagnumrene (1-365) i et ikke-skuddaar er datoene:\n";
    for (int dagNr = 1;  dagNr <= 365; dagNr++)
        skrivDato(dagNr);

    return 0;
}
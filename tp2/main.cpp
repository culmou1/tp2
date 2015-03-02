//
//  main.cpp
//  tp2
//
//  Created by Daehli Nadeau Otis on 2015-02-27.
//  Copyright (c) 2015 Daehli Nadeau-Otis. All rights reserved.
//

#include <iostream>
#include <cstdlib> // Bibliothèque spécial
#include "Header.h"
using namespace std;


PREFIXE :: PREFIXE()
{
   Pile;
   Tableau;
}
bool PREFIXE :: lecture(vector<char> Tableau)
{
    bool lectureCar = false; // Vérifie si les caractères sont OK
    
    for (int i=0; i<Tableau.size(); i++)
    {
        switch (Tableau[i])
        {
            case '(':
                cout << "Lisible";
                lectureCar = true;
                return Tableau[i];
                break;
            case ')':
                cout << "Lisible";
                lectureCar = true;
                return Tableau[i];
                break;
            case '*':
                cout << "Lisible";
                lectureCar = true;
                return Tableau[i];
                break;
            case '/':
                cout << "Lisible";
                lectureCar = true;
                return Tableau[i];
                break;
            case '%':
                cout << "Lisible";
                lectureCar = true;
                return Tableau[i];
                break;
            case '+':
                cout << "Lisible";
                lectureCar = true;
                return Tableau[i];
                break;
            case '-':
                cout << "Lisible";
                lectureCar = true;
                return Tableau[i];
                break;
            case '0':
                cout << "Lisible";
                lectureCar = true;
                return Tableau[i];
                break;
            case '1':
                cout << "Lisible";
                lectureCar = true;
                return Tableau[i];
                break;
            case '2':
                cout << "Lisible";
                lectureCar = true;
                return Tableau[i];
                break;
            case '3':
                cout << "Lisible";
                lectureCar = true;
                return Tableau[i];
                break;
            case '4':
                cout << "Lisible";
                lectureCar = true;
                return Tableau[i];
                break;
            case '5':
                cout << "Lisible";
                lectureCar = true;
                return Tableau[i];
                break;
            case '6':
                cout << "Lisible";
                lectureCar = true;
                return Tableau[i];
                break;
            case '7':
                cout << "Lisible";
                lectureCar = true;
                return Tableau[i];
                break;
            case '8':
                cout << "Lisible";
                lectureCar = true;
                return Tableau[i];
                break;
            case '9':
                cout << "Lisible";
                lectureCar = true;
                return Tableau[i];
                break;
            default:
                cerr << "Vous n'avez aucun paramêtre valide" << endl;
                
        }
    }
}
bool PREFIXE :: valider_expression (vector<char> Tableau)
{
    int pargauche, pardroite; // Calculer le nombre de parenthèse;
    for (int i = 0; i <Tableau.size(); i++)
    {
        if (Tableau[i]== '(')
        {
            pargauche = pargauche +1; // COMPTE LE NOMBRES DE PARATHÈSE
        }
        else if (Tableau[i]== ')')
        {
            pardroite = pardroite +1;
        }
    }
    if (pardroite ==pargauche)
    {
        bool valide;
        valide = true;
    }
}

void PREFIXE:: transformerennombres (vector <char> Tableau)
{
    for (int i = 0; i<Tableau.size(); i++) {
        int nombre = atoi(&Tableau[i]);// atoi convertie le char en int;
        /* ON PEUT PREND LE TABLEAU ASCII PEUT-ÊTRE, MAIS JE TROUVE QUE LA
         FUCNTION ATOI EST PARFAITE POUR NOS BESOIN. ELLE EST DÉCLARÉ DANS
         LA BIBLOTHÈQUE CSTDLIB*/
    }
}

int main()
{
    PREFIXE premier;
    char entre;
    cout << "Entrer une équations";
    cin >> entre;
}
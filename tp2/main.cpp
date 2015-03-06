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
                break;
            case ')':
                cout << "Lisible";
                lectureCar = true;
                break;
            case '*':
                cout << "Lisible";
                lectureCar = true;
                break;
            case '/':
                cout << "Lisible";
                lectureCar = true;
                break;
            case '%':
                cout << "Lisible";
                lectureCar = true;
                break;
            case '+':
                cout << "Lisible";
                lectureCar = true;
                break;
            case '-':
                cout << "Lisible";
                lectureCar = true;
                break;
            case '0':
                cout << "Lisible";
                lectureCar = true;
                break;
            case '1':
                cout << "Lisible";
                lectureCar = true;
                break;
            case '2':
                cout << "Lisible";
                lectureCar = true;
                break;
            case '3':
                cout << "Lisible";
                lectureCar = true;
                break;
            case '4':
                cout << "Lisible";
                lectureCar = true;
                break;
            case '5':
                cout << "Lisible";
                lectureCar = true;
                break;
            case '6':
                cout << "Lisible";
                lectureCar = true;
                break;
            case '7':
                cout << "Lisible";
                lectureCar = true;
                break;
            case '8':
                cout << "Lisible";
                lectureCar = true;
                break;
            case '9':
                cout << "Lisible";
                lectureCar = true;
                break;
            default:
                cerr << "Vous n'avez aucun paramêtre valide" << endl;
                return false;
        }
    }
    return true;
}
bool PREFIXE :: valider_expression (vector<char> Tableau)
{
    int pargauche = 0, pardroite = 0; // Calculer le nombre de parenthèse;
    for (int i = 0; i <Tableau.size(); i++)
    {
        if (Tableau[i]== '(')
        {
            pargauche += 1; // COMPTE LE NOMBRES DE PARATHÈSE
        }
        else if (Tableau[i]== ')')
        {
            pardroite += 1;
        }
    }
    if (pardroite ==pargauche) // On retourne directement la valeur du bool
      return true;
   else
      return false;
}

void PREFIXE:: transformerennombres (vector <char> Tableau)
{
   int temp;
    for (int i = 0; i<Tableau.size(); i++) 
	{
		if (Tableau[i] >= '0' && Tableau[i] <= '9')
		{
			temp = atoi(&Tableau[i]);
			Tableau[i] = temp;
		}
		cout << Tableau[i];
    }
    /* J'ai essayé la focntion atoi. Elle reconnait un nombre meme chacun de ses chiffres est sur un digit.
    Par exemple, si on a : tableau[0]= 2, tableau[1]= 5 et tableau[2]= 5. Dès qu'elle arrive à tableau[0]
    elle a lire 255 et ensuite ça ressort comme ça : tableau[0]= 255, tableau[1]= 5 et tableau[2]= 5.
    Faudrait supprimer les digits qui suivent j'y travaille. */
}

int main()
{
    PREFIXE premier;
    string entre;
    vector <char> expression;
    
    cout << "Entrer une équations";
    cin >> entre;
    
    // pour faire appel au fonction on a besion d'un tableau
    for(int i =0; i<entree.size(); i++) {
		expression.push_back(entree[i]);
	}

	if (premier.lecture(expression))
		cout << endl << "L'expression est bonne" << endl;
	else
		cout << endl << "Il y a des caractères que je ne connais pas" << endl;

   if (premier.valider_expression(expression))
	   cout << endl << "Le nombre parenthèse est correct." << endl;
	else
	   cout << endl << "L'expression manque de parentheses" << endl;

	premier.transformerennombres (expression);

	system ("pause");
}

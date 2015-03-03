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
    { // En effet, dans ma version j'ai essayé de raccourcir le switch je mets ca en description
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
    int pargauche = 0 , pardroite = 0; // Calculer le nombre de parenthèse;
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
    if (pardroite ==pargauche) // On retourne directement la valeur du booléen
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
    /* Ici j'ai essayé la fonnction atoi() elle reconnait un nombre meme si chaque chiffre est sur un digit. 
    PAr exemple, si on a : tableau[0]=2, tableau[1]=5 et tableau[2]=5, dès qu'elle accède a tableau[0] elle 
    trouve 255 du coup ça ressort comme ça : tableau[0]=255, tableau[1]=5 et tableau[2]=5. Faut supprimer des 
    digits mais je sais pas encore comment. */
}

int main()
{
    PREFIXE premier;
    string entre;
    vector <char> expression;
    cout << "Entrer une équations";
    cin >> entre;
    
    //pour transmettre l'expression on doit la mettre dans un vector
    for(int i =0; i<entree.size(); i++) {
		expression.push_back(entree[i]);
	}

	if (premier.lecture(expression)) //appel de la 1ere fonction
		cout << endl << "L'expression est bonne" << endl;
	else
		cout << endl << "Il y a des caractères que je ne connais pas" << endl;
		
	if (premier.valider_expression(expression)) //appel de la 2e fonction
	   cout << endl << "Le nombre de parenthèses est bon" << endl;
	else
	   cout << endl << "L'expression est incorrecte" << endl;

	premier.transformerennombres (expression); //appel de la 3e fonction

	system ("pause");
}

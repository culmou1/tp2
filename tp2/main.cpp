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
    stack<char> Pile;
    vector<char>Tableau;
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
    /* J'ai essayé la fonction atoi. Elle reconnait un nombre meme chacun de ses chiffres est sur un digit.
    Par exemple, si on a : tableau[0]= 2, tableau[1]= 5 et tableau[2]= 5. Dès qu'elle arrive à tableau[0]
    elle va lire 255 et ensuite ça ressort comme ça : tableau[0]= 255, tableau[1]= 5 et tableau[2]= 5.
    Faudrait supprimer les digits qui suivent j'y travaille. */
    /* WTF, on dirait qu'elle lit tout d'un coup et après elle tout séparément */
}
void PREFIXE:: transformerenpostfixe(stack<char> Pile, vector<char> Tableau)
{
    stack <char> operande;
    stack<char> operateur;
    stack<char> resultat;
    for (int i = 0; i < Tableau.size();i++)
    {
        if (Tableau[i]>='0' && Tableau[i] <= '9') {
            operande.push(Tableau[i]);// Ajoute un élément à la pile operande comme 3, 4, 5,6,
            Tableau.pop_back(); // supprime un element de la chaine tableau
        }
        else
        {
            operateur.push(Tableau[i]); // Ajoute un element à la pile des operateur +,-,\,%
            Tableau.pop_back(); // supprime un element de la chaine tableau
        }
    }
    
    for (int i =0; i < operateur.size(); i++)
    {
        Tableau.push_front(operateur(i)); // ajoute l'opérateur au tableau après les 2 operande
            for (i=0; i< operande.size(); i++)
            {
                Tableau.push_front(operande(i)); // Nous devons faire quelque chose comme ça. pour mettre deux operande avant l'operateur.
                Tableau.push_front(operande(i+1)); // le plus +1 est pour aller chercher l'élément suivant
            }
    }
    
    /*Lorsque l'interpréteur rencontre un opérande, il l'empile. Lorsqu'il rencontre un opérateur, il l'exécute
     sur les opérandes empilés et met le résultat de l'opération sur la pile. Ainsi, quand il rencontre
     l’opérateur add, il prend les deux nombres du haut de la pile et les remplace par leur somme. Il fait de
     même pour la multiplication avec l’opérateur mul. La pile aura donc successivement le contenu suivant :
     Par exemple :
     
     14 + 4 s'écrit : 14 4 +
     (98 + 11)* 6 s'écrit : 98 11 + 6 *
     -75 s'écrit : 75-
     */
}

int PREFIXE :: evaluer_expression(stack<char> Pile, vector<char> Tableau)
{
    // Il faut peut-être mettre les opérateurs dans une pile et laisser les opérande dans un tableau.
    // et à la fin nous avons juste à dépilé la pile et le tableau. Il est maintenant l'heure d'aller en cours.
    // À tanto ..
}
int main()
{
    PREFIXE premier; // Création de nôtre object
    string entre;
    vector <char> expression; // Tableaux pour nôtre structure de donné
    
    cout << "Entrer une équations";
    cin >> entre;
    
    // pour faire appel au fonction on a besion d'un tableau
    for(int i =0; i<entre.size(); i++) {
		expression.push_back(entre[i]);
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

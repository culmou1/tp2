#include <iostream>
#include "Prefixe.h"
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;

bool estNombre (string t);
bool estOperande (string t);
int precedance(string t);

Prefixe::Prefixe() {
}

Prefixe::~Prefixe () {
}


bool Prefixe :: lecture(vector<string> tableau)
{
    bool lectureToken =false; // Vérifie si les caractères sont OK
    
    for (int i=0; i<tableau.size(); i++)
    {
       if (estNombre (tableau[i]) || estOperande (tableau[i]))
	   {
			lectureToken  = true;
			Tableau.push_back(tableau[i]);
	   }
		else 
			return false;
	}
	return lectureToken;
}

bool Prefixe :: valider_expression (vector<string> tableau)
{
    int pargauche = 0, pardroite = 0; // Calculer le nombre de parenthèse;
    for (int i = 0; i <tableau.size(); i++)
    {
        if (tableau[i] == "(")
        {
            pargauche += 1; // COMPTE LE NOMBRES DE PARATHÈSE
        }
        else if (tableau[i]== ")")
        {
            pardroite += 1;
        }
    }
    if (pardroite ==pargauche) // On retourne directement la valeur du bool
      return true;
   else
      return false;
}

void Prefixe:: transformerennombres (vector <string> tableau)
{
	vector <int> operande;

	for (int i= 0; i < tableau.size(); i++) {
		if (estNombre (tableau[i]))
			operande.push_back(stoi(tableau[i]));
	}
   
    /* J'ai essayé la focntion atoi. Elle reconnait un nombre meme chacun de ses chiffres est sur un digit.
    Par exemple, si on a : tableau[0]= 2, tableau[1]= 5 et tableau[2]= 5. Dès qu'elle arrive à tableau[0]
    elle a lire 255 et ensuite ça ressort comme ça : tableau[0]= 255, tableau[1]= 5 et tableau[2]= 5.
    Faudrait supprimer les digits qui suivent j'y travaille. */
}

void Prefixe:: transformerenprefixe(stack<string> Pile, vector<string> tableau)
{
    stack <string> operande;
    stack <string> operateur;
    
	for (int i = tableau.size()-1; i >=0;i--)
    {
        if (estNombre (tableau[i])) {
            operande.push(tableau[i]);// Ajoute un élément à la pile operande comme 3, 4, 5,6,
            Pile.push(tableau[i]);
        }
		
		if (estOperande (tableau[i])) {
			if (tableau[i] == ")")
            operateur.push(tableau[i]); // Ajoute un element à la pile des operateur +,-,\,%
			else if (tableau[i] == "(") {
				while (operateur.top() != ")") {
					Pile.push(operateur.top());
					operateur.pop();
				}
				operateur.pop();
			}
			else {
				bool pushed = false;
				while (!pushed) {
					if (operateur.empty() || operateur.top() == ")" || precedance(tableau[i]) >= precedance(operateur.top())) {
					operateur.push(tableau[i]);
					pushed =true;
					}
					else {
						Pile.push(operateur.top());
						operateur.pop();
					}
				}
			}
		}
		
    }
	while (!operateur.empty()) {
		Pile.push(operateur.top());
		operateur.pop();
	}
    
    while (!Pile.empty())
    {
		cout << " " << Pile.top();
		Pile.pop();
	}
}
        

int Prefixe:: evaluer_expression(stack<string> Pile, vector<string> Tableau)
{
    // Il faut peut-être mettre les opérateurs dans une pile et laisser les opérande dans un tableau.
    // et à la fin nous avons juste à dépilé la pile et le tableau. Il est maintenant l'heure d'aller en cours.
    // À tanto ..
}

void main()
{
    Prefixe premier;
    string entree;
	int i = 0;
    vector <string> expression;
	stack <string> prefixe;
    
    cout << "Entrer une équation : ";
    cin >> entree;
    // pour faire appel au fonction on a besion d'un tableau
   while ( i <entree.size()) {
	   string temp;
	   if (entree[i]>= '0' && entree[i] <= '9') {
		   while (entree[i]>= '0' && entree[i] <= '9') {
			   temp += entree[i];
			   i++;
		   }
		   expression.push_back(temp);
	   }
	   else {
		   temp = entree[i];
		   expression.push_back (temp);
		   i++;
	   }
	}

	if (premier.lecture(expression))
		cout << endl << "L'expression est bonne" << endl;
	else
		cout << endl << "Il y a des caractères que je ne connais pas" << endl;

   if (premier.valider_expression(expression))
	   cout << endl << "Le nombre parenthèse est correct." << endl;
	else
	   cout << endl << "L'expression manque de parentheses" << endl;

   premier.transformerenprefixe (prefixe, expression);


	system ("pause");
}

bool estOperande (string t) {
	return (t == "+" || t == "-" || t == "*" || t == "/" || t == "%" || t == "(" || t == ")");
}

bool estNombre (string t) {
	for (int i = 0; i < t.size(); i++) {
		if (t[i] < '0' || t[i] > '9')
			return false;
	}
	return true;
}

int precedance(string t)
{
    int temp;
	if (t == "*" || t == "/" || t == "%")
       temp = 2;
    else  if (t == "+" || t == "-")
       temp = 1;
    return temp;
}

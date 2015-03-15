#include <iostream>
#include "Prefixe.h"
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;

bool estNombre (string t);
bool estOperateur (string t);
int precedance(string t);
int operation (string operateur, int ope_gauche, int ope_droite);

Prefixe::Prefixe() {
	Pile = new stack <string>;
	Tableau = new vector <int>;
}

Prefixe::~Prefixe () {
	delete Pile;
	delete Tableau;
}


bool Prefixe :: lecture(vector<string> infixe)
{
    bool lectureToken =false; // Vérifie si les caractères sont OK
    
    for (int i=0; i<infixe.size(); i++)
    {
       if (estNombre (infixe[i]) || estOperateur (infixe[i]))
			lectureToken  = true;
		else 
			return false;
	}
	return lectureToken;
}

bool Prefixe :: valider_expression (vector<string> infixe)
{
    int pargauche = 0, pardroite = 0; // Calculer le nombre de parenthèse;
    for (int i = 0; i <infixe.size(); i++)
    {
        if (infixe[i] == "(")
        {
            pargauche += 1; // COMPTE LE NOMBRES DE PARATHÈSE
        }
        else if (infixe[i]== ")")
        {
            pardroite += 1;
        }
    }
    if (pardroite ==pargauche) // On retourne directement la valeur du bool
      return true;
   else
      return false;
}

void Prefixe::transformerennombres (vector<string> tokens)
{
    for (int i=tokens.size()-1; i >= 0; i--) {
		Tableau->push_back (stoi (tokens[i]));
	}
    /* J'ai essayé la focntion atoi. Elle reconnait un nombre meme chacun de ses chiffres est sur un digit.
    Par exemple, si on a : tableau[0]= 2, tableau[1]= 5 et tableau[2]= 5. Dès qu'elle arrive à tableau[0]
    elle a lire 255 et ensuite ça ressort comme ça : tableau[0]= 255, tableau[1]= 5 et tableau[2]= 5.
    Faudrait supprimer les digits qui suivent j'y travaille. */
}

void Prefixe:: transformerenprefixe(stack<string> *prefixe, vector<string> infixe)
{
    stack <string> operande;
    stack <string> operateur;
    
	for (int i = infixe.size()-1; i >=0;i--)
    {
        if (estNombre (infixe[i])) {
            operande.push(infixe[i]);// Ajoute un élément à la pile operande comme 3, 4, 5,6,
            Pile->push(infixe[i]);
        }
		
		if (estOperateur (infixe[i])) {
			if (infixe[i] == ")")
            operateur.push(infixe[i]); // Ajoute un element à la pile des operateur +,-,\,%
			else if (infixe[i] == "(") {
				while (operateur.top() != ")") {
					Pile->push(operateur.top());
					operateur.pop();
				}
				operateur.pop();
			}
			else {
				bool pushed = false;
				while (!pushed) {
					if (operateur.empty() || operateur.top() == ")" || precedance(infixe[i]) >= precedance(operateur.top())) {
					operateur.push(infixe[i]);
					pushed =true;
					}
					else {
						Pile->push(operateur.top());
						operateur.pop();
					}
				}
			}
		}
		
    }
	while (!operateur.empty()) {
		Pile->push(operateur.top());
		operateur.pop();
	}
    
    while (!Pile->empty())
    {
		prefixe->push (Pile->top());
		cout << " " << Pile->top();
		Pile->pop();
	}
}
        
int Prefixe:: evaluer_expression(stack<string> prefixe, vector<string> infixe)
{
    vector <string> tableau_to_convert; 
	stack <int> Resultat;
	int tempG, tempD;

	if (prefixe.empty()) 
			return -1;
	while (!prefixe.empty()) {
		
		for (int i=0; i < 2 && estNombre(prefixe.top()); i++) {
			tableau_to_convert.push_back(prefixe.top());
			prefixe.pop();
		}
		transformerennombres (tableau_to_convert); 
		
		if (!Tableau->empty()) {
			for (int i=Tableau->size()-1; i >= 0 ; i--) {
				Resultat.push (Tableau->back());
				Tableau->pop_back();
			}
		}
		else  {
			tempG = Resultat.top();
			Resultat.pop(); 
			tempD = Resultat.top();
			Resultat.pop();
			Resultat.push(operation (prefixe.top(), tempG, tempD));
			prefixe.pop();
		}
		tableau_to_convert.clear();
	}
	return Resultat.top();
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

   premier.transformerenprefixe (&prefixe, expression);
   cout << endl << "Resultat :" << premier.evaluer_expression (prefixe, expression) << endl;

	system ("pause");
}

bool estOperateur (string t) {
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

int operation (string operateur, int ope_gauche, int ope_droite) {
	
	char signe = operateur[0];
	switch (signe) {
		case '+' :	return (ope_gauche + ope_droite); 
			break;
		case '-' :	return (ope_gauche - ope_droite); 
			break;
		case '*' :	return (ope_gauche * ope_droite); 
			break;
		case '/' :	return (ope_gauche / ope_droite); 
			break;
		case '%' :  return (ope_gauche % ope_droite); 
			break;
		default :	return 0;
			break;
	}
}

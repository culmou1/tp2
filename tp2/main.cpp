/*----------------Bibliothèque----------------*/
#include <iostream>
#include "Header.h"
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;

/*----------------Function----------------*/
bool estNombre (string t);
bool estOperateur (string t);
int precedance(string t);
int operation (string operateur, int ope_gauche, int ope_droite);

/*----------------Classe----------------*/
Prefixe::Prefixe() {
	Pile = new stack <string>;
	Tableau = new vector <int>;
} // Constructeur

Prefixe::~Prefixe () {
	delete Pile;
	delete Tableau;
} // Destructueur
bool Prefixe :: lecture(vector<string> infixe)

{
    bool lectureToken = false;
    
    for (int i=0; i < infixe.size(); i++) //Parcous le tableau
    {
       if (estNombre (infixe[i]) || estOperateur (infixe[i])) /* Retourne la position du tableau et si le
                                                               nombre et termine si il est un nombre ou un
                                                               operateur */
			lectureToken  = true;
		else 
			return false; /* Si il n'est pas un autre nombre ou un Operateur return False */
	}
	return lectureToken;
}

bool Prefixe :: valider_expression (vector<string> infixe)
{
    int pargauche = 0, pardroite = 0; // Calculer le nombre de parenthèse;
    for (int i = 0; i < infixe.size(); i++) /* Parcours le tableau */
    {
        if (infixe[i] == "(")
        {
            pargauche += 1; // COMPTE LE NOMBRES DE PARATHÈSE "("
        }
        else if (infixe[i]== ")")
        {
            pardroite += 1; // COMPTE LE NOMBRES DE PARATHÈSE ")"
        }
    }
    if (pardroite ==pargauche) // Le nombre de parenthèse doit être égale
      return true; // Retourne Vrai si les parenthèse sont égales
   else
      return false; // Sinon retourne Faux
}
void Prefixe::transformerennombres (vector<string> tokens)

{
    for (int i=tokens.size()-1; i >= 0; i--) { // Parcours le tableau
		Tableau->push_back (stoi (tokens[i])); /* Stoi est une fonction qui transforme les caractères string en
                                                int avec la bibliothèque "cstdlib" */
	}
}

void Prefixe:: transformerenprefixe(stack<string> *prefixe, vector<string> infixe)
{
    stack <string> operande; // Pile pour les chiffre (3,4,5,etc)
    stack <string> operateur;// Pile pour les operateur // (+,-,*,etc)
    
	for (int i = infixe.size()-1; i >=0;i--) // Parcours notre tableau
    {
        if (estNombre (infixe[i])) { // Retourne vrai si il est un nombre
            operande.push(infixe[i]);// Ajoute un élément à la pile operande comme 3, 4, 5,6,
            Pile->push(infixe[i]); // Ajoute le nombre à notre pile
        }
		
		if (estOperateur (infixe[i])) { // Retourne vrai si il est un Opérateur
			if (infixe[i] == ")") // Vérifie si il y a une parenthèse ouvrante
            operateur.push(infixe[i]);
			else if (infixe[i] == "(") {
				while (operateur.top() != ")") { // Tanqu'il ne trouve pas sa parenthèse
					Pile->push(operateur.top()); // Ajoute à sa Pile
					operateur.pop(); // Enlève en élément à Opérateur
				}
				operateur.pop();
			}
			else {
				bool pushed = false;
				while (!pushed) {
					if (operateur.empty() || operateur.top() == ")" || precedance(infixe[i]) >= precedance(operateur.top())) { /* Doit s'assurer que operateur est vide ou parenthèse fermante ou 
                                             que l'operande est correctement positionner (Aller voir la fonction
                                            precedance un peu plus bas */
					operateur.push(infixe[i]);
					pushed =true;
					}
					else {
						Pile->push(operateur.top()); // Ajoute d'un élément de operateur
						operateur.pop(); // Supprimer l'élément Opérateur
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
			return -1; // Retourne un erreur si tableau Vide
	while (!prefixe.empty()) { // Boucle pour vider nôtre tableau
		
		for (int i=0; i < 2 && estNombre(prefixe.top()); i++) { // Conversion de nos chiffre en Entier
			tableau_to_convert.push_back(prefixe.top()); /* Prends les élément de la pile Prefixe
                                                          et les ajoute au tableaux de conversion */
			prefixe.pop();
		}
		transformerennombres (tableau_to_convert); // Conversion avec nôtre Classe
		
		if (!Tableau->empty()) {
			for (int i=Tableau->size()-1; i >= 0 ; i--) {
				Resultat.push (Tableau->back()); // Envoie les élément du tableaux dans la pile résultats
				Tableau->pop_back();
			}
		}
		else  {
			tempG = Resultat.top(); // Donne le nombre a temG pour la fonction operation plus bas
			Resultat.pop(); // Supprimer l'élément qui vient d'être assigner a temG
			tempD = Resultat.top();
			Resultat.pop();
			Resultat.push(operation (prefixe.top(), tempG, tempD)); // Appel de la fonction operation
			prefixe.pop();
		}
		tableau_to_convert.clear(); // Vide la tableau de conversion
	}
	return Resultat.top(); // Retourne le résultat un fois la boucle terminé
}
/* -------------------------------------------------------------------------------*/
/* DESCRIPTION :      Fonction principale du programmme								*/
/* PARAMETRES :		  Aucun															*/
/* VALEUR DE RETOUR : Aucune 														*/
/* REMARQUE : 		  Aucune														*/
/* -------------------------------------------------------------------------------*/
int main(void)
{
    Prefixe premier; // Constructeur
    string entree;
	int i = 0;
    vector <string> expression;
	stack <string> prefixe;
    
    cout << "Entrer une équation : ";
    cin >> entree;
   while ( i < entree.size()) {
	   string temp;
	   if (entree[i]>= '0' && entree[i] <= '9') {
		   while (entree[i]>= '0' && entree[i] <= '9') {
			   temp += entree[i];
			   i++;
		   }
		   expression.push_back(temp); // Ajoute les éléments à expression
	   }
	   else {
		   temp = entree[i];
		   expression.push_back (temp);
		   i++;
	   }
	}

	if (premier.lecture(expression)) // Valide l'expression
		cout << endl << "L'expression est bonne" << endl; // Retourne true
    else {
		cout << endl << "Il y a des caractères que je ne connais pas" << endl;
        return -1;
    }

    if (premier.valider_expression(expression)){ // Vérifié les parenthèse
	   cout << endl << "Le nombre parenthèse est correct: " << endl; // Retourne true
        cout << "*----------------Équation Préfixe----------------*" << endl;
       premier.transformerenprefixe (&prefixe, expression); // Transforme l'équation en Prefixe
        cout << endl << "*----------------Résultats----------------*" << endl;
        cout << premier.evaluer_expression (prefixe, expression) << endl;
    }
    else
	   cout << endl << "L'expression manque de parentheses" << endl; // Retourne false
    
	system ("pause");
}
/* -----------------------------------------------------------------------------------*/
/* DESCRIPTION :      Fonction estOperateur                                             */
/* PARAMETRES :		  string t                                                          */
/* VALEUR DE RETOUR : Retourne un String												*/
/* REMARQUE : 		  Aucune															*/
/* -----------------------------------------------------------------------------------*/
bool estOperateur (string t) {
	return (t == "+" || t == "-" || t == "*" || t == "/" || t == "%" || t == "(" || t == ")");
}
/* -----------------------------------------------------------------------------------*/
/* DESCRIPTION :      Fonction estNombre                                                */
/* PARAMETRES :		  string t                                                          */
/* VALEUR DE RETOUR : Un Booléen														*/
/* REMARQUE : 		  Aucune															*/
/* -----------------------------------------------------------------------------------*/
bool estNombre (string t) {
	for (int i = 0; i < t.size(); i++) {
		if (t[i] < '0' || t[i] > '9')
			return false;
	}
	return true;
}
/* -----------------------------------------------------------------------------------*/
/* DESCRIPTION :      Fonction precedance                                               */
/* PARAMETRES :		  string t                                                          */
/* VALEUR DE RETOUR : Retourne un nombre pour les priorités								*/
/* REMARQUE : 		  Ordre des priorités comme selon la conformité mathé-              */
/*                    mathique.                                                         */
/* -----------------------------------------------------------------------------------*/
int precedance(string t)
{
    int temp;
	if (t == "*" || t == "/" || t == "%")
       temp = 2;
    else  if (t == "+" || t == "-")
       temp = 1;
    return temp;
}

/* -----------------------------------------------------------------------------------*/
/* DESCRIPTION :      Fonction operation                                                */
/*				      Calcule les opérations d'après les opératons qu'elle reçoit       */
/* PARAMETRES :		  stringoperateur, int ope_gauche, int ope_droite					*/
/* VALEUR DE RETOUR : La somme de l'équation 											*/
/* REMARQUE : 		  Elle s'occupe de tout calculer dans notre programme				*/
/* -----------------------------------------------------------------------------------*/
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

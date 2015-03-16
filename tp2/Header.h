//
//  Header.h
//  tp2
//
//  Created by Daehli Nadeau Otis on 2015-02-27.
//  Copyright (c) 2015 Daehli Nadeau-Otis. All rights reserved.
//

#ifndef tp2_Header_h
#define tp2_Header_h
#include <vector>
#include <stack>
#include <algorithm>

class Prefixe {
	private :
		std::stack <std::string> *Pile;
		std::vector <int> *Tableau;

	public : 
		Prefixe(); //constructeur 
		~Prefixe (); //destructeur 
		bool lecture(std::vector<std::string> infixe); 
		/* lit l’expression à évaluer, à partir du clavier, dans tableau et valide si l’expression ne contient 
		que les caractères ci-dessus, à savoir les nombres entiers composés de caractères nombres, et les 
		opérateurs cités ci-dessus.*/
		bool valider_expression (std::vector<std::string> infixe); 
		/* teste si l’expression est bien définie (le nombre de parenthèses ouvrantes et fermantes est le même).*/
<<<<<<< Updated upstream
		void transformerennombres (std::vector<std::string> tokens); 
=======
		int transformerennombres (std::vector <std::string> tableau);
>>>>>>> Stashed changes
		/* transforme les nombres lus encaractères en valeurs numériques*/
		void transformerenprefixe(std::stack<std::string> *prefixe, std::vector<std::string> infixe);
		/*transforme l’expression lue en une expression prefixée et l’afficher.*/
		int evaluer_expression(std::stack<std::string> prefixe, std::vector<std::string> infixe); 
		// évalue l’expression préfixe
};

#endif

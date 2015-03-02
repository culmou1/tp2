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

class PREFIXE {
private:
    std :: stack <char> Pile;
    std :: vector <char> Tableau;
public :
    PREFIXE();// constructeur ;
    ~PREFIXE();// destructeur ;
    bool lecture(std::vector<char> Tableau );// lit l’expression à évaluer, à partir du clavier, dans tableau et valide si l’expression ne contient que les caractères ci-dessus, à savoir les nombres entiers composés de caractères nombres, et les opérateurs cités ci-dessus.
    bool valider_expression (std ::vector<char> Tableau); // teste si l’expression est bien définie (le nombre de parenthèses ouvrantes et fermantes est le même).
    void s (std::vector <char> Tableau); // transforme les nombres lus en caractères en valeurs numériques
    void transformerenpostfixe(std ::stack<char> Pile, std::vector<char> Tableau);// transforme l’expression lue en une expression prefixée et l’afficher.
    int evaluer_expression(std::stack<char> Pile, std::vector<char> Tableau); // évalue l’expression préfixée et affiche sa valeur.
};

#endif

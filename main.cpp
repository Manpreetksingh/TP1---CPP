#include "matrice.hpp"
#include <iostream>

using namespace std;


int main()
{
    // creation de matrices nulles
    Matrice m(6,6);
    cout << "la matrice m \n" << m << endl;


    Matrice m2(6,6);
    cout << "la matrice m2 \n" << m2 << endl;


    m2(2,3) = 10; // modifier une case
    cout << "on modifie la case (2,3)\n" << m2 << endl;


    Matrice m3(6,5);
    cout << "la matrice m3\n" << m3 << endl;
    m3 = m; // opérateur =
    cout << "m3 = m\n" << m3 << endl;

    cout << "on soustrait m-m2\n" << m-m2 << endl; // soustraction entre 2 matrices

    Matrice ms = m2-10; // soustraction avec scalaire
    cout << "on soustrait m2 par 10\n" << ms << endl;
    cout << "la trace est " << ms.trace() << "\n" << endl; // calcule la trace

    Matrice id = Matrice::identite(4); // retourne la matrice identite
    cout << "la matrice identite de taille 4 \n" << id << endl;
    cout << "la trace est " << id.trace() << "\n" << endl;

    Matrice al = Matrice::aleatoire(4,4); // retourne une matrice aleatoire
    cout << "la matrice aleatoire de taille 4,4 \n" << al <<endl;
    cout << "la trace est " << al.trace() << "\n" << endl;
        
    return 0;


}

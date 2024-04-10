#ifndef MATRICE
#define MATRICE


#include <vector>
#include <iostream>
#include <string>


class Matrice
{
    public:

        Matrice(){};
        Matrice(int n_, int m_); //constructeur qui créé matrice nulle
        Matrice(const Matrice & copie); // constructeur par copie, on ne modif pas la matrice
        ~Matrice(); //destructeur
        double& operator()(int const i, int const j); //accès en lecture et écriture à la case (i, j)
        Matrice operator=(const Matrice& mat); //copie entre deux matrices

        //multiplication, addition et soustraction entre 2 matrices
        Matrice operator*(const Matrice& mat) const;
        Matrice operator+(const Matrice& mat) const;
        Matrice operator-(const Matrice& mat) const;

        //multiplication, addition et soustraction entre matrice et un scalaire
        Matrice operator*(double sca) const;
        Matrice operator+(double sca) const;
        Matrice operator-(double sca) const;

        double trace() const; //calcule de la trace d'une matrice
        static Matrice identite(int taille); //revoie matrice identité de facon statique
        static Matrice aleatoire(int l, int c); //renvoie matrice avec valeurs aleatoires

        friend std::ostream& operator<<(std::ostream& os, const Matrice& m); //affichage de la matrice

    private:
        int n; //lignes de la matrice
        int m; //colonnes de la matrice
        double **ma; //la matrice
};

#endif

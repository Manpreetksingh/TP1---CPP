#include "matrice.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <random>


using namespace std;


Matrice::Matrice(int n_, int m_) //constructeur qui créé matrice nulle
{
    n = n_;
    m = m_;


    ma = new double * [n];
    for (int i = 0; i < n ; i++){
        ma[i] = new double [m];
    }


    for (int i = 0; i < n; i++){
        for (int j = 0; j < m ; j++){
            ma[i][j] = 0;
        }
    }
}


Matrice::Matrice(const Matrice & copie) // constructeur par copie, on ne modif pas la matrice
{
    n = copie.n;
    m = copie.m;


    ma = new double *[n];
    for (int i = 0; i < n; i++) {
        ma[i] = new double[m];
        // copier les données
        for (int j = 0; j < m; j++) {
            ma[i][j] = copie.ma[i][j];
        }
    }
}


double& Matrice::operator()(int const i, int const j) // accès en lecture et écriture à la case (i, j)
{
    if (i >= n && j >= m){
        cout << "Il y a une erreur, la case n'existe pas" << endl;
        return ma[0][0];
    }
    else {
        return ma[i][j];
    }
}


Matrice Matrice::operator=(const Matrice& mat) //copie entre deux matrices
{
    if (this != &mat) { // vérifie si ce n'est pas la même matrice
        // libére la mémoire de l'ancienne matrice
        for (int i = 0; i < n; i++) {
            delete[] ma[i];
        }
        delete[] ma;


        // copier les dimensions
        n = mat.n;
        m = mat.m;


        // copier les valeurs de la matrice dans la nouvelle matrice
        ma = new double * [n];
        for (int i = 0; i < n; i++) {
            ma[i] = new double[m];
            for (int j = 0; j < m; j++) {
                ma[i][j] = mat.ma[i][j];
            }
        }
    }
    return *this;
}


Matrice::~Matrice() // destructeur
{
    for (int i = 0; i < n ; i++){
        delete [] ma[i];
    }

    delete [] ma;
}


Matrice Matrice::operator*(const Matrice& mat) const { // multiplication entre 2 matrices
    if (m != mat.n) {
        std::cerr << "Les matrices ne sont pas de meme taille" << std::endl;
        return Matrice(0, 0); // retourne la matrice vide
        }


    Matrice matrice(n, mat.m); // matrice qui contient la multiplication
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < mat.m; ++j) {
            matrice.ma[i][j] = 0;
            for (int k = 0; k < m; ++k) {
                matrice.ma[i][j] += ma[i][k] * mat.ma[k][j];
            }
        }
    }
    return matrice;
}

Matrice Matrice::operator+(const Matrice& mat) const { // addition entre 2 matrices
    if (n != mat.n || m != mat.m) {
        std::cerr << "Erreur : Les dimensions des matrices ne correspondent pas pour l'addition." << std::endl;
        return Matrice(0, 0); // retourne la matrice vide
    }


    Matrice matrice(n, m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrice.ma[i][j] = ma[i][j] + mat.ma[i][j];
        }
    }
    return matrice;
}


Matrice Matrice::operator-(const Matrice& mat) const { // soustraction entre 2 matrices
    if (n != mat.n || m != mat.m) {
        std::cerr << "Les matrices ne sont pas de meme taille" << std::endl;
        return Matrice(0, 0); // retourne la matrice vide
    }


    Matrice matrice(n, m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrice.ma[i][j] = ma[i][j] - mat.ma[i][j];
        }
    }
    return matrice;
}


Matrice Matrice::operator*(double sca) const { // multiplication entre matrice et scalaire
    Matrice matrice(n, m); // matrice qui contient le produit
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrice.ma[i][j] = ma[i][j] * sca;
        }
    }
    return matrice;
}


Matrice Matrice::operator+(double sca) const { // addition entre matrice et scalaire
    Matrice matrice(n, m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrice.ma[i][j] = ma[i][j] + sca;
        }
    }
    return matrice;
}


Matrice Matrice::operator-(double sca) const { // soustraction entre matrice et scalaire
    Matrice matrice(n, m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrice.ma[i][j] = ma[i][j] - sca;
        }
    }
    return matrice;
}


double Matrice::trace() const { // calcule de la trace d'une matrice
    if (n != m) {
        std::cerr << "La matrice n'est pas carrée" << std::endl;
        return 0; // retourne 0
    }


    double trace = 0;
    for (int i = 0; i < n; ++i) {
        trace += ma[i][i]; // somme de la diagonale
    }
    return trace;
}

Matrice Matrice::identite(int taille) { // renvoie une matrice d'identité
    Matrice identite(taille, taille); // matrice carrée

    for (int i = 0; i < taille; ++i) {
        for (int j = 0; j < taille; ++j) {
            if (i == j) {
                identite(i, j) = 1; // diagona à 1
            } else {
                identite(i, j) = 0; // reste à 0
            }
        }
    }

    return identite;
}

Matrice Matrice::aleatoire(int l, int c) { // renvoie matrice avec valeurs aleatoires
    Matrice aleatoire(l, c); // nouvelle matrice 

    // distribution aléatoire
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(0, 1);

    // mettre valeurs aléatoires dans le matrice
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < c; ++j) {
            aleatoire(i, j) = dis(gen); 
        }
    }

    return aleatoire;
}

std::ostream& operator<<(std::ostream & os, const Matrice &m){ // affichage de la matrice
    for (int i = 0; i < m.n; ++i) {
        for (int j = 0; j < m.m; ++j) {
            os << m.ma[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}



#pragma once
#include <iostream>
using namespace std;

class Bruch
{
    private:
        int zaehler;
        int nenner;
        int ggt();
    public:
        Bruch();
        Bruch(int z, int n);
        int getZaehler();
        int getNenner();
        Bruch addiere(Bruch b);
        Bruch subtrahiere(Bruch b);
        Bruch multipliziere(Bruch b);
        Bruch dividiere(Bruch b);
        void kuerzen();

        // Arithmetische Operatoren (TODO -, *, /)
        Bruch operator + (Bruch b);
        Bruch operator - (Bruch b);
        Bruch operator * (Bruch b);
        Bruch operator / (Bruch b);

        // Prefix ++x (TODO --)
        void operator++();

        // Vergleichsoperatoren (TODO >, <=, >=, ==, !=)
        bool operator < (Bruch b);  // TODO - Implementierung vervollstaendigen
        
        // Ausgabe-Operator
        friend ostream &operator<<(ostream &out, Bruch &b);

        ~Bruch();
};

void test_ArithOp();
void test_VergleichOp();
void test_Mix();


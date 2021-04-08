#include "Bruch.h"

/*********** KLASSE BRUCH **********/

Bruch::Bruch()
{
}

Bruch::Bruch(int z, int n)
{
    //cout << "Im erweiterten Konstruktor." << endl;
    zaehler = z;
    nenner = n;
}

int Bruch::getZaehler()
{
    return this->zaehler;
}

int Bruch::getNenner()
{
    return this->nenner;
}


// Der groesste gemeinsame Teiler wird berechnet
int Bruch::ggt()
{
    int a = abs(this->zaehler);
    int b = abs(this->nenner);
    
    if (b == 0 && a == 0)
    {
        return 1;
    }
    else if (b == 0)
    {
        return a;
    }
    else if (a != 0) {
        while (a != b) {
            if (a > b) a = a - b;
            else b = b - a;
        }
        return a;
    }
    else {
        return b;
    }
}

Bruch Bruch::operator + (Bruch b2)
{
    return addiere(b2);
}

Bruch Bruch::operator - (Bruch b2)
{
    return subtrahiere(b2);
}

Bruch Bruch::operator * (Bruch b2)
{
    return multipliziere(b2);
}

Bruch Bruch::operator / (Bruch b2)
{
    return dividiere(b2);
}

void Bruch::operator ++ ()
{
    zaehler = zaehler + nenner;
}

ostream &operator << (ostream & out, Bruch &b)
{
    out << b.zaehler << "/" << b.nenner;
    return out;
}

void Bruch::kuerzen()
{
    int ggTeiler = ggt();
    zaehler = zaehler / ggTeiler;
    nenner = nenner / ggTeiler;
}

Bruch Bruch::addiere(Bruch b2)
{
    Bruch bReturn;
    bReturn.nenner = b2.nenner * this->nenner;
    bReturn.zaehler = b2.zaehler * this->nenner + this->zaehler * b2.nenner;
    bReturn.kuerzen();
    return bReturn;
}

Bruch Bruch::subtrahiere(Bruch b2)
{
    Bruch bReturn;
    bReturn.nenner = b2.nenner * this->nenner;
    bReturn.zaehler = b2.zaehler * this->nenner - this->zaehler * b2.nenner;
    bReturn.kuerzen();
    return bReturn;
}

Bruch Bruch::multipliziere(Bruch b2)
{
    Bruch bReturn;
    bReturn.zaehler = b2.zaehler * this->zaehler;
    bReturn.nenner = b2.nenner * this->nenner;
    bReturn.kuerzen();
    return bReturn;
}

Bruch Bruch::dividiere(Bruch b2)
{
    Bruch bReturn;
    bReturn.zaehler = b2.zaehler / this->zaehler;
    bReturn.nenner = b2.nenner / this->nenner;
    bReturn.kuerzen();
    return bReturn;
}

Bruch::~Bruch()
{
    //cout << "Im Destruktor." << endl;
}

bool Bruch::operator < (Bruch b)
{
    // TODO
    return false;    // <-- anpassen
}

/*********** ANDERE FUNKTIONEN **********/

void test_ArithOp()
{
    cout << "\n### ARITH-OP ###\n";

    Bruch b1(1, 2);
    Bruch b2(3, 4);

    cout << "Bruch b1: " << b1 << "\n";
    cout << "Bruch b2: " << b2 << "\n";
    Bruch c = b1 + b2;
    //cout << "Bruch c (b1 + b2): " << c << "\n";
    
    c = b1 - b2;
    //cout << "Bruch c (b1 - b2): " << c << "\n";
    if (c.getZaehler() == -1 && c.getNenner() == 4)
        cout << "-: OK.\n";
    else
        cout << "-: nicht OK.\n";
    
    c = b1 * b2;
    //cout << "Bruch c (b1 * b2): " << c << "\n";
    if (c.getZaehler() == 3 && c.getNenner() == 8)
        cout << "*: OK.\n";
    else
        cout << "*: nicht OK.\n";
    
    c = b1 / b2;
    //cout << "Bruch c (b1 / b2): " << c << "\n";
    if (c.getZaehler() == 2 && c.getNenner() == 3)
        cout << "/: OK.\n";
    else
        cout << "/: nicht OK.\n";
    
    ++c;
    //cout << "Bruch c (nach ++): " << c << "\n";
    if (c.getZaehler() == 5 && c.getNenner() == 3)
        cout << "++: OK.\n";
    else
        cout << "++: nicht OK.\n";
    
//    --c;
//    //cout << "Bruch c (nach --): " << c << "\n";
//    if (c.getZaehler() == 2 && c.getNenner() == 3)
//        cout << "--: OK.\n";
//    else
//        cout << "--: nicht OK.\n";
//}
//
//void test_VergleichOp()
//{
//    cout << "\n### VERGLEICH-OP ###\n";
//
//    Bruch b1(1, 2);
//    Bruch b2(3, 4);
//    Bruch b3(2, 4);
//
//    cout << "Bruch b1: " << b1 << "\n";
//    cout << "Bruch b2: " << b2 << "\n";
//    cout << "Bruch b3: " << b3 << "\n";
//
//    if ((b1 > b2) == false)
//        cout << ">: OK.\n";
//    else
//        cout << ">: nicht OK.\n";
//
//    if ((b1 < b2) == true)
//        cout << "<: OK.\n";
//    else
//        cout << "<: nicht OK.\n";
//
//    if ((b1 <= b2) == true && (b2 <= b3) == false)
//        cout << "<=: OK.\n";
//    else
//        cout << "<=: nicht OK.\n";
//
//    if ((b1 >= b2) == false && (b2 >= b3) == true)
//        cout << ">=: OK.\n";
//    else
//        cout << ">=: nicht OK.\n";
//
//    if ((b1 == b2) == false && (b1 == b3) == true)
//        cout << "==: OK.\n";
//    else
//        cout << "==: nicht OK.\n";
//
//    if ((b1 != b2) == true && (b1 != b3) == false)
//        cout << "!=: OK.\n";
//    else
//        cout << "!=: nicht OK.\n";
//}
//
//void test_Mix()
//{
//    cout << "\n### MIX OPERATOR ###\n";
//
//    Bruch b1(3, 4);
//    Bruch b2(4, 5);
//
//    cout << "Bruch b1: " << b1 << "\n";
//    cout << "Bruch b2: " << b2 << "\n";
//    Bruch c = b1 + b2;
//    cout << "Bruch c (b1 + b2): " << c << "\n";
//    ++c;
//    cout << "Bruch c (nach ++): " << c << "\n";
//    --c;
//    cout << "Bruch c (nach --): " << c << "\n";
//
//    Bruch c1;
//    c1 = b1 * b2;
//    cout << "Bruch c1 (b1 * b2): " << c1 << "\n";
//
//    if (c1 < b1)
//        cout << c1 << " < " << b1 << "\n";
//    else if (c1 > b1)
//        cout << c1 << " > " << b1 << "\n";
//    if (c1 != b1)
//        cout << c1 << " != " << b1 << "\n";
//
//    Bruch c2;
//    c2 = c1 / b2;
//    cout << "Bruch c2 (c1 / b2): " << c2 << "\n";
//
//    if (c2 == b1)
//        cout << c2 << " == " << b1 << "\n";
//    cout << "\n";
//}
//
//
}

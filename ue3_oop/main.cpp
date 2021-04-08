#include "Bruch.h"

int main()
{
    // Testfunktionen
    test_ArithOp();
    test_VergleichOp();
    test_Mix();

    Bruch eins(10,5);
    Bruch zwei(20,10);
    Bruch h;
    
    h = eins + zwei;
    
    cout << "Hello" << endl;

}


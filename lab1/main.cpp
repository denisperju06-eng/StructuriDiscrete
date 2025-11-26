#include <iostream>
using namespace std;

void Linie(int coloane) {
    cout << "\n+";
    for (int i = 0; i < coloane; i++) {
        for (int j = 0; j < 5; j++) 
            cout << "-";
        cout << "+";
    }
}

void Linie567() {
    cout << "+-----+-----+--------+\n";
}

void afiseazaRand567(int a, int b, int val) {
    cout << "|  " << a << "  |  " << b << "  |   " << val << "    |\n";
}

int main() {
    int a, b, c, d;

    cout << "Proiectul nr.1 elaborat de Perju Denis!" << endl;

    cout << "\n\t1. Negatia";
    Linie(2);
    cout << "\n|  A  |not A|";
    Linie(2);
    for (a = 0; a <= 1; a++)
        cout << "\n|  " << a << "  |  " << !a << "  |";
    Linie(2);

    cout << "\n\t2. Conjunctia";
    Linie(3);
    cout << "\n|  A  |  B  | A∧B |";
    Linie(3);
    for (a = 0; a <= 1; a++)
        for (b = 0; b <= 1; b++)
            cout << "\n|  " << a << "  |  " << b << "  |  " << (a && b) << "  |";
    Linie(3);

    cout << "\n\t3. Disjunctia";
    Linie(3);
    cout << "\n|  A  |  B  | AvB |";
    Linie(3);
    for (a = 0; a <= 1; a++)
        for (b = 0; b <= 1; b++)
            cout << "\n|  " << a << "  |  " << b << "  |  " << (a || b) << "  |";
    Linie(3);

    cout << "\n\t4. Diferenta (A - B)";
    Linie(3);
    cout << "\n|  A  |  B  | A-B |";
    Linie(3);
    for (a = 0; a <= 1; a++)
        for (b = 0; b <= 1; b++)
            cout << "\n|  " << a << "  |  " << b << "  |  " << (a && !b) << "  |";
    Linie(3);

    cout << "\n\t5. Conectorul Sheffer (NAND)\n";
    Linie567();
    cout << "|  A  |  B  | !(A&&B)|\n";
    Linie567();
    for (a = 0; a <= 1; a++)
        for (b = 0; b <= 1; b++)
            afiseazaRand567(a, b, !(a && b));
    Linie567();

    cout << "\n\t6. Conectorul Pierce (NOR)\n";
    Linie567();
    cout << "|  A  |  B  | !(A||B)|\n";
    Linie567();
    for (a = 0; a <= 1; a++)
        for (b = 0; b <= 1; b++)
            afiseazaRand567(a, b, !(a || b));
    Linie567();

    cout << "\n\t7. Implicatia (A -> B)\n";
    Linie567();
    cout << "|  A  |  B  |  A->B  |\n";
    Linie567();
    for (a = 0; a <= 1; a++)
        for (b = 0; b <= 1; b++)
            afiseazaRand567(a, b, ((!a) || b));
    Linie567();

    cout << "\n\t8. Echivalenta (A <-> B)";
    Linie(3);
    cout << "\n|  A  |  B  | A↔B |";
    Linie(3);
    for (a = 0; a <= 1; a++)
        for (b = 0; b <= 1; b++)
            cout << "\n|  " << a << "  |  " << b << "  |  " << (a == b) << "  |";
    Linie(3);

    cout << "\n\t9. Problema logica cu 3 variabile";
    cout << "\n    F = (A && B) || (!C)";
    Linie(4);
    cout << "\n|  A  |  B  |  C  |  F  |";
    Linie(4);
    for (a = 0; a <= 1; a++)
        for (b = 0; b <= 1; b++)
            for (c = 0; c <= 1; c++) {
                int F = (a && b) || (!c);
                cout << "\n|  " << a << "  |  " << b << "  |  " << c << "  |  " << F << "  |";
            }
    Linie(4);

    cout << "\n\t10. Problema logica cu 4 variabile";
    cout << "\n     F = (A || B) && (!C || D)";
    Linie(5);
    cout << "\n|  A  |  B  |  C  |  D  |  F  |";
    Linie(5);
    for (a = 0; a <= 1; a++)
        for (b = 0; b <= 1; b++)
            for (c = 0; c <= 1; c++)
                for (d = 0; d <= 1; d++) {
                    int F = (a || b) && ((!c) || d);
                    cout << "\n|  " << a << "  |  " << b << "  |  " << c << "  |  " << d << "  |  " << F << "  |";
                }
    Linie(5);

    cout << "\n\t11. Problema logica reala (mers la cinema)";
    cout << "\n    F = (A && B) || (A && C) || (B && C)";
    cout << "\n    Unde: A = Ana, B = Bogdan, C = Cristina";
    Linie(4);
    cout << "\n|  A  |  B  |  C  |  F  |";
    Linie(4);
    for (a = 0; a <= 1; a++)
        for (b = 0; b <= 1; b++)
            for (c = 0; c <= 1; c++) {
                int F = (a && b) || (a && c) || (b && c);
                cout << "\n|  " << a << "  |  " << b << "  |  " << c << "  |  " << F << "  |";
            }
    Linie(4);

    cout << "\n\nSfarsitul programului.\n";
    return 0;
}

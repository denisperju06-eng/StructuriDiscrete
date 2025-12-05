#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>

using namespace std;

// Definim tipul pentru numere mari (Unsigned Long Long)
typedef unsigned long long llu;
int count=0;

// --- Declaratii de functii ---
// Factorial
llu Factorial(unsigned n);
llu FactorialRecursiv(unsigned n);

// Permutari
llu Permutari(unsigned n);

// Aranjamente
llu Aranjamente(unsigned n, unsigned m);
llu AranjamenteOptim(unsigned n, unsigned m);

// Combinari
llu Combinari(unsigned n, unsigned m);
llu CombinariOptim(unsigned n, unsigned m);

// Putere (pentru repetitii)
llu Power(unsigned n, unsigned k); // Iterativ
llu PowerRecursiv(unsigned n, unsigned k); // Recursiv

// Cu Repetitie
llu RPermutari(unsigned n);
llu RAranjamente(unsigned n, unsigned m); // Iterativ, bazat pe Power
llu RAranjamenteRecursiv(unsigned n, unsigned m); // Recursiv, bazat pe PowerRecursiv
llu RCombinari(unsigned n, unsigned m);

// Permutari cu obiecte identice
llu RCPermutari(char s[]);

// Binomul lui Newton
void BinomulNewton(unsigned p);

// Sarcina specifica
llu Sarcina10_Placute();
int Afisare_Placute(int cate);

// --- Functia Principala ---
int main()
{
    unsigned n, m;
    cout << "Oferiti valoarea numarului total: n = ";
    if (!(cin >> n)) { cerr << "Eroare la citirea lui n." << endl; return 1; }

    cout << "Oferiti valoarea lui m = ";
    if (!(cin >> m)) { cerr << "Eroare la citirea lui m." << endl; return 1; }

    cout << "\nProiect nr. 2, elaborat de Perju Denis" << endl;
    cout << "Tema: Elemente din combinatorica" << endl;

    // ------------------------------------------------------------------
    // 1. Factorial
    // ------------------------------------------------------------------
    cout << "\n1.1. Factorial iterativ\n";
    for (unsigned i = 0; i <= 20; ++i)
    {
        cout << setw(2) << left << i << "! = " << setw(20) << Factorial(i) << "| ";
        if ((i + 1) % 4 == 0) cout << endl;
    }

    cout << "\n1.2. Factorial recursiv\n";
    for (unsigned i = 0; i <= 20; ++i)
    {
        cout << setw(2) << left << i << "! = " << setw(20) << FactorialRecursiv(i) << "| ";
        if ((i + 1) % 4 == 0) cout << endl;
    }
    cout << endl;

    // ------------------------------------------------------------------
    // 2-5. Fara Repetitie
    // ------------------------------------------------------------------
    cout << "\n2. Permutari> P(" << n << ") = " << Permutari(n) << endl;

    cout << "3.1. Aranjamente (n!/(n-m)!)> A(" << n << ", " << m << ") = " << Aranjamente(n, m) << endl;
    cout << "3.2. Aranjamente Optim (Iterativ)> A(" << n << ", " << m << ") = " << AranjamenteOptim(n, m) << endl;

    cout << "4.1. Combinari (n!/m!(n-m)! )> C(" << n << ", " << m << ") = " << Combinari(n, m) << endl;
    cout << "4.2. Combinari Optim (Iterativ)> C(" << n << ", " << m << ") = " << CombinariOptim(n, m) << endl;

    // ------------------------------------------------------------------
    // 6. Cu Repetitie
    // ------------------------------------------------------------------
    cout << "\n5. Permutari cu repetitii (n^n)> PR(" << n << ") = " << RPermutari(n) << endl;

    cout << "6.1. Putere (n^m) Iterativ> AR(" << n << ", " << m << ") = " << Power(n, m) << endl;
    cout << "6.2. Putere (n^m) Recursiv> AR(" << n << ", " << m << ") = " << PowerRecursiv(n, m) << endl;

    cout << "6.3. Aranjamente cu repetitii (Iterativ)> AR(" << n << ", " << m << ") = " << RAranjamente(n, m) << endl;
    cout << "6.4. Aranjamente cu repetitii (Recursiv)> AR(" << n << ", " << m << ") = " << RAranjamenteRecursiv(n, m) << endl;

    cout << "7. Combinari cu repetitii (Optim)> CR(" << n << ", " << m << ") = " << RCombinari(n, m) << endl;

    // ------------------------------------------------------------------
    // Alte Sarcini
    // ------------------------------------------------------------------

    // --- Binomul lui Newton ---
    unsigned p;
    cout << "\nIntroduceti p pentru Binomul lui Newton (coeficienti si forma (a+b)^p): p = ";
    if (!(cin >> p)) { cerr << "Eroare la citirea lui p." << endl; return 1; }
    BinomulNewton(p);

    // --- Permutari de cuvinte ---
    cout << "\nIntroduceti un cuvant (max 19 caractere) pentru permutari distincte: ";
    char s[20];
    cin >> s;
    cout << "Numarul de permutari distincte ale cuvantului '" << s << "' = " << RCPermutari(s) << endl;

    cout << "\n--- Sarcina 10: Placute auto ---\n";

    llu total = Sarcina10_Placute();
    cout << "Numarul total de placute auto: " << total << "\n\n";

    int a;
    cout << "Introduceti numarul de placute de afisat: ";
    cin >> a;

    cout << "\nPrimele " << a << " placute auto:\n";
    cout<<"In total\n"<<Afisare_Placute(a)<<"placute";


    return 0;
}

// ===================================================
// --- Implementarea Functiilor ---
// ===================================================

// Factorial Iterativ
llu Factorial(unsigned n)
{
    llu f = 1;
    for (unsigned i = 2; i <= n; ++i) f *= i;
    return f;
}

// Factorial Recursiv
llu FactorialRecursiv(unsigned n)
{
    if (n <= 1) return 1;
    return FactorialRecursiv(n - 1) * n;
}

// Permutari P(n) = n!
llu Permutari(unsigned n)
{
    return Factorial(n);
}

// Aranjamente A(n, m) = n! / (n-m)! (Versiunea ne-optimizata)
llu Aranjamente(unsigned n, unsigned m)
{
    if (m > n) return 0;
    return Factorial(n) / Factorial(n - m);
}

// Aranjamente A(n, m) (Versiunea Optim/Iterativa)
llu AranjamenteOptim(unsigned n, unsigned m)
{
    if (m > n) return 0;
    llu result = 1;
    for (unsigned i = 0; i < m; ++i) {
        result *= (n - i);
    }
    return result;
}

// Combinari C(n, m) = n! / (m! * (n-m)!) (Versiunea ne-optimizata)
llu Combinari(unsigned n, unsigned m)
{
    if (m > n) return 0;
    return Factorial(n) / (Factorial(m) * Factorial(n - m));
}

// Combinari C(n, m) (Versiunea Optim/Iterativa)
llu CombinariOptim(unsigned n, unsigned m)
{
    if (m > n) return 0;
    unsigned k = m;
    if (k > n - k) k = n - k;

    llu num = 1;
    for (unsigned i = 1; i <= k; ++i)
    {
        num = num * (n - k + i) / i;
    }
    return num;
}

// Putere n^k (Iterativ)
llu Power(unsigned n, unsigned k)
{
    llu p = 1;
    for (unsigned i = 0; i < k; ++i) p *= n;
    return p;
}

// Putere n^k (Recursiv)
llu PowerRecursiv(unsigned n, unsigned k)
{
    if (k == 0) return 1;
    return PowerRecursiv(n, k - 1) * n;
}

// Permutari cu repetitii PR(n) = n^n
llu RPermutari(unsigned n)
{
    return Power(n, n);
}

// Aranjamente cu repetitii AR(n, m) = n^m (Iterativ)
llu RAranjamente(unsigned n, unsigned m)
{
    return Power(n, m);
}

// Aranjamente cu repetitii AR(n, m) = n^m (Recursiv)
llu RAranjamenteRecursiv(unsigned n, unsigned m)
{
    return PowerRecursiv(n, m);
}

// Combinari cu repetitii CR(n, m) = C(n + m - 1, m)
llu RCombinari(unsigned n, unsigned m)
{
    return CombinariOptim(n + m - 1, m);
}

// Permutari de cuvinte (obiecte identice)
llu RCPermutari(char s[])
{
    unsigned freq[256] = {0};
    unsigned len = 0;
    while (s[len] != '\0' && len < 20) {
        freq[(unsigned char)s[len]]++;
        len++;
    }

    llu total = Factorial(len);
    llu denom = 1;
    for (unsigned c = 0; c < 256; ++c)
        if (freq[c] > 1)
            denom *= Factorial(freq[c]);

    if (denom == 0) return 0;
    return total / denom;
}

// Binomul lui Newton
void BinomulNewton(unsigned p)
{
    cout << "\nBinomul lui Newton pentru p = " << p << "\n";
    cout << "Coeficientii C(" << p << ", k):\n";
    for (unsigned k = 0; k <= p; ++k) {
        cout << "C(" << p << "," << k << ") = " << CombinariOptim(p, k);
        if (k < p) cout << ", ";
    }
    cout << "\n\nForma simbolica (a+b)^" << p << " = ";
    for (unsigned k = 0; k <= p; ++k) {
        llu c = CombinariOptim(p, k);
        if (k > 0) cout << " + ";
        if (c != 1) cout << c << "*";

        // a^(p-k)
        if (p - k > 0) {
            cout << "a";
            if (p - k > 1) cout << "^" << (p - k);
        }

        // b^k
        if (k > 0) {
            if (p - k > 0) cout << "*";
            cout << "b";
            if (k > 1) cout << "^" << k;
        }

        if (p == 0 && k == 0) cout << "1";
    }
    cout << "\n";
}

// Sarcina 10: Placute auto - total
llu Sarcina10_Placute()
{
    // 3 litere distincte din 26: A(26,3) = 26*25*24
    llu litere = 26ULL * 25ULL * 24ULL;

    // 3 cifre 0-9 cu repetitie: 10^3
    llu cifre = 10ULL * 10ULL * 10ULL;

    return litere * cifre; // total placute
}

// Sarcina 10: Placute auto - afisare primele 'cate'
int Afisare_Placute(int cate)
{
    int afisate = 0;

    for (char a = 'A'; a <= 'Z' && afisate < cate; a++)
        for (char b = 'A'; b <= 'Z' && afisate < cate; b++)
            for (char c = 'A'; c <= 'Z' && afisate < cate; c++)
                if (a != b && a != c && b != c) // litere distincte
                    for (char d1 = '0'; d1 <= '9' && afisate < cate; d1++)
                        for (char d2 = '0'; d2 <= '9' && afisate < cate; d2++)
                            for (char d3 = '0'; d3 <= '9' && afisate < cate; d3++)
                            {
                                cout << a << b << c << "-" << d1 << d2 << d3 << " ";
                                afisate++;
                                if (afisate%10 ==0 ) {
                                    cout<<endl;
                                }
                                if (afisate >= cate) break;
                            }
    return afisate;
}

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
typedef unsigned long long llu;

llu Factorial(unsigned n);
llu FactorialRecursiv(unsigned n);
llu Permutari(unsigned n);
llu Aranjamente(unsigned n, unsigned m);
llu Combinari(unsigned n, unsigned m);
llu CombinariOptim(unsigned n, unsigned m);
llu Power(unsigned n, unsigned k);
llu RPermutari(unsigned n);
llu RAranjamente(unsigned n, unsigned m);
llu RCombinari(unsigned n, unsigned m);
llu RCPermutari(char s[]);
void BinomulNewton(unsigned p);
llu Sarcina10_Placute();

int main()
{
    system("color 0A");
    system("cls");

    unsigned n, m;
    cout << "Oferiti valoarea numarului total: n = ";
    cin >> n;
    cout << "Oferiti valoarea lui m = ";
    cin >> m;

    cout << "Proiect nr. 2, elaborat de Perju Denis" << endl;
    cout << "Tema: Elemente din combinatorica" << endl;

    cout << "\n1.1. Factorial iterativ\n";
    for (unsigned i = 0; i <= 20; ++i)
    {
        cout << setw(2) << left << i << "! = " << setw(20) << Factorial(i) << "| ";
        if (i % 4 == 0) cout << endl;
    }

    cout << "\n1.2. Factorial recursiv\n";
    for (unsigned i = 0; i <= 20; ++i)
    {
        cout << setw(2) << left << i << "! = " << setw(20) << FactorialRecursiv(i) << "| ";
        if (i % 4 == 0) cout << endl;
    }

    cout << "\n2. Permutari> P(" << n << ") = " << Permutari(n) << endl;
    cout << "3. Aranjamente> A(" << n << ", " << m << ") = " << Aranjamente(n, m) << endl;
    cout << "4. Combinari> C(" << n << ", " << m << ") = " << Combinari(n, m) << endl;
    cout << "5. Combinari Optim> C(" << n << ", " << m << ") = " << CombinariOptim(n, m) << endl;
    cout << "6.1. Permutari cu repetitii (n^n)> PR(" << n << ") = " << RPermutari(n) << endl;
    cout << "6.2. Aranjamente cu repetitii (n^m)> AR(" << n << ", " << m << ") = " << RAranjamente(n, m) << endl;
    cout << "7. Combinari cu repetitii> CR(" << n << ", " << m << ") = " << RCombinari(n, m) << endl;

    // --- Binomul lui Newton ---
    unsigned p;
    cout << "\nIntroduceti p pentru Binomul lui Newton (coeficienti si forma (a+b)^p): p = ";
    cin >> p;
    BinomulNewton(p);

    // --- Permutari de cuvinte ---
    cout << "\nIntroduceti un cuvant (max 19 caractere) pentru permutari distincte: ";
    char s[20];
    cin >> s;
    cout << "Numarul de permutari distincte ale cuvantului '" << s << "' = " << RCPermutari(s) << endl;

    // --- Sarcina 10: Placute auto ---
    cout << "\n--- Sarcina 10: Problema placute auto ---\n";
    cout << "Conditie: o placuta auto este formata din 3 litere distincte + 3 cifre (repetitie permisa)\n";
    cout << "Numarul total de placute auto distincte: " << Sarcina10_Placute() << endl;

    return 0;
}


llu Factorial(unsigned n)
{
    llu f = 1;
    for (unsigned i = 2; i <= n; ++i) f *= i;
    return f;
}

llu FactorialRecursiv(unsigned n)
{
    if (n <= 1) return 1;
    return FactorialRecursiv(n - 1) * n;
}

llu Permutari(unsigned n)
{
    return Factorial(n);
}

llu Aranjamente(unsigned n, unsigned m)
{
    if (m > n) return 0;
    return Factorial(n) / Factorial(n - m);
}

llu Combinari(unsigned n, unsigned m)
{
    if (m > n) return 0;
    return Factorial(n) / (Factorial(m) * Factorial(n - m));
}

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

llu Power(unsigned n, unsigned k)
{
    llu p = 1;
    for (unsigned i = 0; i < k; ++i) p *= n;
    return p;
}

llu RPermutari(unsigned n)
{
    return Power(n, n);
}

llu RAranjamente(unsigned n, unsigned m)
{
    return Power(n, m);
}

llu RCombinari(unsigned n, unsigned m)
{
    return CombinariOptim(n + m - 1, m);
}

llu RCPermutari(char s[])
{
    unsigned freq[256] = {0};
    unsigned len = 0;
    while (s[len] != '\0' && len < 19) ++len;
    for (unsigned i = 0; i < len; ++i) freq[(unsigned char)s[i]]++;

    llu denom = 1;
    for (unsigned c = 0; c < 256; ++c)
        if (freq[c] > 1) denom *= Factorial(freq[c]);

    llu total = Factorial(len) / denom;
    return total;
}

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
        cout << "a^" << (p - k) << "*b^" << k;
    }
    cout << "\n";
}

/* --- Sarcina 10: Placute auto --- */
llu Sarcina10_Placute()
{
    // Sarcina 10. Problema: Număr de plăcuțe auto
    // Se consideră sistemul de înmatriculare în care o plăcuță este formată din:
    //  - 3 litere (A–Z), fără repetarea literelor
    //  - 3 cifre (0–9), cu repetarea cifrelor permisă

    llu litere = 26ULL * 25ULL * 24ULL;
    llu cifre = 1000ULL; // 10^3
    return litere * cifre;
}

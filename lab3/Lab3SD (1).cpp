#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream fin("grafin.txt");

    cout << "Proiect Nr. 3, elaborat de Perju Denis!" << endl;

    int a[20][20], s[20], t[20], c[20], n, m, cost, i, j, k, n1, n2, start, costm;
    string name[20]; // numele orașelor

    fin >> n >> m;   // citim numar de varfuri si muchii
    fin.ignore();    // eliminăm newline

    // CITEȘTE NUMELE ORAȘELOR
    for (i = 1; i <= n; i++)
        getline(fin, name[i]);

    cout << "Numar de varfuri: " << n << endl;
    cout << "Dati 3200 daca nu exista muchie" << endl;

    // Initializare matrice
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            a[i][j] = 3200;
        a[i][i] = 0;
    }

    // Citește muchiile
    int x, y;
    for (k = 1; k <= m; k++)
    {
        fin >> x >> y >> a[x][y];
        a[y][x] = a[x][y];
    }

    // Afisare matrice
    cout << "\nMatricea A\n";
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            cout << a[i][j] << "  ";
        cout << endl;
    }

    cout << "\nArborele partial de cost minim (Prim)\n";

    // Prim
    for (i = 1; i <= n; i++)
        s[i] = t[i] = c[i] = 0;

    start = 1;
    s[start] = 1;

    for (k = 1; k <= n - 1; k++)
    {
        costm = 32000;
        n1 = -1;
        n2 = -1;

        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (s[i] == 1 && s[j] == 0)
                    if (a[i][j] < costm)
                    {
                        costm = a[i][j];
                        n1 = i;
                        n2 = j;
                    }

        s[n2] = 1;
        t[n2] = n1;
        c[n2] = a[n1][n2];
    }

    // Afișare muchii MST cu nume de orașe
    cout << "\nMuchiile MST:\n";
    for (i = 2; i <= n; i++)
        cout << name[t[i]] << "  -  " << name[i] << "   cost = " << c[i] << endl;

    // cost total
    cost = 0;
    for (i = 1; i <= n; i++)
        cost += c[i];

    cout << "\nCost minim al arborelui: " << cost << endl;

    fin.close();
    return 0;
}

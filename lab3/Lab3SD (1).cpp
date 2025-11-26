#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin;
    fin.open("grafin.txt");
    system("color 0A");
    system("cls");

    cout << "Proiect Nr. 3, elaborat de Perju Denis!" << endl;

    int a[20][20], s[20], t[20], c[20], n, m, cost, i, j, k, n1, n2, start, costm;

    fin >> n >> m;

    cout << "Numar de varfuri: " << n << endl;
    cout << "Dati 3200 daca nu exista muchie" << endl;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            a[i][j] = 3200;
        a[i][i] = 0;
    }

    for (k = 1; k <= m; k++)
    {
        // cout << "Cost intre " << i << " si " << j << ": ";
        fin >> i >> j;
        fin >> a[i][j];
        a[j][i] = a[i][j];
    }

    cout << "\nMatricea A\n";
    for (i = 1; i < n; i++)
    {
        for (j = 1; j < n; j++)
        {
            cout << a[i][j] << "  ";
        }
        cout << endl;
    }
    cout << "Arborele partial de cost minim" << endl;

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

                if ((s[i] == 1) && (s[j] == 0))

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

    for (i = 2; i <= n; i++)
        cout << t[i] << " " << i << endl;
    cost = 0;

    for (i = 1; i <= n; i++)
        cost += c[i];

    cout << "Cost minim " << cost;

    fin.close();
    return 0;
}
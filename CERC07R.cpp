#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#define MAX 1000010
#define color 2
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, bool> ib;
typedef vector<int> vi;
typedef long long int64;

char num[MAX];

const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    string str, player1, str2, player2;
    map<string, int> type;
    type.insert(mp("Kamen", 3));
    type.insert(mp("Rock", 3));
    type.insert(mp("Pierre", 3));
    type.insert(mp("Stein", 3));
    type.insert(mp("Ko", 3));
    type.insert(mp("Koe", 3));
    type.insert(mp("Sasso", 3));
    type.insert(mp("Roccia", 3));
    type.insert(mp("Guu", 3));
    type.insert(mp("Kamien", 3));
    type.insert(mp("Piedra", 3));

    type.insert(mp("Nuzky", 2));
    type.insert(mp("Scissors", 2));
    type.insert(mp("Ciseaux", 2));
    type.insert(mp("Schere", 2));
    type.insert(mp("Ollo", 2));
    type.insert(mp("Olloo", 2));
    type.insert(mp("Forbice", 2));
    type.insert(mp("Choki", 2));
    type.insert(mp("Nozyce", 2));
    type.insert(mp("Tijera", 2));

    type.insert(mp("Papir", 1));
    type.insert(mp("Paper", 1));
    type.insert(mp("Feuille", 1));
    type.insert(mp("Papier", 1));
    type.insert(mp("Carta", 1));
    type.insert(mp("Rete", 1));
    type.insert(mp("Paa", 1));
    type.insert(mp("Papel", 1));
    int t = 1;
    for (cin >> str; str != "."; cin >> str) {
        cout << "Game #" << t++ << ":\n";
        cin >> player1 >> str2 >> player2;
        pair<int, string> p1 = mp(0, player1), p2 = mp(0, player2);
        for (cin >> str; str != "-" && str != "."; cin >> str) {
            cin >> str2;
            if (type[str] == 3 && type[str2] == 2)
                p1.first++;
            else if (type[str] == 2 && type[str2] == 3)
                p2.first++;
            else if (type[str] == 3 && type[str2] == 1)
                p2.first++;
            else if (type[str] == 1 && type[str2] == 3)
                p1.first++;
            else if (type[str] == 2 && type[str2] == 1)
                p1.first++;
            else if (type[str] == 1 && type[str2] == 2)
                p2.first++;
        }
        cout << p1.second << ": ";
        if (p1.first == 0 || p1.first > 1)
            cout << p1.first << " points\n";
        else
            cout << p1.first << " point\n";
        cout << p2.second << ": ";
        if (p2.first == 0 || p2.first > 1)
            cout << p2.first << " points\n";
        else
            cout << p2.first << " point\n";
        if (p1.first == p2.first)
            cout << "TIED GAME\n\n";
        else if (p1.first > p2.first)
            cout << "WINNER: " << p1.second << "\n\n";
        else if (p1.first < p2.first)
            cout << "WINNER: " << p2.second << "\n\n";
        if (str == ".")
            break;
    }
    return 0;
}

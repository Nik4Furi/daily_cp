#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
#include <iostream>

using namespace std;
using namespace chrono;

//------------- Here I define the variables types
#define int int           // range is ~1e10 (-2147483648 to 2147483647)
#define ll long long      // range is 2e63-1
#define lli long long int // range is 2e63
#define dd double         // range 1.7e+308
#define ld long double    // range 1.7e+308

//---------------- Here I fix some variables/functions
#define MOD 1e9 + 7
#define pb push_back // arrays,stack or others function
#define ppb pop_back // arrays ...
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

//---------------- Here I define some inline/one-line functions
const int MAX_N = 1e5 + 5;
const ll INF = 1e9;
const ld EPS = 1e-9;

//-------------- Here I declare most used functions, i.e. in every line
template <typename T>
void readInput(T &value) { cin >> value; }
template <typename T>
void print(const T &value) { cout << value << endl; }

template <typename T>
void printVector(const std::vector<T> &vec)
{ // printng the vector
    for (const auto &element : vec)
    {
        std::cout << element << " ";
    }
    cout << endl;
}

template <typename K, typename V>
void printMap(const std::map<K, V> &m)
{ // print the map
    for (const auto &pair : m)
    {
        std::cout << pair.ff << ": " << pair.ss << std::endl;
    }
}

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

#ifdef nik4furi
#define debug(x)      \
    cerr << x << " "; \
    cerr << endl;
#else
#define debug(x) ;
#endif

//------------function to traversing the dfs
void dfs(int i, int j, vector<vector<char>> &chessboard, int n, int m, char ch)
{
    // base case
    if (i < 0 || i >= n || j < 0 || j >= m)
        return;

    // if good cell
    if (chessboard[i][j] == '.')
    {
        // put first
        chessboard[i][j] = ch;
        ch = ch == 'W' ? 'B' : 'W';

        // bottom call
        dfs(i + 1, j, chessboard, n, m, ch);

        // left call
        dfs(i, j - 1, chessboard, n, m, ch);

        // right call
        dfs(i, j + 1, chessboard, n, m, ch);

        // up call
        dfs(i - 1, j, chessboard, n, m, ch);
    }
}

void solve()
{
    /* int n;
     cout << "Print i/p " << endl;
     readInput(n);
     cout << n << endl;
     print(n);

     // double number = 3.14;
     std::vector<int> vec = {1, 2, 3};
     std::map<std::string, int> m = {{"one", 1}, {"two", 2}, {"three", 3}};

     // // Printing different types
     // print(number);
     cout << "print vector with " << endl;
     printVector(vec);
     printMap(m); */

    //----------------- START TO CODE FROM HERE
    int n, m;
    cin >> n >> m;

    vector<vector<char>> chessboard(n, vector<char>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> chessboard[i][j];
    }

    // now calling the dfs if cell is good
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (chessboard[i][j] == '.')
                dfs(i, j, chessboard, n, m, 'B');
        }
    }

    // Now print the ans
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << chessboard[i][j];
        cout << endl;
    }
}

int main()
{

#ifdef nik4furi
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    auto start1 = high_resolution_clock::now();
    // int t; readInput(t);
    int t = 1;
    for (int tc = 0; tc < t; tc++)
        solve();
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifdef nik4furi
    cerr << "Time: " << duration.count() / 1000 << endl;
#endif
}

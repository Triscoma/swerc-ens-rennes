#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define sz(x) (int)(x).size()


/** Builtin functions
 * Fonctions utiles pour manipuler les entiers bit à bit
 * Quelques astuces : 
 * floor(log2(x)) = 31 - __builtin_clz(x),  si x > 0
 * v2(x) = __builtin_ctz(x&-x), si x > 0
**/

int x;
__builtin_popcount(x); // nb de bits égaux à 1
__builtin_parity(x); // popcount mod 2
__builtin_clz(x); // numbre de leading zeroes
__builtin_ctz(x); // nombre de trailing zeroes,

ll x;
__builtin_popcountll(x);
__builtin_parityll(x);
__builtin_clzll(x);
__builtin_ctzll(x);

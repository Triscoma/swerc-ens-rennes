#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define sz(x) (int)(x).size()


/** Arithmétique modulaire
**/

ll fast_exp_mod(ll a, ll e, int md) {
	if (e == 0) return 1;
	ll x = fast_exp_mod(a, e/2, md);
	x = (x * x) % md;
	if (e % 2) x = (x * a) % md;
	return x % md;
}

pii bezout(int a, int b) { // renvoie [u, v] tq a*u + b*v = pgcd(a, b)
	if (b == 0) return {1, 0};
	int q = a / b;
	int r = a % b;
	auto [u, v] = bezout(b, r);
	return {v, u - q * v};
}

int inv(int a, int b) { // renvoie x entre 0 et b-1 tq a*x = pgcd(a, b) [mod b]
	int x = bezout(a, b).first;
	return (x%b + b) % b;
}

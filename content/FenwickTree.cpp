#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define sz(x) (int)(x).size()


struct FenwickTree {
	vector<ll> v;
	FenwickTree (int n) : v(n) {}

	// v[i] <- v[i] + x
	void add(int i, ll x) {
		for (int k = i+1; k <= sz(v); k += k&-k) v[k - 1] += x;
	}

	// v[0] + .. + v[i-1]
	ll sum(int i) {
		ll s = 0;
		for (int k = i; k > 0; k -= k&-k) s += v[k - 1];
		return s;
	}
};

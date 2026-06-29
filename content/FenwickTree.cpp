/** Fenwick Tree
 * Dans les commentaires, le vecteur v représente le vecteur abstrait (0-indexed), et non le vecteur réel (1-indexed).
**/
struct FenwickTree {
	vector<ll> v;
	FenwickTree (int n) : v(n+1, 0ll) {}
	// v[i] <- v[i] + x
	void add(int i, ll x) {
		for (int k = i+1; k < sz(v); k += k&-k) v[k] += x;
	}
	// v[0] + .. + v[i-1]
	ll sum(int i) {
		ll s = 0;
		for (int k = i; k > 0; k -= k&-k) s += v[k];
		return s;
	}
};

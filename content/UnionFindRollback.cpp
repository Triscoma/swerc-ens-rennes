/** Union-Find avec Rollback 
 * Complexité : O(log N)
 * Statut : non testé
**/
struct DSU {
	vi e;
	stack<pii> st;
	DSU(int n) : e(n, -1) {}

	int size(int x) { return -e[find(x)]; }
	int time() { return sz(st); }

	int find(int x) { 
		if (e[x] < 0) return x;
		int p = find(e[x]);
		return p;
	}

	bool join(int a, int b) {
		a = find(a); b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		st.push({a, e[a]});
		st.push({b, e[b]});
		e[a] += e[b];
		e[b] = a;
		return true;
	}

	// annule les opérations qui ont eu lieu après le temps t
	void rollback(int t) {
		while (time() > t) {
			auto [a, b] = st.top();
			st.pop();
			e[a] = b;
		}
	}
};

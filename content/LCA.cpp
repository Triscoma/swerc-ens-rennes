/** Lowest Common Ancester
 * Complexité : 
 *   - build en O(N log N)
 *   - query en O(1) 
 * Statut : testé sur CSES
**/
struct LCA {
    int n;
    vi tin, inv;
    vector<vi> t;

  	// par : vecteur des parents directs, par[root] = root
    LCA(const vi& par) : n(sz(par)), tin(n), inv(n) {
        vector<vi> g(n);
        int root;
        for (int i = 0; i < n; i++) {
            if (par[i] == i) root = i;
            else g[par[i]].push_back(i);
		}
        // tin = ordre préfixe, vérifie, en notant A[i] = tin[par[inv[i]]], 
		// tin[lca(x, y)] = min { A[i] | tin[x] < i <= tin[y] }
        int c = 0;
        vi st = {root};
        while (!st.empty()) {
            int u = st.back(); st.pop_back();
            tin[u] = c; inv[c++] = u;
            for (int v : g[u]) st.push_back(v);
        }
		// t[k][i] = min(A[i], ..., A[i + 2^k - 1])
        int LOG = 32 - __builtin_clz(n);
        t.assign(LOG, vi(n));
        for (int v = 0; v < n; v++) t[0][tin[v]] = tin[par[v]];
        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i + (1 << k) <= n; i++) {
                t[k][i] = min(t[k-1][i], t[k-1][i + (1 << (k-1))]);
		  	}
		}
	}

    int get(int x, int y) {
        if (x == y) return x;
        int l = tin[x], r = tin[y];
        if (l > r) swap(l, r);
        int k = 31 - __builtin_clz(r - l); // (r-l)/2 < 2^k <= r-l
        return inv[min(t[k][l+1], t[k][r - (1 << k) + 1])]; // recouvrement
    }
};

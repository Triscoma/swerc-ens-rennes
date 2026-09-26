/** Kosaraju
 * Entrées : g, g_ tableau de liste d'adj de resp graphe et graphe miroir.
 * Sortie : liste des composantes fortement connexes dans l'ordre topologique
 *    (cycles[0] n'a pas de prédécesseur)
 * Complexité : O(V+E)
 * Statut : testé sur CSES
**/
vector<vi> kosaraju(vector<vi>& g, vector<vi>& g_) {
	int n = sz(g);
	vi order;
	vi seen(n, 0);
	function<void(int)> dfs = [&](int u) {
		if (seen[u]) return;
		seen[u] = 1;
		for (int v : g[u]) dfs(v);
		order.push_back(u);
	};
	for (int i = 0; i < n; i++) dfs(i);
	vector<vi> cycles;
	vi cy = {};
	seen = vi(n, 0);
	function<void(int)> dfs_ = [&](int u) {
		if (seen[u]) return;	
		seen[u] = 1 + sz(cycles);
		cy.push_back(u);
		for (int v : g_[u]) dfs_(v);
	};
	while (sz(order)) {
		int i = order.back();
		order.pop_back();
		if (!seen[i]) dfs_(i);
		if (sz(cy)) cycles.push_back(cy);
		cy.clear();
	}
	return cycles;
}

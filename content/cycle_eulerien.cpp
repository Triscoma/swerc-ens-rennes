/** Cycle Eulerien
 * n = nombre de sommets de g, m = nombre d'arrêtes de g, g = graphe, s = sommet de départ
 * g[i] = vecteur de couples {voisin, id_arete}
 * Hypothèse : pour tout i appartenant à la composante connexe de s, g[i] est de taille paire (sinon il n'existe pas de cycle eulérien)
 * Renvoie un cycle eulérien de la composante connexe de s sous forme de vecteur (le premier et le dernier éléments sont égaux)
 * Si g n'est pas connexe, la taille de la sortie est différente de m+1
**/
vi euler_tour(int n, int m, vector<vector<pii>> g, int s) {
	vi tour;
	vector<bool> seen(m);
	function<void(int)> dfs = [&](int u) {
		while (sz(g[u])) {
			auto [v, i] = g[u].back();
			g[u].pop_back();
			if (seen[i]) continue;
			seen[i] = true;
			dfs(v);	
		}
		tour.push_back(u);
	};
	dfs(s);
	return tour;
}

/** Parcours Eulerien
 * n = nombre de sommets de g, m = nombre d'arrêtes de g, g = graphe MIROIR (g lui-même si non-orienté), s = sommet de départ
 * g[i] = vecteur de couples {voisin, id_arete}
 * Hypothèses : 
 *    - Soit pour tout i appartenant à la composante connexe de s, g[i] est de taille paire
 *    - Soit s et exactement 1 autre sommet t de la composante connexe de s ont un degré impair
 *    --> Si g est orienté, chaque sommet doit avoir un degré nul, à l'exception éventuelle de s et t dont les degrés vallent respectivement -1 et 1
 * Dans le premier cas, renvoie un cycle eulérien de la composante connexe de s (le premier et le dernier éléments sont égaux)
 * Dans le second cas, renvoie un chemin eulérien TERMINANT en s
 * Si g n'est pas connexe, la taille de la sortie est différente de m+1
 * /!\ NON TESTE pour les chemins ni pour les graphes orientés
**/
vi euler_walk(int m, vector<vector<pii>> g, int s) {
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

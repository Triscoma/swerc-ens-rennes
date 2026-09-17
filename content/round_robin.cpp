/** Algorithme Round-Robin / Algorithme du tourniquet
 * Etant donnés un entier q, renvoie un ensemble de matchings de cardinal
 * maximal dans le graphe complet à q sommets, tel que toute paire de sommets 
 * apparaisse dans un matching. Le nombre de matchings produits est minimal et
 * vaut :
 * - Si q est pair : q-1 matchings parfaits.
 * - Si q est impair : q matchings, chacun avec un bye (sommet non matché).
 * Chaque paire apparaît exactement une fois.
 *
 * Complexité : O(q^2)
 * Statut : testé sur Kattis
**/
vector<vector<pii>> round_robin(int q) {
    int N = (q&1 ? q+1 : q); // on ajoute un sommet fictif si N est impair
    vi a(N);
	for (int i = 0; i < N; i++) a[i] = i;
    vector<vector<pii>> res;

    while (sz(res) < N-1) {
        vector<pii> cur;
        for (int i = 0; i < N/2; i++) {
            int x = a[i];
            int y = a[N-1 - i];

			      // on ne push pas le sommet fictif (il est match avec le bye)
            if (x < q && y < q) cur.push_back({x, y}); 
        }
        res.push_back(cur);

		    // rotation sur (a[1], ..., a[N-1])
        vi b(N, a[0]);
		    b[1] = a[N-1];
        for (int i = 2; i < N; i++) b[i] = a[i-1];
        a = b;
    }

    return res;
}

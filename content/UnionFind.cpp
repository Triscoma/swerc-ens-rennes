/** Union-Find 
**/
struct UnionFind {
	vi e;
	UnionFind(int n) : e(n, -1) {}

	int size(int x) { return -e[find(x)]; }

	int find(int x) { 
		if (e[x] < 0) return x;
		int p = find(e[x]);
		e[x] = p;
		return p;
	}

	bool join(int a, int b) {
		a = find(a); b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b];
		e[b] = a;
		return true;
	}
};

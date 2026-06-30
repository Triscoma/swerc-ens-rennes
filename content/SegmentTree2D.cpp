/** 2D Segment Tree
 * Requêtes en O(\log^2 n)
 * Adapter les 3 premières lignes à l'utilisation souhaitée
 * Contrairement à la version 1D, f doit être commutative
 * Si f est de la forme f(upper_left, upper_right, lower_left, lower_right) non commutative,
 * on peut utiliser un quad tree, en O(\sqrt n)
**/
struct SegmentTree2D {
	using T = int;
	static constexpr T neutral = 0;
	T f(T a, T b) { return max(a, b); }

	int n, m;
	vector<vector<T>> v;
	SegmentTree2D(int n, int m) : n(n), m(m), v(2*n, vector<T>(2*m, neutral)) {}

	void set_y(int x, int y) {
		while (y >>= 1) v[x][y] = f(v[x][y << 1], v[x][y << 1 | 1]);
	}

	// v[x][y] <- val
	void set(int x, int y, T val) {
		v[x += n][y += m] = val;
		set_y(x, y);
		while (x >>= 1) {
			v[x][y] = f(v[x << 1][y], v[x << 1 | 1][y]);
			set_y(x, y);
		}
	}

	T get_y(int x, int l, int r) {
		l += m; r += m;
		T l_ans = neutral, r_ans = neutral;
		while (l < r) {
			if (l & 1) l_ans = f(l_ans, v[x][l++]);
			if (r & 1) r_ans = f(v[x][--r], r_ans);
			l >>= 1; r >>= 1;
		}
		return f(l_ans, r_ans);
	}

	// f sur [x1,x2) × [y1,y2)
	T get(int x1, int x2, int y1, int y2) {
		x1 += n; x2 += n;
		T l_ans = neutral, r_ans = neutral;
		while (x1 < x2) {
			if (x1 & 1) l_ans = f(l_ans, get_y(x1++, y1, y2));
			if (x2 & 1) r_ans = f(get_y(--x2, y1, y2), r_ans);
			x1 >>= 1; x2 >>= 1;
		}
		return f(l_ans, r_ans);
	}
};

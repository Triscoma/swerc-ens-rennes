/** Segment Tree
 * Adapter les 3 première lignes à l'utilisation souhaitée
**/
struct SegmentTree {
	using T = int;
	static constexpr T neutral = 0;
	T f(T a, T b) { return max(a, b); }

	int n;
	vector<T> v;
	SegmentTree(int n) : n(n), v(2 * n, neutral) {}
	// v[i] <- x
	void set(int i, T x) {
		i += n;
		v[i] = x;
		while (i /= 2) v[i] = f(v[2 * i], v[2 * i + 1]);
	}
	// f(v[l], .., v[r-1])
	T get(int l, int r) {
		l += n; r += n;
		T l_ans = neutral, r_ans = neutral;
		while (l < r) {
			if (l % 2) l_ans = f(l_ans, v[l++]);
			if (r % 2) r_ans = f(v[--r], r_ans);
			l /= 2; r /= 2;
		}
		return f(l_ans, r_ans);
	}
};


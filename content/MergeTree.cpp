/** Merge Sort Tree
**/

struct MergeTree {
	int n; 
  vi tree, pos, len;
	MergeTree(vi& v) : n(sz(v)), tree(n), pos(2*n), len(2*n) {
		tree.reserve(31 * 2e5);
		for (int i = 0; i < n; i++) {
			tree[i] = v[i];
			pos[i + n] = i;
			len[i + n] = 1;
		}
		for (int i = n-1; i >= 1; i--) {
			int l = 2 * i, r = 2 * i + 1;
			pos[i] = sz(tree);
			len[i] = len[l] + len[r];
			auto L = tree.begin() + pos[l], R = tree.begin() + pos[r];
			merge(L, L + len[l], R, R + len[r], back_inserter(tree));
		}
	}
	int query(int l, int r, int a, int b) { // #{i | l <= i < r et a <= v[i] <= b}
		int ans = 0;
		auto f = [&](int i){
			auto begin = tree.begin() + pos[i];
      		auto end = begin + len[i];
			auto it_a = lower_bound(begin, end, a);
			auto it_b = upper_bound(begin, end, b);
			return it_b - it_a;
		};
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l & 1) ans += f(l++);
			if (r & 1) ans += f(--r);
		}
		return ans;
	}
};

/** LAZY SEGMENT TREE
 * intervalles [L, R)
 * si pas besoin de add, retirer la fonction add ainsi que toutes les lignes avec // add
 * f_range doit coincider avec f lorsque R = L+1
 * statut : testé sur CSES
**/
struct LazyTree {
	using T = ll;
	static constexpr T neutral = 0ll;
	static constexpr auto f = [](T a, T b) { return a + b; };
	static constexpr auto f_range = [](int L, int R, T x) { return (R - L) * x; };
	static constexpr T neutradd = 0ll; // add
	static constexpr auto f_add = f; // add
	static constexpr auto f_add_range = f_range; // add
 
	struct Node {
		int l; int r;
		T val, mset = neutral;
		T madd = neutradd; // add
		bool has_set = false;
		Node* left = nullptr; Node* right = nullptr;
		Node(vector<T>& v, int l_, int r_) : l(l_), r(r_) {
			int m = l + (r - l)/2;
			if (m == l) {
				val = v[m];
				return;
			}
			left = new Node(v, l, m); right = new Node(v, m, r);	
			val = f(left->val, right->val);
		}
		void push() {
			if (has_set) {
				left->set(l, r, mset); right->set(l, r, mset);
				has_set = false;
			} else if (madd != neutradd) { // add
				left->add(l, r, madd); right->add(l, r, madd);
				madd = neutradd;
			}
		}
		void set(int L, int R, T k) {
			if (R <= l || r <= L) return;
			if (L <= l && r <= R) {
				has_set = true;
				mset = k;
				madd = neutradd; // add
				val = f_range(l, r, k);
			} else {
				push();
				left->set(L, R, k); right->set(L, R, k);
				val = f(left->val, right->val);
			}
		}
		void add(int L, int R, T x) {
			if (R <= l || r <= L) return;
			if (L <= l && r <= R) {
				if (mset != neutral) mset = f_add(mset, x);
				else madd = f_add(madd, x);
				val = f_add(val, f_add_range(l, r, x));
			} else {
				push();
				left->add(L, R, x); right->add(L, R, x);
				val = f(left->val, right->val);
			}
		}
		T get(int L, int R) {
			if (R <= l || L >= r) return neutral;
			if (L <= l && r <= R) return val;
			push();
			return f(left->get(L, R), right->get(L, R));
		}
	};
	
	Node* root;
	LazyTree(vector<T>& v) { root = new Node(v, 0, sz(v)); }
	void set(int L, int R, T k) { root->set(L, R, k); }
	void add(int L, int R, T x) { root->add(L, R, x); }
	T get(int L, int R) { return root->get(L, R); }
};

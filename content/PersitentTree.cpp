/** PERSISTENT SEGMENT TREE
 * Segment Tree dans lequel l'historique des modifications est accessible
 * Adapter les 3 premières lignes selon les besoins.
 * temps d'exécution estimé pour n = 2e5 : 0.5s 
**/
struct PersistentTree {
	using T = ll;
	static constexpr T neutral = 0ll;
	static constexpr auto f = [](T a, T b) { return a + b; };

	struct Node {
		int l; int r;
		T val;	
		Node* left = nullptr; Node* right = nullptr;
		Node(const Node* other) : Node(*other) {assert(other);}
		Node(int l_, int r_, T val_=neutral) : l(l_), r(r_), val(val_) {}
		Node(vector<T>& v, int l_, int r_) : l(l_), r(r_) {
			if (l == r-1) {
				val = v[l];
				return;
			}
			int m = l + (r - l)/2;
			left = new Node(v, l, m); right = new Node(v, m, r);	
			val = f(left->val, right->val);
		}
		Node* set(int i, T k) {
			if (l == r-1) return new Node(l, r, k);
			Node* node = new Node(this);
			if (i < left->r) node->left = left->set(i, k);
			else node->right = right->set(i, k);
			node->val = f(node->left->val, node->right->val);
			return node;
		}
		T get(int L, int R) {
			if (R <= l || L >= r) return neutral;
			if (L <= l && r <= R) return val;
			return f(left->get(L, R), right->get(L, R));
		}
	};
	
	vector<Node*> hist;
	PersistentTree(vector<T>& v) { hist.push_back(new Node(v, 0, sz(v))); }
	void set(int i, T k, int ver) { hist.push_back(hist[ver]->set(i, k)); }
	T get(int L, int R, int ver) { return hist[ver]->get(L, R); }
};

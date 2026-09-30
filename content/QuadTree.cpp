/** QuadTree
 * Permet de répondre aux 2D-queries en O(\sqrt n)
 * Implémentation persistante permettant d'accéder à l'historique des
 *  modifications
 * N'utiliser que si le 2D segment tree ne permet pas de résoudre le pb
**/
struct QuadTree {
	using T = ll;
	static constexpr T neutral = 0ll;
	static constexpr auto f = [](T a, T b, T c, T d) { return a + b + c + d; };
 
	struct Node {
		pii tl; pii br;
		T val;	
		Node* upper_left = nullptr; Node* upper_right = nullptr; 
		Node* lower_left = nullptr; Node* lower_right = nullptr;
		Node(const Node* other) : Node(*other) {}
		Node(pii tl_, pii br_, T val_=neutral) : tl(tl_), br(br_), val(val_) {}
		Node(vector<vector<T>>& v, pii tl_, pii br_) : tl(tl_), br(br_) {
			if (tl.first >= br.first || tl.second >= br.second) {
				val = neutral;
				return;
			}
			int mi = (tl.first + br.first) / 2;
			int mj = (tl.second + br.second) / 2; 
			if (mi == tl.first && mj == tl.second) {
				val = v[mi][mj];
				return;
			}
			upper_left = new Node(v, tl, {mi, mj}); 
			upper_right = new Node(v, {tl.first, mj}, {mi, br.second});	
			lower_left = new Node(v, {mi, tl.second}, {br.first, mj}); 
			lower_right = new Node(v, {mi, mj}, br);
			val = f(upper_left->val, upper_right->val, 
					lower_left->val, lower_right->val);
		}
		Node* set(pii p, T k) {
			if (tl.first == br.first-1 && tl.second == br.second-1) 
				return new Node(tl, br, k);
			auto [i, j] = p;
			Node* node = new Node(this);
			if (i < upper_left->br.first && j < upper_left->br.second) 
				node->upper_left = upper_left->set(p, k);
			else if (i < upper_left->br.first) 
				node->upper_right = upper_right->set(p, k);
			else if (j < upper_left->br.second) 
				node->lower_left = lower_left->set(p, k);
			else 
				node->lower_right = lower_right->set(p, k);
			node->val = f(node->upper_left->val, node->upper_right->val, 
					node->lower_left->val, node->lower_right->val);
			return node;
		}
		T get(pii TL, pii BR) {
			if (BR.first <= tl.first || BR.second <= tl.second || 
					TL.first >= br.first || TL.second >= br.second) 
				return neutral;
			if (TL.first <= tl.first && TL.second <= tl.second &&
					BR.first >= br.first && BR.second >= br.second) 
				return val;
			return f(upper_left->get(TL, BR), upper_right->get(TL, BR), 
					lower_left->get(TL, BR), lower_right->get(TL, BR));
		}
	};
	
	vector<Node*> hist;
	QuadTree(vector<vector<T>>& v) { 
		hist.push_back(new Node(v, {0, 0}, {sz(v), sz(v[0])})); 
	}
	void set(pii p, T k, int ver) { hist.push_back(hist[ver]->set(p, k)); }
	T get(pii TL, pii BR, int ver) { return hist[ver]->get(TL, BR); }
};

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define sz(x) (int)(x).size()


/** ordered_set<T>
 * set avec des opérations supplémentaires : 
 * t.find_by_order(i) = itérateur vers le iè plus petit élément de t (0-indexed);
 * t.order_of_key(x) = nombre d'éléments str. plus petits que x dans t
 * changer null_type pour avoir une ordered_map à la place
 * prendre T = pii pour avoir un multiset
**/
#include<bits/extc++.h>
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
	  tree_order_statistics_node_update>;

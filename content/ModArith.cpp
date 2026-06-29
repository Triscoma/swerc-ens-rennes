/** Arithmétique modulaire
**/
ll mod_pow(ll a, ll e, int md) {
	if (e == 0) return 1;
	ll x = mod_pow(a, e/2, md);
	x = (x * x) % md;
	if (e % 2) x = (x * a) % md;
	return x % md;
}
// renvoie [u, v] tq a*u + b*v = pgcd(a, b)
pair<ll, ll> bezout(ll a, ll b) {
	if (b == 0) return {1, 0};
	ll q = a / b;
	ll r = a % b;
	auto [u, v] = bezout(b, r);
	return {v, u - q * v};
}
// renvoie x entre 0 et b-1 tq a*x = pgcd(a, b) [mod b]
// Si b est premier, simplement faire mod_pow(a, b-2, b);
ll inv(ll a, ll b) { 
	ll x = bezout(a, b).first;
	return (x%b + b) % b;
}

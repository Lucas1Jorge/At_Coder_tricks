#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef long long int ll;
typedef vector<ll> vll;

#define FOR(i, a, b) for(int i = a; i < b; i++)

ll mod = 1000000007;
ll N = 100000;

ll power(int b, int e) {
	if (e == 0)
		return 1LL;

	ll half = power(b, e / 2);

	if (e % 2 == 0)
		return (half * half) % mod;
	else
		return (((half * half) % mod) * b) % mod;
}

ll inv_mod(ll n) {
	return power(n, mod - 2);
}

ll choose(ll n, ll k, vll &fac, vll &inv_fac) {
	return (((fac[n] * inv_fac[k]) % mod) * inv_fac[n - k]) % mod;
}

void print(vll &A, int s, int e) {
	FOR(i, s, e)
		printf("%lld ", A[i]);
	cout << endl;
}

int main() {
	vll fac(N, 1LL);
	FOR(i, 2, N) {
		fac[i] = (fac[i - 1] * (ll)i) % mod;
	}

	vll inv_fac(N, 1LL);
	inv_fac[N - 1] = inv_mod(fac[N - 1]);
	for (int i = N - 2; i >= 0; i--) {
		inv_fac[i] = (inv_fac[i + 1] * (ll)(i + 1)) % mod;
	}

	// print(fac, 0, 10);
	// print(inv_fac, 0, 10);

	int n = 6;
	FOR(k, 0, 6) {
		printf("%lld ", choose(n, k, fac, inv_fac));
	}
	cout << endl;

	return 0;
}
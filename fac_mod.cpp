#include <iostream>

using namespace std;

typedef vector<int> vi;

#define FOR(i, a, b) for(int i = a; i < b; i++)

int mod = 1000000007;
int max_n = 100000;

int power(int b, int e) {
	if (e == 0)
		return 1;

	int half = power(b, e / 2);

	if (e % 2 == 0)
		return (half * half) % mod;
	else
		return (((half * half) % mod) * b) % mod;
}

int inv_mod(int n) {
	return power(n, mod - 2);
}

int main() {
	vi fac_mod(max_n, 1);
	FOR(i, 2, max_n) {
		fac_mod[i] = (fac_mod[i - 1] * i) % mod;
	}

	vi inv_fac(max_n, 1);
	inv_fac[max_n - 1] = inv_mod(fac_mod[n - 1]);
	for (int i = n - 2; i >= 0; i--) {
		inv_fac[i] = (inv_fac[i + 1] * i) % mod;
	}

	return 0;
}
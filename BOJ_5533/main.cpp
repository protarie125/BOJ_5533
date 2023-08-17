#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;

	auto pts = vvi(n, vi(3));
	for (auto i = 0; i < n; ++i) {
		for (auto&& x : pts[i]) {
			cin >> x;
		}
	}

	auto ans = vi(n, 0);
	for (auto i = 0; i < n; ++i) {
		for (auto t = 0; t < 3; ++t) {
			auto isOk = bool{ true };
			for (auto j = 0; j < n; ++j) {
				if (j == i) {
					continue;
				}

				if (pts[i][t] == pts[j][t]) {
					isOk = false;
					break;
				}
			}

			if (isOk) {
				ans[i] += pts[i][t];
			}
		}
	}

	for (const auto& x : ans) {
		cout << x << '\n';
	}

	return 0;
}
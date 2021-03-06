#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <random>
#include <cmath>
#include <ctime>
#include <functional>
#include <algorithm>
#include <complex>
#include <numeric>
#include <limits>
#include <bitset>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <array>
#include <list>
#include <map>
#include <set>
using namespace std;
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) int((a).size())
#define MP(x, y) make_pair((x),(y))
#define FI first
#define SE second
#define LOWB(x) (x & (-x))
#define UNIQUE(a) sort(ALL(a)), (a).erase(unique(ALL(a)), (a).end())
#define HEIGHT(n) (sizeof(int) * 8 - __builtin_clz(n)) //height of range n segment tree
#define INF 1e9
#define INF_LL 4e18
#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
/*-----------------------------------*/
#define N 100010
string s;
int n, k, sum[N];

bool check(int len) {
  for (int i=0; i+len <= n; i++) {
    int t = (i==0?sum[i+len-1]: sum[i+len-1] - sum[i-1]);
    if (len - t <= k) return true;
    if (t <= k) return true;
  }
  return false;
}

int solve() {
  int l = 1, r = n, best = 1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      best = mid;
      l = mid + 1;
    } else r = mid - 1;
  }
  return best;
}

int main() {
  cin >> n >> k >> s;
  for (int i=0; i<n; i++) sum[i] = (s[i] == 'a');
  for (int i=1; i<n; i++) sum[i] += sum[i-1];
  int ans = solve();
  cout << ans << endl;
  return 0;
}

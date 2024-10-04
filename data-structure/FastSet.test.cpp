#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"
#include "FastSet.hpp"
#include <bits/stdc++.h>
using namespace std;

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int N, Q;
   cin >> N >> Q;
   string S;
   cin >> S;
   FastSet s(N);
   for(int i = 0; i < N; i++) if(S[i] == '1') s.set(i);
   while(Q--) {
      int c, k;
      cin >> c >> k;
      if(c == 0) s.set(k);
      if(c == 1) s.reset(k);
      if(c == 2) cout << (s.a[0][k / FastSet::B] >> (k % FastSet::B) & 1) << '\n';
      if(c == 3) {
         int ans = s.next(k - 1);
         cout << (ans == N ? -1 : ans) << '\n';
      }
      if(c == 4) cout << (int)s.prev(k + 1) << '\n';
   }
}

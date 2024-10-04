---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/FastSet.hpp
    title: data-structure/FastSet.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/predecessor_problem
    links:
    - https://judge.yosupo.jp/problem/predecessor_problem
  bundledCode: "#line 1 \"data-structure/FastSet.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\
    \n#line 2 \"data-structure/FastSet.hpp\"\n#include <bit>\n#include <cstddef>\n\
    #include <cstdint>\n#include <vector>\n\nstruct FastSet {\n    using u64 = std::uint64_t;\n\
    \    using usize = std::size_t;\n    static constexpr u64 B = 64;\n    usize n;\n\
    \    std::vector<std::vector<u64>> a;\n    FastSet(u64 n_) : n(n_) {\n       \
    \ do a.emplace_back(n_ = (n_ + B - 1) / B);\n        while (n_ > 1);\n    }\n\
    \    bool operator[](usize i) const { return a[0][i / B] >> (i % B) & 1; }\n \
    \   void set(usize i) {\n        for (auto& v : a) {\n            v[i / B] |=\
    \ 1ULL << (i % B);\n            i /= B;\n        }\n    }\n    void reset(usize\
    \ i) {\n        for (auto& v : a) {\n            v[i / B] &= ~(1ULL << (i % B));\n\
    \            if (v[i / B]) break;\n            i /= B;\n        }\n    }\n   \
    \ usize next(usize i) {  // i \u3092\u8D85\u3048\u308B\u6700\u2F29\u306E\u8981\
    \u7D20\n        for(usize h = 0; h < a.size(); h++) {\n            i++;\n    \
    \        if (i / B >= a[h].size()) break;\n            u64 d = a[h][i / B] >>\
    \ (i % B);\n            if (d) {\n                i += std::countr_zero(d);\n\
    \                while (h--) i = i * B + std::countr_zero(a[h][i]);\n        \
    \        return i;\n            }\n            i /= B;\n        }\n        return\
    \ n;\n    }\n    usize prev(usize i) {  // i \u3088\u308A\u5C0F\u3055\u3044\u6700\
    \u2F24\u306E\u8981\u7D20\n        for(usize h = 0; i && h < a.size(); h++) {\n\
    \            i--;\n            u64 d = a[h][i / B] << (~i % B);\n            if\
    \ (d) {\n                i -= std::countl_zero(d);\n                while (h--)\
    \ i = i * B + (std::bit_width(a[h][i]) - 1);\n                return i;\n    \
    \        }\n            i /= B;\n        }\n        return -1;\n    }\n};\n#line\
    \ 3 \"data-structure/FastSet.test.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   int N, Q;\n   cin\
    \ >> N >> Q;\n   string S;\n   cin >> S;\n   FastSet s(N);\n   for(int i = 0;\
    \ i < N; i++) if(S[i] == '1') s.set(i);\n   while(Q--) {\n      int c, k;\n  \
    \    cin >> c >> k;\n      if(c == 0) s.set(k);\n      if(c == 1) s.reset(k);\n\
    \      if(c == 2) cout << (s.a[0][k / FastSet::B] >> (k % FastSet::B) & 1) <<\
    \ '\\n';\n      if(c == 3) {\n         int ans = s.next(k - 1);\n         cout\
    \ << (ans == N ? -1 : ans) << '\\n';\n      }\n      if(c == 4) cout << (int)s.prev(k\
    \ + 1) << '\\n';\n   }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\n\
    #include \"FastSet.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\nint\
    \ main() {\n   cin.tie(0)->sync_with_stdio(0);\n   int N, Q;\n   cin >> N >> Q;\n\
    \   string S;\n   cin >> S;\n   FastSet s(N);\n   for(int i = 0; i < N; i++) if(S[i]\
    \ == '1') s.set(i);\n   while(Q--) {\n      int c, k;\n      cin >> c >> k;\n\
    \      if(c == 0) s.set(k);\n      if(c == 1) s.reset(k);\n      if(c == 2) cout\
    \ << (s.a[0][k / FastSet::B] >> (k % FastSet::B) & 1) << '\\n';\n      if(c ==\
    \ 3) {\n         int ans = s.next(k - 1);\n         cout << (ans == N ? -1 : ans)\
    \ << '\\n';\n      }\n      if(c == 4) cout << (int)s.prev(k + 1) << '\\n';\n\
    \   }\n}\n"
  dependsOn:
  - data-structure/FastSet.hpp
  isVerificationFile: true
  path: data-structure/FastSet.test.cpp
  requiredBy: []
  timestamp: '2024-10-04 18:53:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data-structure/FastSet.test.cpp
layout: document
redirect_from:
- /verify/data-structure/FastSet.test.cpp
- /verify/data-structure/FastSet.test.cpp.html
title: data-structure/FastSet.test.cpp
---

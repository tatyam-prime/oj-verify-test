---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data-structure/FastSet.test.cpp
    title: data-structure/FastSet.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/FastSet.hpp\"\n#include <bit>\n#include <cstddef>\n\
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
    \        }\n            i /= B;\n        }\n        return -1;\n    }\n};\n"
  code: "#pragma once\n#include <bit>\n#include <cstddef>\n#include <cstdint>\n#include\
    \ <vector>\n\nstruct FastSet {\n    using u64 = std::uint64_t;\n    using usize\
    \ = std::size_t;\n    static constexpr u64 B = 64;\n    usize n;\n    std::vector<std::vector<u64>>\
    \ a;\n    FastSet(u64 n_) : n(n_) {\n        do a.emplace_back(n_ = (n_ + B -\
    \ 1) / B);\n        while (n_ > 1);\n    }\n    bool operator[](usize i) const\
    \ { return a[0][i / B] >> (i % B) & 1; }\n    void set(usize i) {\n        for\
    \ (auto& v : a) {\n            v[i / B] |= 1ULL << (i % B);\n            i /=\
    \ B;\n        }\n    }\n    void reset(usize i) {\n        for (auto& v : a) {\n\
    \            v[i / B] &= ~(1ULL << (i % B));\n            if (v[i / B]) break;\n\
    \            i /= B;\n        }\n    }\n    usize next(usize i) {  // i \u3092\
    \u8D85\u3048\u308B\u6700\u2F29\u306E\u8981\u7D20\n        for(usize h = 0; h <\
    \ a.size(); h++) {\n            i++;\n            if (i / B >= a[h].size()) break;\n\
    \            u64 d = a[h][i / B] >> (i % B);\n            if (d) {\n         \
    \       i += std::countr_zero(d);\n                while (h--) i = i * B + std::countr_zero(a[h][i]);\n\
    \                return i;\n            }\n            i /= B;\n        }\n  \
    \      return n;\n    }\n    usize prev(usize i) {  // i \u3088\u308A\u5C0F\u3055\
    \u3044\u6700\u2F24\u306E\u8981\u7D20\n        for(usize h = 0; i && h < a.size();\
    \ h++) {\n            i--;\n            u64 d = a[h][i / B] << (~i % B);\n   \
    \         if (d) {\n                i -= std::countl_zero(d);\n              \
    \  while (h--) i = i * B + (std::bit_width(a[h][i]) - 1);\n                return\
    \ i;\n            }\n            i /= B;\n        }\n        return -1;\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/FastSet.hpp
  requiredBy: []
  timestamp: '2024-10-04 18:53:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data-structure/FastSet.test.cpp
documentation_of: data-structure/FastSet.hpp
layout: document
title: "FastSet (64 \u5206\u6728)"
---

- 参考実装：[Gifted Infants](https://yosupo.hatenablog.com/entry/2019/07/02/122433)

## 使い方

整数の set を高速化したい時に使う

- `FastSet(ll n)`：長さ $n$ の bitset を作る
- `void set(ll i)`：`A[i] = true` を行う
- `void reset(ll i)`：`A[i] = false` を行う
- `ll next(ll i)`：$i$ を超える最小の要素を求める
    - std::set における `A.upper_bound(i)` に相当
    - std::bitset における `A._Find_next(i)` に相当
- `ll prev(ll i)`：$i$ より小さい最大の要素を求める
    - std::set における `prev(A.lower_bound(i))` に相当

時間計算量 $O(\log_{\text{word}} n)$ / クエリ  
空間計算量 $(\frac{\text{word}}{\text{word} - 1}\cdot n + O(\log_{\text{word}} n))$ bits　<span style="color:firebrick;font-weight:600;"> ($\boldsymbol{n}$ bits くらいのメモリを使います) </span>

## ベンチマーク

値域 $2^{30}$

| $n = 2^{20}$ 回の 追加 + next クエリ | 所要時間 |
| --- | --- |
| std::set | 467 ms |
| std::bitset | 254 ms |
| FastSet | 56 ms |


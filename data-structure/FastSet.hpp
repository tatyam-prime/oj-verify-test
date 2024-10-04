#pragma once
#include <bit>
#include <cstddef>
#include <cstdint>
#include <vector>

struct FastSet {
    using u64 = std::uint64_t;
    using usize = std::size_t;
    static constexpr u64 B = 64;
    usize n;
    std::vector<std::vector<u64>> a;
    FastSet(u64 n_) : n(n_) {
        do a.emplace_back(n_ = (n_ + B - 1) / B);
        while (n_ > 1);
    }
    bool operator[](usize i) const { return a[0][i / B] >> (i % B) & 1; }
    void set(usize i) {
        for (auto& v : a) {
            v[i / B] |= 1ULL << (i % B);
            i /= B;
        }
    }
    void reset(usize i) {
        for (auto& v : a) {
            v[i / B] &= ~(1ULL << (i % B));
            if (v[i / B]) break;
            i /= B;
        }
    }
    usize next(usize i) {  // i を超える最⼩の要素
        for(usize h = 0; h < a.size(); h++) {
            i++;
            if (i / B >= a[h].size()) break;
            u64 d = a[h][i / B] >> (i % B);
            if (d) {
                i += std::countr_zero(d);
                while (h--) i = i * B + std::countr_zero(a[h][i]);
                return i;
            }
            i /= B;
        }
        return n;
    }
    usize prev(usize i) {  // i より小さい最⼤の要素
        for(usize h = 0; i && h < a.size(); h++) {
            i--;
            u64 d = a[h][i / B] << (~i % B);
            if (d) {
                i -= std::countl_zero(d);
                while (h--) i = i * B + (std::bit_width(a[h][i]) - 1);
                return i;
            }
            i /= B;
        }
        return -1;
    }
};

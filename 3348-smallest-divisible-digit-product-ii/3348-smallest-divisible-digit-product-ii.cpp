class Solution {
    struct S { int a, b, c, d; };
    int f[50][35];                                  // мин. цифр для 2^a * 3^b

    void buildF() {
        for (int a = 0; a < 50; ++a)
            for (int b = 0; b < 35; ++b) {
                int best = 1e9;
                for (int y = 0; y <= 50; ++y) {     // y - число шестёрок
                    int ra = max(0, a - y), rb = max(0, b - y);
                    best = min(best, y + (ra + 2) / 3 + (rb + 1) / 2);
                }
                f[a][b] = best;
            }
    }

    static S applyDigit(S s, int dg) {
        switch (dg) {
            case 2: s.a = max(0, s.a - 1); break;
            case 3: s.b = max(0, s.b - 1); break;
            case 4: s.a = max(0, s.a - 2); break;
            case 5: s.c = max(0, s.c - 1); break;
            case 6: s.a = max(0, s.a - 1); s.b = max(0, s.b - 1); break;
            case 7: s.d = max(0, s.d - 1); break;
            case 8: s.a = max(0, s.a - 3); break;
            case 9: s.b = max(0, s.b - 2); break;
        }
        return s;
    }

    static bool done(const S& s) { return !s.a && !s.b && !s.c && !s.d; }
    int minCnt(const S& s) const { return s.c + s.d + f[s.a][s.b]; }

    // лексикографически минимальная строка длины len с нужным произведением
    string build(S s, int len) {
        string res(len, '1');
        for (int i = 0; i < len; ++i) {
            if (done(s)) break;
            for (int dg = 1; dg <= 9; ++dg) {
                S ns = applyDigit(s, dg);
                if (minCnt(ns) <= len - 1 - i) { res[i] = char('0' + dg); s = ns; break; }
            }
        }
        return res;
    }

public:
    string smallestNumber(string num, long long t) {
        buildF();

        S full{0, 0, 0, 0};
        long long r = t;
        while (r % 2 == 0) { r /= 2; ++full.a; }
        while (r % 3 == 0) { r /= 3; ++full.b; }
        while (r % 5 == 0) { r /= 5; ++full.c; }
        while (r % 7 == 0) { r /= 7; ++full.d; }
        if (r != 1) return "-1";                    // есть простой делитель > 7

        const int n = (int)num.size();

        // 1. подходит ли само num
        if (num.find('0') == string::npos) {
            S s = full;
            for (char ch : num) s = applyDigit(s, ch - '0');
            if (done(s)) return num;
        }

        // префиксные состояния (до первого нуля)
        vector<S> pre(n + 1);
        pre[0] = full;
        int z = n;                                  // позиция первого нуля
        for (int i = 0; i < n; ++i) {
            int dg = num[i] - '0';
            if (dg == 0) { z = i; break; }
            pre[i + 1] = applyDigit(pre[i], dg);
        }

        // 2. увеличиваем цифру на максимально правой позиции
        for (int i = min(n - 1, z); i >= 0; --i) {
            for (int dg = num[i] - '0' + 1; dg <= 9; ++dg) {
                S s = applyDigit(pre[i], dg);
                int rest = n - 1 - i;
                if (minCnt(s) <= rest) {
                    string res = num.substr(0, i);
                    res += char('0' + dg);
                    res += build(s, rest);
                    return res;
                }
            }
        }

        // 3. длина увеличивается
        return build(full, max(n + 1, minCnt(full)));
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
/**
 *  @brief   Calculating Chromatic Index 
 *  @author  Donald Dong (@donaldong)
 */

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

typedef unsigned int uint;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#define hmap unordered_map
#define hset unordered_set
#define pq priority_queue
#define pb push_back
#define mp make_pair
#define putchar putchar_unlocked
#define rep(i, s, e) for (size_t i = s, fe__ = e; i < fe__; ++i)

inline void scan(int&);
inline void scan(ll&);
inline void print(uint);
inline void print(ull);
inline void print(string&);

struct node;

struct edge {
    int col = -1;
    int c;
    node *src, *dest;
    edge() {}
    edge(node* src, node* dest) : src(src), dest(dest) {}
};

struct node {
    vector<edge*> E;
    int i;
};

int X_;  // chromatic index

bool dfs(edge *e) {
    vector<bool> C(X_, false);
    for (auto n : e->src->E) {
        if (n->col != -1) C[n->col] = true;
    }
    for (auto n : e->dest->E) {
        if (n->col != -1) C[n->col] = true;
    }
    rep(i, 0, C.size()) {
        if (C[i]) continue;
        e->col = i;
        e->c = i;
        bool f = true;
        for (auto n : e->src->E) {
            if (n->col != -1) continue;
            if (!dfs(n)) {
                f = false;
                break;
            }
        }
        for (auto n : e->dest->E) {
            if (n->col != -1) continue;
            if (!dfs(n)) {
                f = false;
                break;
            }
        }
        if (f) return true;
    }
    e->col = -1;
    return false;
}

bool colorable(vector<edge*> &E, int x) {
    X_ = x;
    for (auto &e : E) e->col = -1;
    return dfs(E[0]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<node> N(n);
    vector<edge*> E;
    vector<vector<bool>> G(n, vector<bool>(n, false));
    int max_degree = 0;
    cin.ignore();
    rep(i, 0, n) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int j;
        int d = 0;
        while (ss >> j) {
            if (!G[i][j] && !G[j][i]) {
                G[i][j] = G[j][i] = true;
                E.pb(new edge(&N[i], &N[j]));
                N[i].E.pb(E.back());
                N[j].E.pb(E.back());
            }
            ++d;
        }
        max_degree = max(max_degree, d);
        N[i].i = i;
    }
    int c = max_degree;
    if (!colorable(E, c)) {
        colorable(E, ++c);
    }
    cout << c << endl;
    cerr << "d:" << max_degree << endl;
    for (auto &e : E) {
        cerr << e->src->i << " -> " << e->dest->i << ": " << e->c << endl;
    }
    return 0;
}

inline void scan(int &number) {
    bool negative = false;
    int c;
    number = 0;
    c = getchar();
    if (c=='-') {
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar()) number = number *10 + c - 48;
    if (negative) number *= -1;
}

inline void scan(ll &number) {
    bool negative = false;
    int c;
    number = 0;
    c = getchar();
    if (c=='-') {
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar()) number = number *10 + c - 48;
    if (negative) number *= -1;
}

inline void print(uint n) {
    if (n == 0) {
        putchar('0');
        return;
    }
    char buf[11];
    int i = 10;
    while (n) {
        buf[i--] = n % 10 + '0';
        n /= 10;
    }
    while (i < 10) putchar(buf[++i]);
}

inline void print(ull n) {
    if (n == 0) {
        putchar('0');
        return;
    }
    char buf[20];
    int i = 19;
    while (n) {
        buf[i--] = n % 10 + '0';
        n /= 10;
    }
    while (i < 19) putchar(buf[++i]);
}

inline void print(string &s) {
    rep(i, 0, s.length()) putchar(s[i]);
}

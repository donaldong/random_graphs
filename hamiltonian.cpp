/**
 *  @brief   Detecting Hamiltonian Cycle/Path
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

struct node {
    int p = -1;
    bool f;
    int i;
    vector<node*> neigh;
};

vector<node> N;

bool path(node *n, int count) {
    if (n->f) return false;
    n->f = true;
    if (count == N.size()) return true;
    for (auto next : n->neigh) {
        ++count;
        if (!next->f && path(next, count)) {
            next->p = n->i;
            return true;
        }
        --count;
    }
    n->f = false;
    return false;
}

bool path() {
    rep(i, 0, N.size()) {
        rep(j, 0, N.size()) {
            N[j].f = false;
            N[j].p = -1;
        }
        if (path(&N[i], 1)) return true;
    }
    return false;
}

int S;

bool cycle(node *n, int count) {
    if (n->f) return false;
    n->f = true;
    if (count == N.size()) {
        for (auto next : n->neigh) {
            if (next->i == S) return true;
        }
        return false;
    }
    for (auto next : n->neigh) {
        ++count;
        if (!next->f && cycle(next, count)) {
            next->p = n->i;
            return true;
        }
        --count;
    }
    n->f = false;
    return false;
}

bool cycle() {
    rep(i, 0, N.size()) {
        rep(j, 0, N.size()) {
            N[j].f = false;
            N[j].p = -1;
        }
        S = i;
        if (cycle(&N[i], 1)) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    N = vector<node>(n);
    cin.ignore();
    rep(i, 0, n) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int j;
        int d = 0;
        while (ss >> j) {
            N[i].neigh.pb(&N[j]);
        }
        N[i].i = i;
    }
    cout << "Path: " << endl;
    if (path()) {
        rep(i, 0, n) {
            cout << N[i].p << " -> " << i << endl;  
        }
    }
    cout << endl;
    cout << "Cycle: " << endl;
    if (cycle()) {
        rep(i, 0, n) {
            cout << N[i].p << " -> " << i << endl;  
        }
    }
    cout << endl;
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

// https : //codingcompetitions.withgoogle.com/kickstart/round/000000000043585c/000000000085a152#problem

#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
using ll = long long;
#define int ll
#define ldbl long double
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define fr first
#define sc second
#define cu continue
#define br break
#define vi vector<int>
#define vb vector<bool>
#define nl cout << "\n"
#define pq priority_queue<int>
#define pii pair<int, int>
#define ppc __builtin_popcount
#define tz __builtin_ctz
#define lz __builtin_clz
#define rep(i, a, b) for (int i = a; i < b; i++)
#define read(x) \
    int x;      \
    cin >> x
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
void google(int t)
{
    cout << "Case #" << t << ": ";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    // t=1;
    int g = 1;
    while (t--)
    {
        google(g++);
        string s;
        cin >> s;
        int n = sz(s);
        int c[26] = {};
        bool ok = 0;
        for (auto i : s)
        {
            c[i - 'a']++;
            if (n < 2 * c[i - 'a'])
            {
                cout << "IMPOSSIBLE";
                nl;
                ok = 1;
                br;
            }
        }
        if (ok)
        {
            cu;
        }
        vector<pair<char, int>> m;
        rep(i, 0, n)
        {
            m.pb({s[i], i});
        }
        sort(all(m));
        string ans(n, 'a');
        rep(i, 0, n)
        {
            ans[m[(i + n / 2) % n].sc] = m[i].fr;
        }
        cout << ans;
        nl;
    }
}

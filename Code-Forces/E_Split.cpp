#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// handy macros
#define all(x) x.begin(), x.end()
#define vecin(name, len)  \
    vector<ll> name(len); \
    for (auto &_ : name)  \
        cin >> _;
#define vecout(v)         \
    for (auto _ : v)      \
        cout << _ << " "; \
    cout << endl;

// ---------------- PREFIX & SUFFIX UTILITIES ----------------
// Build prefix sum array
template <class T>
vector<T> buildPrefixSum(const vector<T> &v)
{
    int n = v.size();
    vector<T> pref(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        pref[i + 1] = pref[i] + v[i];
    }
    return pref;
}

// Build suffix sum array
template <class T>
vector<T> buildSuffixSum(const vector<T> &v)
{
    int n = v.size();
    vector<T> suf(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        suf[i] = suf[i + 1] + v[i];
    }
    return suf;
}

// Build prefix max array
template <class T>
vector<T> buildPrefixMax(const vector<T> &v)
{
    int n = v.size();
    vector<T> prefMax(n);
    prefMax[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        prefMax[i] = max(prefMax[i - 1], v[i]);
    }
    return prefMax;
}

// Build suffix max array
template <class T>
vector<T> buildSuffixMax(const vector<T> &v)
{
    int n = v.size();
    vector<T> sufMax(n);
    sufMax[n - 1] = v[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        sufMax[i] = max(sufMax[i + 1], v[i]);
    }
    return sufMax;
}

// ---------------- SOLVER ----------------
void solve()
{
    ll n, k;
    cin >> n >> k;
    vecin(v, n);
    vector<ll> cnt(n + 1), ct(n + 1);
    for (int i = 0; i < n; i++)
    {
        cnt[v[i]]++;
    }

    for (int i = 0; i <= n; i++)
    {
        if (cnt[i] % k)
            return void(cout << 0 << endl);
        else
            cnt[i] /= k;
    }

    ll res = 0;
    for (int l = 0, r = 0; l <= r and r < n; r++)
    {
        ct[v[r]]++;
        while (ct[v[r]] > cnt[v[r]])
        {
            ct[v[l]]--;
            l++;
        }

        res += (r - l + 1);
    }
    cout << res << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}
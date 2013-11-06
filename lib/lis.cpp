// Alt1 O(n2)
int lis[MAX], lis_id[MAX], a[MAX], p[MAX];

int len = 0, lis_end = 0;
for (int i = 0; i < n; ++i) {
    int pos = lower_bound(lis, lis + len, a[i]) - lis;
    lis[pos] = a[i];
    lis_id[pos] = i;
    p[i] = pos ? lis_id[pos - 1] : -1;
    if (pos + 1 >= len) {
        len = pos + 1;
        lis_end = i;
    }
}

// Alt2 O(n log n)
vi lis(vi a) { // Return lis array
    int L[MAX];

    vi dp(a.size());

    int lis = 0;
    for (int i = 0; i < a.size(); ++i) {
        // LIS ending at a[i] is at length pos + 1
        int pos = lower_bound(L, L + lis, a[i]) - L;
        L[pos] = a[i];
        dp[i] = pos + 1;

        if (pos + 1 > lis) {
            lis = pos + 1;
        }
    }

    return dp;
}


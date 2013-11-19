vi lis(vi a) { // O(n log k)
    int L[MAX];
    vi dp(a.size());
    int lis = 0;
    for (int i = 0; i < a.size(); ++i) {
        // LIS ending at a[i] is at length pos + 1
        int pos = lower_bound(L, L + lis, a[i]) - L;
        L[pos] = a[i];
        dp[i] = pos + 1;

        if (pos + 1 > lis) lis = pos + 1;
    }
    return dp; // Return lis array
}

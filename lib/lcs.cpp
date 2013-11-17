vector<vi> dp;
int lcs(string A, string B) { // turn edit distance into lcs
    dp.assign((int)A.size() + 1, vi()); // dynamic dp matrix
    for (int i = 0; i <= A.size(); ++i)
        dp[i].assign((int)B.size() + 1, 0); // all edge cases 0

    for (int i = 1; i <= A.size(); ++i)
        for (int j = 1; j <= B.size(); ++j) {
            // Match 1, Mismatch -INF
            dp[i][j] = dp[i - 1][j - 1] + (A[i - 1] == B[j - 1] ? 1 : -INF);
            dp[i][j] = max(dp[i][j], dp[i - 1][j]); // delete cost 0
            dp[i][j] = max(dp[i][j], dp[i][j - 1]); // insert cost 0
        }

    return dp[A.size()][B.size()]; // max alignment score
}

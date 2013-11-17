vector<vi> dp;
int edit_distance(string A, string B) { // align A with B
    dp.assign((int)A.size() + 1, vi()); // dynamic dp matrix
    for (int i = 0; i <= A.size(); ++i)
        dp[i].assign((int)B.size() + 1, 0);

    for (int i = 1; i <= A.size(); ++i)
        dp[i][0] = i * -1; // delete substring A[1..i], score -1
    for (int i = 1; i <= B.size(); ++i)
        dp[0][i] = i * -1; // insert space in B[1..i], score -1

    for (int i = 1; i <= A.size(); ++i)
        for (int j = 1; j <= B.size(); ++j) {
            // Match +2, Mismatch -1
            dp[i][j] = dp[i - 1][j - 1] + (A[i - 1] == B[j - 1] ? 2 : -1);
            dp[i][j] = max(dp[i][j], dp[i - 1][j] - 1); // delete
            dp[i][j] = max(dp[i][j], dp[i][j - 1] - 1); // insert
        }

    return dp[A.size()][B.size()]; // max alignment score
}


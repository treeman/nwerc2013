vector<vi> AdjList; // initialize
vi match, vis;

int aug(int l) { // return 1 if augmenting path is found, 0 otherwise
    if (vis[l]) return 0;
    vis[l] = 1;
    for (int j = 0; j < (int)AdjList[l].size(); ++j) {
        int r = AdjList[l][j];
        if (match[r] == -1 || aug(match[r])) {
            match[r] = l;
            return 1;
        }
    }
    return 0;
}

// in main
int MCBM = 0; // result
match.assign(V, -1);
for (int l = 0; l < n; ++l) {
    vis.assign(n, 0);
    MCBM += aug(l);
}

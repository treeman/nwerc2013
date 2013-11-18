bool is_bipartite(int s) {
    qi q; q.push(s);
    vi color(n, INF); color[s] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int j = 0; j < (int)adjs[u].size(); ++j) {
            ii v = adjs[u][j];
            if (color[v.first] == INF) {
                color[v.first] = 1 - color[u];
                q.push(v.first);
            }
            else if (color[v.first] == color[u]) {
                return false;
            }
        }
    }
    return true;
}

int bellman_ford(int s, int t) { // O(VE) when using adj list
    vi dist(V, INF); dist[s] = 0;
    for (int i = 0; i < V - 1; ++i) // relax all edges V-1 times
        for (int u = 0; u < V; ++u)
            for (int j = 0; j< (int)AdjList[u].size(); ++j) {
                ii v = AdjList[u][j]; // record SP spanning here if needed
                dist[v.first] = min(dist[v.first], dist[u] + v.second);
            }

    return dist[t];
}

// check if there exists a negative cycle
bool hasNegativeCycle = false;
for (int u = 0; u < V; ++u)
    for (int j = 0; j< (int)AdjList[u].size(); ++j) {
        ii v = AdjList[u][j];
        if (dist[v.first] > dist[u] + v.second) // if still possible
            hasNegativeCycle = true;            // then neg cycle exists
    }

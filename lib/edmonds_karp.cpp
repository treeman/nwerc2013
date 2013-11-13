// setup res, s, t, AdjList as global variables
int res[MAXN][MAXN], mf, f, s, t;
vi p;
vector<vi> AdjList; // Don't forget backward edges!

void augment(int v, int minEdge) { // traverse BFS spanning tree from s to t
    if (v == s) { f = minEdge; return; } // record minEdge in a global variable f
    else if (p[v] != -1) {
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f; res[v][p[v]] += f;
    }
}

int edmond_karp() {
    mf = 0;
    while (1) { // run bfs
        f = 0;
        bitset<MAXN> vis; vis[s] = true; // bitset is faster
        queue<int> q; q.push(s);
        p.assign(MAXN, -1); // record the BFS spanning tree, from s to t
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (u == t) break; // stop bfs if we reach t
            for (int j = 0; j < (int)AdjList[u].size(); ++j) { // faster with AdjList
                int v = AdjList[u][j];
                if (res[u][v] > 0 && !vis[v])
                    vis[v] = true, q.push(v), p[v] = u;
            }
        }
        augment(t, INF);
        if (f == 0) break;      // we cannot send any more flow, terminate
        mf += f;                // we can still send a flow, increase the max flow!
    }
    return mf;
}



vi ts; // Result in reverse order

void topo(int u) {
    seen[u] = 1; // Init to false
    for (int i = 0; i < (int)adj_list[u].size(); ++i) {
        ii v = adj_list[u][i];
        if (!seen[v.first])
            topo(v.first);
    }
    ts.push_back(u);
}

// use
ts.clear();
// init seen to false
for (int i = 0; i < n; ++i)
    if (!seen[i]) topo(i);

reverse(ts.begin(), ts.end()); // Or traverse in reverse...


// Weight of euler tour in connected graph.
// Need to fill d[][] with min cost between any two nodes. Do floyd warshall before.
int memo[1 << MAX]; // dp bitmask memo structure

// Min cost of increasing by one the degree of set of the given odd vertices, to make them even.
int min_cost(int s) {
    if (s == 0) return 0;
    if (memo[s] != 0) return memo[s];

    int best = -1;

    int x = 0; // Choose our first node to switch as the first node with odd values we can find.
    while (((s >> x) & 1) == 0) ++x; // x = number of trailing zeros

    // Try to combine with all other odd value nodes.
    for (int y = x + 1; y < n; ++y) {
        if ((s >> y) & 1 == 0) continue;

        int comb = s ^ (1 << x) ^ (1 << y); // Switch off the selected nodes.

        // Cost will be to combine these two nodes + combining the rest.
        int cost = d[x][y] + min_cost(comb);

        if (best == -1 || cost < best)
            best = cost;
    }

    return memo[s] = best;
}


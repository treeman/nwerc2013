list<int> cyc; // list for fast insertion in middle

void EulerTour(list<int>::iterator i, int u) {
    for (int j = 0; j < (int)AdjList[u].size(); ++j) {
        ii v = AdjList[u][j];
        if (v.second) {
            v.second = 0; // mark as to be removed
            for (int k = 0; k < (int)AdjList[v.first].size(); ++k) {
                ii uu = AdjList[v.first][k]; // remove bi-directional
                if (uu.first == u && uu.second) {
                    uu.second = 0;
                    break;
                }
            }
            EulerTour(cyc.insert(i, u), v.first);
        }
    }
}

// inside main
cyc.clear();
EulerTour(cyc.begin(), A); // cyc contains euler tour starting at A
for (list<int>::iterator it = cyc.begin(); it != cyc.end(); ++it)
    printf("%d\n", *it); // the Euler tour


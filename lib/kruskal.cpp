// use union find class
int kruskal_mst(vector<pair<int, ii> > &EdgeList, int V) {
    int mst_cost = 0;
    UnionFind UF(V);
    for (int i = 0; i < EdgeList.size(); ++i) {
        pair<int, ii> front = EdgeList[i];
        if (!UF.isSameSet(front.second.first, front.second.second)) {
            mst_cost += front.first;
            UF.unionSet(front.second.first, front.second.second);
        }
    }

    return mst_cost;
}


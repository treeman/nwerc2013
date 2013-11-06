class UnionFind { // rank ordered with path compression
public:
    UnionFind(int n) {
        rank.assign(n, 0);
        p.assign(n, 0);
        set_size.assign(n, 1);
        num_sets = n;
        for (int i = 0; i < n; ++i)
            p[i] = i;
    }

    int find_set(int i) { return (p[i] == i) ? i : (p[i] = find_set(p[i])); }
    bool is_same_set(int i, int j) { return find_set(i) == find_set(j); }
    void union_set(int i, int j) {
        if (!is_same_set(i, j)) {
            --num_sets;
            int x = find_set(i), y = find_set(j);
            if (rank[x] > rank[y]) {
                p[y] = x;
                set_size[x] += set_size[y];
            }
            else {
                p[x] = y;
                set_size[y] += set_size[x];
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }
    int num_disjoint_sets() { return num_sets; }
    int size_of_set(int i) { return set_size[find_set(i)]; }
private:
    vi rank, p, set_size;
    int num_sets;
};


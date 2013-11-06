
// Max range query. Change >= to <= for min.
class SegmentTree {
    vi st, a;

    int n;
    int left(int p) { return p << 1; } // Same as binary heap
    int right(int p) { return (p << 1) + 1; }

    // O(n log n)
    void build(int p, int l, int r) {
        if (l == r)
            st[p] = l;
        else {
            build(left(p), l, (l + r) / 2);
            build(right(p), (l + r) / 2 + 1, r);
            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = (a[p1] >= a[p2]) ? p1 : p2; // Build max
        }
    }

    // O(log n)
    int rmq(int p, int l, int r, int i, int j) {
        if (i > r || j < l) return -1; // outside of range
        if (l >= i && r <= j) return st[p]; // inside range

        int p1 = rmq(left(p), l, (l + r) / 2, i, j);
        int p2 = rmq(right(p), (l + r) / 2 + 1, r, i, j);

        if (p1 == -1) return p2;
        if (p2 == -1) return p1;
        return (a[p1] >= a[p2]) ? p1 : p2; // Return max inside
    }

    // Support for dynamic updating. O(log n)
    int update_point(int p, int l, int r, int idx, int new_value) {
        int i = idx, j = idx;
        if (i > r || j < l)
            return st[p];

        if (l == i && r == j) {
            a[i] = new_value;
            return st[p] = l;
        }

        int p1, p2;
        p1 = update_point(left(p), l, (l + r) / 2, idx, new_value);
        p2 = update_point(right(p), (l + r) / 2, r, idx, new_value);

        // Max query
        return st[p] = (a[p1] >= a[p2]) ? p1 : p2;
    }
public:
    SegmentTree(const vi &_a) {
        a = _a; n = (int) a.size(); // Copy for local use
        st.assign(4 * n, 0); // Large enough of zeroes
        build(1, 0, n - 1);
    }

    // Return index of max O(log n)
    int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }

    // Update index to a new value.
    int update_point(int idx, int new_value) {
        return update_point(1, 0, n - 1, idx, new_value);
    }
};



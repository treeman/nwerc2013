// Ideal to answer dynamic Range Sum Queries
#define LSOne(S) (S & (-S))
struct FenwickTree {
  vi ft;
  FenwickTree() {}
  // initialization: n + 1 zeroes, ignore index 0
  FenwickTree(int n) { ft.assign(n + 1, 0); }

  int rsq(int b) { // returns RSQ(1, b), O(log n)
    int sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
    return sum;
  }
  int rsq(int a, int b) { // returns RSQ(a, b), O(log n)
    return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
  }
  // adjusts value of the k-th element by v
  void adjust(int k, int v) { // O(log n)
    for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v;
  }
};

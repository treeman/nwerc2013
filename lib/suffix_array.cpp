// Suffix Array is a simpler version of Suffix Tree.
// It is slower to construct, O(n log n) vs O(n)
// but it's a lot simpler to program.

// ex. find all Longest Common Substrings of a and b, O(n log n)
string T = a + "$" + b + "#"; // Chars lower, combine input strings
n = T.size(); m = b.size(); // for ease of programming
constructSA(T); // Construct Suffix Array
computeLCP(T); // LCS depends on LCP, so must do this

set<string> res = allLCS(T); // Can also use LCS()
if (res.empty()) printf("No common sequence.\n");
for (set<string>::iterator i = res.begin(); i != res.end(); ++i) {
    printf("%s\n", i->c_str());
}

// ex. find Longest Repeated Substring (min 2 times), O(n log n)
T += "$"; // input string T, append '$'
n = T.size(); // for ease of programming
constructSA(T); // Construct Suffix Array
computeLCP(T); // LRS depends on LCP

pair<string, int> ans = LRS(T); // LRS string and #repetitions
if (ans.first.size()) printf("%s %d\n", ans.first.c_str(), ans.second);
else printf("No repetitions found!\n");

// impl
const int MAXN = 100010; // ok up to ~100k
int RA[MAXN], tmpRA[MAXN]; // rank array + tmp
int SA[MAXN], tmpSA[MAXN]; // suffix array + tmp
int c[MAXN]; // freq table for counting sort
int n, m; // globals for T and P
int Phi[MAXN]; // for computing longest common prefix
int PLCP[MAXN];
int LCP[MAXN]; // LCP[i] stores the LCP between previous suffix T + SA[i-1]
                                              // and current suffix T + SA[i]

void countingSort(int k, int n) { // sort RA, res in SA
    int sum, maxi = max(300, n); // up to 255 ASCII chars of length n
    memset(c, 0, sizeof c);
    for (int i = 0; i < n; ++i) // count freq of each integer rank
        c[i + k < n ? RA[i + k] : 0]++;
    for (int i = sum = 0; i < maxi; ++i) {
        int t = c[i]; c[i] = sum; sum += t;
    }
    for (int i = 0; i < n; ++i) // shuffle suffix array if necessary
        tmpSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
    for (int i = 0; i < n; ++i) // update suffix array
        SA[i] = tmpSA[i];
}

void constructSA(string &T) { // Construct Suffix Array in O(n log n)
    int n = T.size();
    for (int i = 0; i < n; ++i) RA[i] = T[i];
    for (int i = 0; i < n; ++i) SA[i] = i;
    for (int k = 1; k < n; k <<= 1) { // repeat sort log n times
        countingSort(k, n); // radix sort
        countingSort(0, n); // stable sort on first item
        int r = 0; tmpRA[SA[0]] = 0; // re-rank from rank r = 0
        for (int i = 1; i < n; ++i) {
            // if same pair => r otherwise increase rank
            if (RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + k] == RA[SA[i - 1] + k])
                tmpRA[SA[i]] = r;
            else
                tmpRA[SA[i]] = ++r;
        }
        for (int i = 0; i < n; ++i) // update rank array
            RA[i] = tmpRA[i];
        if (RA[SA[n - 1]] == n - 1) break; // optimization
    }
}

void computeLCP(string &T) { // Longest Common Prefix, O(n)
    Phi[SA[0]] = -1;
    for (int i = 1; i < n; ++i)
        Phi[SA[i]] = SA[i - 1];
    for (int i = 0; i < n; ++i) {
        int L = 0;
        if (Phi[i] == -1) { PLCP[i] = 0; continue; }
        while (T[i + L] == T[Phi[i] + L]) ++L;
        PLCP[i] = L;
        L = max(L - 1, 0);
    }
    for (int i = 0; i < n; ++i)
        LCP[i] = PLCP[SA[i]];
}

int owner(int idx) { return (idx < n - m - 1) ? 1 : 2; }

// Longest Common Substring in O(n)
ii LCS() { // return <LCS length, index>, where SA[index] gives index in T
    int idx = 0, maxLCP = -1;
    for (int i = 1; i < n; ++i)
        if (owner(SA[i]) != owner(SA[i - 1]) && LCP[i] > maxLCP)
            maxLCP = LCP[i], idx = i;
    return ii(maxLCP, idx);
}

set<string> allLCS(string &T) { // return all unique longest substrings O(n log n)
    int maxLCP = -1;
    set<string> res;
    for (int i = 0; i < n; ++i) {
        if (owner(SA[i]) == owner(SA[i - 1])) continue;
        if (LCP[i] == 0) continue;
        if (LCP[i] > maxLCP) res.clear();
        if (LCP[i] >= maxLCP) {
            maxLCP = LCP[i];
            res.insert(T.substr(SA[i], maxLCP));
        }
    }
    return res;
}

// Longest Repeated Substring (substring 2 times or more)
ii LRS() { // returns <LRS length, index>, where SA[index] gives index in T
    int idx = 0, maxLCP = -1;
    for (int i = 1; i < n; i++)
        if (LCP[i] > maxLCP)
          maxLCP = LCP[i], idx = i;
    return ii(maxLCP, idx);
}

pair<string, int> LRS(string &T) { // return LRS and #repetitions
    int maxLCP = -1, rep = 0;
    string s;
    for (int i = 1; i < n; i++) {
        string curr = T.substr(SA[i], LCP[i]);
        if (LCP[i] > maxLCP) {
            maxLCP = LCP[i]; rep = 2;
            s = curr;
        }
        else if (s == curr) ++rep;
    }
    return make_pair(s, rep);
}


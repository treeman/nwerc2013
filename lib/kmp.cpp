int b[MAXN]; // back table
void kmpPreprocess(string P) {
    int i = 0, j = -1; b[0] = -1;
    while (i < P.size()) {
        while (j >= 0 && P[i] != P[j]) j = b[j];
        ++i; ++j;
        b[i] = j;
    }
}

void kmpSearch(string T, string P) { // does P match T?
    kmpPreprocess(P); // must prepare P
    int i = 0, j = 0;
    while (i < T.size()) {
        while (j >= 0 && T[i] != P[j]) j = b[j];
        ++i; ++j;
        if (j == P.size()) {
            printf("P is found at index %d in T\n", i - j);
            j = b[j]; // prepare for next possible match
        }
    }
}

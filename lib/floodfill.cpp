// need grid, R, C
int dr[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dc[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

// Return size of CC
int floodfill(int r, int c, char c1, char c2) {
    if (r < 0 || r >= R || c < 0 || c >= C) return 0;
    if (grid[r][c] != c1) return 0;

    int ans = 1; // Because vertex (r, c) has c1 as its color
    grid[r][c] = c2; // Color it
    for (int d = 0; d < 8; ++d)
        ans += floodfill(r + dr[d], c + dc[d], c1, c2);
    return ans;
}


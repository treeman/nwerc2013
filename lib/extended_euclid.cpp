int x, y, d; // answer, give d = gcd(a, b)
void extendedEuclid(int a, int b) { // solve a*x + b*y = d
    if (b == 0) { x = 1; y = 0; d = a; return; }
    extendedEuclid(b, a % b);
    int x1 = y;
    int y1 = x - (a /b) * y;
    x = x1;
    y = y1;
}

// returns the perimeter, which is the sum of Euclidian distances
// of consecutive line segments (polygon edges)
double perimeter(const vector<point> &P) {
    double result = 0.0;
    for (int i = 0; i < (int)P.size() - 1; i++) // P[0] == P[n - 1]
        result += dist(P[i], P[i + 1]);
    return result;
}

double area(const vector<point> &P) {
    double result = 0.0, x1, y1, x2, y2;
    for (int i = 0; i < (int)P.size() - 1; i++) {
        x1 = P[i].x; x2 = P[i + 1].x;
        y1 = P[i].y; y2 = P[i + 1].y;
        result += (x1 * y2 - x2 * y1);
    }
    return fabs(result) / 2.0;
}

bool isConvex(const vector<point> &P) {
    int sz = (int)P.size();
    if (sz <= 3) return false;
    bool isLeft = ccw(P[0], P[1], P[2]);
    for (int i = 1; i < sz - 1; ++i)
        if (ccw(P[i], P[i + 1], P[(i + 2) == sz ? 1 : i + 2]) != isLeft)
            return false; // different sign -> this polygon is concave
    return true;
}

// true if pt in polygon, either convex or concave
bool inPolygon(point pt, const vector<point> &P) { // Assume P[0] == P[n - 1]
    if ((int)P.size() == 0) return false;
    double sum = 0;
    for (int i = 0; i < (int)P.size() - 1; i++) {
        if (ccw(pt, P[i], P[i + 1]))
           sum += angle(P[i], pt, P[i + 1]);
        else sum -= angle(P[i], pt, P[i + 1]);
    }
    return fabs(fabs(sum) - 2 * PI) < EPS;
}

// Convex hull pivot check
point pivot(0, 0); // global pivot for CH compare fun
bool angleCmp(point a, point b) {
    if (collinear(pivot, a, b))
        return dist(pivot, a) < dist(pivot, b);
    double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
}

vector<point> CH(vector<point> P) { // contents in P may be reshuffled
    int n = (int)P.size();
    if (n <= 3) {
        if (!(P[0] == P[n-1])) P.push_back(P[0]); // corner case
        return P; // special case, CH is P
    }
    int P0 = 0; // first, find P0 lowest Y, tie: lowest X
    for (int i = 1; i < n; ++i)
        if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x < P[P0].x))
            P0 = i;

    swap(P[0], P[P0]); // second, sort w.r to angle to P0
    pivot = P[0];
    sort(++P.begin(), P.end(), angleCmp); // Don't sort P[0]

    //third, ccw tests
    vector<point> S;
    S.push_back(P[n - 1]); S.push_back(P[0]); S.push_back(P[1]);
    int i = 2;
    while (i < n) {
        int j = (int)S.size() - 1;
        if (ccw(S[j - 1], S[j], P[i])) S.push_back(P[i++]); // left turn
        else S.pop_back(); // right turn, bad point
    }
    return S;
}

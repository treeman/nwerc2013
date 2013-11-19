struct point_i { // prefer
    int x, y;
    point_i() { x = y = 0; }
    point_i(int _x, int _y) : x(_x), y(_y) { }
};
struct point { // only if double needed, prefer ints
    double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) { }
    bool operator < (point other) const {
        if (fabs(x - other.x) > EPS) // EPS comparison!
            return x < other.x;
        return y < other.y;
    }
    bool operator == (point other) const { // EPS comparison
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
    }
};
// Euclidian distance
double dist(point p1, point p2) { return hypot(p1.x - p2.x, p1.y - p2.y); }

// A vector is not a point here
struct vec { double x, y; vec(double _x, double _y) : x(_x), y(_y) { } };

vec toVec(point a, point b) { return vec(b.x - a.x, b.y - a.y); }
vec scale(vec v, double s) { return vec(v.x * s, v.y * s); }

// Move a point
point translate(point p, vec v) { return point(p.x + v.x, p.y + v.y); }

double dot(vec a, vec b) { return a.x * b.x + a.y * b.y; }
double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

// Closest point to the line defined by a and b (must be different!)
double distToLine(point p, point a, point b, point &c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));
    return dist(p, c);
}

// Closest point to line segment between a and b (OK if a == b)
double distToLineSegment(point p, point a, point b, point &c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if (u < 0.0) { c = point(a.x, a.y); return dist(p, a); }
    if (u > 1.0) { c = point(b.x, b.y); return dist(p, b); }
    return distToLine(p, a, b, c);
}

// ax + by + c = 0, b = 0.0 if vertical, 1.0 otherwise
struct line { double a, b, c; };

void pointsToLine(point p1, point p2, line &l) {
    if (fabs(p1.x - p2.x) < EPS) { // special for vertical
        l.a = 1.0; l.b = 0.0; l.c = -p1.x;
    }
    else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        l.c = -(double)(l.a * p1.x) - p1.y;
    }
}

bool areParallel(line l1, line l2) { // check a & b
    return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}

bool areSame(line l1, line l2) { // check c
    return areParallel(l1, l2) && (fabs(l1.c - l2.c) < EPS);
}

// Check lines, not line segments
bool areIntersect(line l1, line l2, point &p) {
    if (areParallel(l1, l2)) return false;
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
    else                  p.y = -(l2.a * p.x + l2.c);
    return true;
}

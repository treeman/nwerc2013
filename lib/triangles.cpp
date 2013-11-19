double perimeter(double ab, double bc, double ca) {
    return ab + bc + ca;
}

double perimeter(point a, point b, point c) {
    return dist(a, b) + dist(b, c) + dist(c, a);
}

double area(double ab, double bc, double ca) {
    double s = 0.5 * perimeter(ab, bc, ca); // Heron's formula
    return sqrt(s) * sqrt(s - ab) * sqrt(s - bc) * sqrt(s - ca);
}

double area(point a, point b, point c) {
    return area(dist(a, b), dist(b, c), dist(c, a));
}

// Radius of a circle described inside the triangle
double rInCircle(double ab, double bc, double ca) {
    return area(ab, bc, ca) / (0.5 * perimeter(ab, bc, ca));
}

double rInCircle(point a, point b, point c) {
    return rInCircle(dist(a, b), dist(b, c), dist(c, a));
}

// 1 if there is a circle inside the triangle. ctr will be the center
// and r the radi
int inCircle(point p1, point p2, point p3, point &ctr, double &r) {
    r = rInCircle(p1, p2, p3);
    if (fabs(r) < EPS) return 0; // not in circle

    line l1, l2;
    double ratio = dist(p1, p2) / dist(p1, p3);
    point p = translate(p2, scale(toVec(p2, p3), ratio / (1 + ratio)));
    pointsToLine(p1, p, l1);

    ratio = dist(p2, p1) / dist(p2, p3);
    p = translate(p1, scale(toVec(p1, p3), ratio / (1 + ratio)));
    pointsToLine(p2, p, l2);

    areIntersect(l1, l2, ctr);
    return 1;
}

// Radius of the circle outside the triangle
double rCircumCircle(double ab, double bc, double ca) {
    return ab * bc * ca / (4.0 * area(ab, bc, ca));
}

double rCircumCircle(point a, point b, point c) {
    return rCircumCircle(dist(a, b), dist(b, c), dist(c, a));
}

// 1 if there is a circle circums the triangle. ctr will be the center
// and r the radi
int circumCircle(point p1, point p2, point p3, point &ctr, double &r) {
    double a = p2.x - p1.x, b = p2.y - p1.y;
    double c = p3.x - p1.x, d = p3.y - p1.y;
    double e = a * (p1.x + p2.x) + b * (p1.y + p2.y);
    double f = c * (p1.x + p3.x) + d * (p1.y + p3.y);
    double g = 2.0 * (a * (p3.y - p2.y) - b * (p3.x - p2.x));
    if (fabs(g) < EPS) return 0;

    ctr.x = (d * e - b * f) / g;
    ctr.y = (a * f - c * e) / g;
    r = dist(p1, ctr);
    return 1;
}

bool canFormTriangle(double a, double b, double c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

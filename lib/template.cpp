#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <deque>
#include <set>
#include <string>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <complex>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a); i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define all(x) (x).begin(),(x).end()
#define B begin()
#define E end()
#define pb push_back

typedef pair<int, int> ii; // used in comp prog algorithms
typedef double fl;
typedef long double ld;
typedef long long ll;
//typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef map<int,int> mii;
typedef multimap<int,int> mmii;
typedef set<int> si;
typedef multiset<int> msi;
typedef complex<fl> cx;

const int UNVISITED = -1;
const int INF = 1e9;
const double EPS = 1e-9;
const double PI = acos(-1.0); // alternative (2.0 * acos(0.0))

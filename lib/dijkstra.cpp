const int INF = 1e9;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> AdjList;
int V, E, s, t;

int dijsktra(int s, int t) { // variant will leave duplicate nodes in queue
    vi dist(V, INF);
    dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push(ii(0, s));
    while (!pq.empty()) {
        ii front = pq.top(); pq.pop();
        int d = front.first, u = front.second;
        if (d > dist[u]) continue; // important check
        for (int j = 0; j < (int)AdjList[u].size(); ++j) {
            ii v = AdjList[u][j];
            if (dist[u] + v.second < dist[v.first]) {
                dist[v.first] = dist[u] + v.second; // relax
                pq.push(ii(dist[v.first], v.first));
            }
        }
    }
    return dist[t];
}



// vector<dist> djikstra(vector<vector<egde<dst, len, starttime, period> > >, int source, vector int<path>);
// Complexity O(ElogN)
struct Edge{
  int dst,l,ts,tp;
  Edge(int a, int b, int c, int d){dst=a; l=b; ts=c; tp=d;};
};

vi djikstra(vector<vector<Edge> >& g, int s, vi&path){
  vi res(g.size(),-1); path.resize(g.size());
  set<pii>Q; vector<bool> av(g.size(),1);
  res[s]=0; Q.insert(pii(0,s));
  while(!Q.empty()){
    int cur = Q.B->second;
    Q.erase(Q.B);
    av[cur]=0;
    trav(it, g[cur]){
      if(it->tp==0 && it->ts < res[cur]) continue;
      int nxt = res[cur]-it->ts;
      if(res[cur]<=it->ts) nxt=it->ts; else nxt=it->ts + (nxt/it->tp)*(it->tp) + (nxt%it->tp ? it->tp : 0);
      nxt+=it->l;
      int& dst=res[it->dst];
      if(dst!=-1 && dst<=nxt) continue;
      if(dst>-1) Q.erase(pii(dst, it->dst));
      dst=nxt;
      Q.insert(pii(dst, it->dst));
      path[it->dst]=cur;
    }
  }
  return res;
}

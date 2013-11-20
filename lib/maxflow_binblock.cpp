// int maxflow(vector< vector<pair<dest,cap> > > network, int source, int dest, vector<vector<pair<dest, flow> > > resultflow)
// Complexity O(VE) (:
// Works with noninteger values
vvi G; vector<bool> av;
vector<si> GE;

bool dfs(int s, int t, int c){
  if(s==t) return 1;
  av[s]=0;
  trav(it, GE[s]){
    if(!av[*it]|| c>G[s][*it]) continue;
    if(dfs(*it, t, c)){
      G[s][*it]-=c;
      G[*it][s]+=c;
      return 1;
    }
  }
  return 0;
}

int maxflow(vector<vector<pii> >&g, int s, int t, vector<vector<pii> > &resf){
  int n=g.size();
  G.resize(n); trav(it, G) it->resize(n);
  GE.resize(n);
  rep(i,0,n) trav(it,g[i]) {G[i][it->first]+=it->second; GE[i].insert(it->first); GE[it->first].insert(i);}
  vvi GG=G;
  int res=0; av.resize(n,1);
  rrep(i,30,0) {fill(all(av),1); while(dfs(s,t,1 << i)){fill(all(av),1); res+= 1<<i;}}
  resf.resize(g.size());
  rep(i,0,n) trav(it, g[i]) {
    int d=min(GG[i][it->first]-G[i][it->first], it->second);
    if(d<=0) continue;
    GG[i][it->first]-=d;
    resf[i].pb(pii(it->first,d));
  }
  return res;
}

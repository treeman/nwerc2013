// vector<int> knapsack(capasity, vector<pair<weight, value> >)
// O(NC)
// M(NC)
vi knapsack(int c, vector<pii>&o){
  vi res;
  vector<vi> dp(o.size()+1); //[obj][cap]
  trav(it,dp) it->resize(c+1);
  rep(i,0,o.size()) rep(j,o[i].first,c+1)
    dp[i+1][j]=max(dp[i][j], dp[i][j-o[i].first]+o[i].second);

  int mx=0; rep(i,0,c+1) if(dp.back()[i]>dp.back()[mx]) mx=i;
  rrep(i,o.size()-1,0) if(dp[i][mx]<dp[i+1][mx]){
    res.push_back(i); mx-=o[i].first;
  }
  return res;
}

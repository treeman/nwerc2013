// O(n log n) vector<int> cover(start, end, vector<inteval pair>)
vi cover(fl s, fl e, vector<pair<fl,fl> >& m){
  int lst=-1;
  vector<pair<typeof(m[0]), int> > tm(m.size());
  rep(i,0,m.size()) tm[i]=make_pair(m[i],i);
  sort(all(tm));
  vi res;
  while(lst<int(m.size())){
    int cur=lst;
    for(int i=lst+1; i<int(m.size()) && tm[i].first.first<=s; i++){
      if((cur!=-1 && tm[i].first.second > tm[cur].first.second) ||
              (cur==-1 && tm[i].first.second >=s)) cur=i;
    }
    if (cur==lst) break;
    lst=cur;
    res.push_back(tm[lst].second);
    s=tm[lst].first.second;
    if (s>=e && res.size()) return res;
  }
  res.clear();
  return res;
}

vector<ll> bt;

void add(int i, ll v){
  if(!i){bt[0]+=v; return;}
  while (i<int(bt.size())){
    bt[i]+=v;
    i+=(i&-i);
  } return;
}

ll sum(int i){
  ll res=bt[0];
  while(i>0){
    res+=bt[i];
    i-=(i&-i);
  } return res;
}

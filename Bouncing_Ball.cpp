#include <bits/stdc++.h>
using namespace std;
 

void solve(){
    int n,m;cin>>n>>m; string s;cin>>s; 
    int xmin =0;int xmax=0;
    int ymin =0;int ymax=0;
    int x=0;int y=0; 
    pair<int,int> p ;
    for(int i=0;i<(int)s.size();i++){
       if(s[i]=='L')y--;
       if(s[i]=='R')y++;
       if(s[i]=='D')x++;
       if(s[i]=='U')x--;
       xmin = min(x,xmin);
       ymin = min(y,ymin);
       xmax = max(x,xmax);
       ymax = max(y,ymax);
       if(xmax-xmin == n)break;
       if(ymax-ymin == m)break;
       p={-xmin,-ymin};
    }
    p.first++;p.second++;
    cout<<p.first<<" "<<p.second<<"\n";

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int  t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
    
}

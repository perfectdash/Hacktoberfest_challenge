#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5+7;
int dp[3008][3009]={0};

void  reterival(string& s,string& t,int n,int m,int sz){
        int i=0;int j=0; string LCS;
        while(sz>0){
            if(s[i]==t[j]){
                LCS.push_back(s[i]);
                i++;j++;sz--;
            }else{
                if(dp[i+1][j]>=dp[i][j+1]){
                    i++;
                }else{
                    j++;
                }
            }
        }
        cout<<LCS<<"\n";
}



int max_size(string& s,string& t,int n,int m,int i,int j){
    if(i>=n or j>=m){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s[i]==t[j]){
        return dp[i][j]= 1+max_size(s,t,n,m,i+1,j+1);
    }else{
        return dp[i][j]= max(max_size(s,t,n,m,i+1,j),max_size(s,t,n,m,i,j+1));
    }
    
}

void solve(){
    string s,t;cin>>s>>t;int n,m; n = s.size(); m = t.size(); 
    memset(dp,-1,sizeof dp);


    // not a useful way of doing operations 

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         if(s[i-1]==t[j-1]){
    //            dp[i][j]=(1+max(0,dp[i-1][j-1]));
    //         }
    //         dp[i][j]=max(dp[i][j],dp[i-1][j]);
    //         dp[i][j]=max(dp[i][j],dp[i][j-1]);
    //     }
    // }

    int sz = max_size(s,t,n,m,0,0);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    // int sz = dp[n][m];

    reterival(s,t,n,m,sz);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cout<<setprecision(20);

    unsigned int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
    
}

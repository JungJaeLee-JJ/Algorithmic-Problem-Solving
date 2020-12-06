#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long long int dp[1<<15][100];

long long int gcd(long long int a, long long int b)
{
   if(a==b||b==0) return a;
   else return gcd(b,a%b);
}

int main()
{
    int n,k;
    cin>>n;

    vector<string> s(n);
    vector<int> each_string_len(n,0);
    vector<int> ten_mod(51,0);
    vector<int> each_mod(n,0);

    for(int i=0;i<n;i++) {
        cin>>s[i];
        each_string_len[i]=s[i].length();
    }

    cin>>k;
    ten_mod[0]=1;
    for(int i=1;i<=50;i++) ten_mod[i]=(ten_mod[i-1]*10)%k;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<each_string_len[i];j++)
        {
            each_mod[i]=(each_mod[i]*ten_mod[1]+(s[i][j]-'0'))%k;
        }
    }

    dp[0][0]=1;
    //i는 전체의 수열
    for(int i=0;i<(1<<n);i++)
    {
        //k는 나머지
        for(int j=0;j<k;j++)
        {
            for(int t=0;t<n;t++)
            {
                if((i&(1<<t))==0)
                {
                    int mod_=(j*ten_mod[each_string_len[t]]+each_mod[t])%k;
                    dp[i|1<<t][mod_]= dp[i|1<<t][mod_]+ dp[i][j];
                }
            }
        }
    }
    long long int ans = dp[(1<<n)-1][0];
    long long int total=1;
    for(int i=1;i<=n;i++) total=total*i;
    long long g=gcd(total,ans);
    cout<<ans/g<<"/"<<total/g;
    return 0;
}
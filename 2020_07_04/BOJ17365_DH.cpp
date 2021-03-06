#include <iostream>
#include <cstring>
#include <map>

using namespace std;

typedef struct Node{
    Node * next[26];
    int cnt = 1;
}Node;

Node * root = new Node();
int dp[200001];
int dp2[200001];

string str;
int length;
const int MOD = 1000000007;
map<string, int> m;

void addString(Node* node, string& s, int idx, int len){
    if(idx == len) return;
    int val = s[idx] - 'a';
    if(node->next[val]) node->next[val]->cnt++;
    else node->next[val] = new Node();
    addString(node->next[val], s, idx+1, len);
}

int findCnt(Node* node, string& s, int idx){
    if(int(s.size()) == idx){
        return node->cnt;
    }
    int val = s[idx] - 'a';
    if(node->next[val]) return findCnt(node->next[val], s, idx+1);
    else return 0;
}
//liisryanilio
//12

//dp[0] = 1
//dp[1] = findCnt(o) * dp[0];
//dp[2] = findCnt(io) * dp[0] + findCnt(i) * dp[1]
//dp[3] = findCnt(lio) + dp[0] + findCnt(li) * dp[1] + findCnt(l) * dp[2]  

int dfs(int n){
    if(dp[n] != -1) return dp[n];
    if(n == 0) return dp[n] = 1;
    dp[n] = 0;
    for(int i=0; i<n; i++){
        if(dfs(i) != 0){
            string s = str.substr(length - n, n - i);
            int val = findCnt(root, s, 0);
            if(val == 0) continue;
            dp[n] += ( dfs(i) * val ) % MOD;
            //cout <<"dp[" << n << "]= " << dp[n] << " " << s << " + " << "dp[" << i << "]\n";
        }
    }
    return dp[n];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        int len = s.size();
        addString(root, s, 0, len);
    }
    cin >> str;
    length = str.size();
    cout << dfs(length);
    return 0;
}
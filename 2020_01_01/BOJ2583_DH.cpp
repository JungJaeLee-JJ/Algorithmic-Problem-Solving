iiiiiiiii#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int board[101][101];
int y, x, k;
vector<int> d;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int dfs(int mx, int my){ // (my, mx) 로 시작해서 dfs로 1을 채운다.
	int ret = 1;
	board[my][mx] = 1;
	
	for(int i=0; i<4; i++){
		int nx = mx + dx[i];
		int ny = my + dy[i];
		if(nx < x && ny < y && nx >= 0 && ny >= 0){
			if ( board[ny][nx] == 0 ) 
				ret += dfs(nx, ny);
		}
	}
	
	return ret;
}

int main(){
	cin >> y >> x >> k;
	for(int i=0; i<k; i++){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for(int nx = x1; nx < x2; nx++)
			for(int ny =y1; ny < y2; ny++)
				board[ny][nx] = -1;
	}
	
	for(int i=0; i<y; i++){
		for(int j=0; j<x; j++){
			if(board[i][j] == 0) d.push_back(dfs(j, i));
		}
	}
	
	cout << d.size() << endl;
	sort(d.begin(), d.end());
	for(int i=0; i<d.size(); i++) cout << d[i] << " ";
	
	return 0;
}

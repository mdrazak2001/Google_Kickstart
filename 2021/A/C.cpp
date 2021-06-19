// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000436140/000000000068cb14
#include<bits/stdc++.h>
using namespace std;
#define int               long long
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void solve(int test) {
	cout << "Case #" << test << ": ";
	int r, c ;
	cin >> r >> c ;
	vector<vector<int>> g(r, vector<int> (c));
	set<pair<int, pair<int,int>>> s;
	for(int i = 0 ; i < r ; i++) {
		for(int j = 0 ; j < c ; j++) {
			cin >> g[i][j] ;
			s.insert({-g[i][j], {i,j}}) ;
		}
	}
	int ans = 0 ;
	while(!s.empty()) {
		auto curr = *s.begin() ;
		s.erase(s.begin());
		int h = -curr.first ;
		int x = curr.second.first;
		int y = curr.second.second;
		for(int i = 0 ; i < 4 ; i++) {
			int nx = x + dx[i], ny = y + dy[i] ;
			if(nx < 0 or ny < 0 or nx >= r or ny >= c) {
				continue; 
			}
			if(g[nx][ny] >= h - 1) {
				continue;
			}
			int diff = (h - 1) - g[nx][ny] ;
			ans += diff ;
			s.erase({-g[nx][ny], {nx,ny}}) ;
			g[nx][ny] = h - 1 ;
			s.insert({-g[nx][ny], {nx,ny}}) ;
		}
	}
	cout << ans ;
	cout << "\n" ;
}

signed main()
{
	/* code */
	int t ;
	cin >> t ;
	for(int i = 1 ; i <= t ; i++) {
		solve(i) ;
	}
	return 0;
}
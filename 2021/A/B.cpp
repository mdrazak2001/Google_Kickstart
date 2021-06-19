#include<bits/stdc++.h>
using namespace std;

int main() {
    int t ; 
    cin >> t ;
    // cout << "abc" ;
    int m = 1;
    while(t--) {
       int r, c ;
       cin >> r >> c ;
       vector<vector<int>> g(r, vector<int> (c)) ;
       vector<vector<int>> up(r, vector<int>(c)) ;
       vector<vector<int>> down(r, vector<int>(c)) ;
       vector<vector<int>> left(r, vector<int>(c)) ;
       vector<vector<int>> right(r, vector<int>(c)) ;
       
        for(int i = 0 ; i < r ; i++) {
           for(int j = 0 ; j < c ; j++) {
               cin >> g[i][j] ;
           }
        }
        
        for(int i = 0 ;i < r ; i++) {
            for(int j = 0 ; j < c ; j++) {
                left[i][j] = g[i][j] ;
                if(j and g[i][j]) {
                    left[i][j] += left[i][j-1] ;
                }
            }
        }
        
        for(int j = 0 ; j < c ; j++) {
            for(int i = 0 ; i < r ; i++) {
                up[i][j] = g[i][j] ;
                if(i and g[i][j]) {
                    up[i][j] += up[i-1][j] ;
                }
            }
        }
        
        for(int i = 0 ;i < r ; i++) {
            for(int j = c-1 ; j >= 0 ; j--) {
                right[i][j] = g[i][j] ;
                if(j < c-1 and g[i][j]) {
                    right[i][j] += right[i][j+1] ;
                }
            }
        }
        
        for(int j = 0 ; j < c ; j++) {
            for(int i = r-1 ; i >= 0 ; i--) {
                down[i][j] = g[i][j] ;
                if(i < r-1 and g[i][j]) {
                    down[i][j] += down[i+1][j] ;
                }
            }
        }
        
        int ans = 0 ;
        for(int i = 0 ; i < r ; i++) {
            for(int j = 0 ; j < c ; j++) {
                if(up[i][j] > 1) {
                    if(right[i][j] > 2)
                        ans += min(up[i][j], right[i][j]/2)-1 ;
                    if(left[i][j] > 2)
                        ans += min(up[i][j], left[i][j]/2) -1;   
                }
                
                if(down[i][j] > 1) {
                    if(right[i][j] > 2)
                        ans += min(down[i][j], right[i][j]/2)-1 ;
                    if(left[i][j] > 2)
                        ans += min(down[i][j], left[i][j]/2) -1;
                }
                
                if(left[i][j] > 1) {
                    if(up[i][j] > 2) 
                        ans += min(left[i][j], up[i][j]/2)-1 ;
                    if(down[i][j] > 2)
                        ans += min(left[i][j], down[i][j]/2) -1;   
                }
                if(right[i][j] > 1) {
                    if(up[i][j] > 2)
                        ans += min(right[i][j], up[i][j]/2)-1 ;
                    if(down[i][j] > 2) 
                        ans += min(right[i][j], down[i][j]/2) -1;
                }
            }
        }
        cout << "Case #" << m << ": " << ans << endl ;
        m++;
    }  

}
//this is just an idea of how to implement.
//always implement it fresh.
//author - Satwik_Tiwari


#include<bits/stdc++.h>
using namespace std;

void solve(){
    //binary lifting.
    int LOG = 18;
    int bl[m][LOG]; //stores 2*kth parent for every ith node. where 0<=k<LOG ;
  
    //preprocessing
    for(int j=0;j<LOG;j++){
        for(int i=0;i<m;i++){
            if(j == 0){
                bl[i][j] = right[i];
            }
            else{
                int to = bl[i][j-1];
                if(to == -1) bl[i][j] = -1;
                else bl[i][j] = bl[to][j-1];
            }
        }
    }
  
    // using binary lifting table to find the n-1th parent.
    for(int i=0;i<m;i++){
        int curr = i;
        for(int j=17;j>=0;j--){
            if(curr == -1) break;
            if(((n-1) >> j) & 1){
                curr = bl[curr][j];
            }
        }
    }
}

int32_t main(){
  solve();
}

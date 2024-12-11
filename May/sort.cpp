#include <bits/stdc++.h>
using namespace std;

int binarySearch( vector<int>& grids){
    int s =0;
    int e = grids.size()-1;
    int loc = -1;
    while(s<=e){
        int mid = s+ (e-s)/2;
        if(grids[i]==1){
            loc = mid;
            e = mid -1;
        }
        else{
            s = mid+1;
        }
    }
}
int main(void){

	int n, m; cin >> n >> m;
	vector<int> grid(n);
	for(auto &s : grid) cin >> s;

    

}
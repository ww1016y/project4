#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
#include <algorithm>
#define MAX 100
using namespace std;
int map[MAX][MAX];
char arr[4][32];
vector <int> res;
int N, K;

int max_count;

int transform(char temp){

	if (temp == '0') {
		return 0;
	}
	else if (temp == '1') {
		return 1;
	}
	else if (temp == '2') {
		return 2;
	}
	else if (temp == '3') {
		return 3;
	}
	else if (temp == '4') {
		return 4;
	}
	else if (temp == '5') {
		return 5;
	}
	else if (temp == '6') {
		return 6;
	}
	else if (temp == '7') {
		return 7;
	}
	else if (temp == '8') {
		return 8;
	}
	else if (temp == '9') {
		return 9;
	}
	else if (temp == 'A') {
		return 10;
	}
	else if (temp == 'B') {
		return 11;
	}
	else if (temp == 'C') {
		return 12;
	}
	else if (temp == 'D') {
		return 13;
	}
	else if (temp == 'E') {
		return 14;
	}
	else if (temp == 'F') {
		return 15;
	}
}


void solve(){
	
	int num = N / 4;

	for (int i =0; i<N-1; i++){
		arr[1][i+1] = arr[0][i];
		if (i < N-2)	arr[2][i+2] = arr[0][i];
		if (i < N-3)	arr[3][i+3] = arr[0][i];
	}
	arr[1][0] = arr[0][N-1];
	arr[2][0] = arr[0][N-2];
	arr[2][1] = arr[0][N-1];
	arr[3][0] = arr[0][N-3];
	arr[3][1] = arr[0][N-2];
	arr[3][2] = arr[0][N-1];

	int count = 0;
	int sum = 0;


	for (int l =0; l<4; l++) {
		for (int i = 0; i< N; i=i+num){
			sum = 0;
			for (int j = i; j< num+i; j++){
				int trans = transform(arr[l][j]);

				int result = 1;
				for (int k = num+i-1-j ; k >0 ;k--){
					result = result * 16 ;
				}
				
				sum = sum + result * trans;
				
				//cout << trans << "///"<< j << "///" <<sum << '\n';
			}

			if (res.size() == 0) res.push_back(sum);
			else {
				for (int i =0; i<res.size();i++){;
				if ( sum == res[i]) {
					break;
				}
				if ( i == res.size()-1) {
					res.push_back(sum);
				}
				}
			}
		}
	}

		sort(res.begin(), res.end());

	for (int i =0; i<res.size();i++){;
		cout << res[i] << '\n';
	}

	
}


int main() {
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++) {
        
	memset(arr,0,sizeof(arr));
	res.clear();
	max_count =0; 
        scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++) {
		cin >> arr[0][i];
	}

        solve();
	
        printf("#%d %d", tc, res[res.size()-K]);
    }
}


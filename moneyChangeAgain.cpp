#include<bits/stdc++.h>

using namespace std;

map<int,int> m;

int answer(int n){
	m[0]=0;
	int coins[3] = {1,3,4};
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
//			cout << m[i] << "   " << m[i-coins[j]]+1 << "\n";
			if(i>= coins[j]){
				int res = m[i-coins[j]];
//				cout << res << "\n";
				if(res+1 < m[i] || m[i]==0)
					m[i] = res+1; 
//				cout << "new mi" << i << " " << m[i] << "\n";
			}
		}
	}	
	
	return m[n];
}

int main(){
	int money;
	cin >> money;
	cout << answer(money) << "\n";
	
return 0;
}

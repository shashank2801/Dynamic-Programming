#include<bits/stdc++.h>

using namespace std;

map<int, long long int> dp;

long long int getCoins(long long int n){
	if(n<11){
		dp[n]=n;
		return n;
	}
	
	if(dp[n]!=0)
		return dp[n];
		
	dp[n] = max(n,getCoins(n/2)+getCoins(n/3)+getCoins(n/4));
	
	return dp[n];
}

int main(){
	int n;
	while(cin >> n){
		cout << getCoins(n) << "\n";
	}
	
return 0;
}

#include<bits/stdc++.h>

using namespace std;

int getUgly(int n){
	int ugly[n];
	int i2=0,i3=0,i5=0;
	int m2 = 2, m3 = 3, m5 = 5;
	int next = 1;
	
	ugly[0] = 1;
	for(int i=1;i<=n;i++){
		next = min(m2,min(m3,m5));
		ugly[i] = next;
		if(next == m2){
			i2++;
			m2 = ugly[i2]*2;
		}
		else if(next == m3){
			i3++;
			m3 = ugly[i3]*3;
		}
		else{
			i5++;
			m5 = ugly[i5]*5;
		}
	}
	
	return next;
}

int main(){
	int n;
	while(cin >> n)
	cout << getUgly(n) << "\n";
	
return 0;
}

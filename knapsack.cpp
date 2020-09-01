#include <iostream>
#include <vector>

using namespace std;

int optimal_weight(int W , const vector<int> &w ) {
	int n= w.size();
	int** A = new int* [n+1];
	for(int i=0;i<=n;i++)
		A[i] = new int[W+1];
	
	for(int i=0;i<=n;i++){
		for(int j=0;j<=W;j++){
			if(i==0 || j==0)
				A[i][j] = 0;
			
			else if(w[i-1]<=j){
				A[i][j] = max(w[i-1]+A[i-1][j-w[i-1]],A[i-1][j]);
			}
			else
				A[i][j] = A[i-1][j];
		}
	}
	
	int result = A[n][W];
	
	
  for (int i = 0; i < n; i++) {
    delete[] A[i];
  }

  delete[] A;

  return result;
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W , w ) << '\n';
  return 0;
}

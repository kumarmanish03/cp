#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define for0(i,n)   for ( int (i)=0; (i)<(n); (i)++)
#define for1(i,n)   for ( int (i)=1; (i)<=(n); (i)++)
typedef vector<int> vi;
#define pb push_back
#define OJ \
		freopen("input.txt", "r", stdin); \
		freopen("output.txt", "w", stdout);

int bruteforce(int pos, pair<int, int> p, vi arr){

	if (pos == arr.size()){
		if (p.first == p.second)
			return true;
		else
			return false;
	}

	p.first += arr[pos];
	bool ans1 = bruteforce(pos + 1, p, arr);
	p.first -= arr[pos];
	p.second += arr[pos];
	bool ans2 = bruteforce(pos + 1, p, arr);
	p.second += arr[pos];

	// if(ans1) 
	// 	return ans1;
	// else 
	// 	if(ans2) 
	// 		return ans2;
	// 	else
	// 		return false;

	return ans1 || ans2;
}

int isSubsetSum(vi arr, int sum){

	bool dp[arr.size() + 1][sum + 1];

	for0(i, arr.size()+1)
		dp[i][0] = true;
	for1(i, sum)
		dp[0][i] = false;

	for1(i, arr.size()){
		for1(j, sum){
			if(arr[i-1] > j)
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
		}
	}

	return dp[arr.size()][sum];
}

int solve(){
	int n, sum;
	cin>>n>>sum;
	
	vi arr;
	for0(i,n){
		int t;
		cin>>t;
		arr.push_back(t);
	}

	cout<<isSubsetSum(arr, sum)<<"\n";

  return 0;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  OJ;
  int t = 1;
  cin>>t;
  while(t--) solve();
}
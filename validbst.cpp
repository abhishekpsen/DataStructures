#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;


bool checkpreorderbst(vector<int> &a, int p, int q){
	if(p>q || q-p == 0 || q-p == 1){
		return true;
	}
	int root = a[p];
	int right = p+1;
	while(a[right]<=root){
		right++;
	}
	/*for(int j=p+1;j<right;j++){
		if(a[j]>root){
			return false;
		}
	}*/
	for(int j=right;j<=q;j++){
		if(a[j]<root){
			return false;
		}
	}

	return checkpreorderbst(a,p+1,right-1) && checkpreorderbst(a,right,q);
}

int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,n;
	cin>>t;
	
	while(t--){
		cin>>n;
		vector<int> preorderarr(n);
		for(int i=0;i<=n-1;i++){
			cin>>preorderarr[i];
		}
		cout<<checkpreorderbst(preorderarr,0,n-1)<<endl;
	}
	

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long ll;
 
int p1[100123],p2[100123];
ll rez[200123];
int t,n,i,b;
 
 
void solve( int x ){
	
	n=x;
	
	for(i=n;i>=0;i--)p1[i]=rand();
	for(i=n;i>=0;i--)p2[i]=rand();
	
	for(i=0;i<=n;i++){
		for(b=0;b<=n;b++){
			rez[i+b]+=p1[i]*p2[b];
		}
	}
	
//	for(i=n*2;i>=0;i--)printf("%lld ",rez[i]);
	
	memset( rez , 0 , sizeof rez );

    
}
 
int main(){
	
	srand(time(NULL));
	
	int br_testova=8;
	
	int test_n[] = { 100 , 1000 , 2000 , 5000 ,  10000 , 20000 , 50000 , 100000  };//, 100000
	
	
	for(int i=0;i<br_testova;i++){
		
		chrono::steady_clock::time_point begin = chrono::steady_clock::now();
		
		int br_sim=3;
		double mikrosek=0;
		
		for(int j=0;j<br_sim;j++){
			chrono::steady_clock::time_point begin = chrono::steady_clock::now();
			
			solve( test_n[i] );
		
			chrono::steady_clock::time_point end = chrono::steady_clock::now();
			mikrosek+=chrono::duration_cast<chrono::microseconds>(end - begin).count();
		}
		
		cout << mikrosek/1e6/(double)br_sim << endl;
	}
	
    
    return 0;
}
 

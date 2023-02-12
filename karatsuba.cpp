#include <bits/stdc++.h>
#include <chrono>
using namespace std;
typedef long long ll;
static int n,i,b,t;
ll p1[1000123],p2[1000123],uk[2000123],pom[1000123];
 
void kar( int l , int lp , int kf , int st , int k , int j , int ok ){
	
	if( st<=32 ){
		for(i=0;i<=st;i++)
			for(b=0;b<=st;b++){
				uk[l+i+b]+=ok*p1[k+i]*p2[k+b];
				pom[lp+i+b]+=kf*p1[k+i]*p2[k+b];
			}
		return;
	}
	
	int mp1=st/2;
	
	for(i=0;i<=mp1;i++)p1[k+st+1+i]=p1[k+i],p2[k+st+1+i]=p2[k+i];
	kar( j , k , -1 , mp1 , k+st+1, j+st*2+1  , 1 );
	
	int mp2=st-mp1-1;
	for(i=0;i<=mp2;i++)p1[k+st+1+i]=p1[k+mp1+i+1],p2[k+st+1+i]=p2[k+mp1+i+1];
	kar( j+(mp1+1)*2 , k , -1 , mp2 , k+st+1 , j+st*2+1 , 1 );
	
	for(i=0;i<=mp1;i++)
	p1[k+st+1+i]=p1[k+i]+(mp1+i+1<=st)*p1[k+mp1+i+1],
	p2[k+st+1+i]=p2[k+i]+(mp1+i+1<=st)*p2[k+mp1+i+1];
	
	kar( j , k , 1 , mp1 , k+st+1 , j+st*2+1 , 0 );
	
	for(i=0;i<=st;i++)uk[j+mp1+i+1]+=pom[k+i],pom[k+i]=0;
	
	if(st!=n)for(i=0;i<=2*st;i++)uk[l+i]+=ok*uk[j+i] , pom[lp+i]+=kf*uk[j+i];
	if(st!=n)for(i=0;i<=2*st;i++)uk[j+i]=0;
}
 
 
void solve(int x){
	n=x;
	
	for(i=n;i>=0;i--)p1[i]=rand();
	for(i=n;i>=0;i--)p2[i]=rand();
	
	kar( 0  , 0 , 0 , n , 0 , 0 , 1 );
	
//	for(i=2*n;i>=0;i--)printf("%lld ",uk[i]),uk[i]=0;
//	printf("\n");
}
 
 
int main(){
	
	srand(time(NULL));
	
	int br_testova=2;
	
	//int test_n[] = { 100 , 1000 , 2000 , 5000 ,  10000 , 20000 , 50000 , 100000  };//, 100000
	
	int test_n[] = { 200000 , 500000 };
	
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

/*

#include <chrono>

chrono::steady_clock::time_point begin = chrono::steady_clock::now();
chrono::steady_clock::time_point end = chrono::steady_clock::now();

cout << "Time difference = " << chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << endl;
cout << "Time difference = " << chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << endl;

*/



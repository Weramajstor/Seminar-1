/*

Preuzeto i modificirano sa stranice 
https://cp-algorithms.com/algebra/fft.html#implementation

*/
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;


typedef long long ll;
typedef complex<double> cd;
//using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    if (n == 1)
        return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) { 
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}


vector<ll> multiply(vector<ll> const& a, vector<ll> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<ll> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}


void solve(int x){
	
	vector<ll> a, b;
	
	int n=x;
	
	for(int i=0;i<n+1;i++){
		ll d=rand();
		a.push_back( d );
	}
	
	for(int i=0;i<n+1;i++){
		ll d=rand();
		b.push_back( d );
	}
	
	auto reza=multiply( a , b );
	
/*	for( int i = 0 ; i <= 2*n ; i++ ){
		cout<< reza[i] <<" ";
	}cout<<endl;
*/
	
}


int main(){

	srand(time(NULL));
	
	int br_testova=10;
	
	int test_n[] = { 100 , 1000 , 2000 , 5000 ,  10000 , 20000 , 50000 , 100000 , 200000 , 500000  };//, 100000
	
	
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

1
2
9 1 1
9 1 1

2
2
1 2 3
3 2 1
2
1 0 1
2 1 0



*/




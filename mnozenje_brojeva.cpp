/*

Program za brzo mnozenje u O(nlogn) 
dva velika pozitivna cjelobrojna broja.

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



int main(){
	
	vector<ll> a, b;
	
	string A,B;
	
	cout<<"Unesite prvi broj:"<<endl;
	cin>>A;
	cout<<"Unesite drugi broj:"<<endl;
	cin>>B;
	
	for(int i=0;i<A.length();i++){
		a.push_back( A[i]-'0' );
	}
	
	for(int i=0;i<B.length();i++){
		b.push_back( B[i]-'0' );
	}
	
	
	reverse( a.begin() , a.end() );
	reverse( b.begin() , b.end() );
	
	
	auto c=multiply( a , b );
	
	vector<ll> produkt;
	
	int n=A.length()+B.length();
	
	produkt.resize( n , 0 );
	
	
	
	for(int i=0;i<produkt.size();i++){	
 		
 		produkt[i]+=c[i];
 		
 		ll x=produkt[i]/10;
 		
 		produkt[i]=produkt[i]%10;
 		
 		int b=i+1;
 		while(x){
 			
 			
 			if(b==produkt.size()){
 				produkt.push_back(0);
 				c.push_back(0);
 			}
  			produkt[b]+=x%10;
 			
 			b++;
 			x/=10;
 		}
 		
 	}
	
	cout<<"Umnozak:"<<endl;
	
	int ok=0;
	for(int i=produkt.size()-1; i>=0 ;i--){
		if( produkt[i] )ok=1;
		
		if(ok)cout<<produkt[i];
	}
	cout<<endl;
	
	
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




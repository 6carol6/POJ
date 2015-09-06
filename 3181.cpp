#include <iostream>
#include <memory.h>
using namespace std;

const int MAXN = 1001;
const long long inf=1000000000000000000LL;

long long a[MAXN];
long long b[MAXN];
int nValue;

void CompletePack(int c, int w){
	for(int i = c; i <= nValue; i++){
		a[i] += a[i-c]+(b[i]+b[i-c])/inf;
		b[i] = (b[i]+b[i-c])%inf;
	}
}

int main(){
	int N, K;
	while(cin >> N >> K){
		nValue = N;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		b[0] = 1;
		for(int i = 1; i <= K; i++){
			CompletePack(i, i);
		}
		if(a[N] == 0)
			cout << b[N] << endl;
		else
			cout << a[N] << b[N] << endl;
	}
	return 0;
}
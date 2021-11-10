#include<bits/stdc++.h>
using namespace std;
int p,q,n; 
int power(int x, int y, int p)
{
	int res = 1;	 // Initialize result

	x = x % p; // Update x if it is more than or
				// equal to p

	if (x == 0) return 0; // In case x is divisible by p;

	while (y > 0)
	{
		// If y is odd, multiply x with result
		if (y & 1)
			res = (res*x) % p;

		// y must be even now
		y = y>>1; // y = y/2
		x = (x*x) % p;
	}
	return res;
}

int encrypter(int m, int n)
{
    int c = power(m,2,n);    
    return c;
}
int mod(int k, int b, int m) 
{
    int i=0;
    int a=1;
    vector<int> t;
    while(k>0){
        t.push_back(k%2);
        k=(k-t[i])/2;
        i++;
    }
    for(int j=0; j<i; j++){
        if(t[j]==1){
            a=(a*b)%m;
            b=(b*b)%m;
        } else{
            b=(b*b)%m;
        }
    }
    return a;
}
int PrimarityTest(int a, int i)
{
    int n = i - 1;
    int k = 0;
    int j, m, T;
 
    while (n % 2 == 0)
    {
        k++;
        n = n / 2;
    }
 
    m = n;
    T = mod(m,a, i);
 
    if (T == 1 || T == i - 1) {
        return 1;
    }
 
    for (j = 0; j < k; j++)
    {
        T = mod(2,T, i);
 
        if (T == 1) {
            return 0;
        }
 
        if (T == i - 1) {
            return 1;
        }
    }
 
    return 0;
}
void KeyGeneration()
{
    do {
        do {
            p = rand() % 50000;
        }
        while (!((p % 2 == 1) && (p % 4 == 3)));
    }
    while (!PrimarityTest(2, p));
 
    do {
        do {
            q = rand() % 50000;
        }
        while (!((q % 2 == 1) && (q % 4 == 3)));
    }
    while (!PrimarityTest(2, q));
 
    n = p * q;
   
}


int modulo (int a, int b)
{
    return a >= 0 ? a % b : ( b - abs ( a%b ) ) % b;
}

vector<int> Extended_Euclid(int a, int b)
{
    if (b>a) {
        int temp=a; a=b; b=temp;
    }
    int x=0;
    int y=1;
    int lastx=1;
    int lasty=0;
    while (b!=0) {
        int q= a/b;
        int temp1= a%b;
        a=b;
        b=temp1;
        int temp2 = x;
        x=lastx-q*x;
        lastx = temp2;
        int temp3 = y;
        y = lasty-q*y;
        lasty=temp3;
    }
    vector<int>arr(3);
    arr[0] = lastx;
    arr[1] = lasty;
    arr[2] = 1;
    return arr;
}

void decrypter(int c, int p, int q)
{
    int mp = mod((p+1)/4, c, p);
    int mq = mod((q+1)/4, c, q);
    //cout<<"m"<<mp<<" "<<mq<<"\n";
    vector<int> arr = Extended_Euclid(p, q);
    //cout<<arr[0]<<" "<<arr[1]<<"\n";
    int rootp,rootq;
    if(p*arr[0]+q*arr[1]==1)
    {
        rootp = arr[0]*p*mq;
        rootq = arr[1]*q*mp;
    }
    else 
    {
      rootp = arr[1]*p*mq;
      rootq = arr[0]*q*mp;
    } 
    
    //cout<<rootp<<" "<<"root"<<rootq<<"\n";
    int r = modulo((rootp+rootq), n);
    int negative_r = n - r;
    int s = modulo((rootp-rootq), n);
    int negative_s = n - s;
    cout<<"ALL FOUR ROOTS OBTAINED ARE "<<r<<" "<<negative_r<<" "<<s<<" "<<negative_s<<"\n";
}
int main()
{
    
    int message;
    cout<<"ENTER THE MESSAGE "<<"\n";
    cin>>message;
    while(n<=message)
    {
        KeyGeneration();
    }
    
    cout<<"THE PRIVATE KEY P AND Q ARE "<<p<<" "<<q<<"\n";
    cout<<"THE PUBLIC KET N IS  "<<n<<"\n";
    int cipher=encrypter(message,n);
    cout<<"CIPHER TEXT OBTAINED IS "<<cipher<<"\n";
    decrypter(cipher,p,q);
}

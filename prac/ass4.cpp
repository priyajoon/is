#include <bits/stdc++.h>
using namespace std;

// int gcd(int a,int b){
// 	if(b==0){
// 		return a;
// 	}
// 	return gcd(b , a%b);
// }
int modpow(int base, int exponent, int modulus) {
    int result = 1;
    base = base % modulus;
    while (exponent > 0) {
        if (exponent & 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

void generateKeys(int p,int q,int &e,int &d,int &n){
	n=p*q;
	int phi=(p-1)*(q-1);
	e=2;
	while(1){
		if(__gcd(e,phi)==1){
			break;
		}
		e++;
	}
	d=2;
	while(1){
		if((d*e)%phi==1){
			break;
		}
		d++;
	}
}


long long int encrypt(int msg,int e,int n){
	//long long int ans=modpow(msg,e,n);
	long long int ans=1;
	while(e--){
		ans*=msg;
		ans%=n;
	}
	return ans;
}

long long int decrypt(int en_msg,int d,int n){
	//long long int ans=modpow(en_msg,d,n);
	long long int ans=1;
	while(d--){
		ans*=en_msg;
		ans%=n;
	}
	return ans;
}

vector<int> encode(string msg,int e,int n){
	vector<int> v;
	for(int i=0;i<msg.length();i++){
		v.push_back(encrypt(msg[i],e,n));
	}
	return v;
}

string decode(vector<int> encode,int d,int n){
	string s;
	for(int i=0;i<encode.size();i++){
		s+=decrypt(encode[i],d,n);
	}
	return s;
}

int main(){
	int p,q,e,d,n;
	// cout<<"Enter first prime number = ";
	// cin>>p;
	// cout<<"Enter second prime number = ";
	// cin>>q;
	p=181;
	q=19;
	//181,19
	//>7
	//use big prime numbers

	string msg;
	cout<<"Enter the message to decode = ";
	cin>>msg;

	generateKeys(p,q,e,d,n);
	cout<<"Public keys = "<<e<<" "<<n<<endl;
	cout<<"Private keys = "<<d<<" "<<n<<endl;

	
	vector<int> encryptedMsg = encode(msg,e,n);
    cout << "Encrypted message: "<< endl;
    for(int i=0;i<encryptedMsg.size();i++){
    	cout<<encryptedMsg[i];
    }
    cout<<endl;
    
    string decryptedMsg = decode(encryptedMsg,d,n);
    cout << "Decrypted message: " << decryptedMsg << endl;


}
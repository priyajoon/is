#include <bits/stdc++.h>
using namespace std;

int main(){

	char s[]="Hello World";
	int n=strlen(s);

	char and_op[n];
	char or_op[n];
	char xor_op[n];
	cout<<"Performing AND operation"<<endl;
	cout<<"ASCII values = ";
	for(int i=0;i<n;i++){
		cout<<(s[i]&127)<<" ";
	}
	cout<<endl;
	cout<<"Characters = ";
	for(int i=0;i<n;i++){
		and_op[i]=s[i]&127;
		cout<<and_op[i]<<" ";
	}
	cout<<endl;

	cout<<"Performing OR operation"<<endl;
	cout<<"ASCII values = ";
	for(int i=0;i<n;i++){
		cout<<(s[i] | 127)<<" ";
	}
	cout<<endl;
	cout<<"Characters = ";
	for(int i=0;i<n;i++){
		or_op[i]=s[i] | 127;
		cout<<or_op[i]<<" ";
	}
	cout<<endl;

	cout<<"Performing XOR operation"<<endl;
	cout<<"ASCII values = ";
	for(int i=0;i<n;i++){
		cout<<(s[i]^127)<<" ";
	}
	cout<<endl;
	cout<<"Characters = "<<endl;
	for(int i=0;i<n;i++){
		xor_op[i]=s[i]^127;
		cout<<(s[i]^127)<<"  "<<xor_op[i]<<endl;
	}
	cout<<endl;
}
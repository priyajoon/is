#include <bits/stdc++.h>
using namespace std;


string Encryption(int no_rows,int len_key,int len_msg, string msg, int key_col[]){

	int x=0;
	char enc_mat[no_rows+1][len_key];

	for(int i=0;i<no_rows+1;i++){
		for(int j=0;j<len_key;j++){
			if(x>=len_msg){
				enc_mat[i][j]='_';
			}
			else{
				enc_mat[i][j]=msg[x];
			}
			x++;
		}
	}

	
	string cipher="";
	
		for(int k=1;k<=len_key;k++){
			for (int i = 0; i < len_key; i++)
			{
				if(key_col[i]==k){
					for(int j=0;j<no_rows+1;j++){
						cipher+=enc_mat[j][i];
						
					}
					
				}
			
			}
		}
	
	return cipher;
}

string Decryption(int no_rows,int len_key, string cipher, int key_col[]){
	char dec_mat[no_rows+1][len_key];
	int x=0, t=1;

		for(int k=1;k<=len_key;k++){
			for(int i=0;i<len_key;i++){
				if(k==key_col[i]){
					for(int j=0;j< no_rows+1;j++){
						dec_mat[j][i]=cipher[x];
						x++;
					}
					
				}
			}
		}
	
	string message="";
	for(int i=0;i<no_rows+1;i++){
		for(int j=0;j<len_key;j++){
			if(dec_mat[i][j]=='_'){
				dec_mat[i][j]=' ';
			}
			message+=dec_mat[i][j];
		}
	}
	return message;
}


int main(){
	string msg = "Hello World";
    cout<<"Given string = "<<msg<<endl;
  	
    string key = "HACK";
    cout<<"Given key = "<<key<<endl;

    int len_key = key.length();
    int len_msg = msg.length();

    int key_col[len_key];
    for(int i=0;i<len_key;i++){
    	key_col[i]=0;
    }

    
    
    
    int x=1, cnt=0;
    while(cnt<len_key){
    	int min=199;
    	int ind=0;
    	for(int j=0;j<len_key;j++){
    		if( int(key[j])<min && key_col[j]==0 ){
    			min=int(key[j]);
    			ind=j;
    		}
    	}
    	key_col[ind]=x;
    	cnt++;
    	x++;
    }

	for(int i=0;i<len_key;i++){
    	cout<<key_col[i]<<" ";
    }
    cout<<endl;

    int no_rows=len_msg/len_key;
    string cipher_text = " ";
    cipher_text = Encryption(no_rows, len_key, len_msg, msg, key_col);
    cout << "Encrypted Message : " << cipher_text << endl;

	// //decrypted text
    string original_msg = " ";
    original_msg = Decryption(no_rows, len_key, cipher_text,key_col);
    cout << "Decrypted Message : " << original_msg << endl;

}
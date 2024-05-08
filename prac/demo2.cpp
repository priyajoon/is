#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
void generateKeys(int p, int q, int &e, int &d, int &n) {
    n = p * q;
    int phi = (p - 1) * (q - 1);
    e = 2; // Start with e = 2

    // Find e such that e is coprime with phi
    while (__gcd(e, phi) != 1) {
        e++;
    }

    // Find d such that (d * e) % phi == 1
    d = 1;
    while (((d * e) % phi) != 1) {
        d++;
    }
}

long long int encrypt(int msg, int e, int n) {
    long long int result = 1;
    msg = msg % n; // Ensure msg is within range [0, n-1]
    while (e > 0) {
        if (e % 2 == 1)
            result = (result * msg) % n;
        e = e >> 1; // Equivalent to e = e / 2
        msg = (msg * msg) % n;
    }
    return result;
}

int decrypt(int en_msg, int d, int n) {
    long long int result = 1;
    while (d > 0) {
        if (d % 2 == 1)
            result = (result * en_msg) % n;
        d = d >> 1; // Equivalent to d = d / 2
        en_msg = (en_msg * en_msg) % n;
    }
    return result;
}

vector<int> encode(const string& msg, int e, int n) {
    vector<int> v;
    for (char c : msg) {
        v.push_back(encrypt(c, e, n));
    }
    return v;
}

string decode(const vector<int>& encodedMsg, int d, int n) {
    string s;
    for (int num : encodedMsg) {
        s += static_cast<char>(decrypt(num, d, n));
    }
    return s;
}

int main() {
    int p, q, e, d, n;
    cout << "Enter first prime number: ";
    cin >> p;
    cout << "Enter second prime number: ";
    cin >> q;

    string msg;
    cout << "Enter the message to encode: ";
    cin >> msg;

    generateKeys(p, q, e, d, n);
    cout << "Public key (e, n): (" << e << ", " << n << ")" << endl;
    cout << "Private key (d, n): (" << d << ", " << n << ")" << endl;

    vector<int> encryptedMsg = encode(msg, e, n);
    cout << "Encrypted message: ";
    for (int num : encryptedMsg) {
        cout << num << " ";
    }
    cout << endl;

    string decryptedMsg = decode(encryptedMsg, d, n);
    cout << "Decrypted message: " << decryptedMsg << endl;

    return 0;
}

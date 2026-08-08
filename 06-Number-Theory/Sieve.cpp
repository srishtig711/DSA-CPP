#include<iostream>
#include<vector>
using namespace std;

void Sieve(int n) {
    vector<bool> isPrime(n+1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i*i <= n; i++) {
        if(isPrime[i]) {
            for(int j = i*i; j <= n; j += i) {
                isPrime[j] = false;
            }
        } 
    }
    vector<int> prime;
    for(int i = 0; i < isPrime.size(); i++) {
        if(isPrime[i]) {
            prime.push_back(i);
        }
    }
    cout << "Prime numbers upto " << n << " are: ";
    for(int i = 0; i < prime.size(); i++) {
        cout << prime[i] << " ";
    }
    cout << endl;
    cout << "Number of prime numbers upto " << n << " are " << prime.size() << endl;
}

int main() {
    Sieve(10);
    Sieve(40);
    Sieve(50);
    Sieve(100);
    Sieve(350);
    Sieve(1000);
    Sieve(5);
}
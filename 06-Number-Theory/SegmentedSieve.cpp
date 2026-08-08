#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void segmSieve(int n1, int n2) {
    int n = static_cast<int> (sqrt(n2));
    vector<bool> smallPrime(n+1, true);
    smallPrime[0] = false;
    smallPrime[1] = false;
    for(int i = 2; i*i <= n; i++) {
        if(smallPrime[i]) {
            for(int j = i*i; j <= n; j += i) {
                smallPrime[j] = false;
            } 
        }
    }
    vector<int> smalls;
    for(int i = 0; i < smallPrime.size(); i++) {
        if(smallPrime[i]) {
            smalls.push_back(i);
        }
    }
    vector<bool> isPrime(n2-n1+1, true);
    if(n1 == 0) {
        isPrime[0] = false;
        if(n2 >= 1)
            isPrime[1] = false;
    }
    if(n1 == 1) 
        isPrime[0] = false;
    for(int i = 0; i < smalls.size(); i++) {
        int p = smalls[i];
        int firstMultiple = ((n1+p-1)/p)*p;
        int first = max(firstMultiple, p*p);
        for(int j = first; j <= n2; j += p) {
            isPrime[j-n1] = false;
        }
    }
    vector<int> Primes;
    for(int i = 0; i < isPrime.size(); i++) {
        if(isPrime[i]) {
            Primes.push_back(n1+i);
        }
    }
    cout << "Number of prime numbers between " << n1 << " and " << n2 << " are " << Primes.size() << endl;
    cout << "Prime numbers between " << n1 << " and " << n2 << " are ";
    for(int i = 0; i < Primes.size(); i++) {
        cout << Primes[i] << " ";
    }
    cout << endl;
}

int main() {
    segmSieve(30,70);
    segmSieve(40,50);
    segmSieve(1000,3000);
    segmSieve(0,10);
    segmSieve(32,36);
    segmSieve(100,150);
    segmSieve(200,300);
    return 0;
}
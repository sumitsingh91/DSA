// class Solution {
// public:
//     int countPrimes(int n) {
        
//     }
// };

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        
        // Create a boolean array initialized to true
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime numbers
        
        for (int i = 2; i * i < n; ++i) {
            if (isPrime[i]) {
                // Mark multiples of i starting from i * i as non-prime
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        // Count remaining primes
        int count = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                count++;
            }
        }
        
        return count;
    }
};
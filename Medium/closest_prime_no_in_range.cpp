class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        // Sieve of Eratosthenes to find prime numbers up to 'right'
        vector<bool> prime(right + 1, true);
        prime[0] = prime[1] = false;

        for (int p = 2; p * p <= right; p++) {
            if (prime[p]) {
                for (int i = p * p; i <= right; i += p) {
                    prime[i] = false;
                }
            }
        }

        // Finding the closest prime pair
        vector<int> result = {-1, -1};
        int minDiff = INT_MAX;
        int prev = -1;

        for (int i = left; i <= right; i++) {
            if (prime[i]) {
                if (prev == -1) {
                    prev = i;
                } else {
                    if (i - prev < minDiff) {
                        result[0] = prev;
                        result[1] = i;
                        minDiff = i - prev;
                    }
                    prev = i;
                }
            }
        }

        return result;
    }
};

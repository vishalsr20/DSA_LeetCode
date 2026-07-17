class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        // Frequency of each number
        vector<long long> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;

        // cntMultiples[g] = how many numbers are divisible by g
        vector<long long> cntMultiples(mx + 1, 0);

        for (int g = 1; g <= mx; g++) {
            for (int j = g; j <= mx; j += g)
                cntMultiples[g] += freq[j];
        }

        // exactPairs[g] = number of pairs having gcd exactly g
        vector<long long> exactPairs(mx + 1, 0);

        for (int g = mx; g >= 1; g--) {
            long long c = cntMultiples[g];
            exactPairs[g] = c * (c - 1) / 2;

            for (int j = 2 * g; j <= mx; j += g)
                exactPairs[g] -= exactPairs[j];
        }

        // Prefix count of sorted gcd values
        vector<long long> prefix(mx + 1, 0);
        for (int g = 1; g <= mx; g++)
            prefix[g] = prefix[g - 1] + exactPairs[g];

        vector<int> ans;

        for (long long q : queries) {
            int g = lower_bound(prefix.begin() + 1, prefix.end(), q + 1) - prefix.begin();
            ans.push_back(g);
        }

        return ans;
    }
};
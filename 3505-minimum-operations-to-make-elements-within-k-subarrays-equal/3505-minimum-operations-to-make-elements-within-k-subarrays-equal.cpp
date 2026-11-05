class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<int> low, high;
        long long sumLow = 0, sumHigh = 0;

        vector<long long> cost;

        auto balance = [&]() {
            while (low.size() > high.size() + 1) {
                int v = *low.rbegin();
                low.erase(prev(low.end()));
                high.insert(v);

                sumLow -= v;
                sumHigh += v;
            }

            while (low.size() < high.size()) {
                int v = *high.begin();
                high.erase(high.begin());
                low.insert(v);

                sumHigh -= v;
                sumLow += v;
            }
        };

        // Calculate cost of every window of size x
        for (int i = 0; i < n; i++) {
            int v = nums[i];

            if (low.empty() || v <= *low.rbegin()) {
                low.insert(v);
                sumLow += v;
            } else {
                high.insert(v);
                sumHigh += v;
            }

            if (i >= x) {
                int rem = nums[i - x];

                auto it = low.find(rem);

                if (it != low.end()) {
                    low.erase(it);
                    sumLow -= rem;
                } else {
                    it = high.find(rem);
                    high.erase(it);
                    sumHigh -= rem;
                }
            }

            balance();

            if (i >= x - 1) {
                long long median = *low.rbegin();

                long long currCost =
                    median * (long long)low.size() - sumLow +
                    sumHigh - median * (long long)high.size();

                cost.push_back(currCost);
            }
        }

        // DP on array positions
        const long long INF = LLONG_MAX / 4;

        vector<vector<long long>> dp(
            n + 1, vector<long long>(k + 1, INF)
        );

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {

                // Skip current element
                dp[i][j] = dp[i - 1][j];

                // Select a window of size x ending at i-1
                if (i >= x && dp[i - x][j - 1] != INF) {
                    dp[i][j] = min(
                        dp[i][j],
                        dp[i - x][j - 1] + cost[i - x]
                    );
                }
            }
        }

        return dp[n][k];
    }
};
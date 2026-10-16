
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        vector<long long> sum(4 * n);
        vector<long long> sq(4 * n);
        vector<long long> lazy(4 * n);

        auto update = [&](auto&& self, int node, int start,
                          int end, int l, int r) -> void {
            if (l > end || r < start) return;

            if (l <= start && end <= r) {
                long long len = end - start + 1;
                sq[node] = (sq[node] + 2 * sum[node] + len) % MOD;
                sum[node] = (sum[node] + len) % MOD;
                lazy[node]++;
                return;
            }

            int mid = start + (end - start) / 2;

            if (lazy[node]) {
                long long add = lazy[node];

                for (int child : {node * 2, node * 2 + 1}) {
                    int left = (child == node * 2) ? start : mid + 1;
                    int right = (child == node * 2) ? mid : end;
                    long long len = right - left + 1;

                    sq[child] = (sq[child] +
                        2 * add % MOD * sum[child] % MOD +
                        add * add % MOD * len) % MOD;

                    sum[child] = (sum[child] + add * len) % MOD;
                    lazy[child] += add;
                }

                lazy[node] = 0;
            }

            self(self, node * 2, start, mid, l, r);
            self(self, node * 2 + 1, mid + 1, end, l, r);

            sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
            sq[node] = (sq[node * 2] + sq[node * 2 + 1]) % MOD;
        };

        long long ans = 0;
        unordered_map<int, int> last;

        for (int i = 0; i < n; i++) {
            int prev = last.count(nums[i]) ? last[nums[i]] : -1;

            update(update, 1, 0, n - 1, prev + 1, i);

            ans = (ans + sq[1]) % MOD;
            last[nums[i]] = i;
        }

        return ans;
    }
};

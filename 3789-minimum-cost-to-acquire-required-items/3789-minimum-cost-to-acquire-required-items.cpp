
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth,
                          int need1, int need2) {
        
        long long mn = min(need1, need2);
        long long mx = max(need1, need2);

        long long option1 = 1LL * need1 * cost1
                         + 1LL * need2 * cost2;

        long long option2 = mn * costBoth
                          + 1LL * (need1 - mn) * cost1
                          + 1LL * (need2 - mn) * cost2;

        long long option3 = mx * costBoth;

        return min({option1, option2, option3});
    }
};

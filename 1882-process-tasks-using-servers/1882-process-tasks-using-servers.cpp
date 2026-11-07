
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        // {weight, index}
        priority_queue<pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>> available;

        // {finishTime, weight, index}
        using T = tuple<long long, int, int>;

        priority_queue<T, vector<T>, greater<T>> busy;

        for (int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }

        vector<int> ans;

        long long time = 0;

        for (int i = 0; i < m; i++) {

            time = max(time, (long long)i);

            // Release servers whose tasks are completed
            while (!busy.empty() &&
                   get<0>(busy.top()) <= time) {

                auto [finish, weight, index] = busy.top();
                busy.pop();

                available.push({weight, index});
            }

            // If no server is available, jump to
            // the earliest finishing time
            if (available.empty()) {
                time = get<0>(busy.top());

                while (!busy.empty() &&
                       get<0>(busy.top()) <= time) {

                    auto [finish, weight, index] = busy.top();
                    busy.pop();

                    available.push({weight, index});
                }
            }

            // Select the best available server
            auto [weight, index] = available.top();
            available.pop();

            ans.push_back(index);

            // Assign task and calculate finishing time
            busy.push({time + tasks[i], weight, index});
        }

        return ans;
    }
};

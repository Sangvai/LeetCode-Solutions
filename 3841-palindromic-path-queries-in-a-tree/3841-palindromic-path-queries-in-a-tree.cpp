class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> tin(n), tout(n), depth(n);
        vector<vector<int>> up(n, vector<int>(17, 0));
        vector<int> bit(n);
        vector<int> fenwick(n + 2, 0);
        int timer = 0;

        auto update = [&](int i, int val) {
            for (; i <= n; i += i & -i)
                fenwick[i] ^= val;
        };

        auto get = [&](int i) {
            int res = 0;
            for (; i > 0; i -= i & -i)
                res ^= fenwick[i];
            return res;
        };

        function<void(int, int)> dfs = [&](int u, int p) {
            tin[u] = ++timer;
            up[u][0] = p;
            bit[u] = 1 << (s[u] - 'a');

            for (int j = 1; j < 17; j++)
                up[u][j] = up[up[u][j - 1]][j - 1];

            for (int v : adj[u]) {
                if (v == p) continue;
                depth[v] = depth[u] + 1;
                dfs(v, u);
            }

            tout[u] = timer;
        };

        dfs(0, 0);

        for (int u = 0; u < n; u++) {
            update(tin[u], bit[u]);
            update(tout[u] + 1, bit[u]);
        }

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v])
                swap(u, v);

            int diff = depth[u] - depth[v];

            for (int j = 0; j < 17; j++)
                if (diff & (1 << j))
                    u = up[u][j];

            if (u == v) return u;

            for (int j = 16; j >= 0; j--) {
                if (up[u][j] != up[v][j]) {
                    u = up[u][j];
                    v = up[v][j];
                }
            }

            return up[u][0];
        };

        vector<bool> ans;

        for (string& q : queries) {
            stringstream ss(q);
            string op;
            int u, v;
            ss >> op >> u;

            if (op == "update") {
                char c;
                ss >> c;

                int newBit = 1 << (c - 'a');
                int change = bit[u] ^ newBit;

                update(tin[u], change);
                update(tout[u] + 1, change);

                bit[u] = newBit;
                s[u] = c;
            } else {
                ss >> v;

                int w = lca(u, v);
                int mask = get(tin[u]) ^ get(tin[v]) ^ bit[w];

                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};
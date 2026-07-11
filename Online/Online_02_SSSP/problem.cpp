#include <bits/stdc++.h>
using namespace std;

const int INF = 1e18;

bool in_emerg(int i, vector<int> &emg)
{
    for (auto x : emg)
    {
        if (x == i)
            return true;
    }
    return false;
}

void dijkstra_sparse(int source, vector<int> &dist, vector<vector<pair<int, int>>> &graph)
{
    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, source});
    while (!pq.empty())
    {
        auto pr = pq.top();

        int weight = pr.first;
        int node = pr.second;

        pq.pop();

        if (weight > dist[node])
            continue;

        for (auto x : graph[node])
        {
            int wt = x.second;
            int neigh = x.first;

            int newDist = wt + weight;
            if (newDist < dist[neigh])
            {
                dist[neigh] = newDist;
                pq.push({newDist, neigh});
            }
        }
    }
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> emg(k);
    for (int i = 0; i < k; i++)
    {
        cin >> emg[i];
    }
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    for (int i = 1; i <= n; i++)
    {
        vector<int> dist(n + 1, INF);
        if (in_emerg(i, emg))
            cout << 0 << endl;

        else
        {
            dijkstra_sparse(i, dist, graph);
            int cost = INF;
            for (auto x : emg)
            {
                cost = min(dist[x], cost);
            }
            if (cost == INF)
                cout << -1 << endl;
            else
                cout << cost << endl;
        }
    }

    return 0;
}
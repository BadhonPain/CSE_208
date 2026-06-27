#include <bits/stdc++.h>

using namespace std;

bool hasCycle(int source, const vector<vector<int>> &g, vector<bool> &visited, vector<bool> &recStack, stack<int> &st)
{
    visited[source] = true;
    recStack[source] = true;

    for (auto v : g[source])
    {
        if (!visited[v])
        {
            if (hasCycle(v, g, visited, recStack, st))
                return true;
        }
        else if (recStack[v])
            return true;
    }
    recStack[source] = false;
    st.push(source);
    return false;
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> gr(v + 1);
    for (int i = 1; i <= e; i++)
    {
        int a, b;
        cin >> a >> b;
        gr[a].push_back(b);
    }
    vector<bool> visited(v + 1, false);
    vector<bool> recStack(v + 1, false);
    stack<int> st;

    for (int i = 1; i <= v; i++)
    {
        if (!visited[i])
        {
            if (hasCycle(i, gr, visited, recStack, st))
            {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}
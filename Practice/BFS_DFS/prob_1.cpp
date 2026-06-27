#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, int n, int m, const vector<vector<char>> &g, vector<vector<bool>> &visited, int &count)
{
    if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || g[i][j] == '#')
        return;

    visited[i][j] = true;
    count++;

    dfs(i - 1, j, n, m, g, visited, count);
    dfs(i + 1, j, n, m, g, visited, count);
    dfs(i, j - 1, n, m, g, visited, count);
    dfs(i, j + 1, n, m, g, visited, count);
}

int main()
{
    int m, n;
    cin >> m >> n;

    int idx1 = -1, idx2 = -1;
    vector<vector<char>> grph(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grph[i][j];
            if (grph[i][j] == '@')
            {
                idx1 = i;
                idx2 = j;
            }
        }
    }
    int cnt = 0;

    dfs(idx1, idx2, n, m, grph, visited, cnt);
    cout << cnt << endl;
}
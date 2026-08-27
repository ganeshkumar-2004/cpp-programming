#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    int m, n;
    cout << "Enter the number of vertics : ";
    cin >> n;
    cout << endl;

    cout << "Enter the number of edges: ";
    cin >> m;
    cout << endl;

    int INF = 2e9;
    // creat n*n matrix
    vector<vector<int>> dist(n, vector<int>(m, INF));
    // distance between same vertex to same vertex is 0
    for (int i = 0; i < n; i++)
    {
        dist[i][i] = 0;
    }

    // Enput edge :
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cout << " Enter the source and destination and weight also : ";
        cin >> u >> v >> w;
        dist[u][v] = w;
    }
    // print the matrix :
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }

        cout << endl;
    }
    // calcualted the sortest path wetween all pair:
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    cout<<endl;
     // print the matrix :
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}

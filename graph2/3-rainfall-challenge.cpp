#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;

vpii getNeighbors(const vvi &grid, int x, int y) {
    vpii result;
    if (x > 0) result.push_back(make_pair(y, x-1));
    if (y > 0) result.push_back(make_pair(y-1, x));
    if (y < grid.size() - 1) result.push_back(make_pair(y+1, x));
    if (x < grid[0].size() - 1) result.push_back(make_pair(y, x + 1));
    return result;
}
int _getBasins(const vvi &grid, vvi& sink, int x, int y, mii& basins)
{
    if (sink[y][x] > 0)
        return sink[y][x];
    int minx = 6000, miny = 6000, minv = grid[y][x];
    for (auto nbr : getNeighbors(grid, x, y)) {
        if (minv > grid[nbr.first][nbr.second]) {
            minv = grid[nbr.first][nbr.second];
            minx = nbr.second, miny = nbr.first;
        }
    }
    if (minv == grid[y][x]) {
        sink[y][x] = minv;
       
       
    } else {
        sink[y][x] = _getBasins(grid, sink, minx, miny, basins);
        
    }
    basins[sink[y][x]]++;
    return sink[y][x];
}

vi getBasins(const vvi &grid) {
    vi r;
    mii basins;
    vvi sink(grid.size(), vi(grid.size(), -1));
    for (int y = 0; y < grid.size(); y++) {
        for (int x = 0; x < grid[0].size(); x++) {
            if (sink[y][x] == -1)
                sink[y][x] = _getBasins(grid, sink, x, y, basins);
        }
    }
    for (auto rit = basins.begin(); rit != basins.end(); rit++)
        r.push_back(rit->second);
    return r;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vvi grid(n, vi(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    for (auto num : getBasins(grid))
        cout << num << " ";
    return 0;
}

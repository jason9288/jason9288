#include <iostream>
#include <vector>
using namespace std;

int n, m;
int cnt = 0;
bool bonguri;
vector<vector<int>> farm;
vector<vector<bool>> visited;
int drow[8] = {-1,0,1,1,1,0,-1,-1};
int dcol[8] = {1,1,1,0,-1,-1,-1,0};

bool isValid(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= m) return false;
    return true;
}

void checkH(int row, int col, int depth) {
    // cout << endl;
    // cout << depth << " : " << row << ", " << col << "방문 : 높이 " << farm[row][col] << endl;

    visited[row][col] = true;
    int h = farm[row][col];

    // 주변 값들 탐색하며 만약 같은 레벨이면 재귀적으로 집합에 추가
    for (int i = 0; i < 8; i++) {
        int nxt_r = row + drow[i];
        int nxt_c = col + dcol[i];
        if (!isValid(nxt_r, nxt_c)) {
            // cout << depth << " : " << nxt_r << ", " << nxt_c << "는 유효하지 않은 좌표\n";
            continue;
        }
        // cout << depth << " : " <<  row << ", " << col << "의 " << "주변 좌표 탐색 " << nxt_r << ", " << nxt_c << ", 높이 : " << farm[nxt_r][nxt_c] << endl;

        if (farm[nxt_r][nxt_c] > h) {
            // cout << depth << " : 주변에 나보다 높은 좌표 발견\n";
            // 이 집합은 산봉우리가 될 수 없음
            bonguri = false;
        }
        if (farm[nxt_r][nxt_c] == h) {
            if (visited[nxt_r][nxt_c]) {
                // cout << depth << " : 이미 집합에 포함됨\n";
                continue;
            }
            // cout << depth << " : 같은 높이 발견\n";
            checkH(nxt_r, nxt_c, depth+1);
        }
    }
    // cout << depth << " : 현재 bool 값 " << bonguri << endl;
    if (depth == 0 && bonguri) {
        // cout << depth << " : 주변 좌표 탐색 후 높은 좌표 없음; cnt 추가\n";
        cnt++;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    farm.resize(n, vector<int>(m, 0));
    visited.resize(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> farm[i][j];
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << farm[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j]) continue;
            if (farm[i][j] != 0) {
                bonguri = true;
                checkH(i, j, 0);
            }
        }
    }

    cout << cnt;
}
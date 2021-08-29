//https://www.acmicpc.net/problem/2573

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int ice_mountain[301][301] = { 0, };
int cpy_mountain[301][301] = { 0, };
int visited[301][301] = { 0, };
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

struct POSITION {
	int y;
	int x;
};

int main(void) {

	int n, m;

	scanf("%d %d", &n, &m);

	queue<POSITION> q;
	int mountain_cnt = 0;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			scanf("%d", &ice_mountain[y][x]);
			cpy_mountain[y][x] = ice_mountain[y][x];
			if (ice_mountain[y][x] != 0) {
				mountain_cnt += 1;
			}
		}
	}

	int ans = 0;

	if (mountain_cnt > 1) {
		while (1) {
			memset(visited, 0, sizeof(visited));

			int cnt = 0;
			for (int y = 0; y < n; y++) {
				for (int x = 0; x < m; x++) {
					if (ice_mountain[y][x] && !visited[y][x]) {
						cnt += 1;
						queue<POSITION> visit_check;
						visit_check.push({ y,x });
						visited[y][x] = cnt;

						while (!visit_check.empty()) {
							POSITION cur = visit_check.front();
							visit_check.pop();

							for (int dir = 0; dir < 4; dir++) {
								POSITION next;
								next.y = cur.y + dy[dir];
								next.x = cur.x + dx[dir];

								if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= m) continue;

								if (!visited[next.y][next.x] && ice_mountain[next.y][next.x] != 0) {
									visited[next.y][next.x] = visited[cur.y][cur.x];
									visit_check.push(next);
								}
							}
						}
					}
				}
			}

			if (cnt >= 2) break;

			for (int y = 0; y < n; y++) {
				for (int x = 0; x < m; x++) {
					if (ice_mountain[y][x] != 0) {
						q.push({ y,x });
					}
				}
			}

			if (q.size() == 0) {
				ans = 0;
				break;
			}

			ans += 1;
			while (!q.empty()) {
				POSITION cur = q.front();
				q.pop();

				for (int dir = 0; dir < 4; dir++) {
					POSITION next;
					next.y = cur.y + dy[dir];
					next.x = cur.x + dx[dir];

					if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= m) continue;
					if (ice_mountain[next.y][next.x] == 0) {
						if(cpy_mountain[cur.y][cur.x] - 1 >= 0)
							cpy_mountain[cur.y][cur.x] -= 1;
					}
				}
			}

			for (int y = 0; y < n; y++) {
				for (int x = 0; x < m; x++) {
					ice_mountain[y][x] = cpy_mountain[y][x];
				}
			}
		}
	}

	printf("%d", ans);

	return 0;
}
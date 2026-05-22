#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> tubedog[101]; // 관계 표현할 인접 리스트
vector<int> visited(101, 0); // 촌수(거리) 나타내는 1차원 배열

void bfs(int a);

int main() {
	int n, a, b, m;
	cin >> n; // 전체 사람의 수
	cin >> a >> b; // 촌수 계산해야 하는 사람 번호

	cin >> m; // 부모 자식들 간의 관계의 수
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y; // 관계가 1촌인 관계. x가 부모
		tubedog[x].push_back(y);
		tubedog[y].push_back(x);
	}

	bfs(a);

	cout << visited[b] - 1;

}

void bfs(int a) {
	// a에서 b까지 가야함
	queue<int> q;
	q.push(a); visited[a] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < tubedog[now].size(); i++) {
			if (visited[tubedog[now][i]] == 0) {
				visited[tubedog[now][i]] = visited[now] + 1;
				q.push(tubedog[now][i]);
			}
		}
	}
}

/*
Main.cpp: In function ‘int main()’:
Main.cpp:20:17: error: reference to ‘tubedog’ is ambiguous
   20 |                 tubedog[x].push_back(y);
      |                 ^~~~~~~~
In file included from /usr/include/c++/15/compare:42,
                 from /usr/include/c++/15/bits/char_traits.h:58,
                 from /usr/include/c++/15/ios:44,
                 from /usr/include/c++/15/bits/ostream.h:43,
                 from /usr/include/c++/15/ostream:42,
                 from /usr/include/c++/15/iostream:43,
                 from Main.cpp:1:
/usr/include/c++/15/concepts:375:13: note: candidates are: ‘template<class _Rel, class _Tp, class _Up> concept std::tubedog’
  375 |     concept tubedog
      |             ^~~~~~~~
Main.cpp:6:13: note:                 ‘std::vector<int> tubedog [101]’
    6 | vector<int> tubedog[101]; // 관계 표현할 인접 리스트
      |             ^~~~~~~~
Main.cpp:21:17: error: reference to ‘tubedog’ is ambiguous
   21 |                 tubedog[y].push_back(x);
      |                 ^~~~~~~~
/usr/include/c++/15/concepts:375:13: note: candidates are: ‘template<class _Rel, class _Tp, class _Up> concept std::tubedog’
  375 |     concept tubedog
      |             ^~~~~~~~
Main.cpp:6:13: note:                 ‘std::vector<int> tubedog [101]’
    6 | vector<int> tubedog[101]; // 관계 표현할 인접 리스트
      |             ^~~~~~~~
Main.cpp: In function ‘void bfs(int)’:
Main.cpp:39:37: error: reference to ‘tubedog’ is ambiguous
   39 |                 for (int i = 0; i < tubedog[now].size(); i++) {
      |                                     ^~~~~~~~
/usr/include/c++/15/concepts:375:13: note: candidates are: ‘template<class _Rel, class _Tp, class _Up> concept std::tubedog’
  375 |     concept tubedog
      |             ^~~~~~~~
Main.cpp:6:13: note:                 ‘std::vector<int> tubedog [101]’
    6 | vector<int> tubedog[101]; // 관계 표현할 인접 리스트
      |             ^~~~~~~~
Main.cpp:40:37: error: reference to ‘tubedog’ is ambiguous
   40 |     
*/
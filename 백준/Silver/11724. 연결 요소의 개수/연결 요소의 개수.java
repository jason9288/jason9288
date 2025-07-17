import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int[][] graph;
    static boolean visited[];
    static int N, M;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        int u, v;
        graph = new int[N+1][N+1];
        visited = new boolean[N+1];

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            u = Integer.parseInt(st.nextToken());
            v = Integer.parseInt(st.nextToken());
            graph[u][v] = 1;
            graph[v][u] = 1;
        }

        int res = 0;

        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                dfs(i);
                res++;
            }
        }

        System.out.println(res);
    }
    public static void dfs(int idx) {
        if (visited[idx]) {
            return; // 인접해있으나 이미 방문함 :: 연결 요소의 정점 모두 탐색됨
        } else {
            visited[idx] = true;
            for (int i = 1; i <= N; i++) {
                if (graph[idx][i] == 1) {
                    dfs(i);
                }
            }
        }
    }
}
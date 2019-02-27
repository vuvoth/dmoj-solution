import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class valentines18s5 {
    static class solution {
        int n, k;
        int a[] = new int[1000000];
        FastReader Input = new FastReader();
        int cnt[] = new int[1000000];
        int tree[] = new int[4000000];
        int spTable[][] = new int[21][1000000];
        int Log[] = new int[1000001];

        public int gcd(int a, int b) {
            BigInteger b1 = BigInteger.valueOf(a);
            BigInteger b2 = BigInteger.valueOf(b);
            BigInteger gcd = b1.gcd(b2);
            return gcd.intValue();
        }

        void initSpTable() {
            for (int i = 0; i < n; ++i) {
                spTable[0][i] = a[i];
            }
            Log[1] = 0;
            for (int i = 2; i <= n; ++i) {
                Log[i] = Log[i / 2] + 1;
            }
            for (int j = 1; (1 << j) < n; ++j) {
                for (int i = 0; i + (1 << j) - 1 < n; ++i)
                    spTable[j][i] = gcd(spTable[j - 1][i], spTable[j - 1][i + (1 << (j - 1))]);
            }
        }

        Integer query(int l, int r) {
            int k = Log[r - l + 1];
//            System.out.println(k);
            return gcd(spTable[k][l], spTable[k][r - (1 << k) + 1]);
        }

        void input() {
            n = Input.nextInt();
            k = Input.nextInt();
            for (int i = 0; i < n; ++i) {
                a[i] = Input.nextInt();
            }
        }

        void init_tree(int l, int r, int node) {
            if (l == r) {
                tree[node] = a[l];
            } else {
                int m = (l + r) / 2;
                init_tree(l, m, node * 2);
                init_tree(m + 1, r, node * 2 + 1);
                tree[node] = gcd(tree[node * 2], tree[node * 2 + 1]);
            }
        }

        int query(int l, int r, int u, int v, int node) {
            if (r < u || l > v)
                return 0;
            if (l >= u && r <= v)
                return tree[node];
            int m = (l + r) / 2;
            int nL = query(l, m, u, v, node * 2);
            int nR = query(m + 1, r, u, v, node * 2 + 1);
            return gcd(nL, nR);
        }

        int check(int l, int r, int k) {
            int g = query(l, r);
            return cnt[g] - k;
        }

        int left_side(int l, int r, int k) {
            int p = l;
            while (l <= r) {
                int m = (l + r) / 2;
                if (check(p, m, k) > 0)
                    l = m + 1;
                else
                    r = m - 1;
            }
            return l;
        }

        int right_side(int l, int r, int k) {
            int p = l;
            while (l <= r) {
                int m = (l + r) / 2;
                if (check(p, m, k) >= 0)
                    l = m + 1;
                else
                    r = m - 1;
            }
            return l;
        }

        void process() {
            long ans = 0;
            int right = n - 1;
            int left = n - 1;
            for (int i = 0; i < n; ++i) {
                left = left_side(i, n - 1, k);
                right = right_side(i, n - 1, k);
                ans += right - left;
            }
            System.out.println(ans);
        }

        void init() {
            for (int i = 1; i <= 100000; ++i) {
                cnt[i] = 0;
            }

            for (int i = 2; i <= 100000; ++i) {
                if (cnt[i] == 0)
                    for (int j = i; j <= 100000; j += i) {
                        int h = j;
                        while (h % i == 0) {
                            h /= i;
                            cnt[j]++;
                        }
                    }
            }

        }

        void sol() {
            input();
            init();
            initSpTable();
            process();
        }

    }

    public static void main(String[] args) {
        solution pro = new solution();
        pro.sol();
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        private FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
            st = null;
        }

        String next() {
            while (st == null || !st.hasMoreElements()) try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

    }
}

import java.util.Scanner;

/**
 * @author Yashodhan Ghadge
 */
public class SubsetSum {

    private static boolean subsetSum(int N, int[] arr, int sum){
        boolean[][] ss = new boolean[sum  + 1][N + 1];


        // all the zero element subsets are false
        for (int i = 0; i <= sum; i++) {
            ss[i][0] = false;
        }

        // all subsets with sum 0 are true
        for (int i = 0; i <= N; i++) {
            ss[0][i] = true;
        }

        for(int i = 1; i<= sum; i++){
            for (int j = 1; j<= arr.length; j++){
                // this is basically not picking the current number at arr[j] in the subset sum
                ss[i][j] = ss[i][j-1];
                // this means that the current subset sum we are working on is greater than the number at arr[j-1], so
                // it means that we have 2 options
                // 1. not pick the current number at arr[j]
                // 2. pick it
                if (i >= arr[j-1]){
                    ss[i][j] = ss[i][j]
                            ||
                            // we look for i = arr[j-1] cause, we are looking for the subset sum result upto the
                            // last element
                            ss[i - arr[j-1]][j-1];
                }
            }
        }

        return ss[sum][arr.length];

    }


    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int sum = sc.nextInt();
        int n = sc.nextInt();

        int[] data = new int[n];

        for (int i = 0; i < n; i++) {
            data[i] = sc.nextInt();
        }
        System.out.println(subsetSum(n, data, sum));


    }





}

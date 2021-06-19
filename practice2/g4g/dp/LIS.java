import java.io.*;
import java.util.*;

/**
 * 5
 * 3
 * 5 1 6
 * 3
 * 1 3 7
 * 16
 * 0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
 * 5
 * 10 2 30 4 1
 * 6
 * 5 8 3 7 9 1
 */
public class LIS {

    private static void process(int size, int[] a) {

        var lis = new ArrayList<Integer>();
        lis.add(0,1);

        for (int i=1; i< a.length; i++) {
            int c = -1;
            for (int j = 0; j < i; j++) {
                if (a[i] > a[j]) {
                     c = Math.max (c, lis.get(j));
                }
            }
            if (c == -1) {
                lis.add(1);
            } else {
                lis.add(c+1);
            }
        }
        System.out.println("lis:" + lis);
        System.out.println(Collections.max(lis));
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        System.out.println("t is: " + t);

        for (int i = 0; i < t; i++) {
            System.out.println("=== t = " + i + " ===");
            int n = sc.nextInt();
            System.out.println("N is: " + n);
//            ArrayList<Integer> a = new ArrayList<>();
            int[] a = new int[n];
            for (int j = 0; j < n; j++) {
                a[j] = sc.nextInt();
            }

            System.out.println(Arrays.toString(a));
            process(a.length, a);
        }
    }
}
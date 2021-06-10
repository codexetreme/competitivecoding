import java.io.*;
import java.util.*;

public class LIS {

    private static void process(List<Integer> a) {

        var lis = new ArrayList<Integer>();

        lis.add(0);
        lis.set(0,5);


    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        System.out.println("t is: " + t);

        for (int i = 0; i < t; i++) {
            int n = sc.nextInt();
            System.out.println("N is: " + n);
            ArrayList<Integer> a = new ArrayList<>();
            for (int j = 0; j < n; j++) {
                a.add(sc.nextInt());
            }
            System.out.println(a);
//            process(a);
        }
    }
}
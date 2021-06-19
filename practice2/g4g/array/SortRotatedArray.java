import java.util.*;

class SortRotatedArray {

    private static int t;
    private static boolean binarySearch(ArrayList<Integer> a, int l, int h) {
        if (h < l) return false;

        int mid = l + (h-l)/2;
        if (a.get(mid) == t) return true;

        if (a.get(mid)< t) return binarySearch(a, mid + 1, h);
        return binarySearch(a, l, mid - 1);

    }


    private static int findPivot(ArrayList<Integer> a, int l, int h ){

        if (h < l) return -1; // un rotated array

        if (l == h) return l;

        int mid = l + (h-l)/2;

        if (mid < h && a.get(mid)> a.get(mid + 1)) return mid;
        if (mid > l && a.get(mid - 1) > a.get(mid)) return mid - 1;

        // mid val is greater than end val, so we go to the right
        if (a.get(mid) >= a.get(h)) return findPivot(a, mid + 1, h);
        // otherwise go left
        return findPivot(a, l, mid - 1);
    }


    private static boolean process(ArrayList<Integer> a, int t){

        int pivot = findPivot(a, 0, a.size()-1);
        System.out.println("pivot "+  pivot);
//        return binarySearch(a, 0, a.size()-1);
        if (pivot == -1) return binarySearch(a, 0, a.size()-1);

        if (a.get(pivot) == t) return true;

        if (t > a.get(0)) return binarySearch(a, 0, pivot - 1);
        return binarySearch(a, pivot + 1, a.size()-1);


    }

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        t = sc.nextInt();

        ArrayList<Integer> a = new ArrayList<>();

        for (int i = 0; i <n; i++) {
            int temp = sc.nextInt();
            a.add(temp);
        }
        System.out.println(t);
        System.out.println(process(a, t));

    }
}
import java.util.*;

/**
 * @author Yashodhan Ghadge
 */
public class deleteAndEarn {

    class Num {
        int val;
        int count;

        public Num(int val, int count) {
            this.val = val;
            this.count = count;
        }

        @Override
        public String toString() {
            return new StringBuilder("{ val: ").append(val).append(". count:").append(count).append("}").toString();
        }

    }

    HashMap<Integer, Integer> cnt = new HashMap<>();

    private int calcScore(int num) {
        if (cnt.containsKey(num)){
            int score = cnt.get(num) * num;
            cnt.remove(num - 1);
            cnt.remove(num + 1);
            cnt.remove(num);
            return score;
        }
        return 0;
    }

    public int deleteAndEarn(int[] nums) {


        for (int i = 0; i < nums.length; i++) {
            if (!cnt.containsKey(nums[i])) {
                cnt.put(nums[i], 1);
            } else {
                int val = cnt.get(nums[i]);
                cnt.put(nums[i], val + 1);
            }
        }

        PriorityQueue<Num> countPq = new PriorityQueue<>((o1, o2) -> Integer.compare(o2.count, o1.count));

        for (var kv : cnt.entrySet()) {
            countPq.add(new Num(kv.getKey(), kv.getValue()));
        }

        int sum = 0;
        while (!cnt.isEmpty()) {
            Num top = countPq.poll();
            if (top == null) break;
            PriorityQueue<Integer> valSorted = new PriorityQueue<>(Comparator.reverseOrder());

            valSorted.add(top.val);

            while (true) {
                Num temp = countPq.peek();
                if (temp != null && (temp.count == top.count)) {
                    valSorted.add(temp.val);
                    countPq.poll();
                } else {
                    break;
                }
            }

            while (!valSorted.isEmpty()) {
                sum += calcScore(valSorted.poll());
            }


        }

        return sum;
    }


}

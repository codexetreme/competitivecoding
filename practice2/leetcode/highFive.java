import com.sun.jdi.connect.AttachingConnector;

import java.util.*;
import java.util.stream.Collectors;

public class highFive {
    HashMap<Integer, scr> l;

    class scr implements Comparable<scr>{
        public int id;
        List<Integer> scores;
        public scr(int id){
            this.id = id;
            this.scores = new ArrayList<>();
        }

        public void Add(int score){
            this.scores.add(score);
        }


        public int getTop5avg(){
            this.scores.sort(Comparator.reverseOrder());
            int sum = 0;
            for(int i=0; i<5; i++){
                sum += this.scores.get(i);
            }
            return sum/5;
        }

        public int compareTo(scr b){
            return Integer.compare(this.id, b.id);
        }
    }


    public int[][] highFive(int[][] items) {
        l = new HashMap<>();

        for (int i=0; i<items.length; i++) {
            int id = items[i][0];
            int score = items[i][1];

            if (l.containsKey(id)){
                l.get(id).Add(score);
            }
            else {
                scr r = new scr(id);
                r.Add(score);
                l.put(id, r);

            }
        }



        int[][] a = new int[l.size()][2];

        List<scr> sorted = new ArrayList<>();

        for (var v : l.entrySet()){
            sorted.add(v.getValue());
        }

        sorted.sort(Comparator.naturalOrder());

        for (int i=0; i<sorted.size(); i++){
            a[i][0] = sorted.get(i).id;
            a[i][1] = sorted.get(i).getTop5avg();
        }
        return a;


    }
    public static int main(String[] args) {
        return 0;
    }

}




import java.util.*;

/**
 * LSDBOFDMXJJYYFKROILT
 * UIEVCFFIGZRTRVUHCAUCL
 * ABCDGH
 * AEDFHR
 * AGGTAB
 * GXTXAYB
 * string 1
 * string 2
 *
 *
 *
 * What follows here is my approach to the rather popular question
 * https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
 * @author Yashodhan Ghadge
 */

public class LCS {

    private static int getFirstOccurrence(String str, char char_, int startIdx){

        for (int i = startIdx; i < str.length(); i++) {
            if (str.charAt(i) == char_){
                return i;
            }
        }
        return -1;
    }

    private static int buildMap(String src, String target) {
        int latestCount = -1; // start at 0
        int matchLen = 0;

        for (int i = 0; i < src.length(); i++) {
            int firstOccurence = getFirstOccurrence(target, src.charAt(i), latestCount + 1);
            if (firstOccurence != -1){ // valid occurrence
                latestCount = firstOccurence;
                matchLen +=1;
            }
        }
        return matchLen;
    }

    private static int lcs(String s1, String s2){
        int len2 = buildMap(s2, s1);
        int len1 = buildMap(s1, s2);

        return Math.max(len1, len2);
    }


    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String s1 = sc.nextLine();
        String s2 = sc.nextLine();
        System.out.println(s1);
        System.out.println(s2);
        System.out.println(lcs(s1, s2));
    }


}

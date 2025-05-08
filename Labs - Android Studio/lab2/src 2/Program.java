import java.util.*;

public class Program {
	public static int[] scale(int[] arr, int s) {
        int[] scaledArray = new int[arr.length];

        for (int i = 0; i < arr.length; i++) {
            scaledArray[i] = arr[i] * s;
        }

        return scaledArray;
    }

    public static void main(String[] args) {
        int[] toSend = {4, 9, 2, 7};

        int[] result = scale(toSend, 4);

        System.out.println(result[1]); 
    }
}

import java.util.*;

public class Program {
	 public static int getX(String coordinates) {
	        String[] parts = coordinates.split(",");

	        return Integer.parseInt(parts[0]);
	    }

	    public static int getY(String coordinates) {
	        String[] parts = coordinates.split(",");
	        
	        return Integer.parseInt(parts[1]);
	    }

	    public static int getXDistance(String coordinates1, String coordinates2) {
	        int x1 = getX(coordinates1);
	        int x2 = getX(coordinates2);

	        return Math.abs(x1 - x2);
	    }

	    public static void main(String[] args) {
	    	Scanner in = new Scanner(System.in);
	        String coord1 = in.nextLine();
	        String coord2 = in.nextLine();
	        int distance = getXDistance(coord1, coord2);
	        System.out.println(distance); 
	    }
}

import java.util.Scanner;

public class Program {
	
	public static int multiply(int x,int y) {
		return x * y;
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

        int firstInteger = in.nextInt();

        int secondInteger = in.nextInt();

        int product = multiply(firstInteger, secondInteger);
        
        System.out.println(product);
	}
}

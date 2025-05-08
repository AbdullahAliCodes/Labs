import java.util.Scanner;

public class Program{
    public static void main(String args[]){
        Scanner in =new Scanner(System.in);
        String line = in.nextLine();
        char second_char = line.charAt(1);
        System.out.println(second_char);
    }
}
import java.util.Scanner;

public class Program{
    public static void main(String args[]){
        Scanner in =new Scanner(System.in);
        String s = in.nextLine();
        int i = Integer.parseInt(s);

        if (i%3 == 0){
            System.out.println(true);
        }
        else{
            System.out.println(false);
        }
    }
}
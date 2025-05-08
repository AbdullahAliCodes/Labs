import java.util.Scanner;

public class Examplea {


 public static void main(String [] args){

     String name;
     Scanner in = new Scanner(System.in);
     System.out.println("Please enter your name in full: ");

     name=in.nextLine();
     System.out.print("Hello there: ");
     System.out.print(name);
     System.out.println();
 }
}

import java.util.*;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Sohel_Client {
   private Sohel_Client() {
   }

   public static void main(String[] args) {
      try {
         // Getting the registry
         Registry registry = LocateRegistry.getRegistry(null);

         // Looking up the registry for the remote object
         FactorialInterface stub = (FactorialInterface) registry.lookup("FactorialInterface");

         // Calling the remote method using the obtained object
         while (true) {
            Scanner sc = new Scanner(System.in); // System.in is a standard input stream.
            System.out.print("Enter a number: ");
            int a = sc.nextInt();
            System.out.println(stub.factorial(a));
         }
      } catch (Exception e) {
         System.err.println("Client exception: " + e.toString());
         e.printStackTrace();
      }
   }
}
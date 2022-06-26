import java.rmi.Remote;
import java.rmi.RemoteException;

// Creating Remote interface for our application
public interface FactorialInterface extends Remote {
    int factorial(int n) throws RemoteException;
}

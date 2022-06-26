// Implementing the remote interface
public class Factorial implements FactorialInterface {

    // Implementing the interface method
    public int factorial(int n) {
        int i, fact = 1;
        if (n < 0)
            return -1;

        for (i = 1; i <= n; i++) {
            fact = fact * i;
        }
        return fact;
    }
}
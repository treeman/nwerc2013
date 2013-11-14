// Catalan numbers with BigInteger
import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static BigInteger[] mem;

    public static BigInteger cat(int n) {
        if (n == 0) return BigInteger.ONE;
        if (mem[n] != null) return mem[n];

        BigInteger k = BigInteger.valueOf(2 * (2 * n - 1)).multiply(cat(n - 1));
        return mem[n] = k.divide(BigInteger.valueOf(n + 1));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        mem = new BigInteger[11]; // adjust as necessary
        while (sc.hasNextInt()) {
            System.out.println(cat(sc.nextInt()));
        }
    }
}



public class eratosthenes {

	public static void main(String[] args) {
		System.out.println(eratosthenes(10000));
	}
	
	public static int eratosthenes(int n) {
		if(n>0 && n<=3)
			return n-1;
		else if(n<0)
			return 0;
		
		System.out.println(n);
		
		boolean[] primes = new boolean[n];
		primes[0] = false;
		
		for(int i = 1; i < primes.length; i++) {
			if(i%2==1)
				primes[i] = true;
		}
		
		int numPrimes = 0;
		for(int i = 3; i < Math.sqrt(n); i+=2) {
			if(primes[i])
				for(int j = i*i; j < n; j+=2*i)
					primes[j] = false;
		}
		
		for(boolean p : primes)
			if(p)
				numPrimes++;
		
		return numPrimes;
	}

}

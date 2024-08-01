import java.util.Scanner;
public class ReportChapter04 {
	static void method1() {
		Scanner scanner = new Scanner(System.in);
		Account1 account1 = new Account1("account1");
		Account1 account2 = new Account1("account2");
		System.out.print("Enter deposit amount for "+account1.getName()+": ");
		account1.setBalance(scanner.nextDouble());
		System.out.println(account1.getName()+" balance: "+account1.getBalance());
		System.out.print("Enter deposit amount for "+account2.getName()+": ");
		account2.setBalance(scanner.nextDouble());
		System.out.println(account2.getName()+" balance: "+account2.getBalance());
		System.out.println();
	}
	static void method2() {
		Account1 account = new Account1("홍길동");
		account.credit(1000.0);
		account.print();
		
		account.addInterest(0.011);
		account.print();
		System.out.println();
	}
	static void method3() {
		Scanner scanner = new Scanner(System.in);
		int a,b,Sum,Product,Difference,Quotient;
		System.out.print("Enter first integer: ");
		a = scanner.nextInt();
		System.out.print("Enter second integer: ");
		b = scanner.nextInt();
		Sum = a+b;
		Product = a*b;
		Difference = a-b;
		Quotient = a/b;
		System.out.println();
		System.out.println("Sum is "+Sum);
		System.out.println("Product is "+Product);
		System.out.println("Difference is "+Difference);
		System.out.println("Quotient is "+Quotient);
		scanner.close();
	}
	public static void main(String[]args) {
		method1();
		method2();
		method3();
	}
}

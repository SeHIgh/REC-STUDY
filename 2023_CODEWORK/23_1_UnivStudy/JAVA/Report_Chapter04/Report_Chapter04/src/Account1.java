public class Account1 {
	private String name;
	private double balance;
	
	public Account1(String n){
		name = n;
		balance = 0.0;
	}
	public String getName(){
		return name;
	}
	public double getBalance(){
		return balance;
	}
	public void setBalance(double balance) {
		this.balance = balance;
	}
	public void credit(double b){
		balance += b;
	}
	public void print(){
		System.out.println("예금주 : "+name);
		System.out.println("잔액 : "+balance);
	}
	public void addInterest(double interestRates){
		balance += balance*interestRates;
	}
}
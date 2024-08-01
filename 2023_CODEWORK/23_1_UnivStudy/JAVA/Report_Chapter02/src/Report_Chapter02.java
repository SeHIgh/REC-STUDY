import java.util.Scanner;

public class Report_Chapter02 {
	public static void main(String[]args) {
		method1();
		method2();
	}
	static void method1() {
		Scanner scanner = new Scanner(System.in);
		int score;
		char credit;
		System.out.print("성적을 입력하시오: ");
		score = scanner.nextInt();
		switch(score/10) {			//점수를 10으로 나눈 몫이 10,9->A, 8->B...로 판단
		case 10: case 9:
			credit = 'A';
			break;
		case 8:
			credit = 'B';
			break;
		case 7:
			credit = 'C';
			break;
		case 6:
			credit = 'D';
			break;
		default :
			credit = 'F';
		}
		System.out.println("학점: "+credit);
		//scanner.close();		
		//method1에서 scanner을 close하니 method2에서 scanner관련 오류가 생겨 주석처리 하였습니다.
	}
	static void method2() {
		Scanner scanner = new Scanner(System.in);
		System.out.print("일수를 알고 싶은 월을 입력하시오: ");
		int month = scanner.nextInt();
		int day = 0;
		switch(month) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			day = 31;
			break;
		case 4: case 6: case 9: case 11:
			day = 30;
			break;
		case 2:
			day = 28;
			break;
		}
		System.out.print("월의 날수는: "+day);
		scanner.close();
	}
}

import java.util.Scanner;

public class Report_Chapter03 {
	//점수를 입력받고 합계와 평균 구하기
	static void method1() {
		Scanner scanner = new Scanner(System.in);
		int grade, cnt=0,sum=0, average;
		while(true) {
			System.out.print("Enter grade: ");
			grade = scanner.nextInt();
			if (grade>=0) {
				cnt++;
				sum+=grade;
			}
			else break;
		}
		if(cnt != 0) {
			average = sum/cnt;
			System.out.println();
			System.out.println("Total of "+cnt+" student grades is "+sum);
			System.out.println("Class average is "+average);
			
		}
		else {
			System.out.println("ERROR : 입력된 점수가 없습니다.");
		}
		//scanner.close(); //메인에서의 출력을 위해
	}
	//학점 출력하기
	static void method2() {
		Scanner scanner = new Scanner(System.in);
		int grade, cnt=0;
		int grade_cnt[] = {0,0,0,0,0};	//A,B,C,D,F count 배열 생성
		while(true) {
			System.out.print("Enter grade: ");
			grade = scanner.nextInt();
			
			if(grade >= 0) {
				switch(grade/10) {
				case 10: case 9: grade_cnt[0]++;	//A
				break;									
				case 8: grade_cnt[1]++;				//B
				break;
				case 7: grade_cnt[2]++;				//C
				break;
				case 6: grade_cnt[3]++;				//D
				break;
				default : grade_cnt[4]++;			//F
				}
			}
			else break;
		}
		System.out.println();
		System.out.println("Number of students who received each grade:");
		System.out.println("A: "+grade_cnt[0]);
		System.out.println("B: "+grade_cnt[1]);
		System.out.println("C: "+grade_cnt[2]);
		System.out.println("D: "+grade_cnt[3]);
		System.out.println("F: "+grade_cnt[4]);
		
		//scanner.close(); //메인에서의 출력을 위해
	}
	//돈 액수 계산
	static void method3() {
		Scanner scanner = new Scanner(System.in);
		int money, temp; 
		System.out.print("금액을 입력하시오 : ");
		money = scanner.nextInt();
		temp = money;
		if(money > 0) {
			while(temp>0) {
				if(temp>=50000) {
					System.out.println("오만원권 "+temp/50000+"매");
					temp -= 50000*(temp/50000);
				}
				else if(temp>=10000) {
					System.out.println("만원권 "+temp/10000+"매");
					temp -= 10000*(temp/10000);
				}
				else if(temp>=1000) {
					System.out.println("천원권 "+temp/1000+"매");
					temp -= 1000*(temp/1000);
				}
				else if(temp>=500) {
					System.out.println("오백원 "+temp/500+"개");
					temp -= 500*(temp/500);
				}
				else if(temp>=100) {
					System.out.println("백원 "+temp/100+"개");
					temp -= 100*(temp/100);
				}
				else if(temp>=50) {
					System.out.println("오십원 "+temp/50+"개");
					temp -= 50*(temp/50);
				}
				else if(temp>=10) {
					System.out.println("십원 "+temp/10+"개");
					temp -= 10*(temp/10);
				}
				else {
					System.out.println("일원 "+temp+"개");
					temp -= 10*(temp);
				}
			}
		}	
		scanner.close();
	}
	public static void main(String[]args) {
		method1();
		method2();
		method3();
	}
}

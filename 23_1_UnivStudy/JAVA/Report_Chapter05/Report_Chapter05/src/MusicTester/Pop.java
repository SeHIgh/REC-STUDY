package MusicTester;

public class Pop extends Music {
	private String singer;

	public Pop(String name, int year, String singer) {
		super(name,year);
		this.singer = singer;
	}
	
	@Override
	public String toString() {
		return "Pop [곡명=" + super.name + ", 연도=" + super.year + ", 가수=" + singer + "]";
	}
}

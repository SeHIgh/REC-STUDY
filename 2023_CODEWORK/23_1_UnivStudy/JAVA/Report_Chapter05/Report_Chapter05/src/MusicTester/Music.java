package MusicTester;

public class Music {
	protected String name;
	protected int year;
	public Music(String name, int year) {
		this.name = name;
		this.year = year;
	}
	public String toString() {
		return "Music [곡명=" + name + ", 연도=" + year + "]";
	}
}
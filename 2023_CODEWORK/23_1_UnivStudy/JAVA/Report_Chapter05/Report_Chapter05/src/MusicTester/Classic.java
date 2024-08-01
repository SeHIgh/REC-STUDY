package MusicTester;

public class Classic extends Music {
	private String composer;
	
	public Classic(String name, int year, String composer) {
		super(name,year);
		this.composer = composer;
	}
	
	@Override
	public String toString() {
		return "Classic [곡명=" + super.name + ", 연도=" + super.year + ", 작곡가=" + composer + "]";
	}
}
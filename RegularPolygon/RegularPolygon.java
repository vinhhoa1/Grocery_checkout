public class RegularPolygon {
private int n ;
private double side ;
private double x ;
private double y ;
// no arg constructor
	public RegularPolygon() {
		n = 3;
		side = 1;
		x = 0;
		y = 0;
		
	}
	public RegularPolygon(int n, double side)
	{
		this.n = n;
		this.side = side;
		this.x = 0;
		this.y = 0;
		
	}
	public RegularPolygon(int n, double side,double x, double y)
	{
		this.n = n;
		this.side = side;
		this.x = x;
		this.y = y;
		
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
	// Test 1st constructor
		RegularPolygon test1 = new RegularPolygon();
		System.out.println("Test 1: ");
System.out.println("n = " + test1.n);
System.out.println("side =: " + test1.side);
System.out.println("x = " + test1.x);
System.out.println("y = " + test1.y);
System.out.println("Perimeter = " + test1.getPerimeter());
System.out.println("Area = " + test1.getArea());

//Test 2nd constructor
		RegularPolygon test2 = new RegularPolygon(6,4);
		System.out.println("Test 2: ");
System.out.println("n = " + test2.getn());
System.out.println("side = " + test2.getside());
System.out.println("x = " + test2.getx());
System.out.println("y = " + test2.gety());
System.out.println("Perimeter = " + test2.getPerimeter());
System.out.println("Area = " + test2.getArea());
//Test 3th constructor
RegularPolygon test3 = new RegularPolygon(10,4,5.6,7.8);
System.out.println("Test 3: ");
System.out.println("n = " + test3.getn());
System.out.println("side = " + test3.getside());
System.out.println("x = " + test3.getx());
System.out.println("y = " + test3.gety());
System.out.println("Perimeter = " + test3.getPerimeter());
System.out.println("Area = " + test3.getArea());
	}

	// Accessor and mutator 
	public int getn(){return n;} 
	public double getside(){return side;} 
	public double getx(){return x;} 
	public double gety(){return y;} 
	
	public void setn(int n){this.n = n;} 
	public void  setside(double side){this.side = side;} 
	public void  setx(double x){this.x = x;} 
	public void sety(double y){this.y = y;} 
// Methods
	
	double getPerimeter(){
		return n*side;
	}
	double getArea(){
	return (n*side*side)/ (4* Math.tan(Math.PI / n));	
	}
}

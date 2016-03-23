
public class Circle2D {
double x;
double y;
double radius;

double getx(){return x;}
double gety(){return y;}
double getradius(){return radius;};
	public Circle2D() {
		// TODO Auto-generated constructor stub
		x = 0;
		y = 0;
		radius = 1;
		
	}
	public Circle2D(double x, double y, double radius) {
		this.x = x;
		this.y = y;
		this.radius = radius;
	}
	double getArea(){
		return Math.PI*radius*radius;
	}
	double getPerimeter(){
		return 2*Math.PI*radius;
	}
	boolean contains(double x, double y){
		if(Math.pow(2,x - getx()) + Math.pow(2, y-gety()) < (radius * radius))
				{
			return true;
				}
		else
			return false;
	}
	boolean contains(Circle2D circle){
		double distance;
		distance = Math.sqrt((circle.x-getx())*(circle.x-getx()) + (circle.y-gety())*(circle.y-gety()));
		if(distance <= Math.abs(circle.radius - getradius()))
		{
			return true;
		}
		else
			return false;
	}
	boolean overlaps(Circle2D circle){
		double distance;
		distance = Math.sqrt((circle.x-getx())*(circle.x-getx()) + (circle.y-gety())*(circle.y-gety()));
		if(distance <= Math.abs(circle.radius + getradius()))
		{
			return true;
		}
		else
			return false;
		 
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
// Test no arg constructor
		Circle2D c1 = new Circle2D(2,2,5.5);
		System.out.println("c1: ");
		System.out.println("x = " + c1.getx());
		System.out.println("y = " + c1.gety());
		System.out.println("radius = " + c1.getradius());
		System.out.println("result of c1.contains(3,3) : " + c1.contains(3,3));
		System.out.println("result of c1.contains(new Circle2D(4, 5, 10.5)), : " + c1.contains(new Circle2D(4, 5, 10.5)));
		System.out.println("result of c1.containsc1.overlaps(newCircle2D(3, 5, 2.3)), : " + c1.contains(new Circle2D(3, 5, 2.3)));
		
	}
	

}

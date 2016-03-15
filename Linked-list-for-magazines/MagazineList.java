import java.util.Scanner;
// Name: Hoa P Nguyen
// Linked list Project 1
//CS3345.003
// All function work
// IDE : Eclipse, JavaSE 1.8

public class MagazineList {
	public  Magazine head;
	public static MagazineList magl;
	MagazineList() {
		
	} // constructor 
	void makeEmpty() {
		
		magl.head = null;
		
	} //empties the linked list
	Magazine findID(int ID) {
		Magazine temp = magl.head;
		while(temp!=null){
			if(temp.magazineID == ID)
				{temp.print(); return temp;}
			temp = temp.next;
		}
		System.out.println("ID not found. ");
		return null;
	} // don’t remove the object // return null if the list is empty or ID not found
	 boolean insertAtFront(Magazine mag) {
		//Magazine head = mag;
		Magazine newhead= new Magazine();
		
		System.out.println("Enter MagazineID: ");
		Scanner reader = new Scanner(System.in);  
		int ID = reader.nextInt(); 
		Magazine temp = head;
		while(temp!=null)
		{
			if(temp.magazineID == ID)
		{System.out.println("ID already existed!"); 
				return false;}
			temp=temp.next;
		}
		 
		
		newhead.magazineID = ID;
		reader.nextLine();
		System.out.println("Enter MagazineName: "); 
		 String name = reader.nextLine(); 
		 newhead.magazineName = name;
		 //System.out.println("Name: " +name); 
		 
		 
		System.out.println("Enter publisherName: "); 
		 String pname = reader.nextLine(); 
		 newhead.publisherName = pname;
		 if(magl.head == null)
		 {
			 magl.head = newhead;System.out.println("Head null"); 
		 }
		 else{
		newhead.next = magl.head;System.out.println("Head existed"); 
		magl.head = newhead;
		}
		//head = newhead;
		//printAllRecords();
		head.print();
		
		/*while(newhead.head!= null){
			//System.out.println(head.magazineID + "\n" + head.magazineName + "\n" + head.publisherName + "\n");
			System.out.println("Printing");
			newhead.head.print();
			newhead.head = newhead.head.next;
			}
		*/
		
		System.out.println("Magazine Added "); 
		return true;
	} // insert at front of list or return // false if that ID already exists
	Magazine deleteFromFront() {
		if(magl.head == null)
		return null;
		else
		{
			Magazine temp = magl.head.next;
			magl.head = null;
			magl.head = temp;
			System.out.println("First item deleted");
			return temp;
		}
	} // delete and return the record at the front of the list or return null if the list is empty
	boolean delete(int ID) {
		Magazine temp = magl.head;
		if(temp == null) return false;
		while(temp.next!=null){
			if(temp.next.magazineID == ID)
				{temp.next = temp.next.next; System.out.println("ID deleted");return true;}
			temp = temp.next;
		}
		return false;
	} // find and delete the record with the given ID or return false if it isn’t found
	boolean printRecord(int ID) {
		Magazine temp = magl.head;
		while(temp!=null){
			if(temp.magazineID == ID)
				{temp.print(); return true;}
			temp = temp.next;
		}
		System.out.println("ID not found. ");
		return false;
	} // print that object as above for Magazine
	void printAllRecords() {
	// print all elements in the order they app
		Magazine temp = magl.head;
	while(temp!= null){
		//System.out.println(head.magazineID + "\n" + head.magazineName + "\n" + head.publisherName + "\n");
		System.out.println("Printing");
		temp.print();
		temp = temp.next;
		}
	//head.next.print();
	
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int key = 0;
		 magl = new MagazineList();
		
		Scanner reader = new Scanner(System.in); 
		do{ 
			
		
		System.out.println("Operations on List \n 1. Make Empty \n 2. Find ID \n 3. Insert At Front\n 4. Delete From Front \n 5. Delete ID \n 6. Print ID \n 7. Print All Records \n 8. Done ");
	
		
		System.out.println("Enter a number: ");
		int option = reader.nextInt(); 
		System.out.println("Your choice: " + option);
		int ID;
	switch (option) {
	case 1:magl.makeEmpty();
	break;	
	case 2:
	System.out.print("ID No: ");
	 ID = reader.nextInt();magl.findID(ID);
	break;
	case 3: 
		magl.insertAtFront(magl.head);
	break;
	case 4:
		magl.deleteFromFront();
		break;
	case 5:
		System.out.print("ID No: ");
		 ID = reader.nextInt();magl.delete(ID);
		break;
	case 6:
		System.out.print("ID No: ");
		 ID = reader.nextInt();magl.printRecord(ID);
		break;
	case 7:System.out.println("Printing");
		magl.printAllRecords();
		break;
	case 8: key = 1; System.out.println("Closed");
	break;
	default: System.out.println("Invalid operation");
	break;
	}
	
	}while(key != 1);
		
		
		reader.close();
}
////////////////////Magazine CLass ///////////
class Magazine implements Comparable<Object>{
int magazineID = 0;
String magazineName ;
String publisherName ;
public Magazine next;
public Magazine() {
// TODO Auto-generated constructor stub
	
}
void print(){
	System.out.println("magazineID: "+magazineID + "\n" + "magazineName: "+magazineName + "\n" + "publisherName: "+publisherName + "\n");
}
@Override
public int compareTo(Object o) {
// TODO Auto-generated method stub
return 0;
}

}

}

import java.util.Scanner;
//Name: Hoa P Nguyen
//Binary Search Trees with Lazy Deletion
//All function work
//IDE : Eclipse, JavaSE 1.8

public class TreeNode {
int key ;
TreeNode leftChild;
TreeNode rightChild;
boolean deleted = false;

//contains
//Should return true if a particular element is in the tree and is not marked as deleted
public boolean contain(int key, TreeNode a){
	TreeNode t = a;
	if ( t == null){
		System.out.println("false");
		return false;
		
	}
	if (key > t.key )
		return contain(key, t.rightChild);
	else if(key < t.key)
		return contain(key, t.leftChild);
	else if(t.key == key && t.deleted == true){
		System.out.println("false");
		return false;
	}
	else{
		System.out.println("true");
		return true;
	}
	}
//insert
//Should insert a new element to a leaf node. If new element is a duplicate then do nothing. If
//the new element is previously deleted one, then do not add other copy just mark the previous
//deleted as valid now
private TreeNode insert(int x, TreeNode a){
	TreeNode t = a;
	if(t == null ){
		t=new TreeNode(x, null, null);
		return t;
	}
	if(x <1 || x > 99){
		System.out.println("invalid");
	}
	if(a.key == 0){
		t.key = x;
	}
	if(x > t.key ){
		t.rightChild = insert(x,t.rightChild);
	}
	else if(x < t.key ){
		t.leftChild = insert(x,t.leftChild);
	}
	else if (t.deleted == true){
		System.out.println("remove deleted mark");
		t.deleted = false;
		System.out.println("Element inserted");
		}
	//else if(t.deleted == false){
			
			
	
	return a;
}
public int min(int a, int b){
	if(a<b) return a;
	else return b;
	
}
//findMin
//Should return the minimum element, but if it is marked deleted return appropriate minimum
private int findMin(TreeNode a){
	TreeNode t = a;
	int min = 100; // if tree is empty min =100
	
	
	if(a != null)
	{
		int b=findMin(a.leftChild);
		
		int c=findMin(a.rightChild);
		min = min(b,c);
		if(a.key< min && a.deleted != true)
			min = a.key;
	}
	
	/*if(a != null)
	{
		if(a.key< min && a.deleted != true)
			min = a.key;
	
	
	
	else if(a.leftChild!= null)	
		return findMin(a.leftChild);
	else if(a.leftChild== null && a.rightChild!= null)
		return findMin(a.rightChild);
	else if( a.leftChild!= null && a.rightChild== null)
		return findMin(a.leftChild);
	else
		min = min(findMin(a.rightChild),findMin(a.leftChild));
	}
	*/
	
	
	return min;
	
}
//In order tree Traversal
//Should print the in order traversal of the tree. Indicating with * symbol for elements that are
//marked deleted
public void inorder(TreeNode a){
	TreeNode t = a;
	
	if(a != null)
	{
		inorder(a.leftChild);
		if(a.deleted == false)
			if(t.key != 0)
		System.out.println("key = "+a.key);
		inorder(a.rightChild);
	}
	
}
//findMax
//Should return the maximum element, but if it is marked deleted return appropriate maximum
private int findMax(TreeNode a){
	TreeNode t = a;
	
	int max = 0; // if tree is empty min =100
	
	
	if(a != null)
	{
		int b=findMax(a.leftChild);
		
		int c=findMax(a.rightChild);
		max = max(b,c);
		if(a.key> max && a.deleted != true)
			max = a.key;
	}
	return max;
}
//delete
//Should not remove the element from the tree. It should just mark the element as deleted.
private TreeNode delete(int x,TreeNode a){
	TreeNode t = a;
	
	if ( t == null){
		System.out.println("Tree empty");

		
	}
	if (x > t.key )
		return delete(x, t.rightChild);
	else if(x < t.key)
		return delete(x, t.leftChild);
	else if(t.key == x ){
		t.deleted = true;
		System.out.println("Deleted");
		return a;
	}
	return a;
}
public int max(int a, int b){
	if(a>b) return a;
	else return b;
	
}
//Height ( returns the height of the tree)
//Return the height of the tree, count all the elements even the ones that are marked as deleted
private int height(TreeNode a){
	TreeNode t=a;
	int counter = 0;
	if (t == null)
		return -1;
	if (t.deleted ==true)
		return  max(height(t.leftChild), height(t.rightChild));
	
	
	return  max(height(t.leftChild), height(t.rightChild))+1;
	

	
}
//No Of nodes ( returns number of nodes)
//Return size of the tree, count all the elements even the ones that are marked as deleted. And
//also return the number of deleted elements. */
private int NumOfNode(TreeNode a){
	TreeNode t=a;
	int counter = 0;
	if (t == null)
		return 0;
	
	else if(t.deleted == true){
		return NumOfNode(t.leftChild)+ NumOfNode(t.rightChild);
	}
	
	else return NumOfNode(t.leftChild)+ NumOfNode(t.rightChild)+1;
	
	
}


public TreeNode(int a, TreeNode left, TreeNode right) {

key = a; leftChild = left; rightChild = right;
	
}
public TreeNode(int a) {
this(a, null, null);

	
}
	public TreeNode() {
		// TODO Auto-generated constructor stub
	

	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
TreeNode tree = new TreeNode() ;
System.out.println("Number of Nodes= " + tree.NumOfNode(tree));
System.out.println("Max = " + tree.height(tree));
System.out.println ("Binary Search Trees \n 1. Insert \n 2. Delete \n 3. Find Max \n 4. Find Min \n 5. Contains \n 6. In order Tree Traversal \n 7. Height \n 8. No Of Nodes ");
int option = 0;
int input;
while(option != 9){
Scanner s = new Scanner(System.in);
System.out.println("Pick 1 option: ");
option = s.nextInt();
System.out.println("Your option: "+option);
switch (option) {
case 1: System.out.println("Enter input: ");

input = s.nextInt();
tree.insert(input, tree);
         break;
         
case 2:System.out.println("Enter element to delete: "); 
	input = s.nextInt();
tree.delete(input, tree);
         break;
case 3:  System.out.println("Max: " + tree.findMax(tree));
         break;
case 4: 	 //TreeNode c = tree.findMin(tree);
	System.out.println("Min: " + tree.findMin(tree));
         break;
case 5:  System.out.println("Enter element to check contain: "); 
	input = s.nextInt();
tree.contain(input, tree);
         break;
case 6:  tree.inorder(tree);
         break;
case 7:  System.out.println("Tree height: "+ tree.height(tree));
break;
case 8:  System.out.println("Number of Nodes: "+tree.NumOfNode(tree));
break;
case 9: System.out.println("Closing"); 
break;
default: System.out.println("invalid"); 
}

	
}
	}
}

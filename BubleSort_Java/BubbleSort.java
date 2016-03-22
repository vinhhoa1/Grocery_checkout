
import java.util.Comparator;


public class BubbleSort {
	public static <E extends Comparable<E>>void bubbleSort(E[] list){
		
		E temp = null;
		boolean swap = true;
		for (int i = 1; i < list.length && swap ;i++)
		{
			swap = false;
			
			for (int j =0; j< (list.length - i) ; j++)
			{
				if(list[j].compareTo(list[j+1]) > 0)
				{
					temp = list[j];
					list[j] = list[j+1];
					list[j+1] = temp;
					swap = true;
				}
			}	
			
		}
	}
	
	public static <E> void bubbleSort(E[] list,Comparator<? super E> comparator){
		
		E temp = null;
		boolean swap = true;
		for (int i = 1; i < list.length && swap ;i++)
		{
			swap = false;
			
			for (int j =0; j< (list.length - i) ; j++)
			{
				if(comparator.compare(list[j], list[j+1]) > 0)
				{
					temp = list[j];
					list[j] = list[j+1];
					list[j+1] = temp;
					swap = true;
				}
			}	
			
		}
		
	}
	public BubbleSort() {
		// TODO Auto-generated constructor stub
	}
	
	public static void main(String[] args){
		Integer[] list2 = new Integer[] {3,2,6,5,8, 4,3};
		for (int j =0; j< list2.length; j ++)
		{
		System.out.print(list2[j] + " ");
		}
		bubbleSort(list2);
		System.out.println();
		for (int j =0; j< list2.length; j ++)
		{
		System.out.print(list2[j] + " ");
		}
		
		System.out.println("\nBubblesort with comparator: ");
		Integer[] list3 = new Integer[] {3,2,6,5,8,6,2,7, 4,3};
		for (int j =0; j< list3.length; j ++)
		{
		System.out.print(list3[j] + " ");
		}
		bubbleSort(list3, new testcomparator());
		System.out.println();
		for (int j =0; j< list3.length; j ++)
		{
		System.out.print(list3[j] + " ");
		}
		
	}
	
}
class testcomparator implements Comparator<Integer>{

	public int compare(Integer x, Integer y) {
		if (x > y){
			return 1;
		}
		else if(x< y){return -1;}
		else return 0;
	}}
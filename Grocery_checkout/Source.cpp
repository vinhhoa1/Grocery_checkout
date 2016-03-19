// Hoa P Nguyen
//cs 1337.002 - computer science i - s15
//instructor : miguel angel razo - razo;
//Homework 6

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;



class products
{
public:
	int plu;
	string name;
	int type;
	double price;
	double level;
};
class perunit : public products
{
public:
	perunit * next;
	perunit(){
		next = nullptr;
	}
};
class perpound : public products
{
public:
	perpound * next;
	perpound(){
		next = nullptr;
	}
};

void checkout();
products fruit[6];
perunit * headunit = new perunit;
perunit * currentunit = headunit;
perpound * headpound = new perpound;
perpound * currentpound = headpound;

int main()
{
	int j, i = 0;
	ifstream inf;
	inf.open("products.txt");
	ofstream out;
	out.open("inventory.txt");

	string line;
	if (!inf)
	{
		cout << "Fail to read products.txt" << endl;
		return false;
	}


	while (inf.good())
	{
		while (!inf.eof())
		{
			for (i = 0; i < 6; i++)
			{
				inf >> fruit[i].plu >> fruit[i].name >> fruit[i].type >> fruit[i].price >> fruit[i].level;
			}
		}
	}
	cout << "////////////////" << endl;
	for (int m = 0; m < 6; m++)
	{
		cout << fruit[m].plu << " " << fruit[m].name << " " << fruit[m].type << " " << fruit[m].price << " " << fruit[m].level << endl;
	}
	checkout();
	out << "Inventory: " << endl;
	for (j = 0; j < 6; j++)
	{
		out << fruit[j].plu << " " << fruit[j].name << " " << fruit[j].type << " " << fruit[j].price << " " << fruit[j].level << endl;
	}
	out << "Products sold per unit: " << endl;
	perunit * unit = headunit;
	perpound * pound = headpound;
	double totalsold = 0;
	while (unit != currentunit)
	{
		out << "PLU: " << unit->plu << " Product: " << unit->name << " Price: " << unit->price << " Sold: " << unit->level << endl;
		totalsold += unit->level;
		unit = unit->next;
	}

	out << "Products sold per pound: " << endl;
	while (pound != currentpound)
	{
		out << "PLU: " << pound->plu << " Product: " << pound->name << " Price: " << pound->price << " Sold: " << pound->level << endl;
		pound = pound->next;
	}


	inf.close();
	out.close();

	return 0;
}
void checkout()
{
	int cn = 1; // customer number.
	double buycount[100]; int buylist[100];
	double total = 0; double amount;
	int k; int plu; int key = 0; char key2;
	int product[100];
	int counter = 0; double discount = 0;
	double cost[100];
	do
	{
		cout << "Welcome customer number: " << cn << endl;
		do{
			k = 0;
			key = 0;
			cout << " Enter plu code or 0 to checkout: " << endl;
			do{
				cin >> plu;
				for (int o = 0; o < 6; o++)
				{
					if (plu == fruit[o].plu)
					{
						key++;
						k = o;
						buylist[counter] = o;
					}
					else if (plu == 0)
					{
						key++;
					}
					else if (!plu)
					{
					
						key = 0;
					}
					
				}
				if (key == 0)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid input, try again: ";
				}

			} while (key == 0);
			if (plu == 0)
			{
				break;
			}
			cout << "You want to buy " << fruit[k].name << endl;
			cout << endl;


			cout << "Please enter the weight or units. ";
			do{
				if (fruit[k].type == 0)
				{
					cout << "(has to be integer): ";
				}
				key = 0;
				cin >> amount; cout << endl;
				if (!amount){
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					key = 22;
				}

				else if (fruit[k].type == 0 && (amount - (int(amount))) > 0)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "invalid input, Please enter an integer" << endl;
					key = 22;

				}
				else if (amount < 0)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid input, please enter number bigger than 0" << endl;
					key = 22;
				}
				else if (amount > fruit[k].level)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Out of stock,or invalid input." << endl;
					key = 22;
				}
				
				else
				{
					if (fruit[k].type == 1){

						currentunit->name = fruit[k].name;
						currentunit->plu = fruit[k].plu;
						currentunit->price = fruit[k].price;
						currentunit->level = amount;
						currentunit->next = new perunit;
						currentunit = currentunit->next;
					}
					else if (fruit[k].type == 0){
						currentpound->name = fruit[k].name;
						currentpound->plu = fruit[k].plu;
						currentpound->price = fruit[k].price;
						currentpound->level = amount;
						currentpound->next = new perpound;
						currentpound = currentpound->next;
					}
					break;
				}


			} while (key = 22);
			buycount[counter] = amount;
			cost[counter] = amount * fruit[k].price;
			fruit[k].level -= amount;
			cout << "Cost for " << fruit[k].name << " $" << cost[counter] << endl;

			counter++; // count number of purchase

		} while (plu != 0);

		//check out;
		for (int n = 0; n < counter; n++)//calculate total cost
		{
			total += cost[n];
		}

		cout << "You purchased: " << endl;

		for (int m = 0; m <= (counter - 1); m++) // list item purchased
		{
			cout << setw(5) << buycount[m] << " :  " << fruit[buylist[m]].plu << " " << fruit[buylist[m]].name << " " << fruit[buylist[m]].type << " " << fruit[buylist[m]].price << " " << fruit[buylist[m]].level << endl;

		}
		cout << "Total cost(before discount): " << total << endl;

		if (total > 50) // total purchase exceeds $50
		{
			discount += 5;
		}
		int rand1;
		rand1 = rand() % 3 + 1; // random discount
		if (rand1 == 1)//discount coupon
		{
			discount += 5;

		}
		total = total - total*(discount / 100);
		cout << "Total cost(after discount): " << total << endl;
		cout << "Discount: " << discount << "%" << endl;
		cn++;


		cout << "Press any key to purchase or press i to close store: " << endl;
		cin >> key2;
		discount = 0;
		counter = 0;
		total = 0;
	} while (key2 != 'i');


}


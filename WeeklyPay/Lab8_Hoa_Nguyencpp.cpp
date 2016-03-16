/*Hoa P Nguyen
Dr. Tyson McMillan
Program calculate weekly pay
Visual Studio 2013 Ultimate
*/

#include <iostream>
#include<iomanip>
#include<conio.h>
#include<Windows.h>
#include<string>
#include<locale>
#include <cstdlib>
using namespace std;

double weeklyPay(double, double, string, int);// function prototype

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
void weeklyPay();

int main()
{
	locale loc;
	string tcc = "TCC-TR IS COOL";
	string succ = "i will succeed at c++";
	cout << fixed << setprecision(2);
	cout << weeklyPay(47.0, 505.75, "Hoa P Nguyen", 1) << endl;
	cout << weeklyPay(45, 55.25, "Melivin", 1) << endl;
	cout << weeklyPay(15.0, 65.25, "SuSan", 2) << endl;
	cout << weeklyPay(41.0, 14.75, "Mika", 1) << endl;
	cout << weeklyPay(25.0, 15.0, "Eldridge", 2) << endl;
	cout << weeklyPay(55.0, 203.5, "Freedom", 1) << endl;

	for (int i = 0; i < tcc.length(); i++)
	{
		cout << tolower(tcc[i], loc);
	} cout << endl;

	for (int i = 0; i < tcc.length(); i++)
	{
		cout << toupper(succ[i], loc);
	} cout << endl;
	
	system("pause");
	return 0;
}

double weeklyPay(double hours, double rate, string name, int empType)
{// complete the function definition
	cout << "Net Pay for ";
	
	locale loc;
	double grosspay = 0.0;
	double netpay = 0.0;
	double overtimehours = 40.0;
	int nameLength = name.length();
	if (hours <= overtimehours) 
	{ 
		grosspay = hours * rate;
	}
	else if ((hours > overtimehours) && (empType == 1))
	{
		grosspay = (hours - overtimehours) * (rate * 2) + (overtimehours * rate);
	}
	else if ((hours >= overtimehours) && (empType == 2))
	{
		grosspay = hours * rate;
	}
	if (empType == 2)// part time
	{
		netpay = grosspay - (grosspay * 0.062) - (grosspay * 0.0145);
		cout << "Part time employee - " ;
		
	}
	else if (empType == 1)//full time
	{
		netpay = grosspay - (grosspay * 0.062) - (grosspay * 0.0145) + 15 + 77;
		cout << "Full time employee - " ;
	}
	if (rate < 15)
	{
		netpay = netpay - (grosspay * 0.12);
	}
	else if (rate >= 15)
	{
		netpay = netpay - (grosspay * 0.15);
	}
	for (int i = 0; i < nameLength; i++)
	{
		SetConsoleTextAttribute(console, 236);
		cout << toupper(name[i], loc);
		SetConsoleTextAttribute(console, 7);
	}
	cout << " : $";
	return netpay;
}
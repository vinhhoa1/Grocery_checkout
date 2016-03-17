 /*
Dr. Tyson McMillan 9‐16‐2013
Updated: 02‐01‐2014 by Dr. Tyson McMillan (Teacher)
Student: Hoa P Nguyen
Visual Studio ultimate 2014
Estimate time to complete degree with color texts
 */

 
#include <iostream>
#include <string>
#include <windows.h>
#include <string>    
#include "Input_Validation.h"
#include <ctime>
#include <iomanip>

 using namespace std;

 int main()
 {
 int currentYear = 0;
 double inputYear = 0; // year inputed by user
 int myAge = 0; //type your age in here as variable assignment
 int associatesDegreeCompTime = 0; //est time of completion
 int bachDegreeCompTime = 0; //est time of completion
 int mastDegreeCompTime = 0; //est time of completion
 int docDegreeCompTime = 0; //est time of completion
 int completionAtThisPoint = 0; //variable to hold completion
 int myAgeThisPoint = 0; //variable to hold completion
 double salary = 0;
 HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // For use of SetConsoleTextAttribute()
 //Welcome Message:
 cout << "Welcome! This program projects various times of degree completion" << endl;
 cout << "based upon the year that you enter." << endl << endl;

 do
 {
 currentYear = 0;
 inputYear = 0; // year inputed by user
 myAge = 22; //type your age in here as variable assignment
 // myAge could be set as an input rather than set values as well in future expansion
 associatesDegreeCompTime = 4; //est time of completion of Associates Degree
 bachDegreeCompTime = 6; //est time of completion of Bachelor's Degree
 mastDegreeCompTime = 3; //est time of completion of a Master's Degree
 docDegreeCompTime = 7; 
 completionAtThisPoint = 0; //variable to hold completion
 myAgeThisPoint = 0; //variable to hold completion
 // current date/time based on current system
 time_t now = time(0);

 // convert now to string form
 char* dt = ctime(&now);

 // convert now to tm struct for UTC
 tm *gmtm = gmtime(&now);
 dt = asctime(gmtm);

 // current date/time based on current system
 time_t now2 = time(0);
 tm *ltm = localtime(&now);


 cout << "CURRENT Year: " << 1900 + ltm->tm_year << endl;
 currentYear = 1900 + ltm->tm_year;

 cout << "My age in the CURRENT year is: " << myAge << endl;

 //***APPLY INPUT VALIDATION FROM THE HEADER FILE (Input_Validation.h)
 //Loops, Try‐Catch Blocks, and Header Files
 while (true)
 {
 cout << "\nPlease enter a year to begin calculations (‐1 to exit): ";

 try //get an intger inputYear from the user
 {
	 inputYear = getValidatedInput<int>(); //INPUT
 }
 catch (exception e)
 {
 cerr << e.what() << endl;
 continue;
 }

 //ensure year amount is positive
 if( (inputYear != -1) && (inputYear < 0) ) //‐1 is the only approved negative number to exit program
 {
 cout << "\nPlease enter year amount greather than or equal to 0.";
 }
 else
 {
 break;
 }
 }
 /*****************************/

 //Goal: Estimate Year of Completion, and my age at completion
 if(inputYear != -1)
 {

 if(inputYear != currentYear)
 {
 inputYear = currentYear + (inputYear - currentYear);
 myAgeThisPoint = myAge + (inputYear - currentYear);
 cout << "inputYear ‐ currentYear = " << inputYear - currentYear;
 cout << ", inputYear: " << inputYear << endl;
 cout << "My AGE in the input year is: " << myAgeThisPoint << endl;
 myAge = myAgeThisPoint; //Study the power of what this line is doing
 }
 else if(inputYear == currentYear)
 {
 currentYear = inputYear;
 }
 else
 {
	 cout << "\nError\n";
 }
completionAtThisPoint = associatesDegreeCompTime + inputYear;
myAgeThisPoint = associatesDegreeCompTime + myAge;
cout << "\nFrom the input year to associatesDegreeCompTime is: "
	<< completionAtThisPoint << endl << "My age will be : " << myAgeThisPoint
 << endl << endl;


 completionAtThisPoint += bachDegreeCompTime; //add to the existing value
 myAgeThisPoint += bachDegreeCompTime;


 cout << "From the input year to bachDegreeCompTime is: "
 << completionAtThisPoint << endl << "My age will be : " << myAgeThisPoint
 << endl << endl;

 
 completionAtThisPoint += mastDegreeCompTime; //add to the existing value
 myAgeThisPoint += mastDegreeCompTime;


 cout << "From the input year to mastDegreeCompTime is: "
 << completionAtThisPoint << endl << "My age will be : " << myAgeThisPoint
 << endl << endl;

 //docDegreeCompTime PROCCESS
 completionAtThisPoint += docDegreeCompTime; //add to the existing value
 myAgeThisPoint += docDegreeCompTime;


cout << "From the input year to docDegreeCompTime is: "
 << completionAtThisPoint
 << endl << endl;
 }
 else
 {
 cout << "\nGoodbye, Happy coding and Green tea~~~~!!!" << endl;
 }
 	cout << "Degree I going to earn: " << endl;
	SetConsoleTextAttribute(console, 74);
		cout << "Associate Degree" << endl;
		SetConsoleTextAttribute(console, 74);
		cout << "Bachelor Degree" << endl;
		
	
		while (true)
    {
        	cout << "Enter your expected yearly salary (double) after earning the Ph.D. ";

        try
        {
            salary = getValidatedInput<double>();
        }
        catch (exception e)
        {
            cerr << e.what() << endl;
            continue;
        }

        break;
    }
		SetConsoleTextAttribute(console, 74) ;
		cout << "Your future salary after earning Ph.D is: "  << fixed << setprecision(2) << salary << endl;
		SetConsoleTextAttribute(console, 74);
} while(inputYear != -1);
return 0;
}
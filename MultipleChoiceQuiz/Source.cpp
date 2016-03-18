//HOA P NGUYEN
// CS 1337.002 - Computer Science I - S15
//Instructor: Miguel Angel Razo - Razo;
// PROJECT
//COMPILER VISUAL STUDIO 2013
// April 23, 2015
#include<iostream>
#include<fstream>
#include<istream>
#include<vector>
#include <stdlib.h>   
#include<time.h>   
#include<string>


using namespace std;
class question
{
public:
	int id = 0;
	char * questionr;
	char *option_a;
	char *option_b;
	char *option_c;
	char *option_d;

	question()
	{

		questionr = nullptr;
		option_a = nullptr;
		option_b = nullptr;
		option_c = nullptr;
		option_d = nullptr;
	}
	~question(){

		delete[] questionr;
		delete[] option_a;
		delete[] option_b;
		delete[] option_c;
		delete[] option_d;

	}

};

class answer{
public:
	int num = 0;
	char *ranswer;
	char *exp;
	answer(){
		ranswer = nullptr;
		exp = nullptr;
	}
	~answer(){

		delete[] ranswer;
		delete[] exp;

	}
};

int main()
{
	int counter = 0;
	ifstream inf;
	ifstream keyfile;
	ofstream out("exam.txt");
	keyfile.open("key.txt");
	inf.open("questions.txt");
	if (!inf)
	{
		cout << "Cannot read q file";
	};
	if (!keyfile)
	{
		cout << "Cannot read answer file";
	};
	
	string line;
	char trash[500];
	while (!inf.eof())	//	READ FILE
	{
		getline(inf, line);
		counter++;
	}
	inf.clear();
	inf.seekg(0, inf.beg);
	question * allQuestions;
	question *key3;
	
	allQuestions = new question;
	allQuestions = new question[counter];
	key3 = allQuestions;
	counter = counter / 5;
	int i = 0;
	while (i<counter)	//	READ FILE
	{
		allQuestions->id = counter;
		allQuestions->questionr = new char[300];
		allQuestions->option_a = new char[100];
		allQuestions->option_b = new char[100];
		allQuestions->option_c = new char[100];
		allQuestions->option_d = new char[100];
		//cout << "id: " << allQuestions->id << endl;
		inf.getline(allQuestions->questionr, 300, '\n');
		inf.getline(allQuestions->option_a, 100, '\n');
		inf.getline(allQuestions->option_b, 100, '\n');
		inf.getline(allQuestions->option_c, 100, '\n');
		inf.getline(allQuestions->option_d, 100, '\n');
		/*cout << "question: " << allQuestions->questionr << endl;
		cout << "a: " << allQuestions->option_a << endl;
		cout << "b: " << allQuestions->option_b << endl;
		cout << "c: " << allQuestions->option_c << endl;
		cout << "d: " << allQuestions->option_d << endl;*/

		allQuestions++;
		i++;
		//cout << "counter: " << counter << endl;
		
	}
	counter--;
	allQuestions = key3;
	answer *key;
	answer *key2;
	key = new answer[counter];
	key2 = key;
	//cout << "counter: " << counter << endl;
	////////////////////////////////////////////////////////////////
	while (keyfile)	// READ KEY.TXT FILE
	{
		key->ranswer = new char[50];
		key->exp = new char[50];
		keyfile >> trash >> key->num >> trash >> key->ranswer;
		keyfile.getline(key->exp, 50, '\n');
		//cout << "question: " << key->num << endl << "answer: " << key->ranswer << endl;
		//cout << "explaination: " << key->exp << endl;

		key++;
	}
	key = key2;
	/////////////////////////////////////////////////////////////

	cout << "Finish reading files." << endl;
	/*for (int i = 0; i < counter-1 ; i++)
	{
	cout << "question: " << key[i].num << endl;
	cout << "answer: " << key[i].ranswer << endl;
	cout << "explaination: " << key[i].exp << endl;
	}
	cout << "answers -----------------------------------" << endl;
	*/
	/*for (int i = 0; i <= counter-1; i++)
	{
	cout << "/////////////////////////////////" << endl;
	cout << "question number" << i << " : " << allquestions[i].questionr << endl;
	cout << "a: " << allquestions[i].option_a << endl;
	cout << "b: " << allquestions[i].option_b << endl;
	cout << "c: " << allquestions[i].option_c << endl;
	cout << "d: " << allquestions[i].option_d << endl;
	cout << "----------------------------" << endl;
	cout << "i: " << i << endl;
	}*/

	//////////////////// MAIN MENU //////////////////////
	int k = 0;
	char option = NULL;
	int num2; //number of question display 
	int counter2 = 0;
	char *userAnswers= new char[counter]; // store user answers
	int *IDanswer = new int[counter]; // the question user answers to
	double score = 0;

	bool pass;
	do{
		cout << "------------------MENU---------------" << endl;
		cout << "a.Enter the number of questions" << endl;
		cout << "b.Start the exam review" << endl;
		cout << "c.Get score" << endl;
		cout << "d.Generate report" << endl;
		cout << "e.Exit" << endl;
		cout << " Numbers of question in the file: " << counter << endl;
		cin >> option;
		switch (option){
		case 'a':
		case 'A':
			cout << "------------------OPTION A---------------" << endl;
			do
			{
				cout << "Number of question: ";
				cin >> k;
				if (cin.good() && k <= counter && k > 0)	//input validation
				{
					cout << "You picked " << k << " questions." << endl;
					pass = true;
				}
				else
				{
					pass = false;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Error 01. Invalid number input,try again(number have be less or equal to number of question and bigger than zero). " << endl;
				}
			} while (pass != true);
			cout << endl;

			break;
		case 'b':
		case 'B':
			cout << "------------------OPTION B---------------" << endl;

			int * questionseleted;
			questionseleted = new int[counter];
			
			if (k == 0)
			{
				cout << "Choose option first A to enter number of question." << endl;
				break;
			}

			else if (k != 0)
			{
				while (counter2 < k)
				{
					cout << endl;
					cout << "Generating question ...";
					srand(time(NULL)); //random base on time
					num2 = rand() % counter;

					if (questionseleted[num2] != 1) // checking unseleted question
					{
						cout << endl;
						questionseleted[num2] = 1; //mark the question used
						system("cls");
						cout << "Question ID: " << num2 + 1 << endl;;
						cout << "Question number " << counter2 + 1 << " : " << allQuestions[num2].questionr << endl; //counter+1 start with 1 instead of zero
						cout << "a: " << allQuestions[num2].option_a << endl;
						cout << "b: " << allQuestions[num2].option_b << endl;
						cout << "c: " << allQuestions[num2].option_c << endl;
						cout << "d: " << allQuestions[num2].option_d << endl;

						do{
							cout << "Your answer: ";
							cin >> userAnswers[counter2];
							userAnswers[counter2] = toupper(userAnswers[counter2]);
							if (userAnswers[counter2] == 'A' || userAnswers[counter2] == 'B' || userAnswers[counter2] == 'C' || userAnswers[counter2] == 'D') // select 1 of 4 option
							{

								pass = true;
								if (userAnswers[counter2] == *key[num2].ranswer) // Count score
								{
									score++;
								}
								IDanswer[counter2] = num2;
								counter2++; // move on to the next question.
							}

							else
							{
								pass = false;


								cout << "Error 03. Invalid answer input,try again(enter a,b,c or d). " << endl;			//input validation
							}

						} while (userAnswers[counter2] != 0 && pass != true);

					}
				}
				counter2 = 0;
				cout << "Test finish" << endl;
				cout << "Your answers: " << endl;
				for (int i = 0; i < k; i++)
				{
					cout << "Question number " << i + 1 << " .Your answer: " << userAnswers[i] << endl;

				}
			}
			delete[] questionseleted; questionseleted = NULL;
			break;
		case 'c':
		case 'C':
			cout << "------------------OPTION C---------------" << endl;

			cout << "Your score: " << score << "/" << k << " (" << score / k * 100 << "%)" << endl;
			break;
		case 'd':
		case 'D':
			cout << "------------------OPTION D---------------" << endl;
			;
			for (int i = 0; i < k; i++)
			{
				out << "Question ID: " << key[IDanswer[i]].num << endl;;
				out << "Question number " << i + 1 << " .Your answer: " << userAnswers[i] << endl;
				out << "The right answer: " << *key[IDanswer[i]].ranswer;;
				if (userAnswers[i] == *key[IDanswer[i]].ranswer)
				{
					out << "  Correct!!" << endl;
				}
				else
				{
					out << "  Wrong answer" << endl;
				}
			}

			break;
		case 'e':
		case 'E':
			return -1;
			break;
		default:
			cout << "Error 02. Invalid menu input, try again. " << endl;
		}
	} while (option != 'e' || option != 'E' || option != false);
	inf.close();
	keyfile.close();
	out.close();
	//	delete[] trash;
	//delete[] key;
	//delete[] allQuestions;
	cout << "Closing...";
	return 0;
}

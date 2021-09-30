#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <Windows.h>
#include "functions.h"
using namespace std;
//global variables
int day, month, year;
Diary* New_Diary = nullptr;
int diaryamount = 0;
//date input function(made it to shorten the code)
void DateDate() {
	cout << "Please, enter date: day, month and year\n";
	cout << "Enter year: ";
	cin >> year;
	cout << "Enter month: ";
	cin >> month;
	cout << "Enter day: ";
	cin >> day;
}
//task editing function
void ReductTask(Diary* data, int data_size, string name) {
	for (int i = 0; i < data_size; i++) {
		if (data[i].name == name) {
			if (data[i].status == true) {
				int ans_1;
				system("cls");
				PrintReductMenu();
				cin >> ans_1;
				while (ans_1 != 0) {
					if (ans_1 == 1) {
						cout << "Enter new name of your task: ";
						cin.get();
						getline(cin, data[i].name);
					}

					if (ans_1 == 2) {
						cout << "Enter new discription of your task: ";
						cin.get();
						getline(cin, data[i].description);
					}

					if (ans_1 == 3) {
						cout << "Enter new deadline of your task: \n";
						while (true) {
							DateDate();
							if (CheckDate(day, month, year)) {
								data[i].deadline.day = day;
								data[i].deadline.month = month;
								data[i].deadline.year = year;
								break;
							}
							else {
								cout << "Incorrect date value " << day << "-" << month << "-" << year << endl;
								cout << "Try again\n";
							}
						}
					}
					PrintReductMenu();
					cin >> ans_1;
				}
			}
		}
	}
}
//made this function to short the code
void PutTask() {
	int answer;
	cout << "Enter 1 to add task | 0 to exit --> ";
	cin >> answer;
	while (answer != 0) {
		if (answer == 1) {
			diaryamount++;
			New_Diary = AddDiary(New_Diary, diaryamount);
		}
		system("cls");
		cout << "Enter 1 to add task | 0 to exit --> ";
		cin >> answer;
	}
}
int main() {
	string name;
	PutTask();
	system("cls");
	int ans;
	cout << "\n---My Diary---\n";
	PrintMenu();
	cin >> ans;
	while (ans != 0) {
		if (ans == 1) {
			system("cls");
			PutTask();
		}
		if (ans == 2) {
			system("cls");
			cout << "Enter the name of task, which you want to delete: ";
			cin.get();
			getline(cin, name);
			DeleteTask(New_Diary, diaryamount, name);
		}
		if (ans == 3) {
			system("cls");
			cout << "Enter the name of task, which you want to reduct: ";
			cin.get();
			getline(cin, name);
			ReductTask(New_Diary, diaryamount, name);
		}
		if (ans == 4) {
			system("cls");
			cout << "Enter the name of task, which you want to search: ";
			cin.get();
			getline(cin, name);
			SearchTaskByName(New_Diary, diaryamount, name);
		}
		if (ans == 5) {
			system("cls");
			while (true) {
				DateDate();
				if (CheckDate(day, month, year)) {
					ShowTasksPerDay(New_Diary, diaryamount, day, month, year);
					break;
				}
				else {
					cout << "Incorrect date value " << "1 -" << month << "-" << year << endl;
					cout << "Try again\n";
				}
			}
		}
		if (ans == 6) {
			system("cls");
			while (true) {
				DateDate();
				if (CheckDate(day, month, year)) {
					ShowTasksPerWeek(New_Diary, diaryamount, day, month, year);
					break;
				}
				else {
					cout << "Incorrect date value " << "1 -" << month << "-" << year << endl;
					cout << "Try again\n";
				}
			}
		}
		if (ans == 7) {
			system("cls");
			while (true) {
				DateDate();
				if (CheckDate(day, month, year)) {
					ShowTasksPerMonth(New_Diary, diaryamount, day, month, year);
					break;
				}
				else {
					cout << "Incorrect date value " << "1 -" << month << "-" << year << endl;
					cout << "Try again\n";
				}
			}
		}
		if (ans == 8) {
			system("cls");
			SortPriority(New_Diary, diaryamount);
		}
		if (ans == 9) {
			system("cls");
			while (true) {
				DateDate();
				if (CheckDate(day, month, year)) {
					SearchTaskByDeadline(New_Diary, diaryamount, day, month, year);
					break;
				}
				else {
					cout << "Incorrect date value " << "1 -" << month << "-" << year << endl;
					cout << "Try again\n";
				}
			}
		}
		if (ans == 10) {
			system("cls");
			string discription;
			cout << "Enter the discription\n";
			cin.get();
			getline(cin, discription);
			system("cls");
			SearchTaskByDescription(New_Diary, diaryamount, discription);
		}
		if (ans == 11) {
			system("cls");
			ShowTasks(New_Diary, diaryamount);
		}
		if (ans == 12) {
			int priority;
			system("cls");
			cout << "Enter priority: ";
			cin >> priority;
			SearchTaskByPriority(New_Diary, diaryamount, priority);
		}
		PrintMenu();
		cin >> ans;
	}
	return 0;
}
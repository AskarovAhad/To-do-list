#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <Windows.h>
using namespace std;
const int MONTH_LENGTHS[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//structure with dates
struct Date {
	int day;
	int month;
	int year;
};

//structure
struct Diary {
	string name;
	string description;
	int priority;
	Date deadline;
	bool status = true;
};
//date check (days and months)
bool CheckDate(int day, int month, int year) {
	if (month > 12 || month <= 0) {
		return false;
	}
	if (MONTH_LENGTHS[month - 1] < day || day <= 0) {
		return false;
	}
	return true;
}
//date check only for months for the function of outputting all jobs for a month
bool CheckDate2(int month, int year) {
	if (month > 12 || month <= 0) {
		return false;
	}
	return true;
}
//filling in the added task
Diary Put() {
	Diary diary;
	int day, month, year;
	cout << "Enter the name of your task: ";
	cin.get();
	getline(cin, diary.name);
	cout << "Now enter description for you task: ";
	//cin.get();
	getline(cin, diary.description);
	cout << "Now enter the priority for you task --> ";
	cin >> diary.priority;
	while (true) {
		cout << "Now enter dead line(day, month, year)\n";
		cout << "Enter year: ";
		cin >> year;
		cout << "Enter month: ";
		cin >> month;
		cout << "Enter day: ";
		cin >> day;
		if (CheckDate(day, month, year)) {
			diary.deadline.day = day;
			diary.deadline.month = month;
			diary.deadline.year = year;
			break;
		}
		else {
			cout << "Incorrect date value " << day << "-" << month << "-" << year << endl;
			cout << "Try again\n";
		}
	}
	diary.status = true;
	return diary;
}
//adding a task
Diary* AddDiary(Diary* data, int data_size) {
	Diary* new_data = new Diary[data_size];
	for (int i = 0; i < data_size - 1; i++) {
		new_data[i] = data[i];
	}
	new_data[data_size - 1] = Put();
	return new_data;
}
//menu output function
void PrintMenu() {
	cout << "\t\t\t=Main menu=\n";
	cout << "1 - To add new note\n";
	cout << "2 - To delete note\n";
	cout << "3 - To reduct the note\n";
	cout << "4 - To search the note\n";
	cout << "5 - To show notes for a day\n";
	cout << "6 - To show notes for a week\n";
	cout << "7 - To show notes for a month\n";
	cout << "8 - To sort notes by priority\n";
	cout << "9 - To search task by deadline\n";
	cout << "10 - To search task by discription\n";
	cout << "11 - To show all notes\n";
	cout << "12 - To serch task by priority\n";
	cout << "0 - Exit\n";
	cout << "---->";
}
//output function
void Print(Diary data) {
	cout << "Name of task: " << data.name;
	cout << "\nDescription: " << data.description;
	cout << "\nDeadline: " << data.deadline.day << '.' << data.deadline.month << '.' << data.deadline.year;
	cout << "\nPriority: " << data.priority;
	cout << "\n---------------------------------------\n";
}

//output of all tasks
void ShowTasks(Diary* data, int data_size) {
	for (int i = 0; i < data_size; i++) {
		if (data[i].status == true) {
			Print(data[i]);
		}
	}
}

//sort by priority
void SortPriority(Diary* data, int data_size) {
	system("cls");
	for (int i = 0; i < data_size; i++) {
		for (int j = 0; j < data_size - i - 1; j++) {
			if (data[j].priority > data[j + 1].priority) {
				int tmp;
				tmp = data[j].priority;
				data[j].priority = data[j + 1].priority;
				data[j + 1].priority = tmp;
			}
		}
	}
	for (int i = 0; i < data_size; i++) {
		Print(data[i]);
	}
}

//deleting a task
void DeleteTask(Diary* data, int data_size, string name) {
	for (int i = 0; i < data_size; i++) {
		if (data[i].name == name) {
			if (data[i].status == true) {
				data[i].status = false;
				cout << "Note deleted!";
				break;
			}
		}
	}
}
//search for a task by name
void SearchTaskByName(Diary* data, int data_size, string name) {
	system("cls");
	for (int i = 0; i < data_size; i++) {
		if (data[i].name == name) {
			if (data[i].status == true) {
				Print(data[i]);
				break;
			}
		}
	}
}
//search for a task by description
void SearchTaskByDescription(Diary* data, int data_size, string description) {
	for (int i = 0; i < data_size; i++) {
		if (data[i].description == description) {
			if (data[i].status == true) {
				Print(data[i]);
				break;
			}
		}
	}
}
//displaying the to-do list for the day
void ShowTasksPerDay(Diary* data, int data_size, int day, int month, int year) {
	system("cls");
	for (int i = 0; i < data_size; i++) {
		if (data[i].status == true) {
			if (year == data[i].deadline.year && month == data[i].deadline.month && day == data[i].deadline.day) {
				Print(data[i]);
			}
		}
	}
}


//displaying the to-do list for the month
void ShowTasksPerMonth(Diary* data, int data_size, int day, int month, int year) {
	system("cls");
	for (int i = 0; i < data_size; i++) {
		if (year == data[i].deadline.year && month == data[i].deadline.month && (day - data[i].deadline.day <= 31)) {
			if (data[i].status == true) {
				Print(data[i]);
			}
		}
	}
}

//displaying the to-do list for the week
void ShowTasksPerWeek(Diary* data, int data_size, int day, int month, int year) {
	system("cls");
	for (int i = 0; i < data_size; i++) {
		if (data[i].status == true) {
			if (year == data[i].deadline.year && month == data[i].deadline.month && (day - data[i].deadline.day <= 7)) {
				Print(data[i]);
			}
		}
	}
}
//search task by priotity
void SearchTaskByPriority(Diary* data, int data_size, int priority) {
	system("cls");
	for (int i = 0; i < data_size; i++) {
		if (data[i].status == true) {
			if (data[i].priority == priority) {
				Print(data[i]);
			}
		}
	}
}
//search task by deadline
void SearchTaskByDeadline(Diary* data, int data_size, int day, int month, int year) {
	system("cls");
	for (int i = 0; i < data_size; i++) {
		if (data[i].status == true) {
			if (year == data[i].deadline.year && month == data[i].deadline.month && day == data[i].deadline.day) {
				Print(data[i]);
			}
		}
	}
}
//display edit menu
void PrintReductMenu() {
	cout << "Enter what you want to reduct:\n";
	cout << "1 - Name of your task\n";
	cout << "2 - Discription for your task\n";
	cout << "3 - Deadline for your task\n";
	cout << "0 - To exit";
}
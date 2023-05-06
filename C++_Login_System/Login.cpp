#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "Login.h"
using namespace std; 


void Login::login(string username, string password) {
	string un, pw; 
	ifstream read("login.txt"); 
	getline(read, un); 
	getline(read, pw); 

	
	if (un == username && pw == password) {
		cout << "Successfully logged in...Welcome " + username + "!\n"; 
	}
	else {
		cout << "Login information invalid!\n";
		Login l;
		Sleep(1000);
		system("cls");
		l.welcome();
	}
}
	
void Login::registration(string username, string password) {
	ofstream file("login.txt", ios_base::app);
	file << username << endl << password;
	file.close();
}
void Login::welcome() {
	int num;
	string username, password; 
	cout << "\tWelcome to A Simple Login System\n";
	cout << "1)Login\n2)Register\nChoice: ";
	cin >> num; 

	if (num == 1) {
		system("cls"); 
		cout << "Please enter your username: \n"; cin >> username; 
		cout << "Please enter your password: \n"; cin >> password; 
		Login l; 
		l.login(username, password);
	}
	else if (num == 2) {
		system("cls");
		cout << "Please enter your username: \n"; cin >> username;
		cout << "Please enter your password: \n"; cin >> password;
		Login l;
		l.registration(username, password);
		Sleep(1000); 
		system("cls"); 
		l.welcome();
	}
	else {
		cout << "The option chosen is invalid!!\n";
		Login l;
		Sleep(1000);
		system("cls");
		l.welcome();
	}  
}

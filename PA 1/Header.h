#pragma once
#include <string>
#include <fstream>
#include <iostream>



using namespace std;

class Data {
private:
	string command = "";
	string description = "";
public:

	Data(string com, string des) { //Just reads lines from csv file
		command = com;
		description = des;
	}

	string getCommand() {
		return this->command;
	}

	string getDescription() {
		return this->description;
	}

	string setCommand(string com) {
		return this->command = com;
	}
	string setDesription(string des) {
		return this->description = des;
	}
	

};

template<class DATATYPE>
class Node {
private:
	DATATYPE* data = nullptr;
	Node* next = nullptr;
	int ID = NULL;

public:
	
	Node(string com, string des) { 
	
		
		data = new DATATYPE(com,des);

	}

	//Destructor;

	//Setters and getters;
	///////////////////////////////
	
	void setData(DATATYPE newData) {
		this->data = newData;
	}
	void setNext(Node* newNext) {
		this->next = newNext;
	}
	void setID(int newID) {
		this->ID = newID;
	}
	DATATYPE* getData() {
		return this->data;
	}
	
	Node* getNext() {
		return this->next;
	}
	int getID() {
		return this->ID;
	}
		
	string getCommand() {
		return this->data->getCommand();
	}
	string getDescription() {
		return this->data->getDescription();
	}
	
};

template<class NODETYPE>
class List {
private:
	NODETYPE* head = nullptr;
	string name = "";
	int score = NULL;
	
public:

	List() { //Links nodes together
		//Populate linked list
		ifstream infile;
		infile.open("commands.csv", ios::in);
		while (!infile.eof()) {
			string token;
			getline(infile, token, '$');
			string com = token;
			getline(infile, token, '$');
			string des = token;
			//cout << com << endl << des << endl;
			if (com != "" && des != "") {
				NODETYPE* data = new NODETYPE(com, des);
				insertFront(data);
			}
		}
		infile.close();
	
	}
	/**********************************/
	/*            SETTERS			  */
	/**********************************/
	void setHead(NODETYPE* newHead) {
		this->head = newHead;
	}
	void setName(string newName) {
		this->name = newName;
	}
	void setScore(int newScore) {
		this->score;
	}
	/**********************************/
	/*            GETTERS			  */
	/**********************************/
	NODETYPE* getHead() {
		return this->head;
	}
	string getName() {
		return this->name;
	}
	int getScore() {
		return this->score;
	}

	// Allocates a new node with given data
	NODETYPE* newNode(NODETYPE * newData)
	{
		this->setHead(newData);
		newData->setNext(NULL);
		return newData;
	}

	//Destructor
	void insertFront(NODETYPE * newData)
	{
		if (!this->getHead()) {
			return this->setHead(newData);
		}

		NODETYPE* tempHead = this->getHead();
		this->setHead(newData);
		this->getHead()->setNext(tempHead);
	}

	/*NODETYPE* removeNode() {

	}*/

	/*********************************************
	Int input validation check and buffer clear. *
	**********************************************/
	int checkNUM() {
		int num;
		while (!(cin >> num)) {
			cout << "ERROR: a number must be entered: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		return num;
	}

	void printList() {
		
		if (!this->getHead()) {
			cout << "There is no list stupid" << endl;
		}
		else {
			NODETYPE* temp = this->getHead();
			while (temp) {
				cout << "Command is " << temp->getCommand() << endl;
				cout << "Description is " << temp->getDescription() << endl;
				temp = temp->getNext();
			}
		}

		
	}

};

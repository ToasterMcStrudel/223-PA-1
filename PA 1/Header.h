#pragma once
#include<iostream>
#include<string>

using namespace std;

class Data {
private:
	string command = "";
	string description = "";
public:

	Data(string com, string des) { //Just reads lines from csv file
		this->command = com;
		this->description = des;
	}
};

template<class DATATYPE>  class Node {
private:
	DATATYPE* var = nullptr;
	Node* next = nullptr;

public:
	
	Node(string com, string des) { 
		this->var = new DATATYPE(com, des);
	}

	Node* getNextPointer() {
		return this->next;
	}

	void setNextPointer(Node* newTail ) {
		next = newTail;
	}
};

template<class NODETYPE> class List {
private:
	NODETYPE* head;
	
public:

	List() { //Links nodes together
		//Populate linked list
		//open file
		//while !eof {
			//read line
			//parse data
			//create Node with data as parameters
			//add to list }
	}
	//Destructor

	NODETYPE* insertAtFront() {

	}
	NODETYPE* removeNode() {

	}

};
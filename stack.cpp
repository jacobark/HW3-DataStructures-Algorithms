//ECGR 3180 - Homework 3A
//Jacob Barker
//jbarke33@uncc.edu
#include "stack.h"
#include <iostream>
using namespace std;

istream& operator>> ( istream& sin, Stack &stk ) { //overloads >> operator to take stack from standard input
	Node            *tmp ;
	std::string     id ;
	
	sin >> id ;
	while( !sin.eof() ) {	//inserts new node, taken from standard input into stack
		tmp = new Node(id,stk.head) ;
		stk.head = tmp ;
		sin >> id ;
		
		while ((id=="add" || id=="dump" || id=="print") && !sin.eof()) { //checks for tokens
			if (id=="add") {	//performs add operations
				int a = std::stoi(stk.pop());	//pops two values from stack
				int b = std::stoi(stk.pop());	//and converts to integer
				std::string temp;
				a = a+b;	//adds these popped values
		       		temp = std::to_string(a);	//converts back to string
				stk.push(temp);	//pushes new value back onto stack
			} 
			if (id == "dump") {
				cout << stk;	//outputs stack if dump token is recieved
			}
			if (id == "print") {
				cout << stk.pop() << endl; //pops value from stack and outputs if print token 
			}	
			sin >> id;
		}
	}					    
	return sin;
}

ostream& operator<< (ostream& os, Stack &stk) {	//overloads << operator to output stack to the standard out
	Node *temp = stk.head;
	cout <<"[top] _________"<< endl;
	if(temp != NULL) {	//if head of stack does not equal NULL output head id
		cout << "      " << temp->id << endl;
		temp = temp->next;	//sets stack head to next
	}
	while(temp != NULL) {	//while  head does not equal NULL loop through stack outputing stack ID's
		cout << "      " << temp->id << endl;
		temp = temp->next;
	}
	cout<<"[bot] TTTTTTTTT"<<endl;
	return os;	
}

void Stack::push(std::string id) {	//places input string onto top of stack
	Node *temp = new Node(id);	//creates new node with argument id
	temp->next = head;
	head = temp;
}

std::string Stack::pop() {	//pops of top value of stack
	std::string temp;
	temp = head->id;	//places top value in temp
	head = head->next;	//makes top of stack equal the next value in stack
	return temp;	//returns top of stack


}


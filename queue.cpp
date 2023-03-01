//ECGR 3180 - Homework 3B
//Jacob Barker
//jbarke33@uncc.edu
#include "queue.h"
#include <iostream>
using namespace std;

void Queue::enqueue(double time) {	//EnQueue Function 	
	Node *temp = new Node(time);
	if (tail==NULL) {
		head = tail = temp;	
		return;
	}
	tail->next = temp;	//places new Node with argument time on end of Queue
	tail = temp;
}

void Queue::dequeue() {		//DeQueue Function
	if(head == NULL) {
		return;
	}
	Node *temp = head;
	head = head->next;	//Removes Node from front of Queue
	if(head == NULL) {
		tail == NULL;
	}
	delete(temp);
}

double Queue::Avg_wait() {	//function to calculate wait time of customers
	double time, TotalTime = 0;	//time token and Total wait time of each customer
	std::string token;	//enter/exit token
	int Customers = 0;	//amount of customers in line Queue
	int TotalCust = 0;	//stores the total amount of customers that enter and exit line
	cin >> time;
	cin >> token;
	while(!cin.eof()) {	//loops unitll end of file
		if(token == "enter") {	//if customer enters 
			Customers = Customers + 1;	//adds a Customer to the Customers in line
			TotalCust = TotalCust + 1;	//adds 1 to the total number of customers who have entered and exited
			enqueue(time);	//adds customer time to Queue
		}
		else if(token=="exit") {     //if exit token is given
	                Customers = Customers - 1;      //subtracts one customer from number of customers in line
                        	if(Customers < 0) {     //if more customers exit than enter returns error message
	                                cout << "Non existant customer exited the line." << endl;									                             return 1;
				}
			TotalTime = TotalTime + time - (head->time);    //stores Total wait tim	
			dequeue();           //by adding total wait time to the current time minus the time the customer entered				                        //removes customer from Queue
                }
		else {
			cout << "syntax error around " << token << endl; //if some other token is entered return error message
			return 1;
		}
		cin >> time;
		cin >> token;
	}	//this loops unitill end of file


	if(TotalCust == Customers) {	//if the total number of customers equals the number of customers in line, no one exited
		cout << "No customers exited, so there is no wait times to average." << endl;
		return 0;
	}
	else if(Customers == 0) {	//if all customers who entered exited
		cout << "Avg time spent in line is: ";
		cout << TotalTime/TotalCust << endl;	//outputs average time by dividing the total time each customer spent divided by total customers
	}
	else {
		cout << "Avg time spent in line is: ";	
		cout << TotalTime/(TotalCust-Customers) << endl; //average time if not everybody exited
		cout << "However, some people are still in line." << endl;	//divides total wait time by amount of customers who exited
	}
	return 0;
}

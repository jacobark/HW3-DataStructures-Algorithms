//ECGR 3180 - Homework 3A
//Jacob Barker
//jbarke33@uncc.edu
#ifndef stack_h
#define stack_h
#include <iostream>

class Node {	//Node Class defined from class notes
	public:
		std::string     id ;
		Node            *next ;
		Node ( std::string id , Node *next=nullptr ) {
			this->id = id ;			
			this->next = next ;
		}
} ;


class List {
	public:
		Node    *head ;
		List() { head = nullptr ; }
		Node    *first() { return head ; }
	//	friend std::istream& operator>> ( std::istream& sin, List &lst );	//>> overload function
	//	friend std::ostream& operator<< (std::ostream& os, List &lst);		//<< overload function
	//	void prepend(Node*& head, std::string id);	//prepend function
	//	void append(Node*& head, std::string id);	//append function
} ;

class Stack : public List {	//Stack class
	public:
		friend std::istream& operator>> (std::istream& sin, Stack &stk ); //>> overload finction
		friend std::ostream& operator<< (std::ostream& os, Stack &stk);	//<< overload function
		void push(std::string id);	//push function
		std::string pop();		//pop function
};
#endif

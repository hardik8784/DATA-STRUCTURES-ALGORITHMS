#pragma once
#include "PriorityQueue.h"
#include <iostream>
using namespace std;

int main() {
	PriorityQueue<int> Int(7);
	cout << "Assignment 2 - Hardik Dipakbhai Shah" << endl;
	cout << "Student Id   - 101249099            ";
	cout << endl << endl;

	cout << "------------Push------------" << endl;
	Int.push(500, 1);
	Int.push(910, 4);
	Int.push(600, 4);
	Int.push(400, 2);
	Int.push(800, 1);
	Int.push(890, 2);
	Int.push(500, 3);
	cout << Int;
	cout << endl;

	cout << "------------Front------------" << endl;
	cout << "-------------" << Int.front() << "-------------" <<endl;
	cout << endl << endl;

	cout << "------------Pop------------" << endl;
	Int.pop();
	cout << Int;
	cout << endl;

	cout << "------------Front------------" << endl;
	cout << "-------------"<< Int.front()<<"-------------";
	cout << endl <<endl;
	return 0;
}
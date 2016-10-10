#include<iostream>
#include<thread>

using namespace std;

void threadFunc() {
	cout << "hello thread";
}
int main() {
	thread funtionTest(threadFunc);
	funtionTest.join();
	return 0;
}
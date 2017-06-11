#include <iostream>
#include <klee/klee.h>

using namespace std;

int add(int a, int b){
	return a + b;
}

int main(){
	int a, b;
	klee_make_symbolic(&a, sizeof(a), "a");
	klee_make_symbolic(&b, sizeof(b), "b");
	return add(a, b);
}

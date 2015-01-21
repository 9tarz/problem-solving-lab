/*
LANG: C++
TASK: parentest
*/

#include <cstdio>
#include <iostream>
#include <stack>

int isPaired(char f, char l){
	if (f == '(' && l == ')') return 1;
	else if (f == '[' && l == ']') return 1;
	else if (f == '{' && l == '}') return 1;
	else return 0;
}
int checkedFirst(char f) {
	if (f == '(') return 1;
	else if (f == '[') return 1;
	else if (f == '{') return 1;
	else return 0;
} 

int main(){
	int n;
	scanf("%d", &n);
	int ls[n];
	for(int i = 0; i < n ; i++) {
		char tmp[101]; 
		std::stack <char> parent;
		scanf("%s", tmp);
		int balance = 1;	
		for(int j = 0; tmp[j] != '\0' ;j++) {
			if(checkedFirst(tmp[j])) {
				parent.push(tmp[j]);
			}
			else {
				if (parent.empty() || !isPaired(parent.top(),tmp[j])) {
					balance = 0;
				}
				else {
					parent.pop();
				}
			}
		}
		if(balance ==1 && parent.empty()) {
			ls[i] = 1;
		}
		else {
			ls[i] = 0;
		}
	}
	for(int i =0; i < n ;i++){
		if(ls[i] == 1 ){
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
	}
}
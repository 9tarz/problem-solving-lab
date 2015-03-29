#include <cstdio>
#include <cmath>

int isComma(char c) {
	if (c == ',') 
		return 1;
	return 0; 
}

int countElement(char* strPtr) {

	int num = 0;
	while( *strPtr != '\0') {

		if (isComma(*strPtr) || *strPtr == '}') {
			num++;
		}
		strPtr++;
	}
	return num;

}
main() {

	int numOfElement,result;

	char buffer[1000];

	scanf("%s", buffer);

	if (buffer[0] == '{' && buffer[1] == '}')
		printf("1\n");
	else {
		result = pow(2,countElement(buffer));
		printf("%d\n",result);
	}


}
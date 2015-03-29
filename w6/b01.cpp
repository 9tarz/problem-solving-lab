#include <cstdio>

int isVowel(char c) {
	char vowel[] = {'a', 'e', 'i', 'o', 'u'};
	for (int i = 0; i < 5 ;i++) {
		if (c == vowel[i])
			return 1;
	}
	return 0; 
}
int countSyllables(char* word) {
	int count = 0;
	int num = 0;
	while( *word != '\0') {
		if (isVowel(*word)) {
			count++;
		}
		else {
			if (count > 0)
				num++;
			count = 0;
		}
		//printf("%d\n",count);
		word++;
	}
	word--;
	if (isVowel(*word)) {
			num++;
	}
	return num;

}
	
main() {

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n ;i++) {
		char buffer[31];
		scanf("%s",buffer);
		printf("%d\n",countSyllables(buffer));
	}
}
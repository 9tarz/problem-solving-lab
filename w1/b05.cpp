/*
LANG: C++
TASK: robot1000
*/

#include <stdio.h>

main(){
	char st[101];
	int x,y;
	x = y = 0;
	scanf("%s", st);
	for (int i =0; i < 100 ;i++){
		if (st[i] == 'N')
			y += 1;
		else if (st[i] == 'S')
			y -= 1;
		else if (st[i] == 'E')
			x += 1;
		else if (st[i] == 'W')
			x -= 1;
		else if (st[i] == 'Z'){
			x = 0;
			y = 0;
		}
	}	
	printf("%d %d", x,y);
}
#include <cstdio>
#include <algorithm>
using namespace std;

struct Bag {
  int size;
  int sum;
  Bag(int sz = 0,int sm = 0)
	: size(sz),sum(sm)
	{}
};

bool compare(Bag bg1, Bag bg2) {
	if (bg1.sum == bg2.sum) return bg1.size < bg2.size;
	return bg1.sum < bg2.sum; 
}

main() {

	Bag* bg = new Bag[1000];

	int n,a,b,temp,gap,s_gap;
	scanf("%d %d %d", &n, &a, &b);

	int w[n],s_w[n];

	for(int i =0; i < n;i++) {
		scanf("%d", &w[i]);
		s_w[i] = w[i]; 
	}

	sort(s_w,s_w + n);

	int count = 0;
	for(int i = a; i <= b;i++) {
		if(i >= s_w[n-1]){
			bg[count].size = i;
			count++;
		} 
	}


	for(int i = 0; i < count;i++) {
		temp = gap = s_gap = 0;
		int j = 0;
		int size = bg[i].size;
		while (j < n) {
			temp += w[j];
			//printf("be j: %d >> temp : %d >> bag_size: %d\n",j, temp, bg[i].size);
			if (temp > size) {
				temp -= w[j];
				//printf("%d ", temp);
				gap = size - temp;
				//printf("%d ", gap);
				s_gap += gap;
				temp = 0;
				j--;
				//printf("j: %d\n",j);
			}
			if (j == n - 1 && w[j] < size) {
				gap = size - temp;
				s_gap += gap;
			}
			j++;
		}
		//if (w[n-1] < size) {
			//s_gap += (size - w[n-1]);
		//}
		bg[i].sum = s_gap;
		//printf("sgap %d\n",s_gap );
	}

	sort(bg, bg + count, compare);

	//for(int i = 0; i < count ;i++) {
		//printf("size: %d >> sum: %d\n",bg[i].size, bg[i].sum);
		//printf("%d",bg[0].size);
		//printf("%d\n", bag_size[i]);
	//}

	printf("%d",bg[0].size);

}
#include <vector>
#include <cstdio>
#include <algorithm>
 
using namespace std;

int main()
{
	int n, k, money, sum_price, price ;
	vector<int> prices;
	vector<int>::iterator upper ;

	scanf("%d", &n);
	scanf("%d", &k);

	sum_price = 0 ;
	for (int i = 0 ; i < n ; i++){

		scanf("%d",&price);
		sum_price += price ;
		prices.push_back(sum_price);

	}
	for (int i = 0 ; i < k ; i++){

		scanf("%d",&money);
		upper = upper_bound(prices.begin(), prices.end(), money);

		printf("%d\n",upper - prices.begin());
	}

}
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct Team {
  char name[20];
  int score, goal, goaled, df_goal;
  Team(int sc = 0,int g = 0,int ged = 0, int df = 0)
	: score(sc),goal(g),goaled(ged),df_goal(df)
	{}
};


void print_score(int score[4][4]) {
	for (int i = 0; i < 4 ; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d",score[i][j]);
		}
		printf("\n");
	}
}

bool compare(Team t1, Team t2) {
	if (t1.score == t2.score) return t1.df_goal < t2.df_goal;
	if (t1.df_goal == t2.df_goal) return t1.goal < t2.goal;
	return t1.score < t2.score; 
}


main() {

	int goal[4][4];

	Team* t = new Team[4];
	//vector<Team> t;

	for (int i = 0 ; i < 4; i++) {
		scanf("%s", t[i].name);
	}

	for (int i = 0; i < 4 ; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d",&goal[i][j]);
		}
	}

	for (int i = 0; i < 4 ; i++) {
		for (int j = 0; j < 4; j++) {
			if (goal[i][j] > goal[j][i]) {
				if (i == j)
					continue;
				t[i].score += 3;
			}
			else if (goal[i][j] == goal[j][i] ) {
				if (i == j)
					continue;
				t[i].score += 1;
			}
		}
	}
	for (int i = 0; i < 4 ; i++) {
		for (int j = 0; j < 4; j++) {
				t[i].goal += goal[i][j];
				t[i].goaled += goal[j][i];
		}
	}
	for (int i = 0; i < 4 ; i++) {
		t[i].df_goal = t[i].goal - t[i].goaled;
	}
	
	sort(t, t + 4, compare);

	for (int i = 3 ; i >= 0; i--) {
		printf("%s ",t[i].name);
		//printf("%d ", t[i].goal);
		//printf("%d ", t[i].goaled);
		printf("%d\n", t[i].score);
	}
}
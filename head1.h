#include <string>
using namespace std;

struct sports {
	int fetching = 0;
	int swimming = 0;
	int concur = 0;
	int shooting = 0;
	int running = 0;

};

struct player {
	string surName;
	sports places;
};

player inputPlayer(int);
void Winner(player*, int);

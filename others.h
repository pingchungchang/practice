#include "movie.h"
#include "cinema.h" 
using namespace std;
#define ll long long
typedef struct time{
	ll month;
	ll day;
	ll hour;
	ll minute;
	time();
}time;
typedef struct package{
	movie* mov;
	cinema* cine;
	time t;
	package();
}package;
typedef struct ticketinfo{
	time t;
	int value;
	movie* mov;
	cinema* cine;
}ticket;
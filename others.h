//#include <movie.h>
//#include <cinema.h> 
using namespace std;
#define ll long long
typedef struct time{
	ll month;
	ll day;
	ll hour;
	ll minute;
	time();
	time(ll h,ll m);
	time(ll mon,ll d,ll h,ll m);
}time;
typedef struct package{
//	movie* mov;
//	cinema* cine;
	time t;
	package(time x);
}package;

//#include <movie.h>
using namespace std;

typedef struct time{
	int month;
	int day;
	int hour;
	int minute;
	time(int h,int m){
		hour = h;
		minute= m;
	}
	time(int mon,int d,int h,int m){
		month = mon;
		day=d;
		hour=h;
		minute=m;
	}
}time;
typedef struct package{
//	movie* mov;
//	cinema* cine;
	time t;
	package(time x){
		t.month= x.month;
		t.day = x.day;
		t.hour =x.hour;
		t.minute=x.minute;
	}
}package;
int main(){
	package k(time(1,2,3,4));
	time a(1,2,3,4);
	time b(1,2);
	return 0;
}

using namespace std;
#define ll long long

class movie;
class cinema;

#ifndef others_defined // if "others_defined" no defined => if, else
#define others_defined 1

typedef struct movietime{
	int month;
	int day;
	int hour;
	int minute;
	movietime(){}
	movietime(int h,int m){
		hour = h;
		minute= m;
	}
	movietime(int mon,int d,int h,int m){
		month = mon;
		day=d;
		hour=h;
		minute=m;
	}
}movietime;

typedef struct package{
	movie* mov;
	cinema* cine;
	movietime t;
	package(movietime x){
		t.month= x.month;
		t.day = x.day;
		t.hour =x.hour;
		t.minute=x.minute;
	}
}package;

typedef struct ticketinfo{
	movietime t;
	int value;
	movie* mov;
	cinema* cine;
}ticket;

#endif
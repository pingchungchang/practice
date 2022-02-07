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
	movietime operator+(movietime a){
		movietime newone(this->month+a.month,this->day+a.day,this->hour+a.hour,this->month+a.month);
		if(newone.minute>=60){
			newone.hour += newone.minute/60;
			newone.minute %=60;
		}
		if(newone.hour>=24){
			newone.day += newone.hour/24;
			newone.hour%= 24;
		}
		if(newone.day>30){
			newone.month += newone.day/30;
			newone.day %= 30;
		}
		return newone;
	}
	bool operator+=(movietime a){
		this->month+= a.month;
		this->day += a.day;
		this->hour += a.hour;
		this->minute += a.minute;
		if(this->minute>=60){
			this->hour += this->minute/60;
			this->minute %=60;
		}
		if(this->hour>=24){
			this->day += this->hour/24;
			this->hour%= 24;
		}
		if(this->day>30){
			this->month += this->day/30;
			this->day %= 30;
		}
		return true;
	}
	bool operator>(movietime a){
		if(this->month>a.month)return true;
		else if(this->month != a.month)return false;
		if(this->day>a.day)return true;
		else if(this->day != a.day)return false;
		if(this->hour>a.hour)return true;
		else if(this->hour != a.hour)return false;
		if(this->minute>a.minute)return true;
		return false;
	}
	bool operator<(movietime a){
		if(this->month<a.month)return true;
		else if(this->month != a.month)return false;
		if(this->day<a.day)return true;
		else if(this->day != a.day)return false;
		if(this->hour<a.hour)return true;
		else if(this->hour != a.hour)return false;
		if(this->minute<a.minute)return true;
		return false;
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
	package(movie* x){
		mov = x;
	}
	package(){}
}package;

typedef struct ticketinfo{
	movietime t;
	int value;
	movie* mov;
	cinema* cine;
	ticketinfo(){}
}ticketinfo;

#endif
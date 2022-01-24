#include "salesman.h"
#include "dispatcher.h"
#include "backstage.h"

using namespace std;

salesman::salesman(){
	this->dspatcher = dispatcher::Get_Instance();
	this->bkstage = backstage::Get_Instance();
	this->id = sales_man_num;
	sales_man_num++;
	dspatcher->salesmans.push_back(this);
}

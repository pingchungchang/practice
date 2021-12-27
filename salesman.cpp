using namespace std;

salesman::salesman(){
	this->dspatcher = dispatcher::Get_Instance();
	this->bkstage = backstage::Get_Instance();
	this->id = num;
	num++;
	dspatcher->salemans.push_back(this);
}

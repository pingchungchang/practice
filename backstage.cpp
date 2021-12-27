

backstage::backstage(){
	fstand = new foodstand();
}
static backstage backstage::Get_Instance(){

}
movie* backstage::New_Movie(string name,movietime t,string description,int price_factor){
	movie* newone = new movie();
	newone->name = name;
	newone->duration = t;
	newone->description = description;
	newone->price_factor = price_factor;
	onstage_movies[nowone->name] = newone;
	return newone;
}
cinema* backstage::New_Cinema(int id,int column,int row,string type){
	cinema* c;
	if(type == "kids"){
		c = new cinema();
		c->id = id;
		c->seats = vector<vector<customer*>>(row,vector<customer*>(column,nullptr));
		c->row = row;
		c->column = column;
	}
	this[id] = c;
	return c;
}




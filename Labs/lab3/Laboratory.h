using namespace std;

class Laboratory {
private:

public:
	void execute(void) throw(LaboratoryException) 
	{
		throw LaboratoryException("error thrown");
		cout<<"Failed to throw exception"<<endl;
	}

};

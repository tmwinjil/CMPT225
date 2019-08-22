#include <string>

using namespace std;

class LaboratoryException: public RuntimeException {
private:
	string errorMsg;
public:
	LaboratoryException(const string& err): RuntimeException(err) {;;}

};

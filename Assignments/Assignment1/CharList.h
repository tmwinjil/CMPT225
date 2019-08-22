using namespace std;

struct node {
	char letter;
	struct node *headptr;
	struct node *tailptr;
};

Class CharList
{
public:
	CharList(string s); // constructor. Initializes the list to the contents of the string.
	
	bool empty(); 
	// is the list empty?
	int size(); 
	// the number of elements in the list
	void insert(char c); 
	// inserts the character c at the front of the list
	void append(char c); 
	// inserts the character c at the back of the list
	void insert(char c, char d);
       	/* inserts c immediately before the first occurance of d, or
	 *at the end of the list if d does not occur.
	 */
	void append(char c, char d); 
	/*inserts c immediately after the first occurance of d, or
	 *at the end of the list if d does not occur.
	 */
	void insert(char c, char d, int n);
	/*inserts c immediately before the nth occurance of d, or
	 *at the end of the list if d does not occur n times.
	 */
	 void append(char c, char d, int n); 
	 /*inserts c immediately after the nth occurance of d, or
	  *at the end of the list if d does not occur n times.
	  */
	 void remove(char c); 
	 /*delete the first occurance of character c. Do nothing if
	  * c does not occur.
	  */
	 void remove(char c, int n); 
	 /*delete the n the occurance of c. Do nothing if c does not occur n times.*/
	string toString(); // return the list as a string.
	~CharList(); // destructor. Returns all memory in the list
private:
	node *head, *tail;
	int size;

}

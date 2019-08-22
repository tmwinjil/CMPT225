#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Note: the names in this code use a number of standard prefixes, which you should know.  I've thrown
// in a few others in this list. They can be used with CamelCase or underscore_separated naming conventions.
//
//		min		minimum
//		max		maximum
//		avg		average
//		std		standard
//		temp	temporary (try not to use "temp" by itself as a variable name.  Say what the temporary holds.)
//		num		number of (when used as a prefix only.  Used as a suffix, it indicates an index or ID number.
//					       for example, numFiles is the number of files you have.  fileNum is the ID number
//						   of one particular file.)
//
//	Some people, notably people who learned to use C-style in C++, also use "in" as a prefix for "input", 
//  and "out" as a prefix for "output".  My preference is to not use these prefixes.
//
//  In general, except in the case of the standard prefixes, I advocate writing words out fully.  Don't use
//  "rng" for "range", for instance.  As another example, it would be disastrous to abbreviate "comparisons"
//  in the following main() function as "comp".  When the brain sees "comp" it has to sort out what that
//  means--it could be "computer" or "comprehensive" or "complete" or "computation", etc.--so writing it
//  out is essential.  Most of the comments in the code are meant to help out students and could be eliminated
//  in professional code.
//
//  Note that the correct specification of what a function may throw requires parentheses around the type, as
//  with writeArray() below.

class FileOpeningException {
private:
	string errorMessage;
public:
	FileOpeningException(string message) {
		errorMessage = message;
	}
	string getMessage() {
		return errorMessage;
	}
};

string* readWords(string filename, int & arraySize);
void writeArray(string filename, float *arr, int arraySize) throw (FileOpeningException);
bool isInAlphabeticalOrder(string s, float *compTotal, float *wordLengthTotal, float *numCompPerLength, int *numWordsForLength);

int main (void) {
	int numWords;
	string wordListFilename = "./wordlist";
	string outputFilename = "average_comps.txt";

	// This reads the words from wordListFilename.
	// numWords will be the number of words in the array words
	// words[i] will be the ith word
	string *words = readWords(wordListFilename, numWords);




	// TO DO:: You should compute these values.
	float avgWordLength = 0;
	float avgNumComparisons = 0;
	int maxWordLength = 0;  

	// Find Max Word Length
	for (int i = 0; i < numWords; i++) {
		if (words[i].length() > maxWordLength)
			maxWordLength = words[i].length();
	}

	float *avgComparisonsForLength = new float[maxWordLength + 1];  // avgComparisonsForLength[i] is the average number of comparisons for a word of length i.
	int *numWordsForLength = new int[maxWordLength + 1];

	for (int i = 0; i <= maxWordLength; i++) {
		avgComparisonsForLength[i] = 0;
		numWordsForLength[i] = 0;
	}

	for(int i = 0; i < numWords; i++) {
		isInAlphabeticalOrder(words[i], &avgNumComparisons, &avgWordLength, avgComparisonsForLength, numWordsForLength);
	}

	//Compute averages with all totals
	avgWordLength = avgWordLength / numWords;
	avgNumComparisons = avgNumComparisons / numWords;
	
	cout<<"Average word Length:	"<<avgWordLength<<endl;
	cout<<"Average number of comparisons:	"<<avgNumComparisons<<endl;
	for (int i = 0; i <= maxWordLength; i++) {
		if (numWordsForLength[i] == 0)
			continue;
		else {
			avgComparisonsForLength[i] = avgComparisonsForLength[i] / numWordsForLength[i];
		}
	}


	// Print average number of comparisons for each length to a file for plotting.
	writeArray(outputFilename, avgComparisonsForLength, maxWordLength);

	// Clean up memory and return.
	delete[] words;
	delete[] avgComparisonsForLength;
	delete[] numWordsForLength;
	return 0;
}



// Writes the array arr in text format to a file named filename.
// each element of the array has its own line in the file, 
// which contains the element's index and value, separated by a space.
void writeArray(string filename, float *arr, int arraySize) throw (FileOpeningException) {
	ofstream outputStream(filename.c_str());

	if (outputStream.fail()) {
		throw new FileOpeningException("Error opening " + filename);
	}

	for (int i = 0; i<arraySize; i++) {
		outputStream << i << " " << arr[i] << endl;
	}
	outputStream.close();
}

int numLinesInStream(ifstream& stream) {
	int numLines = 0;
	string tempLine;

	// getline returns 0 at end of file.
	while (getline(stream, tempLine)) {
		numLines++;
	}
	return numLines;
}

// note how the following function is all about one thing:
// the handling of the ifstream called inputStream().
// the exact computation done using inputStream() is abstracted
// to a single call (to numLinesInStream).
// Here, I don't declare the thrown object with a "throw ()" on the
// first line.  It's optional, so I'm leaving it off this time.
int numLinesInFile(string filename) {
	ifstream inputStream(filename.c_str());

	if (inputStream.fail()) {
		throw new FileOpeningException(filename + "... file not found ...");
	}

	int numLines = numLinesInStream(inputStream);

	inputStream.close();
	return numLines;
}

// Reads lines from a file named filename.
// Returns an array of strings, one per line of the file filename, 
// and places the size of the array in the reference parameter (output parameter) arraySize
string* readWords(string filename, int & arraySize) {
	string* result = NULL;
	arraySize = numLinesInFile(filename);
	ifstream inputStream(filename.c_str());

	// Read file contents into result, now that size is known
	result = new string[arraySize];			//create results array
	for (int i=0; i < arraySize; i++){
		getline(inputStream, result[i]);
	}
	inputStream.close(); //don't forget to close file

    return result;
}

/**
 *@brief	Returns whether the word's characters are in alphabetical order. Also tracks number of comparisons and word lengths.
 *
 *@params	{s} word to be checked
 *		{compTotal} running total of number of comparisons
 *		{wordLengthTotal} runningTotal of word lengths
 *		{numCompPerLength} running Total of the number of comparisons per word length
 *		{wordsPerLength} running total of the number of words of a certain length
 *
 *
 *@returns	bool value of whether word letters are in alphabetical order.
 */
bool isInAlphabeticalOrder(string s, float *compTotal, float *wordLengthTotal, float *numCompPerLength, int *wordsPerLength) {
	int length = s.size();
	*wordLengthTotal += length;
	wordsPerLength[length]++;
	for (int i = 0; i <= length; ++i) {
		numCompPerLength[length]++;
		*compTotal += 1;
		if (s[i] > s[i+1]) {
			return false;
		}
	}
	return true;
}


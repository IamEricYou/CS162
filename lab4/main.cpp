// This program demonstrates an application 
// of pure virtual functions.
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class Encryption
{
 protected:
	int key,key2;
	char *arr;
   ifstream inFile;
   ofstream outFile;   
 public:
   Encryption(char *inFileName, char *outFileName);
   Encryption(int i)
   {
	key = i;
   }
   ~Encryption();
   // Pure virtual function
   virtual char transform(char ch, int key) const = 0;
   // Do the actual work.
   void encrypt();
};

//**************************************************
// Constructor opens the input and output file.    *
//**************************************************
Encryption::Encryption(char *inFileName, char *outFileName)
{
   inFile.open(inFileName);
   outFile.open(outFileName);
   if (!inFile) 
     {
       cout <<  "The file " << inFileName 
            << " cannot be opened.";
       exit(1);
     }
   if (!outFile)
    {
      cout << "The file " << outFileName
           << " cannot be opened.";
      exit(1);
    }
}

//**************************************************
//Destructor closes files.                         *
//**************************************************
Encryption::~Encryption()
{
   inFile.close();
   outFile.close(); 
}

//*****************************************************
//Encrypt function uses the virtual transform         *
//member function to transform individual characters. *
//***************************************************** 
void Encryption::encrypt()
{
  char ch;
  char transCh;
  inFile.get(ch);
  while (!inFile.fail())
    {
      transCh = transform(ch,key);
      outFile.put(transCh);
      inFile.get(ch);
    }
}

// The subclass simply overides the virtual
// transformation function
class SimpleEncryption : public Encryption
{
private:
	//int key2;
public:
   char transform(char ch,int key) const
   {
     return ch + key;
   }
   SimpleEncryption(char *inFileName, char *outFileName,int i)
   : Encryption(inFileName, outFileName)
   {
   }
   /*void getkey(int i)
   {
	   key = i;
   }*/
};

class TransformEncryption: public Encryption
{
private:
public:
	char transform(char ch,int key2) const
	{
		return ch;
	}
	TransformEncryption(char *inFileName, char *outFileName)
	: Encryption(inFileName, outFileName)
	{
	}
};

int main()
{
  char inFileName[80], outFileName[80];
  int key1=0,key2;
  cout << "Key? ";
  cin >> key1;
  while(key1 < 0 && key1 > 27)
  {
  	cout << " 1 ~ 26 " << endl;
  	cin >> key1;
  }
  cout << "Enter name of file to encrypt: ";
  cin >> inFileName;
  cout << "Enter name of file to receive " 
       << "the encrypted text: ";
  cin >> outFileName;
  SimpleEncryption obfuscate(inFileName, outFileName,key1);
  //TransformEncryption trans(inFileName, outFileName,key2);
  //obfuscate(key1);
  obfuscate.encrypt();
  return 0;
}

//Kate Blunt
//COP2000.001
//Project 8 

#include<iostream>
#include<fstream>
#include<string>
using std::cout;			
using std::endl;
using std::string;
using std::ifstream;


//To-Do 
//variables for array and file
//open the file
//test the file
//close the file 
//sort the array
//open second file
//read the file
//determine if a name matches the array
//display the results 



class NameSort
{
private:
	ifstream inNames;					//first file
	ifstream inNamesc;					//second file
	static const int SIZE = 20;			//array with set size 
	string names[SIZE];					//names of the array
	int nameCounter = 0;				//name that matches counter
	int nonameCounter = 0;				//name that doesn't match counter
	string sameName;					//string to read names from the second file into 


	void openFile();
	void testFile();
	void closeFile(); 
	void readFile(); 
	void display();
	void sort();
	void openFilen();
	void testFilen(); 
	void readFilen();
	void closeFilen();
	void determine();

public:

	NameSort();
	void driver(); 
};


//**************************Method Definitions*****************************

//NameSort::NameSort
//constructor, set the array to nothing
NameSort::NameSort()
{
	for (int i = 0; i < SIZE; i++)			
	{
		names[i] = ""; 
	}
}


//NameSort::openFile
//open the input file
void NameSort::openFile()
{
	inNames.open("names.txt");

	testFile();

}

//NameSort::testFile
//test to see if the file opens properly
void NameSort::testFile()
{
	using std::cerr;			//only use the cerr twice so put it where it is used
	if (!inNames)

		 
	{
		cerr << "names.txt did not open properly!" << endl; 
		system("pause");
		exit(999); 

	}

}

//NameSort::closeFile
//close the file after reading from it
void NameSort::closeFile()
{
	inNames.close(); 

}

//NameSort::readFile
//read the names into the array
void NameSort::readFile()
{
	string temp;

	for (int j = 0; inNames >> temp && j < SIZE; j++)			//populate the names into the array, only the first 20, because the array is only 20. 
		names[j] = temp;										

}

//NameSort::sort
//sort the names into alphabetical order
void NameSort::sort() 
{
	for (int i = 0; i < SIZE; i++)						//bubble sort into alphabetical order. the minus one is because you have to do one less than the array because you are comparing side-by-side
														//the bubble sort compares to the number or string besides it and moves it down the array. 
		for (int j = 0; j < SIZE - 1; j++)
		{
			if (names[j] > names[j + 1]) 
			{ 
				string temp = names[j];
				names[j] = names[j + 1];
				names[j + 1] = temp; 
			}

		}


}

//NameSort::openFilen
//open the input file
void NameSort::openFilen()
{
	inNamesc.open("moreNames.txt");		

	testFilen();

}

//NameSort::testFilen
//test to see if the file opens properly
void NameSort::testFilen()
{	using std::cerr;				//only use the cerr twice so put it where it is used
	if (!inNamesc)


	{
		cerr << "morenames.txt did not open properly!" << endl;
		system("pause");
		exit(999);

	}

}
//NameSort:: readFilen
//read the file in 
void NameSort::readFilen()
{
	inNamesc >> sameName;			//read the second file into the string sameName

	//cout << sameName << endl;			//used this for testing what was going on 
}



//NameSort::closeFilen
//close the file after reading from it
void NameSort::closeFilen()
{
	inNamesc.close();

}

//NameSort::Determine
//determine if the name matches the other file
void NameSort::determine()
{
	
	readFilen();									//prime read or the file is read twice at the end of it
		while (inNamesc)

		{
			
			
			bool found = false;

			for (int i = 0; i < SIZE; i++)			//have to do the bool because or else the loop goes through 20 times for each name, so you get an absurd number like 200
													// This way each name will be counted once, either not a match or a match. 
													// it keeps looping in this loop up here until it is either through the whole loop and automatically goes down to the bottom, where bool is false, and it
													//adds to the nonameCounter. Or it is true, making it break from the loop and adds to the nameCounter
			{
				if (names[i] == sameName)
				{
					found = true;
					break;
				}

			}
			

				if (found)

				{
					cout << sameName << " is a match." << endl << endl;
					nameCounter++;
				}
				else
				{
					nonameCounter++;
				}
			
				
				readFilen();


		
		
		}
	

}





//NameSort::display
//display the names
void NameSort::display()
{
	//for (int k = 0; k < SIZE; k++)		//testing the first file was sorted properly
		//cout << names[k] << endl; 
	cout << "The total of names that match are: " << nameCounter << endl << endl;
	cout << "The total of names that do not match are: " << nonameCounter << endl; 


}

//NameSort::driver
//order of execution
void NameSort::driver()
{
	//open the first file
	openFile();

	//read the first file into the array
	readFile();

	//close the file
    closeFile();
	
	//sort the first file
	sort();

	//open the second file
	openFilen();

	//determine if the names match with the original file 
	determine();

	//close second file
	closeFilen();

	//display the results
	display();
	
}

//****************************Int Main******************************

int main()
{

	NameSort  nsObj;

	nsObj.driver();

	system("pause");
	return 0; 


}


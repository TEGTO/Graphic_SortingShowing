#include<SFML/Graphics.hpp>
#include<iostream>
#include<ctime>
#include<vector>
#include<thread>
#include<chrono>
#include<fstream>
using namespace std;

enum TypeOfSorting
{
	sBubble = 1, sInsertion, sQuick
};
void displayAnim(sf::RenderWindow& wind,sf::Event ev, sf::RectangleShape sq, vector <int> arrayToDisplay, int animationSpeedCoeff=50,int elementToFill=0)
{
	sq.setFillColor(sf::Color::White);
	int size = arrayToDisplay.size();
	int iterator = 0;
	int x = 0, y = 0, l = 0, count = 0,  check = 0;
	float height = 0;
	wind.clear();
		while (wind.pollEvent(ev))

		{
			if (ev.type == sf::Event::Closed)
			{
				wind.close();
			}
		}
		count = 0, iterator = -1;
		x = 0, y = 580, height = 0;
		sq.setPosition(x, y);
		while (count != size && check != 1)
		{
			sq.setFillColor(sf::Color::White);
			count++;
			iterator++;
			height = arrayToDisplay[iterator] * 10;
			sq.setSize(sf::Vector2f(20.0, -height));
			if (iterator == elementToFill)
			{
				sq.setFillColor(sf::Color::Red);
			}
			wind.draw(sq);
			x += 25;
			sq.setPosition(x, y);
		}
		if (check != 1)
		{
			wind.display();
			this_thread::sleep_for(chrono::milliseconds(animationSpeedCoeff));
		}
		
		
	
} 

void quickSort(vector <int> arrayToSort,sf::RenderWindow & wind, sf::Event ev, sf::RectangleShape sq, int animationSpeedCoeff)
{
	displayAnim(wind, ev, sq, arrayToSort, animationSpeedCoeff);
	int arraySize = arrayToSort.size();
	int elementToFill=0;
	for (int i = 0; i < arraySize;) {
		for (int j = i + 1; j < arraySize; j++) {
			if (arrayToSort[j] < arrayToSort[j - 1])
			{
				swap(arrayToSort[j], arrayToSort[j - 1]);
				elementToFill = j;
				displayAnim(wind, ev, sq, arrayToSort, animationSpeedCoeff, elementToFill);
			}
			
		}
		arraySize--;
		for (int k = arraySize - 1; k > i; k--) {
			if (arrayToSort[k] < arrayToSort[k - 1])
			{
				swap(arrayToSort[k], arrayToSort[k - 1]);
				elementToFill = k;
				displayAnim(wind, ev, sq, arrayToSort, animationSpeedCoeff, elementToFill);
			}
				
		}
		i++;
	}
	
}
void insertionSort(vector <int> arrayToSort, sf::RenderWindow& wind, sf::Event ev, sf::RectangleShape sq, int animationSpeedCoeff)
{
	int oneCycle, key, secondCycle;
	int arraySize = arrayToSort.size();
	int elementToFill = 0;
	displayAnim(wind, ev, sq, arrayToSort, animationSpeedCoeff, elementToFill);
	for (oneCycle = 1; oneCycle < arraySize; oneCycle++)
	{
		key = arrayToSort[oneCycle];
		secondCycle = oneCycle - 1;

		
		while (secondCycle >= 0 && arrayToSort[secondCycle] > key)
		{
			elementToFill = secondCycle;
			displayAnim(wind, ev, sq, arrayToSort, animationSpeedCoeff, elementToFill);
			arrayToSort[secondCycle + 1] = arrayToSort[secondCycle];
			secondCycle--;

		}
		arrayToSort[secondCycle + 1] = key;
		elementToFill = secondCycle+1;
		displayAnim(wind, ev, sq, arrayToSort, animationSpeedCoeff, elementToFill);

	}
	
}
void bubbleSort(vector <int> arrayToSort, sf::RenderWindow& wind, sf::Event ev, sf::RectangleShape sq, int animationSpeedCoeff)
{
	int oneCycle, secondCycle;
	int arraySize = arrayToSort.size();
	int elementToFill = 0;
	displayAnim(wind, ev, sq, arrayToSort, animationSpeedCoeff, elementToFill);
	for (oneCycle = 0; oneCycle < arraySize - 1; oneCycle++)
		for (secondCycle = 0; secondCycle < arraySize - oneCycle - 1; secondCycle++)
			if (arrayToSort[secondCycle] > arrayToSort[secondCycle + 1])
				
			{
				swap(arrayToSort[secondCycle], arrayToSort[secondCycle + 1]);
				elementToFill = secondCycle+1;
				displayAnim(wind, ev, sq, arrayToSort, animationSpeedCoeff, elementToFill);
			}
}

void menu()
{

	ifstream writeSpeedToFile;
	ofstream readSpeedFromFile;
	int countElementsInArray = 0, arraySize;
	int animationSpeed;
	double widghtResolution=800;
	char typeOfSorting;
	int checkIfAnimationIsWorking = 1, checkDoesProgramNeedToWork = 1;
	double random = rand() % 55; // 55 - height of one block
	cout << "Enter the size" << endl;
	cout << "\nEnter: ";
	cin >> arraySize;
	vector <int> arrayToSort;
	srand(time(NULL));
	while (countElementsInArray != arraySize)
	{
		random = rand() % 550;
		random /= 10;
		arrayToSort.push_back(random);
		countElementsInArray++;
	}
	arrayToSort.erase(unique(arrayToSort.begin(), arrayToSort.end()), arrayToSort.end());
	if (arraySize >30)
	{
		 widghtResolution = 25	* arraySize; //25 - widght of one block
	}

	sf::RenderWindow wind(sf::VideoMode(widghtResolution, 600), "Title");
	sf::Event ev{};
	sf::RectangleShape rectangle;
	if (arraySize>30)
	{
		
		double size1 = double(arraySize);
		widghtResolution += ((size1 * 100 / 30) - 100) / 100;
	}

	while (checkDoesProgramNeedToWork!=0)
	{
		cout << "\nChooice the sort's type:\n";
		cout << "1.Bubble\n2.Insertion\n3.Quick\nS.Change the speed\nE.Exit\nEnter: ";
		cin >> typeOfSorting;
		
		writeSpeedToFile.open("Speed.txt");
		writeSpeedToFile >> animationSpeed;
		writeSpeedToFile.close();
		switch (typeOfSorting)
		{
		case '1':
			bubbleSort(arrayToSort, wind, ev, rectangle, animationSpeed);
			break;
		case '2':
			insertionSort(arrayToSort, wind, ev, rectangle, animationSpeed);
			break;
		case '3':
			quickSort(arrayToSort, wind, ev, rectangle, animationSpeed);
			break;
		case 'S':
			while (checkIfAnimationIsWorking != 0)
			{
				cout << "\n1.Look the current speed\n2.Enter new speed\n3.Reset to default\nE.Exit\nEnter: ";
				cin >> typeOfSorting;
				switch (typeOfSorting)
				{
				case '1':
										
					cout << "\nCurrent speed = " << animationSpeed << endl;
					break;
				case'2':

					cout << "\nEnter the new speed:\n";
					cin >> animationSpeed;
					readSpeedFromFile.open("Speed.txt");
					readSpeedFromFile << animationSpeed;
					readSpeedFromFile.close();
					break;
				case '3':
					animationSpeed = 50;
					readSpeedFromFile.open("Speed.txt");
					readSpeedFromFile << animationSpeed;
					readSpeedFromFile.close();
					break;
				default:
					checkIfAnimationIsWorking = 0;
					break;
				}
				
			}
			checkIfAnimationIsWorking = 1;
			break;
		default:
			checkDoesProgramNeedToWork = 0;
			break;
		}
	}
	
	
}
int main()
{
	menu();
	
	

	return 0;
}
#include<SFML/Graphics.hpp>
#include<iostream>
#include<ctime>
#include<vector>
#include<thread>
#include<chrono>
using namespace std;

enum TypeOfSorting
{
	Sbubble=1, Sinsertion,Sshaker
};
//void display(vector <int> vc,int j=-1)
//{
//	sf::RenderWindow wind(sf::VideoMode(800, 600), "Title");
//	sf::Event ev;
//	sf::RectangleShape sq;
//	sq.setFillColor(sf::Color::White);
//	int size = vc.size();
//	int x = 0, y = 0, l = 0, count = 0, it = 0, check = 0;
//	float height = 0;
//	wind.clear();
//		while (wind.pollEvent(ev))
//
//		{
//			if (ev.type == sf::Event::Closed)
//			{
//				wind.close();
//			}
//		}
//		count = 0, it = -1;
//		x = 0, y = 580, height = 0;
//		sq.setPosition(x, y);
//		while (count != size && check != 1)
//		{
//			sq.setFillColor(sf::Color::White);
//			count++;
//			it++;
//			height = vc[it] * 10;
//			sq.setSize(sf::Vector2f(20.0, -height));
//			if (it ==j)
//			{
//				sq.setFillColor(sf::Color::Red);
//			}
//			wind.draw(sq);
//			x += 25;
//			sq.setPosition(x, y);
//		}
//		if (check != 1)
//		{
//			wind.display();
//			
//		}
//		
//		
//	
//} // не робит 

void shaker(vector <int> vc, int size, double coeff=1)
{
	int i, j, k;
	
	sf::RenderWindow wind(sf::VideoMode(800*coeff, 600), "Title");
	sf::Event ev;
	sf::RectangleShape sq;
	sq.setFillColor(sf::Color::White);
	int x = 0, y = 0, l = 0, count = 0, it = 0, check = 0;
	float height = 0;
	while (wind.isOpen())
	{


		while (wind.pollEvent(ev))

		{
			if (ev.type == sf::Event::Closed)
			{
				wind.close();
			}
		}
		count = 0, it = -1;
		x = 0, y = 580, height = 0;
		sq.setPosition(x, y);
		while (count != size && check != 1)
		{
			count++;
			it++;
			height = vc[it] * 10;
			sq.setSize(sf::Vector2f(20.0, -height));
			wind.draw(sq);
			x += 25;
			sq.setPosition(x, y);
		}
		if (check != 1)
		{
			wind.display();
			this_thread::sleep_for(chrono::seconds(1));
		}
		int size1 = size;
		while (true)
		{
			for (i = 0; i < size1;) {
				for (j = i + 1; j < size1; j++) {
					if (vc[j] < vc[j - 1])
					{
						swap(vc[j], vc[j - 1]);
						wind.clear();
						count = 0, it = -1;
						x = 0, y = 580, height = 0;
						sq.setPosition(x, y);

						while (count != size && check != 1)
						{
							sq.setFillColor(sf::Color::White);
							count++;
							it++;
							height = vc[it] * 10;
							if (it == j)
							{
								sq.setFillColor(sf::Color::Red);
							}
							sq.setSize(sf::Vector2f(20.0, -height));
							wind.draw(sq);
							x += 25;
							sq.setPosition(x, y);
						}
						if (check != 1)
						{
							wind.display();
							this_thread::sleep_for(chrono::milliseconds(50));

						}
					}
				}
				size1--;
				for (k = size1 - 1; k > i; k--) {
					if (vc[k] < vc[k - 1])
					{
						swap(vc[k], vc[k - 1]);
						wind.clear();
						count = 0, it = -1;
						x = 0, y = 580, height = 0;
						sq.setPosition(x, y);

						while (count != size && check != 1)
						{
							sq.setFillColor(sf::Color::White);
							count++;
							it++;
							height = vc[it] * 10;
							if (it == k)
							{
								sq.setFillColor(sf::Color::Red);
							}
							sq.setSize(sf::Vector2f(20.0, -height));
							wind.draw(sq);
							x += 25;
							sq.setPosition(x, y);
						}
						if (check != 1)
						{
							wind.display();
							this_thread::sleep_for(chrono::milliseconds(50));

						}
					}
				}
				i++;
			}
			
						

					
			check = 1;

		}
	}
}
void insertion(vector <int> vc, int size, double coeff = 1)
{
	int buff = 0; 
	int i, j;

	

	sf::RenderWindow wind(sf::VideoMode(800*coeff, 600), "Title");
	sf::Event ev;
	sf::RectangleShape sq;
	sq.setFillColor(sf::Color::White);
	int x = 0, y = 0, l = 0, count = 0, it = 0, check = 0;
	float height = 0;
	while (wind.isOpen())
	{


		while (wind.pollEvent(ev))

		{
			if (ev.type == sf::Event::Closed)
			{
				wind.close();
			}
		}
		count = 0, it = -1;
		x = 0, y = 580, height = 0;
		sq.setPosition(x, y);
		while (count != size && check != 1)
		{
			count++;
			it++;
			height = vc[it] * 10;
			sq.setSize(sf::Vector2f(20.0, -height));
			wind.draw(sq);
			x += 25;
			sq.setPosition(x, y);
		}
		if (check != 1)
		{
			wind.display();
			this_thread::sleep_for(chrono::seconds(1));
		}
	
		while (true)
		{
			
			for (i = 1; i < size; i++)
			{
				buff = vc[i];

				for (j = i - 1; j >= 0 && vc[j] > buff; j--)
				{
					vc[j + 1] = vc[j];
					wind.clear();
					count = 0, it = -1;
					x = 0, y = 580, height = 0;
					sq.setPosition(x, y);

					while (count != size && check != 1)
					{
						sq.setFillColor(sf::Color::White);
						count++;
						it++;
						height = vc[it] * 10;
						if (it == j)
						{
							sq.setFillColor(sf::Color::Red);
						}
						sq.setSize(sf::Vector2f(20.0, -height));
						wind.draw(sq);
						x += 25;
						sq.setPosition(x, y);
					}
					if (check != 1)
					{
						wind.display();
						this_thread::sleep_for(chrono::milliseconds(50));

					}

				}


				vc[j + 1] = buff;
			}
						
					
			check = 1;

		}
	}
	
}
void bubble(vector <int> vc, int size, double coeff = 1)
{
	sf::RenderWindow wind(sf::VideoMode(800*coeff, 600), "Title");
	sf::Event ev;
	sf::RectangleShape sq;
	sq.setFillColor(sf::Color::White);
	int x = 0, y = 0, l = 0, count = 0, it = 0,check = 0;
	float height = 0;
	while (wind.isOpen())
	{


		while (wind.pollEvent(ev))

		{
			if (ev.type == sf::Event::Closed)
			{
				wind.close();
			}
		}
		count = 0, it = -1;
		x = 0, y = 580, height = 0;
		sq.setPosition(x, y);
		while (count != size && check != 1)
		{
			count++;
			it++;
			height = vc[it] * 10;
			sq.setSize(sf::Vector2f(20.0, -height));
			wind.draw(sq);
			x += 25;
			sq.setPosition(x, y);
		}
		if (check != 1)
		{
			wind.display();
			this_thread::sleep_for(chrono::seconds(1));
		}
		int i, j;
		while (true)
		{
			for (i = 0; i < size - 1; i++)
				for (j = 0; j < size - i - 1; j++)
					if (vc[j] > vc[j + 1])
					{
						swap(vc[j], vc[j + 1]);
						wind.clear();
						count = 0, it = -1;
						x = 0, y = 580, height = 0;
						sq.setPosition(x, y);
						
						while (count != size && check != 1)
						{
							sq.setFillColor(sf::Color::White);
							count++;
							it++;
							height = vc[it] * 10;
							if (it ==j)
							{
								sq.setFillColor(sf::Color::Red);
							}
							sq.setSize(sf::Vector2f(20.0, -height));
							wind.draw(sq);
							x += 25;
							sq.setPosition(x, y);
						}
						if (check != 1)
						{
							wind.display();
							this_thread::sleep_for(chrono::milliseconds(50));

						}

					}
			check = 1;

		}
	}
}

void menu()
{

	int count = 0, size, type;
	cout << "Enter the size" << endl;
	cout << "\nEnter: ";
	cin >> size;
	vector <int> vc;
	int random = rand() % 55;
	srand(time(NULL));
	while (count != size)
	{
		random = rand() % 55;
		vc.push_back(random);
		count++;
	}
	double coeff = 1;
	
	if (size>30)
	{
		
		double size1 = double(size);
		coeff += ((size1 * 100 / 30) - 100) / 100;
	}
	cout << "\nChooice the sort's type:\n";
	cout << "1.Bubble\n2.Insertion\n3.Quick\n\nEnter: ";
	cin >> type;
	switch (type)
	{
	case Sbubble:
		bubble(vc, size,coeff);
		break;
	case Sinsertion:
		insertion(vc, size,coeff);
		break;
	case Sshaker:
		shaker(vc, size,coeff);
		break;
	default:
		break;
	}
	
}
int main()
{
	menu();
	
	

	return 0;
}
#include<SFML/Graphics.hpp>
#include<iostream>
#include<ctime>
#include<vector>
#include<thread>
#include<chrono>
using namespace std;



void bubble(vector <int> vc, int size)
{
	sf::RenderWindow wind(sf::VideoMode(800, 600), "Title");
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
							this_thread::sleep_for(chrono::milliseconds(50));

						}

					}
			check = 1;

		}
	}
}

int main()
{

	
	int count=0,size;
	cout << "Enter the size" << endl;
	cin >> size;
	vector <int> vc;
	int random = rand () % 55;
	srand(time(NULL));
	while (count!=size)
	{
		random = rand() % 55;
		vc.push_back(random);
			count++;
	}

	bubble(vc, size);

	return 0;
}
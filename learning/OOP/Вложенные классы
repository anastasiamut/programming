//Вложенные классы


#include "pch.h"
#include <iostream>
#include <string>
using namespace std;


class Image
{
public:
	class Pixel
	{
	private:
		int r;
		int g;
		int b;
	public:
		Pixel(int r, int g, int b)
		{
			this->r = r;
			this->g = g;
			this->b = b;
		}
		string GetInfo()
		{
			return "Pixel: r =" + to_string(r) + " g = " + to_string(g) + " b = " + to_string(b);
		}
	};
	void GetImageInfo()
	{
		for (int i = 0; i < LENGTH; i++)
		{
			cout<<"#"<<i<<pixels[i].GetInfo();
			cout << endl;
		}

	}
private:


	static const int LENGTH = 5;
	Pixel pixels[LENGTH]
	{
		Pixel(0,4,64),
		Pixel(4, 14, 10),
		Pixel(111, 4, 24),
		Pixel(244,244,12),
		Pixel(111,179,64)

	};
};


int main()
{
	Image img;
	Image::Pixel p(1, 1, 1);
	cout << p.GetInfo() << endl;
	
	img.GetImageInfo();
}


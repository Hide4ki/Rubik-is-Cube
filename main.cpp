#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "figure.h"
#include "myException.h"

using namespace std;

int main(void)
{
	point p[8];
	p[0] = point(100, 100,-25);
	p[1] = point(150, 100,-25);
	p[2] = point(150, 150,-25);
	p[3] = point(100, 150,-25);
	p[4] = point(100, 100, 25);
	p[5] = point(150, 100, 25);
	p[6] = point(150, 150, 25);
	p[7] = point(100, 150, 25);
	figure *myFigure = new figure(p);
	matrixMOV left(-5,0,0);
	matrixMOV right(5,0,0);
	matrixMOV top(0,-5,0);
	matrixMOV bottom(0,5,0);
	matrixMOV forward(0,0,5);
	matrixMOV back(0,0,-5);
	matrixSCALE less(0.5,0.5,0.5);
	matrixSCALE more(2,2,2);
	matrixROTX leftRX(10);
	matrixROTX rightRX(-10);
	matrixROTY leftRY(10);
	matrixROTY rightRY(-10);
	matrixROTZ leftRZ(10);
	matrixROTZ rightRZ(-10);
	for(;;)
	{
		try
		{
			switch(_getch())
			{
			case 'r':
				delete myFigure;
				myFigure = new figure(p);
				break;
			case 'q':
				myFigure->move(bottom);
				break;
			case 'w':
				myFigure->move(forward);
				break;
			case 'e':
				myFigure->move(top);
				break;
			case 'a':
				myFigure->move(left);
				break;
			case 's':
				myFigure->move(back);
				break;
			case 'd':
				myFigure->move(right);
				break;
			case 'z':
				myFigure->scale(less);
				break;
			case 'x':
				myFigure->scale(more);
				break;
			case 'y':
				myFigure->rot<matrixROTX>(leftRX);
				break;
			case 'u':
				myFigure->rot<matrixROTX>(rightRX);
				break;
			case 'h':
				myFigure->rot<matrixROTY>(leftRY);
				break;
			case 'j':
				myFigure->rot<matrixROTY>(rightRY);
				break;
			case 'n':
				myFigure->rot<matrixROTZ>(leftRZ);
				break;
			case 'm':
				myFigure->rot<matrixROTZ>(rightRZ);
				break;
			case  27:
				delete myFigure;
				return 0;
				break;
			}
		}
		catch(myException e)
		{
			cout << e;
		}
	}

}
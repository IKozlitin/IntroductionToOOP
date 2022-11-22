#include<iostream>
using namespace std;

class Point
{
//private:
	double x;
	double y;
public:

	//snake_case_style
	//camelCaseStyle
	//pascalCaseStyle
	//smallCamel
	//BigCamel

	//			Encapsulation:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	//			Constructors:
	
	/*Point()
	{
		x = y = double();//Значение по умолчанию для double
		cout << "Constructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;//Значение с одним аргументом
		this->y = 0;
		cout << "1argConstructor:" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	Point(const Point& other) //copy constructor
	{
		this->x = other.x;
		this->y = other.y;
		cout << "copyconstructor:" << this << endl;
	}
	~Point()				  //Destructor
	{
		cout << "Destructor:\t" << this << endl;
	}
							  //Methods:
	double distance(const Point& other)const
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}

//#define STRUCT_POINT
#define DISTANCE_CHEK
//#define CONSTRUCTORS_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK

	Point A;	//Default constructor
	A.print();

	Point B = 5;//Single-argument constructor
	B.print();

	Point C = 8;//Single-argument constructor
	C.print();

	Point D(5, 8);//Parametrised constructor
	D.print();

	Point E = D;//Copy constructor
	E.print();
#endif // CONSTRUCTION_CHECK
#ifdef DISTANCE_CHEK
	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << "Расстояниеот точки 'А' до точки 'B':\t " << A.distance(B) << endl;
	cout << "Расстояниеот точки 'B' до точки 'A':\t " << B.distance(A) << endl;
	cout << "Расстояние между точками 'A' и 'B':\t " << distance(A, B) << endl;
	cout << "Расстояние между точками 'A' и 'B':\t " << distance(B, A) << endl;
#endif // DISTANCE_CHEK
#ifdef STRUCT_POINT
	int a;
	Point A;
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;
	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT
}
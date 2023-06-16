//#include <iostream>
//using namespace std;
//
//class RationalNumber
//{
//	int numer;
//	int denom;
//
//public:
//	RationalNumber(int n = 1, int d = 1)
//	{
//		if (d > 0)
//		{
//			numer = n;
//			denom = d;
//
//
//			// simplify
//			for (int i = 2; i <= abs(numer) && i <= denom; i++)
//			{
//			 if (numer % i == 0 && denom % i == 0)
//				{
//					numer /= i;
//					denom /= i;			
//					i = 1;					
//				}
//			}
//		}
//		else
//		{
//			cout << "Error!";
//		}
//	}
//
//	RationalNumber operator+(const RationalNumber &obj)
//	{
//		RationalNumber n;
//		n.denom = denom * obj.denom;
//		n.numer = (numer * obj.denom) + (denom * obj.numer);
//		return n;
//	}
//
//	RationalNumber operator-(const RationalNumber &obj)
//	{
//		RationalNumber n;
//		n.denom = denom * obj.denom;
//		n.numer = (numer * obj.denom) - (denom * obj.numer);
//		return n;
//	}
//
//
//	void display()
//	{
//		cout <<"Numerator:" <<numer<<endl;
//		cout <<"Denominator:"<< denom << endl;
//	}
//
//	~RationalNumber()
//	{
//		numer = 0;
//		denom = 0;
//	}
//
//};
//
//int main()
//{
//	RationalNumber n1(4,8);
//	n1.display();
//	RationalNumber n2(3,4);
//	n2.display();
//
//	RationalNumber n3;
//	n3 = n1 + n2;
//
//	n3.display();
//
//	RationalNumber n4;
//	n4 = n1 - n2;
//
//	n4.display();
//
//	system("PAUSE");
//	return 0;
//}
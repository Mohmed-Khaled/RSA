/*
Ain Shams University
Faculty of Engineering
RSA Project for CSE432 Computer Security Fall 2016
Name: Mohamed Khaled Gamil Ismail
ID: 1201154
*/

#include <iostream>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;

#define BASE 1000000000
#define DIGITS_PER_ELEMENT 9 // digits per array element
#define MAX_SIZE 70
#define MAX_VALUE (BASE - 1)
#define LSD (MAX_SIZE - 1)

class LongNumber
{
public:
	LongNumber();
	LongNumber(long long n);
	LongNumber(string n_str);
	LongNumber operator+(const LongNumber& b);
	LongNumber operator-(const LongNumber& b);
	LongNumber operator*(const LongNumber& b);
	LongNumber operator/(const LongNumber& b);
	LongNumber operator%(const LongNumber& b);
	bool operator==(const LongNumber& b);
	bool operator!=(const LongNumber& b);
	bool operator<(const LongNumber& b);
	bool operator>(const LongNumber& b);
	bool operator<=(const LongNumber& b);
	bool operator>=(const LongNumber& b);
	LongNumber ModularExponentiation(const LongNumber& power, const LongNumber& mod);
	LongNumber ModularInverse(const LongNumber& mod);
	LongNumber MulExponententBase(int power);
	LongNumber DivExponententBase(int power);
	LongNumber ModExponententBase(int power);
	LongNumber MulExponentent10(int power);
	LongNumber DivExponentent10(int power);
	LongNumber Absolute();
	bool IsPrime(int iterations);
	bool IsEven();
	bool IsOdd();
	string GetStringNumber();
	int GetNumberOfDigits();
private:
	bool sign; //true means positive and false means negative
	unsigned long long number[MAX_SIZE];
	int size;
	void Insert(unsigned long long n);
	void Append(unsigned long long n, int count);
	bool MillerRabinTest(LongNumber& n, LongNumber& q, int k);
	LongNumber static REDC(LongNumber & N, LongNumber& N_inv, LongNumber& T);
};

void test_addition_time(int n)
{
	LongNumber x("12369571528747655798110188786567180759626910465726920556567298659370399748072366507234899432827475865189642714067836207300153035059472237275816384410077871");
	LongNumber y("2065420353441994803054315079370635087865508423962173447811880044936318158815802774220405304957787464676771309034463560633713497474362222775683960029689473");
	clock_t begin = clock();
	for (int i = 0; i < n; i++)
	{
		LongNumber z = x + y;
	}
	clock_t end = clock();
	cout << "Addition Time = " << double(end - begin) / CLOCKS_PER_SEC << endl;
	cout << "RESULT = " << (x + y).GetStringNumber() << endl << endl;
}

void test_subtraction_time(int n)
{
	LongNumber x("12369571528747655798110188786567180759626910465726920556567298659370399748072366507234899432827475865189642714067836207300153035059472237275816384410077871");
	LongNumber y("2065420353441994803054315079370635087865508423962173447811880044936318158815802774220405304957787464676771309034463560633713497474362222775683960029689473");
	clock_t begin = clock();
	for (int i = 0; i < n; i++)
	{
		LongNumber z = x - y;
	}
	clock_t end = clock();
	cout << "Subtraction Time = " << double(end - begin) / CLOCKS_PER_SEC << endl;
	cout << "RESULT = " << (x - y).GetStringNumber() << endl << endl;
}

void test_multiplication_time(int n)
{
	LongNumber x("4397678428390379126255360246165021910057442267382175543246817108158797115317154540746718616555865161372450860559307149988169566508274711121236049281217144195628407516579953387138808449458611836421032431582081899650685651973204503916459595600207918950383877057152533041873901965623112895996177941667469292738");
	LongNumber y("4397678428390379126255360246165021910057442267382175543246817108158797115317154540746718616555865161372450860559307149988169566508274711121236049281217144195628407516579953387138808449458611836421032431582081899650685651973204503916459595600207918950383877057152533041873901965623112895996177941667469292738");
	clock_t begin = clock();
	for (int i = 0; i < n; i++)
	{
		LongNumber z = x * y;
	}
	clock_t end = clock();
	cout << "Multiplication Time = " << double(end - begin) / CLOCKS_PER_SEC << endl;
	cout << "RESULT = " << (x * y).GetStringNumber() << endl << endl;
}

void test_division_time(int n)
{
	//LongNumber x("613146241500251217781901182511578808656343996048865281195067222865875354435414754879740860169824341435779835004773419788215233286755223570756287073597240575020868820262738469079836284381887865043849058594244529999914407749623070473656002187994440630465017165980166916860301334175145980082772439857221824948844421903362650679826662219735503474838915729563886599030273053547440858613719791522407802156967772707196919240610998753813018909978568881709034791373718526666771136015908120183409001795657352");
	LongNumber x("4397678428390379126255360246165021910057442267382175543246817108158797115317154540746718616555865161372450860559307149988169566508274711121236049281217144195628407516579953387138808449458611836421032431582081899650685651973204503916459595600207918950383877057152533041873901965623112895996177941667469292738");
	LongNumber y("25548364798832019218170326077010425733930233389897468141147917831084690989884562791601588954296621731652139141347541240725432606132471100644835778517336041031200174441223836394229943651678525471050219216183727749114047330431603023948126844573697946795476319956787513765533596926704755530772983549787878951983");
	LongNumber z;
	clock_t begin = clock();
	for (int i = 0; i < n; i++)
	{
		z = (x * x) / y;
	}
	clock_t end = clock();
	cout << "Division Time = " << double(end - begin) / CLOCKS_PER_SEC << endl;
	cout << "RESULT = " << z.GetStringNumber() << endl << endl;
}

void test_mod_time(int n)
{
	//LongNumber x("613146241500251217781901182511578808656343996048865281195067222865875354435414754879740860169824341435779835004773419788215233286755223570756287073597240575020868820262738469079836284381887865043849058594244529999914407749623070473656002187994440630465017165980166916860301334175145980082772439857221824948844421903362650679826662219735503474838915729563886599030273053547440858613719791522407802156967772707196919240610998753813018909978568881709034791373718526666771136015908120183409001795657352");
	LongNumber x("4397678428390379126255360246165021910057442267382175543246817108158797115317154540746718616555865161372450860559307149988169566508274711121236049281217144195628407516579953387138808449458611836421032431582081899650685651973204503916459595600207918950383877057152533041873901965623112895996177941667469292738");
	LongNumber y("25548364798832019218170326077010425733930233389897468141147917831084690989884562791601588954296621731652139141347541240725432606132471100644835778517336041031200174441223836394229943651678525471050219216183727749114047330431603023948126844573697946795476319956787513765533596926704755530772983549787878951983");
	LongNumber z;
	clock_t begin = clock();
	for (int i = 0; i < n; i++)
	{
		z = (x * x) % y;
	}
	clock_t end = clock();
	cout << "Mod Time = " << double(end - begin) / CLOCKS_PER_SEC << endl;
	cout << "RESULT = " << z.GetStringNumber() << endl << endl;
}

void test_division_time2(int n)
{
	LongNumber x("25051719899710729069339146813050963409059898810366373119834423967819636191509401691818253978210229371822961344590338934536803264841097247978074700319812702399440521918349189245279566231685265955731649745935378380489722580113725907099133943430294137060596724659637599737926649148356615085679203385772673944833");
	clock_t begin = clock();
	for (int i = 0; i < n; i++)
	{
		LongNumber z = x / 2;
	}
	clock_t end = clock();
	cout << "Division By 2 Time = " << double(end - begin) / CLOCKS_PER_SEC << endl;
	cout << "RESULT = " << (x / 2).GetStringNumber() << endl << endl;
}

void test_prime_check_time(string p_str, int i)
{
	LongNumber x(p_str);
	clock_t begin = clock();
	bool check = x.IsPrime(i);
	clock_t end = clock();
	cout << "Prime Check Time for " << p_str << " = "
		<< double(end - begin) / CLOCKS_PER_SEC << endl;
	cout << ((check) ? "Prime" : "Not Prime") << endl << endl;
}

void test_modular_exponentiation_time(string m_str, string e_str, string n_str)
{
	LongNumber m(m_str);
	LongNumber e(e_str);
	LongNumber n(n_str);
	clock_t begin = clock();
	LongNumber r = m.ModularExponentiation(e, n);
	clock_t end = clock();
	cout << "Modular Exponentiation Time for M = " << m_str
		<< " and e = " << e_str
		<< " and n = " << n_str << " : "
		<< double(end - begin) / CLOCKS_PER_SEC << endl;
	cout << "Result = " << r.GetStringNumber() << endl << endl;
}

string Encrypt(const string& message, const LongNumber& number, const LongNumber& mod);

int main()
{
	// TEST START
	int test_itr = 1000;
	test_addition_time(test_itr);
	test_subtraction_time(test_itr);
	test_multiplication_time(test_itr);
	test_division_time(test_itr);
	test_mod_time(test_itr);
	test_division_time2(test_itr);
	string m_str = "88";
	string c_str = "4397678428390379126255360246165021910057442267382175543246817108158797115317154540746718616555865161372450860559307149988169566508274711121236049281217144195628407516579953387138808449458611836421032431582081899650685651973204503916459595600207918950383877057152533041873901965623112895996177941667469292738";
	string e_str = "65537";
	string d_str = "25051719899710729069339146813050963409059898810366373119834423967819636191509401691818253978210229371822961344590338934536803264841097247978074700319812702399440521918349189245279566231685265955731649745935378380489722580113725907099133943430294137060596724659637599737926649148356615085679203385772673944833";
	string n_str = "25548364798832019218170326077010425733930233389897468141147917831084690989884562791601588954296621731652139141347541240725432606132471100644835778517336041031200174441223836394229943651678525471050219216183727749114047330431603023948126844573697946795476319956787513765533596926704755530772983549787878951983";
	string p_str = "12369571528747655798110188786567180759626910465726920556567298659370399748072366507234899432827475865189642714067836207300153035059472237275816384410077871";
	string q_str = "2065420353441994803054315079370635087865508423962173447811880044936318158815802774220405304957787464676771309034463560633713497474362222775683960029689473";
	test_modular_exponentiation_time(m_str, e_str, n_str);
	test_modular_exponentiation_time(c_str, d_str, n_str);
	test_prime_check_time(p_str, 3);
	test_prime_check_time(q_str, 3);
	// TEST END
	string P_str, Q_str, E_str;
	P_str = "P=12369571528747655798110188786567180759626910465726920556567298659370399748072366507234899432827475865189642714067836207300153035059472237275816384410077871";
	Q_str = "Q=2065420353441994803054315079370635087865508423962173447811880044936318158815802774220405304957787464676771309034463560633713497474362222775683960029689473";
	E_str = "E=65537";
	//P_str = "P=17";
	//Q_str = "Q=11";
	//E_str = "E=7";
	//getline(cin,P_str);
	//getline(cin,Q_str);
	//getline(cin,E_str);
	P_str = P_str.substr(2);
	Q_str = Q_str.substr(2);
	E_str = E_str.substr(2);
	LongNumber P(P_str);
	LongNumber Q(Q_str);
	LongNumber N = P * Q;
	LongNumber PhiN = ((P - 1) * (Q - 1));
	LongNumber E(E_str);
	LongNumber D = E.ModularInverse(PhiN);
	string operation;
	while (getline(cin, operation))
	{
		if (operation == "Quit") break;
		if (operation == "IsPPrime")
		{
			string response = (P.IsPrime(3)) ? "Yes" : "No";
			cout << response << endl;
		}
		else if (operation == "IsQPrime")
		{
			string response = (Q.IsPrime(3)) ? "Yes" : "No";
			cout << response << endl;
		}
		else if (operation == "PrintN")
		{
			cout << N.GetStringNumber() << endl;
		}
		else if (operation == "PrintPhi")
		{
			cout << PhiN.GetStringNumber() << endl;
		}
		else if (operation == "PrintD")
		{
			cout << D.GetStringNumber() << endl;
		}
		else if (operation.substr(0, 13) == "EncryptPublic")
		{
			string message = operation.substr(15);
			message = message.substr(0, message.size() - 1);
			cout << Encrypt(message, E, N) << endl;
		}
		else if (operation.substr(0, 14) == "EncryptPrivate")
		{
			string message = operation.substr(16);
			message = message.substr(0, message.size() - 1);
			cout << Encrypt(message, D, N) << endl;
		}
	}
	return 0;
}

string Encrypt(const string& message, const LongNumber& number, const LongNumber& mod)
{
	LongNumber msg(message);
	msg = msg.ModularExponentiation(number, mod); //encryption or decryption
	return msg.GetStringNumber();
}

LongNumber::LongNumber()
{
	sign = true; //default is positive
	size = 1;
	number[LSD] = 0;
}

LongNumber::LongNumber(long long n)
{
	sign = n >= 0;
	if (n <= MAX_VALUE)
	{
		size = 1;
		number[LSD] = abs(n);
	}
	else if (n <= 999999999999999999)
	{
		size = 2;
		number[LSD - 1] = abs(n) / BASE;
		number[LSD] = abs(n) - number[LSD - 1] * BASE;
	}
	else
	{
		size = 3;
		number[LSD - 2] = (abs(n) / BASE) / BASE;
		number[LSD - 1] = (abs(n) - number[LSD - 2] * BASE * BASE) / BASE;
		number[LSD] = abs(n) - number[LSD - 1] * BASE;
	}
}

LongNumber::LongNumber(string n_str)
{
	sign = n_str[0] != '-';
	if (!sign)
		n_str = n_str.substr(1);
	n_str.erase(0, n_str.find_first_not_of('0'));
	if (n_str.length() == 0)
	{
		size = 1;
		number[LSD] = 0;
	}
	else
	{
		size = (int)ceil(n_str.length() / (float)DIGITS_PER_ELEMENT);
		if (n_str.length() % DIGITS_PER_ELEMENT != 0)
		{
			number[MAX_SIZE - size] = stoull(n_str.substr(0, n_str.length() % DIGITS_PER_ELEMENT));
		}
		int start = (int)n_str.length() - DIGITS_PER_ELEMENT;
		for (int i = LSD; i >= MAX_SIZE - size; i--)
		{
			if (start < 0)
				break;
			number[i] = stoull(n_str.substr(start, DIGITS_PER_ELEMENT));
			start -= DIGITS_PER_ELEMENT;
		}
	}
}

void LongNumber::Insert(unsigned long long n)
{
	size++;
	number[MAX_SIZE - size] = n;
}

void LongNumber::Append(unsigned long long n, int count)
{
	if (count <= 0)
		return;
	size += count;
	if (size > MAX_SIZE)
		size = MAX_SIZE;
	int i = MAX_SIZE - size;
	for (; i < MAX_SIZE - count; i++)
	{
		number[i] = number[i + count];
	}
	for (; i < MAX_SIZE; i++)
	{
		number[i] = n;
	}
}

LongNumber LongNumber::operator*(const LongNumber & b)
{
	if ((size == 1 && number[LSD] == 0) || (b.size == 1 && b.number[LSD] == 0))
	{
		return LongNumber();
	}
	LongNumber mul;
	if ((size == 1 && number[LSD] == 1))
	{
		mul = b;
	}
	else if ((b.size == 1 && b.number[LSD] == 1))
	{
		mul = *this;
	}
	else if (size == 1 && b.size == 1)
	{
		mul = number[LSD] * b.number[LSD];
	}
	else
	{
		if (size < b.size)
		{
			for (int i = LSD; i >= MAX_SIZE - size; i--)
			{
				LongNumber tmp = b;
				unsigned long long d1 = number[i];
				unsigned long long c = 0; //carry
				for (int j = LSD; j >= MAX_SIZE - tmp.size; j--)
				{
					unsigned long long d2 = tmp.number[j] * d1 + c;
					if (d2 > MAX_VALUE)
					{
						c = d2 / BASE;
						d2 -= c * BASE;
					}
					else
						c = 0;
					tmp.number[j] = d2;
				}
				if (c > 0)
					tmp.Insert(c);
				tmp = tmp.MulExponententBase(LSD - i);//result of multiplication with tens, hundreds,...
				mul = mul + tmp;
			}
		}
		else
		{
			for (int i = LSD; i >= MAX_SIZE - b.size; i--)
			{
				LongNumber tmp = *this;
				unsigned long long d1 = b.number[i];
				unsigned long long c = 0; //carry
				for (int j = LSD; j >= MAX_SIZE - tmp.size; j--)
				{
					unsigned long long d2 = tmp.number[j] * d1 + c;
					if (d2 > MAX_VALUE)
					{
						c = d2 / BASE;
						d2 -= c * BASE;
					}
					else
						c = 0;
					tmp.number[j] = d2;
				}
				if (c > 0)
					tmp.Insert(c);
				tmp = tmp.MulExponententBase(LSD - i);//result of multiplication with tens, hundreds,...
				mul = mul + tmp;
			}
		}
	}
	mul.sign = !(sign ^ b.sign);
	return mul;
}

LongNumber LongNumber::operator/(const LongNumber & b)
{
	if ((size == 1 && number[LSD] == 0) || (*this < b))
		return LongNumber();
	if ((b.size == 1 && b.number[LSD] == 1))
	{
		LongNumber tmp = *this;
		tmp.sign = !(sign ^ b.sign);
		return tmp;
	}
	if (size == 1 && b.size == 1)
	{
		LongNumber tmp(number[LSD] / b.number[LSD]);
		tmp.sign = !(sign ^ b.sign);
		return tmp;
	}
	if (b.size == 1)
	{
		unsigned long long divisor = b.number[LSD];
		unsigned long long rem = 0;
		LongNumber div;
		div.size = size;
		for (int i = MAX_SIZE - size; i < MAX_SIZE; i++)
		{
			rem = (rem * BASE) + number[i];
			div.number[i] = rem / divisor;
			rem %= divisor;
		}
		div.sign = !(sign ^ b.sign);
		for (int i = MAX_SIZE - size; i < MAX_SIZE; i++)
		{
			if (div.number[i] == 0)
				div.size--;
			else
				break;
		}
		return div.size != 0 ? div : 0;
	}
	LongNumber A = *this;
	LongNumber B = b;
	if (A.Absolute() == B.Absolute())
	{
		LongNumber tmp(1);
		tmp.sign = !(sign ^ b.sign);
		return tmp;
	}
	LongNumber quotient;
	bool quotientSign = !(sign ^ b.sign);
	LongNumber nx1 = B;
	LongNumber nx2 = LongNumber(nx1) * 2;
	LongNumber nx4 = LongNumber(nx2) * 2;
	LongNumber nx8 = LongNumber(nx4) * 2;
	while (A.Absolute() >= nx1.Absolute())
	{
		if (A.Absolute() >= nx8.Absolute())
		{
			LongNumber q(8);
			LongNumber tmp = nx8;
			q = q.MulExponentent10(A.GetNumberOfDigits() - tmp.GetNumberOfDigits());
			tmp = tmp.MulExponentent10(A.GetNumberOfDigits() - tmp.GetNumberOfDigits());
			if (A.Absolute() < tmp.Absolute())
			{
				q = q.DivExponentent10(1);
				tmp = tmp.DivExponentent10(1);
			}
			if (quotientSign)
				A = A - tmp;
			else
				A = A + tmp;
			quotient = quotient + q;
		}
		if (A.Absolute() >= nx4.Absolute())
		{
			LongNumber q(4);
			LongNumber tmp = nx4;
			q = q.MulExponentent10(A.GetNumberOfDigits() - tmp.GetNumberOfDigits());
			tmp = tmp.MulExponentent10(A.GetNumberOfDigits() - tmp.GetNumberOfDigits());
			if (A.Absolute() < tmp.Absolute())
			{
				q = q.DivExponentent10(1);
				tmp = tmp.DivExponentent10(1);
			}
			if (quotientSign)
				A = A - tmp;
			else
				A = A + tmp;
			quotient = quotient + q;
		}
		if (A.Absolute() >= nx2.Absolute())
		{
			LongNumber q(2);
			LongNumber tmp = nx2;
			q = q.MulExponentent10(A.GetNumberOfDigits() - tmp.GetNumberOfDigits());
			tmp = tmp.MulExponentent10(A.GetNumberOfDigits() - tmp.GetNumberOfDigits());
			if (A.Absolute() < tmp.Absolute())
			{
				q = q.DivExponentent10(1);
				tmp = tmp.DivExponentent10(1);
			}
			if (quotientSign)
				A = A - tmp;
			else
				A = A + tmp;
			quotient = quotient + q;
		}
		if (A.Absolute() >= nx1.Absolute())
		{
			LongNumber q(1);
			LongNumber tmp = nx1;
			q = q.MulExponentent10(A.GetNumberOfDigits() - tmp.GetNumberOfDigits());
			tmp = tmp.MulExponentent10(A.GetNumberOfDigits() - tmp.GetNumberOfDigits());
			if (A.Absolute() < tmp.Absolute())
			{
				q = q.DivExponentent10(1);
				tmp = tmp.DivExponentent10(1);
			}
			if (quotientSign)
				A = A - tmp;
			else
				A = A + tmp;
			quotient = quotient + q;
		}
	}
	quotient.sign = quotientSign;
	return quotient;
}

LongNumber LongNumber::operator%(const LongNumber & b)
{
	if ((size == 1 && number[LSD] == 0) || *this == b)
		return LongNumber();
	if ((b.size == 1 && b.number[LSD] == 1))
		return LongNumber();
	if ((b.size == 1 && b.number[LSD] == 2))
	{
		return IsEven() ? LongNumber() : LongNumber(1);
	}
	if (*this < b)
		return *this;
	if (size == 1 && b.size == 1)
	{
		return LongNumber(number[LSD] % b.number[LSD]);
	}
	if (b.size == 1)
	{
		unsigned long long divisor = b.number[LSD];
		unsigned long long rem = 0;
		for (int i = MAX_SIZE - size; i < MAX_SIZE; i++)
		{
			rem = (rem * BASE) + number[i];
			rem %= divisor;
		}
		return rem;
	}
	LongNumber A = *this;
	bool quotientSign = !(sign ^ b.sign);
	A.sign = true;
	LongNumber nx1 = b;
	nx1.sign = true;
	LongNumber nx2 = nx1 * 2;
	LongNumber nx4 = nx2 * 2;
	LongNumber nx8 = nx4 * 2;
	while (A >= nx1)
	{
		if (A >= nx8)
		{
			LongNumber tmp = nx8;
			tmp = tmp.MulExponentent10(A.GetNumberOfDigits() - tmp.GetNumberOfDigits());
			if (A < tmp)
			{
				tmp = tmp.DivExponentent10(1);
			}
			A = A - tmp;
		}
		if (A >= nx4)
		{
			LongNumber tmp = nx4;
			tmp = tmp.MulExponentent10(A.GetNumberOfDigits() - tmp.GetNumberOfDigits());
			if (A < tmp)
			{
				tmp = tmp.DivExponentent10(1);
			}
			A = A - tmp;
		}
		if (A >= nx2)
		{
			LongNumber tmp = nx2;
			tmp = tmp.MulExponentent10(A.GetNumberOfDigits() - tmp.GetNumberOfDigits());
			if (A < tmp)
			{
				tmp = tmp.DivExponentent10(1);
			}
			A = A - tmp;
		}
		if (A >= nx1)
		{
			LongNumber tmp = nx1;
			tmp = tmp.MulExponentent10(A.GetNumberOfDigits() - tmp.GetNumberOfDigits());
			if (A < tmp)
			{
				tmp = tmp.DivExponentent10(1);
			}
			A = A - tmp;
		}
	}
	return A;
}

bool LongNumber::operator==(const LongNumber& b)
{
	if (size != b.size)
		return false;
	for (int i = MAX_SIZE - size; i < MAX_SIZE; i++)
	{
		if (number[i] != b.number[i])
			return false;
	}
	return true;
}

bool LongNumber::operator!=(const LongNumber & b)
{
	return !(*this == b);
}

bool LongNumber::operator<(const LongNumber & b)
{
	if (size < b.size)
		return true;
	if (size > b.size)
		return false;
	if (*this == b)
		return false;
	if (!sign && !b.sign)
	{
		for (int i = MAX_SIZE - size; i < MAX_SIZE; i++)
		{
			if (number[i] < b.number[i])
				return false;
			if (number[i] > b.number[i])
				break;
		}
	}
	if (sign && !b.sign)
		return false;
	if (!sign && b.sign)
		return true;
	if (sign && b.sign)
	{
		for (int i = MAX_SIZE - size; i < MAX_SIZE; i++)
		{
			if (number[i] > b.number[i])
				return false;
			if (number[i] < b.number[i])
				break;
		}
	}
	return true;
}

bool LongNumber::operator>(const LongNumber & b)
{
	LongNumber tmp = b;
	return tmp < *this;
}

bool LongNumber::operator<=(const LongNumber & b)
{
	return !(*this > b);
}

bool LongNumber::operator>=(const LongNumber & b)
{
	return !(*this < b);
}

LongNumber LongNumber::operator+(const LongNumber & b)
{
	if ((size == 1 && number[LSD] == 0))
		return b;
	if ((b.size == 1 && b.number[LSD] == 0))
		return *this;
	if (sign && !b.sign)
	{
		LongNumber tmp = b;
		tmp.sign = true;
		return *this - tmp;
	}
	if (!sign && b.sign)
	{
		LongNumber tmp = b;
		LongNumber tmp2 = *this;
		tmp2.sign = true;
		return tmp - tmp2;
	}
	bool addSign;
	if (sign && b.sign)
		addSign = true;
	else
		addSign = false;
	LongNumber add;
	add.sign = addSign;
	unsigned long long sum = 0;
	unsigned long long carry = 0;
	if (size > b.size)
	{
		add.size = size;
		int op1Index = MAX_SIZE;
		int op2Index = MAX_SIZE;
		while (op2Index > MAX_SIZE - b.size)
		{
			sum = number[--op1Index] + b.number[--op2Index] + carry;
			if (sum > MAX_VALUE)
			{
				sum -= BASE;
				carry = 1;
			}
			else
				carry = 0;
			add.number[op1Index] = sum;
		}
		while (op1Index > MAX_SIZE - size)
		{
			sum = number[--op1Index] + carry;
			if (sum > MAX_VALUE)
			{
				sum -= BASE;
				carry = 1;
			}
			else
				carry = 0;
			add.number[op1Index] = sum;
		}
	}
	else
	{
		add.size = b.size;
		int op1Index = MAX_SIZE;
		int op2Index = MAX_SIZE;
		while (op2Index > MAX_SIZE - size)
		{
			sum = b.number[--op1Index] + number[--op2Index] + carry;
			if (sum > MAX_VALUE)
			{
				sum -= BASE;
				carry = 1;
			}
			else
				carry = 0;
			add.number[op1Index] = sum;
		}
		while (op1Index > MAX_SIZE - b.size)
		{
			sum = b.number[--op1Index] + carry;
			if (sum > MAX_VALUE)
			{
				sum -= BASE;
				carry = 1;
			}
			else
				carry = 0;
			add.number[op1Index] = sum;
		}
	}
	if (carry == 1)
	{
		add.Insert(1);
	}
	return add;
}

LongNumber LongNumber::operator-(const LongNumber & b)
{
	if ((b.size == 1 && b.number[LSD] == 0))
	{
		return *this;
	}
	if ((size == 1 && number[LSD] == 0))
	{
		LongNumber tmp = b;
		tmp.sign = !sign;
		return tmp;
	}
	if (!b.sign)
	{
		LongNumber tmp = b;
		tmp.sign = true;
		return *this + tmp;
	}
	if (!sign)
	{
		LongNumber tmp = b;
		tmp.sign = false;
		return *this + tmp;
	}
	bool subSign;
	if (*this > b)
		subSign = true;
	else
		subSign = false;
	LongNumber op1 = *this;
	LongNumber sub;
	sub.size = size;
	sub.sign = true;
	int op1Index = MAX_SIZE;
	int op2Index = MAX_SIZE;
	while (op2Index > MAX_SIZE - b.size)
	{
		if (op1.number[--op1Index] < b.number[--op2Index])
		{
			sub.number[op1Index] = BASE + op1.number[op1Index] - b.number[op2Index];
			if (op1Index != MAX_SIZE - op1.size)
			{
				if (op1.number[op1Index - 1] != 0)
					op1.number[op1Index - 1]--;
				else
				{
					op1.number[op1Index - 1] = MAX_VALUE;
					int i = 2;
					while (op1.number[op1Index - i] == 0)
					{
						op1.number[op1Index - i] = MAX_VALUE;
						i++;
					}
					op1.number[op1Index - i]--;
				}
			}

		}
		else
			sub.number[op1Index] = op1.number[op1Index] - b.number[op2Index];
	}
	while (op1Index > MAX_SIZE - size)
	{
		--op1Index;
		sub.number[op1Index] = op1.number[op1Index];
	}
	for (int i = MAX_SIZE - size; i < MAX_SIZE; i++)
	{
		if (sub.number[i] == 0)
			sub.size--;
		else
			break;
	}
	return sub.size != 0 ? sub : 0;
}

LongNumber LongNumber::ModularExponentiation(const LongNumber & power, const LongNumber & mod)
{
	if ((mod.size == 1 && mod.number[LSD] == 1))
		return LongNumber();
	LongNumber base = *this;
	base = base % mod;
	LongNumber p = power;
	if ((p.size == 1 && p.number[LSD] == 1)) {
		return base;
	}
	if ((p.size == 1 && p.number[LSD] == 0)) {
		return LongNumber(1);
	}
	LongNumber N(mod);
	LongNumber R(LongNumber(1).MulExponententBase(N.size));
	LongNumber N_inv(N.ModularInverse(R));
	if (N_inv != 0)
		N_inv = R - N_inv;
	LongNumber result(R % N);
	LongNumber base_mont((base * R) % N);
	while (p > 0)
	{
		if (p.IsOdd())
		{
			LongNumber T = result * base_mont;
			result = REDC(N, N_inv, T);
		}
		p = p / 2;
		LongNumber T = base_mont * base_mont;
		base_mont = REDC(N, N_inv, T);
	}
	return (result * R.ModularInverse(N)) % N;
}

LongNumber LongNumber::ModularInverse(const LongNumber & mod)
{
	LongNumber A1 = 1, A2 = 0, A3 = mod;
	LongNumber B1 = 0, B2 = 1, B3 = *this;
	LongNumber Q, T1, T2, T3;
	while (1)
	{
		if (B3 == 0)
		{
			break;
		}
		if (B3 == 1)
		{
			if (!B2.sign)
				B2 = B2 + mod;
			return B2;
		}
		Q = A3 / B3;
		T1 = A1 - (Q * B1);
		T2 = A2 - (Q * B2);
		T3 = A3 - (Q * B3);
		A1 = B1;
		A2 = B2;
		A3 = B3;
		B1 = T1;
		B2 = T2;
		B3 = T3;
	}
	return LongNumber();
}

LongNumber LongNumber::MulExponententBase(int power)
{
	LongNumber tmp = *this;
	if (power > MAX_SIZE)
		power = MAX_SIZE;
	if (power < 0)
		power = 0;
	tmp.Append(0, power);
	return tmp;
}

LongNumber LongNumber::DivExponententBase(int power)
{
	if (power > MAX_SIZE)
		power = MAX_SIZE;
	if (power < 0)
		power = 0;
	if (size <= power)
		return LongNumber();
	LongNumber tmp = *this;
	for (int i = LSD; i >= MAX_SIZE - size; i--)
	{
		if (i - power < 0)
			break;
		tmp.number[i] = number[i - power];
	}
	tmp.size -= power;
	for (int i = MAX_SIZE - tmp.size; i < MAX_SIZE; i++)
	{
		if (tmp.number[i] == 0)
			tmp.size--;
		else
			break;
	}
	return tmp.size != 0 ? tmp : 0;
}

LongNumber LongNumber::ModExponententBase(int power)
{
	if (power > MAX_SIZE || power < 0)
		power = MAX_SIZE;
	if (size <= power)
		return *this;
	LongNumber tmp = *this;
	tmp.size = power;
	return tmp;
}

LongNumber LongNumber::MulExponentent10(int power)
{
	int p1 = power / 9;
	int p2 = power % 9;
	LongNumber tmp = (*this).MulExponententBase(p1);
	return tmp * (unsigned long long) pow(10, p2);
}

LongNumber LongNumber::DivExponentent10(int power)
{
	int p1 = power / 9;
	int p2 = power % 9;
	LongNumber tmp = (*this).MulExponententBase(p1);
	return tmp / (unsigned long long) pow(10, p2);
}

LongNumber LongNumber::Absolute()
{
	LongNumber tmp = *this;
	tmp.sign = true;
	return tmp;
}

LongNumber LongNumber::REDC(LongNumber & N, LongNumber & N_inv, LongNumber & T)
{
	int R = N.size;
	LongNumber m((T.ModExponententBase(R) * N_inv).ModExponententBase(R));
	LongNumber t((T + m * N).DivExponententBase(R));
	if (t >= N)
		return t - N;
	else
		return t;
}

bool LongNumber::IsPrime(int iterations)
{
	if ((size == 1 && number[LSD] == 2) || (size == 1 && number[LSD] == 3))
		return true;
	if ((size == 1 && number[LSD] == 0) || (size == 1 && number[LSD] == 1) || IsEven())
		return false;
	LongNumber n = *this;
	LongNumber q = n - 1;
	int k = 0;
	while (q.IsEven())
	{
		q = q / 2;
		k++;
	}
	for (int i = 0; i < iterations; i++)
	{
		if (!MillerRabinTest(n, q, k))
			return false;
	}
	return true;
}

bool LongNumber::IsEven()
{
	return number[LSD] % 2 == 0;
}

bool LongNumber::IsOdd()
{
	return !IsEven();
}

string LongNumber::GetStringNumber()
{
	string num_str = "";
	if (!sign)
		num_str += "-";
	string tmp;
	for (int i = MAX_SIZE - size; i < MAX_SIZE; i++)
	{
		tmp = to_string(number[i]);
		if (i != MAX_SIZE - size && tmp.length() < DIGITS_PER_ELEMENT)
			tmp.insert(0, DIGITS_PER_ELEMENT - tmp.length(), '0');
		num_str += tmp;
	}
	return num_str;
}

int LongNumber::GetNumberOfDigits()
{
	return 	(size - 1) * 9 + (int)to_string(number[MAX_SIZE - size]).length();
}

bool LongNumber::MillerRabinTest(LongNumber& n, LongNumber& q, int k)
{
	int max = atoi(GetStringNumber().c_str()) - 2;
	LongNumber a(1 + rand() % max);
	LongNumber x = a.ModularExponentiation(q, n);
	if (x == 1 || x == (n - 1))
		return true;
	for (int i = 1; i < k; i++)
	{
		LongNumber p2i = (int)pow(2, i);
		p2i = p2i * q;
		LongNumber x = a.ModularExponentiation(p2i, n);
		if (x == (n - 1))
			return true;
	}
	return false;
}
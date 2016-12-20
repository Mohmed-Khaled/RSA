#include <iostream>
#include <string>
#include <random>
#include <cmath>
#include <ctime>

using namespace std;

class LongNumber
{
public:
	LongNumber();
	LongNumber(string n_str);
	LongNumber(long long n);
	LongNumber operator*(const LongNumber& b);
	LongNumber operator/(const LongNumber& b);
	LongNumber operator%(const LongNumber& b);
	bool operator==(const LongNumber& b);
	bool operator!=(const LongNumber& b);
	bool operator<(const LongNumber& b);
	bool operator>(const LongNumber& b);
	bool operator<=(const LongNumber& b);
	bool operator>=(const LongNumber& b);
	LongNumber operator+(const LongNumber& b);
	LongNumber operator-(const LongNumber& b);
	LongNumber ModularExponentiation(const LongNumber& power, const LongNumber& mod);
	LongNumber ModularInverse(const LongNumber& mod);
	LongNumber Exponentiation(const LongNumber& power);
	LongNumber MulExponentent10(int power);
	LongNumber DivExponentent10(int power);
	LongNumber ModExponentent10(int power);
	LongNumber Absolute();
	bool IsPrime(int iterations);
	bool IsEven();
	bool IsOdd();
	string getStringNumber();
private:
	bool sign; //true means positive and false means negative
	string number;
	bool MillerRabinTest(LongNumber& n,LongNumber& q, int k);
	void RemoveLeadingZeros();
	LongNumber DivideBy2();
	LongNumber static karatsuba(LongNumber& a,LongNumber& b);
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
	cout << "Addition Time = " << double(end - begin) / CLOCKS_PER_SEC << endl << endl;
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
	cout << "Subtraction Time = " << double(end - begin) / CLOCKS_PER_SEC << endl << endl;
}

void test_multiplication_time(int n)
{
	LongNumber x("12369571528747655798110188786567180759626910465726920556567298659370399748072366507234899432827475865189642714067836207300153035059472237275816384410077871");
	LongNumber y("2065420353441994803054315079370635087865508423962173447811880044936318158815802774220405304957787464676771309034463560633713497474362222775683960029689473");
	clock_t begin = clock();
	for (int i = 0; i < n; i++)
	{
		LongNumber z = x * y;
	}
	clock_t end = clock();
	cout << "Multiplication Time = " << double(end - begin) / CLOCKS_PER_SEC << endl << endl;
}

void test_division_time(int n)
{
	LongNumber x("12369571528747655798110188786567180759626910465726920556567298659370399748072366507234899432827475865189642714067836207300153035059472237275816384410077871");
	LongNumber y("2065420353441994803054315079370635087865508423962173447811880044936318158815802774220405304957787464676771309034463560633713497474362222775683960029689473");
	clock_t begin = clock();
	for (int i = 0; i < n; i++)
	{
		LongNumber z = x / y;
	}
	clock_t end = clock();
	cout << "Divisiom Time = " << double(end - begin) / CLOCKS_PER_SEC << endl << endl;
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
	cout << "Result = " << r.getStringNumber() << endl << endl;
}

string Encrypt(const string& message, const LongNumber& number, const LongNumber& mod);

int main()
{
	// TEST START
	int test_itr = 100;
	test_addition_time(test_itr);
	test_subtraction_time(test_itr);
	test_multiplication_time(test_itr);
	test_division_time(test_itr);
	string m_str = "88";
	string c_str = "4397678428390379126255360246165021910057442267382175543246817108158797115317154540746718616555865161372450860559307149988169566508274711121236049281217144195628407516579953387138808449458611836421032431582081899650685651973204503916459595600207918950383877057152533041873901965623112895996177941667469292738";
	string e_str = "65537";
	string d_str = "25051719899710729069339146813050963409059898810366373119834423967819636191509401691818253978210229371822961344590338934536803264841097247978074700319812702399440521918349189245279566231685265955731649745935378380489722580113725907099133943430294137060596724659637599737926649148356615085679203385772673944833";
	string n_str = "25548364798832019218170326077010425733930233389897468141147917831084690989884562791601588954296621731652139141347541240725432606132471100644835778517336041031200174441223836394229943651678525471050219216183727749114047330431603023948126844573697946795476319956787513765533596926704755530772983549787878951983";
	test_modular_exponentiation_time(m_str, e_str, n_str);
	test_modular_exponentiation_time(c_str, d_str, n_str);
	string p_str = "12369571528747655798110188786567180759626910465726920556567298659370399748072366507234899432827475865189642714067836207300153035059472237275816384410077871";
	string q_str = "2065420353441994803054315079370635087865508423962173447811880044936318158815802774220405304957787464676771309034463560633713497474362222775683960029689473";
	test_prime_check_time(p_str, 1);
	test_prime_check_time(q_str, 1);
	// TEST END*/
	string P_str, Q_str, E_str;
	P_str = "P=12369571528747655798110188786567180759626910465726920556567298659370399748072366507234899432827475865189642714067836207300153035059472237275816384410077871";
	Q_str = "Q=2065420353441994803054315079370635087865508423962173447811880044936318158815802774220405304957787464676771309034463560633713497474362222775683960029689473";
	E_str = "E=65537";
	//P_str = "P=17";
	//Q_str = "Q=11";
	//E_str = "E=7";
	/*getline(cin,P_str);
	getline(cin,Q_str);
	getline(cin,E_str);*/
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
	while(getline(cin,operation))
	{
		if (operation == "Quit") break;
		if (operation == "IsPPrime")
		{
			string response = (P.IsPrime(1)) ? "Yes" : "No";
			cout << response << endl;
		}
		else if (operation == "IsQPrime")
		{
			string response = (Q.IsPrime(1)) ? "Yes" : "No";
			cout << response << endl;
		}
		else if (operation == "PrintN")
		{
			cout << N.getStringNumber() << endl;
		}
		else if (operation == "PrintPhi")
		{
			cout << PhiN.getStringNumber() << endl;
		}
		else if (operation == "PrintD")
		{
			cout << D.getStringNumber() << endl;
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
	msg = msg.ModularExponentiation(number, mod); //encryption
	return msg.getStringNumber();
}

LongNumber::LongNumber()
{
	sign = true; //default is positive
	number = "0";
}

LongNumber::LongNumber(string n_str)
{
	if(n_str[n_str.size() - 1] == '-')
	{
		sign = false;
		number = n_str.substr(1);
	}
	else
	{
		sign = true;
		number = n_str;
	}
	RemoveLeadingZeros();
}

LongNumber::LongNumber(long long n)
{
	if (n < 0)
	{
		sign = false;
		number = to_string(n).substr(1);
	}
	else
	{
		sign = true;
		number = to_string(n);
	}
	RemoveLeadingZeros();
}

LongNumber LongNumber::operator*(const LongNumber & b)
{
	//TODO: Try to enhance Muyliplication.
	if (number == "0" || b.number == "0")
	{
		return LongNumber(0);
	}
	if (number == "1")
	{
		return b;
	}
	if (b.number == "1")
	{
		return *this;
	}
	LongNumber mul;
	if (number.size() < 10 && b.number.size() < 10)
	{
		mul = stoll(number) * stoll(b.number);
	}
	else if(number.size() < 80 || b.number.size() < 80)
	{
		string n1 = number;
		string n2 = b.number;
		if (n1.length() > n2.length())
			n1.swap(n2); //to decrease calls to add operation
		for (int i = n1.size() - 1; i >= 0; i--)
		{
			string tmp = n2;
			unsigned int d1 = n1[i] - '0';
			unsigned int c = 0; //carry
			for (int j = tmp.size() - 1; j >= 0; j--)
			{
				unsigned int d2 = tmp[j] - '0';
				d2 = d1 * d2 + c;
				if (d2 > 9)
				{
					c = d2 / 10;
					d2 -= c * 10;
				}
				else
					c = 0;
				tmp[j] = d2 + '0';
			}
			if (c > 0)
				tmp.insert(0, 1, c + '0');
			tmp.append(n1.size() - 1 - i, '0');//result of multiplication with tens, hundreds,...
			mul = mul + tmp;
		}
	}
	else
	{
		LongNumber op1 = *this;
		LongNumber op2 = b;
		mul = karatsuba(op1, op2);
	}
	RemoveLeadingZeros();
	mul.sign = !(sign ^ b.sign);
	return mul;
}

LongNumber LongNumber::operator/(const LongNumber & b)
{
	//TODO: Try to enhance Division.
	if (number == "0" || (*this < b))
		return LongNumber();
	if (b.number == "1")
	{
		LongNumber tmp = *this;
		tmp.sign = !(sign ^ b.sign);
		return tmp;
	}
	if (b.number == "2")
	{
		LongNumber tmp = (*this).DivideBy2();
		tmp.sign = !(sign ^ b.sign);
		return tmp;
	}
	if (*this == b)
		return LongNumber(1);
	LongNumber quotient;
	bool quotientSign = !(sign ^ b.sign);
	LongNumber dividend = *this;
	LongNumber nx1 = b;
	LongNumber nx2 = (LongNumber(nx1) * 2).getStringNumber();
	LongNumber nx4 = (LongNumber(nx2) * 2).getStringNumber();
	LongNumber nx8 = (LongNumber(nx4) * 2).getStringNumber();
	while(dividend.Absolute() >= nx1.Absolute())
	{
		if (dividend.Absolute() >= nx8.Absolute())
		{
			string q = "8";
			LongNumber tmp = nx8;
			q.append(dividend.number.size() - tmp.number.size(), '0');
			tmp.number.append(dividend.number.size() - tmp.number.size(), '0');
			if (dividend.Absolute() < tmp.Absolute())
			{
				q = q.substr(0, q.size() - 1);
				tmp.number = tmp.number.substr(0, tmp.number.size() - 1);
			}
			if(quotientSign)
				dividend = dividend - tmp;
			else
				dividend = dividend + tmp;
			quotient = quotient + q;
		}
		else if (dividend.Absolute() >= nx4.Absolute())
		{
			string q = "4";
			LongNumber tmp = nx4;
			q.append(dividend.number.size() - tmp.number.size(), '0');
			tmp.number.append(dividend.number.size() - tmp.number.size(), '0');
			if (dividend.Absolute() < tmp.Absolute())
			{
				q = q.substr(0, q.size() - 1);
				tmp.number = tmp.number.substr(0, tmp.number.size() - 1);
			}
			if (quotientSign)
				dividend = dividend - tmp;
			else
				dividend = dividend + tmp;
			quotient = quotient + q;
		}
		else if (dividend.Absolute() >= nx2.Absolute())
		{
			string q = "2";
			LongNumber tmp = nx2;
			q.append(dividend.number.size() - tmp.number.size(), '0');
			tmp.number.append(dividend.number.size() - tmp.number.size(), '0');
			if (dividend.Absolute() < tmp.Absolute())
			{
				q = q.substr(0, q.size() - 1);
				tmp.number = tmp.number.substr(0, tmp.number.size() - 1);
			}
			if (quotientSign)
				dividend = dividend - tmp;
			else
				dividend = dividend + tmp;
			quotient = quotient + q;
		}
		else if (dividend.Absolute() >= nx1.Absolute())
		{
			string q = "1";
			LongNumber tmp = nx1;
			q.append(dividend.number.size() - tmp.number.size(), '0');
			tmp.number.append(dividend.number.size() - tmp.number.size(), '0');
			if (dividend.Absolute() < tmp.Absolute())
			{
				q = q.substr(0, q.size() - 1);
				tmp.number = tmp.number.substr(0, tmp.number.size() - 1);
			}
			if (quotientSign)
				dividend = dividend - tmp;
			else
				dividend = dividend + tmp;
			quotient = quotient + q;
		}
	}
	RemoveLeadingZeros();
	quotient.sign = quotientSign;
	return quotient;
}

LongNumber LongNumber::operator%(const LongNumber & b)
{
	// not tested with negative numbers as it is not needed in RSA
	if (number == "0" || *this == b)
		return LongNumber();
	if (b.number == "1")
		return LongNumber();
	if (b.number == "2")
	{
		return IsEven() ? LongNumber() : LongNumber(1);
	}
	if (*this < b)
		return *this;
	LongNumber dividend = *this;
	bool quotientSign = !(sign ^ b.sign);
	LongNumber nx1 = b;
	LongNumber nx2 = (LongNumber(nx1) * 2).getStringNumber();
	LongNumber nx4 = (LongNumber(nx2) * 2).getStringNumber();
	LongNumber nx8 = (LongNumber(nx4) * 2).getStringNumber();
	while (dividend.Absolute() >= nx1.Absolute())
	{
		if (dividend.Absolute() >= nx8.Absolute())
		{
			LongNumber tmp = nx8;
			tmp.number.append(dividend.number.size() - tmp.number.size(), '0');
			if (dividend.Absolute() < tmp.Absolute())
			{
				tmp.number = tmp.number.substr(0, tmp.number.size() - 1);
			}
			if (quotientSign)
				dividend = dividend - tmp;
			else
				dividend = dividend + tmp;
		}
		else if (dividend.Absolute() >= nx4.Absolute())
		{
			LongNumber tmp = nx4;
			tmp.number.append(dividend.number.size() - tmp.number.size(), '0');
			if (dividend.Absolute() < tmp.Absolute())
			{
				tmp.number = tmp.number.substr(0, tmp.number.size() - 1);
			}
			if (quotientSign)
				dividend = dividend - tmp;
			else
				dividend = dividend + tmp;
		}
		else if (dividend.Absolute() >= nx2.Absolute())
		{
			LongNumber tmp = nx2;
			tmp.number.append(dividend.number.size() - tmp.number.size(), '0');
			if (dividend.Absolute() < tmp.Absolute())
			{
				tmp.number = tmp.number.substr(0, tmp.number.size() - 1);
			}
			if (quotientSign)
				dividend = dividend - tmp;
			else
				dividend = dividend + tmp;
		}
		else if (dividend.Absolute() >= nx1.Absolute())
		{
			LongNumber tmp = nx1;
			tmp.number.append(dividend.number.size() - tmp.number.size(), '0');
			if (dividend.Absolute() < tmp.Absolute())
			{
				tmp.number = tmp.number.substr(0, tmp.number.size() - 1);
			}
			if (quotientSign)
				dividend = dividend - tmp;
			else
				dividend = dividend + tmp;
		}
	}
	RemoveLeadingZeros();
	return dividend;
}

bool LongNumber::operator==(const LongNumber& b)
{
	return number == b.number && sign == b.sign;
}

bool LongNumber::operator!=(const LongNumber & b)
{
	return !(*this == b);
}

bool LongNumber::operator<(const LongNumber & b)
{
	if (!sign && !b.sign) 
	{
		if (number.length() > b.number.length())
			return true;
		if (number.length() < b.number.length())
			return false;
		return number > b.number;
	}
	if (sign && !b.sign)
		return false;
	if (!sign && b.sign)
		return true;
	if (sign && b.sign) 
	{
		if (number.length() < b.number.length())
			return true;
		if (number.length() > b.number.length())
			return false;
		return number < b.number;
	}
	return false;
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
	if (number == "0")
		return b;
	if (b.number == "0")
		return *this;
	if(sign && !b.sign)
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
	string n1 = number;
	string n2 = b.number;
	string add = (n1.length() > n2.length()) ? n1 : n2;
	add.insert(0, 1, '0');
	int padding = abs((int)(n1.size() - n2.size()));
	if (n1.size() > n2.size())
	{
		n1.insert(0, 1, '0');
		n2.insert(0, padding + 1, '0');
	}
	else if (n1.size() < n2.size())
	{
		n1.insert(0, padding + 1, '0');
		n2.insert(0, 1, '0');
	}
	else
	{
		n1.insert(0, 1, '0');
		n2.insert(0, 1, '0');
	}
	for (int i = add.size() - 1; i >= 0; i--)
	{
		add[i] = ((n1[i] - '0') + (n2[i] - '0')) + '0';
		while (add[i] > '9')
		{
			add[i] -= 10;
			n1[i - 1]++;
		}
	}
	LongNumber addResult(add);
	addResult.sign = addSign;
	return addResult;
}

LongNumber LongNumber::operator-(const LongNumber & b)
{
	if(b.number == "0")
	{
		return *this;
	}
	if (number == "0")
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
	string n1 = number;
	string n2 = b.number;
	string sub = (n1.length() > n2.length()) ? n1 : n2;
	int padding = abs((int) (n1.size() - n2.size()));
	if (n1.size() > n2.size())
		n2.insert(0, padding, '0');
	else
		n1.insert(0, padding, '0');
	for(int i = sub.size() - 1;i >= 0;i--)
	{
		if (n1[i] < n2[i])
		{
			n1[i] += 10;
			if(i != 0)
				n1[i - 1]--;
		}
		sub[i] = ((n1[i] - '0') - (n2[i] - '0')) + '0';
	}
	LongNumber subResult(sub);
	subResult.sign = subSign;
	return subResult;
}

LongNumber LongNumber::ModularExponentiation(const LongNumber & power, const LongNumber & mod)
{
	//TODO: Try to enhance ModularExponentiation. 
	if (mod.number == "1")
		return LongNumber();
	LongNumber base = *this;
	base = base % mod;
	LongNumber p = power;
	if (p == 1) {
		return base;
	}
	if (p == 0) {
		return LongNumber(1);
	}
	if(p.number.size() > 300)
	{
		LongNumber result = 1;
		while (p > 0)
		{
			if (p.IsOdd())
				result = (result * base) % mod;
			p = p / 2;
			base = (base * base) % mod;
		}
		RemoveLeadingZeros();
		return result;
	}
	else
	{
		LongNumber m = base.ModularExponentiation(p / 2, mod);
		LongNumber res;
		if (p.IsEven())
		{
			res = LongNumber(1);
		}
		else 
		{
			res = base;
		}
		LongNumber x = m * m;
		return (x * res) % mod;
	}
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
			B2.RemoveLeadingZeros();
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

LongNumber LongNumber::Exponentiation(const LongNumber & power)
{
	LongNumber base = *this;
	LongNumber p = power;
	LongNumber result = 1;
	if (p == 1) {
		return base;
	}
	if (p == 0) {
		return LongNumber(1);
	}
	LongNumber m = base.Exponentiation(p / 2);
	LongNumber res;
	if (p.IsEven())
	{
		res = LongNumber(1);
	}
	else {
		res = base;
	}
	LongNumber x = m * m;
	x = x * res;
	RemoveLeadingZeros();
	return x;
}

LongNumber LongNumber::MulExponentent10(int power)
{
	LongNumber tmp = *this;
	tmp.number.append(power,'0');
	return tmp;
}

LongNumber LongNumber::DivExponentent10(int power)
{
	LongNumber tmp = *this;
	int pos = tmp.number.size() - power;
	if (pos <= 0)
		return LongNumber(0);
	tmp.number = tmp.number.substr(0, tmp.number.size() - power);
	return tmp;
}

LongNumber LongNumber::ModExponentent10(int power)
{
	LongNumber tmp = *this;
	int pos = tmp.number.size() - power;
	if (pos < 0)
		return tmp;
	tmp.number = tmp.number.substr(tmp.number.size() - power);
	return tmp;
}

LongNumber LongNumber::Absolute()
{
	return LongNumber(number);
}

LongNumber LongNumber::DivideBy2()
{
	LongNumber tmp = *this;
	tmp = tmp * 5;
	tmp = tmp.DivExponentent10(1);
	return tmp;
}

LongNumber LongNumber::karatsuba(LongNumber & a, LongNumber & b)
{
	if (a.number == "0" || b.number == "0")
	{
		return LongNumber(0);
	}
	if (a.number == "1")
	{
		return b;
	}
	if (b.number == "1")
	{
		return a;
	}
	int m = (a.number.size() > b.number.size()) ? a.number.size() : b.number.size();
	if (m < 10)
	{
		return stoll(a.number) * stoll(b.number);
	}
	m = (m / 2) + (m % 2);
	LongNumber x1 = a.DivExponentent10(m);
	LongNumber x0 = a.ModExponentent10(m);
	LongNumber y1 = b.DivExponentent10(m);
	LongNumber y0 = b.ModExponentent10(m);
	LongNumber u = karatsuba(x1, y1);
	LongNumber v = karatsuba(x0, y0);
	LongNumber w = (karatsuba((x1 + x0), (y1 + y0)) - u) - v;
	return u.MulExponentent10(2*m) + w.MulExponentent10(m) + v;
}

bool LongNumber::IsPrime(int iterations)
{
	//TODO: Try to enhance IsPrime.
	if (number == "2" || number == "3")
		return true;
	if (number == "0" || number == "1" || IsEven()) 
		return false;
	LongNumber n = *this;
	LongNumber q = n - 1;
	int k = 0;
	while(q.IsEven())
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
	return number.back() == '0'
		|| number.back() == '2'
		|| number.back() == '4'
		|| number.back() == '6'
		|| number.back() == '8';
}

bool LongNumber::IsOdd()
{
	return number.back() == '1'
		|| number.back() == '3'
		|| number.back() == '5'
		|| number.back() == '7'
		|| number.back() == '9';
}

string LongNumber::getStringNumber()
{
	if (number == "0")
		return "0";
	return sign ? number : "-"+number;
}

void LongNumber::RemoveLeadingZeros()
{
	if (number == "0")
		return;
	number.erase(0, number.find_first_not_of('0'));
	if (number.length() == 0)
		number = "0";
}

bool LongNumber::MillerRabinTest(LongNumber& n,LongNumber& q, int k)
{
	random_device rseed;
	mt19937 rgen(rseed());
	int max = atoi(number.c_str()) - 2;
	uniform_int_distribution<int> dist(2, max);
	LongNumber a = dist(rgen);
	LongNumber x = a.ModularExponentiation(q, n);
	if (x == 1 || x == (n - 1))
		return true;
	for (int i = 1; i < k;i++)
	{
		LongNumber p2i = (int) pow(2, i);
		LongNumber x = a.ModularExponentiation(p2i * q, n);
		if (x == (n - 1))
			return true;
	}
	return false;
}

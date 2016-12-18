#include <iostream>
#include <string>
#include <random>
#include <cmath>

using namespace std;

class BigNumber
{
public:
	BigNumber();
	BigNumber(string n_str);
	BigNumber(unsigned int n);
	BigNumber operator*(const BigNumber& b);
	BigNumber operator/(const BigNumber& b);
	BigNumber operator%(const BigNumber& b);
	bool operator==(const BigNumber& b);
	bool operator!=(const BigNumber& b);
	bool operator<(const BigNumber& b);
	bool operator>(const BigNumber& b);
	bool operator<=(const BigNumber& b);
	bool operator>=(const BigNumber& b);
	BigNumber operator+(const BigNumber& b);
	BigNumber operator-(const BigNumber& b);
	BigNumber ModularPower(const BigNumber& power, const BigNumber& mod);
	BigNumber ModularInverse(const BigNumber& mod);
	bool IsPrime();
	bool IsEven();
	bool IsOdd();
	string getStringNumber();
	string getStringNumber() const;
private:
	string number;
	bool MillerRabinTest(BigNumber n, BigNumber q, int k);
};

string Encrypt(const string& message, const BigNumber& number, const BigNumber& mod);

int main()
{
	string P_str, Q_str, E_str;
	getline(cin,P_str);
	getline(cin,Q_str);
	getline(cin,E_str);
	P_str = P_str.substr(2);
	Q_str = Q_str.substr(2);
	E_str = E_str.substr(2);
	BigNumber P(P_str);
	BigNumber Q(Q_str);
	BigNumber N = P * Q;
	BigNumber PhiN = (P - 1) * (Q - 1);
	BigNumber E(E_str);
	BigNumber D = E.ModularInverse(PhiN);
	string operation;
	while(getline(cin,operation))
	{
		if (operation == "Quit") break;
		if (operation == "IsPPrime")
		{
			string response = (P.IsPrime()) ? "Yes" : "No";
			cout << response << endl;
		}
		else if (operation == "IsQPrime")
		{
			string response = (Q.IsPrime()) ? "Yes" : "No";
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

string Encrypt(const string& message, const BigNumber& number, const BigNumber& mod)
{
	BigNumber msg(message);
	msg = msg.ModularPower(number, mod); //encryption
	return msg.getStringNumber();
}

BigNumber::BigNumber()
{
	number = "0";
}

BigNumber::BigNumber(string n_str)
{
	number = n_str;
}

BigNumber::BigNumber(unsigned int n)
{
	number == to_string(n);
}

BigNumber BigNumber::operator*(const BigNumber & b)
{
	//TODO implement multiply operation
	return BigNumber();
}

BigNumber BigNumber::operator/(const BigNumber & b)
{
	//TODO implement divide operation
	return BigNumber();
}

BigNumber BigNumber::operator%(const BigNumber & b)
{
	//TODO implement mod operation
	return BigNumber();
}

bool BigNumber::operator==(const BigNumber& b)
{
	return number == b.number;
}

bool BigNumber::operator!=(const BigNumber & b)
{
	return !(*this == b);
}

bool BigNumber::operator<(const BigNumber & b)
{
	//TODO implement less than operation
	return false;
}

bool BigNumber::operator>(const BigNumber & b)
{
	BigNumber tmp = b;
	return tmp < *this;
}

bool BigNumber::operator<=(const BigNumber & b)
{
	return !(*this > b);
}

bool BigNumber::operator>=(const BigNumber & b)
{
	return !(*this < b);
}

BigNumber BigNumber::operator+(const BigNumber & b)
{
	//TODO implement add operation
	return BigNumber();
}

BigNumber BigNumber::operator-(const BigNumber & b)
{
	//TODO implement minus operation
	return BigNumber();
}

BigNumber BigNumber::ModularPower(const BigNumber & power, const BigNumber & mod)
{
	BigNumber result = 1;
	BigNumber base = *this;
	BigNumber p = power;
	base = base % mod;
	while (atoi(p.getStringNumber().c_str()) > 0)
	{
		if (p.IsOdd())
			result = (result * base) % p;

		p = p / 2;
		base = (base * base) % mod;
	}
	return result;
}

BigNumber BigNumber::ModularInverse(const BigNumber & mod)
{
	BigNumber A1 = 1, A2 = 0, A3 = mod;
	BigNumber B1 = 0, B2 = 1, B3 = *this;
	BigNumber Q, T1, T2, T3;
	while (1)
	{
		if (B3 == 0)
		{
			break;
		}
		if (B3 == 1)
		{
			return B2;
		}
		Q = A3 / B3;
		T1 = A1 - Q * B1;
		T2 = A2 - Q * B2;
		T3 = A3 - Q * B3;
		A1 = B1;
		A2 = B2;
		A3 = B3;
		B1 = T1;
		B2 = T2;
		B3 = T3;
	}
	return BigNumber();
}

bool BigNumber::IsPrime()
{
	if (number == "2" || number == "3")
		return true;
	if (number == "0" || number == "1" || IsEven()) 
		return false;
	BigNumber n = *this;
	BigNumber q = n - 1;
	int k = 0;
	while(q.IsEven())
	{
		q = q / 2;
		k++;
	}
	for (int i = 0; i < 10; i++)
	{
		if (!MillerRabinTest(n, q, k))
			return false;
	}
	return true;
}

bool BigNumber::IsEven()
{
	return number.back() == '0'
		|| number.back() == '2'
		|| number.back() == '4'
		|| number.back() == '6'
		|| number.back() == '8';
}

bool BigNumber::IsOdd()
{
	return number.back() == '1'
		|| number.back() == '3'
		|| number.back() == '5'
		|| number.back() == '7'
		|| number.back() == '9';
}

string BigNumber::getStringNumber()
{
	return number;
}

string BigNumber::getStringNumber() const
{
	return number;
}

bool BigNumber::MillerRabinTest(BigNumber n,BigNumber q,int k)
{
	random_device rseed;
	mt19937 rgen(rseed());
	int max = atoi(number.c_str()) - 2;
	uniform_int_distribution<int> dist(2, max);
	BigNumber a = dist(rgen);
	BigNumber x = a.ModularPower(q, n);
	if (x.number == "1")
		return true;
	for (int i = 0; i < k - 1;i++)
	{
		BigNumber p2i = (int) pow(2, i);
		BigNumber x = a.ModularPower(p2i * q, n);
		if (x == (n - 1))
			return true;
	}
	return false;
}

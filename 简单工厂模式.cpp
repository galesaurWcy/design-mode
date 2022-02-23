#include<iostream>

using namespace std;

class Operation {
private:
	double _NumA;
	double _NumB;
public:
	void SetNumA() {
		cout << "Enter a double number: ";
		if (!(cin >> _NumA))
			throw "It must be a number!";
	}

	double GetNumA() {
		return _NumA;
	}

	void SetNumB() {
		cout << "Enter a double number: ";
		if (!(cin >> _NumB))
			throw "It must be a number!";
	}

	double GetNumB() {
		return _NumB;
	}

	virtual double GetResult() {
		int result = 0;
		return result;
	}
};

class OperationAdd :public Operation {
public:
	double GetResult() {
		double result = GetNumA() + GetNumB();
		return result;
	}
};

class OperationSub :public Operation {
public:
	double GetResult() {
		double result = GetNumA() - GetNumB();
		return result;
	}
};

class OperationMul :public Operation {
public:
	double GetResult() {
		double result = GetNumA() * GetNumB();
		return result;
	}
};

class OperationDiv : public Operation {
public:
	double GetResult() {
		if (GetNumB() == 0) {
			throw "The divisor cannot be 0";
		}
		double result = GetNumA() / GetNumB();
		return result;
	}
};

class OperatorFactory {
public:
	Operation* CreatOperation(char s) {
		Operation* ope = nullptr;
		switch (s)
		{
		case '+':
			ope = new OperationAdd;
			break;
		case '-':
			ope = new OperationSub;
			break;
		case '*':
			ope = new OperationMul;
			break;
		case '/':
			ope = new OperationDiv;
			break;
		default:
			throw "Error input operator!";
			break;
		}
		return ope;
	}

};

int main() {
	OperatorFactory fac;
	cout << "Choose an operation: ";
	char temp;
	cin >> temp;
	try {
		Operation* oper = fac.CreatOperation(temp);
		oper->SetNumA();
		oper->SetNumB();
		double result = 0;
		result = oper->GetResult();
		cout << "Result is: " << result << endl;
	}
	catch (const char* err) {
		cerr << err << endl;
		exit(EXIT_FAILURE);
	}
	return 0;
}

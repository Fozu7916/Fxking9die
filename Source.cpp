#include <iostream>
//консольная программа которую можете переписывать для встройки в разные системы/механизмы

//5 модулей под каждый тип задачи
class N
{
	int A = 0; int t = 0;
	double Find(int A_this, int t_this)
	{
		const double N = (double)A_this / (double)t_this;

		return N;
	}
public:
	double Start()
	{
		std::cout << "Введите A(работа)" << std::endl;
		std::cin >> A;

		std::cout << "Введите t(время)" << std::endl;
		std::cin >> t;

		std::cout << "N(мощность) = " << Find(A, t);
		return Find(A, t);
	}
};
class E
{
	double g = 9.8; double m = 0; double h = 0;
	double Find_p(double m_here, double h_here)
	{

		const double e = m * g * h;
		return e;
	}
	double v; double e1; double e2;
	double Find_kinetic(double m_here, double v_here)
	{
		e1 = m * v * v;
		e2 = e1 / 2;
		return e2;
	}
public:
	double Start_p()
	{
		std::cout << "Масса = ";
		std::cin >> m;
		std::cout << "кг" << std::endl;
		std::cout << "Высота = ";
		std::cin >> h;
		std::cout << "м" << std::endl;
		std::cout << "Енергия потенциальная = " << Find_p(m, h);
		std::cout << "Джоуль" << std::endl;
		return Find_p(m, h);
	}
	double Start_kinetic()
	{
		std::cout << "Масса = ";
		std::cin >> m;

		std::cout << "кг" << std::endl;
		std::cout << "Скорость = ";
		std::cin >> v;


		std::cout << "м/с" << std::endl;
		std::cout << "Енергия кинетическая = " << Find_kinetic(m, v);
		std::cout << " Джоуль" << std::endl;
		return Find_kinetic(m, v);
	}
};




class F
{
	double m = 0, k = 0, l = 0, p = 0, s = 0, P = 0, g = 9.8, V = 0;
	//F = m*g
	//F = k*l
	//F = p * s(p-давление)
	//Fa = P × g × V, 

};
class I
{

};
class Q
{

};



int main()
{
	setlocale(LC_ALL, "RU");
	int variant;
	std::cout << "Выберите тип задачи" << std::endl;
	std::cout << "1-мощность 2-энергия 3-сила 4-ток 5-удельная теплота" << std::endl;
	std::cin >> variant;
	while (variant < 1 or variant >5)
	{
		std::cout << "Неверный тип задачи" << std::endl;
		std::cout << "1-мощность 2-энергия 3-сила 4-ток 5-удельная теплота" << std::endl;
		std::cin >> variant;
	}
	while (variant >= 1 && variant <= 5)
	{
		//Мощность
		if (variant == 1)
		{
			N n;
			n.Start();

		}
		//Энергия
		if (variant == 2)
		{
			E e;
			int x;
			std::cout << "Энергия потенциальная(1) или кинетическая(2)  ";
			std::cin >> x;


			while (x != 1 && x != 2)
			{
				std::cout << "Выбран неправильный вариант" << std::endl;
				std::cout << "Энергия потенциальная(1) или кинетическая(2) ";
				std::cin >> x;

			}
			while (x == 1 or x == 2)
			{
				if (x == 1)
				{
					e.Start_p();
				}


				if (x == 2)
				{
					e.Start_kinetic();
				}
				break;
			}

		}
		//Сила
		if (variant == 3)
		{
			F f;
		}














		break;
	}
	int end;
	std::cin >> end;
	return 0;
}


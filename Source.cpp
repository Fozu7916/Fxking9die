
#include <iostream>
#include <conio.h>
//консольная программа которую можете переписывать для встройки в разные системы/механизмы
//основная задача данного кода - облегчить решение задач по физике, сам код существует онли для моей практике собственно в знании
//физики и формул а так же для практики написания чистого лаконичного кода на языке С++

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
class I
{
	double U; double R; double I;
	double Find(double U_here, double R_here)
	{
		I = U / R;
		return I;
	}
public:
	double Start()
	{
		std::cout << "Сопротивление  = ";
		std::cin >> R;
		std::cout << "Ом" << std::endl;
		std::cout << "Напряжение  = ";
		std::cin >> U;
		std::cout << "Вольт" << std::endl;
		std::cout << "Сила тока = " << Find(R, U);
		std::cout << " Ампер" << std::endl;
		return Find(R, U);

	}
};

//Ниже вследствие того что будет много формул, во имя облегчения кода я буду создавать новый класс под каждый вид силы и теплоты
// убрать возможность делать к больше одного и меньше нуля
class F
{
public:
	virtual double Find(double x, double y) = 0;


	virtual double Start() = 0;
};
class F_tyag : public F // тут есть некая проблема , т.к передаваться должен только один параметр но я решил это просто добавле-
{                       //нием 0 вместо отсутсвющего параметра , если кто знает как это решить легче прошу в лс fozu7916(дс)
	double m;
	double Find(double x, double y) override
	{
		double g = 9.8;
		double F = g * x;
		return F;
	}
public:
	double Start() override
	{
		std::cout << "Масса = ";
		std::cin >> m;
		std::cout << "кг" << std::endl;
		std::cout << "Сила тяжести = " << Find(m, 0);
		std::cout << " Ньютонов" << std::endl;
		return Find(m, 0);
	}


};
class F_k : public F
{
	double k = 0; double l = 0;
	double Find(double x, double y) override
	{
		double F = x * y;
		return F;
	}
public:
	double Start() override
	{
		std::cout << "Коэфицент трения = ";
		std::cin >> k;
		std::cout << "Длина = ";
		std::cin >> l;
		std::cout << "м" << std::endl;
		std::cout << "Сила трения = " << Find(k, l);
		std::cout << " Ньютонов" << std::endl;
		return Find(k, l);
	}
};
class F_d : public F
{
	double p; double s;
	double Find(double x, double y) override
	{
		double F = x * y;
		return F;
	}
public:
	double Start() override
	{
		std::cout << "Давление  = ";
		std::cin >> p;
		std::cout << "Паскаль" << std::endl;
		std::cout << "Площадь = ";
		std::cin >> s;
		std::cout << "м^2" << std::endl;
		std::cout << "Сила = " << Find(p, s);
		std::cout << " Ньютонов" << std::endl;
		return Find(p, s);
	}
};
class Fa : public  F
{
	double P; double V;
	double Find(double P_here, double V_here) override
	{
		double F = P_here * V_here;
		return F;
	}
public:
	double Start() override
	{
		std::cout << "Плотность жидкости  = ";
		std::cin >> P;
		std::cout << "Кг/м^3" << std::endl;
		std::cout << "Обьём = ";
		std::cin >> V;
		std::cout << "м^3" << std::endl;
		std::cout << "Сила = " << Find(P, V);
		std::cout << " Ньютонов" << std::endl;
		return Find(P, V);
	}
};
//класс выполняющий работу
class Find_force
{
public:
	void Find(F* f)
	{
		f->Start();

	}
};




class Q_teplota
{
	double t1, t2, c, m;
	int varik;

	double Find()
	{
		double Q = c * m * (t1 - t2);
		return Q;
	}
public:
	double Start()
	{
		std::cout << "Введите температуру начальную" << std::endl;
		std::cin >> t1;
		std::cout << "Введите температуру конечную" << std::endl;
		std::cin >> t2;
		std::cout << "Введите массу" << std::endl;
		std::cin >> m;
		std::cout << "Выберите из списка необходимое вещество , если его нету то самостоятельно введите удельную теплоёмкость(c)" << std::endl;
		std::cout << "... 8 - next page 9 - previous page 0 - указать теплоёмкость в-ва самостоятельно" << std::endl;
		std::cin >> varik;
		if (varik == 0)
		{
			std::cout << "Введите теплоёмкость" << std::endl;
			std::cin >> c;
			std::cout << "Ваш результат \n Q = " << Find();
			return Find();
		}
	}
};

/*

Дюралюминий =880
Железо = 452
Золото = 129
Латунь = 378
Медь = 383
Никель = 443

double  Алюминий = 897;
	double Бронза_алюминиевая = 420;
	double Бронза_оловянистая = 380;
	double Вольфрам = 134;
	double Дюралюминий = 880;

Олово Sn

228

Платина Pt

133

Ртуть Hg

139

Свинец Pb

128

Серебро Ag

235

Сталь стержневая арматурная

482

Сталь углеродистая

468

Сталь хромистая

460

Титан Ti

520

Уран U

116

Цинк Zn

385

Чугун белый

540

Чугун серый

470

Жидкости

Cp, Дж / (кг·К)

Азотная кислота(100 % -ная) NH3

1720

Бензин

2090

Вода

4182

Вода морская

3936

Водный раствор хлорида натрия(25 % -ный)

3300

Глицерин

2430

Керосин

2085…2220

Масло подсолнечное рафинированное

1775

Молоко

3906

Нефть

2100

Парафин жидкий(при 50С)

3000

Серная кислота(100 % -ная) H2SO4

1380

Скипидар

1800

Спирт метиловый(метанол)

2470

Спирт этиловый(этанол)

2470

Топливо дизельное(солярка)

2010

*/



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
			int x = 0;
			std::cout << "Выберите тип силы" << "\n" << "1-сила тяжести   2-сила трения 3-сила давления 4-сила Архимеда" << std::endl;
			std::cin >> x;
			while (x < 1 or x >4)
			{
				std::cout << "Неверный тип силы" << std::endl;
				std::cout << "Выберите тип силы" << "\n" << "1-сила тяжести   2-сила трения 3-сила давления 4-сила Архимеда" << std::endl;
				std::cin >> x;
			}

			while (x >= 1 && x <= 4)
			{
				Find_force find;
				if (x == 1)
				{
					F_tyag fe;
					find.Find(&fe);
				}
				if (x == 2)
				{
					F_k fe;
					find.Find(&fe);
				}
				if (x == 3)
				{
					F_d fe;
					find.Find(&fe);
				}
				if (x == 4)
				{
					Fa fe;
					find.Find(&fe);
				}

				break;
			}





















			break;
		}
		//сила тока
		if (variant == 4)
		{
			I i;
			i.Start();
		}
		//теплота
		if (variant == 5)
		{
			int x = 0;
			std::cout << "Выберите тип Теплоты" << "\n" << "1-Теплота нагревания/охлаждения....." << std::endl;
			std::cin >> x;
			while (x < 1 or x >4)
			{
				std::cout << "Неверный тип Теплоты" << std::endl;
				std::cout << "Выберите тип Теплоты" << "\n" << "1-Теплота нагревания/охлаждения....." << std::endl;
				std::cin >> x;
			}
			if (x == 1)
			{
				Q_teplota q;
				q.Start();
			}

		}


		int end;
		std::cout << "\nНажмите любую клавишу для завершения рабооты";
		_getch();
		return 0;
	}
}



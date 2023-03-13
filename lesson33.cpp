// lesson33.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
/*
1.	Написать функцию, добавляющую в конец списка вещественных чисел элемент, значение которого равно среднему арифметическому всех его элементов.


2.	Имеется отсортированный массив целых чисел. Необходимо разработать функцию insert_sorted,
которая принимает вектор и новое число и вставляет новое число в определенную позицию в векторе,
чтобы упорядоченность контейнера сохранялась. Реализуйте шаблонную функцию insert_sorted,
которая сможет аналогично работать с любым контейнером, содержащим любой тип значения.

3.  Подсчитайте количество гласных букв в веденной пользователем строке. Для подсчета используйте 4 способа:
    - count_if и find
    - count_if и цикл for
    - цикл for и find
    - 2 цикла for
*/

#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<string_view>


template<typename T>
void Push_back_arithmetic_mean(std:: vector<T> v_vector)
{
    T summ_elements = 0;
    for (int i = 0; i < v_vector.size(); i++)
    {
        summ_elements += v_vector.at(i);


    }

   v_vector.push_back(summ_elements / static_cast<T>(v_vector.size()));

   for (int i = 0; i < v_vector.size(); i++)
   {
       std::cout << v_vector.at(i) << " ";
        
   }


}

void insert_sorted(std::vector<int>& v_vector,int& n)
{
    auto it = std::upper_bound(v_vector.begin(), v_vector.end(), n);
    v_vector.insert(it, n);

    for (int i = 0; i < v_vector.size(); i++)
    {
        std::cout << v_vector.at(i) << " ";

    }

}

template<typename G>

void VectorCout(std::vector<G>& v_vector)
{

    for (int c=0;c<v_vector.size();++c)
    {

        std::cout << v_vector.at(c) << " ";
   }

    std::cout << std::endl;

}

template<typename U,typename value>

void insert_sorted(std::vector<U>& v_vector, value& n)
{
    auto it = std::upper_bound(v_vector.begin(), v_vector.end(), n);
    v_vector.insert(it, n);

    for (int i = 0; i < v_vector.size(); i++)
    {
        std::cout << v_vector.at(i) << " ";

    }
}

    int KolGlassnihForFor(std::vector<char>& vv_vector)
    {
        char massive[6]{ 'e','y','u','i','o','a'};
        int ccount = 0;
        for (int i = 0; i < vv_vector.size(); i++)
        {
            for (int f = 0; f < 6; f++)
            {
                if (massive[f] == vv_vector.at(i))
                {
                    ccount++;
               }

            }

        }
        return ccount;

    }
    int KolGlassnihCount_If_find(std::vector<char>& vv_vector)
    {
        std::string massive{ "eyuoia" };
        
        return std::count_if(vv_vector.begin(), vv_vector.end(), [&massive](const char& c)
            {
                return massive.find(c) != std::string::npos;

            });
        
        

    }

    int KolGlassnihCount_If_for(std::vector<char>& vv_vector)
    {
        std::string massive{ "eyuoia" };

        return std::count_if(vv_vector.begin(), vv_vector.end(), [&massive](const char& c)
            {
                for (const auto& search_element : massive)
                {
                    if (c == search_element) return true;
                }
                return false;

            });



    }
    int KolGlassnih_For_find(std::vector<char>& vv_vector)
    {
        std::string massive{ "eyuoia" };
        int ccout = 0;

        for (const auto& c : vv_vector)
        {
            if (massive.find(c) != std::string::npos) ccout++;


        }

        return ccout;
        



    }






int main()
{
    setlocale(LC_ALL, "rus");

    std::cout << "Первая часть" << std::endl;

    std::vector<int> Test{ 1,3,4,5,6,7,8 };
    std::cout << "Дан отсортированный массив\n : ";
    VectorCout(Test);
    std::cout << "Добавляем среднее арифметическое всех элементов в конец контейнера :\n ";



    Push_back_arithmetic_mean(Test);

    std::cout << "\nВторая часть" << std::endl;

    double f = 0;
    std::vector<double> Test1{ 1.5,3.2,4.6,5.9,6.1,7.4,8.2 };
    std::cout << "Даны два отсортированных массива\n : "  ;
    VectorCout(Test);
    VectorCout(Test1);

    std::cout << "Введите число котороe нужно вставить в отсортированный вектор : " ;
    std::cin >> f;
    insert_sorted(Test, f);
    std::cout << std::endl;
    insert_sorted(Test1,f);
    std::cout << std::endl;




    std::cout << "\nТретья  часть" << std::endl;

    std::string stroka;
    std::cout << "Введите строку с гласными буквами на английском : ";
    std::cin >> stroka;
    std::vector<char>Stroka(stroka.begin(), stroka.end());
    std::cout << "Метод For for" << std::endl;
    
    std::cout << KolGlassnihForFor(Stroka) << std::endl;
    std::cout << "Метод count_find" << std::endl;
    std::cout << KolGlassnihCount_If_find(Stroka) << std::endl;
    std::cout << "Метод count_find_for" << std::endl;
    std::cout << KolGlassnihCount_If_for(Stroka) << std::endl;
    std::cout << "Метод For_find" << std::endl;
    std::cout << KolGlassnih_For_find(Stroka) << std::endl;

    





    

   

   

   



   
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.



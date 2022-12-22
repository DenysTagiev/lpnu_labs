#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// Клас Автомобіль
class Car
{
public:
    // Конструктор Автомобіля
    Car(string brand, int age, int maxSpeed, int horsePower)
    {
        this->brand = brand;
        this->age = age;
        this->maxSpeed = maxSpeed;
        this->horsePower = horsePower;
    }

    // Функція повернення марки автомобіля
    string getBrand()
    {
        return brand;
    }

    // Функція повернення віку автомобіля
    int getAge()
    {
        return age;
    }

    // Функція повернення максимальної швидкості автомобіля
    int getMaxSpeed()
    {
        return maxSpeed;
    }

    // Функція повернення потужності автомобіля
    int getHorsePower()
    {
        return horsePower;
    }

    string getId()
    {
        return brand + to_string(age) + to_string(maxSpeed) + to_string(horsePower);
    }

    // Функція виведення інформації про автомобіль на екран
    void printInfo()
    {
        cout << "Brand: " << brand << endl;
        cout << "Age: " << age << endl;
        cout << "Max speed: " << maxSpeed << endl;
        cout << "Horse power: " << horsePower << endl;
    }

public:
    // Поле марки автомобіля
    string brand;
    // Вік автомобіля
    int age;
    // Максимальна швидкість автомобіля
    int maxSpeed;
    // Потужність автомобіля
    int horsePower;
};

// Клас паркінг
class Parking
{
public:
    // Конструктор паркінгу
    Parking(int maxPlaces, int parkingPrice)
    {
        this->maxPlaces = maxPlaces;
        this->parkingPrice = parkingPrice;
    }

    // Функція паркування автомобіля
    void parkCar(Car car)
    {
        if (cars.size() == maxPlaces)
        {
            cout << "Parking is full!" << endl;
        }
        else
        {
            cars.push_back(car);
            cout << "Car parked!" << endl;
        }
    }

    // Функція залишення паркінгу
    void leaveParking(Car car)
    {
        vector<Car> cars_new;
        for (int i = 0; i < cars.size(); i++)
        {
            if (car.getId() != cars[i].getId())
                cars_new.push_back(cars[i]);
        }
        cars = cars_new;
        // cars.erase(remove(cars.begin(), cars.end(), car), cars.end());
        cout << "Car left the parking!" << endl;
    }

    // Функція сортування автомобілів за тривалістю стоянки
    void sortByTime()
    {
        // vector<Car> cars_new;
        for (int i = 0; i < cars.size(); i++)
        {
            for (int j = 0; j < cars.size(); j++)
            {
                if (cars[i].getAge() < cars[j].getAge())
                {
                    Car temp = cars[i];
                    cars[i] = cars[j];
                    cars[j] = temp;
                }
            }
        }
    }

    // Функція порахування ціни паркінгу
    int calculatePrice()
    {
        int totalPrice = 0;
        for (Car car : cars)
        {
            totalPrice += car.getAge() * parkingPrice;
        }
        return totalPrice;
    }

public:
    // Максимальна кількість місць на паркінгу
    int maxPlaces;
    // Ціна однієї години стоянки
    int parkingPrice;
    // Колекція автомобілів на паркінгу
    vector<Car> cars;
};

int main()
{
    // Створюємо автомобілі
    Car car1("BMW", 5, 250, 250);
    Car car2("Audi", 7, 200, 200);
    Car car3("Mercedes", 3, 300, 300);

    // Створюємо паркінг
    Parking parking(2, 20);

    // Запаркувати автомобілі
    parking.parkCar(car1);
    parking.parkCar(car2);
    parking.parkCar(car3);

    // Вивести інформацію про автомобілі
    cout << "Cars on parking:" << endl;
    for (Car car : parking.cars)
    {
        car.printInfo();
    }

    // Відсортувати автомобілі за тривалістю стоянки
    parking.sortByTime();
    cout << endl
        << "Cars sorted by time:" << endl;
    for (Car car : parking.cars)
    {
        car.printInfo();
    }
    cout << endl
        << "Total parking price: " << parking.calculatePrice() << endl;

    // Залишити паркінг
    parking.leaveParking(car1);

    return 0;
}
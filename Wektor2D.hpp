#include <iostream>
#include <cmath>
#include "catch.hpp"

class Informer {
public:
    Informer() {
        std::cout << "Konstrukcja Informera\n";
    }

    ~Informer() {
        std::cout << "Destrukcja Informera\n";
    }
};

class Wektor2D {
private:
    static int num_wek;
    double x;
    double y;
    Informer info; 

public:
	Wektor2D(){x=0; y=0;}
	//konstruktor
    Wektor2D(double x, double y): x(x), y(y){
        num_wek++;
        std::cout << "Tworze wektor: Wektor2D(" << x << ", " << y << "), liczba wektorow: " << num_wek << '\n';
    }

    // Destruktor
    ~Wektor2D() {
        num_wek--;
        std::cout << "Usuwam wektor: Wektor2D(" << x << ", " << y << "), liczba wektorow: " << num_wek << '\n';
    }

    //norma wektora
    double norm() {
        return std::sqrt(x * x + y * y);
    }

    //ustawianie nowej wartosci wspolrzednej
    void setX(double newX) {
        x = newX;
    }

    double getX() {
        return x;
    }

    void setY(double newY) {
        y = newY;
    }

    double getY() {
        return y;
    }

    // przeciazenia-dodawania
    Wektor2D operator+(const Wektor2D& other) {
        return Wektor2D(x + other.x, y + other.y);
    }

    // przeciazenia-mnozenie
    double operator*(const Wektor2D& other) {
        return x * other.x + y * other.y;
    }

    // Przeciążony operator <<
    friend std::ostream& operator<<(std::ostream& os, const Wektor2D& w) {
        os << "Wektor2D(" << w.x << ", " << w.y << ")";
        return os;
    }

    // liczba wektorow
    static int populacja() {
        return num_wek;
    }

    // drukowanie
    void print() {
        std::cout << "Wektor2D(" << x << ", " << y << ")\n";
    }
};

int Wektor2D::num_wek = 0;  


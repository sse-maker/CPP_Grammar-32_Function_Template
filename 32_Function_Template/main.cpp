//
//  main.cpp
//  32_Function_Template
//
//  Created by 세광 on 2021/07/27.
//

#include <iostream>
#include <string>

using namespace std;

class Vector2 {
public:
    Vector2() : x(0), y(0) {}
    Vector2(float x, float y) : x(x), y(y) {}
    float GetX() const { return x; }
    float GetY() const { return y; }
    
    Vector2 &operator+=(const Vector2 &rhs) {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }
    
private:
    float x, y;
};

template<typename T> // 임의의 타입을 정할 경우 그 임의의 타입에 대한 새로운 함수를 찍어낼 수 있음
T getArraySum(const T arr[], int n) {
    T sum = T(); // 기본 생성자 호출
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}
// 위 자체는 아직 함수가 아님 (함수를 생성해주는 템플릿)

int main() {
    int iarr[5] = { 3, 1, 4, 1, 5 };
    float farr[5] = { 3.1, 1.2, 4.3, 1.4, 5.5 };
    Vector2 varr[3] = { Vector2(1, 2), Vector2(3, 4), Vector2(5, 6) };
    string sarr[3] = { "hello", "world", "doodle" };
    
    int isum = getArraySum(iarr, 5);
    float fsum = getArraySum(farr, 5);
    Vector2 vsum = getArraySum(varr, 3);
    string ssum = getArraySum(sarr, 3);
    
    cout << isum << endl;
    cout << fsum << endl;
    cout << vsum.GetX() << ", " << vsum.GetY() << endl;
    cout << ssum << endl;
}

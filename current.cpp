// Step 8 — const 멤버 함수와 getter
//
// [지난 스텝 통과] 클래스/생성자/초기화 리스트/객체 생성 모두 정확했다.
//
// Step 6 에서 const std::vector<int>& 로 받으면 "안 바꾸겠다" 는 약속이
// 된다고 했다. 그런데 약속을 받은 쪽에도 문제가 생긴다.
//
//   void print(const Rect &r) { std::cout << r.area(); }   // ✗ 컴파일 에러
//
// r 은 const 인데 area() 가 "나는 안 바꾼다" 고 말한 적이 없기 때문이다.
// 컴파일러는 함수 몸통을 들여다보고 봐주지 않는다. 선언만 본다.
//
// 그래서 객체를 바꾸지 않는 멤버 함수에는 뒤에 const 를 붙인다.
//
//   int area() const { return w * h; }
//        매개변수 괄호 뒤, 중괄호 앞이다.
//        이 함수 안에서 멤버를 바꾸려 하면 컴파일 에러가 난다.
//        실수로 바꾸는 것까지 컴파일러가 막아준다.
//
// C 에는 이런 게 없었다. rect_area(const struct Rect *r) 처럼 포인터에
// const 를 붙이는 게 전부였고, 그마저도 안 붙이는 코드가 대부분이었다.
//
// [getter]
//   멤버 변수가 private 이면 바깥에서 못 읽는다. 읽기만 허용하고 싶을 때
//   값을 돌려주는 함수를 만든다. 이걸 getter 라 한다.
//
//     int getWidth() const { return w; }
//
//   "그냥 public 으로 두면 되지 않나" 싶지만 다르다.
//   public 변수는 읽기와 쓰기가 같이 열린다. getter 만 두면 읽기만 열린다.
//   나중에 저장 방식이 바뀌어도(예: w 를 없애고 계산해서 돌려주기)
//   바깥 코드는 그대로 쓸 수 있다.
//
// [예제]
//   class Circle {
//       double r;
//   public:
//       Circle(double radius) : r(radius) {}
//       double getR() const  { return r; }          // 읽기만
//       double area() const  { return 3.14 * r * r; }
//       void scale(double k) { r *= k; }            // 바꾸므로 const 없음
//   };
//
//   void show(const Circle &c) {       // const 객체
//       std::cout << c.area();         // OK. area 가 const 라서.
//       // c.scale(2);                 // ✗ 에러. scale 은 const 가 아니다.
//   }
//
// [힌트]
//   - 바꾸지 않는 멤버 함수에는 전부 const 를 붙이는 게 원칙이다.
//     나중에 붙이려면 호출부까지 줄줄이 고쳐야 하니 처음부터 붙인다.
//   - const 객체에는 const 멤버 함수만 부를 수 있다. 반대는 자유롭다.
//   - 값을 바꾸는 함수(scale 등)에는 붙이면 안 된다. 실제로 바꾸니까.
//
// [문제]
//   Step 7 의 Rect 를 고쳐 아래를 만족시키시오.
//
//   멤버 변수 (private)
//     너비, 높이. int.
//
//   생성자
//     Rect(int w, int h)
//
//   const 멤버 함수 (객체를 바꾸지 않는다)
//     int  area() const        넓이
//     int  perimeter() const   둘레
//     bool isSquare() const    정사각형 여부
//     int  getWidth() const    너비를 돌려준다
//     int  getHeight() const   높이를 돌려준다
//
//   const 아닌 멤버 함수 (객체를 바꾼다)
//     void scale(int k)
//       너비와 높이에 각각 k 를 곱한다. 돌려주는 값은 없다.
//
//   자유 함수 (클래스 바깥. 멤버가 아니다)
//     void printRect(const Rect &r)
//       받은 사각형의 너비, 높이, 넓이, 둘레, 정사각형 여부를 출력한다.
//       매개변수가 const 참조이므로, 여기서 부르는 멤버 함수는
//       전부 const 여야 컴파일된다. 그게 이번 스텝의 확인 지점이다.
//
//   main
//     3x4 객체를 만들어 printRect 로 출력한다.
//     scale(2) 를 부른 뒤 다시 printRect 로 출력한다.
//     5x5 객체도 하나 만들어 printRect 로 출력한다.
//
//   실행 예시 (문구는 자유)
//     3x4 area 12 perimeter 14 square? no
//     6x8 area 48 perimeter 28 square? no
//     5x5 area 25 perimeter 20 square? yes
//
//   조건: printRect 는 반드시 const Rect& 로 받을 것.
//   컴파일: g++ -std=c++20 -Wall current.cpp -o /tmp/out && /tmp/out

#include <iostream>

class Rect {
private:
    int width;
    int height;
public:
    Rect(int width, int height)
        : width(width), height(height) {}
    
    int area() {
        return width * height;
    }
    int perimeter() {
        return (width + height) * 2;
    }
    int getWidth() {
        return width;
    }
    int getHeight() {
        return height;
    }

    void scale(int k) {
        width *= k;
        height *= k;
    }

    
};

void printRect(const Rect &r) {
    
}

int main() {
    Rect nemo(10, 20);
    std::cout
        << nemo.area() << '\n'
        << nemo.isSquare() << '\n'
        << nemo.perimeter() << std::endl;

    return 0;
}
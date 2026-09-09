// Step 7 — 클래스
//
// C 의 struct 는 데이터만 담았고, 다루는 함수는 바깥에 흩어져 있었다.
//   struct Rect { int w, h; };
//   int rect_area(struct Rect *r) { return r->w * r->h; }
//   rect_area(&r);
// C++ 은 그 함수를 안으로 넣는다. 그래서 &r 도, r-> 도 사라진다.
//
// class 는 struct 와 같되 기본이 private 이다. private 은 바깥에서
// 직접 못 건드린다는 뜻. 잘못된 상태(음수 너비 등)를 원천 차단한다.
// 생성자는 객체가 태어날 때 자동으로 불린다. 이름은 클래스 이름과
// 같고 반환 타입이 없다. 초기화 안 된 객체가 아예 생길 수 없다.
//
// [예제 — 원]
//   class Circle {
//   private:
//       double r;
//   public:
//       Circle(double radius) { r = radius; }   // 생성자
//       double area() { return 3.14159 * r * r; }
//       bool isBig()  { return r > 10; }
//   };                                          // ← 세미콜론 필수
//
//   int main() {
//       Circle c1(2.0);          // 객체 생성. C 의 struct Rect r = {..} 자리
//       Circle c2(15.0);         // c1 과 별개. 각자 자기 r 을 가진다.
//       std::cout << c1.area();  // 포인터가 아니므로 -> 아니고 .
//       if (c2.isBig()) ...      // bool 은 C++ 의 진짜 타입
//       // c1.r                  // ✗ private
//   }
//
// [힌트]
//   - 멤버 함수 안에서는 멤버 변수를 그냥 이름으로 쓴다. this-> 불필요.
//   - Circle c3(); 는 객체가 아니라 함수 선언이 된다. 인자 없으면 괄호를 뺀다.
//   - bool 을 그냥 출력하면 1 / 0 이다. 조건문으로 yes/no 를 찍어도 된다.
//
// [1차 채점 — 재도전]
//   1. 88줄 세미콜론 빠져서 컴파일 안 됨.
//   2. main 이 비었다. 객체를 만들어 쓰는 게 이번 스텝의 절반이다. 채울 것.
//   3. u_int32_t 는 표준이 아니다(BSD 계열). 표준은 <cstdint> 의 uint32_t.
//      게다가 부호 없는 타입은 뺄셈이 음수가 되면 0 이 아니라 42억 쪽으로
//      감싸 돈다. 여기선 그냥 int 를 쓸 것.
//   4. 초기화 리스트 : width(width), height(height) 는 잘 썼다.
//      몸통에서 대입하면 "기본값으로 만든 뒤 덮어쓰기" 지만,
//      초기화 리스트는 처음부터 그 값으로 만든다. 이쪽이 낫다.
//   5. 질문 — "마름모면 어떡할 건데"
//      Rect 는 너비/높이 두 값으로 표현되는 직사각형만 모델링한다.
//      마름모는 이 클래스로 만들 방법이 아예 없으니 걱정할 상황이 안 생긴다.
//      클래스 설계는 "무엇을 표현할 수 있게 할지" 정하는 일이다.
//
// [문제]
//   사각형을 나타내는 Rect 클래스를 만드시오.
//
//   멤버 변수 (private)
//     너비, 높이. 정수 두 개.
//
//   생성자
//     Rect(int w, int h)
//       너비와 높이를 받아 멤버 변수에 넣는다. 반환 타입은 쓰지 않는다.
//
//   멤버 함수 (public, 세 개 모두 매개변수 없음)
//     int  area()
//       넓이를 돌려준다. 너비 x 높이.
//       매개변수가 없는 이유는 필요한 값이 이미 자기 안에 있기 때문이다.
//
//     int  perimeter()
//       둘레를 돌려준다. (너비 + 높이) x 2.
//
//     bool isSquare()
//       정사각형이면 true, 아니면 false 를 돌려준다.
//       너비와 높이가 같은지 비교한 결과가 곧 답이다.
//       비교식 자체가 bool 이므로 if 로 감쌀 필요는 없다.
//
//   main
//     3x4 짜리와 5x5 짜리 Rect 객체를 하나씩 만들고,
//     각 객체마다 area / perimeter / isSquare 세 개를 모두 출력한다.
//
//   실행 예시 (문구는 자유)
//     Rect 3x4  -> area 12, perimeter 14, square? no
//     Rect 5x5  -> area 25, perimeter 20, square? yes
//
//   조건: 멤버 변수는 private. 생성자로 초기화 (set 방식 금지).
//   컴파일: g++ -std=c++20 -Wall current.cpp -o /tmp/out && /tmp/out

#include <iostream>
#include <cstdint>

class Rect {
private:
    uint16_t width;
    uint16_t height;
public:
    Rect(uint16_t width, uint16_t height)
        : width(width), height(height) {}
    
    int area() {
        return width * height;
    }
    int perimeter() {
        return (width + height) * 2;
    }
    bool isSquare() {
        return width == height;
    }
};

int main() {
    Rect nemo(10, 20);
    std::cout
        << nemo.area() << '\n'
        << nemo.isSquare() << '\n'
        << nemo.perimeter() << std::endl;

    return 0;
}
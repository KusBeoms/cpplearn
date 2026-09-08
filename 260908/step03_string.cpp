// ============================================================
// Step 3 — std::string (문자열)
// ============================================================
//
// [먼저, 세 번째 지적]
//   여전히 int main(void) 라고 쓰고 있다. C++ 에서는 int main() 이다.
//   C 에서 (void) 는 "인자 없음"을 명시하는 장치였지만,
//   C++ 에서는 빈 괄호 () 자체가 이미 "인자 없음"을 뜻한다.
//   이번엔 꼭 int main() 으로 쓸 것.
//
// [개념] C 의 char 배열이 C++ 에서는 std::string 이 된다.
//
//   C 에서 문자열은 고통이었다.
//     char buf[100];              // 크기를 미리 정해야 하고
//     strcpy(buf, "hello");       // 넘치면 터지고
//     strcat(buf, " world");      // 함수 이름을 다 외워야 하고
//     if (strcmp(buf, "x") == 0)  // == 로 비교하면 주소를 비교해버리고
//     char *p = malloc(...);      // 동적이면 free 까지 책임져야 했다
//
//   C++ 의 std::string 은 길이가 자동으로 늘어나고,
//   메모리도 알아서 잡고 알아서 반납한다. free 를 부를 일이 없다.
//
//     C                                C++
//     -------------------------------  --------------------------
//     #include <string.h>              #include <string>
//     char s[100];                     std::string s;
//     strcpy(s, "hello");              s = "hello";
//     strcat(s, " world");             s += " world";
//     strlen(s)                        s.size()
//     strcmp(a, b) == 0                a == b
//
// [문법]
//   #include <string>
//
//   std::string s = "hello";
//   std::string t = s + " world";   // + 로 이어붙이기
//   t += "!";                       // 뒤에 덧붙이기
//
//   s.size()                        // 길이 (s.length() 도 같다)
//   s[0]                            // 첫 글자 (배열처럼 접근된다)
//   s.empty()                       // 비었는지
//
//   if (s == "hello") { }           // == 로 내용 비교. strcmp 아님.
//
//   std::cin >> s;                  // 공백 전까지 한 단어 읽기
//   std::cout << s;                 // 그냥 출력됨
//
// [힌트]
//   - <string> 헤더를 include 해야 한다. <iostream> 만으로는 부족하다.
//     (환경에 따라 우연히 되기도 하지만, 반드시 명시할 것.)
//   - cin >> 은 공백을 만나면 거기서 끊는다. 이 문제에는 그게 맞다.
//   - 길이는 s.size() 처럼 점(.) 을 찍어서 쓴다.
//     C 처럼 strlen(s) 가 아니라, 문자열 자기 자신에게 물어보는 방식이다.
//
// ============================================================
// [1차 채점 — 재도전]
//
//   int main() 로 고친 것 확인했다. 좋다.
//   std::string, .size(), <string> 헤더 모두 제대로 썼다.
//
//   틀린 곳: 느낌표가 빠졌다.
//     기대  Hello, dalgsiki!
//     실제  Hello, dalgsiki
//   출력 형식은 예시와 글자 하나까지 똑같아야 한다. 이것만 고치면 통과다.
//
//   질문 답 — "이런식으로 내리는게 맞음?"
//     맞다. << 로 이어붙인 건 세미콜론까지가 문장 하나이고,
//     C++ 은 줄바꿈을 문장의 끝으로 보지 않는다. 몇 줄에 걸쳐 써도 된다.
//     다만 보통은 << 를 줄 앞에 두고 들여쓰기를 맞춘다. 읽기 쉬워서다.
//
//       std::cout << "Hello, " << value << "!\n"
//                 << "Your name has " << value.size() << " letters.\n";
//
//     사실 이 경우는 문장 두 개로 나누는 편이 더 읽기 쉽다.
//     한 줄에 하나씩, std::cout 문장을 두 번 쓰는 것도 똑같이 좋은 답이다.
//
//   덧 — return 0; 을 안 썼는데, 그건 틀린 게 아니다.
//     C++ 에서 main 은 return 문이 없으면 자동으로 0 을 반환한다.
//     main 에서만 허용되는 특례다. 다른 함수는 반드시 반환해야 한다.
//
// ============================================================
// [문제]
//   이름 한 단어를 입력받아, 인사말과 이름의 길이를 출력하시오.
//
//   실행 예시 (dalgsiki 는 사용자가 입력한 값)
//     Enter your name: dalgsiki
//     Hello, dalgsiki!
//     Your name has 8 letters.
//
//   조건
//     - char 배열, strlen, strcpy 등 C 문자열 함수 사용 금지.
//     - std::string 만 사용할 것.
//
//   컴파일
//     g++ -std=c++20 -Wall current.cpp -o /tmp/out && /tmp/out
// ============================================================

#include <iostream>
#include <string>

int main() {
    std::string value;
    std::cout << "Enter your name : ";
    std::cin >> value;
    std::cout
        << "Hello, " << value << "!\n"
        << "Your name has " << value.size() << " letters." << "\n";

    return 0;
    // \n == std::endl 같은건가? 뭘 더 추천하니
}
#include <iostream>
using namespace std;
// 객체 지향 프로그래밍의 시작은 클래스를 만들어서 시작합니다. 
// 피보나치 수열을 만드는 클래스를 만들고 시작합니다.
// 우리가 해야 하는 블랙잭 프로그래밍에서도 모든 내용은 클래스로 작성해 보세요.
// 콘솔창에 구현한 게임 내용을 보여주거나, 과제에서 요구하는 내용을 표현하는 과정도 모두 Handler 클래스를 이용해 객체로 구현하기를 바랍니다.
class Fibonacci {
    // Fibonacci sequence는 자기 자신을 호출합니다. 있는 그대로 recursion으로 작성하면 매우 느리죠.
    // 이제 클래스를 구성해 봅시다. 
    // Fibonacci sequence는 외부에서 관심있는 특정 숫자 n만 있으면 자기 자신을 호출하며 값을 계산할 수 있습니다.
    // 따라서 이를 클래스로 구성할 때 어떻게 해야 할까요?
    // fibonacci sequence 특성 상, 외부에서 함수를 호출하면, 계속 자기 자신을 호출하면 되기 때문에 해당 함수는 public으로 작성하고, 
    // 외부에서 기입하는 특정 숫자 n을 매개변수로 가져오면 됩니다. 

    // 여기에, 오늘 다룬 하나의 아이디어는 fibonacci 계산 시 이미 계산한 내용은 memo에 기입해 두려고 합니다. 
    // 외부에서는 fibonacci가 계산된 결과가 관심 있지, 계산 중 사용하는 memo에는 관심이 없습니다.
    // 따라서 이를 private 변수로 지정하여 캡슐화시키면 됩니다.
private:
    int* memo;
public:
    // 메모를 사용한다면 계산하려는 숫자 n에 해당하는 값들을 배열로 저장해 둘 거예요.
    // 따라서 n + 1 크기의 메모를 가진 객체를 만들어 봅시다.
    // 객체를 만들 때 메모를 함께 만들어 주면 편하겠죠? 따라서 생성자를 이용해 메모를 가진 객체를 만들어 줍니다.
    // 그리고 메모의 크기를 모르기 때문에 동적 배열을 사용합니다.
    Fibonacci(int n) {
        memo = new int[n + 1];            // 이렇게 동적 배열을 사용하고(수업 시간에 한 그대로), 
        for (int i = 0; i < n + 1; ++i) { // -1로 초기화 시켜 줍니다.
            memo[i] = -1;               // -1로 초기화 시켜주는 이유는 아래 fib_memo 함수에서 확인할 수 있습니다.
        }
    }
    int fib(int n) {                    // fibonacci sequence를 그대로 recursion으로 구현한 매우 느린 함수입니다.
        if (n <= 2) return 1;
        return fib(n - 1) + fib(n - 2);
    }
    int fib_memo(int n) {               // memo를 사용하는 fibonacci 입니다.
        // 이번에 생각해본 풀이 방법은 이미 recursion이 진행된 fib(n)의 경우, memo에 저장하고, 메모에서 꺼내 사용하기로 했습니다.
        // memo를 모두 -1로 초기화 해 두었으니, -1이 아닌 경우 memo에 이미 저장되어 있다는 뜻, 그러니까 fib(n)을 계산했다는 뜻이겠죠?
        if (memo[n] != -1) return memo[n];  // 따라서 메모에 있으면, memo 값을 그대로 사용합니다. 
        if (n <= 2) {   // 메모에 없는 경우는 위의 일반적인 fibonacci 계산을 그대로 진행합니다.
            memo[n] = n;
        }
        else {
            memo[n] = fib(n - 1) + fib(n - 2);
        }
        return memo[n];
    }
    ~Fibonacci() {
        delete[] memo;
    }
};

int main() {
    int n = 10;
    Fibonacci fibonacci(10);
    cout << "The " << n << "nth Fibonacci number is : " << fibonacci.fib(n) << endl;
    cout << "If you use memo, the number is " << fibonacci.fib_memo(n) << endl;
    return 0;
}

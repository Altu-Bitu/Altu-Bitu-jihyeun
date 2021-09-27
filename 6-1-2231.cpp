#include <iostream>

// 생성자+각 자리수=분해합 , 분해합을 만들 수 있는 가장 작은 생성자 구하기
// 브루트포스 추측단서 : n의 범위 * 최대 연산 횟수 < 1억

using namespace std;

//가장 작은 생성자 리턴
int constructor(int n) {
    //n까지 분해합 모두 구해보며(모든 수를 분해) 분해합이 n인 경우 찾음
    for (int i = 1; i < n; i++) {
        int k = i; //i는 가공하면 안되므로 k에 저장**
        int sum = k; //분해합 -> 해당 수**
        while (k > 0) { //분해합 -> 각 자리수의 합
            sum += (k % 10); // 자기 자신+각 자리수의 합(한 자리수이므로 %10)
            k /= 10;
        }
        if (sum == n) //분해합이 n이라면 바로 i(n의 가장 작은 생성자) 리턴**
            return i;
    }
    return 0; //생성자가 없는 경우
}

int main() {
    int n;

    //입력
    cin >> n;

    //연산 + 출력
    cout << constructor(n) << '\n';

    return 0;
}